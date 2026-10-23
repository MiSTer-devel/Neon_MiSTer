//
// sdram.sv
//
// Soyuz-Neon main memory on the MiSTer SDRAM board: the command sequence,
// state numbering and data capture of the TSConf core's sdram.v (TS-Labs /
// Sorgelig, GPL v3) behind a single 16-bit word port with byte enables,
// req held high until ack.  The earlier slot-based controller
// (sdram_slot.sv) passed simulation and timing analysis but corrupted
// single reads on real hardware; this sequence is proven on the board.
//
// ACTIVE in state 25, READ/WRITE with auto precharge in state 27 (tRCD two
// clocks), SDRAM_DQ registered every clock and taken in state 24, four
// clocks after the READ (CAS latency 2 on the inverted SDRAM clock).
//
module sdram
(
   input             clk,          // 64 MHz
   input             init,         // high: reinitialise the chip
   output reg        ready,        // the chip is initialised

   inout      [15:0] SDRAM_DQ,
   output reg [12:0] SDRAM_A,
   output            SDRAM_DQML,
   output            SDRAM_DQMH,
   output reg  [1:0] SDRAM_BA,
   output            SDRAM_nCS,
   output            SDRAM_nWE,
   output            SDRAM_nRAS,
   output            SDRAM_nCAS,
   output            SDRAM_CKE,
   output            SDRAM_CLK,

   input             req,
   input             we,
   input      [21:1] addr,         // word address
   input      [15:0] din,
   input       [1:0] be,           // byte enables for a write
   output reg [15:0] dout,
   output reg        ack           // one clock: dout valid / write taken
);

localparam [2:0] CMD_NOP = 3'b111, CMD_ACTIVE = 3'b011, CMD_READ = 3'b101, CMD_WRITE = 3'b100,
                 CMD_PRECHARGE = 3'b010, CMD_REFRESH = 3'b001, CMD_LOAD_MODE = 3'b000;

localparam STARTUP_CYCLES = 14'd8000;    // > 100 us at 64 MHz
localparam REFRESH_CYCLES = 9'd480;      // < 7.8 us: 64 ms / 8192 rows

reg  [2:0] cmd = CMD_NOP;
reg [15:0] dq_out;
reg        dq_oe = 0;
reg [15:0] data;
assign SDRAM_DQ   = dq_oe ? dq_out : 16'bZ;
assign SDRAM_CKE  = 1'b1;
assign SDRAM_nCS  = 1'b0;
assign SDRAM_nRAS = cmd[2];
assign SDRAM_nCAS = cmd[1];
assign SDRAM_nWE  = cmd[0];
assign SDRAM_DQML = SDRAM_A[11];
assign SDRAM_DQMH = SDRAM_A[12];

reg [13:0] startup = 0;
reg  [8:0] refresh_cnt = 0;
reg        refresh_due = 0;
reg  [4:0] state = 0;
reg        rd = 0, rq = 0;
reg        pend = 0;          // a request was taken: wait for req to drop before the next
reg  [8:0] col;
reg [11:0] row;
reg  [1:0] dqm;
reg [15:0] wdata;

always @(posedge clk) begin
   cmd   <= CMD_NOP;
   dq_oe <= 1'b0;
   ack   <= 1'b0;
   data  <= SDRAM_DQ;
   if(!req) pend <= 1'b0;

   if(refresh_cnt == REFRESH_CYCLES) refresh_due <= 1'b1;
   else refresh_cnt <= refresh_cnt + 1'd1;

   if(init) begin
      startup <= 0;
      ready   <= 1'b0;
      state   <= 0;
      rd      <= 1'b0;
      rq      <= 1'b0;
   end
   else if(!ready) begin
      SDRAM_BA <= 0;
      if(startup != STARTUP_CYCLES) begin
         startup <= startup + 1'd1;
         SDRAM_A <= 13'h0400;                   // DQM high while waiting
      end
      else begin
         state <= state + 1'd1;
         case(state)
         5'd0:  begin cmd <= CMD_PRECHARGE; SDRAM_A <= 13'h0400; end
         5'd3,
         5'd10: cmd <= CMD_REFRESH;
         5'd17: begin cmd <= CMD_LOAD_MODE; SDRAM_A <= {3'b000, 1'b1, 2'b00, 3'b010, 1'b0, 3'b000}; end   // CL2, BL1
         5'd24: begin ready <= 1'b1; state <= 5'd24; refresh_cnt <= 0; refresh_due <= 1'b0; end
         default: ;
         endcase
      end
   end
   else begin
      state <= state + 1'd1;
      case(state)
      5'd24: begin                              // idle
         if(rd) begin dout <= data; ack <= 1'b1; end
         rd    <= 1'b0;
         rq    <= 1'b0;
         state <= 5'd24;
         if(refresh_due) begin
            refresh_due <= 1'b0;
            refresh_cnt <= 0;
            state       <= 5'd25;
         end
         else if(req && !pend) begin
            pend  <= 1'b1;
            rq    <= 1'b1;
            rd    <= ~we;
            row   <= addr[21:10];
            col   <= addr[9:1];
            dqm   <= we ? ~be : 2'b00;
            wdata <= din;
            state <= 5'd25;
         end
      end
      5'd25: begin
         if(rq) begin
            cmd      <= CMD_ACTIVE;
            SDRAM_A  <= {1'b0, row};
            SDRAM_BA <= 2'b00;
         end
         else begin
            cmd   <= CMD_REFRESH;
            state <= 5'd19;
         end
      end
      5'd27: begin                              // single read/write with auto precharge
         SDRAM_A <= {dqm, 2'b10, col};
         if(rd) begin
            cmd   <= CMD_READ;
            state <= 5'd21;
         end
         else begin
            cmd    <= CMD_WRITE;
            dq_out <= wdata;
            dq_oe  <= 1'b1;
            ack    <= 1'b1;
            state  <= 5'd22;
         end
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
