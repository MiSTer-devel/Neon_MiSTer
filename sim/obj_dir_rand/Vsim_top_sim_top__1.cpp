// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "Vsim_top__pch.h"

void Vsim_top_sim_top___nba_sequent__TOP__sim_top__2(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_sequent__TOP__sim_top__2\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v1 = 0U;
    vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v1 = 0U;
    vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v0 = 0U;
    vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v0 = 0U;
}

extern const VlUnpacked<CData/*1:0*/, 128> Vsim_top__ConstPool__TABLE_hb1452a0c_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsim_top__ConstPool__TABLE_h37b90ccd_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vsim_top__ConstPool__TABLE_hbfad6147_0;

void Vsim_top_sim_top___nba_sequent__TOP__sim_top__3(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_sequent__TOP__sim_top__3\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    SData/*8:0*/ __Vdly__emu__DOT__cpu__DOT__qtim;
    __Vdly__emu__DOT__cpu__DOT__qtim = 0;
    CData/*0:0*/ __Vdly__emu__DOT__cpu__DOT__tend;
    __Vdly__emu__DOT__cpu__DOT__tend = 0;
    CData/*0:0*/ __Vdly__emu__DOT__cpu__DOT__tabort;
    __Vdly__emu__DOT__cpu__DOT__tabort = 0;
    // Body
    __Vdly__emu__DOT__cpu__DOT__qtim = vlSelfRef.__PVT__emu__DOT__cpu__DOT__qtim;
    __Vdly__emu__DOT__cpu__DOT__tabort = vlSelfRef.__PVT__emu__DOT__cpu__DOT__tabort;
    __Vdly__emu__DOT__cpu__DOT__tend = vlSelfRef.__PVT__emu__DOT__cpu__DOT__tend;
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy0_set) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy0 = 1U;
    } else if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__1__KET__) 
                & ((((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_1tm) 
                     | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_f4r)) 
                    & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_div)) 
                   | ((~ (0U != (3U & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ireg) 
                                       >> 9U)))) & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_ctld))))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy0 = 0U;
    }
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__cmd_nrdy = 
        (((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res)) 
          & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ir_stb))) 
         & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__set_cend) 
            | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__cmd_nrdy)));
    __Vdly__emu__DOT__cpu__DOT__tend = ((~ ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tena)) 
                                            | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tend))) 
                                        & (0x01feU 
                                           == (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qtim)));
    __Vdly__emu__DOT__cpu__DOT__tabort = (((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tim_nrdy1)) 
                                           & (0x0033U 
                                              == (0x0033U 
                                                  & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qtim)))) 
                                          & (~ ((((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tena)) 
                                                  | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tabort)) 
                                                 | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tend)) 
                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tadone))));
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__tena) {
        __Vdly__emu__DOT__cpu__DOT__qtim = (0x000001ffU 
                                            & ((IData)(1U) 
                                               + (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qtim)));
        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__tabort) {
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__tadone = 1U;
        }
    } else {
        __Vdly__emu__DOT__cpu__DOT__qtim = 0U;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__tadone = 0U;
    }
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__to_rply = 
        ((((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_rcd) 
           & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__word27))) 
          & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tabort)) 
         & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__to_rply)));
    if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res) 
         | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy1_clr))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy1 = 0U;
    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_ctld) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy1 = 1U;
    }
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__1__KET__) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_rcd1 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_rcd1_xt;
    }
    __Vtableidx1 = ((((((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iopc_st__BRA__0__KET__) 
                        << 3U) | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_rcdr) 
                                  << 2U)) | (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_cmdr) 
                                              << 1U) 
                                             | (7U 
                                                == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)))) 
                     << 3U) | (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_cmd) 
                                << 2U) | (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__word27) 
                                           << 1U) | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_wr))));
    if ((0U != (1U & Vsim_top__ConstPool__TABLE_hb1452a0c_0
                [__Vtableidx1]))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__iopc_st__BRA__0__KET__ 
            = Vsim_top__ConstPool__TABLE_h37b90ccd_0
            [__Vtableidx1];
    }
    if ((0U != (2U & Vsim_top__ConstPool__TABLE_hb1452a0c_0
                [__Vtableidx1]))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__iopc_st__BRA__1__KET__ 
            = Vsim_top__ConstPool__TABLE_hbfad6147_0
            [__Vtableidx1];
    }
    if ((1U & (((((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__reset) 
                  | (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__br_iocmd))) 
                 | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__buf_res)) 
                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__word27)) 
               | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ir_stb)))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__br_ready = 0U;
    } else if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__br_iocmd) 
                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__bir_stb))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__br_ready = 1U;
    }
    if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__1__KET__) 
         | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__0__KET__))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__2__KET__ = 1U;
    } else if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__word27) 
                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_wr))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__2__KET__ = 0U;
    }
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy2_clr 
        = vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy1_clr;
    if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_cmdr) 
         | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_wr) 
            & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_cmd)))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__br_cmdrq = 0U;
    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__rcmd_set) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__br_cmdrq = 1U;
    }
    if ((((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res) 
          | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pi_stb)) 
         | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_wr))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_nrdy = 0U;
    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_stb) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_nrdy = 1U;
    }
    if ((1U & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res) 
               | ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_st__BRA__4__KET__)) 
                  & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_st__BRA__5__KET__)))))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_st__BRA__2__KET__ = 0U;
    } else if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_start) 
                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_st__BRA__1__KET__))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_st__BRA__2__KET__ = 1U;
    }
    if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res) 
         | (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_drdy0) 
             | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_start) 
                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_in))) 
            & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_sta))))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_drdy1 = 0U;
    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__brd_wq) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_drdy1 = 1U;
    }
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__pswt_wa) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw = 
            ((0x01efU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)) 
             | (0x00000010U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ax)));
    }
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw = 
            ((0x011fU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)) 
             | (0x000000e0U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ax)));
    }
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw8_wa) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw = 
            ((0x00ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)) 
             | (0x00000100U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ax)));
    }
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw = 
            ((0x01f0U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)) 
             | (0x0000000fU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ax)));
    } else {
        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__pswc_stb) {
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw 
                = ((0x01feU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)) 
                   | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__cond_c));
        }
        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_stb) {
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw 
                = ((0x01fdU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)) 
                   | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__cond_v) 
                      << 1U));
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw 
                = ((0x01fbU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)) 
                   | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__cond_z) 
                      << 2U));
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw 
                = ((0x01f7U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)) 
                   | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__cond_n) 
                      << 3U));
        }
    }
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__qtim = __Vdly__emu__DOT__cpu__DOT__qtim;
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__tabort = __Vdly__emu__DOT__cpu__DOT__tabort;
    if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__reset) 
         | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tend))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__tim_nrdy1 = 0U;
    } else if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pi_stb) 
                & (vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm 
                   >> 0x0dU))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__tim_nrdy1 = 1U;
    }
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_wr) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_rcdr 
            = (7U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2));
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_cmdr 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_cmd;
    }
    if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_cmd) 
         & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wra))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__br_iocmd = 0U;
    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_sta) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__br_iocmd = 1U;
    }
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_st__BRA__4__KET__ 
        = vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_st__BRA__3__KET__;
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_sta) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_drdy0 = 0U;
    } else if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_start) 
                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_in))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_drdy0 = 1U;
    }
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__tend = __Vdly__emu__DOT__cpu__DOT__tend;
}

void Vsim_top_sim_top___nba_sequent__TOP__sim_top__4(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_sequent__TOP__sim_top__4\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__emu__DOT__sys__DOT__rst__DOT__powerup 
        = ((2U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu_reset_s))
            ? 0U : (0x0000001fU & ((IData)(vlSelfRef.__PVT__emu__DOT__vm_aclo)
                                    ? ((IData)(1U) 
                                       + (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rst__DOT__powerup))
                                    : (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rst__DOT__powerup))));
    vlSelfRef.__PVT__emu__DOT__vm_aclo = (1U & (~ (3U 
                                                   == 
                                                   (3U 
                                                    & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rst__DOT__powerup) 
                                                       >> 3U)))));
}

void Vsim_top_sim_top___nba_sequent__TOP__sim_top__5(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_sequent__TOP__sim_top__5\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__3__KET__) {
        if ((1U & (~ ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_cyc) 
                      | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__adr_req))))) {
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__4__KET__ = 1U;
        }
    } else {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__4__KET__ = 0U;
    }
}

extern const VlWide<256>/*8191:0*/ Vsim_top__ConstPool__CONST_hf0d4d37b_0;

void Vsim_top_sim_top___nba_sequent__TOP__sim_top__6(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_sequent__TOP__sim_top__6\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __PVT__emu__DOT__sys__DOT__pit_rd;
    __PVT__emu__DOT__sys__DOT__pit_rd = 0;
    CData/*0:0*/ __PVT__emu__DOT__sys__DOT__pit_wr;
    __PVT__emu__DOT__sys__DOT__pit_wr = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__qswp;
    __PVT__emu__DOT__cpu__DOT__qswp = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__alu_xb;
    __PVT__emu__DOT__cpu__DOT__alu_xb = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__sxt_rxy;
    __PVT__emu__DOT__cpu__DOT__sxt_rxy = 0;
    CData/*7:0*/ __Vfunc_emu__DOT__sys__DOT__pic_poll_val__6__rr;
    __Vfunc_emu__DOT__sys__DOT__pic_poll_val__6__rr = 0;
    CData/*6:0*/ __Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx;
    __Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx = 0;
    CData/*6:0*/ __Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx;
    __Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx = 0;
    CData/*5:0*/ __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__9__ctl;
    __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__9__ctl = 0;
    CData/*5:0*/ __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__10__ctl;
    __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__10__ctl = 0;
    CData/*5:0*/ __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl;
    __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl = 0;
    CData/*5:0*/ __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl;
    __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl = 0;
    CData/*5:0*/ __Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__13__ctl;
    __Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__13__ctl = 0;
    CData/*5:0*/ __Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__14__ctl;
    __Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__14__ctl = 0;
    CData/*5:0*/ __Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl;
    __Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_40;
    __VdfgRegularize_hebeb780c_0_40 = 0;
    CData/*4:0*/ __VdfgRegularize_hebeb780c_0_101;
    __VdfgRegularize_hebeb780c_0_101 = 0;
    CData/*4:0*/ __VdfgRegularize_hebeb780c_0_102;
    __VdfgRegularize_hebeb780c_0_102 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_151;
    __VdfgRegularize_hebeb780c_0_151 = 0;
    CData/*1:0*/ __Vdly__emu__DOT__fdc__DOT__done_s;
    __Vdly__emu__DOT__fdc__DOT__done_s = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__HR__v8;
    __VdlyVal__emu__DOT__sys__DOT__HR__v8 = 0;
    CData/*2:0*/ __VdlyDim0__emu__DOT__sys__DOT__HR__v8;
    __VdlyDim0__emu__DOT__sys__DOT__HR__v8 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__HR__v9;
    __VdlyVal__emu__DOT__sys__DOT__HR__v9 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__HR__v10;
    __VdlyVal__emu__DOT__sys__DOT__HR__v10 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__writehi__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__writehi__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__readhi__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__readhi__v3 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__latch__v3;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__latch__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__latch__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__latch__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v3 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v3;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__output_r__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__output_r__v3 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v3;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v4;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v4 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v4;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v4 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v4;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v4 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v5;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v5 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v5;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v5 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v5;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v5 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v6;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v6 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v6;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v6 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v6;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v6 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__writehi__v4;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__writehi__v4 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__writehi__v4;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__writehi__v4 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v4;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v4 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v5;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v5 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v6;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v6 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__readhi__v4;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__readhi__v4 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__readhi__v4;
    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__readhi__v4 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v3;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v3 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v4;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v4 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v5;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v5 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v6;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v6 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v7;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v7 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v8;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v8 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v8;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v8 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v9;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v9 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v9;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v9 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v10;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v10 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v10;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v10 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v12;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v12 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v13;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v13 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v14;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v14 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v15;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v15 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v16;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v16 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v17;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v17 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v19;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v19 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v20;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v20 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v21;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v21 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v22;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v22 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v23;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v23 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v20;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v20 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v25;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v25 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v21;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v21 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v26;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v26 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v22;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v22 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v23;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v23 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v27;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v27 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v29;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v29 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v30;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v30 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v31;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v31 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v32;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v32 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v33;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v33 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v34;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v34 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v36;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v36 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v37;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v37 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v38;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v38 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v39;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v39 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v40;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v40 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v33;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v33 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v42;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v42 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v34;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v34 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v43;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v43 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v35;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v35 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v36;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v36 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v44;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v44 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v46;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v46 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v47;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v47 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v48;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v48 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v49;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v49 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v50;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v50 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v51;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v51 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v53;
    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v53 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__writehi__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__writehi__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__readhi__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__readhi__v3 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__latch__v3;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__latch__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__latch__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__latch__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v3 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v3;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__output_r__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__output_r__v3 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v3;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v3;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v3 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v4;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v4 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v4;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v4 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v4;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v4 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v5;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v5 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v5;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v5 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v5;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v5 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v6;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v6 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v6;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v6 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v6;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v6 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__writehi__v4;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__writehi__v4 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__writehi__v4;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__writehi__v4 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v4;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v4 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v5;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v5 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v6;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v6 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__readhi__v4;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__readhi__v4 = 0;
    CData/*1:0*/ __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__readhi__v4;
    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__readhi__v4 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v3;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v3 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v4;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v4 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v5;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v5 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v6;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v6 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v7;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v7 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v8;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v8 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v8;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v8 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v9;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v9 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v9;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v9 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v10;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v10 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v10;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v10 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v12;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v12 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v13;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v13 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v14;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v14 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v15;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v15 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v16;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v16 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v17;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v17 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v19;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v19 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v20;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v20 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v21;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v21 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v22;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v22 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v23;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v23 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v19;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v19 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v25;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v25 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v20;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v20 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v26;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v26 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v21;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v21 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v22;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v22 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v27;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v27 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v29;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v29 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v30;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v30 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v31;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v31 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v32;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v32 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v33;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v33 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v34;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v34 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v36;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v36 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v37;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v37 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v38;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v38 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v39;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v39 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v40;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v40 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v31;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v31 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v42;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v42 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v32;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v32 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v43;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v43 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v33;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v33 = 0;
    CData/*0:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v34;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v34 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v44;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v44 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v46;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v46 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v47;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v47 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v48;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v48 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v49;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v49 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v50;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v50 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v51;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v51 = 0;
    SData/*15:0*/ __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v53;
    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v53 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__cmd__v0;
    __VdlyVal__emu__DOT__fdc__DOT__cmd__v0 = 0;
    CData/*3:0*/ __VdlyDim0__emu__DOT__fdc__DOT__cmd__v0;
    __VdlyDim0__emu__DOT__fdc__DOT__cmd__v0 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v1;
    __VdlyVal__emu__DOT__fdc__DOT__res__v1 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v3;
    __VdlyVal__emu__DOT__fdc__DOT__res__v3 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v6;
    __VdlyVal__emu__DOT__fdc__DOT__res__v6 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v7;
    __VdlyVal__emu__DOT__fdc__DOT__res__v7 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v8;
    __VdlyVal__emu__DOT__fdc__DOT__res__v8 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v9;
    __VdlyVal__emu__DOT__fdc__DOT__res__v9 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v10;
    __VdlyVal__emu__DOT__fdc__DOT__res__v10 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v11;
    __VdlyVal__emu__DOT__fdc__DOT__res__v11 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v14;
    __VdlyVal__emu__DOT__fdc__DOT__res__v14 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v15;
    __VdlyVal__emu__DOT__fdc__DOT__res__v15 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v16;
    __VdlyVal__emu__DOT__fdc__DOT__res__v16 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v17;
    __VdlyVal__emu__DOT__fdc__DOT__res__v17 = 0;
    CData/*7:0*/ __VdlyVal__emu__DOT__fdc__DOT__res__v18;
    __VdlyVal__emu__DOT__fdc__DOT__res__v18 = 0;
    // Body
    vlSelfRef.__PVT__emu__DOT__dbg_beat = vlSelfRef.__Vdly__emu__DOT__dbg_beat;
    if (vlSelfRef.__VdlySet__emu__DOT__dbg_adr__v0) {
        vlSelfRef.__PVT__emu__DOT__dbg_dat[0U] = vlSelfRef.__VdlyVal__emu__DOT__dbg_dat__v0;
        vlSelfRef.__PVT__emu__DOT__dbg_dat[1U] = vlSelfRef.__VdlyVal__emu__DOT__dbg_dat__v1;
        vlSelfRef.__PVT__emu__DOT__dbg_dat[2U] = vlSelfRef.__VdlyVal__emu__DOT__dbg_dat__v2;
        vlSelfRef.__PVT__emu__DOT__dbg_dat[3U] = vlSelfRef.__VdlyVal__emu__DOT__dbg_dat__v3;
        vlSelfRef.__PVT__emu__DOT__dbg_adr[0U] = vlSelfRef.__VdlyVal__emu__DOT__dbg_adr__v0;
        vlSelfRef.__PVT__emu__DOT__dbg_adr[1U] = vlSelfRef.__VdlyVal__emu__DOT__dbg_adr__v1;
        vlSelfRef.__PVT__emu__DOT__dbg_adr[2U] = vlSelfRef.__VdlyVal__emu__DOT__dbg_adr__v2;
        vlSelfRef.__PVT__emu__DOT__dbg_adr[3U] = vlSelfRef.__VdlyVal__emu__DOT__dbg_adr__v3;
    }
    if (((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__pos) 
         & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__a_wr))) {
        vlSelfRef.__VdlyVal__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v0 
            = (0x000000ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
        vlSelfRef.__VdlyDim0__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v0 
            = vlSelfRef.__PVT__emu__DOT__fdc__DOT__a_waddr;
        vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v0 = 1U;
    }
    if (((~ (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__pos)) 
         & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__a_wr))) {
        vlSelfRef.__VdlyVal__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v0 
            = (0x000000ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
        vlSelfRef.__VdlyDim0__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v0 
            = vlSelfRef.__PVT__emu__DOT__fdc__DOT__a_waddr;
        vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v0 = 1U;
    }
    if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb) 
         & (IData)(vlSelfRef.__PVT__emu__DOT__wbm_ack))) {
        if (vlSelfRef.__PVT__emu__DOT__dbg_trap) {
            vlSelfRef.__PVT__emu__DOT__dbg_frozen = 1U;
        }
        vlSelfRef.__PVT__emu__DOT__dbg_we = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we;
    }
    if ((1U & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb)) 
               | (IData)(vlSelfRef.__PVT__emu__DOT__wbm_ack)))) {
        vlSelfRef.__Vdly__emu__DOT__dbg_stb_cnt = 0U;
    } else if ((0xffU != (IData)(vlSelfRef.__PVT__emu__DOT__dbg_stb_cnt))) {
        vlSelfRef.__Vdly__emu__DOT__dbg_stb_cnt = (0x000000ffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelfRef.__PVT__emu__DOT__dbg_stb_cnt)));
    }
    if ((0xffU == (IData)(vlSelfRef.__PVT__emu__DOT__dbg_stb_cnt))) {
        vlSelfRef.__PVT__emu__DOT__dbg_stall = 1U;
    }
    if ((2U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu_reset_s))) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__ack = 0U;
        vlSelfRef.__PVT__emu__DOT__cpu_ram_req = 0U;
        vlSelfRef.__Vdly__emu__DOT__sys__DOT__ram_wait = 0U;
        vlSelfRef.__Vdly__emu__DOT__sys__DOT__rom_wait = 0U;
        vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_mode = 1U;
        vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_poll = 0U;
        vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_rr = 0U;
        vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_mr = 0U;
        vlSelfRef.__Vdly__emu__DOT__sys__DOT__keypos = 0U;
        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__HR__v0 = 1U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_alarm_hour = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_alarm_min = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_alarm_sec = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__cyc_rd_held = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_snum = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_cnum = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_sdh = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_int = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd = 0x0bU;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__keyint = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__ppia_rd = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic = 0x0eU;
        vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousedx = 0U;
        vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousedy = 0U;
        vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousest = 0U;
    } else {
        if (vlSelfRef.__PVT__emu__DOT__vm_init) {
            if ((0U == (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_mode))) {
                vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_rr 
                    = (1U | (IData)(vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_rr));
            }
        }
        if ((0U == (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_mode))) {
            vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_rr 
                = ((0xfdU & (IData)(vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_rr)) 
                   | (((IData)(vlSelfRef.__PVT__emu__DOT__fdc_int) 
                       | (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_int)) 
                      << 1U));
            vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_rr 
                = ((0xefU & (IData)(vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_rr)) 
                   | ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__keyint) 
                      << 4U));
            if ((1U & ((0x00000010U & vlSelfRef.__PVT__emu__DOT__hps_io__DOT__status_r[0U])
                        ? (0x0001e847U == vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_div)
                        : (IData)((2U == (6U & (IData)(vlSelfRef.__PVT__emu__DOT__frame_s))))))) {
                vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_rr 
                    = (0x00000020U | (IData)(vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_rr));
            }
        }
        if (vlSelfRef.__PVT__emu__DOT__vm_init) {
            vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_int = 0U;
        }
        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb) {
            if (vlSelfRef.__PVT__emu__DOT__sys__DOT__stb_rise) {
                if (((vlSelfRef.__PVT__emu__DOT__wbm_adr 
                      >> 0x00000010U) & (0x4000U > 
                                         (0x0000ffffU 
                                          & vlSelfRef.__PVT__emu__DOT__wbm_adr)))) {
                    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                        vlSelfRef.__PVT__emu__DOT__sys__DOT__ack = 1U;
                    } else {
                        vlSelfRef.__Vdly__emu__DOT__sys__DOT__rom_wait = 1U;
                    }
                } else if ((0xe000U <= (0x0000ffffU 
                                        & vlSelfRef.__PVT__emu__DOT__wbm_adr))) {
                    if ((0xf800U > (0x0000ffffU & vlSelfRef.__PVT__emu__DOT__wbm_adr))) {
                        vlSelfRef.__PVT__emu__DOT__sys__DOT__ack = 1U;
                        vlSelfRef.__Vdly__emu__DOT__wbm_dat_i = 0U;
                        if ((0x7100U == (0x00007fffU 
                                         & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                            >> 1U)))) {
                            if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                if ((1U == (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_mode))) {
                                    vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_mode = 2U;
                                } else if ((0U == (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_mode))) {
                                    if ((0x0cU == (0x000000ffU 
                                                   & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg)))) {
                                        vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_poll = 1U;
                                    } else if ((0x20U 
                                                == 
                                                (0x000000ffU 
                                                 & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg)))) {
                                        vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_rr = 0U;
                                    }
                                }
                            } else {
                                if (((0U == (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_mode)) 
                                     & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_poll))) {
                                    __Vfunc_emu__DOT__sys__DOT__pic_poll_val__6__rr 
                                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_rr;
                                    vlSelfRef.emu__DOT__sys__DOT____VlemCall_0__pic_poll_val 
                                        = (0x000000ffU 
                                           & Vsim_top__ConstPool__CONST_hf0d4d37b_0
                                           [(0x07ffffffU 
                                             & (IData)(__Vfunc_emu__DOT__sys__DOT__pic_poll_val__6__rr))]);
                                    vlSelfRef.emu__DOT__sys__DOT____VlemCond_1 
                                        = vlSelfRef.emu__DOT__sys__DOT____VlemCall_0__pic_poll_val;
                                } else {
                                    vlSelfRef.emu__DOT__sys__DOT____VlemCond_1 = 0U;
                                }
                                vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                    = vlSelfRef.emu__DOT__sys__DOT____VlemCond_1;
                            }
                        } else if ((0x7101U == (0x00007fffU 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U)))) {
                            if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                if ((2U == (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_mode))) {
                                    vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_mode = 0U;
                                } else if ((0U == (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_mode))) {
                                    vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_mr 
                                        = (0x000000ffU 
                                           & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                                }
                            } else {
                                vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                    = vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_mr;
                            }
                        } else if (((0x1c41U == (0x00001fffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 3U))) 
                                    | (0x1c42U == (0x00001fffU 
                                                   & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                      >> 3U))))) {
                            if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                vlSelfRef.__PVT__emu__DOT__sys__DOT__ack = 0U;
                                vlSelfRef.__Vdly__emu__DOT__sys__DOT__late_rd = 1U;
                            }
                        } else if ((0x710cU == (0x00007fffU 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                    = vlSelfRef.__PVT__emu__DOT__sys__DOT__ppia_rd;
                            }
                        } else if ((0x710dU == (0x00007fffU 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                    = vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd;
                            }
                        } else if ((0x710eU == (0x00007fffU 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U)))) {
                            if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                    = vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic;
                            }
                        } else if ((0x710fU != (0x00007fffU 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U)))) {
                            if ((((((0x7110U == (0x00007fffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U))) 
                                    | (0x7112U == (0x00007fffU 
                                                   & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                      >> 1U)))) 
                                   | (0x711cU == (0x00007fffU 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U)))) 
                                  | (0x711dU == (0x00007fffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))) 
                                 | (0x711fU == (0x00007fffU 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U))))) {
                                if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                    vlSelfRef.__PVT__emu__DOT__sys__DOT__ack = 0U;
                                    vlSelfRef.__Vdly__emu__DOT__sys__DOT__late_rd = 1U;
                                }
                            } else if ((0x7111U == 
                                        (0x00007fffU 
                                         & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                            >> 1U)))) {
                                vlSelfRef.__Vdly__emu__DOT__wbm_dat_i = 0x00ffU;
                            } else if ((0x7113U == 
                                        (0x00007fffU 
                                         & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                            >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                    vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_snum;
                                }
                            } else if ((0x7114U == 
                                        (0x00007fffU 
                                         & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                            >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                    vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                        = (0x000000ffU 
                                           & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_cnum));
                                }
                            } else if ((0x7115U == 
                                        (0x00007fffU 
                                         & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                            >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                    vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                        = (0x000000ffU 
                                           & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_cnum) 
                                              >> 8U));
                                }
                            } else if ((0x7116U == 
                                        (0x00007fffU 
                                         & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                            >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                    vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_sdh;
                                }
                            } else if ((0x7117U == 
                                        (0x00007fffU 
                                         & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                            >> 1U)))) {
                                if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                    vlSelfRef.__Vdly__emu__DOT__wbm_dat_i = 0x0041U;
                                }
                            } else if ((0x7118U != 
                                        (0x00007fffU 
                                         & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                            >> 1U)))) {
                                if ((0x7119U == (0x00007fffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))) {
                                    vlSelfRef.__Vdly__emu__DOT__wbm_dat_i = 1U;
                                } else if ((0x711aU 
                                            == (0x00007fffU 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U)))) {
                                    if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                        vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                            = vlSelfRef.__PVT__emu__DOT__key_matrix
                                            [vlSelfRef.__PVT__emu__DOT__sys__DOT__keypos];
                                        vlSelfRef.__Vdly__emu__DOT__sys__DOT__keypos 
                                            = (7U & 
                                               ((IData)(1U) 
                                                + (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__keypos)));
                                    }
                                } else if ((0x711bU 
                                            == (0x00007fffU 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U)))) {
                                    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                        if ((2U == 
                                             (7U & 
                                              ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                               >> 5U)))) {
                                            vlSelfRef.__Vdly__emu__DOT__sys__DOT__keypos = 0U;
                                        } else if (
                                                   (6U 
                                                    == 
                                                    (7U 
                                                     & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                                        >> 5U)))) {
                                            vlSelfRef.__Vdly__emu__DOT__sys__DOT__keypos = 0U;
                                        }
                                    }
                                } else if ((0x0e25U 
                                            != (0x00000fffU 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 4U)))) {
                                    if ((0x0e28U == 
                                         (0x00000fffU 
                                          & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                             >> 4U)))) {
                                        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                            __VdlyVal__emu__DOT__sys__DOT__HR__v8 
                                                = vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg;
                                            __VdlyDim0__emu__DOT__sys__DOT__HR__v8 
                                                = (7U 
                                                   & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                      >> 1U));
                                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__HR__v8 = 1U;
                                            if ((1U 
                                                 & (~ 
                                                    (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 0x00000010U)))) {
                                                vlSelfRef.__PVT__emu__DOT__sys__DOT__ack = 0U;
                                            }
                                        } else {
                                            vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__HR
                                                [(7U 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U))];
                                        }
                                    } else if ((0x0e29U 
                                                == 
                                                (0x00000fffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 4U)))) {
                                        if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                            vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__UR
                                                [(7U 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U))];
                                        }
                                    } else if ((0x038cU 
                                                == 
                                                (0x000003ffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 6U)))) {
                                        if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)))) {
                                            __Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx 
                                                = (1U 
                                                   | (0x0000007eU 
                                                      & vlSelfRef.__PVT__emu__DOT__wbm_adr));
                                            vlSelfRef.emu__DOT__sys__DOT____VlemCall_2__rtc_byte 
                                                = (0x000000ffU 
                                                   & ((0x00000040U 
                                                       & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                       ? 
                                                      ((0x0eU 
                                                        <= (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                        ? 
                                                       ((0x31U 
                                                         >= 
                                                         (0x0000003fU 
                                                          & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx) 
                                                             - (IData)(0x0eU))))
                                                         ? vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_mem
                                                        [
                                                        (0x0000003fU 
                                                         & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx) 
                                                            - (IData)(0x0eU)))]
                                                         : 0U)
                                                        : 0U)
                                                       : 
                                                      ((0x00000020U 
                                                        & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                        ? 
                                                       ((0x0eU 
                                                         <= (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                         ? 
                                                        ((0x31U 
                                                          >= 
                                                          (0x0000003fU 
                                                           & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx) 
                                                              - (IData)(0x0eU))))
                                                          ? vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_mem
                                                         [
                                                         (0x0000003fU 
                                                          & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx) 
                                                             - (IData)(0x0eU)))]
                                                          : 0U)
                                                         : 0U)
                                                        : 
                                                       ((0x00000010U 
                                                         & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                         ? 
                                                        ((0x0eU 
                                                          <= (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                          ? 
                                                         ((0x31U 
                                                           >= 
                                                           (0x0000003fU 
                                                            & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx) 
                                                               - (IData)(0x0eU))))
                                                           ? vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_mem
                                                          [
                                                          (0x0000003fU 
                                                           & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx) 
                                                              - (IData)(0x0eU)))]
                                                           : 0U)
                                                          : 0U)
                                                         : 
                                                        ((8U 
                                                          & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                           ? 
                                                          ((0x0eU 
                                                            <= (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                            ? 
                                                           ((0x31U 
                                                             >= 
                                                             (0x0000003fU 
                                                              & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx) 
                                                                 - (IData)(0x0eU))))
                                                             ? vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_mem
                                                            [
                                                            (0x0000003fU 
                                                             & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx) 
                                                                - (IData)(0x0eU)))]
                                                             : 0U)
                                                            : 0U)
                                                           : 
                                                          ((2U 
                                                            & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                            ? 
                                                           ((0x0eU 
                                                             <= (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                             ? 
                                                            ((0x31U 
                                                              >= 
                                                              (0x0000003fU 
                                                               & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx) 
                                                                  - (IData)(0x0eU))))
                                                              ? vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_mem
                                                             [
                                                             (0x0000003fU 
                                                              & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx) 
                                                                 - (IData)(0x0eU)))]
                                                              : 0U)
                                                             : 0U)
                                                            : 
                                                           ((1U 
                                                             & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                             ? (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_year)
                                                             : (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_month))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                           ? 
                                                          ((2U 
                                                            & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                            ? 
                                                           ((1U 
                                                             & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                             ? (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_date)
                                                             : 
                                                            ((IData)(1U) 
                                                             + 
                                                             ((vlSelfRef.__PVT__emu__DOT__hps_io__DOT__rtc_r[1U] 
                                                               << 0x00000010U) 
                                                              | (vlSelfRef.__PVT__emu__DOT__hps_io__DOT__rtc_r[1U] 
                                                                 >> 0x00000010U))))
                                                            : 
                                                           ((1U 
                                                             & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                             ? (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_alarm_hour)
                                                             : (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_hour)))
                                                           : 
                                                          ((2U 
                                                            & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                            ? 
                                                           ((1U 
                                                             & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                             ? (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_alarm_min)
                                                             : (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_min))
                                                            : 
                                                           ((1U 
                                                             & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__7__idx))
                                                             ? (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_alarm_sec)
                                                             : (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_sec)))))))));
                                            __Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx 
                                                = (0x0000007eU 
                                                   & vlSelfRef.__PVT__emu__DOT__wbm_adr);
                                            vlSelfRef.emu__DOT__sys__DOT____VlemCall_3__rtc_byte 
                                                = (0x000000ffU 
                                                   & ((0x00000040U 
                                                       & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                       ? 
                                                      ((0x0eU 
                                                        <= (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                        ? 
                                                       ((0x31U 
                                                         >= 
                                                         (0x0000003fU 
                                                          & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx) 
                                                             - (IData)(0x0eU))))
                                                         ? vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_mem
                                                        [
                                                        (0x0000003fU 
                                                         & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx) 
                                                            - (IData)(0x0eU)))]
                                                         : 0U)
                                                        : 0U)
                                                       : 
                                                      ((0x00000020U 
                                                        & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                        ? 
                                                       ((0x0eU 
                                                         <= (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                         ? 
                                                        ((0x31U 
                                                          >= 
                                                          (0x0000003fU 
                                                           & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx) 
                                                              - (IData)(0x0eU))))
                                                          ? vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_mem
                                                         [
                                                         (0x0000003fU 
                                                          & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx) 
                                                             - (IData)(0x0eU)))]
                                                          : 0U)
                                                         : 0U)
                                                        : 
                                                       ((0x00000010U 
                                                         & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                         ? 
                                                        ((0x0eU 
                                                          <= (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                          ? 
                                                         ((0x31U 
                                                           >= 
                                                           (0x0000003fU 
                                                            & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx) 
                                                               - (IData)(0x0eU))))
                                                           ? vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_mem
                                                          [
                                                          (0x0000003fU 
                                                           & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx) 
                                                              - (IData)(0x0eU)))]
                                                           : 0U)
                                                          : 0U)
                                                         : 
                                                        ((8U 
                                                          & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                          ? 
                                                         ((4U 
                                                           & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                           ? 
                                                          ((0x0eU 
                                                            <= (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                            ? 
                                                           ((0x31U 
                                                             >= 
                                                             (0x0000003fU 
                                                              & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx) 
                                                                 - (IData)(0x0eU))))
                                                             ? vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_mem
                                                            [
                                                            (0x0000003fU 
                                                             & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx) 
                                                                - (IData)(0x0eU)))]
                                                             : 0U)
                                                            : 0U)
                                                           : 
                                                          ((2U 
                                                            & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                            ? 
                                                           ((0x0eU 
                                                             <= (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                             ? 
                                                            ((0x31U 
                                                              >= 
                                                              (0x0000003fU 
                                                               & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx) 
                                                                  - (IData)(0x0eU))))
                                                              ? vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_mem
                                                             [
                                                             (0x0000003fU 
                                                              & ((IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx) 
                                                                 - (IData)(0x0eU)))]
                                                              : 0U)
                                                             : 0U)
                                                            : 
                                                           ((1U 
                                                             & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                             ? (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_year)
                                                             : (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_month))))
                                                          : 
                                                         ((4U 
                                                           & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                           ? 
                                                          ((2U 
                                                            & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                            ? 
                                                           ((1U 
                                                             & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                             ? (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_date)
                                                             : 
                                                            ((IData)(1U) 
                                                             + 
                                                             ((vlSelfRef.__PVT__emu__DOT__hps_io__DOT__rtc_r[1U] 
                                                               << 0x00000010U) 
                                                              | (vlSelfRef.__PVT__emu__DOT__hps_io__DOT__rtc_r[1U] 
                                                                 >> 0x00000010U))))
                                                            : 
                                                           ((1U 
                                                             & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                             ? (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_alarm_hour)
                                                             : (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_hour)))
                                                           : 
                                                          ((2U 
                                                            & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                            ? 
                                                           ((1U 
                                                             & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                             ? (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_alarm_min)
                                                             : (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_min))
                                                            : 
                                                           ((1U 
                                                             & (IData)(__Vfunc_emu__DOT__sys__DOT__rtc_byte__8__idx))
                                                             ? (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_alarm_sec)
                                                             : (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_sec)))))))));
                                            vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                                = (
                                                   ((IData)(vlSelfRef.emu__DOT__sys__DOT____VlemCall_2__rtc_byte) 
                                                    << 8U) 
                                                   | (IData)(vlSelfRef.emu__DOT__sys__DOT____VlemCall_3__rtc_byte));
                                        }
                                    } else if ((0x71U 
                                                == 
                                                (0x0000007fU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 9U)))) {
                                        vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                                            = (0x000000ffU 
                                               & vlSelfRef.__PVT__emu__DOT__wbm_adr);
                                    } else {
                                        vlSelfRef.__PVT__emu__DOT__sys__DOT__ack = 0U;
                                    }
                                }
                            }
                        }
                    } else if (((~ (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                    >> 0x00000010U)) 
                                & (0xffc0U > (0x0000ffffU 
                                              & vlSelfRef.__PVT__emu__DOT__wbm_adr)))) {
                        if ((1U & (~ ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__cyc_rd_held) 
                                      & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we))))) {
                            if ((1U & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd))) {
                                __VdlyVal__emu__DOT__sys__DOT__HR__v9 
                                    = (0x0000ffffU 
                                       & vlSelfRef.__PVT__emu__DOT__wbm_adr);
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__HR__v9 = 1U;
                            } else {
                                __VdlyVal__emu__DOT__sys__DOT__HR__v10 
                                    = (0x0000ffffU 
                                       & vlSelfRef.__PVT__emu__DOT__wbm_adr);
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__HR__v10 = 1U;
                            }
                        }
                        vlSelfRef.__PVT__emu__DOT__cpu_ram_req = 1U;
                        vlSelfRef.__Vdly__emu__DOT__sys__DOT__ram_wait = 1U;
                    } else if ((0x00010000U & vlSelfRef.__PVT__emu__DOT__wbm_adr)) {
                        vlSelfRef.__PVT__emu__DOT__cpu_ram_req = 1U;
                        vlSelfRef.__Vdly__emu__DOT__sys__DOT__ram_wait = 1U;
                    }
                } else if ((1U & (~ ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__memreg) 
                                     >> 3U)))) {
                    if ((0U == (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__bankbits))) {
                        vlSelfRef.__Vdly__emu__DOT__wbm_dat_i = 0U;
                        vlSelfRef.__PVT__emu__DOT__sys__DOT__ack = 1U;
                    } else {
                        vlSelfRef.__PVT__emu__DOT__cpu_ram_req = 1U;
                        vlSelfRef.__Vdly__emu__DOT__sys__DOT__ram_wait = 1U;
                    }
                }
            } else {
                if ((0U != (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rom_wait))) {
                    vlSelfRef.__Vdly__emu__DOT__sys__DOT__rom_wait 
                        = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rom_wait)));
                    if ((1U == (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rom_wait))) {
                        vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                            = vlSelfRef.__PVT__emu__DOT__rom_dout;
                        vlSelfRef.__PVT__emu__DOT__sys__DOT__ack = 1U;
                        vlSelfRef.__Vdly__emu__DOT__sys__DOT__rom_wait = 0U;
                    }
                }
                if (((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ram_wait) 
                     & (IData)(vlSelfRef.__PVT__emu__DOT__cpu_ram_ack))) {
                    vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                        = vlSelfRef.__PVT__emu__DOT__cpu_ram_dout;
                    vlSelfRef.__PVT__emu__DOT__sys__DOT__ack = 1U;
                    vlSelfRef.__PVT__emu__DOT__cpu_ram_req = 0U;
                    vlSelfRef.__Vdly__emu__DOT__sys__DOT__ram_wait = 0U;
                }
                if (vlSelfRef.__PVT__emu__DOT__sys__DOT__late_rd) {
                    vlSelfRef.__Vdly__emu__DOT__wbm_dat_i 
                        = ((0x1c41U == (0x00001fffU 
                                        & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                           >> 3U)))
                            ? (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__pit_snd_dout)
                            : ((0x1c42U == (0x00001fffU 
                                            & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                               >> 3U)))
                                ? (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__pit_snl_dout)
                                : (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__dout_r)));
                    vlSelfRef.__PVT__emu__DOT__sys__DOT__ack = 1U;
                    vlSelfRef.__Vdly__emu__DOT__sys__DOT__late_rd = 0U;
                }
            }
        } else {
            vlSelfRef.__PVT__emu__DOT__sys__DOT__ack = 0U;
            vlSelfRef.__Vdly__emu__DOT__sys__DOT__ram_wait = 0U;
            vlSelfRef.__Vdly__emu__DOT__sys__DOT__rom_wait = 0U;
            vlSelfRef.__Vdly__emu__DOT__sys__DOT__late_rd = 0U;
        }
        vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd 
            = ((0xfbU & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd)) 
               | ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ioint) 
                  << 2U));
        if (((vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[0U] 
              != vlSelfRef.__PVT__emu__DOT__key_matrix[0U]) 
             | ((vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[1U] 
                 != vlSelfRef.__PVT__emu__DOT__key_matrix[1U]) 
                | ((vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[2U] 
                    != vlSelfRef.__PVT__emu__DOT__key_matrix[2U]) 
                   | ((vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[3U] 
                       != vlSelfRef.__PVT__emu__DOT__key_matrix[3U]) 
                      | ((vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[4U] 
                          != vlSelfRef.__PVT__emu__DOT__key_matrix[4U]) 
                         | ((vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[5U] 
                             != vlSelfRef.__PVT__emu__DOT__key_matrix[5U]) 
                            | ((vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[6U] 
                                != vlSelfRef.__PVT__emu__DOT__key_matrix[6U]) 
                               | (vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[7U] 
                                  != vlSelfRef.__PVT__emu__DOT__key_matrix[7U]))))))))) {
            vlSelfRef.__PVT__emu__DOT__sys__DOT__keyint = 1U;
        }
        if (((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__mouse_tgl) 
             != (1U & (vlSymsp->TOP.ps2_mouse >> 0x18U)))) {
            vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousedx 
                = (0x000000ffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__mousedx) 
                                  - ((0x00000010U & vlSymsp->TOP.ps2_mouse) 
                                     | (0x0000000fU 
                                        & (vlSymsp->TOP.ps2_mouse 
                                           >> 8U)))));
            vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousedy 
                = (0x000000ffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__mousedy) 
                                  + ((0x00000010U & 
                                      (vlSymsp->TOP.ps2_mouse 
                                       >> 1U)) | (0x0000000fU 
                                                  & (vlSymsp->TOP.ps2_mouse 
                                                     >> 0x10U)))));
            vlSelfRef.__PVT__emu__DOT__sys__DOT__ppia_rd 
                = ((0x9fU & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppia_rd)) 
                   | (((2U & ((~ (vlSymsp->TOP.ps2_mouse 
                                  >> 1U)) << 1U)) | 
                       (1U & (~ vlSymsp->TOP.ps2_mouse))) 
                      << 5U));
        }
        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb) {
            if (vlSelfRef.__PVT__emu__DOT__sys__DOT__stb_rise) {
                vlSelfRef.__PVT__emu__DOT__sys__DOT__cyc_rd_held 
                    = (1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)));
                if ((1U & (~ ((vlSelfRef.__PVT__emu__DOT__wbm_adr 
                               >> 0x00000010U) & (0x4000U 
                                                  > 
                                                  (0x0000ffffU 
                                                   & vlSelfRef.__PVT__emu__DOT__wbm_adr)))))) {
                    if ((0xe000U <= (0x0000ffffU & vlSelfRef.__PVT__emu__DOT__wbm_adr))) {
                        if ((0xf800U > (0x0000ffffU 
                                        & vlSelfRef.__PVT__emu__DOT__wbm_adr))) {
                            if ((0x7100U != (0x00007fffU 
                                             & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                >> 1U)))) {
                                if ((0x7101U != (0x00007fffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))) {
                                    if ((1U & (~ ((0x1c41U 
                                                   == 
                                                   (0x00001fffU 
                                                    & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                       >> 3U))) 
                                                  | (0x1c42U 
                                                     == 
                                                     (0x00001fffU 
                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                         >> 3U))))))) {
                                        if ((0x710cU 
                                             != (0x00007fffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))) {
                                            if ((0x710dU 
                                                 != 
                                                 (0x00007fffU 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U)))) {
                                                if (
                                                    (0x710eU 
                                                     != 
                                                     (0x00007fffU 
                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                         >> 1U)))) {
                                                    if (
                                                        (0x710fU 
                                                         != 
                                                         (0x00007fffU 
                                                          & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (((((0x7110U 
                                                                     == 
                                                                     (0x00007fffU 
                                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                         >> 1U))) 
                                                                    | (0x7112U 
                                                                       == 
                                                                       (0x00007fffU 
                                                                        & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                           >> 1U)))) 
                                                                   | (0x711cU 
                                                                      == 
                                                                      (0x00007fffU 
                                                                       & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                          >> 1U)))) 
                                                                  | (0x711dU 
                                                                     == 
                                                                     (0x00007fffU 
                                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                         >> 1U)))) 
                                                                 | (0x711fU 
                                                                    == 
                                                                    (0x00007fffU 
                                                                     & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                        >> 1U))))))) {
                                                            if (
                                                                (0x7111U 
                                                                 != 
                                                                 (0x00007fffU 
                                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (0x7113U 
                                                                     == 
                                                                     (0x00007fffU 
                                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                         >> 1U)))) {
                                                                    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                                                        vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_snum 
                                                                            = 
                                                                            (0x000000ffU 
                                                                             & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                                                                    }
                                                                }
                                                                if (
                                                                    (0x7113U 
                                                                     != 
                                                                     (0x00007fffU 
                                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                         >> 1U)))) {
                                                                    if (
                                                                        (0x7114U 
                                                                         == 
                                                                         (0x00007fffU 
                                                                          & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                             >> 1U)))) {
                                                                        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                                                            vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_cnum 
                                                                                = 
                                                                                ((0xff00U 
                                                                                & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_cnum)) 
                                                                                | (0x000000ffU 
                                                                                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg)));
                                                                        }
                                                                    } else if (
                                                                               (0x7115U 
                                                                                == 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                                                            vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_cnum 
                                                                                = 
                                                                                ((0x00ffU 
                                                                                & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_cnum)) 
                                                                                | (0x0000ff00U 
                                                                                & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                                                                << 8U)));
                                                                        }
                                                                    }
                                                                    if (
                                                                        (0x7114U 
                                                                         != 
                                                                         (0x00007fffU 
                                                                          & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                             >> 1U)))) {
                                                                        if (
                                                                            (0x7115U 
                                                                             != 
                                                                             (0x00007fffU 
                                                                              & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                            if (
                                                                                (0x7116U 
                                                                                == 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                                                                vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_sdh 
                                                                                = vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg;
                                                                                }
                                                                            }
                                                                            if (
                                                                                (0x7116U 
                                                                                != 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (
                                                                                (0x7117U 
                                                                                == 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                                                                if (
                                                                                (0x0010U 
                                                                                == (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg))) {
                                                                                vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_int = 1U;
                                                                                }
                                                                                } else {
                                                                                vlSelfRef.__PVT__emu__DOT__sys__DOT__hd_int = 0U;
                                                                                }
                                                                                }
                                                                                if (
                                                                                (0x7117U 
                                                                                != 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (
                                                                                (0x7118U 
                                                                                != 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (
                                                                                (0x7119U 
                                                                                != 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (
                                                                                (0x711aU 
                                                                                != 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (
                                                                                (0x711bU 
                                                                                == 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                                                                if (
                                                                                (2U 
                                                                                != 
                                                                                (7U 
                                                                                & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                                                                >> 5U)))) {
                                                                                if (
                                                                                (6U 
                                                                                == 
                                                                                (7U 
                                                                                & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                                                                >> 5U)))) {
                                                                                vlSelfRef.__PVT__emu__DOT__sys__DOT__keyint = 0U;
                                                                                } else if (
                                                                                (7U 
                                                                                == 
                                                                                (7U 
                                                                                & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                                                                >> 5U)))) {
                                                                                vlSelfRef.__PVT__emu__DOT__sys__DOT__keyint = 0U;
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                                if (
                                                    (0x710eU 
                                                     == 
                                                     (0x00007fffU 
                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                         >> 1U)))) {
                                                    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                                        vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd 
                                                            = 
                                                            ((0xf7U 
                                                              & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd)) 
                                                             | (8U 
                                                                & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                                                   << 1U)));
                                                    }
                                                } else if (
                                                           (0x710fU 
                                                            != 
                                                            (0x00007fffU 
                                                             & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                >> 1U)))) {
                                                    if (
                                                        (1U 
                                                         & (~ 
                                                            (((((0x7110U 
                                                                 == 
                                                                 (0x00007fffU 
                                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                     >> 1U))) 
                                                                | (0x7112U 
                                                                   == 
                                                                   (0x00007fffU 
                                                                    & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                       >> 1U)))) 
                                                               | (0x711cU 
                                                                  == 
                                                                  (0x00007fffU 
                                                                   & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                      >> 1U)))) 
                                                              | (0x711dU 
                                                                 == 
                                                                 (0x00007fffU 
                                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                     >> 1U)))) 
                                                             | (0x711fU 
                                                                == 
                                                                (0x00007fffU 
                                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                    >> 1U))))))) {
                                                        if (
                                                            (0x7111U 
                                                             != 
                                                             (0x00007fffU 
                                                              & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                 >> 1U)))) {
                                                            if (
                                                                (0x7113U 
                                                                 != 
                                                                 (0x00007fffU 
                                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (0x7114U 
                                                                     != 
                                                                     (0x00007fffU 
                                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                         >> 1U)))) {
                                                                    if (
                                                                        (0x7115U 
                                                                         != 
                                                                         (0x00007fffU 
                                                                          & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                             >> 1U)))) {
                                                                        if (
                                                                            (0x7116U 
                                                                             != 
                                                                             (0x00007fffU 
                                                                              & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                            if (
                                                                                (0x7117U 
                                                                                != 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (
                                                                                (0x7118U 
                                                                                != 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (
                                                                                (0x7119U 
                                                                                != 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (
                                                                                (0x711aU 
                                                                                != 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (
                                                                                (0x711bU 
                                                                                != 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (
                                                                                (0x0e25U 
                                                                                != 
                                                                                (0x00000fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 4U)))) {
                                                                                if (
                                                                                (0x0e28U 
                                                                                == 
                                                                                (0x00000fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 4U)))) {
                                                                                if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                                                                if ((IData)(
                                                                                (0x00010000U 
                                                                                == 
                                                                                (0x0001000cU 
                                                                                & vlSelfRef.__PVT__emu__DOT__wbm_adr)))) {
                                                                                vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd 
                                                                                = 
                                                                                (3U 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd));
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        if ((0x710cU 
                                             == (0x00007fffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))) {
                                            if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                                vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic 
                                                    = 
                                                    (0x0fU 
                                                     & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic));
                                                if (
                                                    (0x00000080U 
                                                     & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg))) {
                                                    if (
                                                        (2U 
                                                         & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__mousest))) {
                                                        if (
                                                            (1U 
                                                             & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__mousest))) {
                                                            vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic 
                                                                = 
                                                                ((0x0fU 
                                                                  & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic)) 
                                                                 | (0x000000f0U 
                                                                    & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__mousedy) 
                                                                       << 4U)));
                                                            vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousest = 0U;
                                                            vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousedy = 0U;
                                                        } else {
                                                            vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic 
                                                                = 
                                                                ((0x0fU 
                                                                  & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic)) 
                                                                 | (0x000000f0U 
                                                                    & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__mousedy)));
                                                            vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousest = 3U;
                                                        }
                                                    } else if (
                                                               (1U 
                                                                & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__mousest))) {
                                                        vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic 
                                                            = 
                                                            ((0x0fU 
                                                              & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic)) 
                                                             | (0x000000f0U 
                                                                & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__mousedx) 
                                                                   << 4U)));
                                                        vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousest = 2U;
                                                        vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousedx = 0U;
                                                    } else {
                                                        vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic 
                                                            = 
                                                            ((0x0fU 
                                                              & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic)) 
                                                             | (0x000000f0U 
                                                                & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__mousedx)));
                                                        vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousest = 1U;
                                                    }
                                                } else {
                                                    vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousest = 0U;
                                                }
                                            }
                                        } else if (
                                                   (0x710dU 
                                                    != 
                                                    (0x00007fffU 
                                                     & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                        >> 1U)))) {
                                            if ((0x710eU 
                                                 == 
                                                 (0x00007fffU 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U)))) {
                                                if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                                    vlSelfRef.__PVT__emu__DOT__sys__DOT__ppic 
                                                        = 
                                                        (0x000000ffU 
                                                         & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else if (((~ (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                        >> 0x00000010U)) 
                                    & (0xffc0U > (0x0000ffffU 
                                                  & vlSelfRef.__PVT__emu__DOT__wbm_adr)))) {
                            vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd 
                                = (0xfeU & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd));
                            if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd 
                                    = (0xfdU & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd));
                            }
                        }
                    }
                }
            }
        } else if ((1U & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_cyc)))) {
            vlSelfRef.__PVT__emu__DOT__sys__DOT__cyc_rd_held = 0U;
        }
    }
    vlSelfRef.__PVT__emu__DOT__dbg_stb_cnt = vlSelfRef.__Vdly__emu__DOT__dbg_stb_cnt;
    vlSelfRef.__PVT__emu__DOT__sys__DOT__ram_wait = vlSelfRef.__Vdly__emu__DOT__sys__DOT__ram_wait;
    vlSelfRef.__PVT__emu__DOT__sys__DOT__rom_wait = vlSelfRef.__Vdly__emu__DOT__sys__DOT__rom_wait;
    vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_mode = vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_mode;
    vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_poll = vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_poll;
    vlSelfRef.__PVT__emu__DOT__sys__DOT__keypos = vlSelfRef.__Vdly__emu__DOT__sys__DOT__keypos;
    vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_div = vlSelfRef.__Vdly__emu__DOT__sys__DOT__rtc_div;
    vlSelfRef.__PVT__emu__DOT__frame_s = vlSelfRef.__Vdly__emu__DOT__frame_s;
    vlSelfRef.__PVT__emu__DOT__sys__DOT__late_rd = vlSelfRef.__Vdly__emu__DOT__sys__DOT__late_rd;
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__rtc_mem__v0) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_mem[vlSelfRef.__VdlyDim0__emu__DOT__sys__DOT__rtc_mem__v0] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__rtc_mem__v0;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__rtc_mem__v1) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__rtc_mem[vlSelfRef.__VdlyDim0__emu__DOT__sys__DOT__rtc_mem__v1] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__rtc_mem__v1;
    }
    vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_mr = vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_mr;
    vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_rr = vlSelfRef.__Vdly__emu__DOT__sys__DOT__pic_rr;
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__UR__v0) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__UR[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__UR[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__UR[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__UR[3U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__UR[4U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__UR[5U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__UR[6U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__UR[7U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__UR__v8) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__UR[vlSelfRef.__VdlyDim0__emu__DOT__sys__DOT__UR__v8] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__UR__v8;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__HR__v0) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__HR[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__HR[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__HR[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__HR[3U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__HR[4U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__HR[5U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__HR[6U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__HR[7U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__HR__v8) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__HR[__VdlyDim0__emu__DOT__sys__DOT__HR__v8] 
            = __VdlyVal__emu__DOT__sys__DOT__HR__v8;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__HR__v9) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__HR[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__HR__v9;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__HR__v10) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__HR[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__HR__v10;
    }
    vlSelfRef.__PVT__emu__DOT__rom_dout = vlSelfRef.__PVT__emu__DOT__rom__DOT__rom
        [(0x00001fffU & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                         >> 1U))];
    __Vdly__emu__DOT__fdc__DOT__done_s = ((2U & ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__done_s) 
                                                 << 1U)) 
                                          | (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_done_sd));
    if ((IData)((((IData)(vlSelfRef.__PVT__emu__DOT__cpu_reset_s) 
                  >> 1U) | (IData)(vlSelfRef.__PVT__emu__DOT__fdc_reset)))) {
        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 1U;
        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__cmdlen = 0U;
        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__reslen = 0U;
        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__respos = 0U;
        vlSelfRef.__PVT__emu__DOT__fdc_int = 0U;
        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_run = 0U;
        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_req = 0U;
        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__nbuf = 0U;
        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__pos = 0U;
        if ((2U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu_reset_s))) {
            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__scnt = 0U;
        }
    } else {
        if (vlSelfRef.__PVT__emu__DOT__fdc_sel) {
            if ((8U & vlSelfRef.__PVT__emu__DOT__wbm_adr)) {
                if ((4U & vlSelfRef.__PVT__emu__DOT__wbm_adr)) {
                    if ((2U & vlSelfRef.__PVT__emu__DOT__wbm_adr)) {
                        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__nbuf 
                                = (3U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__pos = 0U;
                            if ((0x00000010U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg))) {
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 1U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__cmdlen = 0U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__reslen = 0U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__respos = 0U;
                                vlSelfRef.__PVT__emu__DOT__fdc_int = 0U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_run = 0U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_req = 0U;
                            }
                        }
                    } else {
                        vlSelfRef.__PVT__emu__DOT__fdc__DOT__dout_r = 0U;
                    }
                } else if ((2U & vlSelfRef.__PVT__emu__DOT__wbm_adr)) {
                    vlSelfRef.__PVT__emu__DOT__fdc__DOT__dout_r = 0xffU;
                    if ((0x00000010U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc_params))) {
                        vlSelfRef.__PVT__emu__DOT__fdc__DOT__dout_r = 0U;
                    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                        if ((1U == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__phase))) {
                            vlSelfRef.__PVT__emu__DOT__fdc_int = 0U;
                            if ((8U >= (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmdlen))) {
                                __VdlyVal__emu__DOT__fdc__DOT__cmd__v0 
                                    = (0x000000ffU 
                                       & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                                __VdlyDim0__emu__DOT__fdc__DOT__cmd__v0 
                                    = vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmdlen;
                                vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__cmd__v0 = 1U;
                            }
                            if (((3U != (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)) 
                                 & ((4U != (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)) 
                                    & ((7U != (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)) 
                                       & ((8U != (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)) 
                                          & ((0x0fU 
                                              != (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)) 
                                             & ((0x00000010U 
                                                 & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                 ? 
                                                ((8U 
                                                  & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                  ? (IData)(
                                                            (1U 
                                                             != 
                                                             (3U 
                                                              & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))))
                                                  : (IData)(
                                                            (1U 
                                                             != 
                                                             (7U 
                                                              & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)))))
                                                 : 
                                                ((8U 
                                                  & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                   ? 
                                                  ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first) 
                                                   >> 1U)
                                                   : (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_100))
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                   ? (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_100)
                                                   : (IData)(
                                                             (2U 
                                                              != 
                                                              (3U 
                                                               & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))))))))))))) {
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 3U;
                                vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v0 = 1U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__reslen = 1U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__respos = 0U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__cmdlen = 0U;
                            } else if ((8U == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))) {
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 3U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__cmdlen = 0U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__respos = 0U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__reslen = 2U;
                                __VdlyVal__emu__DOT__fdc__DOT__res__v1 
                                    = ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__attached)
                                        ? 0x20U : 0x60U);
                                vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v1 = 1U;
                                vlSelfRef.__PVT__emu__DOT__fdc_int = 0U;
                                vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v2 = 1U;
                            } else if (((3U == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                         ? (3U == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__newlen))
                                         : ((4U == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                             ? (2U 
                                                == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__newlen))
                                             : ((7U 
                                                 == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                 ? 
                                                (2U 
                                                 == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__newlen))
                                                 : 
                                                ((8U 
                                                  == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)) 
                                                 | ((0x0fU 
                                                     == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                     ? 
                                                    (3U 
                                                     == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__newlen))
                                                     : 
                                                    ((0x00000010U 
                                                      & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                      ? 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                       ? (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_104)
                                                       : 
                                                      ((~ 
                                                        ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first) 
                                                         >> 2U)) 
                                                       & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_104)))
                                                      : 
                                                     ((8U 
                                                       & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                       ? 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                        ? 
                                                       ((~ 
                                                         ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first) 
                                                          >> 1U)) 
                                                        & ((1U 
                                                            & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                            ? 
                                                           (6U 
                                                            == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__newlen))
                                                            : 
                                                           (9U 
                                                            == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__newlen))))
                                                        : 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                         ? 
                                                        ((~ (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)) 
                                                         & (2U 
                                                            == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__newlen)))
                                                         : (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_31)))
                                                       : 
                                                      ((4U 
                                                        & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                        ? 
                                                       ((2U 
                                                         & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                         ? (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_105)
                                                         : (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_31))
                                                        : 
                                                       (((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first) 
                                                         >> 1U) 
                                                        & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_105))))))))))) {
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__cmdlen = 0U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__reslen = 0U;
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__respos = 0U;
                                if ((0x00000010U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))) {
                                    vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 2U;
                                } else if ((8U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))) {
                                    if ((4U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))) {
                                        if ((2U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))) {
                                            if ((1U 
                                                 & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))) {
                                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 1U;
                                                vlSelfRef.__PVT__emu__DOT__fdc_int = 1U;
                                            } else {
                                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 2U;
                                            }
                                        } else {
                                            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 2U;
                                        }
                                    } else {
                                        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 2U;
                                    }
                                } else if ((4U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))) {
                                    if ((2U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))) {
                                        if ((1U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))) {
                                            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 1U;
                                            vlSelfRef.__PVT__emu__DOT__fdc_int = 1U;
                                        } else {
                                            __VdlyVal__emu__DOT__fdc__DOT__res__v3 
                                                = (0x20U 
                                                   | (3U 
                                                      & vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[1U]));
                                            vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v3 = 1U;
                                            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__reslen = 7U;
                                            vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v4 = 1U;
                                            __VdlyVal__emu__DOT__fdc__DOT__res__v6 
                                                = vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[2U];
                                            __VdlyVal__emu__DOT__fdc__DOT__res__v7 
                                                = vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[3U];
                                            __VdlyVal__emu__DOT__fdc__DOT__res__v8 
                                                = vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[4U];
                                            __VdlyVal__emu__DOT__fdc__DOT__res__v9 
                                                = vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[5U];
                                            if ((1U 
                                                 & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__attached)) 
                                                    | (0x52U 
                                                       <= vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[2U])))) {
                                                __VdlyVal__emu__DOT__fdc__DOT__res__v10 
                                                    = 
                                                    ((6U 
                                                      == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))
                                                      ? 
                                                     (0xc8U 
                                                      | (3U 
                                                         & vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[1U]))
                                                      : 0xc8U);
                                                vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v10 = 1U;
                                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 3U;
                                                vlSelfRef.__PVT__emu__DOT__fdc_int = 1U;
                                            } else {
                                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 2U;
                                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_run = 1U;
                                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_we 
                                                    = 
                                                    (5U 
                                                     == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id));
                                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__sector 
                                                    = 
                                                    (0x0000000fU 
                                                     & (vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[4U] 
                                                        - (IData)(1U)));
                                            }
                                        }
                                    } else if ((1U 
                                                & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))) {
                                        __VdlyVal__emu__DOT__fdc__DOT__res__v11 
                                            = (0x20U 
                                               | (3U 
                                                  & vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[1U]));
                                        vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v11 = 1U;
                                        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__reslen = 7U;
                                        vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v12 = 1U;
                                        __VdlyVal__emu__DOT__fdc__DOT__res__v14 
                                            = vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[2U];
                                        __VdlyVal__emu__DOT__fdc__DOT__res__v15 
                                            = vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[3U];
                                        __VdlyVal__emu__DOT__fdc__DOT__res__v16 
                                            = vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[4U];
                                        __VdlyVal__emu__DOT__fdc__DOT__res__v17 
                                            = vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[5U];
                                        if ((1U & (
                                                   (~ (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__attached)) 
                                                   | (0x52U 
                                                      <= vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[2U])))) {
                                            __VdlyVal__emu__DOT__fdc__DOT__res__v18 
                                                = (
                                                   (6U 
                                                    == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))
                                                    ? 
                                                   (0xc8U 
                                                    | (3U 
                                                       & vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[1U]))
                                                    : 0xc8U);
                                            vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v18 = 1U;
                                            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 3U;
                                            vlSelfRef.__PVT__emu__DOT__fdc_int = 1U;
                                        } else {
                                            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 2U;
                                            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_run = 1U;
                                            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_we 
                                                = (5U 
                                                   == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id));
                                            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__sector 
                                                = (0x0000000fU 
                                                   & (vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[4U] 
                                                      - (IData)(1U)));
                                        }
                                    } else {
                                        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 2U;
                                    }
                                } else {
                                    vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase 
                                        = ((2U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))
                                            ? ((1U 
                                                & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id))
                                                ? 1U
                                                : 2U)
                                            : 2U);
                                }
                            } else {
                                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__cmdlen 
                                    = (0x0000000fU 
                                       & ((IData)(1U) 
                                          + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmdlen)));
                            }
                        }
                    } else if ((3U == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__phase))) {
                        vlSelfRef.__PVT__emu__DOT__fdc_int = 0U;
                        if (((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__respos) 
                             < (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__reslen))) {
                            vlSelfRef.__PVT__emu__DOT__fdc__DOT__dout_r 
                                = ((6U >= (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__respos))
                                    ? vlSelfRef.__PVT__emu__DOT__fdc__DOT__res
                                   [vlSelfRef.__PVT__emu__DOT__fdc__DOT__respos]
                                    : 0U);
                            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__respos 
                                = (7U & ((IData)(1U) 
                                         + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__respos)));
                        }
                        if (((7U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__respos))) 
                             >= (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__reslen))) {
                            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 1U;
                        }
                    }
                } else {
                    vlSelfRef.__PVT__emu__DOT__fdc__DOT__dout_r 
                        = vlSelfRef.__PVT__emu__DOT__fdc__DOT__msr;
                }
            } else if ((4U & vlSelfRef.__PVT__emu__DOT__wbm_adr)) {
                if ((2U & vlSelfRef.__PVT__emu__DOT__wbm_adr)) {
                    vlSelfRef.__PVT__emu__DOT__fdc__DOT__dout_r = 0U;
                } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                    vlSelfRef.__Vdly__emu__DOT__fdc__DOT__scnt 
                        = (0x000000ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                } else {
                    vlSelfRef.__PVT__emu__DOT__fdc__DOT__dout_r 
                        = vlSelfRef.__PVT__emu__DOT__fdc__DOT__scnt;
                }
            } else if ((2U & vlSelfRef.__PVT__emu__DOT__wbm_adr)) {
                vlSelfRef.__PVT__emu__DOT__fdc__DOT__dout_r = 0U;
            } else {
                if ((1U & ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__dir)
                            ? (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)
                            : (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we))))) {
                    if ((0x01ffU == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__pos))) {
                        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__nbuf 
                            = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__nbuf)));
                        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__pos = 0U;
                    } else {
                        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__pos 
                            = (0x000001ffU & ((IData)(1U) 
                                              + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__pos)));
                    }
                }
                vlSelfRef.__PVT__emu__DOT__fdc__DOT__dout_r 
                    = ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__dir)
                        ? 0U : ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__a_q_sel_d)
                                 ? (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__buf_hi__DOT__q_a)
                                 : (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__buf_lo__DOT__q_a)));
            }
        }
        if ((((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_run) 
              & (~ (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_req))) 
             & (~ ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__done_s) 
                   >> 1U)))) {
            if (vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_we) {
                if ((0U == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__scnt))) {
                    vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_run = 0U;
                    vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 3U;
                    vlSelfRef.__PVT__emu__DOT__fdc_int = 1U;
                } else {
                    vlSelfRef.__Vdly__emu__DOT__fdc__DOT__scnt 
                        = (0x000000ffU & ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__scnt) 
                                          - (IData)(1U)));
                    vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_buf 
                        = (3U & ((IData)(3U) - ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__scnt) 
                                                - (IData)(1U))));
                    vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_lba 
                        = ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__lba_calc) 
                           + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__sector));
                    vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_req 
                        = (1U & (~ ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__readonly) 
                                    >> (1U & ((IData)(vlSelfRef.__PVT__emu__DOT__fdc_params) 
                                              >> 2U)))));
                    if ((1U & ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__readonly) 
                               >> (1U & ((IData)(vlSelfRef.__PVT__emu__DOT__fdc_params) 
                                         >> 2U))))) {
                        vlSelfRef.__Vdly__emu__DOT__fdc__DOT__sector 
                            = ((9U == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__sector))
                                ? 0U : (0x0000000fU 
                                        & ((IData)(1U) 
                                           + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__sector))));
                    }
                }
            } else {
                vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_buf 
                    = vlSelfRef.__PVT__emu__DOT__fdc__DOT__nbuf;
                vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_lba 
                    = ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__lba_calc) 
                       + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__sector));
                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_req = 1U;
            }
        }
        if (((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_req) 
             & ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__done_s) 
                >> 1U))) {
            vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_req = 0U;
            if (vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_we) {
                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__sector 
                    = ((9U == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__sector))
                        ? 0U : (0x0000000fU & ((IData)(1U) 
                                               + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__sector))));
            } else if ((3U == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__nbuf))) {
                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__nbuf = 0U;
                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__pos = 0U;
                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_run = 0U;
                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase = 3U;
                vlSelfRef.__PVT__emu__DOT__fdc_int = 1U;
            } else {
                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__nbuf 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__nbuf)));
                vlSelfRef.__Vdly__emu__DOT__fdc__DOT__sector 
                    = ((9U == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__sector))
                        ? 0U : (0x0000000fU & ((IData)(1U) 
                                               + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__sector))));
            }
        }
    }
    if ((2U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu_reset_s))) {
        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v0 = 1U;
        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v0 = 1U;
        vlSelfRef.__PVT__emu__DOT__fdc_params = 0U;
    } else {
        if (vlSelfRef.emu__DOT__sys__DOT____Vcellinp__snd__wr) {
            if ((3U == (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                              >> 1U)))) {
                if ((3U != (3U & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                  >> 6U)))) {
                    if ((2U >= (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel))) {
                        __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__writehi__v3 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel;
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__writehi__v3 = 1U;
                        __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__readhi__v3 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel;
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__readhi__v3 = 1U;
                    }
                    if ((0U == (3U & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                      >> 4U)))) {
                        if ((2U >= (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel))) {
                            __VdlyVal__emu__DOT__sys__DOT__snd__DOT__latch__v3 
                                = ((2U >= (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel))
                                    ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value
                                   [vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel]
                                    : 0U);
                            __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__latch__v3 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel;
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__latch__v3 = 1U;
                        }
                    } else {
                        __Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__13__ctl 
                            = (0x0000003fU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                        vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_0__mode 
                            = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__13__ctl) 
                                                   >> 1U)))
                                      ? (3U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__13__ctl) 
                                               >> 1U))
                                      : ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__13__ctl) 
                                         >> 1U)));
                        if ((2U >= (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel))) {
                            __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v3 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel;
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v3 = 1U;
                            __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v3 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel;
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__loaded__v3 = 1U;
                            __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v3 
                                = (0U != (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_0__mode));
                            __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__output_r__v3 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel;
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v3 = 1U;
                        }
                    }
                }
            } else {
                __Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__14__ctl 
                    = ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U))) ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control
                       [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                               >> 1U))] : 0U);
                vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_1__mode 
                    = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__14__ctl) 
                                           >> 1U)))
                              ? (3U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__14__ctl) 
                                       >> 1U)) : ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__14__ctl) 
                                                  >> 1U)));
                if ((1U == (3U & (((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                 >> 1U)))
                                    ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control
                                   [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                           >> 1U))]
                                    : 0U) >> 4U)))) {
                    if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                      >> 1U)))) {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v3 
                            = (0x000000ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                        __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v3 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__count__v3 = 1U;
                        __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v4 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__loaded__v4 = 1U;
                    }
                } else if ((2U == (3U & (((2U >= (3U 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U)))
                                           ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control
                                          [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                  >> 1U))]
                                           : 0U) >> 4U)))) {
                    if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                      >> 1U)))) {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v4 
                            = (0x000000ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                        __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v4 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__count__v4 = 1U;
                        __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v5 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__loaded__v5 = 1U;
                    }
                } else if ((3U == (3U & (((2U >= (3U 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U)))
                                           ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control
                                          [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                  >> 1U))]
                                           : 0U) >> 4U)))) {
                    if (((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                       >> 1U))) && vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__writehi
                         [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                 >> 1U))])) {
                        if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                          >> 1U)))) {
                            __VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v5 
                                = (0x000000ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                            __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v5 
                                = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                         >> 1U));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__count__v5 = 1U;
                            __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v6 
                                = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                         >> 1U));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__loaded__v6 = 1U;
                        }
                    } else if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                             >> 1U)))) {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v6 
                            = (0x000000ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                        __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v6 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__count__v6 = 1U;
                    }
                    if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                      >> 1U)))) {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__writehi__v4 
                            = (1U & (~ ((2U >= (3U 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U))) 
                                        && vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__writehi
                                        [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                >> 1U))])));
                        __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__writehi__v4 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__writehi__v4 = 1U;
                    }
                }
                if ((4U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_1__mode))) {
                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_1__mode) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_1__mode)))) {
                            if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                              >> 1U)))) {
                                __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v4 
                                    = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                             >> 1U));
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v4 = 1U;
                            }
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_1__mode))) {
                    if ((0U == ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                              >> 1U)))
                                 ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase
                                [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                        >> 1U))] : 0U))) {
                        if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                          >> 1U)))) {
                            __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v5 
                                = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                         >> 1U));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v5 = 1U;
                        }
                    }
                } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_1__mode)))) {
                    if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                      >> 1U)))) {
                        __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v6 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v6 = 1U;
                    }
                }
            }
        }
        if (((IData)(vlSelfRef.emu__DOT__sys__DOT____Vcellinp__snd__rd) 
             & (3U != (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                             >> 1U))))) {
            if ((1U == (3U & (((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                             >> 1U)))
                                ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control
                               [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                       >> 1U))] : 0U) 
                              >> 4U)))) {
                vlSelfRef.__PVT__emu__DOT__sys__DOT__pit_snd_dout 
                    = ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U))) ? (0x000000ffU 
                                                 & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value
                                                 [(3U 
                                                   & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                      >> 1U))])
                        : 0U);
            } else if ((2U == (3U & (((2U >= (3U & 
                                              (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                               >> 1U)))
                                       ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control
                                      [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                              >> 1U))]
                                       : 0U) >> 4U)))) {
                vlSelfRef.__PVT__emu__DOT__sys__DOT__pit_snd_dout 
                    = (0x000000ffU & (((2U >= (3U & 
                                               (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                >> 1U)))
                                        ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value
                                       [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                               >> 1U))]
                                        : 0U) >> 8U));
            } else {
                vlSelfRef.__PVT__emu__DOT__sys__DOT__pit_snd_dout 
                    = (0x000000ffU & ((3U == (3U & 
                                              (((2U 
                                                 >= 
                                                 (3U 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U)))
                                                 ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control
                                                [(3U 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U))]
                                                 : 0U) 
                                               >> 4U)))
                                       ? (((2U >= (3U 
                                                   & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                      >> 1U))) 
                                           && vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__readhi
                                           [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U))])
                                           ? (((2U 
                                                >= 
                                                (3U 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))
                                                ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value
                                               [(3U 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U))]
                                                : 0U) 
                                              >> 8U)
                                           : ((2U >= 
                                               (3U 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U)))
                                               ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value
                                              [(3U 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U))]
                                               : 0U))
                                       : (((2U >= (3U 
                                                   & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                      >> 1U))) 
                                           && vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__readhi
                                           [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U))])
                                           ? (((2U 
                                                >= 
                                                (3U 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))
                                                ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__latch
                                               [(3U 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U))]
                                                : 0U) 
                                              >> 8U)
                                           : ((2U >= 
                                               (3U 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U)))
                                               ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__latch
                                              [(3U 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U))]
                                               : 0U))));
                if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                  >> 1U)))) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__readhi__v4 
                        = (1U & (~ ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                  >> 1U))) 
                                    && vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__readhi
                                    [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                            >> 1U))])));
                    __VdlyDim0__emu__DOT__sys__DOT__snd__DOT__readhi__v4 
                        = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                 >> 1U));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__readhi__v4 = 1U;
                }
            }
        }
        if (((IData)(vlSelfRef.emu__DOT__sys__DOT____Vcellinp__snd__rd) 
             & (6U == (6U & vlSelfRef.__PVT__emu__DOT__wbm_adr)))) {
            vlSelfRef.__PVT__emu__DOT__sys__DOT__pit_snd_dout = 0U;
        }
        if ((3U == (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__tick_div))) {
            __Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl 
                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control[0U];
            vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode 
                = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl) 
                                       >> 1U))) ? (3U 
                                                   & ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl) 
                                                      >> 1U))
                          : ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl) 
                             >> 1U)));
            __Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl 
                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control[1U];
            if ((4U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode) 
                              >> 1U)))) {
                    if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U])) {
                        if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U])) {
                            __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v3 
                                = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U]) 
                                                  - (IData)(1U)));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v3 = 1U;
                        } else if ((0U < vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U])) {
                            __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v4 
                                = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U]) 
                                                  - (IData)(1U)));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v4 = 1U;
                        } else {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v5 = 1U;
                        }
                    } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v9 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v5 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U];
                    } else if ((vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[0U] 
                                & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[0U])))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v10 = 1U;
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode))) {
                if ((1U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode))) {
                    if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v6 = 1U;
                    } else if ((1U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v6 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v6 = 1U;
                    } else if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v7 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v7 
                            = (0x0000ffffU > ((((0U 
                                                 == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U]) 
                                                << 0x00000010U) 
                                               | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U]) 
                                              >> 1U));
                    } else if ((1U < vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v8 
                            = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U]) 
                                              - (IData)(1U)));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v8 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v8 
                            = ((0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U]) 
                                               - (IData)(1U))) 
                               > ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U]) 
                                    << 0x00000010U) 
                                   | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U]) 
                                  >> 1U));
                    } else {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v9 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v9 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v9 
                            = ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U]) 
                                 << 0x00000010U) | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U]) 
                               > ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U]) 
                                    << 0x00000010U) 
                                   | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U]) 
                                  >> 1U));
                    }
                } else if ((vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[0U] 
                            & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[0U])))) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v10 
                        = ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U]) 
                           | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U]);
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v10 = 1U;
                } else if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U])) {
                    if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v11 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v10 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U];
                    } else if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v11 = 1U;
                    } else if ((2U >= vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v14 = 1U;
                    } else {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v12 
                            = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U]) 
                                              - (IData)(1U)));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v12 = 1U;
                    }
                } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v13 
                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U];
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v13 = 1U;
                } else {
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v12 = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode))) {
                if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U])) {
                    if ((1U & (~ vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U]))) {
                        if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v13 = 1U;
                        }
                    }
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v14 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v14 = 1U;
                } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v15 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v15 = 1U;
                } else {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v16 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v16 = 1U;
                    if ((vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[0U] 
                         & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[0U])))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v18 = 1U;
                    }
                }
            } else if ((0U != vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U])) {
                if ((1U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v17 
                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U];
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v17 = 1U;
                } else if (((2U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U]) 
                            & (1U >= vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U]))) {
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v20 = 1U;
                } else {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v19 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v19 = 1U;
                }
            }
            vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode 
                = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl) 
                                       >> 1U))) ? (3U 
                                                   & ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl) 
                                                      >> 1U))
                          : ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl) 
                             >> 1U)));
            __Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl 
                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control[2U];
            if ((4U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode) 
                              >> 1U)))) {
                    if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U])) {
                        if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U])) {
                            __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v20 
                                = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U]) 
                                                  - (IData)(1U)));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v20 = 1U;
                        } else if ((0U < vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U])) {
                            __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v21 
                                = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U]) 
                                                  - (IData)(1U)));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v21 = 1U;
                        } else {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v17 = 1U;
                        }
                    } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v23 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v22 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U];
                    } else if ((vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[1U] 
                                & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[1U])))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v24 = 1U;
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode))) {
                if ((1U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode))) {
                    if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v18 = 1U;
                    } else if ((1U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v23 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v23 = 1U;
                    } else if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v24 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v19 
                            = (0x0000ffffU > ((((0U 
                                                 == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U]) 
                                                << 0x00000010U) 
                                               | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U]) 
                                              >> 1U));
                    } else if ((1U < vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v25 
                            = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U]) 
                                              - (IData)(1U)));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v25 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v20 
                            = ((0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U]) 
                                               - (IData)(1U))) 
                               > ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U]) 
                                    << 0x00000010U) 
                                   | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U]) 
                                  >> 1U));
                    } else {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v26 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v26 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v21 
                            = ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U]) 
                                 << 0x00000010U) | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U]) 
                               > ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U]) 
                                    << 0x00000010U) 
                                   | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U]) 
                                  >> 1U));
                    }
                } else if ((vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[1U] 
                            & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[1U])))) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v22 
                        = ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U]) 
                           | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U]);
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v22 = 1U;
                } else if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U])) {
                    if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v23 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v27 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U];
                    } else if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v28 = 1U;
                    } else if ((2U >= vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v28 = 1U;
                    } else {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v29 
                            = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U]) 
                                              - (IData)(1U)));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v29 = 1U;
                    }
                } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v30 
                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U];
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v30 = 1U;
                } else {
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v24 = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode))) {
                if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U])) {
                    if ((1U & (~ vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U]))) {
                        if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v25 = 1U;
                        }
                    }
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v31 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v31 = 1U;
                } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v32 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v32 = 1U;
                } else {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v33 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v33 = 1U;
                    if ((vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[1U] 
                         & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[1U])))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v32 = 1U;
                    }
                }
            } else if ((0U != vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U])) {
                if ((1U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v34 
                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U];
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v34 = 1U;
                } else if (((2U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U]) 
                            & (1U >= vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U]))) {
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v34 = 1U;
                } else {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v36 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v36 = 1U;
                }
            }
            vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode 
                = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl) 
                                       >> 1U))) ? (3U 
                                                   & ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl) 
                                                      >> 1U))
                          : ((IData)(__Vfunc_emu__DOT__sys__DOT__snd__DOT__mode__15__ctl) 
                             >> 1U)));
            if ((4U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode) 
                              >> 1U)))) {
                    if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U])) {
                        if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U])) {
                            __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v37 
                                = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U]) 
                                                  - (IData)(1U)));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v37 = 1U;
                        } else if ((0U < vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U])) {
                            __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v38 
                                = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U]) 
                                                  - (IData)(1U)));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v38 = 1U;
                        } else {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v29 = 1U;
                        }
                    } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v37 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v39 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U];
                    } else if ((vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[2U] 
                                & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[2U])))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v38 = 1U;
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode))) {
                if ((1U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode))) {
                    if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v30 = 1U;
                    } else if ((1U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v40 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v40 = 1U;
                    } else if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v41 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v31 
                            = (0x0000ffffU > ((((0U 
                                                 == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U]) 
                                                << 0x00000010U) 
                                               | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U]) 
                                              >> 1U));
                    } else if ((1U < vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v42 
                            = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U]) 
                                              - (IData)(1U)));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v42 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v32 
                            = ((0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U]) 
                                               - (IData)(1U))) 
                               > ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U]) 
                                    << 0x00000010U) 
                                   | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U]) 
                                  >> 1U));
                    } else {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v43 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v43 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v33 
                            = ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U]) 
                                 << 0x00000010U) | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U]) 
                               > ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U]) 
                                    << 0x00000010U) 
                                   | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U]) 
                                  >> 1U));
                    }
                } else if ((vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[2U] 
                            & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[2U])))) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v34 
                        = ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U]) 
                           | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U]);
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v34 = 1U;
                } else if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U])) {
                    if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v35 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v44 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U];
                    } else if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v45 = 1U;
                    } else if ((2U >= vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v42 = 1U;
                    } else {
                        __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v46 
                            = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U]) 
                                              - (IData)(1U)));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v46 = 1U;
                    }
                } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v47 
                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U];
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v47 = 1U;
                } else {
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v36 = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snd__DOT____VlemCall_2__mode))) {
                if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U])) {
                    if ((1U & (~ vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U]))) {
                        if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v37 = 1U;
                        }
                    }
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v48 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v48 = 1U;
                } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v49 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v49 = 1U;
                } else {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v50 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v50 = 1U;
                    if ((vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[2U] 
                         & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[2U])))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v46 = 1U;
                    }
                }
            } else if ((0U != vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U])) {
                if ((1U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v51 
                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U];
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v51 = 1U;
                } else if (((2U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U]) 
                            & (1U >= vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U]))) {
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v48 = 1U;
                } else {
                    __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v53 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v53 = 1U;
                }
            }
            __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl 
                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control[0U];
            vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode 
                = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl) 
                                       >> 1U))) ? (3U 
                                                   & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl) 
                                                      >> 1U))
                          : ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl) 
                             >> 1U)));
            __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl 
                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control[1U];
            if ((4U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode) 
                              >> 1U)))) {
                    __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl 
                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control[0U];
                    vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_3__mode 
                        = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl) 
                                               >> 1U)))
                                  ? (3U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl) 
                                           >> 1U)) : 
                                 ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl) 
                                  >> 1U)));
                    if ((1U & (~ ((4U == (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_3__mode)) 
                                  & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out)))))) {
                        if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U])) {
                            if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U])) {
                                __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v3 
                                    = (0x0000ffffU 
                                       & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U]) 
                                          - (IData)(1U)));
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v3 = 1U;
                            } else if ((0U < vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U])) {
                                __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v4 
                                    = (0x0000ffffU 
                                       & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U]) 
                                          - (IData)(1U)));
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v4 = 1U;
                            } else {
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v5 = 1U;
                            }
                        } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v9 = 1U;
                            __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v5 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U];
                        } else if (((vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[0U] 
                                     & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[0U]))) 
                                    & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out))) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v10 = 1U;
                        }
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode))) {
                if ((1U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode))) {
                    if ((1U & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out)) 
                               | (0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U])))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v6 = 1U;
                    } else if ((1U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v6 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v6 = 1U;
                    } else if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v7 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v7 
                            = (0x0000ffffU > ((((0U 
                                                 == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U]) 
                                                << 0x00000010U) 
                                               | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U]) 
                                              >> 1U));
                    } else if ((1U < vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v8 
                            = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U]) 
                                              - (IData)(1U)));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v8 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v8 
                            = ((0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U]) 
                                               - (IData)(1U))) 
                               > ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U]) 
                                    << 0x00000010U) 
                                   | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U]) 
                                  >> 1U));
                    } else {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v9 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v9 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v9 
                            = ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U]) 
                                 << 0x00000010U) | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U]) 
                               > ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U]) 
                                    << 0x00000010U) 
                                   | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U]) 
                                  >> 1U));
                    }
                } else if ((1U & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out))) {
                    if (((vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[0U] 
                          & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[0U]))) 
                         & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out))) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v10 
                            = ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U]) 
                               | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U]);
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v10 = 1U;
                    } else if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U])) {
                        if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v11 = 1U;
                            __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v10 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U];
                        } else if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v11 = 1U;
                        } else if ((2U >= vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v14 = 1U;
                        } else {
                            __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v12 
                                = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U]) 
                                                  - (IData)(1U)));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v12 = 1U;
                        }
                    } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v13 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v13 = 1U;
                    } else {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v12 = 1U;
                    }
                } else {
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v13 = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode))) {
                if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U])) {
                    if ((1U & (~ vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U]))) {
                        if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v14 = 1U;
                        }
                    }
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v14 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v14 = 1U;
                } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v15 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v15 = 1U;
                } else {
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v16 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v16 = 1U;
                    if (((vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[0U] 
                          & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[0U]))) 
                         & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v18 = 1U;
                    }
                }
            } else if ((0U != vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U])) {
                if ((1U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v17 
                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U];
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v17 = 1U;
                } else if ((1U & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out))) {
                    if (((2U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U]) 
                         & (1U >= vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U]))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v20 = 1U;
                    } else {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v19 
                            = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U]) 
                                              - (IData)(1U)));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v19 = 1U;
                    }
                }
            }
            vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode 
                = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl) 
                                       >> 1U))) ? (3U 
                                                   & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl) 
                                                      >> 1U))
                          : ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl) 
                             >> 1U)));
            __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl 
                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control[2U];
            if ((4U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode) 
                              >> 1U)))) {
                    __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl 
                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control[1U];
                    vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_3__mode 
                        = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl) 
                                               >> 1U)))
                                  ? (3U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl) 
                                           >> 1U)) : 
                                 ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl) 
                                  >> 1U)));
                    if ((1U & (~ ((4U == (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_3__mode)) 
                                  & (~ ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out) 
                                        >> 1U)))))) {
                        if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U])) {
                            if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U])) {
                                __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v20 
                                    = (0x0000ffffU 
                                       & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U]) 
                                          - (IData)(1U)));
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v20 = 1U;
                            } else if ((0U < vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U])) {
                                __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v21 
                                    = (0x0000ffffU 
                                       & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U]) 
                                          - (IData)(1U)));
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v21 = 1U;
                            } else {
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v18 = 1U;
                            }
                        } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v23 = 1U;
                            __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v22 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U];
                        } else if (((vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[1U] 
                                     & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[1U]))) 
                                    & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out) 
                                       >> 1U))) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v24 = 1U;
                        }
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode))) {
                if ((1U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode))) {
                    if ((1U & ((~ ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out) 
                                   >> 1U)) | (0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U])))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v19 = 1U;
                    } else if ((1U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v23 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v23 = 1U;
                    } else if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v24 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v20 
                            = (0x0000ffffU > ((((0U 
                                                 == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U]) 
                                                << 0x00000010U) 
                                               | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U]) 
                                              >> 1U));
                    } else if ((1U < vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v25 
                            = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U]) 
                                              - (IData)(1U)));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v25 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v21 
                            = ((0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U]) 
                                               - (IData)(1U))) 
                               > ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U]) 
                                    << 0x00000010U) 
                                   | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U]) 
                                  >> 1U));
                    } else {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v26 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v26 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v22 
                            = ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U]) 
                                 << 0x00000010U) | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U]) 
                               > ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U]) 
                                    << 0x00000010U) 
                                   | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U]) 
                                  >> 1U));
                    }
                } else if ((2U & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out))) {
                    if (((vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[1U] 
                          & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[1U]))) 
                         & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out) 
                            >> 1U))) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v23 
                            = ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U]) 
                               | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U]);
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v23 = 1U;
                    } else if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U])) {
                        if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v24 = 1U;
                            __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v27 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U];
                        } else if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v28 = 1U;
                        } else if ((2U >= vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v28 = 1U;
                        } else {
                            __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v29 
                                = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U]) 
                                                  - (IData)(1U)));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v29 = 1U;
                        }
                    } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v30 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v30 = 1U;
                    } else {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v25 = 1U;
                    }
                } else {
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v26 = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode))) {
                if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U])) {
                    if ((1U & (~ vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U]))) {
                        if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v27 = 1U;
                        }
                    }
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v31 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v31 = 1U;
                } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v32 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v32 = 1U;
                } else {
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v33 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v33 = 1U;
                    if (((vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[1U] 
                          & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[1U]))) 
                         & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out) 
                            >> 1U))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v32 = 1U;
                    }
                }
            } else if ((0U != vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U])) {
                if ((1U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v34 
                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U];
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v34 = 1U;
                } else if ((2U & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out))) {
                    if (((2U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U]) 
                         & (1U >= vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U]))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v34 = 1U;
                    } else {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v36 
                            = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U]) 
                                              - (IData)(1U)));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v36 = 1U;
                    }
                }
            }
            vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode 
                = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl) 
                                       >> 1U))) ? (3U 
                                                   & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl) 
                                                      >> 1U))
                          : ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__11__ctl) 
                             >> 1U)));
            if ((4U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode))) {
                if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode) 
                              >> 1U)))) {
                    __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl 
                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control[2U];
                    vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_3__mode 
                        = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl) 
                                               >> 1U)))
                                  ? (3U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl) 
                                           >> 1U)) : 
                                 ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__12__ctl) 
                                  >> 1U)));
                    if ((1U & (~ ((4U == (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_3__mode)) 
                                  & (~ ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out) 
                                        >> 2U)))))) {
                        if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U])) {
                            if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U])) {
                                __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v37 
                                    = (0x0000ffffU 
                                       & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U]) 
                                          - (IData)(1U)));
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v37 = 1U;
                            } else if ((0U < vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U])) {
                                __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v38 
                                    = (0x0000ffffU 
                                       & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U]) 
                                          - (IData)(1U)));
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v38 = 1U;
                            } else {
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v31 = 1U;
                            }
                        } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v37 = 1U;
                            __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v39 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U];
                        } else if (((vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[2U] 
                                     & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[2U]))) 
                                    & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out) 
                                       >> 2U))) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v38 = 1U;
                        }
                    }
                }
            } else if ((2U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode))) {
                if ((1U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode))) {
                    if ((1U & ((~ ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out) 
                                   >> 2U)) | (0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U])))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v32 = 1U;
                    } else if ((1U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v40 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v40 = 1U;
                    } else if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U])) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v41 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v33 
                            = (0x0000ffffU > ((((0U 
                                                 == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U]) 
                                                << 0x00000010U) 
                                               | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U]) 
                                              >> 1U));
                    } else if ((1U < vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v42 
                            = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U]) 
                                              - (IData)(1U)));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v42 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v34 
                            = ((0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U]) 
                                               - (IData)(1U))) 
                               > ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U]) 
                                    << 0x00000010U) 
                                   | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U]) 
                                  >> 1U));
                    } else {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v43 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v43 = 1U;
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v35 
                            = ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U]) 
                                 << 0x00000010U) | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U]) 
                               > ((((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U]) 
                                    << 0x00000010U) 
                                   | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U]) 
                                  >> 1U));
                    }
                } else if ((4U & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out))) {
                    if (((vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[2U] 
                          & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[2U]))) 
                         & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out) 
                            >> 2U))) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v36 
                            = ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U]) 
                               | vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U]);
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v36 = 1U;
                    } else if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U])) {
                        if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v37 = 1U;
                            __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v44 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U];
                        } else if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v45 = 1U;
                        } else if ((2U >= vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v42 = 1U;
                        } else {
                            __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v46 
                                = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U]) 
                                                  - (IData)(1U)));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v46 = 1U;
                        }
                    } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U])) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v47 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U];
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v47 = 1U;
                    } else {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v38 = 1U;
                    }
                } else {
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v39 = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_2__mode))) {
                if ((2U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U])) {
                    if ((1U & (~ vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U]))) {
                        if ((0U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U])) {
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v40 = 1U;
                        }
                    }
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v48 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v48 = 1U;
                } else if ((1U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v49 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v49 = 1U;
                } else {
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v50 
                        = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U]) 
                                          - (IData)(1U)));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v50 = 1U;
                    if (((vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[2U] 
                          & (~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[2U]))) 
                         & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out) 
                            >> 2U))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v46 = 1U;
                    }
                }
            } else if ((0U != vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U])) {
                if ((1U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U])) {
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v51 
                        = vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U];
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v51 = 1U;
                } else if ((4U & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out))) {
                    if (((2U == vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U]) 
                         & (1U >= vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U]))) {
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v48 = 1U;
                    } else {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v53 
                            = (0x0000ffffU & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U]) 
                                              - (IData)(1U)));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v53 = 1U;
                    }
                }
            }
        }
        if (vlSelfRef.emu__DOT__sys__DOT____Vcellinp__snl__wr) {
            if ((3U == (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                              >> 1U)))) {
                if ((3U != (3U & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                  >> 6U)))) {
                    if ((2U >= (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel))) {
                        __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__writehi__v3 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel;
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__writehi__v3 = 1U;
                        __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__readhi__v3 
                            = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel;
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__readhi__v3 = 1U;
                    }
                    if ((0U == (3U & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                      >> 4U)))) {
                        if ((2U >= (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel))) {
                            __VdlyVal__emu__DOT__sys__DOT__snl__DOT__latch__v3 
                                = ((2U >= (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel))
                                    ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value
                                   [vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel]
                                    : 0U);
                            __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__latch__v3 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel;
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__latch__v3 = 1U;
                        }
                    } else {
                        __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__9__ctl 
                            = (0x0000003fU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                        vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_0__mode 
                            = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__9__ctl) 
                                                   >> 1U)))
                                      ? (3U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__9__ctl) 
                                               >> 1U))
                                      : ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__9__ctl) 
                                         >> 1U)));
                        if ((2U >= (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel))) {
                            __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v3 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel;
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v3 = 1U;
                            __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v3 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel;
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__loaded__v3 = 1U;
                            __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v3 
                                = (0U != (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_0__mode));
                            __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__output_r__v3 
                                = vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel;
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v3 = 1U;
                        }
                    }
                }
            } else {
                __Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__10__ctl 
                    = ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U))) ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control
                       [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                               >> 1U))] : 0U);
                vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_1__mode 
                    = (7U & ((6U <= (7U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__10__ctl) 
                                           >> 1U)))
                              ? (3U & ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__10__ctl) 
                                       >> 1U)) : ((IData)(__Vfunc_emu__DOT__sys__DOT__snl__DOT__mode__10__ctl) 
                                                  >> 1U)));
                if ((1U == (3U & (((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                 >> 1U)))
                                    ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control
                                   [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                           >> 1U))]
                                    : 0U) >> 4U)))) {
                    if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                      >> 1U)))) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v3 
                            = (0x000000ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                        __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v3 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__count__v3 = 1U;
                        __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v4 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__loaded__v4 = 1U;
                    }
                } else if ((2U == (3U & (((2U >= (3U 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U)))
                                           ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control
                                          [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                  >> 1U))]
                                           : 0U) >> 4U)))) {
                    if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                      >> 1U)))) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v4 
                            = (0x000000ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                        __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v4 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__count__v4 = 1U;
                        __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v5 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__loaded__v5 = 1U;
                    }
                } else if ((3U == (3U & (((2U >= (3U 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U)))
                                           ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control
                                          [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                  >> 1U))]
                                           : 0U) >> 4U)))) {
                    if (((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                       >> 1U))) && vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__writehi
                         [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                 >> 1U))])) {
                        if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                          >> 1U)))) {
                            __VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v5 
                                = (0x000000ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                            __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v5 
                                = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                         >> 1U));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__count__v5 = 1U;
                            __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v6 
                                = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                         >> 1U));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__loaded__v6 = 1U;
                        }
                    } else if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                             >> 1U)))) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v6 
                            = (0x000000ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg));
                        __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v6 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__count__v6 = 1U;
                    }
                    if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                      >> 1U)))) {
                        __VdlyVal__emu__DOT__sys__DOT__snl__DOT__writehi__v4 
                            = (1U & (~ ((2U >= (3U 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U))) 
                                        && vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__writehi
                                        [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                >> 1U))])));
                        __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__writehi__v4 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__writehi__v4 = 1U;
                    }
                }
                if ((4U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_1__mode))) {
                    if ((1U & (~ ((IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_1__mode) 
                                  >> 1U)))) {
                        if ((1U & (~ (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_1__mode)))) {
                            if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                              >> 1U)))) {
                                __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v4 
                                    = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                             >> 1U));
                                vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v4 = 1U;
                            }
                        }
                    }
                } else if ((2U & (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_1__mode))) {
                    if ((0U == ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                              >> 1U)))
                                 ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase
                                [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                        >> 1U))] : 0U))) {
                        if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                          >> 1U)))) {
                            __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v5 
                                = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                         >> 1U));
                            vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v5 = 1U;
                        }
                    }
                } else if ((1U & (~ (IData)(vlSelfRef.emu__DOT__sys__DOT__snl__DOT____VlemCall_1__mode)))) {
                    if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                      >> 1U)))) {
                        __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v6 
                            = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U));
                        vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v6 = 1U;
                    }
                }
            }
        }
        if (((IData)(vlSelfRef.emu__DOT__sys__DOT____Vcellinp__snl__rd) 
             & (3U != (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                             >> 1U))))) {
            if ((1U == (3U & (((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                             >> 1U)))
                                ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control
                               [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                       >> 1U))] : 0U) 
                              >> 4U)))) {
                vlSelfRef.__PVT__emu__DOT__sys__DOT__pit_snl_dout 
                    = ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 1U))) ? (0x000000ffU 
                                                 & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value
                                                 [(3U 
                                                   & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                      >> 1U))])
                        : 0U);
            } else if ((2U == (3U & (((2U >= (3U & 
                                              (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                               >> 1U)))
                                       ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control
                                      [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                              >> 1U))]
                                       : 0U) >> 4U)))) {
                vlSelfRef.__PVT__emu__DOT__sys__DOT__pit_snl_dout 
                    = (0x000000ffU & (((2U >= (3U & 
                                               (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                >> 1U)))
                                        ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value
                                       [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                               >> 1U))]
                                        : 0U) >> 8U));
            } else {
                vlSelfRef.__PVT__emu__DOT__sys__DOT__pit_snl_dout 
                    = (0x000000ffU & ((3U == (3U & 
                                              (((2U 
                                                 >= 
                                                 (3U 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U)))
                                                 ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control
                                                [(3U 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U))]
                                                 : 0U) 
                                               >> 4U)))
                                       ? (((2U >= (3U 
                                                   & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                      >> 1U))) 
                                           && vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__readhi
                                           [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U))])
                                           ? (((2U 
                                                >= 
                                                (3U 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))
                                                ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value
                                               [(3U 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U))]
                                                : 0U) 
                                              >> 8U)
                                           : ((2U >= 
                                               (3U 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U)))
                                               ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value
                                              [(3U 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U))]
                                               : 0U))
                                       : (((2U >= (3U 
                                                   & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                      >> 1U))) 
                                           && vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__readhi
                                           [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U))])
                                           ? (((2U 
                                                >= 
                                                (3U 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))
                                                ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__latch
                                               [(3U 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U))]
                                                : 0U) 
                                              >> 8U)
                                           : ((2U >= 
                                               (3U 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U)))
                                               ? vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__latch
                                              [(3U 
                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                   >> 1U))]
                                               : 0U))));
                if ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                  >> 1U)))) {
                    __VdlyVal__emu__DOT__sys__DOT__snl__DOT__readhi__v4 
                        = (1U & (~ ((2U >= (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                  >> 1U))) 
                                    && vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__readhi
                                    [(3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                            >> 1U))])));
                    __VdlyDim0__emu__DOT__sys__DOT__snl__DOT__readhi__v4 
                        = (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                 >> 1U));
                    vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__readhi__v4 = 1U;
                }
            }
        }
        if (((IData)(vlSelfRef.emu__DOT__sys__DOT____Vcellinp__snl__rd) 
             & (6U == (6U & vlSelfRef.__PVT__emu__DOT__wbm_adr)))) {
            vlSelfRef.__PVT__emu__DOT__sys__DOT__pit_snl_dout = 0U;
        }
        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb) {
            if (vlSelfRef.__PVT__emu__DOT__sys__DOT__stb_rise) {
                if ((1U & (~ ((vlSelfRef.__PVT__emu__DOT__wbm_adr 
                               >> 0x00000010U) & (0x4000U 
                                                  > 
                                                  (0x0000ffffU 
                                                   & vlSelfRef.__PVT__emu__DOT__wbm_adr)))))) {
                    if ((0xe000U <= (0x0000ffffU & vlSelfRef.__PVT__emu__DOT__wbm_adr))) {
                        if ((0xf800U > (0x0000ffffU 
                                        & vlSelfRef.__PVT__emu__DOT__wbm_adr))) {
                            if ((0x7100U != (0x00007fffU 
                                             & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                >> 1U)))) {
                                if ((0x7101U != (0x00007fffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))) {
                                    if ((1U & (~ ((0x1c41U 
                                                   == 
                                                   (0x00001fffU 
                                                    & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                       >> 3U))) 
                                                  | (0x1c42U 
                                                     == 
                                                     (0x00001fffU 
                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                         >> 3U))))))) {
                                        if ((0x710cU 
                                             != (0x00007fffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))) {
                                            if ((0x710dU 
                                                 != 
                                                 (0x00007fffU 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U)))) {
                                                if (
                                                    (0x710eU 
                                                     != 
                                                     (0x00007fffU 
                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                         >> 1U)))) {
                                                    if (
                                                        (0x710fU 
                                                         != 
                                                         (0x00007fffU 
                                                          & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (((((0x7110U 
                                                                     == 
                                                                     (0x00007fffU 
                                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                         >> 1U))) 
                                                                    | (0x7112U 
                                                                       == 
                                                                       (0x00007fffU 
                                                                        & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                           >> 1U)))) 
                                                                   | (0x711cU 
                                                                      == 
                                                                      (0x00007fffU 
                                                                       & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                          >> 1U)))) 
                                                                  | (0x711dU 
                                                                     == 
                                                                     (0x00007fffU 
                                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                         >> 1U)))) 
                                                                 | (0x711fU 
                                                                    == 
                                                                    (0x00007fffU 
                                                                     & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                        >> 1U))))))) {
                                                            if (
                                                                (0x7111U 
                                                                 != 
                                                                 (0x00007fffU 
                                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (0x7113U 
                                                                     != 
                                                                     (0x00007fffU 
                                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                         >> 1U)))) {
                                                                    if (
                                                                        (0x7114U 
                                                                         != 
                                                                         (0x00007fffU 
                                                                          & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                             >> 1U)))) {
                                                                        if (
                                                                            (0x7115U 
                                                                             != 
                                                                             (0x00007fffU 
                                                                              & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                            if (
                                                                                (0x7116U 
                                                                                == 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) {
                                                                                vlSelfRef.__PVT__emu__DOT__fdc_params 
                                                                                = 
                                                                                ((0x00000010U 
                                                                                & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                                                                << 1U)) 
                                                                                | ((8U 
                                                                                & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                                                                >> 1U)) 
                                                                                | (7U 
                                                                                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg))));
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if ((IData)((((IData)(vlSelfRef.__PVT__emu__DOT__cpu_reset_s) 
                  >> 1U) | (IData)(vlSelfRef.__PVT__emu__DOT__fdc_reset)))) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__dir = 0U;
    } else {
        if (vlSelfRef.__PVT__emu__DOT__hd_dir_wr) {
            vlSelfRef.__PVT__emu__DOT__fdc__DOT__dir = 1U;
        }
        if (vlSelfRef.__PVT__emu__DOT__hd_dir_rd) {
            vlSelfRef.__PVT__emu__DOT__fdc__DOT__dir = 0U;
        }
    }
    vlSelfRef.__PVT__emu__DOT__sys__DOT__ioint = (0U 
                                                  != 
                                                  ((~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_mr)) 
                                                   & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__pic_rr)));
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__key_prev__v0) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[3U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[4U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[5U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[6U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[7U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__key_prev__v8) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[0U] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__key_prev__v8;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[1U] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__key_prev__v9;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[2U] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__key_prev__v10;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[3U] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__key_prev__v11;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[4U] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__key_prev__v12;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[5U] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__key_prev__v13;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[6U] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__key_prev__v14;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__key_prev[7U] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__key_prev__v15;
    }
    vlSelfRef.__PVT__emu__DOT__sys__DOT__mousedx = vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousedx;
    vlSelfRef.__PVT__emu__DOT__sys__DOT__mousedy = vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousedy;
    vlSelfRef.__PVT__emu__DOT__sys__DOT__mousest = vlSelfRef.__Vdly__emu__DOT__sys__DOT__mousest;
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__gateprev__v0) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[0U] = 1U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[1U] = 1U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__gateprev__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[0U] = 1U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[1U] = 1U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__gateprev[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__control__v0) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__control__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__control[vlSelfRef.__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__control__v3] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__snd__DOT__control__v3;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v0) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__latch[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__latch[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__latch[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__writehi[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__writehi[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__writehi[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__readhi[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__readhi[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__readhi[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__latch__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__latch[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__latch__v3] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__latch__v3;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__writehi__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__writehi[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__writehi__v3] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__writehi__v4) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__writehi[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__writehi__v4] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__writehi__v4;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__readhi__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__readhi[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__readhi__v3] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__readhi__v4) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__readhi[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__readhi__v4] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__readhi__v4;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__loaded__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v3] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__loaded__v4) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v4] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__loaded__v5) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v5] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__loaded__v6) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__loaded[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__loaded__v6] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__count__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v3] 
            = ((0xff00U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count
                [__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v3]) 
               | (SData)(__VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v3));
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__count__v4) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v4] 
            = ((0x00ffU & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count
                [__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v4]) 
               | ((SData)((IData)(__VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v4)) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__count__v5) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v5] 
            = ((0x00ffU & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count
                [__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v5]) 
               | ((SData)((IData)(__VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v5)) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__count__v6) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v6] 
            = ((0xff00U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__count
                [__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__count__v6]) 
               | (SData)(__VdlyVal__emu__DOT__sys__DOT__snd__DOT__count__v6));
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v3] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v4) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v4] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v5) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v5] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v6) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__phase__v6] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v5) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v9) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v10) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v6) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v10) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v11) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v14) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v13) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v13) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v15) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v18) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v17) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v20) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[0U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v20) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v17) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v24) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v22) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v28) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v30) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v25) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v32) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v32) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v34) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v34) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[1U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v29) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v38) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v40) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v34) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v35) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v42) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v47) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v49) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v46) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[__VdlyDim0__emu__DOT__sys__DOT__snd__DOT__output_r__v3] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v3;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] = 1U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v3;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v5) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v6) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v7) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v7;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v8) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v8;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v9) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v9;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v10) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v10;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v11) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v12) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v13) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v15) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v20) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v20) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v17) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v18) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v24) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v19;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v25) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v20;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v26) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v21;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v22) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v22;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v24) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v25) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v32) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v34) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v29) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v30) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v41) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v31;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v42) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v32;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v43) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v33;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v34) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__output_r__v34;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v35) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v36) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v51) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v49) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v4) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v4;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v9) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v5;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v6) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v6;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v7) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v8) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v8;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v9) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v9;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v11) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v10;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v11) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v12) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v12;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v13) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v13;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v14) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v14;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v15) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v15;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v16) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v16;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v17) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v17;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v20) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v19) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v19;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v20) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v20;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v21) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v21;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v22;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v23;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v24) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v25) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v25;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v26) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v26;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v27;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v28) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v29) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v29;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v30) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v30;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v31) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v31;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v32) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v32;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v33) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v33;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v34) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v34;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v34) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v36) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v36;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v37;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v38) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v38;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v39;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v40) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v40;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v41) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v42) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v42;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v43) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v43;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__output_r__v35) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v44;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v45) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v46) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v46;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v47) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v47;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v48) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v48;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v49) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v49;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v50) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v50;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v51) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v51;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__phase__v48) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__phase[2U] = 3U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U] = 1U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snd__DOT__value__v53) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snd__DOT__value__v53;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__control__v0) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__control__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__control[vlSelfRef.__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__control__v3] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__snl__DOT__control__v3;
    }
    vlSelfRef.__PVT__emu__DOT__sys__DOT__tick_div = vlSelfRef.__Vdly__emu__DOT__sys__DOT__tick_div;
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__gateprev__v0) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[0U] = 1U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[1U] = 1U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__gateprev__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[0U] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__snl__DOT__gateprev__v3;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[1U] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__snl__DOT__gateprev__v4;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__gateprev[2U] 
            = vlSelfRef.__VdlyVal__emu__DOT__sys__DOT__snl__DOT__gateprev__v5;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v0) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__latch[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__latch[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__latch[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__writehi[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__writehi[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__writehi[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__readhi[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__readhi[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__readhi[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__latch__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__latch[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__latch__v3] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__latch__v3;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__writehi__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__writehi[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__writehi__v3] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__writehi__v4) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__writehi[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__writehi__v4] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__writehi__v4;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__readhi__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__readhi[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__readhi__v3] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__readhi__v4) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__readhi[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__readhi__v4] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__readhi__v4;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__loaded__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v3] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__loaded__v4) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v4] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__loaded__v5) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v5] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__loaded__v6) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__loaded[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__loaded__v6] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__count__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v3] 
            = ((0xff00U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count
                [__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v3]) 
               | (SData)(__VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v3));
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__count__v4) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v4] 
            = ((0x00ffU & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count
                [__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v4]) 
               | ((SData)((IData)(__VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v4)) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__count__v5) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v5] 
            = ((0x00ffU & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count
                [__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v5]) 
               | ((SData)((IData)(__VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v5)) 
                  << 8U));
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__count__v6) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v6] 
            = ((0xff00U & vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__count
                [__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__count__v6]) 
               | (SData)(__VdlyVal__emu__DOT__sys__DOT__snl__DOT__count__v6));
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v3] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v4) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v4] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v5) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v5] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v6) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__phase__v6] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v5) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v9) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v10) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v6) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v10) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v11) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v14) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v13) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v14) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v15) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v18) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v17) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v20) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[0U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v20) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v18) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v24) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v24) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v28) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v30) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v27) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v32) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v32) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v34) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v34) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[1U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v31) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v38) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v40) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v36) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v42) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v47) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v40) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 3U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v49) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v46) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[__VdlyDim0__emu__DOT__sys__DOT__snl__DOT__output_r__v3] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v3;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v3) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] = 1U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v3;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v5) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v6) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v7) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v7;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v8) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v8;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v9) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v9;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v10) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v10;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v11) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v12) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v13) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v14) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v15) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v20) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[0U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v20) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v18) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v19) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v24) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v20;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v25) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v21;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v26) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v22;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v23;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v24) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v25) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v26) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v27) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v32) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v34) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[1U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v31) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v32) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v41) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v33;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v42) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v34;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v43) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v35;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v36) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__output_r__v36;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v38) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v39) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v40) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] = 1U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v51) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 2U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v49) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v4) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v4;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v9) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v5;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v6) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v6;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v7) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v8) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v8;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v9) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v9;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v11) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v10;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v11) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v12) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v12;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v13) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v13;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v14) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v14;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v15) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v15;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v16) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v16;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v17) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v17;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v20) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v19) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[0U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v19;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v20) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v20;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v21) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v21;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v22;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v23) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v23;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v24) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v25) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v25;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v26) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v26;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v24) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v27;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v28) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v29) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v29;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v30) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v30;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v31) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v31;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v32) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v32;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v33) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v33;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v34) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v34;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v34) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v36) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[1U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v36;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v37;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v38) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v38;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v39;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v40) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v40;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v41) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v42) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v42;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v43) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v43;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__output_r__v37) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v44;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v45) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v46) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v46;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v47) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v47;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v48) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v48;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v49) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v49;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v50) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v50;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v51) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v51;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__phase__v48) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__phase[2U] = 3U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__output_r[2U] = 1U;
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] = 0xffffU;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__sys__DOT__snl__DOT__value__v53) {
        vlSelfRef.__PVT__emu__DOT__sys__DOT__snl__DOT__value[2U] 
            = __VdlyVal__emu__DOT__sys__DOT__snl__DOT__value__v53;
    }
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__done_s = __Vdly__emu__DOT__fdc__DOT__done_s;
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__reslen = vlSelfRef.__Vdly__emu__DOT__fdc__DOT__reslen;
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__respos = vlSelfRef.__Vdly__emu__DOT__fdc__DOT__respos;
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_run = vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_run;
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__scnt = vlSelfRef.__Vdly__emu__DOT__fdc__DOT__scnt;
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__sector = vlSelfRef.__Vdly__emu__DOT__fdc__DOT__sector;
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_req = vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_req;
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__phase = vlSelfRef.__Vdly__emu__DOT__fdc__DOT__phase;
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__nbuf = vlSelfRef.__Vdly__emu__DOT__fdc__DOT__nbuf;
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_we = vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_we;
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v0) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[0U] = 0x80U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v1) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[0U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v1;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v2) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[1U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v3) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[0U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v3;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v4) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[3U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v6;
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[4U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v7;
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[5U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v8;
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[6U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v9;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v10) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[0U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v10;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v11) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[0U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v11;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v12) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[3U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v14;
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[4U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v15;
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[5U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v16;
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[6U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v17;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__res__v18) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__res[0U] 
            = __VdlyVal__emu__DOT__fdc__DOT__res__v18;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__cmd__v0) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[__VdlyDim0__emu__DOT__fdc__DOT__cmd__v0] 
            = __VdlyVal__emu__DOT__fdc__DOT__cmd__v0;
    }
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmdlen = vlSelfRef.__Vdly__emu__DOT__fdc__DOT__cmdlen;
    vlSelfRef.__PVT__emu__DOT__vm_halt = (1U & (IData)(
                                                       ((0x0bU 
                                                         != 
                                                         (0x0bU 
                                                          & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ppib_rd))) 
                                                        | (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ioint))));
    vlSelfRef.__PVT__emu__DOT__sys__DOT__snd_out = 
        (((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[2U]) 
          << 2U) | (((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[1U]) 
                     << 1U) | vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__output_r[0U]));
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__msr = ((1U 
                                                 == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__phase))
                                                 ? 0x80U
                                                 : 
                                                ((2U 
                                                  == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__phase))
                                                  ? 0x10U
                                                  : 0xd0U));
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__a_q_sel_d 
        = (1U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__pos));
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__buf_hi__DOT__q_a 
        = vlSelfRef.__PVT__emu__DOT__fdc__DOT__buf_hi__DOT__mem
        [vlSelfRef.__PVT__emu__DOT__fdc__DOT__a_waddr];
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__buf_lo__DOT__q_a 
        = vlSelfRef.__PVT__emu__DOT__fdc__DOT__buf_lo__DOT__mem
        [vlSelfRef.__PVT__emu__DOT__fdc__DOT__a_waddr];
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__lba_calc = 
        (0x000007ffU & ((IData)(0x000aU) * (((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[2U]) 
                                             << 1U) 
                                            | (1U & vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[3U]))));
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__newlen = (0x0000000fU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmdlen)));
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__pos = vlSelfRef.__Vdly__emu__DOT__fdc__DOT__pos;
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__a_waddr = 
        (((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__nbuf) 
          << 8U) | (0x000000ffU & ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__pos) 
                                   >> 1U)));
    vlSelfRef.__PVT__emu__DOT__fdc_reset = 0U;
    vlSelfRef.__PVT__emu__DOT__hd_dir_wr = 0U;
    vlSelfRef.__PVT__emu__DOT__hd_dir_rd = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.__PVT__emu__DOT__cpu_reset_s) 
                  >> 1U)))) {
        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb) {
            if (vlSelfRef.__PVT__emu__DOT__sys__DOT__stb_rise) {
                if ((1U & (~ ((vlSelfRef.__PVT__emu__DOT__wbm_adr 
                               >> 0x00000010U) & (0x4000U 
                                                  > 
                                                  (0x0000ffffU 
                                                   & vlSelfRef.__PVT__emu__DOT__wbm_adr)))))) {
                    if ((0xe000U <= (0x0000ffffU & vlSelfRef.__PVT__emu__DOT__wbm_adr))) {
                        if ((0xf800U <= (0x0000ffffU 
                                         & vlSelfRef.__PVT__emu__DOT__wbm_adr))) {
                            if (((~ (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                     >> 0x00000010U)) 
                                 & (0xffc0U > (0x0000ffffU 
                                               & vlSelfRef.__PVT__emu__DOT__wbm_adr)))) {
                                vlSelfRef.__PVT__emu__DOT__cpu_ram_mask = 0U;
                                vlSelfRef.__PVT__emu__DOT__cpu_ram_addr 
                                    = (0x000007ffU 
                                       & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                          >> 1U));
                                vlSelfRef.__PVT__emu__DOT__cpu_ram_we 
                                    = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we;
                                vlSelfRef.__PVT__emu__DOT__cpu_ram_be 
                                    = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_sel;
                                vlSelfRef.__PVT__emu__DOT__cpu_ram_din 
                                    = vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg;
                            } else if ((0x00010000U 
                                        & vlSelfRef.__PVT__emu__DOT__wbm_adr)) {
                                vlSelfRef.__PVT__emu__DOT__cpu_ram_mask = 0U;
                                vlSelfRef.__PVT__emu__DOT__cpu_ram_addr 
                                    = (0x000007ffU 
                                       & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                          >> 1U));
                                vlSelfRef.__PVT__emu__DOT__cpu_ram_we 
                                    = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we;
                                vlSelfRef.__PVT__emu__DOT__cpu_ram_be 
                                    = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_sel;
                                vlSelfRef.__PVT__emu__DOT__cpu_ram_din 
                                    = vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg;
                            }
                        }
                        if ((0xf800U > (0x0000ffffU 
                                        & vlSelfRef.__PVT__emu__DOT__wbm_adr))) {
                            if ((0x7100U != (0x00007fffU 
                                             & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                >> 1U)))) {
                                if ((0x7101U != (0x00007fffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))) {
                                    if ((1U & (~ ((0x1c41U 
                                                   == 
                                                   (0x00001fffU 
                                                    & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                       >> 3U))) 
                                                  | (0x1c42U 
                                                     == 
                                                     (0x00001fffU 
                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                         >> 3U))))))) {
                                        if ((0x710cU 
                                             != (0x00007fffU 
                                                 & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                    >> 1U)))) {
                                            if ((0x710dU 
                                                 != 
                                                 (0x00007fffU 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U)))) {
                                                if (
                                                    (0x710eU 
                                                     != 
                                                     (0x00007fffU 
                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                         >> 1U)))) {
                                                    if (
                                                        (0x710fU 
                                                         != 
                                                         (0x00007fffU 
                                                          & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                             >> 1U)))) {
                                                        if (
                                                            (1U 
                                                             & (~ 
                                                                (((((0x7110U 
                                                                     == 
                                                                     (0x00007fffU 
                                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                         >> 1U))) 
                                                                    | (0x7112U 
                                                                       == 
                                                                       (0x00007fffU 
                                                                        & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                           >> 1U)))) 
                                                                   | (0x711cU 
                                                                      == 
                                                                      (0x00007fffU 
                                                                       & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                          >> 1U)))) 
                                                                  | (0x711dU 
                                                                     == 
                                                                     (0x00007fffU 
                                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                         >> 1U)))) 
                                                                 | (0x711fU 
                                                                    == 
                                                                    (0x00007fffU 
                                                                     & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                        >> 1U))))))) {
                                                            if (
                                                                (0x7111U 
                                                                 != 
                                                                 (0x00007fffU 
                                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                     >> 1U)))) {
                                                                if (
                                                                    (0x7113U 
                                                                     != 
                                                                     (0x00007fffU 
                                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                         >> 1U)))) {
                                                                    if (
                                                                        (0x7114U 
                                                                         != 
                                                                         (0x00007fffU 
                                                                          & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                             >> 1U)))) {
                                                                        if (
                                                                            (0x7115U 
                                                                             != 
                                                                             (0x00007fffU 
                                                                              & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                            if (
                                                                                (0x7116U 
                                                                                == 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                vlSelfRef.__PVT__emu__DOT__hd_dir_wr = 1U;
                                                                            }
                                                                            if (
                                                                                (0x7116U 
                                                                                != 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                if (
                                                                                (0x7117U 
                                                                                == 
                                                                                (0x00007fffU 
                                                                                & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                                                >> 1U)))) {
                                                                                vlSelfRef.__PVT__emu__DOT__hd_dir_rd = 1U;
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if ((1U & (~ ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__memreg) 
                                         >> 3U)))) {
                        if ((0U != (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__bankbits))) {
                            vlSelfRef.__PVT__emu__DOT__cpu_ram_mask 
                                = ((0U == (3U & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__memreg)))
                                    ? 0U : ((2U & (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__memreg))
                                             ? 2U : 1U));
                            vlSelfRef.__PVT__emu__DOT__cpu_ram_addr 
                                = (0x001fffffU & ((
                                                   (1U 
                                                    == (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__bankbits))
                                                    ? 
                                                   (0x0027ffffU 
                                                    & vlSelfRef.__PVT__emu__DOT__sys__DOT__phys)
                                                    : vlSelfRef.__PVT__emu__DOT__sys__DOT__phys) 
                                                  >> 1U));
                            vlSelfRef.__PVT__emu__DOT__cpu_ram_we 
                                = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we;
                            vlSelfRef.__PVT__emu__DOT__cpu_ram_be 
                                = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_sel;
                            vlSelfRef.__PVT__emu__DOT__cpu_ram_din 
                                = vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg;
                        }
                    }
                }
            }
        }
        vlSelfRef.__PVT__emu__DOT__sys__DOT__mouse_tgl 
            = (1U & (vlSymsp->TOP.ps2_mouse >> 0x18U));
        if (vlSelfRef.__PVT__emu__DOT__vm_init) {
            vlSelfRef.__PVT__emu__DOT__fdc_reset = 1U;
        }
    }
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_cyc = 0U;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_sel = 0U;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb = 0U;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we = 0U;
    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_start) {
        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_rd) {
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_cyc = 1U;
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_sel = 3U;
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb = 1U;
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we = 0U;
        }
        if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wr) 
             & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_rd)))) {
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_cyc = 1U;
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we = 1U;
        }
    } else {
        if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_wdone) 
             | ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wr)) 
                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_rdone)))) {
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_cyc = 0U;
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_sel = 0U;
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb = 0U;
        } else if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_rdone) 
                    & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wr))) {
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_sel = 0U;
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb = 0U;
        }
        if ((((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) 
              & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__drdy) 
                 | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__brd_wa))) 
             & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_wdone)))) {
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_sel 
                = ((2U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_sel)) 
                   | (1U & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wo) 
                            | (~ vlSelfRef.__PVT__emu__DOT__wbm_adr))));
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb = 1U;
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_sel 
                = ((1U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_sel)) 
                   | (2U & (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wo) 
                             | vlSelfRef.__PVT__emu__DOT__wbm_adr) 
                            << 1U)));
        }
        if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_wdone) 
             | ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wr)) 
                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_rdone)))) {
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we = 0U;
        } else if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_rdone) 
                    & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wr))) {
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we = 1U;
        }
    }
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__brd_wa) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg = 
            ((0xff00U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg)) 
             | (0x000000ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ax)));
        if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__axy_wh) {
            vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg 
                = ((0x00ffU & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg)) 
                   | (0x0000ff00U & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ax)));
        }
    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__brd_wq) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg = 
            ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qa0)
              ? (0x000000ffU & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_dat) 
                                >> 8U)) : (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_dat));
    }
    vlSelfRef.__PVT__emu__DOT__cpu_reset_s = vlSelfRef.__Vdly__emu__DOT__cpu_reset_s;
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__brd_wq = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__rdat) 
                                                   & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_in) 
                                                      | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_rcd)));
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_rdone) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_dat 
            = vlSelfRef.__PVT__emu__DOT__wbm_dat_i;
    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_idone) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_dat = 0U;
    }
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__first = (0x000000ffU 
                                                  & ((0U 
                                                      == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmdlen))
                                                      ? (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg)
                                                      : vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd[0U]));
    vlSelfRef.__PVT__emu__DOT__wbm_dat_i = vlSelfRef.__Vdly__emu__DOT__wbm_dat_i;
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_idone = 
        ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_iak) 
         & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_una));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_100 = (1U 
                                                  & ((2U 
                                                      & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                      ? (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)
                                                      : 
                                                     (~ (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_105 = ((~ (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)) 
                                                  & (9U 
                                                     == 
                                                     (0x0000000fU 
                                                      & ((IData)(1U) 
                                                         + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmdlen)))));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_31 = ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first) 
                                                 & (9U 
                                                    == 
                                                    (0x0000000fU 
                                                     & ((IData)(1U) 
                                                        + (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmdlen)))));
    if ((1U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))) {
        __VdfgRegularize_hebeb780c_0_101 = 5U;
        __VdfgRegularize_hebeb780c_0_102 = (0x0000001fU 
                                            & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first));
    } else {
        __VdfgRegularize_hebeb780c_0_101 = (0x0000001fU 
                                            & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first));
        __VdfgRegularize_hebeb780c_0_102 = 6U;
    }
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_done) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__drdy = 0U;
    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__brd_wa) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__drdy = 1U;
    }
    vlSelfRef.__PVT__emu__DOT__wbm_ack = ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__ack) 
                                          & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb));
    vlSelfRef.__PVT__emu__DOT__sys__DOT__stb_rise = 
        ((~ (IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__stb_d)) 
         & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_104 = ((~ 
                                                   ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first) 
                                                    >> 1U)) 
                                                  & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_31));
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__cmd_id = (0x0000001fU 
                                                   & ((3U 
                                                       == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                       ? (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)
                                                       : 
                                                      ((4U 
                                                        == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                        ? (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)
                                                        : 
                                                       ((7U 
                                                         == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                         ? (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)
                                                         : 
                                                        ((8U 
                                                          == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                          ? (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)
                                                          : 
                                                         ((0x0fU 
                                                           == (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                           ? (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)
                                                           : 
                                                          ((0x00000010U 
                                                            & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                            ? (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)
                                                            : 
                                                           ((8U 
                                                             & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                             ? 
                                                            ((4U 
                                                              & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                              ? 
                                                             ((2U 
                                                               & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                               ? (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)
                                                               : (IData)(__VdfgRegularize_hebeb780c_0_102))
                                                              : 
                                                             ((2U 
                                                               & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                               ? (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first)
                                                               : (IData)(__VdfgRegularize_hebeb780c_0_101)))
                                                             : 
                                                            ((4U 
                                                              & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                              ? 
                                                             ((2U 
                                                               & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))
                                                               ? (IData)(__VdfgRegularize_hebeb780c_0_102)
                                                               : (IData)(__VdfgRegularize_hebeb780c_0_101))
                                                              : (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__first))))))))));
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_sta) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_adr 
            = (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sel) 
                << 0x00000010U) | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__areg));
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__qa0 = 
            (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__areg) 
              & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wo_xt))) 
             & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_rd_xt) 
                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wr_xt)));
    }
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_stb) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_rd_xt 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_rd_rc;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wo_xt 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wo_rc;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wr_xt 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_wr;
    }
    __PVT__emu__DOT__cpu__DOT__qswp = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qa0) 
                                       & (0x0fU == (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm_rn)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_sta = vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_stb;
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__ra_wa) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__areg = vlSelfRef.__PVT__emu__DOT__cpu__DOT__ax;
    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__ra_wx) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__areg = vlSelfRef.__PVT__emu__DOT__cpu__DOT__x;
    }
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wra) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__sel = 
            (1U & (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                    >> 8U) ^ ((5U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
                              | (3U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)))));
    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__sel = 1U;
    }
    vlSelfRef.__PVT__emu__DOT__wbm_adr = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_sta)
                                           ? (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sel) 
                                               << 0x00000010U) 
                                              | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__areg))
                                           : vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_adr);
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__brd_wa = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__1__KET__) 
                                                   & (0x0fU 
                                                      == (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm_rn)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wo_rc 
        = (1U & (~ ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__dc_fb) 
                    & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__0__KET__)
                        ? (vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm 
                           >> 0x0000001eU) : ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm_wt) 
                                              >> 9U)))));
    __PVT__emu__DOT__cpu__DOT__sxt_rxy = ((~ (IData)(__PVT__emu__DOT__cpu__DOT__qswp)) 
                                          & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sf_byte));
    __PVT__emu__DOT__cpu__DOT__alu_xb = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sf_xchg) 
                                         | (IData)(__PVT__emu__DOT__cpu__DOT__qswp));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__ra_wa = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ra_fw) 
                                                  & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__1__KET__));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_2 = ((((2U 
                                                   & ((~ 
                                                       ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__0__KET__)
                                                         ? 
                                                        (vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm 
                                                         >> 0x00000018U)
                                                         : 
                                                        ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm_wt) 
                                                         >> 3U))) 
                                                      << 1U)) 
                                                  | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_149)) 
                                                 << 2U) 
                                                | (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_38) 
                                                    << 1U) 
                                                   | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_150)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_wdone = 
        ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb) 
         & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) 
            & (IData)(vlSelfRef.__PVT__emu__DOT__wbm_ack)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__axy_wh = (1U 
                                                   & (~ 
                                                      ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sxt_y) 
                                                       & (IData)(__PVT__emu__DOT__cpu__DOT__sxt_rxy))));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_3 = (0x000000ffU 
                                                & ((IData)(__PVT__emu__DOT__cpu__DOT__alu_xb)
                                                    ? 
                                                   ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__xb) 
                                                    >> 8U)
                                                    : (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__xb)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_sel = (
                                                   (0x0bU 
                                                    == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
                                                   | (0x0dU 
                                                      == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_cmd = (
                                                   (2U 
                                                    == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
                                                   | (6U 
                                                      == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_x001 = 
        ((1U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
         | (9U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_cta = (0x0000001fU 
                                                   & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_ctld)
                                                       ? 
                                                      ((1U 
                                                        & ((~ 
                                                            ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__acc) 
                                                             >> 5U)) 
                                                           | (~ 
                                                              ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ireg) 
                                                               >> 0x0000000aU))))
                                                        ? (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3)
                                                        : 
                                                       (~ (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3)))
                                                       : 
                                                      ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_ct) 
                                                       - 
                                                       ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_nrdy) 
                                                        & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__1__KET__)))));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_103 = (0x000000ffU 
                                                  & ((- (IData)(
                                                                (1U 
                                                                 & (~ 
                                                                    (((~ 
                                                                       ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                                                        >> 7U)) 
                                                                      | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sxt_y)) 
                                                                     & (IData)(__PVT__emu__DOT__cpu__DOT__sxt_rxy)))))) 
                                                     & ((- (IData)(
                                                                   (1U 
                                                                    & (~ 
                                                                       ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sf_byte)) 
                                                                        | (IData)(__PVT__emu__DOT__cpu__DOT__qswp)))))) 
                                                        | ((0x00000080U 
                                                            & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_xb)
                                                                  ? 
                                                                 ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__xb) 
                                                                  >> 7U)
                                                                  : 
                                                                 ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sf_sum)) 
                                                                  & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__xb) 
                                                                     >> 0x0000000fU))) 
                                                                | (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cr) 
                                                                    >> 0x0000000fU) 
                                                                   & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sf_sum))) 
                                                               << 7U)) 
                                                           | (0x0000007fU 
                                                              & ((IData)(__PVT__emu__DOT__cpu__DOT__alu_xb)
                                                                  ? (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__xb)
                                                                  : 
                                                                 ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__xb) 
                                                                  >> 8U)))))));
    vlSelfRef.__PVT__emu__DOT__dbg_trap = ((vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                            >> 0x00000010U) 
                                           & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)) 
                                              & ((2U 
                                                  == 
                                                  (0x00007fffU 
                                                   & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                      >> 1U))) 
                                                 | ((4U 
                                                     == 
                                                     (0x00007fffU 
                                                      & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                         >> 1U))) 
                                                    | (6U 
                                                       == 
                                                       (0x00007fffU 
                                                        & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                           >> 1U)))))));
    vlSelfRef.__PVT__emu__DOT__sys__DOT__snd__DOT__wsel 
        = (3U & ((3U == (3U & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                               >> 1U))) ? ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                           >> 6U) : 
                 (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                  >> 1U)));
    vlSelfRef.__PVT__emu__DOT__fdc_sel = (((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__stb_rise) 
                                           & (0x0000e200U 
                                              == (0x0000ffc0U 
                                                  & vlSelfRef.__PVT__emu__DOT__wbm_adr))) 
                                          & ((0x10U 
                                              == (0x0000001fU 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U))) 
                                             | ((0x12U 
                                                 == 
                                                 (0x0000001fU 
                                                  & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                     >> 1U))) 
                                                | ((0x1cU 
                                                    == 
                                                    (0x0000001fU 
                                                     & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                        >> 1U))) 
                                                   | ((0x1dU 
                                                       == 
                                                       (0x0000001fU 
                                                        & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                           >> 1U))) 
                                                      | (0x1fU 
                                                         == 
                                                         (0x0000001fU 
                                                          & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                             >> 1U))))))));
    vlSelfRef.__PVT__emu__DOT__sys__DOT__memreg = (
                                                   (0x00010000U 
                                                    & vlSelfRef.__PVT__emu__DOT__wbm_adr)
                                                    ? vlSelfRef.__PVT__emu__DOT__sys__DOT__HR
                                                   [
                                                   (7U 
                                                    & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                       >> 0x0000000dU))]
                                                    : vlSelfRef.__PVT__emu__DOT__sys__DOT__UR
                                                   [
                                                   (7U 
                                                    & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                                       >> 0x0000000dU))]);
    __VdfgRegularize_hebeb780c_0_40 = ((0x1c41U == 
                                        (0x00001fffU 
                                         & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                            >> 3U))) 
                                       | (0x1c42U == 
                                          (0x00001fffU 
                                           & (vlSelfRef.__PVT__emu__DOT__wbm_adr 
                                              >> 3U))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_wr = (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__dc_iowr) 
                                                   & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_x001)) 
                                                  | ((4U 
                                                      == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
                                                     | (5U 
                                                        == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2))));
    __VdfgRegularize_hebeb780c_0_151 = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__dc_iord) 
                                        & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_x001));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__ax = (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_103) 
                                                << 8U) 
                                               | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3));
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__a_wr = ((((IData)(vlSelfRef.__PVT__emu__DOT__fdc_sel) 
                                                   & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)) 
                                                  & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__dir)) 
                                                 & (0U 
                                                    == 
                                                    (0x0000000eU 
                                                     & vlSelfRef.__PVT__emu__DOT__wbm_adr)));
    vlSelfRef.__PVT__emu__DOT__sys__DOT__phys = (0x003fffffU 
                                                 & ((0x003ff000U 
                                                     & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__memreg) 
                                                        << 8U)) 
                                                    + 
                                                    (0x00001fffU 
                                                     & vlSelfRef.__PVT__emu__DOT__wbm_adr)));
    __PVT__emu__DOT__sys__DOT__pit_rd = ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__stb_rise) 
                                         & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)) 
                                            & (IData)(__VdfgRegularize_hebeb780c_0_40)));
    __PVT__emu__DOT__sys__DOT__pit_wr = ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__stb_rise) 
                                         & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we) 
                                            & ((IData)(__VdfgRegularize_hebeb780c_0_40) 
                                               & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_sel))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_in = ((7U 
                                                   == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
                                                  | ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_cmd)) 
                                                     & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_38) 
                                                        | (IData)(__VdfgRegularize_hebeb780c_0_151))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_rd_rc 
        = ((7U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
           | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_cmd) 
              | ((3U == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
                 | ((IData)(__VdfgRegularize_hebeb780c_0_151) 
                    | ((0x0eU == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)) 
                       | (0x0aU == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2)))))));
    vlSelfRef.__PVT__emu__DOT__sys__DOT__bankbits = 
        ((0x00200000U & vlSelfRef.__PVT__emu__DOT__sys__DOT__phys)
          ? (IData)(vlSelfRef.__PVT__emu__DOT__ram_banks1)
          : (IData)(vlSelfRef.__PVT__emu__DOT__ram_banks0));
    vlSelfRef.emu__DOT__sys__DOT____Vcellinp__snl__rd 
        = (IData)(((0x0000e210U == (0x0000fff8U & vlSelfRef.__PVT__emu__DOT__wbm_adr)) 
                   & (IData)(__PVT__emu__DOT__sys__DOT__pit_rd)));
    vlSelfRef.emu__DOT__sys__DOT____Vcellinp__snd__rd 
        = (IData)(((0x0000e208U == (0x0000fff8U & vlSelfRef.__PVT__emu__DOT__wbm_adr)) 
                   & (IData)(__PVT__emu__DOT__sys__DOT__pit_rd)));
    vlSelfRef.emu__DOT__sys__DOT____Vcellinp__snl__wr 
        = (IData)(((0x0000e210U == (0x0000fff8U & vlSelfRef.__PVT__emu__DOT__wbm_adr)) 
                   & (IData)(__PVT__emu__DOT__sys__DOT__pit_wr)));
    vlSelfRef.emu__DOT__sys__DOT____Vcellinp__snd__wr 
        = (IData)(((0x0000e208U == (0x0000fff8U & vlSelfRef.__PVT__emu__DOT__wbm_adr)) 
                   & (IData)(__PVT__emu__DOT__sys__DOT__pit_wr)));
}

void Vsim_top_sim_top___nba_sequent__TOP__sim_top__7(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_sequent__TOP__sim_top__7\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__PVT__emu__DOT__fdc__DOT__b_wr) {
        vlSelfRef.__VdlyVal__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v1 
            = (0x000000ffU & ((IData)(vlSymsp->TOP.sd_buff_dout) 
                              >> 8U));
        vlSelfRef.__VdlyDim0__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v1 
            = vlSelfRef.__PVT__emu__DOT__fdc__DOT__b_addr;
        vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v1 = 1U;
        vlSelfRef.__VdlyVal__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v1 
            = (0x000000ffU & (IData)(vlSymsp->TOP.sd_buff_dout));
        vlSelfRef.__VdlyDim0__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v1 
            = vlSelfRef.__PVT__emu__DOT__fdc__DOT__b_addr;
        vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v1 = 1U;
    }
    vlSelfRef.__PVT__emu__DOT__cpu_ram_dout = vlSelfRef.__Vdly__emu__DOT__cpu_ram_dout;
    vlSelfRef.__PVT__emu__DOT__cpu_ram_ack = vlSelfRef.__Vdly__emu__DOT__cpu_ram_ack;
    if (vlSelfRef.__VdlySet__emu__DOT__key_matrix__v0) {
        vlSelfRef.__PVT__emu__DOT__key_matrix[0U] = 0U;
        vlSelfRef.__PVT__emu__DOT__key_matrix[1U] = 0U;
        vlSelfRef.__PVT__emu__DOT__key_matrix[2U] = 0U;
        vlSelfRef.__PVT__emu__DOT__key_matrix[3U] = 0U;
        vlSelfRef.__PVT__emu__DOT__key_matrix[4U] = 0U;
        vlSelfRef.__PVT__emu__DOT__key_matrix[5U] = 0U;
        vlSelfRef.__PVT__emu__DOT__key_matrix[6U] = 0U;
        vlSelfRef.__PVT__emu__DOT__key_matrix[7U] = 0U;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__key_matrix__v8) {
        vlSelfRef.__PVT__emu__DOT__key_matrix[0U] = vlSelfRef.__VdlyVal__emu__DOT__key_matrix__v8;
        vlSelfRef.__PVT__emu__DOT__key_matrix[1U] = vlSelfRef.__VdlyVal__emu__DOT__key_matrix__v9;
        vlSelfRef.__PVT__emu__DOT__key_matrix[2U] = vlSelfRef.__VdlyVal__emu__DOT__key_matrix__v10;
        vlSelfRef.__PVT__emu__DOT__key_matrix[3U] = vlSelfRef.__VdlyVal__emu__DOT__key_matrix__v11;
        vlSelfRef.__PVT__emu__DOT__key_matrix[4U] = vlSelfRef.__VdlyVal__emu__DOT__key_matrix__v12;
        vlSelfRef.__PVT__emu__DOT__key_matrix[5U] = vlSelfRef.__VdlyVal__emu__DOT__key_matrix__v13;
        vlSelfRef.__PVT__emu__DOT__key_matrix[6U] = vlSelfRef.__VdlyVal__emu__DOT__key_matrix__v14;
        vlSelfRef.__PVT__emu__DOT__key_matrix[7U] = vlSelfRef.__VdlyVal__emu__DOT__key_matrix__v15;
    }
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_done_sd 
        = vlSelfRef.__Vdly__emu__DOT__fdc__DOT__xfer_done_sd;
    if ((1U & (IData)(vlSymsp->TOP.img_mounted))) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__readonly 
            = (2U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__readonly));
    }
    if ((2U & (IData)(vlSymsp->TOP.img_mounted))) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__readonly 
            = (1U & (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__readonly));
    }
}

void Vsim_top_sim_top___nba_comb__TOP__sim_top__0(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_comb__TOP__sim_top__0\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    SData/*15:0*/ __PVT__emu__DOT__cpu__DOT__alu_inx;
    __PVT__emu__DOT__cpu__DOT__alu_inx = 0;
    SData/*15:0*/ __PVT__emu__DOT__cpu__DOT__alu_iny;
    __PVT__emu__DOT__cpu__DOT__alu_iny = 0;
    SData/*15:0*/ __PVT__emu__DOT__cpu__DOT__alu_an;
    __PVT__emu__DOT__cpu__DOT__alu_an = 0;
    SData/*15:0*/ __PVT__emu__DOT__cpu__DOT__alu_or;
    __PVT__emu__DOT__cpu__DOT__alu_or = 0;
    SData/*15:0*/ __PVT__emu__DOT__cpu__DOT__y;
    __PVT__emu__DOT__cpu__DOT__y = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__14__KET__;
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__14__KET__ = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__13__KET__;
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__13__KET__ = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__12__KET__;
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__12__KET__ = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__11__KET__;
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__11__KET__ = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__9__KET__;
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__9__KET__ = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__8__KET__;
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__8__KET__ = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__7__KET__;
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__7__KET__ = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__5__KET__;
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__5__KET__ = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__4__KET__;
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__4__KET__ = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__3__KET__;
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__3__KET__ = 0;
    CData/*0:0*/ __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__tbit;
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__tbit = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_14;
    __VdfgRegularize_hebeb780c_0_14 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_35;
    __VdfgRegularize_hebeb780c_0_35 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_132;
    __VdfgRegularize_hebeb780c_0_132 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_133;
    __VdfgRegularize_hebeb780c_0_133 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_134;
    __VdfgRegularize_hebeb780c_0_134 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_135;
    __VdfgRegularize_hebeb780c_0_135 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_136;
    __VdfgRegularize_hebeb780c_0_136 = 0;
    CData/*0:0*/ __VdfgRegularize_hebeb780c_0_137;
    __VdfgRegularize_hebeb780c_0_137 = 0;
    // Body
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy1_clr 
        = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__1__KET__) 
           & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy1) 
              & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_ctld)) 
                 & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_f0r))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__thang = ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__2__KET__)) 
                                                  & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__5__KET__));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__sh_cin = (1U 
                                                   & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_54)
                                                       ? 
                                                      ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ear2) 
                                                       >> 0x0000000fU)
                                                       : (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)));
    __VdfgRegularize_hebeb780c_0_137 = ((~ (3U == (3U 
                                                   & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                                      >> 7U)))) 
                                        & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_138));
    __VdfgRegularize_hebeb780c_0_136 = (IData)(((0x0180U 
                                                 == 
                                                 (0x0180U 
                                                  & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw))) 
                                                & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_138)));
    __VdfgRegularize_hebeb780c_0_133 = (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                         >> 7U) & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5));
    __VdfgRegularize_hebeb780c_0_134 = (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                         >> 8U) & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5));
    __VdfgRegularize_hebeb780c_0_135 = ((~ ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                            >> 8U)) 
                                        & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5));
    __VdfgRegularize_hebeb780c_0_35 = ((~ ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                           >> 7U)) 
                                       & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5));
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__tbit 
        = (1U & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tbit) 
                 | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                    >> 4U)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli_nrdy = 
        ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tend) 
         | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tim_nrdy0) 
            | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tim_nrdy1)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__pc1_wr = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__word27) 
                                                   | (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__0__KET__) 
                                                       & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iopc_st__BRA__1__KET__)) 
                                                          & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_rcdr))) 
                                                      | ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_rcdr)) 
                                                         & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pc2_wa))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__x = ((0x00000010U 
                                               & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                               ? ((0x00000020U 
                                                   & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                   ? 
                                                  ((0x00000040U 
                                                    & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                    ? 
                                                   ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg) 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm 
                                                                     >> 7U)))))
                                                    : 
                                                   ((0x00000080U 
                                                     & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                     ? (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__acc)
                                                     : (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)))
                                                   : 
                                                  ((0x00000040U 
                                                    & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                    ? 
                                                   ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sreg) 
                                                    & (- (IData)(
                                                                 (1U 
                                                                  & (vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm 
                                                                     >> 7U)))))
                                                    : 
                                                   ((0x00000080U 
                                                     & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                     ? (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ear2)
                                                     : (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ear1))))
                                               : ((0x00000020U 
                                                   & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                   ? 
                                                  ((0x00000040U 
                                                    & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                    ? 
                                                   ((0x00000080U 
                                                     & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                     ? 
                                                    ((((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__word27) 
                                                       & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__0__KET__)) 
                                                      | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ra_fr1))
                                                      ? (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pc2)
                                                      : (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pc1))
                                                     : vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[6U])
                                                    : 
                                                   ((0x00000080U 
                                                     & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                     ? vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[5U]
                                                     : vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[4U]))
                                                   : 
                                                  ((0x00000040U 
                                                    & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                    ? 
                                                   ((0x00000080U 
                                                     & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                     ? vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[3U]
                                                     : vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[2U])
                                                    : 
                                                   ((0x00000080U 
                                                     & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                     ? vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[1U]
                                                     : vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[0U]))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_rdone = 
        ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb) 
         & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_we)) 
            & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__to_rply) 
               | (IData)(vlSelfRef.__PVT__emu__DOT__wbm_ack))));
    __PVT__emu__DOT__cpu__DOT__y = (0x0000ffffU & (
                                                   (0x00000100U 
                                                    & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                    ? 
                                                   ((0x00000200U 
                                                     & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                     ? 
                                                    ((0x00000400U 
                                                      & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                      ? 
                                                     ((0x00000800U 
                                                       & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                       ? (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__cpc)
                                                       : 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? 0x0014U
                                                        : (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__vmux)))
                                                      : 
                                                     ((0x00000800U 
                                                       & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                       ? 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? 0x0010U
                                                        : 
                                                       (1U 
                                                        & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)))
                                                       : 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? 
                                                       (- (IData)(
                                                                  (1U 
                                                                   & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                                                      >> 3U))))
                                                        : 
                                                       ((0x0000ff00U 
                                                         & ((- (IData)(
                                                                       (1U 
                                                                        & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ireg) 
                                                                           >> 7U)))) 
                                                            << 8U)) 
                                                        | (0x000000feU 
                                                           & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ireg) 
                                                              << 1U))))))
                                                     : 
                                                    ((0x00000400U 
                                                      & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                      ? 
                                                     ((0x00000800U 
                                                       & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                       ? 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__breg)
                                                        : (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__cpsw))
                                                       : 
                                                      (4U 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm 
                                                                        >> 0x0000000cU))))))
                                                      : 
                                                     ((0x00000800U 
                                                       & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                       ? 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? 2U
                                                        : 
                                                       ((1U 
                                                         & (((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__dc_fb)) 
                                                             & (vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm 
                                                                >> 0x0000001eU)) 
                                                            | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__dc_fb) 
                                                               & (0x40000060U 
                                                                  == 
                                                                  (0x40000060U 
                                                                   & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)))))
                                                         ? 2U
                                                         : 1U))
                                                       : 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? 
                                                       (0x0000007eU 
                                                        & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ireg) 
                                                           << 1U))
                                                        : 
                                                       (0x0000000fU 
                                                        & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ireg))))))
                                                    : 
                                                   ((0x00000200U 
                                                     & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                     ? 
                                                    ((0x00000400U 
                                                      & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                      ? 
                                                     ((0x00000800U 
                                                       & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                       ? 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__qreg)
                                                        : (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__areg))
                                                       : 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__acc)
                                                        : (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)))
                                                      : 
                                                     ((0x00000800U 
                                                       & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                       ? 
                                                      ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sreg) 
                                                       & (- (IData)(
                                                                    (1U 
                                                                     & (vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm 
                                                                        >> 0x0000000cU)))))
                                                       : 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ear2)
                                                        : (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ear1))))
                                                     : 
                                                    ((0x00000400U 
                                                      & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                      ? 
                                                     ((0x00000800U 
                                                       & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                       ? 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pc1)
                                                        : vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[6U])
                                                       : 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[5U]
                                                        : vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[4U]))
                                                      : 
                                                     ((0x00000800U 
                                                       & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                       ? 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[3U]
                                                        : vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[2U])
                                                       : 
                                                      ((0x00001000U 
                                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm)
                                                        ? vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[1U]
                                                        : vlSelfRef.__PVT__emu__DOT__cpu__DOT__r[0U]))))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_rc = (
                                                   ((((4U 
                                                       & ((((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw8_wa)) 
                                                            & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                                               >> 8U)) 
                                                           | ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_103) 
                                                              & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw8_wa))) 
                                                          << 2U)) 
                                                      | ((2U 
                                                          & ((((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa)) 
                                                               & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                                                  >> 7U)) 
                                                              | (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                                                  >> 7U) 
                                                                 & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa))) 
                                                             << 1U)) 
                                                         | (1U 
                                                            & (((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa)) 
                                                                & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                                                   >> 6U)) 
                                                               | (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                                                   >> 6U) 
                                                                  & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa)))))) 
                                                     << 6U) 
                                                    | (((2U 
                                                         & ((((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa)) 
                                                              & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                                                 >> 5U)) 
                                                             | (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                                                 >> 5U) 
                                                                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa))) 
                                                            << 1U)) 
                                                        | (1U 
                                                           & (((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pswt_wa)) 
                                                               & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                                                  >> 4U)) 
                                                              | (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                                                  >> 4U) 
                                                                 & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pswt_wa))))) 
                                                       << 4U)) 
                                                   | (((((((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                                           >> 3U) 
                                                          & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa)) 
                                                         | (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__cond_n) 
                                                             & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)) 
                                                            | ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_37) 
                                                               & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                                                  >> 3U)))) 
                                                        << 3U) 
                                                       | (((((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                                             >> 2U) 
                                                            & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa)) 
                                                           | (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__cond_z) 
                                                               & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20)) 
                                                              | ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_37) 
                                                                 & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                                                    >> 2U)))) 
                                                          << 2U)) 
                                                      | ((((((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                                             >> 1U) 
                                                            & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa)) 
                                                           | (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_20) 
                                                               & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__cond_v)) 
                                                              | ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_37) 
                                                                 & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                                                    >> 1U)))) 
                                                          << 1U) 
                                                         | (1U 
                                                            & (((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa)) 
                                                                & (((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pswc_stb)) 
                                                                    & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw)) 
                                                                   | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pswc_stb) 
                                                                      & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__cond_c)))) 
                                                               | ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_3) 
                                                                  & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa)))))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__tovf = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__tevent) 
                                                 | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__thang));
    vlSelfRef.__VdfgRegularize_hebeb780c_0_51 = ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sh_ci2)) 
                                                 & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__sh_cin));
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__9__KET__ 
        = ((IData)(__VdfgRegularize_hebeb780c_0_135) 
           & ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__tbit) 
              & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_142)));
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__7__KET__ 
        = ((IData)(__VdfgRegularize_hebeb780c_0_135) 
           & ((~ (IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__tbit)) 
              & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__halt)));
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__5__KET__ 
        = ((IData)(__VdfgRegularize_hebeb780c_0_35) 
           & ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__tbit) 
              & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wcpu) 
                 & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__halt)) 
                    & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__evnt_rq)))));
    __VdfgRegularize_hebeb780c_0_132 = ((IData)(__VdfgRegularize_hebeb780c_0_35) 
                                        & ((~ (IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__tbit)) 
                                           & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__halt))));
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__8__KET__ 
        = ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_36) 
           & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wcpu)) 
              & (IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__tbit)));
    __VdfgRegularize_hebeb780c_0_14 = (1U & ((~ (IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__tbit)) 
                                             & (~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wcpu))));
    __PVT__emu__DOT__cpu__DOT__alu_inx = (0x0000ffffU 
                                          & (((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__x)) 
                                              & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_b)))) 
                                             | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__x) 
                                                & (- (IData)(
                                                             ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_b)) 
                                                              & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm14m) 
                                                                 | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm13m))))))));
    __PVT__emu__DOT__cpu__DOT__alu_iny = (0x0000ffffU 
                                          & (((~ (IData)(__PVT__emu__DOT__cpu__DOT__y)) 
                                              & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_d)))) 
                                             | ((IData)(__PVT__emu__DOT__cpu__DOT__y) 
                                                & (- (IData)(
                                                             (1U 
                                                              & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_d)) 
                                                                 & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm14m)) 
                                                                    | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm13m)))))))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__cpsw_stb = 
        ((~ (3U == (3U & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_rc) 
                          >> 7U)))) & (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_pswr) 
                                        & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_wdone)) 
                                       | ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_pswr)) 
                                          & (((~ (vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm 
                                                  >> 8U)) 
                                              & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_wa)) 
                                             | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw_stb)))));
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__3__KET__ 
        = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__evnt_rq) 
           & (IData)(__VdfgRegularize_hebeb780c_0_132));
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__12__KET__ 
        = ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__tbit) 
           & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__dc_rtt) 
              & (IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__8__KET__)));
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__13__KET__ 
        = ((IData)(__VdfgRegularize_hebeb780c_0_136) 
           & (IData)(__VdfgRegularize_hebeb780c_0_14));
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__11__KET__ 
        = ((IData)(__VdfgRegularize_hebeb780c_0_134) 
           & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__halt) 
              & (IData)(__VdfgRegularize_hebeb780c_0_14)));
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__4__KET__ 
        = ((IData)(__VdfgRegularize_hebeb780c_0_133) 
           & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__halt)) 
              & (IData)(__VdfgRegularize_hebeb780c_0_14)));
    __PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__14__KET__ 
        = ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5) 
           & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_131) 
              & (IData)(__VdfgRegularize_hebeb780c_0_14)));
    __PVT__emu__DOT__cpu__DOT__alu_or = (((IData)(__PVT__emu__DOT__cpu__DOT__alu_inx) 
                                          | (IData)(__PVT__emu__DOT__cpu__DOT__alu_iny)) 
                                         & (- (IData)(
                                                      (1U 
                                                       & (~ 
                                                          (vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm 
                                                           >> 0x0000000fU))))));
    __PVT__emu__DOT__cpu__DOT__alu_an = ((IData)(__PVT__emu__DOT__cpu__DOT__alu_inx) 
                                         & ((- (IData)(
                                                       (1U 
                                                        & (~ 
                                                           (vlSelfRef.__PVT__emu__DOT__cpu__DOT__plm 
                                                            >> 0x00000010U))))) 
                                            & (IData)(__PVT__emu__DOT__cpu__DOT__alu_iny)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli = (0x000003ffU 
                                                & (~ 
                                                   (((((((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__5__KET__) 
                                                         | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__3__KET__) 
                                                            | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_34))) 
                                                        << 4U) 
                                                       | ((((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__6__KET__) 
                                                            | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__5__KET__) 
                                                               | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__3__KET__) 
                                                                  | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__0__KET__) 
                                                                     | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__2__KET__))))) 
                                                           << 3U) 
                                                          | (((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__9__KET__) 
                                                              | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__8__KET__) 
                                                                 | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__7__KET__) 
                                                                    | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__5__KET__) 
                                                                       | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__1__KET__) 
                                                                          | (IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__3__KET__)))))) 
                                                             << 2U))) 
                                                      | ((((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_140) 
                                                           | (((~ (IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__tbit)) 
                                                               & (IData)(__VdfgRegularize_hebeb780c_0_137)) 
                                                              | (((IData)(__VdfgRegularize_hebeb780c_0_137) 
                                                                  & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wcpu) 
                                                                     & (IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__tbit))) 
                                                                 | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_34)))) 
                                                          << 1U) 
                                                         | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__9__KET__) 
                                                            | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__7__KET__) 
                                                               | ((((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__psw) 
                                                                    >> 8U) 
                                                                   & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__0__KET__)) 
                                                                  | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_129)))))) 
                                                     << 5U) 
                                                    | (((((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__14__KET__) 
                                                          | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__13__KET__) 
                                                             | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__12__KET__) 
                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__11__KET__) 
                                                                   | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__10__KET__) 
                                                                      | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__4__KET__) 
                                                                         | (((IData)(__VdfgRegularize_hebeb780c_0_134) 
                                                                             & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_142)) 
                                                                            | (((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_5) 
                                                                                & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_131) 
                                                                                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wcpu))) 
                                                                               | (((IData)(__VdfgRegularize_hebeb780c_0_133) 
                                                                                & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__halt)) 
                                                                                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wcpu))) 
                                                                                | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wcpu) 
                                                                                & (IData)(__VdfgRegularize_hebeb780c_0_136))))))))))) 
                                                         << 4U) 
                                                        | (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__10__KET__) 
                                                            << 3U) 
                                                           | (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__0__KET__) 
                                                               | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_129)) 
                                                              << 2U))) 
                                                       | ((((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__14__KET__) 
                                                            | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__13__KET__) 
                                                               | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__12__KET__) 
                                                                  | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__11__KET__) 
                                                                     | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__1__KET__) 
                                                                        | (((IData)(__VdfgRegularize_hebeb780c_0_35) 
                                                                            & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wcpu) 
                                                                               & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__halt)) 
                                                                                & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_130)))) 
                                                                           | (((IData)(__VdfgRegularize_hebeb780c_0_132) 
                                                                               & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_130)) 
                                                                              | (IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__4__KET__)))))))) 
                                                           << 1U) 
                                                          | ((IData)(__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__8__KET__) 
                                                             | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli_matrix__DOT__p__BRA__2__KET__) 
                                                                | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_34))))))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cf = (
                                                   (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g))) 
                                                   & ((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                      | (((0x0000fffeU 
                                                           & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                   & ((0x00007ffeU 
                                                                       & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                            | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                               & ((0x00003ffeU 
                                                                                & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & ((0x00001ffeU 
                                                                                & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & ((0x00000ffeU 
                                                                                & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & ((0x000007feU 
                                                                                & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & ((0x000003feU 
                                                                                & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & ((0x000001feU 
                                                                                & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & ((0x000000feU 
                                                                                & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & ((0x0000007eU 
                                                                                & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & ((0x0000003eU 
                                                                                & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & ((0x0000001eU 
                                                                                & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & ((0x0000000eU 
                                                                                & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & ((6U 
                                                                                & ((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & (((((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                                                | ((IData)(__PVT__emu__DOT__cpu__DOT__alu_or) 
                                                                                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin))) 
                                                                                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                                & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                                << 1U)) 
                                                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                                           & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                                          << 1U)) 
                                                                      | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)))) 
                                                               & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_g)))) 
                                                              << 1U)) 
                                                          | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)) 
                                                         & (IData)(__PVT__emu__DOT__cpu__DOT__alu_or))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_af = ((IData)(__PVT__emu__DOT__cpu__DOT__alu_an) 
                                                   ^ 
                                                   (((0x0000fffeU 
                                                      & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cf) 
                                                         << 1U)) 
                                                     | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_cin)) 
                                                    ^ (IData)(__PVT__emu__DOT__cpu__DOT__alu_or)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_mxin = 
        (1U & (~ ((((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__acc) 
                    ^ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_af)) 
                   >> 0x0000000fU) | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_shl))));
}

void Vsim_top_sim_top___nba_comb__TOP__sim_top__1(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_comb__TOP__sim_top__1\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__reset = (1U 
                                                  & ((~ 
                                                      ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rst__DOT__powerup) 
                                                       >> 4U)) 
                                                     | ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ac0)) 
                                                        & (~ 
                                                           (3U 
                                                            == 
                                                            (3U 
                                                             & ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rst__DOT__powerup) 
                                                                >> 3U)))))));
    vlSelfRef.__PVT__emu__DOT__vm_init = (1U & ((~ 
                                                 ((IData)(vlSelfRef.__PVT__emu__DOT__sys__DOT__rst__DOT__powerup) 
                                                  >> 4U)) 
                                                | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__init_out)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__na_rc__BRA__0__KET__ 
        = (1U & ((~ ((IData)((vlSelfRef.__PVT__emu__DOT__cpu__DOT__pla 
                              >> 0x0000001fU)) | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__abort))) 
                 | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__reset)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__set_cend_rc 
        = (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_stb) 
            & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__na_rc__BRA__0__KET__)) 
           & (0x0000000002000000ULL == (0x0000000006000000ULL 
                                        & vlSelfRef.__PVT__emu__DOT__cpu__DOT__pla)));
}

void Vsim_top_sim_top___nba_comb__TOP__sim_top__2(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_comb__TOP__sim_top__2\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__SDRAM_DQ = (((IData)(vlSymsp->TOP__sim_top__sdram.__PVT__dout) 
                                  & (- (IData)((IData)(vlSymsp->TOP__sim_top__sdram.__PVT__drive)))) 
                                 | ((IData)(vlSelfRef.__PVT__emu__DOT__mem__DOT__sdram__DOT__dq_out) 
                                    & (- (IData)((IData)(vlSelfRef.__PVT__emu__DOT__mem__DOT__sdram__DOT__dq_oe)))));
}

void Vsim_top_sim_top___nba_sequent__TOP__sim_top__8(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_sequent__TOP__sim_top__8\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res) 
          | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__to_block)) 
         | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_sta))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__adr_req = 0U;
    } else if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__wra) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__adr_req = 1U;
    }
    if (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__1__KET__) 
         & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_rcd1_xt))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__3__KET__ = 1U;
    } else if ((1U & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_rcd1_xt)) 
                      | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__0__KET__)))) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__3__KET__ = 0U;
    }
}

void Vsim_top_sim_top___nba_comb__TOP__sim_top__3(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_comb__TOP__sim_top__3\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__attached = 
        (1U & ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__mounted) 
               >> (1U & ((IData)(vlSelfRef.__PVT__emu__DOT__fdc_params) 
                         >> 2U))));
    vlSelfRef.__PVT__emu__DOT__fdc__DOT__b_wr = ((IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__sd_busy) 
                                                 & ((IData)(vlSymsp->TOP.sd_buff_wr) 
                                                    & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__fdc__DOT__xfer_we)) 
                                                       & (0U 
                                                          != (IData)(vlSymsp->TOP.sd_ack)))));
}

void Vsim_top_sim_top___nba_sequent__TOP__sim_top__9(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_sequent__TOP__sim_top__9\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v0) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__buf_hi__DOT__mem[vlSelfRef.__VdlyDim0__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v0] 
            = vlSelfRef.__VdlyVal__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v0;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v1) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__buf_hi__DOT__mem[vlSelfRef.__VdlyDim0__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v1] 
            = vlSelfRef.__VdlyVal__emu__DOT__fdc__DOT__buf_hi__DOT__mem__v1;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v0) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__buf_lo__DOT__mem[vlSelfRef.__VdlyDim0__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v0] 
            = vlSelfRef.__VdlyVal__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v0;
    }
    if (vlSelfRef.__VdlySet__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v1) {
        vlSelfRef.__PVT__emu__DOT__fdc__DOT__buf_lo__DOT__mem[vlSelfRef.__VdlyDim0__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v1] 
            = vlSelfRef.__VdlyVal__emu__DOT__fdc__DOT__buf_lo__DOT__mem__v1;
    }
}

void Vsim_top_sim_top___nba_comb__TOP__sim_top__4(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_comb__TOP__sim_top__4\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__rcmd_set = 
        ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__thang) 
         | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__buf_res) 
            & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__4__KET__)));
}

void Vsim_top_sim_top___nba_comb__TOP__sim_top__5(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_comb__TOP__sim_top__5\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__tena = ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__reset)) 
                                                 & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__pli_nrdy) 
                                                    | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_stb) 
                                                       | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_iak))));
}

void Vsim_top_sim_top___nba_comb__TOP__sim_top__6(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_comb__TOP__sim_top__6\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__to_block = 
        ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__thang) 
         | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__5__KET__) 
            & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_rcd1)));
}

void Vsim_top_sim_top___nba_comb__TOP__sim_top__7(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_comb__TOP__sim_top__7\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__abort) 
                                                   | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__reset));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__na_rc__BRA__1__KET__ 
        = (1U & ((~ (IData)((vlSelfRef.__PVT__emu__DOT__cpu__DOT__pla 
                             >> 0x00000020U))) | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res)));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy0_set 
        = (((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__1__KET__)) 
            & (((vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_f 
                 >> 1U) & (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_145)) 
               | ((vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_f 
                   >> 4U) & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_div)))) 
           | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res));
}

void Vsim_top_sim_top___nba_comb__TOP__sim_top__8(Vsim_top_sim_top* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      Vsim_top_sim_top___nba_comb__TOP__sim_top__8\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__bra_req = 
        ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__br_ready) 
         & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__cmd_nrdy) 
            | ((~ ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ir_stb) 
                   | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res))) 
               & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__set_cend_rc))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_done = 
        ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__mc_res) 
         | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_idone) 
            | (((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wr_xt)) 
                & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_rdone)) 
               | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_wdone))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_rdy = (
                                                   ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy0) 
                                                    | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy0_set)) 
                                                   & ((~ 
                                                       ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_trdy1) 
                                                        & ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ireg) 
                                                           >> 0x0000000aU))) 
                                                      | vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_f));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_wr = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__0__KET__) 
                                                   & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ea_rdy));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__ra_wx = ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ra_fr) 
                                                  & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_wr));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__wra = (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ra_wx) 
                                                 | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__ra_wa)) 
                                                & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__to_block)) 
                                                   & (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__dc_iord) 
                                                       | ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_x001)) 
                                                          | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__dc_iowr))) 
                                                      & ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_150) 
                                                         | ((IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_149) 
                                                            | (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_38))))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_start = 
        (((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__alu_st__BRA__1__KET__) 
          & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_una)) 
         | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wra));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_stb = 
        (((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_st__BRA__1__KET__)) 
          & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_start)) 
         | ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_st__BRA__2__KET__) 
            & ((~ (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_st__BRA__3__KET__)) 
               & (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_st__BRA__5__KET__))));
    vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_start = 
        ((IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__wb_swait) 
         | (IData)(vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_stb));
    if (vlSelfRef.__PVT__emu__DOT__cpu__DOT__iop_stb) {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_ia 
            = (0x0fU == (IData)(vlSelfRef.__VdfgRegularize_hebeb780c_0_2));
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_ua 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_sel;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wr 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__io_wr;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_rd 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_rd_rc;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wo 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wo_rc;
    } else {
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_ia 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_ia_xt;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_ua 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_ua_xt;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wr 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wr_xt;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_rd 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_rd_xt;
        vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wo 
            = vlSelfRef.__PVT__emu__DOT__cpu__DOT__wio_wo_xt;
    }
}
