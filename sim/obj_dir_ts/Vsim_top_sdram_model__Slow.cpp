// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "Vsim_top__pch.h"

void Vsim_top_sdram_model___ctor_var_reset(Vsim_top_sdram_model* vlSelf);

Vsim_top_sdram_model::Vsim_top_sdram_model() = default;
Vsim_top_sdram_model::~Vsim_top_sdram_model() = default;

void Vsim_top_sdram_model::ctor(Vsim_top__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vsim_top_sdram_model___ctor_var_reset(this);
}

void Vsim_top_sdram_model::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vsim_top_sdram_model::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
