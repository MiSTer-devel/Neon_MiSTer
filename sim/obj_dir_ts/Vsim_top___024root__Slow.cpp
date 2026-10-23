// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "Vsim_top__pch.h"

void Vsim_top___024root___ctor_var_reset(Vsim_top___024root* vlSelf);

Vsim_top___024root::Vsim_top___024root(Vsim_top__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vsim_top___024root___ctor_var_reset(this);
}

void Vsim_top___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vsim_top___024root::~Vsim_top___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
