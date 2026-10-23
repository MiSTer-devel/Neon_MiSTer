// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "Vsim_top__pch.h"

VL_ATTR_COLD void Vsim_top_sdram_model___eval_static__TOP__sim_top__sdram(Vsim_top_sdram_model* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_top_sdram_model___eval_static__TOP__sim_top__sdram\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__row = 0U;
    vlSelfRef.__PVT__rd1 = 0U;
    vlSelfRef.__PVT__rd2 = 0U;
    vlSelfRef.__PVT__drive = 0U;
}

VL_ATTR_COLD void Vsim_top_sdram_model___ctor_var_reset(Vsim_top_sdram_model* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_top_sdram_model___ctor_var_reset\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__PVT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->__PVT__dq = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 5194084716458346210ull);
    vlSelf->__PVT__a = VL_SCOPED_RAND_RESET_I(13, __VscopeHash, 510903276987443985ull);
    vlSelf->__PVT__ba = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13913074996085095135ull);
    vlSelf->__PVT__dqml = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2677815409532037072ull);
    vlSelf->__PVT__dqmh = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18416457097958626982ull);
    vlSelf->__PVT__ncs = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5435045564708987814ull);
    vlSelf->__PVT__nwe = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6908023722684379908ull);
    vlSelf->__PVT__nras = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9197231716863909691ull);
    vlSelf->__PVT__ncas = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7375744771599957189ull);
    for (int __Vi0 = 0; __Vi0 < 2097152; ++__Vi0) {
        vlSelf->mem[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 4032165174000709208ull);
    }
    vlSelf->__PVT__rdata1 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12169918079455006130ull);
    vlSelf->__PVT__rdata2 = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10569764147769340794ull);
    vlSelf->__PVT__dout = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 11474705599699299244ull);
    vlSelf->__PVT__addr = VL_SCOPED_RAND_RESET_I(21, __VscopeHash, 14934084843038794831ull);
    vlSelf->dq__out = 0;
    vlSelf->dq__en = 0;
}
