//
// sdram.sv
//
// Soyuz-Neon main memory on the MiSTer SDRAM board: a single 16-bit word
// port with byte enables, one word per access, req held high until ack.
//
// The chip runs on the inverted 64 MHz clock, so it samples a command half
// a cycle after the register that drives it.  An access is ACTIVE, one
// idle clock (tRCD), then READ or WRITE with auto precharge.  A write is
// acknowledged with its command and the port is free four clocks later;
// a read's data (CAS latency 2) is registered three clocks after the READ
// and handed over the clock after that.  A refresh is done between
// accesses whenever one is due.  The 4 MB of the machine are bank 0, rows
// 0..4095 (address bits 21:10) and columns 0..511 (bits 9:1).
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

// commands as {nRAS, nCAS, nWE}
localparam [2:0] NOP = 3'b111, ACTIVE = 3'b011, READ = 3'b101, WRITE = 3'b100,
                 PRECHARGE = 3'b010, REFRESH = 3'b001, LOAD_MODE = 3'b000;

localparam [12:0] MODE_CL2_BL1  = 13'b000_1_00_010_0_000;  // single writes, CAS latency 2, burst 1
localparam [12:0] PRECHARGE_ALL = 13'b0_0100_0000_0000;    // A10 set; A12:11 double as DQM: both high
localparam [13:0] POWER_UP_WAIT = 14'd8000;                // 125 us
localparam  [8:0] REFRESH_EVERY = 9'd480;                  // 7.5 us: 8192 rows in 64 ms

localparam [3:0] I_WAIT = 4'd0, I_PRECHARGE = 4'd1, I_REFRESH1 = 4'd2, I_REFRESH2 = 4'd3, I_MODE = 4'd4, I_DONE = 4'd5;
localparam [3:0] S_IDLE = 4'd0, S_ACTIVE = 4'd1, S_RCD = 4'd2, S_COMMAND = 4'd3,
                 S_READ1 = 4'd4, S_READ2 = 4'd5, S_READ3 = 4'd6, S_READ_OUT = 4'd7,
                 S_WRITE1 = 4'd8, S_WRITE2 = 4'd9, S_REFRESH = 4'd10;

reg  [2:0] cmd = NOP;
reg [15:0] dq_out;
reg        dq_oe = 0;
reg [15:0] dq_in;                 // SDRAM_DQ as it was at the last clock

assign SDRAM_DQ   = dq_oe ? dq_out : 16'bZ;
assign SDRAM_CKE  = 1'b1;
assign SDRAM_nCS  = 1'b0;
assign {SDRAM_nRAS, SDRAM_nCAS, SDRAM_nWE} = cmd;
assign SDRAM_DQML = SDRAM_A[11];
assign SDRAM_DQMH = SDRAM_A[12];

reg [13:0] power_up = 0;
reg  [3:0] istate = I_WAIT;
reg  [2:0] pause = 0;             // clocks still to wait in the current state
reg  [3:0] state = S_IDLE;
reg  [8:0] refresh_timer = 0;
reg        refresh_due = 0;
reg        taken = 0;             // the request on the port has been served; wait for it to drop
reg        is_write = 0;
reg [11:0] row;
reg  [8:0] col;
reg  [1:0] mask;
reg [15:0] wdata;

always @(posedge clk) begin
   cmd   <= NOP;
   dq_oe <= 1'b0;
   ack   <= 1'b0;
   dq_in <= SDRAM_DQ;
   if(!req) taken <= 1'b0;

   if(refresh_timer == REFRESH_EVERY) refresh_due <= 1'b1;
   else refresh_timer <= refresh_timer + 1'd1;

   if(init) begin
      ready    <= 1'b0;
      power_up <= 0;
      istate   <= I_WAIT;
      state    <= S_IDLE;
      pause    <= 0;
      SDRAM_BA <= 2'b00;
      SDRAM_A  <= PRECHARGE_ALL;
   end
   else if(!ready) begin
      // the power-up sequence, with the data masked
      if(pause != 0) pause <= pause - 1'd1;
      else case(istate)
      I_WAIT:      if(power_up == POWER_UP_WAIT) istate <= I_PRECHARGE; else power_up <= power_up + 1'd1;
      I_PRECHARGE: begin cmd <= PRECHARGE; pause <= 3'd2; istate <= I_REFRESH1; end
      I_REFRESH1:  begin cmd <= REFRESH;   pause <= 3'd6; istate <= I_REFRESH2; end
      I_REFRESH2:  begin cmd <= REFRESH;   pause <= 3'd6; istate <= I_MODE; end
      I_MODE:      begin cmd <= LOAD_MODE; SDRAM_A <= MODE_CL2_BL1; pause <= 3'd6; istate <= I_DONE; end
      default:     begin ready <= 1'b1; refresh_timer <= 0; refresh_due <= 1'b0; end
      endcase
   end
   else if(pause != 0) pause <= pause - 1'd1;
   else case(state)
   S_IDLE: begin
      if(refresh_due) begin
         refresh_due   <= 1'b0;
         refresh_timer <= 0;
         state         <= S_REFRESH;
      end
      else if(req && !taken) begin
         taken    <= 1'b1;
         is_write <= we;
         row      <= addr[21:10];
         col      <= addr[9:1];
         mask     <= we ? ~be : 2'b00;
         wdata    <= din;
         state    <= S_ACTIVE;
      end
   end
   S_ACTIVE: begin
      cmd      <= ACTIVE;
      SDRAM_A  <= {1'b0, row};
      SDRAM_BA <= 2'b00;
      state    <= S_RCD;
   end
   S_RCD: state <= S_COMMAND;
   S_COMMAND: begin
      SDRAM_A <= {mask, 2'b10, col};            // A10: auto precharge
      if(is_write) begin
         cmd    <= WRITE;
         dq_out <= wdata;
         dq_oe  <= 1'b1;
         ack    <= 1'b1;
         state  <= S_WRITE1;
      end
      else begin
         cmd   <= READ;
         state <= S_READ1;
      end
   end
   S_READ1:  state <= S_READ2;
   S_READ2:  state <= S_READ3;                  // dq_in takes the data at the end of this clock
   S_READ3:  state <= S_READ_OUT;
   S_READ_OUT: begin
      dout  <= dq_in;
      ack   <= 1'b1;
      state <= S_IDLE;
   end
   S_WRITE1: state <= S_WRITE2;                 // tWR and the auto precharge
   S_WRITE2: state <= S_IDLE;
   S_REFRESH: begin
      cmd   <= REFRESH;
      pause <= 3'd4;                            // tRFC before the next command
      state <= S_IDLE;
   end
   default: state <= S_IDLE;
   endcase
end

// the chip's clock: the inverted system clock, out of the DDR register
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
sdram_clock
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
