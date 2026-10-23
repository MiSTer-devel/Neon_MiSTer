//
// fdc.sv
//
// The floppy controller (KR1810VG72A, an 8272) and the 2 KB disk buffer
// shared with the hard disk controller, as NeonBTL models them
// (emubase/Floppy.cpp and the HD.BUFF/FD.CNT/HD.SCNT handling in
// Board.cpp): a command phase, an execution phase that moves whole
// sectors between the buffer and the disk, and a result phase.  The
// buffer is four 512-byte sectors; a READ DATA fills it from the current
// sector up to the fourth, a WRITE DATA empties HD.SCNT sectors from the
// end of it.
//
// Disks are .dsk images on hps_io's sector interface: 80 tracks, two
// sides, ten sectors of 512 bytes, sector (c * 2 + h) * 10 + r - 1.
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
   input       [2:0] port,         // 0 HD.BUFF, 2 HD.SCNT, 4 FD.CSR, 5 FD.BUF, 7 FD.CNT
   input             wr,
   input       [7:0] din,
   output      [7:0] dout,         // valid the clock after sel
   input             dir_wr,       // HD.SDH accessed: buffer to write mode
   input             dir_rd,       // HD.CSR accessed: buffer to read mode
   input       [4:0] params,       // {hdd, motor, density, drive, side}
   output reg        int_o,
   output            motor_o,

   // hps_io, on sd_clk
   input             sd_clk,
   input       [1:0] img_mounted,
   input             img_readonly,
   input      [63:0] img_size,
   output     [31:0] sd_lba,
   output      [1:0] sd_rd,
   output      [1:0] sd_wr,
   input       [1:0] sd_ack,
   input       [7:0] sd_buff_addr,
   input      [15:0] sd_buff_dout,
   output reg [15:0] sd_buff_din,
   input             sd_buff_wr
);

localparam [7:0] MSR_RQM = 8'h80, MSR_DIO = 8'h40, MSR_CB = 8'h10;
localparam [1:0] PH_CMD = 2'd1, PH_EXEC = 2'd2, PH_RESULT = 2'd3;
localparam [7:0] MAX_TRACKS = 8'd83;

// the sector transfer sequence
reg        xfer_run = 0;      // moving sectors
reg        xfer_we  = 0;
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
reg  [1:0] ack_d = 0;

// ---------------------------------------------------------------------
// The buffer: 1024 words, byte lanes separate; port A the CPU, port B sd
// ---------------------------------------------------------------------
wire [9:0] a_waddr = {nbuf, pos[8:1]};
wire [7:0] a_qlo, a_qhi;
wire       a_q_sel = pos[0];
reg        a_q_sel_d;
wire [7:0] a_q = a_q_sel_d ? a_qhi : a_qlo;
always @(posedge clk) a_q_sel_d <= a_q_sel;
wire a_wr = sel && port == 3'd0 && wr && dir;

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
reg  [1:0] mounted = 0;
reg  [1:0] readonly = 0;
always @(posedge sd_clk) begin
   if(img_mounted[0]) begin mounted[0] <= |img_size; readonly[0] <= img_readonly; end
   if(img_mounted[1]) begin mounted[1] <= |img_size; readonly[1] <= img_readonly; end
end

wire       hdd_sel = params[4];
wire       motor   = params[3];
wire       drive   = params[2];
wire       side    = params[0];
assign     motor_o = motor;
wire       attached = mounted[drive];

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
      xfer_run <= 1'b0; xfer_req <= 1'b0;
      nbuf <= 0; pos <= 0; dir <= 1'b0;
      if(reset) scnt <= 0;
   end
   else begin
      if(dir_wr) dir <= 1'b1;
      if(dir_rd) dir <= 1'b0;

      // ---------------- register access ----------------
      if(sel) case(port)
      3'd0: begin   // HD.BUFF
         if(dir ? wr : !wr) begin
            if(pos == 9'd511) begin pos <= 0; nbuf <= nbuf + 1'd1; end
            else pos <= pos + 1'd1;
         end
         dout_r <= dir ? 8'd0 : a_q;
      end
      3'd2: begin   // HD.SCNT
         if(wr) scnt <= din; else dout_r <= scnt;
      end
      3'd4: dout_r <= msr;   // FD.CSR
      3'd5: begin   // FD.BUF
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
      3'd7: begin   // FD.CNT
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
      if(xfer_req && done_s[1]) begin
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

// ---------------------------------------------------------------------
// sd_clk side: one sector per request
// ---------------------------------------------------------------------

assign sd_rd  = {2{sd_req_rd}} & (drive ? 2'b10 : 2'b01);
assign sd_wr  = {2{sd_req_wr}} & (drive ? 2'b10 : 2'b01);
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
