// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSIM_TOP__SYMS_H_
#define VERILATED_VSIM_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vsim_top.h"

// INCLUDE MODULE CLASSES
#include "Vsim_top___024root.h"
#include "Vsim_top_sim_top.h"
#include "Vsim_top_sdram_model.h"

// DPI TYPES for DPI Export callbacks (Internal use)

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vsim_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vsim_top* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    Vsim_top___024root             TOP;
    Vsim_top_sim_top               TOP__sim_top;
    Vsim_top_sdram_model           TOP__sim_top__sdram;

    // SCOPE NAMES
    VerilatedScope* __Vscopep_TOP;
    VerilatedScope* __Vscopep_sim_top;
    VerilatedScope* __Vscopep_sim_top__sdram;

    // CONSTRUCTORS
    Vsim_top__Syms(VerilatedContext* contextp, const char* namep, Vsim_top* modelp);
    ~Vsim_top__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
