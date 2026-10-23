// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsim_top.h for the primary calling header

#include "Vsim_top__pch.h"

VL_ATTR_COLD void Vsim_top_sim_top___eval_static__TOP__sim_top(Vsim_top_sim_top* vlSelf);
VL_ATTR_COLD void Vsim_top_sdram_model___eval_static__TOP__sim_top__sdram(Vsim_top_sdram_model* vlSelf);

VL_ATTR_COLD void Vsim_top___024root___eval_static(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_static\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsim_top_sim_top___eval_static__TOP__sim_top((&vlSymsp->TOP__sim_top));
    Vsim_top_sdram_model___eval_static__TOP__sim_top__sdram((&vlSymsp->TOP__sim_top__sdram));
    vlSelfRef.__Vtrigprevexpr___TOP__CLK_50M__0 = vlSelfRef.CLK_50M;
    vlSelfRef.__Vtrigprevexpr___TOP__RESET__0 = vlSelfRef.RESET;
    vlSelfRef.__Vtrigprevexpr___TOP__ps2_key__0 = vlSelfRef.ps2_key;
    vlSelfRef.__Vtrigprevexpr___TOP__ps2_mouse__0 = vlSelfRef.ps2_mouse;
    vlSelfRef.__Vtrigprevexpr___TOP__img_mounted__0 
        = vlSelfRef.img_mounted;
    vlSelfRef.__Vtrigprevexpr___TOP__img_size__0 = vlSelfRef.img_size;
    vlSelfRef.__Vtrigprevexpr___TOP__sd_ack__0 = vlSelfRef.sd_ack;
    vlSelfRef.__Vtrigprevexpr___TOP__sd_buff_addr__0 
        = vlSelfRef.sd_buff_addr;
    vlSelfRef.__Vtrigprevexpr___TOP__sd_buff_dout__0 
        = vlSelfRef.sd_buff_dout;
    vlSelfRef.__Vtrigprevexpr___TOP__sd_buff_wr__0 
        = vlSelfRef.sd_buff_wr;
    vlSelfRef.__Vtrigprevexpr___TOP__sim_top____PVT__emu__DOT__clk_cpu__0 = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__CLK_50M__1 = vlSelfRef.CLK_50M;
    vlSelfRef.__Vtrigprevexpr_hf7916eec__0 = 1U;
    vlSelfRef.__Vtrigprevexpr___TOP__sim_top____PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__3__KET____0 
        = vlSymsp->TOP__sim_top.__PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__3__KET__;
}

VL_ATTR_COLD void Vsim_top_sim_top___eval_initial__TOP__sim_top(Vsim_top_sim_top* vlSelf);

VL_ATTR_COLD void Vsim_top___024root___eval_initial(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_initial\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vsim_top_sim_top___eval_initial__TOP__sim_top((&vlSymsp->TOP__sim_top));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vsim_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vsim_top_sim_top___stl_sequent__TOP__sim_top__0(Vsim_top_sim_top* vlSelf);
void Vsim_top_sdram_model___nba_comb__TOP__sim_top__sdram__0(Vsim_top_sdram_model* vlSelf);

VL_ATTR_COLD bool Vsim_top___024root___eval_stl(Vsim_top___024root* vlSelf, CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_stl\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vsim_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vsim_top___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
                {
                    // Inlined CFunc: _stl_sequent__TOP__0
                    vlSelfRef.LED_USER = vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc_int;
                    vlSelfRef.AUDIO_R = vlSymsp->TOP__sim_top.__PVT__emu__DOT__audio;
                    vlSelfRef.AUDIO_L = vlSymsp->TOP__sim_top.__PVT__emu__DOT__audio;
                    vlSelfRef.VGA_DE = vlSymsp->TOP__sim_top.VGA_DE;
                    vlSelfRef.VGA_VS = vlSymsp->TOP__sim_top.VGA_VS;
                    vlSelfRef.VGA_HS = vlSymsp->TOP__sim_top.VGA_HS;
                    vlSelfRef.VGA_B = vlSymsp->TOP__sim_top.VGA_B;
                    vlSelfRef.VGA_G = vlSymsp->TOP__sim_top.VGA_G;
                    vlSelfRef.VGA_R = vlSymsp->TOP__sim_top.VGA_R;
                    vlSelfRef.CE_PIXEL = vlSymsp->TOP__sim_top.CE_PIXEL;
                    vlSelfRef.sd_buff_din = vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc_buff_din;
                    vlSelfRef.sd_lba = vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc__DOT__xfer_lba;
                    vlSelfRef.sd_wr = (((4U & (IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc_params))
                                         ? 2U : 1U) 
                                       & (- (IData)((IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc__DOT__sd_req_wr))));
                    vlSelfRef.sd_rd = ((- (IData)((IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc__DOT__sd_req_rd))) 
                                       & ((4U & (IData)(vlSymsp->TOP__sim_top.__PVT__emu__DOT__fdc_params))
                                           ? 2U : 1U));
                }
                Vsim_top_sim_top___stl_sequent__TOP__sim_top__0((&vlSymsp->TOP__sim_top));
                Vsim_top_sdram_model___nba_comb__TOP__sim_top__sdram__0((&vlSymsp->TOP__sim_top__sdram));
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vsim_top___024root___eval_dump_triggers__stl(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_dump_triggers__stl\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vsim_top___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsim_top___024root___eval_dump_triggers__ico(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_dump_triggers__ico\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vsim_top___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsim_top___024root___eval_dump_triggers__act(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_dump_triggers__act\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vsim_top___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vsim_top___024root___eval_dump_triggers__nba(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_dump_triggers__nba\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vsim_top___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vsim_top___024root___eval_dump_triggers__obs(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_dump_triggers__obs\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vsim_top___024root___eval_dump_triggers__react(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_dump_triggers__react\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vsim_top___024root___eval_final(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___eval_final\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vsim_top___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vsim_top___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___trigger_anySet__stl\n"); );
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

bool Vsim_top___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 2> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(Vsim_top___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( CLK_50M)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( RESET)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( ps2_key)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( ps2_mouse)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @( img_mounted)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @( img_size)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 6U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 6 is active: @( sd_ack)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 7U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 7 is active: @( sd_buff_addr)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 8U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 8 is active: @( sd_buff_dout)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 9U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 9 is active: @( sd_buff_wr)\n");
    }
    if ((1U & (IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vsim_top___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vsim_top___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge sim_top.emu.clk_cpu)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge CLK_50M)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(posedge sim_top.emu.cpu_reset_s[1])\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(negedge sim_top.emu.clk_cpu)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @(negedge sim_top.emu.cpu.iocmd_st[3])\n");
    }
    if ((1U & (IData)((triggers[0U] >> 5U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 5 is active: @(negedge CLK_50M)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vsim_top___024root___ctor_var_reset(Vsim_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsim_top___024root___ctor_var_reset\n"); );
    Vsim_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->CLK_50M = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11947538796484961521ull);
    vlSelf->RESET = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5415920568641164577ull);
    vlSelf->ps2_key = VL_SCOPED_RAND_RESET_I(11, __VscopeHash, 11330952063172673235ull);
    vlSelf->ps2_mouse = VL_SCOPED_RAND_RESET_I(25, __VscopeHash, 7966832717985307938ull);
    vlSelf->img_mounted = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7899656893000756925ull);
    vlSelf->img_size = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6124065141836779697ull);
    vlSelf->sd_lba = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7165698058624058577ull);
    vlSelf->sd_rd = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7791587886048458278ull);
    vlSelf->sd_wr = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7299549130114028831ull);
    vlSelf->sd_ack = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9837628613120359464ull);
    vlSelf->sd_buff_addr = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2271695569605748135ull);
    vlSelf->sd_buff_dout = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 9965866996333852648ull);
    vlSelf->sd_buff_din = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16344143758680466184ull);
    vlSelf->sd_buff_wr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4301658548683351820ull);
    vlSelf->CE_PIXEL = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11316549464966722680ull);
    vlSelf->VGA_R = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8713651417395270250ull);
    vlSelf->VGA_G = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2930052969200674513ull);
    vlSelf->VGA_B = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18057832749456581997ull);
    vlSelf->VGA_HS = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3953739287931852003ull);
    vlSelf->VGA_VS = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14802786966247625123ull);
    vlSelf->VGA_DE = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14654138865792612532ull);
    vlSelf->AUDIO_L = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 12828991824685735322ull);
    vlSelf->AUDIO_R = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 18438569505873599472ull);
    vlSelf->LED_USER = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13537948858535583566ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__VicoTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__CLK_50M__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__RESET__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ps2_key__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ps2_mouse__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__img_mounted__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__img_size__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__sd_ack__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__sd_buff_addr__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__sd_buff_dout__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__sd_buff_wr__0 = 0;
    vlSelf->__VicoDidInit = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__sim_top____PVT__emu__DOT__clk_cpu__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__CLK_50M__1 = 0;
    vlSelf->__Vtrigprevexpr_hf7916eec__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__sim_top____PVT__emu__DOT__cpu__DOT__iocmd_st__BRA__3__KET____0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
