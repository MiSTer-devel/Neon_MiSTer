//
// sdram.sv
//
// Soyuz-Neon main memory on the MiSTer SDRAM board: a single 16-bit port
// with byte enables, one access per fixed 8-clock slot at 64 MHz.
//
// Every access opens its row, reads or writes one word with auto
// precharge and is done inside the slot, so the next slot can go to any
// address; a refresh takes a slot of its own when it is due.  The 4 MB of
// the machine use one bank, rows 0..4095 (byte address bits 21:10) and
// columns 0..511 (bits 9:1).
//
// Timing at 64 MHz (15.6 ns): ACTIVE at phase 0, READ/WRITE at phase 2
// (tRCD 31 ns), CAS latency 2 so the data is latched at phase 5, and the
// auto precharge is long over by the next slot (tRC 125 ns).
//
// Based on the init and clock-out parts of Sorgelig's sdram.v (GPL v3).
//
module sdram
(
   input             clk,          // 64 MHz
   input             init,         // high: reinitialise the chip
   output reg        ready,        // the chip is initialised

   inout      [15:0] SDRAM_DQ,
   output reg [12:0] SDRAM_A,
   output reg        SDRAM_DQML,
   output reg        SDRAM_DQMH,
   output reg  [1:0] SDRAM_BA,
   output            SDRAM_nCS,
   output            SDRAM_nWE,
   output            SDRAM_nRAS,
   output            SDRAM_nCAS,
   output            SDRAM_CKE,
   output            SDRAM_CLK,

   // the port: req held high until ack
   input             req,
   input             we,
   input      [21:1] addr,         // word address
   input      [15:0] din,
   input       [1:0] be,           // byte enables for a write
   output reg [15:0] dout,
   output reg        ack           // one clock: dout valid / write taken
);

assign SDRAM_CKE  = 1'b1;
assign SDRAM_nCS  = 1'b0;
assign SDRAM_nRAS = command[2];
assign SDRAM_nCAS = command[1];
assign SDRAM_nWE  = command[0];

localparam BURST_LENGTH   = 3'b000;   // 1
localparam ACCESS_TYPE    = 1'b0;     // sequential
localparam CAS_LATENCY    = 3'd2;
localparam OP_MODE        = 2'b00;
localparam NO_WRITE_BURST = 1'b1;
localparam MODE = {3'b000, NO_WRITE_BURST, OP_MODE, CAS_LATENCY, ACCESS_TYPE, BURST_LENGTH};

localparam [2:0] CMD_NOP = 3'b111, CMD_ACTIVE = 3'b011, CMD_READ = 3'b101, CMD_WRITE = 3'b100,
                 CMD_PRECHARGE = 3'b010, CMD_AUTO_REFRESH = 3'b001, CMD_LOAD_MODE = 3'b000;

localparam STARTUP_CYCLES  = 14'd8000;   // > 100 us at 64 MHz
localparam REFRESH_CYCLES  = 9'd480;     // < 7.8 us: 64 ms / 8192 rows

reg  [2:0] command = CMD_NOP;
reg [15:0] dq_out;
reg        dq_oe = 0;
assign SDRAM_DQ = dq_oe ? dq_out : 16'bZ;

reg [13:0] startup = 0;
reg  [8:0] refresh_cnt = 0;
reg        refresh_due = 0;
reg  [2:0] ph = 0;             // phase in the slot
reg        slot_rw = 0;        // this slot is an access
reg        slot_we = 0;
reg  [1:0] slot_be;
reg [15:0] slot_din;
reg [21:1] slot_addr;

always @(posedge clk) begin
   command <= CMD_NOP;
   dq_oe   <= 1'b0;
   ack     <= 1'b0;

   if(init) begin
      startup     <= 0;
      ready       <= 1'b0;
      ph          <= 0;
      slot_rw     <= 1'b0;
      refresh_cnt <= 0;
      refresh_due <= 1'b0;
      SDRAM_DQML  <= 1'b1;
      SDRAM_DQMH  <= 1'b1;
   end
   else if(!ready) begin
      startup    <= startup + 1'd1;
      SDRAM_A    <= 0;
      SDRAM_BA   <= 0;
      SDRAM_DQML <= 1'b1;
      SDRAM_DQMH <= 1'b1;
      if(startup == STARTUP_CYCLES)      begin command <= CMD_PRECHARGE; SDRAM_A[10] <= 1'b1; end
      if(startup == STARTUP_CYCLES + 8)  command <= CMD_AUTO_REFRESH;
      if(startup == STARTUP_CYCLES + 16) command <= CMD_AUTO_REFRESH;
      if(startup == STARTUP_CYCLES + 24) command <= CMD_AUTO_REFRESH;
      if(startup == STARTUP_CYCLES + 32) command <= CMD_AUTO_REFRESH;
      if(startup == STARTUP_CYCLES + 40) begin command <= CMD_LOAD_MODE; SDRAM_A <= MODE; end
      if(startup == STARTUP_CYCLES + 48) begin ready <= 1'b1; ph <= 0; end
   end
   else begin
      ph <= ph + 1'd1;

      if(refresh_cnt == REFRESH_CYCLES) refresh_due <= 1'b1;
      else refresh_cnt <= refresh_cnt + 1'd1;

      case(ph)
      3'd0: begin
         slot_rw <= 1'b0;
         if(refresh_due) begin
            command     <= CMD_AUTO_REFRESH;
            refresh_due <= 1'b0;
            refresh_cnt <= 0;
         end
         else if(req) begin
            command   <= CMD_ACTIVE;
            SDRAM_A   <= {1'b0, addr[21:10]};
            SDRAM_BA  <= 2'b00;
            slot_rw   <= 1'b1;
            slot_we   <= we;
            slot_be   <= be;
            slot_din  <= din;
            slot_addr <= addr;
         end
      end
      3'd2: if(slot_rw) begin
         SDRAM_A <= {4'b0010, slot_addr[9:1]};      // A10: auto precharge
         if(slot_we) begin
            command    <= CMD_WRITE;
            dq_out     <= slot_din;
            dq_oe      <= 1'b1;
            SDRAM_DQMH <= ~slot_be[1];
            SDRAM_DQML <= ~slot_be[0];
            ack        <= 1'b1;
         end
         else begin
            command    <= CMD_READ;
            SDRAM_DQMH <= 1'b0;
            SDRAM_DQML <= 1'b0;
         end
      end
      3'd3: begin
         SDRAM_DQMH <= 1'b1;
         SDRAM_DQML <= 1'b1;
      end
      3'd5: if(slot_rw & ~slot_we) begin
         dout <= SDRAM_DQ;
         ack  <= 1'b1;
      end
      default: ;
      endcase
   end
end

altddio_out
#(
   .extend_oe_disable("OFF"),
   .intended_device_family("Cyclone V"),
   .invert_output("OFF"),
   .lpm_hint("UNUSED"),
   .lpm_type("altddio_out"),
   .oe_reg("UNREGISTERED"),
   .power_up_high("OFF"),
   .width(1)
)
sdramclk_ddr
(
   .datain_h(1'b0),
   .datain_l(1'b1),
   .outclock(clk),
   .dataout(SDRAM_CLK),
   .aclr(1'b0),
   .aset(1'b0),
   .oe(1'b1),
   .outclocken(1'b1),
   .sclr(1'b0),
   .sset(1'b0)
);

endmodule
