//
// dpram.sv
//
// A true dual-port RAM with a clock a port.  Quartus does not infer one
// with two clocks from a template, so it is an altsyncram; the
// behavioural form is for the simulation.
//
module dpram #(parameter AW = 10, parameter DW = 8)
(
   input               clk_a,
   input      [AW-1:0] addr_a,
   input      [DW-1:0] din_a,
   input               we_a,
   output     [DW-1:0] dout_a,

   input               clk_b,
   input      [AW-1:0] addr_b,
   input      [DW-1:0] din_b,
   input               we_b,
   output     [DW-1:0] dout_b
);

`ifdef VERILATOR

reg [DW-1:0] mem[2**AW];
reg [DW-1:0] q_a, q_b;
assign dout_a = q_a;
assign dout_b = q_b;

always @(posedge clk_a) begin
   if(we_a) mem[addr_a] <= din_a;
   q_a <= mem[addr_a];
end

always @(posedge clk_b) begin
   if(we_b) mem[addr_b] <= din_b;
   q_b <= mem[addr_b];
end

`else

altsyncram altsyncram_component
(
   .clock0(clk_a),
   .address_a(addr_a),
   .data_a(din_a),
   .wren_a(we_a),
   .q_a(dout_a),

   .clock1(clk_b),
   .address_b(addr_b),
   .data_b(din_b),
   .wren_b(we_b),
   .q_b(dout_b),

   .aclr0(1'b0), .aclr1(1'b0),
   .addressstall_a(1'b0), .addressstall_b(1'b0),
   .byteena_a(1'b1), .byteena_b(1'b1),
   .clocken0(1'b1), .clocken1(1'b1), .clocken2(1'b1), .clocken3(1'b1),
   .eccstatus(),
   .rden_a(1'b1), .rden_b(1'b1)
);
defparam
   altsyncram_component.address_reg_b = "CLOCK1",
   altsyncram_component.clock_enable_input_a = "BYPASS",
   altsyncram_component.clock_enable_input_b = "BYPASS",
   altsyncram_component.clock_enable_output_a = "BYPASS",
   altsyncram_component.clock_enable_output_b = "BYPASS",
   altsyncram_component.indata_reg_b = "CLOCK1",
   altsyncram_component.intended_device_family = "Cyclone V",
   altsyncram_component.lpm_type = "altsyncram",
   altsyncram_component.numwords_a = 2**AW,
   altsyncram_component.numwords_b = 2**AW,
   altsyncram_component.operation_mode = "BIDIR_DUAL_PORT",
   altsyncram_component.outdata_aclr_a = "NONE",
   altsyncram_component.outdata_aclr_b = "NONE",
   altsyncram_component.outdata_reg_a = "UNREGISTERED",
   altsyncram_component.outdata_reg_b = "UNREGISTERED",
   altsyncram_component.power_up_uninitialized = "FALSE",
   altsyncram_component.read_during_write_mode_port_a = "NEW_DATA_NO_NBE_READ",
   altsyncram_component.read_during_write_mode_port_b = "NEW_DATA_NO_NBE_READ",
   altsyncram_component.widthad_a = AW,
   altsyncram_component.widthad_b = AW,
   altsyncram_component.width_a = DW,
   altsyncram_component.width_b = DW,
   altsyncram_component.width_byteena_a = 1,
   altsyncram_component.width_byteena_b = 1,
   altsyncram_component.wrcontrol_wraddress_reg_b = "CLOCK1";

`endif

endmodule
