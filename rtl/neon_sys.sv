//
// neon_sys.sv
//
// The Soyuz-Neon system board around the VM2: the memory dispatcher (HR/UR
// registers, the ROM window, the emulated-register area with its EF0/EF1
// trap), and the I/O block at 161000-161777: the KR580VN59A interrupt
// controller, the two K580VI53 sound timers, the KR580VV55A parallel
// interface with the mouse, the KR580VV79 keyboard controller, the
// KR512VI1 real-time clock, the KR1809VG7 hard disk registers, and the
// serial port status.  The floppy controller and the 2 KB disk buffer are
// in fdc.sv, the RAM goes out on a request/acknowledge port to neon_mem.
//
// Everything here is on the 8 MHz CPU clock; the RAM port crosses to the
// 64 MHz clock, which is in phase with it from the same PLL.
//
// Behaviour follows NeonBTL (emubase/Board.cpp).
//
module neon_sys
(
   input             clk,          // 8 MHz, the CPU clock
   input             reset,        // hard reset: the OSD, the framework
   input       [1:0] ram_banks0,   // RAM modules in bank 0: 0 none, 1 2x256K, 2 2x1M
   input       [1:0] ram_banks1,   // and bank 1
   input             timer64,      // IRQ5 from the RTC's 64 Hz instead of the 50 Hz frame

   // VM2 wishbone master
   output            vm_dclo,
   output            vm_aclo,
   output            vm_halt,
   output            vm_virq,
   input             vm_init,
   input      [16:0] wbm_adr,      // [16] halt mode
   input      [15:0] wbm_dat_o,
   output reg [15:0] wbm_dat_i,
   input             wbm_cyc,
   input             wbm_we,
   input       [1:0] wbm_sel,
   input             wbm_stb,
   output            wbm_ack,

   // ROM
   output     [13:1] rom_addr,
   input      [15:0] rom_dout,

   // RAM (neon_mem), four-phase handshake
   output reg        ram_req,
   output reg        ram_we,
   output reg [21:1] ram_addr,
   output reg [15:0] ram_din,
   output reg  [1:0] ram_be,
   output reg  [1:0] ram_mask,     // write masking: 0 none, 1 2 bpp, 2 4 bpp
   input      [15:0] ram_dout,
   input             ram_ack,

   // the floppy controller / disk buffer side (fdc.sv)
   output            fdc_sel,      // one of its ports is addressed, on the strobe
   output      [2:0] fdc_port,     // address bits 3:1
   output            fdc_wr,
   input       [7:0] fdc_dout,
   output reg        fdc_reset,
   output reg        hd_dir_wr,    // SDH access: buffer into write mode
   output reg        hd_dir_rd,    // CSR access: buffer into read mode
   output reg  [4:0] fdc_params,   // {motor, density, drive, side} from HD.SDH, [4] = SDH[3] (HDD selected)
   input             fdc_int,
   output      [7:0] dbg,          // {ppib_rd[3:0], ioint, fdc_int, hd_int, pic_rr != 0}

   // peripherals
   input       [7:0] key_matrix[8],
   input      [24:0] ps2_mouse,
   input      [64:0] rtc,
   input             tick50,       // one clk pulse per frame
   output      [2:0] sound,        // the three SNL outputs
   output      [7:0] lpt_data,
   output reg        uart_wr,
   output      [7:0] uart_data
);

// ---------------------------------------------------------------------
// Reset
// ---------------------------------------------------------------------
vm_reset rst(.clk(clk), .reset(reset), .dclo(vm_dclo), .aclo(vm_aclo));

// ---------------------------------------------------------------------
// Bus cycle
// ---------------------------------------------------------------------
reg        stb_d = 0;
wire       stb_rise = wbm_stb & ~stb_d;
reg        ack = 0;
assign     wbm_ack = ack & wbm_stb;

wire        halt = wbm_adr[16];
wire [15:0] a    = wbm_adr[15:0];

// a write whose read half was the previous strobe of a still-open cycle
reg  cyc_rd_held = 0;
wire is_rmw_write = wbm_we & cyc_rd_held;

// the dispatcher
reg [15:0] HR[8];
reg [15:0] UR[8];
wire [15:0] memreg = halt ? HR[a[15:13]] : UR[a[15:13]];
wire [21:0] phys = {6'd0, a[12:0]} + {memreg[13:4], 12'd0} - 22'd0;   // (a & 017777) + ((memreg & 037760) << 8)
wire        bank1 = phys[21];
wire  [1:0] bankbits = bank1 ? ram_banks1 : ram_banks0;
wire [21:0] phys_lim = (bankbits == 2'd1) ? (phys & ~22'h180000) : phys;

localparam [1:0] A_ROM = 0, A_IO = 1, A_EMUL = 2, A_RAM = 3;
reg  [1:0] rom_wait = 0;
reg        ram_wait = 0;
reg        late_rd  = 0;

// ---------------------------------------------------------------------
// Devices
// ---------------------------------------------------------------------
// PIC
localparam [1:0] PIC_ICW1 = 2'd1, PIC_ICW2 = 2'd2, PIC_READY = 2'd0;
reg  [1:0] pic_mode = PIC_ICW1;
reg        pic_poll = 0;
reg  [7:0] pic_rr = 0, pic_mr = 0;
wire       ioint = |(pic_rr & ~pic_mr);
reg        int0_set = 0, int5_set = 0;    // one-clock requests

// PPI
reg  [7:0] ppia_wr = 0, ppia_rd = 0, ppib_wr = 0, ppib_rd = 8'd11, ppic = 8'd14;
assign lpt_data = ppib_wr;

// HDD registers
reg [15:0] hd_sdh = 0;
reg  [7:0] hd_snum = 0;
reg [15:0] hd_cnum = 0;
reg        hd_int = 0;

// keyboard
reg  [2:0] keypos = 0;
reg        keyint = 0;
reg  [7:0] key_prev[8];
wire       key_changed = (key_prev[0] != key_matrix[0]) | (key_prev[1] != key_matrix[1]) |
                         (key_prev[2] != key_matrix[2]) | (key_prev[3] != key_matrix[3]) |
                         (key_prev[4] != key_matrix[4]) | (key_prev[5] != key_matrix[5]) |
                         (key_prev[6] != key_matrix[6]) | (key_prev[7] != key_matrix[7]);

// mouse
reg  [7:0] mousedx = 0, mousedy = 0;
reg  [1:0] mousest = 0;
reg        mouse_tgl = 0;

// RTC
reg  [7:0] rtc_mem[50];
reg  [7:0] rtc_alarm_sec = 0, rtc_alarm_min = 0, rtc_alarm_hour = 0;

// timers
reg  [1:0] tick_div = 0;
wire       tick2m = (tick_div == 2'd3);
wire [2:0] snd_out, snl_out;
wire       pit_sel_snd = (a[15:3] == 16'o161010 >> 3);   // 161010..161016
wire       pit_sel_snl = (a[15:3] == 16'o161020 >> 3);   // 161020..161026
wire       pit_rd = stb_rise & ~wbm_we & (pit_sel_snd | pit_sel_snl);
wire       pit_wr = stb_rise &  wbm_we & (pit_sel_snd | pit_sel_snl) & wbm_sel[0];
wire [7:0] pit_snd_dout, pit_snl_dout;

pit8253 snd(.clk(clk), .reset(reset), .tick(tick2m), .gate(3'b111),
            .addr(a[2:1]), .din(wbm_dat_o[7:0]), .wr(pit_wr & pit_sel_snd), .rd(pit_rd & pit_sel_snd),
            .dout(pit_snd_dout), .out(snd_out));
pit8253 snl(.clk(clk), .reset(reset), .tick(tick2m), .gate(snd_out),
            .addr(a[2:1]), .din(wbm_dat_o[7:0]), .wr(pit_wr & pit_sel_snl), .rd(pit_rd & pit_sel_snl),
            .dout(pit_snl_dout), .out(snl_out));
assign sound = snl_out;

// 64 Hz from the 8 MHz clock for the RTC's SQW
reg [16:0] rtc_div = 0;
wire       tick64 = (rtc_div == 17'd124999);

// the HALT line: EF0/EF1 active (low), IHLT low, or an unmasked I/O interrupt
assign vm_halt = ~ppib_rd[0] | ~ppib_rd[1] | ~ppib_rd[3] | ioint;
assign dbg = {ppib_rd[3:0], ioint, fdc_int, hd_int, |pic_rr};
assign vm_virq = ~ppic[3];

// FDC side
assign fdc_port  = a[3:1];
assign fdc_sel   = stb_rise & (a[15:6] == 16'o161000 >> 6) &
                   (a[5:1] == 5'o20 || a[5:1] == 5'o22 || a[5:1] == 5'o34 || a[5:1] == 5'o35 || a[5:1] == 5'o37);
assign fdc_wr    = wbm_we;
assign uart_data = wbm_dat_o[7:0];

assign rom_addr = a[13:1];

// RTC time from the framework, binary
function [7:0] bcd2bin(input [7:0] v);
   bcd2bin = v[7:4] * 8'd10 + v[3:0];
endfunction
wire [7:0] rtc_sec   = bcd2bin(rtc[7:0]);
wire [7:0] rtc_min   = bcd2bin(rtc[15:8]);
wire [7:0] rtc_hour  = bcd2bin(rtc[23:16]);
wire [7:0] rtc_date  = bcd2bin(rtc[31:24]);
wire [7:0] rtc_month = bcd2bin(rtc[39:32]);
wire [7:0] rtc_year  = bcd2bin(rtc[47:40]);
wire [7:0] rtc_wday  = rtc[55:48] + 8'd1;

// the PIC's poll result: the lowest pending request
function [7:0] pic_poll_val(input [7:0] rr);
   casez(rr)
   8'b???????1: pic_poll_val = 8'h80;
   8'b??????10: pic_poll_val = 8'h81;
   8'b?????100: pic_poll_val = 8'h82;
   8'b????1000: pic_poll_val = 8'h83;
   8'b???10000: pic_poll_val = 8'h84;
   8'b??100000: pic_poll_val = 8'h85;
   8'b?1000000: pic_poll_val = 8'h86;
   8'b10000000: pic_poll_val = 8'h87;
   default:     pic_poll_val = 8'h00;
   endcase
endfunction

// the RTC/NVRAM byte at an index
function [7:0] rtc_byte(input [6:0] idx);
   case(idx)
   7'd0: rtc_byte = rtc_sec;
   7'd1: rtc_byte = rtc_alarm_sec;
   7'd2: rtc_byte = rtc_min;
   7'd3: rtc_byte = rtc_alarm_min;
   7'd4: rtc_byte = rtc_hour;
   7'd5: rtc_byte = rtc_alarm_hour;
   7'd6: rtc_byte = rtc_wday;
   7'd7: rtc_byte = rtc_date;
   7'd8: rtc_byte = rtc_month;
   7'd9: rtc_byte = rtc_year;
   default: rtc_byte = (idx >= 7'd14) ? rtc_mem[idx - 7'd14] : 8'd0;
   endcase
endfunction

integer i;
always @(posedge clk) begin
   stb_d <= wbm_stb;
   fdc_reset  <= 1'b0;
   hd_dir_wr  <= 1'b0;
   hd_dir_rd  <= 1'b0;
   uart_wr    <= 1'b0;
   int0_set   <= 1'b0;
   int5_set   <= 1'b0;

   tick_div <= tick_div + 1'd1;
   rtc_div  <= tick64 ? 17'd0 : rtc_div + 1'd1;

   if(reset) begin
      ack <= 1'b0; ram_req <= 1'b0; ram_wait <= 1'b0; rom_wait <= 0; cyc_rd_held <= 1'b0;
      pic_mode <= PIC_ICW1; pic_poll <= 1'b0; pic_rr <= 0; pic_mr <= 0;
      ppia_wr <= 0; ppia_rd <= 0; ppib_wr <= 0; ppib_rd <= 8'd11; ppic <= 8'd14;
      hd_sdh <= 0; hd_snum <= 0; hd_cnum <= 0; hd_int <= 1'b0;
      keypos <= 0; keyint <= 1'b0;
      mousedx <= 0; mousedy <= 0; mousest <= 0;
      rtc_alarm_sec <= 0; rtc_alarm_min <= 0; rtc_alarm_hour <= 0;
      for(i = 0; i < 8; i = i + 1) begin HR[i] <= 0; UR[i] <= 0; key_prev[i] <= 0; end
      fdc_params <= 0;
   end
   else begin
      // ---- the INIT line: the RESET instruction or DCLO ----
      if(vm_init) begin
         fdc_reset <= 1'b1;
         hd_int    <= 1'b0;
         if(pic_mode == PIC_READY) pic_rr[0] <= 1'b1;
      end

      // ---- interrupt sources ----
      if(pic_mode == PIC_READY) begin
         pic_rr[1] <= fdc_int | hd_int;
         pic_rr[4] <= keyint;
         if(timer64 ? tick64 : tick50) pic_rr[5] <= 1'b1;
      end
      ppib_rd[2] <= ioint;

      // ---- keyboard: a change of the matrix requests an interrupt ----
      for(i = 0; i < 8; i = i + 1) key_prev[i] <= key_matrix[i];
      if(key_changed) keyint <= 1'b1;

      // ---- mouse: accumulate the framework's reports ----
      mouse_tgl <= ps2_mouse[24];
      if(mouse_tgl != ps2_mouse[24]) begin
         mousedx <= mousedx - {ps2_mouse[4], ps2_mouse[11:8]};      // -dx, as NeonBTL
         mousedy <= mousedy + {ps2_mouse[5], ps2_mouse[19:16]};     // PS/2 y is up, Windows y is down
         ppia_rd[6:5] <= {~ps2_mouse[1], ~ps2_mouse[0]};
      end

      // ---- the bus ----
      if(!wbm_stb) begin
         ack      <= 1'b0;
         ram_wait <= 1'b0;
         rom_wait <= 0;
         late_rd  <= 1'b0;
         if(!wbm_cyc) cyc_rd_held <= 1'b0;
      end
      else if(stb_rise) begin
         cyc_rd_held <= ~wbm_we;
         // ---------------- ROM, halt mode 0..37777 ----------------
         if(halt && a < 16'o040000) begin
            if(wbm_we) ack <= 1'b1;             // writes to ROM are ignored
            else rom_wait <= 2'd1;
         end
         // ---------------- the I/O page ----------------
         else if(a >= 16'o160000) begin
            if(a < 16'o174000) begin
               // -------- I/O registers --------
               ack <= 1'b1;                     // unless a case below takes it back
               wbm_dat_i <= 16'd0;
               if(a[15:1] == 16'o161000 >> 1) begin           // PICCSR
                  if(wbm_we) begin
                     if(pic_mode == PIC_ICW1) pic_mode <= PIC_ICW2;
                     else if(pic_mode == PIC_READY) begin
                        if(wbm_dat_o[7:0] == 8'o014) pic_poll <= 1'b1;
                        else if(wbm_dat_o[7:0] == 8'o040) pic_rr <= 0;
                     end
                  end
                  else wbm_dat_i <= {8'd0, (pic_mode == PIC_READY && pic_poll) ? pic_poll_val(pic_rr) : 8'd0};
               end
               else if(a[15:1] == 16'o161002 >> 1) begin      // PICMR
                  if(wbm_we) begin
                     if(pic_mode == PIC_ICW2) pic_mode <= PIC_READY;
                     else if(pic_mode == PIC_READY) pic_mr <= wbm_dat_o[7:0];
                  end
                  else wbm_dat_i <= {8'd0, pic_mr};
               end
               else if(pit_sel_snd | pit_sel_snl) begin       // 161010..161026 the timers
                  if(!wbm_we) begin ack <= 1'b0; late_rd <= 1'b1; end
               end
               else if(a[15:1] == 16'o161030 >> 1) begin      // PPIA
                  if(wbm_we) begin
                     ppia_wr <= wbm_dat_o[7:0];
                     // the mouse nibble sequencer on bits 7..4
                     ppic[7:4] <= 4'd0;
                     if(!wbm_dat_o[7]) mousest <= 0;
                     else case(mousest)
                     2'd0: begin ppic[7:4] <= mousedx[7:4]; mousest <= 2'd1; end
                     2'd1: begin ppic[7:4] <= mousedx[3:0]; mousedx <= 0; mousest <= 2'd2; end
                     2'd2: begin ppic[7:4] <= mousedy[7:4]; mousest <= 2'd3; end
                     2'd3: begin ppic[7:4] <= mousedy[3:0]; mousedy <= 0; mousest <= 2'd0; end
                     endcase
                  end
                  else wbm_dat_i <= {8'd0, ppia_rd};
               end
               else if(a[15:1] == 16'o161032 >> 1) begin      // PPIB
                  if(wbm_we) ppib_wr <= wbm_dat_o[7:0];
                  else wbm_dat_i <= {8'd0, ppib_rd};
               end
               else if(a[15:1] == 16'o161034 >> 1) begin      // PPIC
                  if(wbm_we) begin
                     ppic       <= wbm_dat_o[7:0];
                     ppib_rd[3] <= wbm_dat_o[2];            // PC2 (IHLT) -> PB3
                  end
                  else wbm_dat_i <= {8'd0, ppic};
               end
               else if(a[15:1] == 16'o161036 >> 1) begin      // PPIP mode word
               end
               else if(a[15:1] == 16'o161040 >> 1 || a[15:1] == 16'o161044 >> 1 ||
                       a[15:1] == 16'o161070 >> 1 || a[15:1] == 16'o161072 >> 1 ||
                       a[15:1] == 16'o161076 >> 1) begin      // HD.BUFF, HD.SCNT, FD.CSR, FD.BUF, FD.CNT
                  if(!wbm_we) begin ack <= 1'b0; late_rd <= 1'b1; end
               end
               else if(a[15:1] == 16'o161042 >> 1) wbm_dat_i <= 16'h00ff;   // HD.ERR
               else if(a[15:1] == 16'o161046 >> 1) begin      // HD.SNUM
                  if(wbm_we) hd_snum <= wbm_dat_o[7:0]; else wbm_dat_i <= {8'd0, hd_snum};
               end
               else if(a[15:1] == 16'o161050 >> 1) begin      // HD.CNLO
                  if(wbm_we) hd_cnum[7:0] <= wbm_dat_o[7:0]; else wbm_dat_i <= {8'd0, hd_cnum[7:0]};
               end
               else if(a[15:1] == 16'o161052 >> 1) begin      // HD.CNHI
                  if(wbm_we) hd_cnum[15:8] <= wbm_dat_o[7:0]; else wbm_dat_i <= {8'd0, hd_cnum[15:8]};
               end
               else if(a[15:1] == 16'o161054 >> 1) begin      // HD.SDH
                  hd_dir_wr <= 1'b1;
                  if(wbm_we) begin
                     hd_sdh <= wbm_dat_o;
                     fdc_params <= {wbm_dat_o[3], wbm_dat_o[4], wbm_dat_o[2], wbm_dat_o[1], wbm_dat_o[0]};
                  end
                  else wbm_dat_i <= hd_sdh;
               end
               else if(a[15:1] == 16'o161056 >> 1) begin      // HD.CSR
                  hd_dir_rd <= 1'b1;
                  if(wbm_we) begin
                     if(wbm_dat_o == 16'o020) hd_int <= 1'b1;   // RESTORE
                  end
                  else begin hd_int <= 1'b0; wbm_dat_i <= 16'h0041; end
               end
               else if(a[15:1] == 16'o161060 >> 1) begin      // DLBUF
                  if(wbm_we) uart_wr <= 1'b1;
               end
               else if(a[15:1] == 16'o161062 >> 1) wbm_dat_i <= 16'd1;   // DLCSR: transmitter ready
               else if(a[15:1] == 16'o161064 >> 1) begin      // KBDCSR
                  if(!wbm_we) begin
                     wbm_dat_i <= {8'd0, key_matrix[keypos]};
                     keypos    <= keypos + 1'd1;
                  end
               end
               else if(a[15:1] == 16'o161066 >> 1) begin      // KBDBUF: 8279 commands
                  if(wbm_we) case(wbm_dat_o[7:5])
                  3'b010: keypos <= 0;                           // read FIFO
                  3'b110: begin keypos <= 0; keyint <= 1'b0; end // clear
                  3'b111: keyint <= 1'b0;                        // end interrupt
                  default: ;
                  endcase
               end
               else if(a[15:4] == 16'o161120 >> 4) begin      // 161120..161136 IDE: not fitted
               end
               else if(a[15:4] == 16'o161200 >> 4) begin      // HR0..HR7
                  if(wbm_we) begin
                     HR[a[3:1]] <= wbm_dat_o;
                     if(halt && a[3:2] == 2'b00) ppib_rd[1:0] <= 2'b11;   // HR0/HR1 written in halt mode: EF0/EF1 off
                     if(!halt) ack <= 1'b0;                               // in user mode: a bus error
                  end
                  else wbm_dat_i <= HR[a[3:1]];
               end
               else if(a[15:4] == 16'o161220 >> 4) begin      // UR0..UR7
                  if(wbm_we) UR[a[3:1]] <= wbm_dat_o;
                  else wbm_dat_i <= UR[a[3:1]];
               end
               else if(a[15:6] == 16'o161400 >> 6) begin      // 161400..161477 RTC, byte registers
                  if(wbm_we) begin
                     if(wbm_sel[0] && a[6:1] >= 6'd7)  rtc_mem[{a[6:1], 1'b0} - 7'd14] <= wbm_dat_o[7:0];
                     if(wbm_sel[1] && a[6:1] >= 6'd7)  rtc_mem[{a[6:1], 1'b1} - 7'd14] <= wbm_dat_o[15:8];
                  end
                  else wbm_dat_i <= {rtc_byte({a[6:1], 1'b1}), rtc_byte({a[6:1], 1'b0})};
               end
               else if(a[15:9] == 16'o161000 >> 9) begin
                  // unused registers in 161000-161777 answer with the low address byte
                  wbm_dat_i <= {8'd0, a[7:0]};
               end
               else ack <= 1'b0;                // nothing there: the bus times out
            end
            else if(!halt && a < 16'o177700) begin
               // -------- the emulated registers: RAM 0..7777 and a trap --------
               if(!is_rmw_write) begin
                  if(ppib_rd[0]) HR[0] <= a; else HR[1] <= a;
               end
               ppib_rd[0] <= 1'b0;
               if(wbm_we) ppib_rd[1] <= 1'b0;
               ram_req <= 1'b1; ram_we <= wbm_we; ram_addr <= {10'd0, a[11:1]};
               ram_din <= wbm_dat_o; ram_be <= wbm_sel; ram_mask <= 2'd0; ram_wait <= 1'b1;
            end
            else if(!halt) begin
               // 177700-177777 in user mode: denied, the bus times out
            end
            else begin
               // halt mode 174000-177777: RAM 0..7777
               ram_req <= 1'b1; ram_we <= wbm_we; ram_addr <= {10'd0, a[11:1]};
               ram_din <= wbm_dat_o; ram_be <= wbm_sel; ram_mask <= 2'd0; ram_wait <= 1'b1;
            end
         end
         // ---------------- RAM through the dispatcher ----------------
         else begin
            if(memreg[3]) begin
               // access denied: no reply
            end
            else if(bankbits == 2'd0) begin
               // no module in this bank: reads nothing, writes vanish
               wbm_dat_i <= 16'd0;
               ack <= 1'b1;
            end
            else begin
               ram_req <= 1'b1; ram_we <= wbm_we; ram_addr <= phys_lim[21:1];
               ram_din <= wbm_dat_o; ram_be <= wbm_sel;
               ram_mask <= (memreg[1:0] == 2'd0) ? 2'd0 : (memreg[1] ? 2'd2 : 2'd1);
               ram_wait <= 1'b1;
            end
         end
      end
      else begin
         // ---- waiting on the ROM or the RAM ----
         if(rom_wait != 0) begin
            rom_wait <= rom_wait + 1'd1;
            if(rom_wait == 2'd1) begin wbm_dat_i <= rom_dout; ack <= 1'b1; rom_wait <= 0; end
         end
         if(ram_wait && ram_ack) begin
            wbm_dat_i <= ram_dout;
            ack       <= 1'b1;
            ram_req   <= 1'b0;
            ram_wait  <= 1'b0;
         end
         // a timer or disk buffer read: those register their data on the strobe
         if(late_rd) begin
            wbm_dat_i <= pit_sel_snd ? {8'd0, pit_snd_dout} : pit_sel_snl ? {8'd0, pit_snl_dout} : {8'd0, fdc_dout};
            ack       <= 1'b1;
            late_rd   <= 1'b0;
         end
      end
   end
end

endmodule
