# Model of the core for Verilator: make, then run sim/obj_dir/Vsim_top
# FRAMES EVERY [options] from a directory holding an rtl/ link (the ROM
# is read as rtl/rom/pk11_rom.hex).
# make RAND=1 builds obj_dir_rand with --x-initial unique: run with
# +verilator+rand+reset+2 +verilator+seed+N to randomise the power-up state

RTL = ../rtl
OBJ = obj_dir$(if $(RAND),_rand,)
XINIT = $(if $(RAND),--x-initial unique,)
SRC = sim_top.sv monitor.sv hps_io_sim.sv video_mixer_sim.sv pll_sim.v sdram_model.sv ../Neon.sv \
      $(RTL)/vm2/vm2_wb.v $(RTL)/vm2/vm2_plm.v $(RTL)/vm_reset.v $(RTL)/pit8253.v \
      $(RTL)/sdram.sv $(RTL)/neon_mem.sv $(RTL)/neon_rom.sv $(RTL)/neon_video.sv \
      $(RTL)/neon_sys.sv $(RTL)/dpram.sv $(RTL)/fdc.sv $(RTL)/keyboard.sv

VFLAGS = --cc --exe --build -O3 -j 0 --top-module sim_top -I. -I.. \
         -Wno-fatal -Wno-WIDTH -Wno-UNUSED -Wno-PINMISSING -Wno-PINCONNECTEMPTY \
         -Wno-DECLFILENAME -Wno-UNDRIVEN -Wno-CASEINCOMPLETE -Wno-MULTIDRIVEN \
         -Wno-TIMESCALEMOD -Wno-COMBDLY -Wno-CASEX -Wno-UNOPTFLAT -Wno-BLKSEQ \
         -CFLAGS -O2

$(OBJ)/Vsim_top: $(SRC) sim_main.cpp
	verilator $(VFLAGS) $(XINIT) --Mdir $(OBJ) $(SRC) sim_main.cpp

clean:
	rm -rf obj_dir obj_dir_rand *.ppm

.PHONY: clean
