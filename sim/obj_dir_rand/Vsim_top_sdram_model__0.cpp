// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "Vsim_top__pch.h"

void Vsim_top_sdram_model___nba_sequent__TOP__sim_top__sdram__0(Vsim_top_sdram_model* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_top_sdram_model___nba_sequent__TOP__sim_top__sdram__0\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __PVT__cmd;
    __PVT__cmd = 0;
    CData/*7:0*/ __VdlyVal__mem__v0;
    __VdlyVal__mem__v0 = 0;
    IData/*20:0*/ __VdlyDim0__mem__v0;
    __VdlyDim0__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__mem__v0;
    __VdlySet__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__mem__v1;
    __VdlyVal__mem__v1 = 0;
    IData/*20:0*/ __VdlyDim0__mem__v1;
    __VdlyDim0__mem__v1 = 0;
    CData/*0:0*/ __VdlySet__mem__v1;
    __VdlySet__mem__v1 = 0;
    // Body
    __VdlySet__mem__v0 = 0U;
    __VdlySet__mem__v1 = 0U;
    vlSelfRef.__PVT__drive = vlSelfRef.__PVT__rd2;
    vlSelfRef.__PVT__dout = vlSelfRef.__PVT__rdata2;
    vlSelfRef.__PVT__rd2 = vlSelfRef.__PVT__rd1;
    vlSelfRef.__PVT__rdata2 = vlSelfRef.__PVT__rdata1;
    __PVT__cmd = vlSymsp->TOP__sim_top.__PVT__emu__DOT__mem__DOT__sdram__DOT__command;
    vlSelfRef.__PVT__rd1 = 0U;
    if ((3U == (IData)(__PVT__cmd))) {
        vlSelfRef.__PVT__row = (0x00000fffU & (IData)(vlSymsp->TOP__sim_top.__PVT__SDRAM_A));
    } else if ((5U == (IData)(__PVT__cmd))) {
        vlSelfRef.__PVT__rd1 = 1U;
        vlSelfRef.__PVT__rdata1 = vlSelfRef.mem[vlSelfRef.__PVT__addr];
    } else if ((4U == (IData)(__PVT__cmd))) {
        if ((1U & (~ (IData)(vlSymsp->TOP__sim_top.__PVT__SDRAM_DQML)))) {
            __VdlyVal__mem__v0 = (0x000000ffU & (IData)(vlSymsp->TOP__sim_top.__PVT__SDRAM_DQ));
            __VdlyDim0__mem__v0 = vlSelfRef.__PVT__addr;
            __VdlySet__mem__v0 = 1U;
        }
        if ((1U & (~ (IData)(vlSymsp->TOP__sim_top.__PVT__SDRAM_DQMH)))) {
            __VdlyVal__mem__v1 = (0x000000ffU & ((IData)(vlSymsp->TOP__sim_top.__PVT__SDRAM_DQ) 
                                                 >> 8U));
            __VdlyDim0__mem__v1 = vlSelfRef.__PVT__addr;
            __VdlySet__mem__v1 = 1U;
        }
    }
    if (__VdlySet__mem__v0) {
        vlSelfRef.mem[__VdlyDim0__mem__v0] = ((0xff00U 
                                               & vlSelfRef.mem
                                               [__VdlyDim0__mem__v0]) 
                                              | (SData)(__VdlyVal__mem__v0));
    }
    if (__VdlySet__mem__v1) {
        vlSelfRef.mem[__VdlyDim0__mem__v1] = ((0x00ffU 
                                               & vlSelfRef.mem
                                               [__VdlyDim0__mem__v1]) 
                                              | ((SData)((IData)(__VdlyVal__mem__v1)) 
                                                 << 8U));
    }
}

void Vsim_top_sdram_model___nba_comb__TOP__sim_top__sdram__0(Vsim_top_sdram_model* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vsim_top_sdram_model___nba_comb__TOP__sim_top__sdram__0\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__addr = (((IData)(vlSelfRef.__PVT__row) 
                              << 9U) | (0x000001ffU 
                                        & (IData)(vlSymsp->TOP__sim_top.__PVT__SDRAM_A)));
}
