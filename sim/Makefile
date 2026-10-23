# Model of the core for Verilator: make, then (from the project root)
# sim/obj_dir/Vsim_top FRAMES EVERY [options]
# make SDRAM=sdram_slot builds sim/obj_dir_ts with the old slot-based controller;
# make RAND=1 builds *_rand with --x-initial unique: run with
# +verilator+rand+reset+2 +verilator+seed+N to randomise the power-up state

RTL = ../rtl
SDRAM ?= sdram
OBJ = $(if $(filter sdram,$(SDRAM)),obj_dir,obj_dir_ts)$(if $(RAND),_rand,)
XINIT = $(if $(RAND),--x-initial unique,)
SRC = sim_top.sv monitor.sv hps_io_sim.sv video_mixer_sim.sv pll_sim.v sdram_model.sv ../Neon.sv \
      $(RTL)/vm2/vm2_wb.v $(RTL)/vm2/vm2_plm.v $(RTL)/vm_reset.v $(RTL)/pit8253.v \
      $(RTL)/$(SDRAM).sv $(RTL)/neon_mem.sv $(RTL)/neon_rom.sv $(RTL)/neon_video.sv \
      $(RTL)/neon_sys.sv $(RTL)/dpram.sv $(RTL)/fdc.sv $(RTL)/keyboard.sv

VFLAGS = --cc --exe --build -O3 -j 0 --top-module sim_top -I. -I.. \
         -Wno-fatal -Wno-WIDTH -Wno-UNUSED -Wno-PINMISSING -Wno-PINCONNECTEMPTY \
         -Wno-DECLFILENAME -Wno-UNDRIVEN -Wno-CASEINCOMPLETE -Wno-MULTIDRIVEN \
         -Wno-TIMESCALEMOD -Wno-COMBDLY -Wno-CASEX -Wno-UNOPTFLAT -Wno-BLKSEQ \
         -CFLAGS -O2

$(OBJ)/Vsim_top: $(SRC) sim_main.cpp
	verilator $(VFLAGS) $(XINIT) --Mdir $(OBJ) $(SRC) sim_main.cpp

clean:
	rm -rf obj_dir obj_dir_ts *.ppm

.PHONY: clean
