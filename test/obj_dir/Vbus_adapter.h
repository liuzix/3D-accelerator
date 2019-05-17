// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vbus_adapter_H_
#define _Vbus_adapter_H_

#include "verilated.h"

class Vbus_adapter__Syms;

//----------

VL_MODULE(Vbus_adapter) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(slave_readdatavalid,0,0);
    VL_OUT8(slave_waitrequest,0,0);
    VL_IN8(slave_write,0,0);
    VL_IN8(slave_read,0,0);
    VL_IN8(master_readdatavalid,0,0);
    VL_IN8(master_waitrequest,0,0);
    VL_OUT8(master_read,0,0);
    VL_OUT8(master_write,0,0);
    VL_OUT8(master_byteenable,1,0);
    VL_IN16(master_readdata,15,0);
    VL_OUT16(master_writedata,15,0);
    VL_IN(slave_writedata,31,0);
    VL_OUT(slave_readdata,31,0);
    VL_IN(slave_address,25,0);
    VL_OUT(master_address,25,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(bus_adapter__DOT__read_state,2,0);
    VL_SIG8(bus_adapter__DOT__rec_state,1,0);
    VL_SIG8(bus_adapter__DOT__write_state,2,0);
    VL_SIG8(bus_adapter__DOT__read_busy,0,0);
    VL_SIG8(bus_adapter__DOT__write_busy,0,0);
    VL_SIG8(bus_adapter__DOT__prev_state,2,0);
    VL_SIG8(bus_adapter__DOT__prev_state_w,2,0);
    VL_SIG16(bus_adapter__DOT__read_data_cache,15,0);
    VL_SIG(bus_adapter__DOT__master_address_r,25,0);
    VL_SIG(bus_adapter__DOT__master_address_w,25,0);
    VL_SIG(bus_adapter__DOT__read_addr_cache,25,0);
    VL_SIG(bus_adapter__DOT__write_data_cache,31,0);
    VL_SIG(bus_adapter__DOT__write_addr_cache,25,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    VL_SIG8(__Vclklast__TOP__reset,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vbus_adapter__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vbus_adapter);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vbus_adapter(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vbus_adapter();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vbus_adapter__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vbus_adapter__Syms* symsp, bool first);
  private:
    static QData _change_request(Vbus_adapter__Syms* __restrict vlSymsp);
    void _ctor_var_reset();
  public:
    static void _eval(Vbus_adapter__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vbus_adapter__Syms* __restrict vlSymsp);
    static void _eval_settle(Vbus_adapter__Syms* __restrict vlSymsp);
    static void _initial__TOP__1(Vbus_adapter__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vbus_adapter__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vbus_adapter__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
