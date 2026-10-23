//
// sim_top.sv
//
// Simulation top: emu with the framework stubbed, an SDRAM model on the
// memory pins, the video and audio out.
//
module sim_top
(
   input         CLK_50M,       // the 64 MHz system clock in fact: pll_sim passes it through
   input         RESET,
   input  [10:0] ps2_key /*verilator public*/,
   input  [24:0] ps2_mouse,

   // the HPS side of the sector interface (see hps_io_sim.sv)
   input  [ 1:0] img_mounted,
   input  [31:0] img_size,
   output [31:0] sd_lba,
   output [ 1:0] sd_rd,
   output [ 1:0] sd_wr,
   input  [ 1:0] sd_ack,
   input  [ 7:0] sd_buff_addr,
   input  [15:0] sd_buff_dout,
   output [15:0] sd_buff_din,
   input         sd_buff_wr,

   output        CE_PIXEL,
   output [ 7:0] VGA_R,
   output [ 7:0] VGA_G,
   output [ 7:0] VGA_B,
   output        VGA_HS,
   output        VGA_VS,
   output        VGA_DE,
   output [15:0] AUDIO_L,
   output [15:0] AUDIO_R,
   output        LED_USER
);

wire [45:0] HPS_BUS;

wire [15:0] SDRAM_DQ;
wire [12:0] SDRAM_A;
wire  [1:0] SDRAM_BA;
wire        SDRAM_DQML, SDRAM_DQMH, SDRAM_nCS, SDRAM_nWE, SDRAM_nRAS, SDRAM_nCAS, SDRAM_CKE, SDRAM_CLK;

emu emu
(
   .CLK_50M (CLK_50M),
   .RESET   (RESET),
   .HPS_BUS (HPS_BUS),
   .CE_PIXEL(CE_PIXEL),
   .VGA_R   (VGA_R),
   .VGA_G   (VGA_G),
   .VGA_B   (VGA_B),
   .VGA_HS  (VGA_HS),
   .VGA_VS  (VGA_VS),
   .VGA_DE  (VGA_DE),
   .AUDIO_L (AUDIO_L),
   .AUDIO_R (AUDIO_R),
   .LED_USER(LED_USER),
   .SDRAM_DQ(SDRAM_DQ), .SDRAM_A(SDRAM_A), .SDRAM_BA(SDRAM_BA),
   .SDRAM_DQML(SDRAM_DQML), .SDRAM_DQMH(SDRAM_DQMH), .SDRAM_nCS(SDRAM_nCS),
   .SDRAM_nWE(SDRAM_nWE), .SDRAM_nRAS(SDRAM_nRAS), .SDRAM_nCAS(SDRAM_nCAS),
   .SDRAM_CKE(SDRAM_CKE), .SDRAM_CLK(SDRAM_CLK)
);

sdram_model sdram
(
   .clk(SDRAM_CLK), .dq(SDRAM_DQ), .a(SDRAM_A), .ba(SDRAM_BA),
   .dqml(SDRAM_DQML), .dqmh(SDRAM_DQMH), .ncs(SDRAM_nCS), .nwe(SDRAM_nWE),
   .nras(SDRAM_nRAS), .ncas(SDRAM_nCAS)
);

assign sd_lba      = emu.hps_io.sd_lba[0];
assign sd_rd       = emu.hps_io.sd_rd;
assign sd_wr       = emu.hps_io.sd_wr;
assign sd_buff_din = emu.hps_io.sd_buff_din[0];

monitor mon();

endmodule
