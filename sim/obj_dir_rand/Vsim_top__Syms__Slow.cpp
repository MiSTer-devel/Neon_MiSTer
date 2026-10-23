// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vsim_top__pch.h"

extern const VlVarTableEntry Vsim_top___024root__VpiVarTable0[];
extern const VlVarTableEntry Vsim_top_sim_top__VpiVarTable1[];
extern const VlVarTableEntry Vsim_top_sdram_model__VpiVarTable2[];
extern const VlScopeTableEntry Vsim_top__Syms__VpiScopeTable[];


// VPI VARIABLE/SCOPE TABLES
#if defined(__GNUC__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif
extern const VlVarTableEntry Vsim_top___024root__VpiVarTable0[] = {
    {"ps2_key", offsetof(Vsim_top___024root, ps2_key), VLVT_UINT16, (VLVD_IN|VLVF_PUB_RW), 0, 1, {10, 0, 0, 0, 0, 0}},
};
extern const VlVarTableEntry Vsim_top_sim_top__VpiVarTable1[] = {
    {"ps2_key", offsetof(Vsim_top_sim_top, ps2_key), VLVT_UINT16, (VLVD_IN|VLVF_PUB_RW|VLVF_CONTINUOUSLY), 0, 1, {10, 0, 0, 0, 0, 0}},
};
extern const VlVarTableEntry Vsim_top_sdram_model__VpiVarTable2[] = {
    {"mem", offsetof(Vsim_top_sdram_model, mem), VLVT_UINT16, (VLVD_NODIR|VLVF_PUB_RW), 1, 1, {0, 2097151, 15, 0, 0, 0}},
};
extern const VlScopeTableEntry Vsim_top__Syms__VpiScopeTable[] = {
    {offsetof(Vsim_top__Syms, __Vscopep_TOP), "TOP", "TOP", "<null>", 0, VerilatedScope::SCOPE_OTHER},
    {offsetof(Vsim_top__Syms, __Vscopep_sim_top), "sim_top", "sim_top", "<null>", 0, VerilatedScope::SCOPE_OTHER},
    {offsetof(Vsim_top__Syms, __Vscopep_sim_top__sdram), "sim_top.sdram", "sdram", "<null>", 0, VerilatedScope::SCOPE_OTHER},
};
#if defined(__GNUC__)
# pragma GCC diagnostic pop
#endif
Vsim_top__Syms::Vsim_top__Syms(VerilatedContext* contextp, const char* namep, Vsim_top* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_didInit{modelp->m_didInit}
    // Setup top module instance
    , TOP{this, namep}
{
    // Check resources
    Verilated::stackCheck(966);
    // Setup sub module instances
    TOP__sim_top.ctor(this, "sim_top");
    TOP__sim_top__sdram.ctor(this, "sim_top.sdram");
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    TOP.sim_top = &TOP__sim_top;
    TOP__sim_top.sdram = &TOP__sim_top__sdram;
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
    TOP__sim_top.__Vconfigure(true);
    TOP__sim_top__sdram.__Vconfigure(true);
    // Setup scopes
    VerilatedScope::scopesConstructFromTable(Vsim_top__Syms__VpiScopeTable, 3, this);
    // Setup export functions - final: 0
    // Setup export functions - final: 1
    // Setup public variables
    __Vscopep_TOP->varsInsertFromTable(Vsim_top___024root__VpiVarTable0, 1, &(TOP));
    __Vscopep_sim_top->varsInsertFromTable(Vsim_top_sim_top__VpiVarTable1, 1, &(TOP__sim_top));
    __Vscopep_sim_top__sdram->varsInsertFromTable(Vsim_top_sdram_model__VpiVarTable2, 1, &(TOP__sim_top__sdram));
}

Vsim_top__Syms::~Vsim_top__Syms() {
    // Tear down scopes
    VL_DO_CLEAR(delete __Vscopep_TOP, __Vscopep_TOP = nullptr);
    VL_DO_CLEAR(delete __Vscopep_sim_top, __Vscopep_sim_top = nullptr);
    VL_DO_CLEAR(delete __Vscopep_sim_top__sdram, __Vscopep_sim_top__sdram = nullptr);
    // Tear down sub module instances
    TOP__sim_top__sdram.dtor();
    TOP__sim_top.dtor();
}
