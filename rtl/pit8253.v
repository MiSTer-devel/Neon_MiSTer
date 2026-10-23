//
// pit8253.v
//
// K580VI53 (8253) programmable interval timer, three channels, as NeonBTL
// models it (emubase/pit8253.cpp): modes 0..5 with 6 and 7 aliased to
// 2 and 3, counting on the 2 MHz tick, gate edges reloading the count
// only after a count has been written.
//
module pit8253
(
   input             clk,
   input             reset,
   input             tick,        // 2 MHz count enable
   input       [2:0] gate,

   input       [1:0] addr,        // 0..2 counters, 3 control
   input       [7:0] din,
   input             wr,
   input             rd,          // a read strobe: the lo/hi toggles advance on it
   output reg  [7:0] dout,
   output      [2:0] out
);

reg  [5:0] control[3];
reg  [1:0] phase[3];
reg [15:0] value[3];
reg [15:0] count[3];
reg [15:0] latch[3];
reg        gateprev[3];
reg        writehi[3];
reg        readhi[3];
reg        output_r[3];
reg        loaded[3];

assign out = {output_r[2], output_r[1], output_r[0]};

function [2:0] mode(input [5:0] ctl);
   mode = (ctl[3:1] >= 3'd6) ? {1'b0, ctl[2:1]} : ctl[3:1];
endfunction

// the control word selects the channel by its top two bits
wire [1:0] wsel = (addr == 2'd3) ? din[7:6] : addr;

integer i;
always @(posedge clk) begin
   if(reset) begin
      for(i = 0; i < 3; i = i + 1) begin
         control[i] <= 0; phase[i] <= 0; value[i] <= 0; count[i] <= 0; latch[i] <= 0;
         gateprev[i] <= 1'b1; writehi[i] <= 0; readhi[i] <= 0; output_r[i] <= 0; loaded[i] <= 0;
      end
   end
   else begin
      // ---- bus write ----
      if(wr) begin
         if(addr == 2'd3) begin
            if(din[7:6] != 2'b11) begin
               control[wsel] <= din[5:0];
               writehi[wsel] <= 1'b0;
               readhi[wsel]  <= 1'b0;
               if(din[5:4] == 2'b00) latch[wsel] <= value[wsel];
               else begin
                  phase[wsel]    <= 0;
                  loaded[wsel]   <= 1'b0;
                  output_r[wsel] <= (mode(din[5:0]) != 0);
               end
            end
         end
         else begin
            case(control[addr][5:4])
            2'd1: begin count[addr][7:0]  <= din; loaded[addr] <= 1'b1; end
            2'd2: begin count[addr][15:8] <= din; loaded[addr] <= 1'b1; end
            2'd3: begin
               if(writehi[addr]) begin count[addr][15:8] <= din; loaded[addr] <= 1'b1; end
               else count[addr][7:0] <= din;
               writehi[addr] <= ~writehi[addr];
            end
            default: ;
            endcase
            case(mode(control[addr]))
            3'd2, 3'd3: if(phase[addr] == 0) phase[addr] <= 2'd1;
            3'd0, 3'd4: phase[addr] <= 2'd1;
            default: ;
            endcase
         end
      end

      // ---- bus read ----
      if(rd && addr != 2'd3) begin
         case(control[addr][5:4])
         2'd1: dout <= value[addr][7:0];
         2'd2: dout <= value[addr][15:8];
         2'd3: begin dout <= readhi[addr] ? value[addr][15:8] : value[addr][7:0]; readhi[addr] <= ~readhi[addr]; end
         default: begin dout <= readhi[addr] ? latch[addr][15:8] : latch[addr][7:0]; readhi[addr] <= ~readhi[addr]; end
         endcase
      end
      if(rd && addr == 2'd3) dout <= 8'd0;

      // ---- counting ----
      if(tick) for(i = 0; i < 3; i = i + 1) begin
         gateprev[i] <= gate[i];
         case(mode(control[i]))
         3'd0: begin   // interrupt on terminal count
            if(phase[i] != 0) begin
               if(phase[i] == 2'd1) begin value[i] <= count[i]; phase[i] <= 2'd2; end
               else if(gate[i]) begin
                  if(phase[i] == 2'd2 && value[i] <= 16'd1) begin phase[i] <= 2'd3; value[i] <= 16'hffff; output_r[i] <= 1'b1; end
                  else value[i] <= value[i] - 1'd1;
               end
            end
         end
         3'd1: begin   // retriggerable one-shot
            case(phase[i])
            2'd0: begin if(loaded[i] && !gateprev[i] && gate[i]) phase[i] <= 2'd1; value[i] <= value[i] - 1'd1; end
            2'd1: begin value[i] <= count[i] - 1'd1; output_r[i] <= 1'b0; phase[i] <= 2'd2; end
            2'd2: begin if(value[i] == 0) begin output_r[i] <= 1'b1; phase[i] <= 2'd3; end value[i] <= value[i] - 1'd1; end
            2'd3: value[i] <= value[i] - 1'd1;
            endcase
         end
         3'd2: begin   // rate generator
            if(!gate[i]) output_r[i] <= 1'b1;
            else if(loaded[i] && !gateprev[i] && gate[i]) begin output_r[i] <= (phase[i] == 0) ? 1'b1 : output_r[i]; phase[i] <= 2'd1; end
            else case(phase[i])
            2'd0: output_r[i] <= 1'b1;
            2'd1: begin value[i] <= count[i]; phase[i] <= 2'd2; end
            2'd2: begin
               if(value[i] == 0) value[i] <= 16'hffff;
               else if(value[i] <= 16'd2) phase[i] <= 2'd3;
               else value[i] <= value[i] - 1'd1;
            end
            2'd3: begin output_r[i] <= 1'b0; value[i] <= count[i]; phase[i] <= 2'd2; end
            endcase
         end
         3'd3: begin   // square wave
            if(!gate[i] || phase[i] == 0) output_r[i] <= 1'b1;
            else if(phase[i] == 2'd1) begin value[i] <= count[i]; phase[i] <= 2'd2; end
            else begin
               // the next value, then the output level from it
               if(value[i] == 0) begin
                  value[i] <= 16'hffff;
                  output_r[i] <= (17'h0ffff > ({(count[i] == 0), count[i]} >> 1));
               end
               else if(value[i] > 16'd1) begin
                  value[i] <= value[i] - 1'd1;
                  output_r[i] <= ({1'b0, value[i] - 1'd1} > ({(count[i] == 0), count[i]} >> 1));
               end
               else begin
                  value[i] <= count[i];
                  output_r[i] <= ({(count[i] == 0), count[i]} > ({(count[i] == 0), count[i]} >> 1));
               end
            end
         end
         3'd4, 3'd5: begin   // software / hardware triggered strobe
            if(!(mode(control[i]) == 3'd4 && !gate[i])) case(phase[i])
            2'd0: if(loaded[i] && !gateprev[i] && gate[i]) phase[i] <= 2'd1;
            2'd1: begin phase[i] <= 2'd2; value[i] <= count[i]; end
            2'd2: begin
               if(value[i] > 0) value[i] <= value[i] - 1'd1;
               else begin output_r[i] <= 1'b0; phase[i] <= 2'd3; end
            end
            2'd3: begin phase[i] <= 2'd0; value[i] <= value[i] - 1'd1; output_r[i] <= 1'b1; end
            endcase
         end
         default: ;
         endcase
      end
   end
end

endmodule
