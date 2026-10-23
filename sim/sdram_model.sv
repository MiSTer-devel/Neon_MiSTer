//
// sdram_model.sv
//
// A behavioural 16-bit SDRAM for the simulation: ACTIVE, READ and WRITE
// with CAS latency 2 and single-word bursts; precharge and refresh are
// accepted and ignored.  4096 rows of 512 columns in bank 0 = 2M words,
// the 4 MB of the machine.
//
module sdram_model
(
   input         clk,
   inout  [15:0] dq,
   input  [12:0] a,
   input   [1:0] ba,
   input         dqml, dqmh,
   input         ncs, nwe, nras, ncas
);

reg [15:0] mem[2097152] /*verilator public*/;

reg [11:0] row = 0;
reg  [2:0] cmd;
reg        rd1 = 0, rd2 = 0;
reg [15:0] rdata1, rdata2;
reg        drive = 0;
reg [15:0] dout;

wire [20:0] addr = {row[11:0], a[8:0]};

always @(posedge clk) begin
   cmd = ncs ? 3'b111 : {nras, ncas, nwe};
   rd2 <= rd1; rdata2 <= rdata1;
   rd1 <= 1'b0;
   case(cmd)
   3'b011: row <= a[11:0];                                  // ACTIVE
   3'b101: begin rd1 <= 1'b1; rdata1 <= mem[addr]; end      // READ
   3'b100: begin                                            // WRITE
      if(!dqml) mem[addr][7:0]  <= dq[7:0];
      if(!dqmh) mem[addr][15:8] <= dq[15:8];
   end
   default: ;
   endcase
   drive <= rd2;
   dout  <= rdata2;
end

assign dq = drive ? dout : 16'bz;

endmodule
