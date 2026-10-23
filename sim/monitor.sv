//
// monitor.sv
//
// Debug prints from inside the core: +busmon prints the CPU's bus cycles
// (the first MAX_LINES), +trap prints halt-mode entries.
//
module monitor;

localparam MAX_LINES = 300000;

integer lines = 0;
integer cycles = 0;
reg     on = 0;
integer bus_from = 0;
initial begin on = $test$plusargs("busmon"); if(!$value$plusargs("busfrom=%d", bus_from)) bus_from = 0; end

always @(posedge sim_top.emu.clk_cpu) begin
   cycles = cycles + 1;
   if(on && frames >= bus_from && lines < MAX_LINES && sim_top.emu.wbm_stb && sim_top.emu.wbm_ack) begin
      $display("%0d f%0d %s%s %o = %o  halt=%0d rr=%x mr=%x ppib=%x", cycles, frames,
               sim_top.emu.wbm_adr[16] ? "H" : "U", sim_top.emu.wbm_we ? "W" : "R", sim_top.emu.wbm_adr[15:0],
               sim_top.emu.wbm_we ? sim_top.emu.wbm_dat_o : sim_top.emu.wbm_dat_i,
               sim_top.emu.vm_halt, sim_top.emu.sys.pic_rr, sim_top.emu.sys.pic_mr, sim_top.emu.sys.ppib_rd);
      lines = lines + 1;
   end
end


// +demon: the active pixels of the first lines with other than 832
integer de_cnt = 0, de_lines = 0;
reg de_on = 0, old_de = 0;
initial de_on = $test$plusargs("demon");
always @(posedge sim_top.emu.clk_sys) if(de_on && sim_top.emu.CE_PIXEL) begin
   old_de <= sim_top.emu.VGA_DE;
   if(sim_top.emu.VGA_DE && !old_de && de_lines < 6) $display("DE up at vcnt=%0d hcnt=%0d", sim_top.emu.video.vcnt, sim_top.emu.video.hcnt);
   if(sim_top.emu.VGA_DE) de_cnt = de_cnt + 1;
   else if(old_de) begin
      if(de_cnt != 832 && de_lines < 20) begin
         $display("line with %0d active pixels at vcnt=%0d hcnt=%0d", de_cnt, sim_top.emu.video.vcnt, sim_top.emu.video.hcnt);
         de_lines = de_lines + 1;
      end
      de_cnt = 0;
   end
end


// +fdmon: every access to the disk controllers' registers 161040..161076
reg fd_on = 0;
initial fd_on = $test$plusargs("fdmon");
always @(posedge sim_top.emu.clk_cpu) begin
   if(fd_on && sim_top.emu.wbm_stb && sim_top.emu.wbm_ack &&
      sim_top.emu.wbm_adr[15:5] == (16'o161040 >> 5)) begin
      $display("%0d FD %s%s %o = %o  msr=%x phase=%0d int=%0d nbuf=%0d pos=%0d dir=%0d", cycles,
               sim_top.emu.wbm_adr[16] ? "H" : "U", sim_top.emu.wbm_we ? "W" : "R", sim_top.emu.wbm_adr[15:0],
               sim_top.emu.wbm_we ? sim_top.emu.wbm_dat_o : sim_top.emu.wbm_dat_i,
               sim_top.emu.fdc.msr, sim_top.emu.fdc.phase, sim_top.emu.fdc.int_o,
               sim_top.emu.fdc.nbuf, sim_top.emu.fdc.pos, sim_top.emu.fdc.dir);
   end
end


// +vidmon: a line a frame with the display pointers and the renderer's state
reg vid_on = 0;
integer frames = 0;
initial vid_on = $test$plusargs("vidmon");
always @(posedge sim_top.emu.clk_sys) if(vid_on && sim_top.emu.video.frame_tick) begin
   frames = frames + 1;
   $display("frame %0d tas=%o tap=%o state=%0d rendering=%0d pc=%o halt=%0d dbg=%h", frames,
            sim_top.emu.video.tasaddr, sim_top.emu.video.tapaddr, sim_top.emu.video.state,
            sim_top.emu.video.rendering, sim_top.emu.dbg_adr[15:0], sim_top.emu.vm_halt, sim_top.emu.dbg_cpu);
end


// +linemon=F: in frame F, every segment of lines 2 and 150 as the renderer sees it
integer mon_frame = -1;
initial if(!$value$plusargs("linemon=%d", mon_frame)) mon_frame = -1;
always @(posedge sim_top.emu.clk_sys) if(frames == mon_frame) begin
   if(sim_top.emu.video.state == 13 && (sim_top.emu.video.line == 2 || sim_top.emu.video.line == 150))
      $display("  line %0d seg lo=%o hi=%o -> addr=%o len=%0d vmode=%0d pb=%0d", sim_top.emu.video.line - 2,
               sim_top.emu.video.tmp, sim_top.emu.video.fetch_data,
               {sim_top.emu.video.fetch_data[3:0], sim_top.emu.video.tmp, 2'b00},
               (32 - sim_top.emu.video.fetch_data[14:10]) & 31, sim_top.emu.video.fetch_data[9:6], sim_top.emu.video.fetch_data[15]);
   if(sim_top.emu.video.state == 14 && (sim_top.emu.video.line == 2 || sim_top.emu.video.line == 150))
      $display("      palbase=%0d entries %02x%02x %02x%02x %02x%02x %02x%02x  +14: %02x%02x %02x%02x", sim_top.emu.video.palbase,
               sim_top.emu.video.pal_hi[sim_top.emu.video.palbase], sim_top.emu.video.pal_lo[sim_top.emu.video.palbase],
               sim_top.emu.video.pal_hi[sim_top.emu.video.palbase+1], sim_top.emu.video.pal_lo[sim_top.emu.video.palbase+1],
               sim_top.emu.video.pal_hi[sim_top.emu.video.palbase+2], sim_top.emu.video.pal_lo[sim_top.emu.video.palbase+2],
               sim_top.emu.video.pal_hi[sim_top.emu.video.palbase+3], sim_top.emu.video.pal_lo[sim_top.emu.video.palbase+3],
               sim_top.emu.video.pal_hi[sim_top.emu.video.palbase+14], sim_top.emu.video.pal_lo[sim_top.emu.video.palbase+14],
               sim_top.emu.video.pal_hi[sim_top.emu.video.palbase+15], sim_top.emu.video.pal_lo[sim_top.emu.video.palbase+15]);
   if(sim_top.emu.video.state == 2 && sim_top.emu.video.ret == 18 && (sim_top.emu.video.line == 2 || sim_top.emu.video.line == 150) && sim_top.emu.video.x < 64)
      $display("      data word %o at x=%0d", sim_top.emu.video.fetch_data, sim_top.emu.video.x);
   if(sim_top.emu.video.state == 11 && (sim_top.emu.video.line == 2 || sim_top.emu.video.line == 150))
      $display("  line %0d tas entry lo=%o hi=%o", sim_top.emu.video.line - 2, sim_top.emu.video.tmp, sim_top.emu.video.fetch_data);
   if(sim_top.emu.video.state == 6)
      $display("  vdptas=%o vdptap=%o pal0=%02x%02x", sim_top.emu.video.tasaddr, {sim_top.emu.video.fetch_data[3:0], sim_top.emu.video.tmp, 2'b00},
               sim_top.emu.video.pal_hi[0], sim_top.emu.video.pal_lo[0]);
end


// +lowmon: every CPU write into RAM words 0..17 (the display pointers), from frame +lowfrom=F
integer low_from = 0;
reg low_on = 0;
initial begin low_on = $test$plusargs("lowmon"); if(!$value$plusargs("lowfrom=%d", low_from)) low_from = 0; end
always @(posedge sim_top.emu.clk_sys) if(low_on && frames >= low_from && sim_top.emu.mem.state == 0 && sim_top.emu.mem.cpu_req_s && !sim_top.emu.mem.cpu_ack &&
      sim_top.emu.cpu_ram_we && sim_top.emu.cpu_ram_addr < 21'd16)
   $display("frame %0d: write ram %o <= %o (cpu %s%o sel=%b) prev pc %o", frames, {sim_top.emu.cpu_ram_addr, 1'b0}, sim_top.emu.wbm_dat_o,
            sim_top.emu.wbm_adr[16] ? "H" : "U", sim_top.emu.wbm_adr[15:0], sim_top.emu.wbm_sel, sim_top.emu.dbg_adr[15:0]);

// +adrmon=N: the first bus cycles whose halt flag + address bits 16..6 equal N (as the HW debug overlay shows them)
integer adr_match = -1, adr_lines = 0, adr_from = 0;
initial begin if(!$value$plusargs("adrmon=%d", adr_match)) adr_match = -1; if(!$value$plusargs("adrfrom=%d", adr_from)) adr_from = 0; end
always @(posedge sim_top.emu.clk_cpu) begin
   if(adr_match >= 0 && frames >= adr_from && adr_lines < 100000 && sim_top.emu.wbm_stb && sim_top.emu.wbm_ack && sim_top.emu.wbm_adr[16:6] == adr_match[10:0]) begin
      $display("%0d f%0d ADR %s%s %o = %o halt=%0d", cycles, frames,
               sim_top.emu.wbm_adr[16] ? "H" : "U", sim_top.emu.wbm_we ? "W" : "R", sim_top.emu.wbm_adr[15:0],
               sim_top.emu.wbm_we ? sim_top.emu.wbm_dat_o : sim_top.emu.wbm_dat_i, sim_top.emu.vm_halt);
      adr_lines = adr_lines + 1;
   end
end

// +sdmon=C: SDRAM commands (and the model's data) for 100 commands from CPU cycle C
integer sd_from = -1, sd_lines = 0;
initial if(!$value$plusargs("sdmon=%d", sd_from)) sd_from = -1;
wire [2:0] sd_cmd = {sim_top.SDRAM_nRAS, sim_top.SDRAM_nCAS, sim_top.SDRAM_nWE};
always @(negedge sim_top.SDRAM_CLK) if(sd_from >= 0 && cycles >= sd_from && sd_lines < 100) begin
   if(sd_cmd != 3'b111) begin
      $display("  c%0d SD %s a=%h ba=%0d dqm=%b dq=%h   mem.req=%0d ack=%0d state=%0d cpu_req=%0d cpu_ack=%0d", cycles,
               sd_cmd == 3'b011 ? "ACT " : sd_cmd == 3'b101 ? "READ" : sd_cmd == 3'b100 ? "WRIT" : sd_cmd == 3'b001 ? "REF " : sd_cmd == 3'b010 ? "PRE " : "MODE",
               sim_top.SDRAM_A, sim_top.SDRAM_BA, {sim_top.SDRAM_DQMH, sim_top.SDRAM_DQML}, sim_top.SDRAM_DQ,
               sim_top.emu.mem.req, sim_top.emu.mem.ack, sim_top.emu.mem.state, sim_top.emu.mem.cpu_req_s, sim_top.emu.mem.cpu_ack);
      sd_lines = sd_lines + 1;
   end
end

endmodule
