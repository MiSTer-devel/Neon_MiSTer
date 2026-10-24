//
// fdc.sv
//
// The disk controller: the floppy controller (KR1810VG72A, an 8272), the
// hard disk controller (KM1809VG7, a WD1010) and the 2 KB buffer they
// share, as NeonBTL models the floppy side (emubase/Floppy.cpp and the
// HD.BUFF/FD.CNT/HD.SCNT handling in Board.cpp) and as the firmware's
// disk driver drives the hard disk side (NeonBTL has no hard disk).
//
// The buffer is four 512-byte sectors with one address counter: FD.CNT
// selects a sector buffer and zeroes the position, HD.BUFF reads or
// writes a byte and steps it.  An access to HD.SDH turns the buffer to
// write mode, one to HD.CSR to read mode.  The floppy's READ DATA fills
// the buffer from the current sector up to the fourth, its WRITE DATA
// empties HD.SCNT sectors from the end of it.  The hard disk's READ
// SECTOR puts HD.SCNT sectors into the buffer from the selected one on,
// WRITE SECTOR takes them from there; both end in an interrupt.
//
// Floppies are .dsk images on hps_io's sector interface: 80 tracks, two
// sides, ten sectors of 512 bytes, sector (c * 2 + h) * 10 + r - 1.  The
// hard disk is a raw image on the third slot, four heads of eighteen
// sectors a cylinder (the firmware formatter's defaults): image sector
// 1 + (c * 4 + h) * 18 + s with s counted from 0, and image sector 0 the
// firmware's home block, which it reads as sector 255 of cylinder 0 head
// 0 (the formatter lays that sector down outside the normal numbering);
// the cylinder count is the image size.  tools/mkhd.py makes one.
//
// The registers are on the CPU clock; the sector interface on sd_clk.
//
module fdc
(
   input             clk,          // CPU clock
   input             reset,        // hard reset
   input             init,         // the INIT line

   // the registers, from neon_sys: sel is a one-clock strobe
   input             sel,
   input       [3:0] port,         // address bits 4:1 of 161040..161076: 0 HD.BUFF,
                                   // 1 HD.ERR, 2 HD.SCNT, 3 HD.SNUM, 4 HD.CNLO, 5 HD.CNHI,
                                   // 6 HD.SDH, 7 HD.CSR, 12 FD.CSR, 13 FD.BUF, 15 FD.CNT
   input             wr,
   input       [7:0] din,
   output      [7:0] dout,         // valid the clock after sel
   output reg        int_o,        // the floppy controller's interrupt
   output reg        hd_int,       // the hard disk controller's
   output            motor_o,
   output     [15:0] dbg,          // hard disk state for the debug overlay

   // hps_io, on sd_clk: slots 0 and 1 the floppies, 2 the hard disk
   input             sd_clk,
   input       [2:0] img_mounted,
   input             img_readonly,
   input      [63:0] img_size,
   output     [31:0] sd_lba,
   output      [2:0] sd_rd,
   output      [2:0] sd_wr,
   input       [2:0] sd_ack,
   input       [7:0] sd_buff_addr,
   input      [15:0] sd_buff_dout,
   output reg [15:0] sd_buff_din,
   input             sd_buff_wr
);

localparam [7:0] MSR_RQM = 8'h80, MSR_DIO = 8'h40, MSR_CB = 8'h10;
localparam [1:0] PH_CMD = 2'd1, PH_EXEC = 2'd2, PH_RESULT = 2'd3;
localparam [7:0] MAX_TRACKS = 8'd83;

// the hard disk: WD1010 status bits, commands and the fixed geometry
localparam [7:0] HS_BUSY = 8'h80, HS_READY = 8'h40, HS_SC = 8'h10, HS_DRQ = 8'h08, HS_ERR = 8'h01;
localparam [7:0] HE_IDNF = 8'h10, HE_ABORT = 8'h04;
localparam [3:0] HC_RESTORE = 4'h1, HC_READ = 4'h2, HC_WRITE = 4'h3, HC_SCANID = 4'h4,
                 HC_FORMAT = 4'h5, HC_SEEK = 4'h7;
localparam       HD_HEADS = 4, HD_SPT = 18;
localparam [1:0] HD_IDLE = 2'd0, HD_DELAY = 2'd1, HD_XFER = 2'd2, HD_NEXT = 2'd3;
// A command takes at least this long (CPU clocks, 3 ms): the firmware arms
// its wait for the interrupt only after the command, through several
// emulated-register traps, and a completion that comes sooner is lost.
// A real drive takes longer than this for any command.
localparam [15:0] HD_MIN_CLOCKS = 16'd24000;

// the sector transfer sequence
reg        xfer_run = 0;      // moving sectors
reg        xfer_we  = 0;
reg        xfer_hd  = 0;      // the hard disk's slot, not the floppy's
reg  [3:0] sector   = 0;      // 0..9
reg  [1:0] xfer_buf = 0;
reg        xfer_req = 0;      // to sd_clk: do one sector
reg [31:0] xfer_lba = 0;
reg  [1:0] done_s   = 0;      // sd side's done, synchronised

// the sd_clk side
reg  [1:0] req_s = 0;
reg        xfer_done_sd = 0;
reg        sd_busy = 0;
reg        sd_req_rd = 0, sd_req_wr = 0;
reg  [2:0] ack_d = 0;

// ---------------------------------------------------------------------
// The buffer: 1024 words, byte lanes separate; port A the CPU, port B sd
// ---------------------------------------------------------------------
wire [9:0] a_waddr = {nbuf, pos[8:1]};
wire [7:0] a_qlo, a_qhi;
wire       a_q_sel = pos[0];
reg        a_q_sel_d;
wire [7:0] a_q = a_q_sel_d ? a_qhi : a_qlo;
always @(posedge clk) a_q_sel_d <= a_q_sel;
wire a_wr = sel && port == 4'd0 && wr && dir;

wire [9:0] b_addr = {xfer_buf, sd_buff_addr};
wire       b_wr   = sd_buff_wr && |sd_ack && sd_busy && !xfer_we;
wire [7:0] b_qlo, b_qhi;

reg  [1:0] nbuf = 0;
reg  [8:0] pos  = 0;
reg        dir  = 0;         // 1: write mode
reg  [7:0] scnt = 0;

dpram #(.AW(10), .DW(8)) buf_lo
(
   .clk_a(clk),    .addr_a(a_waddr), .din_a(din), .we_a(a_wr & ~pos[0]), .dout_a(a_qlo),
   .clk_b(sd_clk), .addr_b(b_addr),  .din_b(sd_buff_dout[7:0]),  .we_b(b_wr), .dout_b(b_qlo)
);
dpram #(.AW(10), .DW(8)) buf_hi
(
   .clk_a(clk),    .addr_a(a_waddr), .din_a(din), .we_a(a_wr & pos[0]), .dout_a(a_qhi),
   .clk_b(sd_clk), .addr_b(b_addr),  .din_b(sd_buff_dout[15:8]), .we_b(b_wr), .dout_b(b_qhi)
);

// ---------------------------------------------------------------------
// Drives
// ---------------------------------------------------------------------
reg  [2:0] mounted = 0;
reg  [2:0] readonly = 0;
reg [31:0] hd_sectors = 0;
always @(posedge sd_clk) begin
   if(img_mounted[0]) begin mounted[0] <= |img_size; readonly[0] <= img_readonly; end
   if(img_mounted[1]) begin mounted[1] <= |img_size; readonly[1] <= img_readonly; end
   if(img_mounted[2]) begin mounted[2] <= |img_size; readonly[2] <= img_readonly; hd_sectors <= img_size[40:9]; end
end

// the HD.SDH register selects for both controllers: {size, drive, head}
// on the hard disk, {motor, density, drive, side} on the floppies, bit 3
// the hard disk itself
reg  [7:0] hd_sdh = 0;
wire       hdd_sel = hd_sdh[3];
wire       motor   = hd_sdh[4];
wire       drive   = hd_sdh[2];
wire       side    = hd_sdh[0];
assign     motor_o = motor;
wire       attached = mounted[drive];

// the hard disk controller
reg  [7:0] hd_err = 0, hd_snum = 0;
reg [15:0] hd_cnum = 0;
reg  [7:0] hd_status = HS_READY | HS_SC;
reg  [3:0] hd_cmd = 0;
reg  [1:0] hd_st = HD_IDLE;
reg [15:0] hd_delay = 0;
reg  [8:0] hd_left = 0;          // sectors still to move
reg  [1:0] hd_buf = 0;           // the buffer the next sector goes to or comes from
// The formatter numbers the sectors of partition p as 32p + 0..17, so a
// seek into the wrong partition finds no ID: the sector within the track
// is the low five bits of the number.
wire        hd_home = (hd_cnum == 0) && (hd_sdh[2:0] == 0) && (hd_snum == 8'd255);
wire  [4:0] hd_sec  = hd_snum[4:0];
wire [31:0] hd_lba = hd_home ? 32'd0 : ({16'd0, hd_cnum} * HD_HEADS + {29'd0, hd_sdh[2:0]}) * HD_SPT + {27'd0, hd_sec} + 32'd1;
wire        hd_lba_ok = mounted[2] && hd_lba < hd_sectors && hd_sdh[2:0] < HD_HEADS && (hd_sec < HD_SPT || hd_home);

// ---------------------------------------------------------------------
// The controller
// ---------------------------------------------------------------------
reg  [1:0] phase = PH_CMD;
reg  [7:0] cmd[9];
reg  [3:0] cmdlen = 0;
reg  [7:0] res[7];
reg  [2:0] reslen = 0, respos = 0;


wire [7:0] msr = (phase == PH_CMD)    ? MSR_RQM :
                 (phase == PH_EXEC)   ? MSR_CB  :
                                        (MSR_RQM | MSR_DIO | MSR_CB);

// the command: judged from its first byte, which is the byte being
// written while the buffer is empty, and the length including this byte
wire [7:0] first  = (cmdlen == 0) ? din : cmd[0];
wire [3:0] newlen = cmdlen + 1'd1;
reg        cmd_done, cmd_bad;
reg  [4:0] cmd_id;
always @(*) begin
   cmd_done = 1'b0; cmd_bad = 1'b0; cmd_id = first[4:0];
   case(first)
   8'h03: cmd_done = (newlen == 3);          // SPECIFY
   8'h04: cmd_done = (newlen == 2);          // SENSE DRIVE STATUS
   8'h07: cmd_done = (newlen == 2);          // RECALIBRATE
   8'h08: cmd_done = 1'b1;                   // SENSE INTERRUPT STATUS
   8'h0f: cmd_done = (newlen == 3);          // SEEK
   default: case(first[4:0])
      5'h02:        cmd_done = (newlen == 9);   // READ TRACK
      5'h05, 5'h09: begin cmd_done = (newlen == 9); cmd_id = 5'h05; end   // WRITE DATA
      5'h06, 5'h0c: begin cmd_done = (newlen == 9); cmd_id = 5'h06; end   // READ DATA
      5'h0a:        cmd_done = (newlen == 2);   // READ ID
      5'h0d:        cmd_done = (newlen == 6);   // FORMAT TRACK
      5'h11, 5'h19, 5'h1d: cmd_done = (newlen == 9);   // SCAN
      default:      cmd_bad = 1'b1;
      endcase
   endcase
end

// the sector address of a READ/WRITE DATA: C = cmd[2], H = cmd[3], R = cmd[4]
wire  [7:0] cyl = cmd[2];
wire        head = cmd[3][0];
wire [10:0] lba_calc = {2'd0, cyl, head} * 11'd10;   // (c*2+h)*10

reg  [7:0] dout_r;
assign dout = dout_r;

integer i;
always @(posedge clk) begin
   done_s <= {done_s[0], xfer_done_sd};

   if(reset || init) begin
      phase <= PH_CMD; cmdlen <= 0; reslen <= 0; respos <= 0; int_o <= 1'b0;
      xfer_run <= 1'b0; xfer_req <= 1'b0; xfer_hd <= 1'b0;
      nbuf <= 0; pos <= 0; dir <= 1'b0;
      hd_st <= HD_IDLE; hd_int <= 1'b0; hd_status <= HS_READY | HS_SC; hd_err <= 0;
      if(reset) begin scnt <= 0; hd_sdh <= 0; hd_snum <= 0; hd_cnum <= 0; end
   end
   else begin
      // ---------------- register access ----------------
      if(sel) case(port)
      4'd0: begin   // HD.BUFF
         if(dir ? wr : !wr) begin
            if(pos == 9'd511) begin pos <= 0; nbuf <= nbuf + 1'd1; end
            else pos <= pos + 1'd1;
         end
         dout_r <= dir ? 8'd0 : a_q;
      end
      4'd1: begin   // HD.ERR: the error register, write precompensation
         if(!wr) dout_r <= hd_err;
      end
      4'd2: begin   // HD.SCNT
         if(wr) scnt <= din; else dout_r <= scnt;
      end
      4'd3: begin   // HD.SNUM
         if(wr) hd_snum <= din; else dout_r <= hd_snum;
      end
      4'd4: begin   // HD.CNLO
         if(wr) hd_cnum[7:0] <= din; else dout_r <= hd_cnum[7:0];
      end
      4'd5: begin   // HD.CNHI
         if(wr) hd_cnum[15:8] <= din; else dout_r <= hd_cnum[15:8];
      end
      4'd6: begin   // HD.SDH: the buffer into write mode
         dir <= 1'b1;
         if(wr) hd_sdh <= din; else dout_r <= hd_sdh;
      end
      4'd7: begin   // HD.CSR: the buffer into read mode; status, or a command
         dir <= 1'b0;
         if(wr) begin
            hd_int    <= 1'b0;
            hd_cmd    <= din[7:4];
            hd_status <= (hd_status | HS_BUSY) & ~(HS_DRQ | HS_ERR);
            hd_err    <= 0;
            hd_left   <= !din[2] ? 9'd1 : (scnt == 0) ? 9'd256 : {1'b0, scnt};   // the M bit: HD.SCNT sectors, else one
            hd_delay  <= HD_MIN_CLOCKS;
            hd_st     <= HD_DELAY;
         end
         else begin
            dout_r <= hd_status;
            hd_int <= 1'b0;
         end
      end
      4'd12: dout_r <= msr;   // FD.CSR
      4'd13: begin   // FD.BUF
         dout_r <= 8'hff;
         if(!hdd_sel) begin
            if(wr) begin
               if(phase == PH_CMD) begin
                  int_o <= 1'b0;
                  cmd[cmdlen] <= din;
                  if(cmd_bad) begin
                     // an unknown command: one result byte
                     phase <= PH_RESULT; res[0] <= 8'h80; reslen <= 3'd1; respos <= 0; cmdlen <= 0;
                  end
                  else if(first == 8'h08) begin
                     // SENSE INTERRUPT STATUS completes at once
                     phase <= PH_RESULT; cmdlen <= 0; respos <= 0; reslen <= 3'd2;
                     res[0] <= attached ? 8'h20 : 8'h60; res[1] <= 8'h00;
                     int_o <= 1'b0;
                  end
                  else if(cmd_done) begin
                     cmdlen <= 0; reslen <= 0; respos <= 0;
                     case(cmd_id)
                     5'h06, 5'h05: begin   // READ DATA / WRITE DATA
                        res[0] <= 8'h20 | {6'd0, cmd[1][1:0]};
                        res[1] <= 0; res[2] <= 0;
                        res[3] <= cmd[2]; res[4] <= cmd[3]; res[5] <= cmd[4]; res[6] <= cmd[5];
                        reslen <= 3'd7;
                        if(!attached || cmd[2] >= MAX_TRACKS - 1) begin
                           res[0] <= (cmd_id == 5'h06) ? (8'hC8 | {6'd0, cmd[1][1:0]}) : 8'hC8;
                           phase  <= PH_RESULT;
                           int_o  <= 1'b1;
                        end
                        else begin
                           phase    <= PH_EXEC;
                           xfer_run <= 1'b1;
                           xfer_we  <= (cmd_id == 5'h05);
                           sector   <= cmd[4][3:0] - 1'd1;
                        end
                     end
                     5'h07, 5'h0f: begin   // RECALIBRATE, SEEK
                        phase <= PH_CMD; int_o <= 1'b1;
                     end
                     5'h03: phase <= PH_CMD;   // SPECIFY
                     default: phase <= PH_EXEC;   // not implemented: stays busy
                     endcase
                  end
                  else cmdlen <= cmdlen + 1'd1;
               end
            end
            else begin
               if(phase == PH_RESULT) begin
                  int_o <= 1'b0;
                  if(respos < reslen) begin dout_r <= res[respos]; respos <= respos + 1'd1; end
                  if(respos + 1'd1 >= reslen) phase <= PH_CMD;
               end
            end
         end
         else dout_r <= 8'd0;
      end
      4'd15: begin   // FD.CNT
         if(wr) begin
            nbuf <= din[1:0];
            pos  <= 0;
            if(din[4]) begin
               phase <= PH_CMD; cmdlen <= 0; reslen <= 0; respos <= 0; int_o <= 1'b0;
               xfer_run <= 1'b0; xfer_req <= 1'b0;
            end
         end
      end
      default: dout_r <= 8'd0;
      endcase

      // ---------------- the hard disk controller ----------------
      case(hd_st)
      HD_IDLE: ;
      HD_DELAY: begin
         // the command settles: a seek, or the first sector of a transfer
         if(hd_delay != 0) hd_delay <= hd_delay - 1'd1;
         else begin
            case(hd_cmd)
            HC_READ, HC_WRITE: begin
               if(!hd_lba_ok || (hd_cmd == HC_WRITE && readonly[2])) begin
                  hd_status <= (hd_status & ~HS_BUSY) | HS_ERR;
                  hd_err    <= HE_IDNF;
                  hd_int    <= 1'b1;
                  hd_st     <= HD_IDLE;
               end
               else begin
                  // a read lands in the selected buffer; a write takes the
                  // buffer after the selected one (the firmware selects the
                  // one before the first it filled)
                  xfer_hd  <= 1'b1;
                  xfer_we  <= (hd_cmd == HC_WRITE);
                  xfer_buf <= (hd_cmd == HC_WRITE) ? nbuf + 1'd1 : nbuf;
                  hd_buf   <= (hd_cmd == HC_WRITE) ? nbuf + 2'd2 : nbuf + 1'd1;
                  xfer_lba <= hd_lba;
                  xfer_req <= 1'b1;
                  hd_st    <= HD_XFER;
               end
            end
            HC_RESTORE: begin
               hd_cnum   <= 0;
               hd_status <= (hd_status & ~HS_BUSY) | HS_SC | (mounted[2] ? HS_READY : 8'd0);
               if(!mounted[2]) begin hd_status[0] <= 1'b1; hd_err <= HE_ABORT; end
               hd_int    <= 1'b1;
               hd_st     <= HD_IDLE;
            end
            default: begin   // SEEK, SCAN ID, FORMAT: done as asked
               hd_status <= (hd_status & ~HS_BUSY) | HS_SC;
               hd_int    <= 1'b1;
               hd_st     <= HD_IDLE;
            end
            endcase
         end
      end
      HD_XFER: if(xfer_req && done_s[1]) begin
         xfer_req <= 1'b0;
         nbuf     <= xfer_buf + 1'd1;
         pos      <= 0;
         hd_snum  <= hd_snum + 1'd1;
         hd_left  <= hd_left - 1'd1;
         hd_st    <= HD_NEXT;
      end
      HD_NEXT: if(!done_s[1]) begin
         if(hd_left == 0) begin
            xfer_hd   <= 1'b0;
            hd_status <= hd_status & ~HS_BUSY;
            hd_int    <= 1'b1;
            hd_st     <= HD_IDLE;
         end
         else if(!hd_lba_ok) begin
            xfer_hd   <= 1'b0;
            hd_status <= (hd_status & ~HS_BUSY) | HS_ERR;
            hd_err    <= HE_IDNF;
            hd_int    <= 1'b1;
            hd_st     <= HD_IDLE;
         end
         else begin
            xfer_buf <= hd_buf;
            hd_buf   <= hd_buf + 1'd1;
            xfer_lba <= hd_lba;
            xfer_req <= 1'b1;
            hd_st    <= HD_XFER;
         end
      end
      endcase

      // ---------------- the sector transfer sequence ----------------
      if(xfer_run && !xfer_req && !done_s[1]) begin
         if(xfer_we) begin
            // GetHDBuffer: nothing left when the count is zero
            if(scnt == 0) begin
               xfer_run <= 1'b0; phase <= PH_RESULT; int_o <= 1'b1;
            end
            else begin
               scnt     <= scnt - 1'd1;
               xfer_buf <= 2'd3 - (scnt[1:0] - 2'd1);
               xfer_lba <= {21'd0, lba_calc} + {28'd0, sector};
               xfer_req <= ~readonly[drive];
               if(readonly[drive]) sector <= (sector == 4'd9) ? 4'd0 : sector + 1'd1;   // dropped, but counted
            end
         end
         else begin
            // FillHDBuffer: into the current buffer, up to the fourth
            xfer_buf <= nbuf;
            xfer_lba <= {21'd0, lba_calc} + {28'd0, sector};
            xfer_req <= 1'b1;
         end
      end
      if(xfer_req && done_s[1] && !xfer_hd) begin
         xfer_req <= 1'b0;
         if(xfer_we) sector <= (sector == 4'd9) ? 4'd0 : sector + 1'd1;
         else begin
            if(nbuf == 2'd3) begin
               nbuf <= 0; pos <= 0;
               xfer_run <= 1'b0; phase <= PH_RESULT; int_o <= 1'b1;
            end
            else begin
               nbuf   <= nbuf + 1'd1;
               sector <= (sector == 4'd9) ? 4'd0 : sector + 1'd1;
            end
         end
      end
   end
end

reg  [9:0] dbg_secs = 0;        // sectors moved, commands taken: for the overlay
reg  [5:0] dbg_cmds = 0;
always @(posedge clk) begin
   if(hd_st == HD_XFER && xfer_req && done_s[1]) dbg_secs <= dbg_secs + 1'd1;
   if(sel && port == 4'd7 && wr) dbg_cmds <= dbg_cmds + 1'd1;
end
assign dbg = {dbg_secs, dbg_cmds};

// ---------------------------------------------------------------------
// sd_clk side: one sector per request
// ---------------------------------------------------------------------

wire [2:0] slot = xfer_hd ? 3'b100 : drive ? 3'b010 : 3'b001;
assign sd_rd  = {3{sd_req_rd}} & slot;
assign sd_wr  = {3{sd_req_wr}} & slot;
assign sd_lba = xfer_lba;

always @(posedge sd_clk) begin
   req_s <= {req_s[0], xfer_req};
   ack_d <= sd_ack;
   sd_buff_din <= {b_qhi, b_qlo};

   if(!req_s[1]) begin
      xfer_done_sd <= 1'b0;
      sd_busy <= 1'b0;
      sd_req_rd <= 1'b0; sd_req_wr <= 1'b0;
   end
   else if(!sd_busy && !xfer_done_sd) begin
      sd_busy <= 1'b1;
      if(xfer_we) sd_req_wr <= 1'b1; else sd_req_rd <= 1'b1;
   end
   else if(sd_busy) begin
      if(|sd_ack) begin sd_req_rd <= 1'b0; sd_req_wr <= 1'b0; end
      if(|ack_d && !(|sd_ack)) begin sd_busy <= 1'b0; xfer_done_sd <= 1'b1; end
   end
end

endmodule
