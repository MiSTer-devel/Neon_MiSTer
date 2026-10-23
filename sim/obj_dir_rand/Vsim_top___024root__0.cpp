// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "Vsim_top__pch.h"

void Vsim_top___024root___eval_sample(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_sample\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG
bool Vsim_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);
void Vsim_top_sim_top___ico_sequent__TOP__sim_top__0(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___ico_sequent__TOP__sim_top__1(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___ico_sequent__TOP__sim_top__2(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___ico_comb__TOP__sim_top__0(Vsim_top_sim_top* vlSelf);

bool Vsim_top___024root___eval_ico(Vsim_top___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_ico\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (IData)((IData)(firstIteration)));
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (QData)((IData)(
                                                        (((((IData)(vlSelfRef.sd_buff_wr) 
                                                            != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sd_buff_wr__0)) 
                                                           << 9U) 
                                                          | (((IData)(vlSelfRef.sd_buff_dout) 
                                                              != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sd_buff_dout__0)) 
                                                             << 8U)) 
                                                         | (((((((IData)(vlSelfRef.sd_buff_addr) 
                                                                 != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sd_buff_addr__0)) 
                                                                << 3U) 
                                                               | (((IData)(vlSelfRef.sd_ack) 
                                                                   != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sd_ack__0)) 
                                                                  << 2U)) 
                                                              | (((vlSelfRef.img_size 
                                                                   != vlSelfRef.__Vtrigprevexpr___TOP__img_size__0) 
                                                                  << 1U) 
                                                                 | ((IData)(vlSelfRef.img_mounted) 
                                                                    != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__img_mounted__0)))) 
                                                             << 4U) 
                                                            | ((((vlSelfRef.ps2_mouse 
                                                                  != vlSelfRef.__Vtrigprevexpr___TOP__ps2_mouse__0) 
                                                                 << 3U) 
                                                                | (((IData)(vlSelfRef.ps2_key) 
                                                                    != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ps2_key__0)) 
                                                                   << 2U)) 
                                                               | ((((IData)(vlSelfRef.RESET) 
                                                                    != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__RESET__0)) 
                                                                   << 1U) 
                                                                  | ((IData)(vlSelfRef.CLK_50M) 
                                                                     != (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CLK_50M__0))))))));
        vlSelfRef.__Vtrigprevexpr___TOP__CLK_50M__0 
            = vlSelfRef.CLK_50M;
        vlSelfRef.__Vtrigprevexpr___TOP__RESET__0 = vlSelfRef.RESET;
        vlSelfRef.__Vtrigprevexpr___TOP__ps2_key__0 
            = vlSelfRef.ps2_key;
        vlSelfRef.__Vtrigprevexpr___TOP__ps2_mouse__0 
            = vlSelfRef.ps2_mouse;
        vlSelfRef.__Vtrigprevexpr___TOP__img_mounted__0 
            = vlSelfRef.img_mounted;
        vlSelfRef.__Vtrigprevexpr___TOP__img_size__0 
            = vlSelfRef.img_size;
        vlSelfRef.__Vtrigprevexpr___TOP__sd_ack__0 
            = vlSelfRef.sd_ack;
        vlSelfRef.__Vtrigprevexpr___TOP__sd_buff_addr__0 
            = vlSelfRef.sd_buff_addr;
        vlSelfRef.__Vtrigprevexpr___TOP__sd_buff_dout__0 
            = vlSelfRef.sd_buff_dout;
        vlSelfRef.__Vtrigprevexpr___TOP__sd_buff_wr__0 
            = vlSelfRef.sd_buff_wr;
        if (VL_UNLIKELY(((1U & (~ (IData)(vlSelfRef.__VicoDidInit)))))) {
            vlSelfRef.__VicoDidInit = 1U;
            vlSelfRef.__VicoTriggered[0U] = (1ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (2ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (4ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (8ULL | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (0x0000000000000010ULL 
                                             | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (0x0000000000000020ULL 
                                             | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (0x0000000000000040ULL 
                                             | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (0x0000000000000080ULL 
                                             | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (0x0000000000000100ULL 
                                             | vlSelfRef.__VicoTriggered[0U]);
            vlSelfRef.__VicoTriggered[0U] = (0x0000000000000200ULL 
                                             | vlSelfRef.__VicoTriggered[0U]);
        }
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsim_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vsim_top___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_body__ico
            if ((4ULL & vlSelfRef.__VicoTriggered[0U])) {
                Vsim_top_sim_top___ico_sequent__TOP__sim_top__0((&vlSymsp->TOP__sim_top));
            }
            if ((0x0000000000000080ULL & vlSelfRef.__VicoTriggered[0U])) {
                Vsim_top_sim_top___ico_sequent__TOP__sim_top__1((&vlSymsp->TOP__sim_top));
            }
            if ((2ULL & vlSelfRef.__VicoTriggered[0U])) {
                Vsim_top_sim_top___ico_sequent__TOP__sim_top__2((&vlSymsp->TOP__sim_top));
            }
            if ((0x0000000000000240ULL & vlSelfRef.__VicoTriggered[0U])) {
                Vsim_top_sim_top___ico_comb__TOP__sim_top__0((&vlSymsp->TOP__sim_top));
            }
        }
    }
    return (__VicoExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
void Vsim_top___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in);

bool Vsim_top___024root___eval_act(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_act\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                        (((((~ (IData)(vlSelfRef.CLK_50M)) 
                                                            & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CLK_50M__1)) 
                                                           << 5U) 
                                                          | (((~ (IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__3__KET__)) 
                                                              & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sim_top____PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__3__KET____0)) 
                                                             << 4U)) 
                                                         | (((((~ (IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__clk_cpu)) 
                                                               & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sim_top____PVT__emu__DOT__clk_cpu__0)) 
                                                              << 3U) 
                                                             | ((IData)(
                                                                        (((IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__cpu_reset_s) 
                                                                          >> 1U) 
                                                                         & (~ (IData)(vlSelfRef.__Vtrigprevexpr_hf7916eec__0)))) 
                                                                << 2U)) 
                                                            | ((((IData)(vlSelfRef.CLK_50M) 
                                                                 & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CLK_50M__1))) 
                                                                << 1U) 
                                                               | ((IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__clk_cpu) 
                                                                  & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__sim_top____PVT__emu__DOT__clk_cpu__0))))))));
        vlSelfRef.__Vtrigprevexpr___TOP__sim_top____PVT__emu__DOT__clk_cpu__0 
            = vlSymsp->TOP__sim_top.__PVT__emu__DOT__clk_cpu;
        vlSelfRef.__Vtrigprevexpr___TOP__CLK_50M__1 
            = vlSelfRef.CLK_50M;
        vlSelfRef.__Vtrigprevexpr_hf7916eec__0 = (1U 
                                                  & ((IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__cpu_reset_s) 
                                                     >> 1U));
        vlSelfRef.__Vtrigprevexpr___TOP__sim_top____PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__3__KET____0 
            = vlSymsp->TOP__sim_top.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__3__KET__;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsim_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vsim_top___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

bool Vsim_top___024root___eval_inact(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_inact\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vsim_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);
void Vsim_top___024root___eval_body__nba(Vsim_top___024root* vlSelf);
void Vsim_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out);

bool Vsim_top___024root___eval_nba(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_nba\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vsim_top___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vsim_top___024root___eval_body__nba(vlSelf);
        Vsim_top___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vsim_top___024root___eval_obs(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_obs\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vsim_top___024root___eval_react(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_react\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vsim_top___024root___eval_postponed(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_postponed\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vsim_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___trigger_anySet__ico\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

bool Vsim_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vsim_top_sim_top___nba_sequent__TOP__sim_top__0(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_sequent__TOP__sim_top__1(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_sequent__TOP__sim_top__2(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_sequent__TOP__sim_top__3(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_sequent__TOP__sim_top__4(Vsim_top_sim_top* vlSelf);
void Vsim_top_sdram_model___nba_sequent__TOP__sim_top__sdram__0(Vsim_top_sdram_model* vlSelf);
void Vsim_top_sim_top___nba_sequent__TOP__sim_top__5(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_sequent__TOP__sim_top__6(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_sequent__TOP__sim_top__7(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_comb__TOP__sim_top__0(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_comb__TOP__sim_top__1(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_comb__TOP__sim_top__2(Vsim_top_sim_top* vlSelf);
void Vsim_top_sdram_model___nba_comb__TOP__sim_top__sdram__0(Vsim_top_sdram_model* vlSelf);
void Vsim_top_sim_top___nba_sequent__TOP__sim_top__8(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_comb__TOP__sim_top__3(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_sequent__TOP__sim_top__9(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_comb__TOP__sim_top__4(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_comb__TOP__sim_top__5(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_comb__TOP__sim_top__6(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_comb__TOP__sim_top__7(Vsim_top_sim_top* vlSelf);
void Vsim_top_sim_top___nba_comb__TOP__sim_top__8(Vsim_top_sim_top* vlSelf);

void Vsim_top___024root___eval_body__nba(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_body__nba\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_sequent__TOP__sim_top__0((&vlSymsp->TOP__sim_top));
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_sequent__TOP__sim_top__1((&vlSymsp->TOP__sim_top));
        {
            // Inlined CFunc: _nba_sequent__TOP__0
            vlSelfRef.AUDIO_R = vlSymsp->TOP__sim_top.__PVT__emu__DOT__audio;
            vlSelfRef.AUDIO_L = vlSymsp->TOP__sim_top.__PVT__emu__DOT__audio;
            vlSelfRef.sd_buff_din = vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc_buff_din;
            vlSelfRef.VGA_VS = vlSymsp->TOP__sim_top.VGA_VS;
            vlSelfRef.VGA_HS = vlSymsp->TOP__sim_top.VGA_HS;
            vlSelfRef.VGA_B = vlSymsp->TOP__sim_top.VGA_B;
            vlSelfRef.VGA_R = vlSymsp->TOP__sim_top.VGA_R;
            vlSelfRef.VGA_G = vlSymsp->TOP__sim_top.VGA_G;
            vlSelfRef.CE_PIXEL = vlSymsp->TOP__sim_top.CE_PIXEL;
            vlSelfRef.VGA_DE = vlSymsp->TOP__sim_top.VGA_DE;
        }
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_sequent__TOP__sim_top__2((&vlSymsp->TOP__sim_top));
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_sequent__TOP__sim_top__3((&vlSymsp->TOP__sim_top));
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_sequent__TOP__sim_top__4((&vlSymsp->TOP__sim_top));
    }
    if ((0x0000000000000020ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sdram_model___nba_sequent__TOP__sim_top__sdram__0((&vlSymsp->TOP__sim_top__sdram));
    }
    if ((0x0000000000000018ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_sequent__TOP__sim_top__5((&vlSymsp->TOP__sim_top));
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_sequent__TOP__sim_top__6((&vlSymsp->TOP__sim_top));
        {
            // Inlined CFunc: _nba_sequent__TOP__1
            vlSelfRef.LED_USER = vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc_int;
            vlSelfRef.sd_lba = vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc__DOT__xfer_lba;
        }
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_sequent__TOP__sim_top__7((&vlSymsp->TOP__sim_top));
    }
    if ((9ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_comb__TOP__sim_top__0((&vlSymsp->TOP__sim_top));
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_comb__TOP__sim_top__1((&vlSymsp->TOP__sim_top));
    }
    if ((0x0000000000000022ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_comb__TOP__sim_top__2((&vlSymsp->TOP__sim_top));
        Vsim_top_sdram_model___nba_comb__TOP__sim_top__sdram__0((&vlSymsp->TOP__sim_top__sdram));
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_sequent__TOP__sim_top__8((&vlSymsp->TOP__sim_top));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        {
            // Inlined CFunc: _nba_comb__TOP__0
            vlSelfRef.sd_wr = (((4U & (IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc_params))
                                 ? 2U : 1U) & (- (IData)((IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc__DOT__sd_req_wr))));
            vlSelfRef.sd_rd = ((- (IData)((IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc__DOT__sd_req_rd))) 
                               & ((4U & (IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc_params))
                                   ? 2U : 1U));
        }
        Vsim_top_sim_top___nba_comb__TOP__sim_top__3((&vlSymsp->TOP__sim_top));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_sequent__TOP__sim_top__9((&vlSymsp->TOP__sim_top));
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___ico_sequent__TOP__sim_top__1((&vlSymsp->TOP__sim_top));
    }
    if ((0x0000000000000019ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_comb__TOP__sim_top__4((&vlSymsp->TOP__sim_top));
    }
    if ((0x000000000000000dULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_comb__TOP__sim_top__5((&vlSymsp->TOP__sim_top));
    }
    if ((9ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_comb__TOP__sim_top__6((&vlSymsp->TOP__sim_top));
    }
    if ((5ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_comb__TOP__sim_top__7((&vlSymsp->TOP__sim_top));
    }
    if ((0x000000000000000dULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vsim_top_sim_top___nba_comb__TOP__sim_top__8((&vlSymsp->TOP__sim_top));
    }
}

void Vsim_top___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

void Vsim_top___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

#ifdef VL_DEBUG
void Vsim_top___024root___eval_debug_assertions(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_debug_assertions\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.CLK_50M & 0xfeU)))) {
        Verilated::overWidthError("CLK_50M");
    }
    if (VL_UNLIKELY(((vlSelfRef.RESET & 0xfeU)))) {
        Verilated::overWidthError("RESET");
    }
    if (VL_UNLIKELY(((vlSelfRef.ps2_key & 0xf800U)))) {
        Verilated::overWidthError("ps2_key");
    }
    if (VL_UNLIKELY(((vlSelfRef.ps2_mouse & 0xfe000000U)))) {
        Verilated::overWidthError("ps2_mouse");
    }
    if (VL_UNLIKELY(((vlSelfRef.img_mounted & 0xfcU)))) {
        Verilated::overWidthError("img_mounted");
    }
    if (VL_UNLIKELY(((vlSelfRef.sd_ack & 0xfcU)))) {
        Verilated::overWidthError("sd_ack");
    }
    if (VL_UNLIKELY(((vlSelfRef.sd_buff_wr & 0xfeU)))) {
        Verilated::overWidthError("sd_buff_wr");
    }
}
#endif  // VL_DEBUG
