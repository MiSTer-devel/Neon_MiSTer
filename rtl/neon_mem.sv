//
// neon_mem.sv
//
// The RAM arbiter: the CPU's port from neon_sys and the display's port
// from neon_video share the SDRAM.  The CPU goes first; a masked write
// (the dispatcher's 2 and 4 bits-per-pixel modes, where a zero pixel in
// the data leaves the memory's pixel alone) is a read, a merge and a
// write.
//
// The CPU port crosses from the 8 MHz clock: req and ack are levels in a
// four-phase handshake and the clocks are in phase, so one register on
// each side is the synchroniser.
//
module neon_mem
(
   input             clk,          // 64 MHz
   input             reset,
   output            ready,

   // the CPU
   input             cpu_req,
   input             cpu_we,
   input      [21:1] cpu_addr,
   input      [15:0] cpu_din,
   input       [1:0] cpu_be,
   input       [1:0] cpu_mask,     // 0 none, 1 2 bpp, 2 4 bpp
   output reg [15:0] cpu_dout,
   output reg        cpu_ack,

   // the display: reads only, req a level until ack
   input             vid_req,
   input      [21:1] vid_addr,
   output reg [15:0] vid_dout,
   output reg        vid_ack,

   // the chip
   inout      [15:0] SDRAM_DQ,
   output     [12:0] SDRAM_A,
   output            SDRAM_DQML,
   output            SDRAM_DQMH,
   output      [1:0] SDRAM_BA,
   output            SDRAM_nCS,
   output            SDRAM_nWE,
   output            SDRAM_nRAS,
   output            SDRAM_nCAS,
   output            SDRAM_CKE,
   output            SDRAM_CLK
);

reg         req;
reg         we;
reg  [21:1] addr;
reg  [15:0] din;
reg   [1:0] be;
wire [15:0] dout;
wire        ack;

sdram sdram
(
   .clk(clk), .init(reset), .ready(ready),
   .SDRAM_DQ(SDRAM_DQ), .SDRAM_A(SDRAM_A), .SDRAM_DQML(SDRAM_DQML), .SDRAM_DQMH(SDRAM_DQMH),
   .SDRAM_BA(SDRAM_BA), .SDRAM_nCS(SDRAM_nCS), .SDRAM_nWE(SDRAM_nWE), .SDRAM_nRAS(SDRAM_nRAS),
   .SDRAM_nCAS(SDRAM_nCAS), .SDRAM_CKE(SDRAM_CKE), .SDRAM_CLK(SDRAM_CLK),
   .req(req), .we(we), .addr(addr), .din(din), .be(be), .dout(dout), .ack(ack)
);

// the pixel masks: a nonzero pixel in the data is written, a zero one is kept
function [15:0] mask2(input [15:0] d);
   mask2 = {{2{|d[15:14]}}, {2{|d[13:12]}}, {2{|d[11:10]}}, {2{|d[9:8]}},
            {2{|d[7:6]}},   {2{|d[5:4]}},   {2{|d[3:2]}},   {2{|d[1:0]}}};
endfunction
function [15:0] mask4(input [15:0] d);
   mask4 = {{4{|d[15:12]}}, {4{|d[11:8]}}, {4{|d[7:4]}}, {4{|d[3:0]}}};
endfunction

reg        cpu_req_s = 0;
localparam [2:0] S_IDLE = 0, S_CPU = 1, S_CPU_RMW_RD = 2, S_CPU_RMW_WR = 3, S_VID = 4;
reg  [2:0] state = S_IDLE;
reg [15:0] old;

always @(posedge clk) begin
   cpu_req_s <= cpu_req;

   if(reset) begin
      state <= S_IDLE; req <= 1'b0; cpu_ack <= 1'b0; vid_ack <= 1'b0;
   end
   else begin
      // the handshakes' falling halves
      if(!cpu_req_s) cpu_ack <= 1'b0;
      if(!vid_req)   vid_ack <= 1'b0;

      case(state)
      S_IDLE: if(ready) begin
         if(cpu_req_s && !cpu_ack) begin
            addr <= cpu_addr;
            if(cpu_we && cpu_mask != 0) begin
               req <= 1'b1; we <= 1'b0; state <= S_CPU_RMW_RD;
            end
            else begin
               req <= 1'b1; we <= cpu_we; din <= cpu_din; be <= cpu_be; state <= S_CPU;
            end
         end
         else if(vid_req && !vid_ack) begin
            addr <= vid_addr; req <= 1'b1; we <= 1'b0; state <= S_VID;
         end
      end
      S_CPU: if(ack) begin
         req <= 1'b0; cpu_dout <= dout; cpu_ack <= 1'b1; state <= S_IDLE;
      end
      S_CPU_RMW_RD: if(ack) begin
         old   <= dout;
         req   <= 1'b0;
         state <= S_CPU_RMW_WR;
      end
      S_CPU_RMW_WR: begin
         // merge the new pixels into the old word, in the written byte lanes only
         req <= 1'b1; we <= 1'b1; be <= 2'b11;
         din <= (cpu_mask == 2'd1) ?
                ((cpu_din & mask2(cpu_din)) | (old & ~mask2(cpu_din))) :
                ((cpu_din & mask4(cpu_din)) | (old & ~mask4(cpu_din)));
         if(!cpu_be[1]) din[15:8] <= old[15:8];
         if(!cpu_be[0]) din[7:0]  <= old[7:0];
         state <= S_CPU;
      end
      S_VID: if(ack) begin
         req <= 1'b0; vid_dout <= dout; vid_ack <= 1'b1; state <= S_IDLE;
      end
      default: state <= S_IDLE;
      endcase
   end
end

endmodule
