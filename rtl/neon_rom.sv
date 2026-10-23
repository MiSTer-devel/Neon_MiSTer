//
// neon_rom.sv
//
// The 16 KB firmware ROM (two KM1801RR1), 8K x 16, built in from
// rom/pk11_rom.hex and reloadable from the OSD (boot.rom).
//
module neon_rom
(
   input             clk,
   input      [13:1] addr,
   output reg [15:0] dout,

   input             wr_clk,
   input      [13:1] wr_addr,
   input      [15:0] wr_data,
   input             wr_en
);

reg [15:0] rom[8192];
initial $readmemh("rtl/rom/pk11_rom.hex", rom);

always @(posedge clk)    dout <= rom[addr];
always @(posedge wr_clk) if(wr_en) rom[wr_addr] <= wr_data;

endmodule
