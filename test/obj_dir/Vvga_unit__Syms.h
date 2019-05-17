// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vvga_unit__Syms_H_
#define _Vvga_unit__Syms_H_

#include "verilated_heavy.h"

// INCLUDE MODULE CLASSES
#include "Vvga_unit.h"

// SYMS CLASS
class Vvga_unit__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vvga_unit*                     TOPp;
    
    // SCOPE NAMES
    VerilatedScope __Vscope_vga_unit__master;
    
    // CREATORS
    Vvga_unit__Syms(Vvga_unit* topp, const char* namep);
    ~Vvga_unit__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
