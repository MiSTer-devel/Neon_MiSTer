//
// pll_sim.v
//
// Simulation stand-in for rtl/pll.v: outclk_0 is the reference itself
// (the testbench clocks it at the 64 MHz rate) and outclk_1 divides it
// by 8 for the CPU.
//
module pll
(
   input      refclk,
   input      rst,
   output     outclk_0,
   output reg outclk_1 = 1'b0,
   output     locked
);

reg [1:0] cnt = 0;
always @(posedge refclk) begin
   cnt <= cnt + 1'd1;
   if(cnt == 2'd3) outclk_1 <= ~outclk_1;
end

assign outclk_0 = refclk;
assign locked   = ~rst;

endmodule

// the DDR clock-out cell: the SDRAM clock is the inverted system clock
module altddio_out #(parameter extend_oe_disable = "OFF", intended_device_family = "", invert_output = "OFF",
                     lpm_hint = "", lpm_type = "", oe_reg = "", power_up_high = "OFF", width = 1)
(
   input  [width-1:0] datain_h,
   input  [width-1:0] datain_l,
   input              outclock,
   output [width-1:0] dataout,
   input              aclr, aset, oe, outclocken, sclr, sset
);
assign dataout = outclock ? datain_h : datain_l;
endmodule
