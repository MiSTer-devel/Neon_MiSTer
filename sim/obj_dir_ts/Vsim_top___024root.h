// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vsim_top.h for the primary calling header

#ifndef VERILATED_VSIM_TOP___024ROOT_H_
#define VERILATED_VSIM_TOP___024ROOT_H_  // guard

#include "verilated.h"
class Vsim_top_sim_top;


class Vsim_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vsim_top___024root final {
  public:
    // CELLS
    Vsim_top_sim_top* sim_top;

    // DESIGN SPECIFIC STATE
    VL_IN8(CLK_50M,0,0);
    VL_IN8(RESET,0,0);
    VL_IN8(img_mounted,1,0);
    VL_OUT8(sd_rd,1,0);
    VL_OUT8(sd_wr,1,0);
    VL_IN8(sd_ack,1,0);
    VL_IN8(sd_buff_addr,7,0);
    VL_IN8(sd_buff_wr,0,0);
    VL_OUT8(CE_PIXEL,0,0);
    VL_OUT8(VGA_R,7,0);
    VL_OUT8(VGA_G,7,0);
    VL_OUT8(VGA_B,7,0);
    VL_OUT8(VGA_HS,0,0);
    VL_OUT8(VGA_VS,0,0);
    VL_OUT8(VGA_DE,0,0);
    VL_OUT8(LED_USER,0,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__CLK_50M__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__RESET__0;
    CData/*1:0*/ __Vtrigprevexpr___TOP__img_mounted__0;
    CData/*1:0*/ __Vtrigprevexpr___TOP__sd_ack__0;
    CData/*7:0*/ __Vtrigprevexpr___TOP__sd_buff_addr__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__sd_buff_wr__0;
    CData/*0:0*/ __VicoDidInit;
    CData/*0:0*/ __Vtrigprevexpr___TOP__sim_top____PVT__emu__DOT__clk_cpu__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__CLK_50M__1;
    CData/*0:0*/ __Vtrigprevexpr_hf7916eec__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__sim_top____PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__3__KET____0;
    VL_IN16(ps2_key,10,0);
    VL_IN16(sd_buff_dout,15,0);
    VL_OUT16(sd_buff_din,15,0);
    VL_OUT16(AUDIO_L,15,0);
    VL_OUT16(AUDIO_R,15,0);
    SData/*10:0*/ __Vtrigprevexpr___TOP__ps2_key__0;
    SData/*15:0*/ __Vtrigprevexpr___TOP__sd_buff_dout__0;
    VL_IN(ps2_mouse,24,0);
    VL_IN(img_size,31,0);
    VL_OUT(sd_lba,31,0);
    IData/*24:0*/ __Vtrigprevexpr___TOP__ps2_mouse__0;
    IData/*31:0*/ __Vtrigprevexpr___TOP__img_size__0;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 2> __VicoTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vsim_top__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vsim_top___024root(Vsim_top__Syms* symsp, const char* namep);
    ~Vsim_top___024root();
    VL_UNCOPYABLE(Vsim_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
