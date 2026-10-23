//
// neon_video.sv
//
// The Soyuz-Neon display controller: 832 x 300 at 50 Hz, 15.625 kHz
// lines, from the display list in RAM, as NeonBTL renders it
// (Emulator_PrepareScreenLines in Emulator.cpp).
//
//   VDPTAS (RAM 000010/000012) -> the line table, a 32-bit pointer a line
//   (two lines before the first visible one); each line's table of
//   segments: 32-bit entries {PB, -length[14:10], VD[9:8], VN[7:6],
//   PN[5:4], A21..18[3:0]} + {A17..2}; a segment is its length in 32-bit
//   words, two 16-pixel bars a word, and every segment after the first
//   starts with a 16-pixel border bar.  VDPTAP -> the 2 KB palette:
//   two 512-byte blocks (PB) of high then low bytes for the 1/2/4 bpp
//   palettes (VN * 64 + PN * 16) and two 512-byte 8 bpp palettes.
//
// A line is rendered into one of two line buffers during the previous
// line: the segment list is walked, the pixel words fetched from RAM
// one at a time and the pixels written as 16-bit palette colours (the
// palette itself is copied from RAM into block RAM during the vertical
// blank).  The scan-out reads the other buffer at the 16 MHz pixel rate.
//
module neon_video
(
   input             clk,          // 64 MHz
   input             reset,
   input       [1:0] ram_banks0,
   input       [1:0] ram_banks1,

   // RAM reads (neon_mem)
   output reg        ram_req,
   output reg [21:1] ram_addr,
   input      [15:0] ram_dout,
   input             ram_ack,

   // video out
   output reg        ce_pix,
   output reg        hsync,
   output reg        vsync,
   output reg        hblank = 1,
   output reg        vblank = 1,
   output reg  [7:0] red,
   output reg  [7:0] green,
   output reg  [7:0] blue,
   output            frame_tick,   // one clk at the start of the vertical blank

   // debug overlay: 32 bits as boxes on the top 16 lines, [31:16] above [15:0]
   input     [463:0] dbg_in,
   output    [511:0] dbg_out
);

// ---------------------------------------------------------------------
// Timing: 1024 x 312 pixels of 62.5 ns
// ---------------------------------------------------------------------
localparam H_TOTAL = 1024, H_ACTIVE = 832, H_SYNC_ON = 872, H_SYNC_OFF = 948;
localparam V_TOTAL = 312,  V_ACTIVE = 300, V_SYNC_ON = 304, V_SYNC_OFF = 308;

reg  [1:0] pix_div = 0;
reg  [9:0] hcnt = 0;
reg  [8:0] vcnt = 0;
wire       line_start = (hcnt == 0) && (pix_div == 0);

always @(posedge clk) begin
   pix_div <= pix_div + 1'd1;
   ce_pix  <= (pix_div == 2'd3);
   if(reset) begin hcnt <= 0; vcnt <= 0; end
   else if(pix_div == 2'd3) begin
      if(hcnt == H_TOTAL - 1) begin
         hcnt <= 0;
         vcnt <= (vcnt == V_TOTAL - 1) ? 9'd0 : vcnt + 1'd1;
      end
      else hcnt <= hcnt + 1'd1;
   end
end

assign frame_tick = (vcnt == V_ACTIVE) && line_start;

// ---------------------------------------------------------------------
// The palette copy: pal_hi/pal_lo[n], n = block * 256 + index
// ---------------------------------------------------------------------
reg  [7:0] pal_hi[1024];
reg  [7:0] pal_lo[1024];
reg  [9:0] pal_waddr;
reg  [7:0] pal_wdata;
reg        pal_whi, pal_wlo;
always @(posedge clk) begin
   if(pal_whi) pal_hi[pal_waddr] <= pal_wdata;
   if(pal_wlo) pal_lo[pal_waddr] <= pal_wdata;
end

// the lookup port
reg  [9:0] pal_raddr;
reg  [7:0] pal_qhi, pal_qlo;
always @(posedge clk) begin
   pal_qhi <= pal_hi[pal_raddr];
   pal_qlo <= pal_lo[pal_raddr];
end

// ---------------------------------------------------------------------
// The line buffers: {line parity, x}
// ---------------------------------------------------------------------
reg [15:0] lbuf[2048];
reg [10:0] lb_waddr;
reg [15:0] lb_wdata;
reg        lb_we;
always @(posedge clk) if(lb_we) lbuf[lb_waddr] <= lb_wdata;

reg [15:0] lb_q;
always @(posedge clk) lb_q <= lbuf[{vcnt[0], hcnt}];

// ---------------------------------------------------------------------
// The renderer
// ---------------------------------------------------------------------
// the RAM bank logic of the machine, on a 22-bit byte address
function [21:1] bank_addr(input [21:0] a);
   bank_addr = ((a[21] ? ram_banks1 : ram_banks0) == 2'd1) ? (a[21:1] & ~21'h0C0000) : a[21:1];
endfunction
function bank_none(input [21:0] a);
   bank_none = ((a[21] ? ram_banks1 : ram_banks0) == 2'd0);
endfunction

localparam [4:0]
   S_IDLE = 0, S_FETCH = 1, S_FETCH_END = 2,
   S_VDP0 = 3, S_VDP1 = 4, S_VDP2 = 5, S_VDP3 = 6,
   S_PAL = 7, S_PAL_WR0 = 8, S_PAL_WR1 = 9,
   S_TAS0 = 10, S_TAS1 = 11, S_OTR0 = 12, S_OTR1 = 13, S_SEG = 14,
   S_BORDER = 15, S_CLAMP = 16, S_BAR = 17, S_PIX = 18, S_SEGEND = 19, S_DONE = 20;

reg  [4:0] state = S_IDLE, ret = S_IDLE;
reg [21:0] fetch_addr;
reg [15:0] fetch_data;
reg [15:0] tmp;

reg [21:0] tasaddr, tapaddr;
reg [21:0] lineaddr, otraddr;
reg [10:0] pal_cnt;          // words copied

reg  [8:0] line;             // the line being rendered: 0..301 for -2..299
reg        rendering;        // a line is in hand
reg  [9:0] x;                // pixel in the line buffer
reg  [5:0] bar;              // bars of the line not yet taken, 52..0
reg  [6:0] barcount;         // bars of this segment still to draw
reg        first;
reg  [9:0] colorbprev;       // palette entry of the previous segment's border
reg  [9:0] colorb;           // and of this one
reg  [9:0] palbase;          // entry number of the segment's palette
reg  [3:0] vmode;
reg        otrpb;
reg  [4:0] otrcount;
reg  [1:0] units;            // units a bar: 1 or 2
reg        byte_unit;        // the unit is a byte, not a word
reg  [1:0] unit_n;           // units done in the bar
reg [15:0] sh;               // the unit's bits, consumed from the bottom
reg  [3:0] bpp;              // 1, 2, 4, 8
reg  [4:0] ppg;              // pixels a group: 1, 2, 4, 8, 16
reg  [4:0] pcnt;             // pixels done in the group
reg  [4:0] gcnt;             // groups done in the unit
reg  [4:0] groups;           // groups in a unit
reg  [2:0] pmap;             // the palette mapping of a group
localparam [2:0] M_VM1 = 0, M_2BIT = 1, M_12 = 2, M_NIB = 3, M_MC = 4, M_VM1ODD = 5;
reg  [4:0] bcnt;             // border pixel count
reg  [1:0] pipe;             // palette lookup pipeline valid bits
reg [10:0] pipe_addr0, pipe_addr1;

// the palette entry of the current group
wire [9:0] group_entry =
   (pmap == M_VM1)    ? palbase + 10'd14 + {9'd0, sh[0]} :
   (pmap == M_VM1ODD) ? palbase + 10'd14 + {9'd0, sh[1]} :
   (pmap == M_2BIT)   ? palbase + {8'd0, sh[1:0]} :
   (pmap == M_12)     ? palbase + 10'd12 + {8'd0, sh[1:0]} :
   (pmap == M_NIB)    ? palbase + {6'd0, sh[3:0]} :
                        palbase + {2'd0, sh[7:0]};

// the border bar's pixels: AAAAAAAAABBCCCCC - the previous segment's
// border, the screen's border, this segment's border
wire [9:0] border_entry = (bcnt < 5'd9) ? colorbprev : (bcnt < 5'd11) ? 10'd0 : colorb;

// a line is rendered during the scan line before it, into buffer L[0]:
// while vcnt = L - 1, and vcnt 311 does the two unseen lines and line 0
wire render_now = (vcnt == V_TOTAL - 1) || (vcnt < V_ACTIVE - 1);

always @(posedge clk) begin
   lb_we   <= 1'b0;
   pal_whi <= 1'b0;
   pal_wlo <= 1'b0;

   // the lookup pipeline: entry -> colour -> line buffer
   pipe       <= {pipe[0], 1'b0};
   pipe_addr1 <= pipe_addr0;
   if(pipe[1]) begin lb_we <= 1'b1; lb_waddr <= pipe_addr1; lb_wdata <= {pal_qhi, pal_qlo}; end

   if(reset) begin
      state <= S_IDLE; ram_req <= 1'b0; rendering <= 1'b0; pipe <= 0;
      tasaddr <= 0; tapaddr <= 0;
   end
   else begin
      case(state)
      // ----- the frame: the pointers and the palette, in the vertical blank -----
      S_IDLE: begin
         if(frame_tick) begin
            fetch_addr <= 22'o000010; ret <= S_VDP0; state <= S_FETCH;
         end
         else if(line_start && render_now && !rendering) begin
            rendering <= 1'b1;
            line <= (vcnt == V_TOTAL - 1) ? 9'd0 : vcnt + 9'd3;
            fetch_addr <= tasaddr; ret <= S_TAS0; state <= S_FETCH;
         end
      end
      S_VDP0: begin tmp <= fetch_data; fetch_addr <= 22'o000012; ret <= S_VDP1; state <= S_FETCH; end
      S_VDP1: begin tasaddr <= {fetch_data[3:0], tmp, 2'b00}; fetch_addr <= 22'o000004; ret <= S_VDP2; state <= S_FETCH; end
      S_VDP2: begin tmp <= fetch_data; fetch_addr <= 22'o000006; ret <= S_VDP3; state <= S_FETCH; end
      S_VDP3: begin tapaddr <= {fetch_data[3:0], tmp, 2'b00}; pal_cnt <= 0; state <= S_PAL; end
      S_PAL: begin
         if(pal_cnt == 11'd1024) state <= S_IDLE;
         else begin fetch_addr <= tapaddr + {10'd0, pal_cnt, 1'b0}; ret <= S_PAL_WR0; state <= S_FETCH; end
      end
      // word w holds bytes 2w and 2w+1: block w[9:8], high/low half w[7], entries {w[6:0], 0/1}
      S_PAL_WR0: begin
         pal_waddr <= {pal_cnt[9:8], pal_cnt[6:0], 1'b0};
         pal_wdata <= fetch_data[7:0];
         pal_whi   <= ~pal_cnt[7];
         pal_wlo   <=  pal_cnt[7];
         state     <= S_PAL_WR1;
      end
      S_PAL_WR1: begin
         pal_waddr <= {pal_cnt[9:8], pal_cnt[6:0], 1'b1};
         pal_wdata <= fetch_data[15:8];
         pal_whi   <= ~pal_cnt[7];
         pal_wlo   <=  pal_cnt[7];
         pal_cnt   <= pal_cnt + 1'd1;
         state     <= S_PAL;
      end

      // ----- a line: its entry in the line table -----
      S_TAS0: begin tmp <= fetch_data; fetch_addr <= tasaddr + 22'd2; ret <= S_TAS1; state <= S_FETCH; end
      S_TAS1: begin
         lineaddr <= {fetch_data[3:0], tmp, 2'b00};
         tasaddr  <= tasaddr + 22'd4;
         if(line < 9'd2) state <= S_DONE;      // the two lines before the screen: not drawn
         else begin
            x <= 0; bar <= 6'd52; first <= 1'b1; colorbprev <= 0;
            fetch_addr <= {fetch_data[3:0], tmp, 2'b00}; ret <= S_OTR0; state <= S_FETCH;
         end
      end
      // ----- a segment: its entry -----
      S_OTR0: begin tmp <= fetch_data; fetch_addr <= lineaddr + 22'd2; ret <= S_OTR1; state <= S_FETCH; end
      S_OTR1: begin
         lineaddr <= lineaddr + 22'd4;
         otraddr  <= {fetch_data[3:0], tmp, 2'b00};
         otrcount <= 5'd0 - fetch_data[14:10];          // 32 - length, mod 32; 0 is 32
         vmode    <= fetch_data[9:6];
         otrpb    <= fetch_data[15];
         if((fetch_data[7:6] == 2'b11) && fetch_data[15])
            palbase <= {1'b1, fetch_data[4], 8'd0};                            // 8 bpp: 512 + (bit 4 ? 256 : 0)
         else
            palbase <= {fetch_data[15], fetch_data[7:6], fetch_data[5:4], 4'd0};   // pb*256 + vn*64 + pn*16
         state <= S_SEG;
      end
      S_SEG: begin
         colorb <= palbase;
         // the bar format
         case(vmode)
         4'd0, 4'd4:  begin units <= 2'd1; byte_unit <= 1'b1; bpp <= 4'd1; ppg <= 5'd2;  groups <= 5'd8;  pmap <= M_VM1; end
         4'd1:        begin units <= 2'd1; byte_unit <= 1'b1; bpp <= 4'd2; ppg <= 5'd4;  groups <= 5'd4;  pmap <= M_2BIT; end
         4'd5:        begin units <= 2'd1; byte_unit <= 1'b1; bpp <= 4'd2; ppg <= 5'd4;  groups <= 5'd4;  pmap <= M_12; end
         4'd2, 4'd6:  begin units <= 2'd1; byte_unit <= 1'b1; bpp <= 4'd4; ppg <= 5'd8;  groups <= 5'd2;  pmap <= M_NIB; end
         4'd3, 4'd7:  begin units <= 2'd1; byte_unit <= 1'b1;
                            if(otrpb) begin bpp <= 4'd8; ppg <= 5'd16; groups <= 5'd1; pmap <= M_MC; end
                            else      begin bpp <= 4'd4; ppg <= 5'd8;  groups <= 5'd2; pmap <= M_NIB; end end
         4'd8:        begin units <= 2'd1; byte_unit <= 1'b0; bpp <= 4'd1; ppg <= 5'd1;  groups <= 5'd16; pmap <= M_VM1; end
         4'd9:        begin units <= 2'd1; byte_unit <= 1'b0; bpp <= 4'd2; ppg <= 5'd2;  groups <= 5'd8;  pmap <= M_12; end
         4'd10:       begin units <= 2'd1; byte_unit <= 1'b0; bpp <= 4'd4; ppg <= 5'd4;  groups <= 5'd4;  pmap <= M_NIB; end
         4'd11:       begin units <= 2'd1; byte_unit <= 1'b0;
                            if(otrpb) begin bpp <= 4'd8; ppg <= 5'd8;  groups <= 5'd2; pmap <= M_MC; end
                            else      begin bpp <= 4'd4; ppg <= 5'd4;  groups <= 5'd4; pmap <= M_NIB; end end
         4'd12:       begin units <= 2'd2; byte_unit <= 1'b0; bpp <= 4'd2; ppg <= 5'd1;  groups <= 5'd8;  pmap <= M_VM1ODD; end
         4'd13:       begin units <= 2'd2; byte_unit <= 1'b0; bpp <= 4'd2; ppg <= 5'd1;  groups <= 5'd8;  pmap <= M_12; end
         4'd14:       begin units <= 2'd2; byte_unit <= 1'b0; bpp <= 4'd4; ppg <= 5'd2;  groups <= 5'd4;  pmap <= M_NIB; end
         default:     begin units <= 2'd2; byte_unit <= 1'b0;                                      // 15
                            if(otrpb) begin bpp <= 4'd8; ppg <= 5'd4;  groups <= 5'd2; pmap <= M_MC; end
                            else      begin bpp <= 4'd4; ppg <= 5'd2;  groups <= 5'd4; pmap <= M_NIB; end end
         endcase
         // two bars a 32-bit word; a later segment's first bar is its border
         barcount <= (otrcount == 0 ? 7'd64 : {1'b0, otrcount, 1'b0}) - {6'd0, ~first};
         if(first) state <= S_CLAMP;
         else begin bcnt <= 0; state <= S_BORDER; end
      end
      S_BORDER: begin
         pal_raddr  <= border_entry;
         pipe[0]    <= 1'b1;
         pipe_addr0 <= {line[0], x};
         x    <= x + 1'd1;
         bcnt <= bcnt + 1'd1;
         if(bcnt == 5'd15) begin
            bar <= bar - 1'd1;
            if(bar == 6'd1) state <= S_DONE;
            else state <= S_CLAMP;
         end
      end
      S_CLAMP: begin
         // no more of the segment than the line has room for
         if(barcount > {1'b0, bar}) begin barcount <= {1'b0, bar}; bar <= 0; end
         else bar <= bar - barcount[5:0];
         colorbprev <= colorb;
         state <= S_BAR;
      end
      // ----- a bar's units and pixels -----
      S_BAR: begin
         if(barcount == 0) state <= S_SEGEND;
         else begin
            unit_n <= 0; pcnt <= 0; gcnt <= 0;
            fetch_addr <= otraddr; ret <= S_PIX; state <= S_FETCH;
         end
      end
      S_PIX: begin
         pal_raddr  <= group_entry;
         pipe[0]    <= 1'b1;
         pipe_addr0 <= {line[0], x};
         x    <= x + 1'd1;
         if(pcnt == ppg - 1) begin
            pcnt <= 0;
            sh   <= sh >> bpp;
            gcnt <= gcnt + 1'd1;
            if(gcnt == groups - 1) begin
               gcnt <= 0;
               if(unit_n == units - 1) begin
                  barcount <= barcount - 1'd1;
                  state    <= S_BAR;
               end
               else begin
                  unit_n <= unit_n + 1'd1;
                  fetch_addr <= otraddr; ret <= S_PIX; state <= S_FETCH;
               end
            end
         end
         else pcnt <= pcnt + 1'd1;
      end
      S_SEGEND: begin
         if(bar == 0) state <= S_DONE;
         else begin first <= 1'b0; fetch_addr <= lineaddr; ret <= S_OTR0; state <= S_FETCH; end
      end
      S_DONE: begin
         // the two unseen lines run on into line 0
         if(line < 9'd2) begin
            line <= line + 1'd1;
            fetch_addr <= tasaddr; ret <= S_TAS0; state <= S_FETCH;
         end
         else begin
            rendering <= 1'b0;
            state <= S_IDLE;
         end
      end

      // ----- a RAM word -----
      S_FETCH: begin
         if(bank_none(fetch_addr)) begin
            fetch_data <= 16'd0; state <= S_FETCH_END;
         end
         else if(!ram_req) begin
            if(!ram_ack) begin ram_addr <= bank_addr(fetch_addr); ram_req <= 1'b1; end
         end
         else if(ram_ack) begin
            ram_req    <= 1'b0;
            fetch_data <= ram_dout;
            state      <= S_FETCH_END;
         end
      end
      S_FETCH_END: begin
         // a unit for the pixels: a byte of the word, or the word
         if(ret == S_PIX) begin
            sh <= byte_unit ? (otraddr[0] ? {8'd0, fetch_data[15:8]} : {8'd0, fetch_data[7:0]}) : fetch_data;
            otraddr <= otraddr + (byte_unit ? 22'd1 : 22'd2);
         end
         state <= ret;
      end
      default: state <= S_IDLE;
      endcase

      // a line that runs past its time is given up
      if(rendering && line_start) begin
         rendering <= 1'b0;
         state     <= S_IDLE;
         ram_req   <= 1'b0;
      end
   end
end

// ---------------------------------------------------------------------
// Scan-out
// ---------------------------------------------------------------------
assign dbg_out = {dbg_in, state, rendering, ram_req, ram_ack, 8'd0, 32'd0};
wire [8:0] dbg_bit = 9'd511 - {vcnt[7:3], hcnt[8:5]};
`ifdef NEON_DEBUG_OVERLAY
wire       dbg_on  = (vcnt < 9'd240) && (hcnt < 10'd512) && (hcnt[4:1] != 4'd15) && (vcnt[2:0] != 3'd7);
wire       dbg_val = dbg_out[dbg_bit];
`else
wire       dbg_on  = 1'b0, dbg_val = 1'b0;       // the overlay is compiled out
`endif

// a palette colour: high byte {G5..3, R4..2, B4..3}, low byte {G2..0, R1..0, B2..0}
wire [15:0] c = lb_q;
wire [7:0] r8 = {c[12:10], c[4:3], c[12:10]};
wire [7:0] g8 = {c[15:13], c[7:5], c[15:14]};
wire [7:0] b8 = {c[9:8], c[2:0], c[9:8], c[2]};

always @(posedge clk) if(pix_div == 2'd3) begin
   hblank <= (hcnt >= H_ACTIVE);
   vblank <= (vcnt >= V_ACTIVE);
   hsync  <= (hcnt >= H_SYNC_ON) && (hcnt < H_SYNC_OFF);
   vsync  <= (vcnt >= V_SYNC_ON) && (vcnt < V_SYNC_OFF);
   if(dbg_on) begin red <= dbg_val ? 8'hff : 8'h30; green <= dbg_val ? 8'hff : 8'h30; blue <= 8'h30; end
   else if(hcnt < H_ACTIVE && vcnt < V_ACTIVE) begin red <= r8; green <= g8; blue <= b8; end
   else begin red <= 0; green <= 0; blue <= 0; end
end

endmodule
