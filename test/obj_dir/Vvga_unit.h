// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vvga_unit_H_
#define _Vvga_unit_H_

#include "verilated_heavy.h"

class Vvga_unit__Syms;

//----------

VL_MODULE(Vvga_unit) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(master_readdatavalid,0,0);
    VL_IN8(master_waitrequest,0,0);
    VL_OUT8(master_read,0,0);
    VL_OUT8(master_write,0,0);
    VL_OUT8(VGA_R,7,0);
    VL_OUT8(VGA_G,7,0);
    VL_OUT8(VGA_B,7,0);
    VL_OUT8(VGA_CLK,0,0);
    VL_OUT8(VGA_HS,0,0);
    VL_OUT8(VGA_VS,0,0);
    VL_OUT8(VGA_BLANK_n,0,0);
    VL_OUT8(VGA_SYNC_n,0,0);
    VL_OUT16(master_writedata,15,0);
    VL_IN16(bus_data,15,0);
    VL_IN(frame_buffer_ptr,25,0);
    VL_OUT(master_address,25,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(vga_unit__DOT__pixel_read,0,0);
    VL_SIG8(vga_unit__DOT__pixel_valid,0,0);
    VL_SIG8(vga_unit__DOT__slave_readdatavalid,0,0);
    VL_SIG8(vga_unit__DOT__slave_waitrequest,0,0);
    VL_SIG8(vga_unit__DOT__slave_write,0,0);
    VL_SIG8(vga_unit__DOT__slave_read,0,0);
    VL_SIG8(vga_unit__DOT__bus_adp__DOT__read_state,2,0);
    VL_SIG8(vga_unit__DOT__bus_adp__DOT__rec_state,1,0);
    VL_SIG8(vga_unit__DOT__bus_adp__DOT__write_state,2,0);
    VL_SIG8(vga_unit__DOT__bus_adp__DOT__read_busy,0,0);
    VL_SIG8(vga_unit__DOT__bus_adp__DOT__write_busy,0,0);
    VL_SIG8(vga_unit__DOT__bus_adp__DOT__prev_state,2,0);
    VL_SIG8(vga_unit__DOT__bus_adp__DOT__prev_state_w,2,0);
    VL_SIG8(vga_unit__DOT__master__DOT__wr,0,0);
    VL_SIG8(vga_unit__DOT__master__DOT__addr_invalid,0,0);
    VL_SIG8(vga_unit__DOT__master__DOT__pixel_in_progress,4,0);
    VL_SIG8(vga_unit__DOT__master__DOT__pixel_in_progress_next,4,0);
    VL_SIG8(vga_unit__DOT__master__DOT__empty,0,0);
    VL_SIG8(vga_unit__DOT__master__DOT__sync,0,0);
    VL_SIG8(vga_unit__DOT__master__DOT__buffer__DOT__wr_ptr,3,0);
    VL_SIG8(vga_unit__DOT__master__DOT__buffer__DOT__rd_ptr,3,0);
    VL_SIG8(vga_unit__DOT__master__DOT__buffer__DOT__counter,3,0);
    VL_SIG8(vga_unit__DOT__master__DOT__buffer__DOT__new_counter,3,0);
    VL_SIG8(vga_unit__DOT__buffer__DOT__clk_counter,0,0);
    VL_SIG8(vga_unit__DOT__buffer__DOT__counters__DOT__endOfLine,0,0);
    VL_SIG8(vga_unit__DOT__buffer__DOT__counters__DOT__endOfField,0,0);
    VL_SIG16(vga_unit__DOT__bus_adp__DOT__read_data_cache,15,0);
    VL_SIG16(vga_unit__DOT__buffer__DOT__hcount,10,0);
    VL_SIG16(vga_unit__DOT__buffer__DOT__vcount,9,0);
    VL_SIG(vga_unit__DOT__cur_vga_addr,25,0);
    VL_SIG(vga_unit__DOT__pixel_data,31,0);
    VL_SIG(vga_unit__DOT__slave_readdata,31,0);
    VL_SIG(vga_unit__DOT__slave_writedata,31,0);
    VL_SIG(vga_unit__DOT__slave_address,25,0);
    VL_SIG(vga_unit__DOT__bus_adp__DOT__master_address_r,25,0);
    VL_SIG(vga_unit__DOT__bus_adp__DOT__master_address_w,25,0);
    VL_SIG(vga_unit__DOT__bus_adp__DOT__read_addr_cache,25,0);
    VL_SIG(vga_unit__DOT__bus_adp__DOT__write_data_cache,31,0);
    VL_SIG(vga_unit__DOT__bus_adp__DOT__write_addr_cache,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__cur_addr,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__din,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__dout,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__up_addr,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__up_addr_next,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__down_addr,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__down_addr_next,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__next_cur,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__offset8_cur_addr,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__next_vga,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__next_vga128,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__next_vga120,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__next_dout,25,0);
    VL_SIG(vga_unit__DOT__master__DOT__offset8_dout,25,0);
    VL_SIG(vga_unit__DOT__buffer__DOT__read_state,31,0);
    VL_SIG(vga_unit__DOT__master__DOT__pixel_buffer[32],31,0);
    VL_SIG(vga_unit__DOT__master__DOT__buffer__DOT__buffer[16],25,0);
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Begin mtask footprint  all: 
    VL_SIG8(__Vclklast__TOP__clk,0,0);
    VL_SIG8(__Vclklast__TOP__reset,0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vvga_unit__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vvga_unit);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vvga_unit(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vvga_unit();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vvga_unit__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vvga_unit__Syms* symsp, bool first);
  private:
    static QData _change_request(Vvga_unit__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__4(Vvga_unit__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vvga_unit__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vvga_unit__Syms* __restrict vlSymsp);
    static void _eval_settle(Vvga_unit__Syms* __restrict vlSymsp);
    static void _initial__TOP__1(Vvga_unit__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vvga_unit__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vvga_unit__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
