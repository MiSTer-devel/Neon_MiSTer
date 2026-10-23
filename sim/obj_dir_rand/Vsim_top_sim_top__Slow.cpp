// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "Vsim_top__pch.h"

void Vsim_top_sim_top___ctor_var_reset(Vsim_top_sim_top* vlSelf);

Vsim_top_sim_top::Vsim_top_sim_top() = default;
Vsim_top_sim_top::~Vsim_top_sim_top() = default;

void Vsim_top_sim_top::ctor(Vsim_top__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vsim_top_sim_top___ctor_var_reset(this);
}

void Vsim_top_sim_top::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vsim_top_sim_top::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
