//============================================================================
//
//  Soyuz-Neon PK-11/16 for MiSTer
//
//  A 1991 Soviet computer on the N1806VM2 (a PDP-11 compatible CPU, the
//  K1801VM2 core by 1801BM1, github.com/1801BM1/cpu11, CC BY 3.0), with
//  up to 4 MB of RAM behind a page dispatcher, a display-list video
//  controller and an 8-bit I/O block.  The machine's behaviour follows
//  the NeonBTL emulator (github.com/nzeemin/neonbtl).
//
//  This program is free software; you can redistribute it and/or modify it
//  under the terms of the GNU General Public License as published by the Free
//  Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope that it will be useful, but WITHOUT
//  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
//  FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
//  more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this program; if not, write to the Free Software Foundation, Inc.,
//  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
//
//============================================================================

module emu
(
	`include "sys/emu_ports.vh"
);

///////// Default values for ports not used in this core /////////

assign ADC_BUS  = 'Z;
assign USER_OUT = '1;
assign {UART_RTS, UART_TXD, UART_DTR} = 0;
assign {SD_SCK, SD_MOSI, SD_CS} = 'Z;
assign {DDRAM_CLK, DDRAM_BURSTCNT, DDRAM_ADDR, DDRAM_DIN, DDRAM_BE, DDRAM_RD, DDRAM_WE} = '0;

assign VGA_SL = 0;
assign VGA_F1 = 0;
assign VGA_SCALER  = 0;
assign VGA_DISABLE = 0;
assign HDMI_FREEZE = 0;
assign HDMI_BLACKOUT = 0;
assign HDMI_BOB_DEINT = 0;

assign AUDIO_MIX = 0;
assign LED_POWER = 0;
assign BUTTONS = 0;

//////////////////////////////////////////////////////////////////

wire [1:0] ar = status[122:121];

assign VIDEO_ARX = (!ar) ? 12'd4 : (ar - 1'd1);
assign VIDEO_ARY = (!ar) ? 12'd3 : 12'd0;

`include "build_id.v"
localparam CONF_STR = {
	"Neon;;",
	"-;",
	"S0,DSK,Floppy FD0;",
	"S1,DSK,Floppy FD1;",
	"S2,IMG,Hard disk;",
	"-;",
	"O[3:2],RAM,4 MB,512 KB,1 MB,2 MB;",
	"O[4],Timer IRQ5,50 Hz frame,64 Hz clock;",
	"-;",
	"O[122:121],Aspect ratio,Original,Full Screen,[ARC1],[ARC2];",
	"-;",
	"T[0],Reset;",
	"R[0],Reset and close OSD;",
	"V,v",`BUILD_DATE
};

wire   [1:0] buttons;
wire         forced_scandoubler;
wire  [21:0] gamma_bus;
wire [127:0] status;
wire  [10:0] ps2_key;
wire  [24:0] ps2_mouse;
wire  [64:0] rtc;

wire        ioctl_download;
wire [15:0] ioctl_index;
wire        ioctl_wr;
wire [26:0] ioctl_addr;
wire [15:0] ioctl_dout;

localparam SLOTS = 3;             // two floppies and the hard disk

wire [SLOTS-1:0]  img_mounted;
wire              img_readonly;
wire [63:0]       img_size;
wire [31:0]       sd_lba[SLOTS];
wire [SLOTS-1:0]  sd_rd;
wire [SLOTS-1:0]  sd_wr;
wire [SLOTS-1:0]  sd_ack;
wire [12:0]       sd_buff_addr;
wire [15:0]       sd_buff_dout;
wire [15:0]       sd_buff_din[SLOTS];
wire              sd_buff_wr;

hps_io #(.CONF_STR(CONF_STR), .WIDE(1), .VDNUM(SLOTS)) hps_io
(
	.clk_sys(clk_sys),
	.HPS_BUS(HPS_BUS),
	.EXT_BUS(),
	.gamma_bus(gamma_bus),

	.buttons(buttons),
	.forced_scandoubler(forced_scandoubler),
	.status(status),
	.status_menumask(16'd0),

	.ioctl_download(ioctl_download),
	.ioctl_index(ioctl_index),
	.ioctl_wr(ioctl_wr),
	.ioctl_addr(ioctl_addr),
	.ioctl_dout(ioctl_dout),

	.img_mounted(img_mounted),
	.img_readonly(img_readonly),
	.img_size(img_size),

	.sd_lba(sd_lba),
	.sd_blk_cnt('{SLOTS{6'd0}}),
	.sd_rd(sd_rd),
	.sd_wr(sd_wr),
	.sd_ack(sd_ack),
	.sd_buff_addr(sd_buff_addr),
	.sd_buff_dout(sd_buff_dout),
	.sd_buff_din(sd_buff_din),
	.sd_buff_wr(sd_buff_wr),

	.ps2_key(ps2_key),
	.ps2_mouse(ps2_mouse),
	.RTC(rtc)
);

///////////////////////   CLOCKS   ///////////////////////////////
//
// clk_sys  64 MHz   memory, video (16 MHz pixels), the framework
// clk_cpu   8 MHz   the CPU and the I/O block, in phase with clk_sys
//

wire clk_sys;
wire clk_cpu;
wire pll_locked;

pll pll
(
	.refclk(CLK_50M),
	.rst(0),
	.outclk_0(clk_sys),
	.outclk_1(clk_cpu),
	.locked(pll_locked)
);

///////////////////////   ROM LOADING   //////////////////////////

localparam ROM_INDEX = 8'd0;          // boot.rom
localparam ROM_BYTES = 16384;

wire rom_loading = ioctl_download && ioctl_index == ROM_INDEX;
wire rom_wr_en   = rom_loading && ioctl_wr && ioctl_addr < ROM_BYTES;

wire reset = RESET | status[0] | buttons[1] | rom_loading | ~pll_locked;

// the CPU waits for the memory
wire       mem_ready;
reg  [1:0] cpu_reset_s = 2'b11;
always @(posedge clk_cpu) cpu_reset_s <= {cpu_reset_s[0], reset | ~mem_ready};
wire cpu_reset = cpu_reset_s[1];

// the RAM fitted: bank 0 and bank 1, 0 none, 1 2 x 256K, 2 2 x 1M
wire [1:0] ram_banks0 = (status[3:2] == 2'd1) ? 2'd1 : (status[3:2] == 2'd2) ? 2'd1 : 2'd2;
wire [1:0] ram_banks1 = (status[3:2] == 2'd1) ? 2'd0 : (status[3:2] == 2'd2) ? 2'd1 :
                        (status[3:2] == 2'd3) ? 2'd0 : 2'd2;

///////////////////////   MEMORY   ///////////////////////////////

wire        cpu_ram_req, cpu_ram_we, cpu_ram_ack;
wire [21:1] cpu_ram_addr;
wire [15:0] cpu_ram_din, cpu_ram_dout;
wire  [1:0] cpu_ram_be, cpu_ram_mask;
wire        vid_ram_req, vid_ram_ack;
wire [21:1] vid_ram_addr;
wire [15:0] vid_ram_dout;

neon_mem mem
(
	.clk(clk_sys),
	.reset(reset),
	.ready(mem_ready),

	.cpu_req(cpu_ram_req),
	.cpu_we(cpu_ram_we),
	.cpu_addr(cpu_ram_addr),
	.cpu_din(cpu_ram_din),
	.cpu_be(cpu_ram_be),
	.cpu_mask(cpu_ram_mask),
	.cpu_dout(cpu_ram_dout),
	.cpu_ack(cpu_ram_ack),

	.vid_req(vid_ram_req),
	.vid_addr(vid_ram_addr),
	.vid_dout(vid_ram_dout),
	.vid_ack(vid_ram_ack),

	.SDRAM_DQ(SDRAM_DQ), .SDRAM_A(SDRAM_A), .SDRAM_DQML(SDRAM_DQML), .SDRAM_DQMH(SDRAM_DQMH),
	.SDRAM_BA(SDRAM_BA), .SDRAM_nCS(SDRAM_nCS), .SDRAM_nWE(SDRAM_nWE), .SDRAM_nRAS(SDRAM_nRAS),
	.SDRAM_nCAS(SDRAM_nCAS), .SDRAM_CKE(SDRAM_CKE), .SDRAM_CLK(SDRAM_CLK)
);

wire [13:1] rom_addr;
wire [15:0] rom_dout;

neon_rom rom
(
	.clk(clk_cpu),
	.addr(rom_addr),
	.dout(rom_dout),
	.wr_clk(clk_sys),
	.wr_addr(ioctl_addr[13:1]),
	.wr_data(ioctl_dout),
	.wr_en(rom_wr_en)
);

///////////////////////   VIDEO   ////////////////////////////////

wire        hsync, vsync, hblank, vblank, ce_pix, frame_tick;
wire  [7:0] red, green, blue;

neon_video video
(
	.clk(clk_sys),
	.reset(reset),
	.ram_banks0(ram_banks0),
	.ram_banks1(ram_banks1),

	.ram_req(vid_ram_req),
	.ram_addr(vid_ram_addr),
	.ram_dout(vid_ram_dout),
	.ram_ack(vid_ram_ack),

	.ce_pix(ce_pix),
	.hsync(hsync),
	.vsync(vsync),
	.hblank(hblank),
	.vblank(vblank),
	.red(red),
	.green(green),
	.blue(blue),
	.frame_tick(frame_tick),
	.dbg_in(dbg_cpu),
	.dbg_hd(dbg_hd),
	.dbg_out(dbg_bits)
);

// The debug overlay, shown when the project is built with the macro
// NEON_DEBUG_OVERLAY (neon_video.sv draws it over the top left of the
// picture, 16 boxes a row, yellow = 1): 30 rows of 16 bits.  Rows 0..27 are
// the 28 acknowledged bus cycles (halt flag, A15..1, the oldest first) before
// the firmware's monitor is entered (a halt-mode fetch at 010200 or 010216)
// or before a halt-mode word read of vector 4 or 10; until then, the 28
// cycles before the start of the current frame.  Row 28: {beat15, frozen,
// halt, dclo, ppib3..0, ioint, fdc_int, hd_int, pic_rr!=0, bus stall, we,
// ram req, ram ack}; row 29 the disk controller's counters (fdc.sv dbg).
// A MiSTer screenshot ("screenshot" to /dev/MiSTer_cmd) reads cleanly.
localparam DBG_N = 28;
reg  [DBG_N*16+15:0] dbg_cpu = 0;
wire         [511:0] dbg_bits;
wire           [7:0] dbg_sys;
wire          [15:0] dbg_hd;
reg  [DBG_N*16-1:0]  dbg_ring = 0;     // the newest cycle in [15:0]
reg  [DBG_N*16-1:0]  dbg_adr  = 0;     // the displayed ones
reg   [15:0] dbg_beat = 0;
reg    [7:0] dbg_stb_cnt = 0;
reg          dbg_stall = 0, dbg_we = 0, dbg_frozen = 0;
reg          dbg_tick = 0, dbg_tick_d = 0;
wire         dbg_trap = wbm_adr[16] & ~wbm_we &
                        ((wbm_sel == 2'b11 && (wbm_adr[15:1] == 15'd2 || wbm_adr[15:1] == 15'd4)) ||
                         wbm_adr[15:1] == (16'o010200 >> 1) || wbm_adr[15:1] == (16'o010216 >> 1));
// the firmware's request-wait loop is left out of the ring, so a hang in
// it shows what came before
wire dbg_skip = ~wbm_adr[16] & (wbm_adr[15:3] == (16'o001240 >> 3) || wbm_adr[15:1] == (16'o157130 >> 1));
always @(posedge clk_sys) if(frame_tick) dbg_tick <= ~dbg_tick;
always @(posedge clk_cpu) begin
	dbg_tick_d <= dbg_tick;
	if(wbm_stb & wbm_ack) begin
		if(dbg_trap) dbg_frozen <= 1'b1;
		else if(!dbg_skip) dbg_ring <= {dbg_ring[DBG_N*16-17:0], wbm_adr[16:1]};
		dbg_we   <= wbm_we;
		dbg_beat <= dbg_beat + 1'd1;
	end
	if((dbg_tick != dbg_tick_d && !dbg_frozen) || (dbg_trap & wbm_stb & wbm_ack & ~dbg_frozen)) dbg_adr <= dbg_ring;
	if(!wbm_stb || wbm_ack) dbg_stb_cnt <= 0;
	else if(dbg_stb_cnt != 8'hff) dbg_stb_cnt <= dbg_stb_cnt + 1'd1;
	if(dbg_stb_cnt == 8'hff) dbg_stall <= 1'b1;
end
always @(posedge clk_sys) dbg_cpu <= {dbg_adr,
                                      dbg_beat[15], dbg_frozen, vm_halt, vm_dclo, dbg_sys, dbg_stall, dbg_we, cpu_ram_req, cpu_ram_ack};

assign CLK_VIDEO = clk_sys;

video_mixer #(.LINE_LENGTH(832), .HALF_DEPTH(0), .GAMMA(1)) video_mixer
(
	.CLK_VIDEO  (CLK_VIDEO),
	.CE_PIXEL   (CE_PIXEL),
	.ce_pix     (ce_pix),

	.scandoubler(forced_scandoubler),
	.hq2x       (1'b0),
	.gamma_bus  (gamma_bus),

	.R          (red),
	.G          (green),
	.B          (blue),
	.HSync      (hsync),
	.VSync      (vsync),
	.HBlank     (hblank),
	.VBlank     (vblank),

	.HDMI_FREEZE(1'b0),
	.freeze_sync(),

	.VGA_R      (VGA_R),
	.VGA_G      (VGA_G),
	.VGA_B      (VGA_B),
	.VGA_VS     (VGA_VS),
	.VGA_HS     (VGA_HS),
	.VGA_DE     (VGA_DE)
);

// the frame tick for the I/O block, on the CPU clock
reg [2:0] frame_s = 0;
// the frame tick as a toggle, so the one-clk_sys pulse cannot be missed
reg  frame_tgl = 0;
always @(posedge clk_sys) if(frame_tick) frame_tgl <= ~frame_tgl;
always @(posedge clk_cpu) frame_s <= {frame_s[1:0], frame_tgl};
wire tick50 = frame_s[1] ^ frame_s[2];

///////////////////////   KEYBOARD   /////////////////////////////

wire [7:0] key_matrix[8];

keyboard kbd
(
	.clk(clk_sys),
	.reset(reset),
	.ps2_key(ps2_key),
	.matrix(key_matrix)
);

///////////////////////   THE CPU AND THE BOARD   ////////////////

wire        vm_dclo, vm_aclo, vm_halt, vm_virq, vm_init;
wire [16:0] wbm_adr;
wire [15:0] wbm_dat_o, wbm_dat_i;
wire        wbm_cyc, wbm_we, wbm_stb, wbm_ack;
wire  [1:0] wbm_sel;
wire        wbi_stb, wbi_una;

vm2_wb #(.VM2_CORE_FIX_PREFETCH(0)) cpu
(
	.vm_clk_p   (clk_cpu),
	.vm_clk_n   (~clk_cpu),
	.vm_clk_ena (1'b0),
	.vm_clk_slow(1'b0),

	.vm_init    (vm_init),
	.vm_dclo    (vm_dclo),
	.vm_aclo    (vm_aclo),
	.vm_halt    (vm_halt),
	.vm_evnt    (1'b0),
	.vm_virq    (vm_virq),

	.wbm_gnt_i  (1'b1),
	.wbm_ios_o  (),
	.wbm_adr_o  (wbm_adr),
	.wbm_dat_o  (wbm_dat_o),
	.wbm_dat_i  (wbm_dat_i),
	.wbm_cyc_o  (wbm_cyc),
	.wbm_we_o   (wbm_we),
	.wbm_sel_o  (wbm_sel),
	.wbm_stb_o  (wbm_stb),
	.wbm_ack_i  (wbm_ack),

	// the SEL register reads as 0: the start vector is 0 in halt space;
	// no device answers an interrupt acknowledge, so a VIRQ ends in the
	// bus timeout and the halt-mode trap on 274, as on the machine
	.wbi_dat_i  (16'd0),
	.wbi_ack_i  (wbi_una),
	.wbi_stb_o  (wbi_stb),
	.wbi_una_o  (wbi_una)
);

wire        fdc_sel, fdc_wr, fdc_reset, fdc_int, hd_int, fdc_motor;
wire  [3:0] fdc_port;
wire  [7:0] fdc_dout;
wire  [2:0] sound;
wire  [7:0] lpt_data, uart_data;
wire        uart_wr;

neon_sys sys
(
	.clk(clk_cpu),
	.reset(cpu_reset),
	.ram_banks0(ram_banks0),
	.ram_banks1(ram_banks1),
	.timer64(status[4]),

	.vm_dclo(vm_dclo),
	.vm_aclo(vm_aclo),
	.vm_halt(vm_halt),
	.vm_virq(vm_virq),
	.vm_init(vm_init),
	.wbm_adr(wbm_adr),
	.wbm_dat_o(wbm_dat_o),
	.wbm_dat_i(wbm_dat_i),
	.wbm_cyc(wbm_cyc),
	.wbm_we(wbm_we),
	.wbm_sel(wbm_sel),
	.wbm_stb(wbm_stb),
	.wbm_ack(wbm_ack),

	.rom_addr(rom_addr),
	.rom_dout(rom_dout),

	.ram_req(cpu_ram_req),
	.ram_we(cpu_ram_we),
	.ram_addr(cpu_ram_addr),
	.ram_din(cpu_ram_din),
	.ram_be(cpu_ram_be),
	.ram_mask(cpu_ram_mask),
	.ram_dout(cpu_ram_dout),
	.ram_ack(cpu_ram_ack),

	.fdc_sel(fdc_sel),
	.fdc_port(fdc_port),
	.fdc_wr(fdc_wr),
	.fdc_dout(fdc_dout),
	.fdc_reset(fdc_reset),
	.fdc_int(fdc_int),
	.hd_int(hd_int),
	.dbg(dbg_sys),

	.key_matrix(key_matrix),
	.ps2_mouse(ps2_mouse),
	.rtc(rtc),
	.tick50(tick50),
	.sound(sound),
	.lpt_data(lpt_data),
	.uart_wr(uart_wr),
	.uart_data(uart_data)
);

///////////////////////   DISKS   ////////////////////////////////

wire [31:0] fdc_lba;
wire [15:0] fdc_buff_din;

fdc fdc
(
	.clk(clk_cpu),
	.reset(cpu_reset),
	.init(fdc_reset),

	.sel(fdc_sel),
	.port(fdc_port),
	.wr(fdc_wr),
	.din(wbm_dat_o[7:0]),
	.dout(fdc_dout),
	.int_o(fdc_int),
	.hd_int(hd_int),
	.motor_o(fdc_motor),
	.dbg(dbg_hd),

	.sd_clk(clk_sys),
	.img_mounted(img_mounted),
	.img_readonly(img_readonly),
	.img_size(img_size),
	.sd_lba(fdc_lba),
	.sd_rd(sd_rd),
	.sd_wr(sd_wr),
	.sd_ack(sd_ack),
	.sd_buff_addr(sd_buff_addr[7:0]),
	.sd_buff_dout(sd_buff_dout),
	.sd_buff_din(fdc_buff_din),
	.sd_buff_wr(sd_buff_wr)
);

assign sd_lba[0] = fdc_lba;
assign sd_lba[1] = fdc_lba;
assign sd_lba[2] = fdc_lba;
assign sd_buff_din[0] = fdc_buff_din;
assign sd_buff_din[1] = fdc_buff_din;
assign sd_buff_din[2] = fdc_buff_din;

assign LED_DISK = {1'b0, fdc_motor | sd_rd[2] | sd_wr[2]};
assign LED_USER = fdc_int;

///////////////////////   SOUND   ////////////////////////////////

// the three timer outputs, each a third of the range, mixed to one signed sample
wire [15:0] snd_level = {13'd0, sound[0]} * 16'h2AAA + {13'd0, sound[1]} * 16'h2AAA + {13'd0, sound[2]} * 16'h2AAA;
reg  [15:0] audio;
always @(posedge clk_sys) audio <= snd_level - 16'h4000;

assign AUDIO_S = 1;
assign AUDIO_L = audio;
assign AUDIO_R = audio;

endmodule
