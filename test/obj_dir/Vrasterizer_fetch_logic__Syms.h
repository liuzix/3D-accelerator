// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vrasterizer_fetch_logic__Syms_H_
#define _Vrasterizer_fetch_logic__Syms_H_

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vrasterizer_fetch_logic.h"

// SYMS CLASS
class Vrasterizer_fetch_logic__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vrasterizer_fetch_logic*       TOPp;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_rasterizer_fetch_logic;
    
    // CREATORS
    Vrasterizer_fetch_logic__Syms(Vrasterizer_fetch_logic* topp, const char* namep);
    ~Vrasterizer_fetch_logic__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
