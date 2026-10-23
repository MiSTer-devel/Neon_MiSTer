//
// keyboard.sv
//
// PS/2 (set 2, as hps_io reports it) to the Soyuz-Neon keyboard matrix:
// eight row bytes as the KR580VV79 keyboard controller returns them.
//
// A row byte is the OR of its pressed keys' codes; codes 1..6 in the low
// three bits name one of six keys and bits 3..7 are one key each, so the
// matrix is rebuilt from the set of held keys whenever it may have
// changed, as NeonBTL does every frame.  The table is NeonBTL's
// arrPcscan2VscanLat (ScreenView.cpp), moved from Windows virtual keys to
// PS/2 scan codes.
//
module keyboard
(
   input             clk,
   input             reset,
   input      [10:0] ps2_key,      // hps_io: [10] toggle, [9] pressed, [8] extended, [7:0] code
   output reg  [7:0] matrix[8]
);

// {row[2:0], code[7:0]}; 0 is a key the machine does not have
function [10:0] neon_key(input ext, input [7:0] code);
   if(!ext)
      case(code)
      8'h66: neon_key = 11'h503;  // Backspace  - ЗБ
      8'h0D: neon_key = 11'h180;  // Tab        - ТАБ
      8'h5A: neon_key = 11'h608;  // Enter      - ВВОД
      8'h76: neon_key = 11'h080;  // Esc        - АР2
      8'h29: neon_key = 11'h408;  // Space
      8'h45: neon_key = 11'h720;  // 0
      8'h16: neon_key = 11'h102;  // 1
      8'h1E: neon_key = 11'h104;  // 2
      8'h26: neon_key = 11'h103;  // 3
      8'h25: neon_key = 11'h008;  // 4
      8'h2E: neon_key = 11'h110;  // 5
      8'h36: neon_key = 11'h105;  // 6
      8'h3D: neon_key = 11'h020;  // 7
      8'h3E: neon_key = 11'h006;  // 8
      8'h46: neon_key = 11'h706;  // 9
      8'h1C: neon_key = 11'h303;  // A
      8'h32: neon_key = 11'h320;  // B
      8'h21: neon_key = 11'h202;  // C
      8'h23: neon_key = 11'h206;  // D
      8'h24: neon_key = 11'h108;  // E
      8'h2B: neon_key = 11'h201;  // F
      8'h34: neon_key = 11'h205;  // G
      8'h33: neon_key = 11'h620;  // H
      8'h43: neon_key = 11'h308;  // I
      8'h3B: neon_key = 11'h101;  // J
      8'h42: neon_key = 11'h203;  // K
      8'h4B: neon_key = 11'h220;  // L
      8'h3A: neon_key = 11'h403;  // M
      8'h31: neon_key = 11'h210;  // N
      8'h44: neon_key = 11'h305;  // O
      8'h4D: neon_key = 11'h208;  // P
      8'h15: neon_key = 11'h301;  // Q
      8'h2D: neon_key = 11'h310;  // R
      8'h1B: neon_key = 11'h404;  // S
      8'h2C: neon_key = 11'h410;  // T
      8'h3C: neon_key = 11'h204;  // U
      8'h2A: neon_key = 11'h506;  // V
      8'h1D: neon_key = 11'h304;  // W
      8'h22: neon_key = 11'h405;  // X
      8'h35: neon_key = 11'h302;  // Y
      8'h1A: neon_key = 11'h606;  // Z
      8'h70: neon_key = 11'h580;  // KP 0
      8'h69: neon_key = 11'h501;  // KP 1
      8'h72: neon_key = 11'h601;  // KP 2
      8'h7A: neon_key = 11'h701;  // KP 3
      8'h6B: neon_key = 11'h502;  // KP 4
      8'h73: neon_key = 11'h602;  // KP 5
      8'h74: neon_key = 11'h702;  // KP 6
      8'h6C: neon_key = 11'h540;  // KP 7
      8'h75: neon_key = 11'h640;  // KP 8
      8'h7D: neon_key = 11'h740;  // KP 9
      8'h79: neon_key = 11'h504;  // KP +
      8'h7B: neon_key = 11'h140;  // KP -
      8'h71: neon_key = 11'h680;  // KP .
      8'h05: neon_key = 11'h002;  // F1  - К1
      8'h06: neon_key = 11'h004;  // F2  - К2
      8'h04: neon_key = 11'h003;  // F3  - К3
      8'h0C: neon_key = 11'h010;  // F4  - К4
      8'h03: neon_key = 11'h005;  // F5  - К5
      8'h0B: neon_key = 11'h703;  // F6  - ПОМ
      8'h83: neon_key = 11'h603;  // F7  - УСТ
      8'h0A: neon_key = 11'h604;  // F8  - ИСП
      8'h78: neon_key = 11'h704;  // F11 - СБРОС
      8'h07: neon_key = 11'h240;  // F12 - СТОП
      8'h12: neon_key = 11'h440;  // Left Shift  - НР
      8'h59: neon_key = 11'h480;  // Right Shift - АЛФ
      8'h14: neon_key = 11'h280;  // Left Ctrl   - УПР
      8'h4C: neon_key = 11'h708;  // ;
      8'h55: neon_key = 11'h705;  // =
      8'h41: neon_key = 11'h406;  // ,
      8'h4E: neon_key = 11'h605;  // -
      8'h49: neon_key = 11'h505;  // .
      8'h4A: neon_key = 11'h710;  // /
      8'h0E: neon_key = 11'h001;  // `
      8'h54: neon_key = 11'h120;  // [
      8'h5D: neon_key = 11'h520;  // backslash
      8'h5B: neon_key = 11'h106;  // ]
      8'h52: neon_key = 11'h306;  // '
      default: neon_key = 11'h000;
      endcase
   else
      case(code)
      8'h5A: neon_key = 11'h780;  // KP Enter
      8'h6B: neon_key = 11'h420;  // Left
      8'h75: neon_key = 11'h610;  // Up
      8'h74: neon_key = 11'h508;  // Right
      8'h72: neon_key = 11'h510;  // Down
      8'h14: neon_key = 11'h380;  // Right Ctrl - ГРАФ
      8'h4A: neon_key = 11'h710;  // KP /
      default: neon_key = 11'h000;
      endcase
endfunction

// ---------------------------------------------------------------------
// The set of held keys, 256 plain and 256 extended codes
// ---------------------------------------------------------------------
reg [511:0] held = 0;
reg         old_toggle = 0;
reg         dirty = 0;

// ---------------------------------------------------------------------
// Rebuild: walk the 512 codes, OR the held ones into a fresh matrix
// ---------------------------------------------------------------------
reg  [9:0] scan = 0;         // [8:0] the code, [9] done flag unused
reg        scanning = 0;
reg  [7:0] build[8];
wire [10:0] k = neon_key(scan[8], scan[7:0]);

integer i;
always @(posedge clk) begin
   old_toggle <= ps2_key[10];
   if(reset) begin
      held  <= 0;
      dirty <= 1'b1;
      scanning <= 1'b0;
      for(i = 0; i < 8; i = i + 1) matrix[i] <= 8'd0;
   end
   else begin
      if(old_toggle != ps2_key[10]) begin
         held[{ps2_key[8], ps2_key[7:0]}] <= ps2_key[9];
         dirty <= 1'b1;
      end

      if(!scanning) begin
         if(dirty) begin
            dirty    <= 1'b0;
            scanning <= 1'b1;
            scan     <= 0;
            for(i = 0; i < 8; i = i + 1) build[i] <= 8'd0;
         end
      end
      else begin
         if(held[scan[8:0]] && k != 0) build[k[10:8]] <= build[k[10:8]] | k[7:0];
         scan <= scan + 1'd1;
         if(scan[8:0] == 9'h1ff) begin
            scanning <= 1'b0;
            for(i = 0; i < 8; i = i + 1) matrix[i] <= build[i];
         end
      end
   end
end

endmodule
