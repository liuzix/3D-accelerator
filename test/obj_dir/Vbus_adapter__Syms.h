// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header

#ifndef _Vbus_adapter__Syms_H_
#define _Vbus_adapter__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vbus_adapter.h"

// SYMS CLASS
class Vbus_adapter__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vbus_adapter*                  TOPp;
    
    // CREATORS
    Vbus_adapter__Syms(Vbus_adapter* topp, const char* namep);
    ~Vbus_adapter__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif // guard
