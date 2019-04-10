// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vrasterizer_fetch_logic_H_
#define _Vrasterizer_fetch_logic_H_

#include "verilated_heavy.h"

class Vrasterizer_fetch_logic__Syms;

//----------

VL_MODULE(Vrasterizer_fetch_logic) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(master_read,0,0);
    VL_OUT8(master_write,0,0);
    VL_OUT8(master_byteenable,3,0);
    VL_IN8(master_readdatavalid,0,0);
    VL_IN8(master_waitrequest,0,0);
    VL_IN8(input_valid,0,0);
    VL_OUT8(output_valid,0,0);
    VL_OUT8(wait_request,0,0);
    VL_OUT(master_address,25,0);
    VL_IN(master_readdata,31,0);
    VL_OUT(master_writedata,31,0);
    VL_IN(addr_in,25,0);
    VL_IN(color_in,23,0);
    VL_IN(depth_in,31,0);
    VL_OUT(addr_out,25,0);
    VL_OUT(old_depth_out,31,0);
    VL_OUT(new_depth_out,31,0);
    VL_OUT(color_out,23,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(rasterizer_fetch_logic__DOT__wrreq,0,0);
    VL_SIG8(rasterizer_fetch_logic__DOT__empty,0,0);
    VL_SIG8(rasterizer_fetch_logic__DOT__fifo__DOT__wr_ptr,3,0);
    VL_SIG8(rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr,3,0);
    VL_SIG8(rasterizer_fetch_logic__DOT__fifo__DOT__counter,3,0);
    VL_SIG8(rasterizer_fetch_logic__DOT__fifo__DOT__new_counter,3,0);
    VL_SIGW(rasterizer_fetch_logic__DOT__data_in,95,0,3);
    VL_SIGW(rasterizer_fetch_logic__DOT__data_out_reg,95,0,3);
    VL_SIGW(rasterizer_fetch_logic__DOT__fifo__DOT__buffer[16],95,0,3);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__clock,0,0);
    VL_SIG8(__Vclklast__TOP__reset,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vrasterizer_fetch_logic__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vrasterizer_fetch_logic);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vrasterizer_fetch_logic(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vrasterizer_fetch_logic();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vrasterizer_fetch_logic__Syms* symsp, bool first);
  private:
    static QData _change_request(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp);
    void _ctor_var_reset();
  public:
    static void _eval(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp);
    static void _eval_settle(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp);
    static void _sequent__TOP__1(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp);
    static void _settle__TOP__2(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
