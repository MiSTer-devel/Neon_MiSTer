// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vsim_top__pch.h"

//============================================================
// Constructors

Vsim_top::Vsim_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vsim_top__Syms(contextp(), _vcname__, this)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , CLK_50M{vlSymsp->TOP.CLK_50M}
    , RESET{vlSymsp->TOP.RESET}
    , img_mounted{vlSymsp->TOP.img_mounted}
    , sd_rd{vlSymsp->TOP.sd_rd}
    , sd_wr{vlSymsp->TOP.sd_wr}
    , sd_ack{vlSymsp->TOP.sd_ack}
    , sd_buff_addr{vlSymsp->TOP.sd_buff_addr}
    , sd_buff_wr{vlSymsp->TOP.sd_buff_wr}
    , CE_PIXEL{vlSymsp->TOP.CE_PIXEL}
    , VGA_R{vlSymsp->TOP.VGA_R}
    , VGA_G{vlSymsp->TOP.VGA_G}
    , VGA_B{vlSymsp->TOP.VGA_B}
    , VGA_HS{vlSymsp->TOP.VGA_HS}
    , VGA_VS{vlSymsp->TOP.VGA_VS}
    , VGA_DE{vlSymsp->TOP.VGA_DE}
    , LED_USER{vlSymsp->TOP.LED_USER}
    , ps2_key{vlSymsp->TOP.ps2_key}
    , sd_buff_dout{vlSymsp->TOP.sd_buff_dout}
    , sd_buff_din{vlSymsp->TOP.sd_buff_din}
    , AUDIO_L{vlSymsp->TOP.AUDIO_L}
    , AUDIO_R{vlSymsp->TOP.AUDIO_R}
    , ps2_mouse{vlSymsp->TOP.ps2_mouse}
    , img_size{vlSymsp->TOP.img_size}
    , sd_lba{vlSymsp->TOP.sd_lba}
    , sim_top{vlSymsp->TOP.sim_top}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vsim_top::Vsim_top(const char* _vcname__)
    : Vsim_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vsim_top::~Vsim_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vsim_top___024root___eval_debug_assertions(Vsim_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vsim_top___024root___eval_static(Vsim_top___024root* vlSelf);
VL_ATTR_COLD void Vsim_top___024root___eval_initial(Vsim_top___024root* vlSelf);
VL_ATTR_COLD bool Vsim_top___024root___eval_stl(Vsim_top___024root* vlSelf, CData/*0:0*/ firstIteration);
void Vsim_top___024root___eval_sample(Vsim_top___024root* vlSelf);
bool Vsim_top___024root___eval_ico(Vsim_top___024root* vlSelf, CData/*0:0*/ firstIteration);
bool Vsim_top___024root___eval_act(Vsim_top___024root* vlSelf);
bool Vsim_top___024root___eval_inact(Vsim_top___024root* vlSelf);
bool Vsim_top___024root___eval_nba(Vsim_top___024root* vlSelf);
bool Vsim_top___024root___eval_obs(Vsim_top___024root* vlSelf);
bool Vsim_top___024root___eval_react(Vsim_top___024root* vlSelf);
void Vsim_top___024root___eval_postponed(Vsim_top___024root* vlSelf);
VL_ATTR_COLD void Vsim_top___024root___eval_final(Vsim_top___024root* vlSelf);
VL_ATTR_COLD void Vsim_top___024root___eval_dump_triggers__stl(Vsim_top___024root* vlSelf);
VL_ATTR_COLD void Vsim_top___024root___eval_dump_triggers__ico(Vsim_top___024root* vlSelf);
VL_ATTR_COLD void Vsim_top___024root___eval_dump_triggers__act(Vsim_top___024root* vlSelf);
VL_ATTR_COLD void Vsim_top___024root___eval_dump_triggers__nba(Vsim_top___024root* vlSelf);
VL_ATTR_COLD void Vsim_top___024root___eval_dump_triggers__obs(Vsim_top___024root* vlSelf);
VL_ATTR_COLD void Vsim_top___024root___eval_dump_triggers__react(Vsim_top___024root* vlSelf);

void Vsim_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vsim_top::eval_step\n"); );
    m_evalLoop.eval();
}

void Vsim_top::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vsim_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vsim_top::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vsim_top::evalStatic() {
    Vsim_top___024root___eval_static(&(vlSymsp->TOP));
}

void Vsim_top::evalInitial() {
    Vsim_top___024root___eval_initial(&(vlSymsp->TOP));
}

bool Vsim_top::evalStl(bool firstIteration) {
    return Vsim_top___024root___eval_stl(&(vlSymsp->TOP), firstIteration);
}

void Vsim_top::evalSample() {
    Vsim_top___024root___eval_sample(&(vlSymsp->TOP));
}

bool Vsim_top::evalIco(bool firstIteration) {
    return Vsim_top___024root___eval_ico(&(vlSymsp->TOP), firstIteration);
}

bool Vsim_top::evalAct() {
    return Vsim_top___024root___eval_act(&(vlSymsp->TOP));
}

bool Vsim_top::evalInact() {
    return Vsim_top___024root___eval_inact(&(vlSymsp->TOP));
}

bool Vsim_top::evalNba() {
    return Vsim_top___024root___eval_nba(&(vlSymsp->TOP));
}

bool Vsim_top::evalObs() {
    return Vsim_top___024root___eval_obs(&(vlSymsp->TOP));
}

bool Vsim_top::evalReact() {
    return Vsim_top___024root___eval_react(&(vlSymsp->TOP));
}

void Vsim_top::evalPostponed() {
    Vsim_top___024root___eval_postponed(&(vlSymsp->TOP));
}

void Vsim_top::evalFinal() {
    Vsim_top___024root___eval_final(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsim_top::dumpTriggersStl() {
    Vsim_top___024root___eval_dump_triggers__stl(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsim_top::dumpTriggersIco() {
    Vsim_top___024root___eval_dump_triggers__ico(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsim_top::dumpTriggersAct() {
    Vsim_top___024root___eval_dump_triggers__act(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsim_top::dumpTriggersNba() {
    Vsim_top___024root___eval_dump_triggers__nba(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsim_top::dumpTriggersObs() {
    Vsim_top___024root___eval_dump_triggers__obs(&(vlSymsp->TOP));
}

VL_ATTR_COLD void Vsim_top::dumpTriggersReact() {
    Vsim_top___024root___eval_dump_triggers__react(&(vlSymsp->TOP));
}

//============================================================
// Events and timing
bool Vsim_top::eventsPending() { return false; }

uint64_t Vsim_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vsim_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vsim_top::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vsim_top::hierName() const { return vlSymsp->name(); }
const char* Vsim_top::modelName() const { return "Vsim_top"; }
unsigned Vsim_top::threads() const { return 1; }
void Vsim_top::prepareClone() const { contextp()->prepareClone(); }
void Vsim_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
