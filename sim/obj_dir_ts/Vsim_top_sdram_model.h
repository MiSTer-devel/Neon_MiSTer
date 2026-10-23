// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsim_top.h for the primary calling header

#ifndef VERILATED_VSIM_TOP_SDRAM_MODEL_H_
#define VERILATED_VSIM_TOP_SDRAM_MODEL_H_  // guard

#include "verilated.h"


class Vsim_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsim_top_sdram_model final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __PVT__clk;
    CData/*1:0*/ __PVT__ba;
    CData/*0:0*/ __PVT__dqml;
    CData/*0:0*/ __PVT__dqmh;
    CData/*0:0*/ __PVT__ncs;
    CData/*0:0*/ __PVT__nwe;
    CData/*0:0*/ __PVT__nras;
    CData/*0:0*/ __PVT__ncas;
    CData/*0:0*/ __PVT__rd1;
    CData/*0:0*/ __PVT__rd2;
    CData/*0:0*/ __PVT__drive;
    SData/*15:0*/ __PVT__dq;
    SData/*12:0*/ __PVT__a;
    SData/*11:0*/ __PVT__row;
    SData/*15:0*/ __PVT__rdata1;
    SData/*15:0*/ __PVT__rdata2;
    SData/*15:0*/ __PVT__dout;
    SData/*15:0*/ dq__out;
    SData/*15:0*/ dq__en;
    IData/*20:0*/ __PVT__addr;
    VlUnpacked<SData/*15:0*/, 2097152> mem;

    // INTERNAL VARIABLES
    Vsim_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vsim_top_sdram_model();
    ~Vsim_top_sdram_model();
    void ctor(Vsim_top__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vsim_top_sdram_model);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
