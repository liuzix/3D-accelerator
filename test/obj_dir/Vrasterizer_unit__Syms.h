// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vrasterizer_unit__Syms_H_
#define _Vrasterizer_unit__Syms_H_

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vrasterizer_unit.h"

// SYMS CLASS
class Vrasterizer_unit__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vrasterizer_unit*              TOPp;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_rasterizer_unit__fetch_logic;
    VerilatedScope __Vscope_rasterizer_unit__raster__area_divider;
    
    // CREATORS
    Vrasterizer_unit__Syms(Vrasterizer_unit* topp, const char* namep);
    ~Vrasterizer_unit__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
