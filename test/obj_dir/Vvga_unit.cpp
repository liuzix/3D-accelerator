// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vvga_unit.h for the primary calling header

#include "Vvga_unit.h"
#include "Vvga_unit__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vvga_unit) {
    Vvga_unit__Syms* __restrict vlSymsp = __VlSymsp = new Vvga_unit__Syms(this, name());
    Vvga_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vvga_unit::__Vconfigure(Vvga_unit__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vvga_unit::~Vvga_unit() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vvga_unit::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vvga_unit::eval\n"); );
    Vvga_unit__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vvga_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

void Vvga_unit::_eval_initial_loop(Vvga_unit__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
	_eval_settle(vlSymsp);
	_eval(vlSymsp);
	if (VL_UNLIKELY(++__VclockLoop > 100)) {
	    // About to fail, so enable debug to see what's not settling.
	    // Note you must run make with OPT=-DVL_DEBUG for debug prints.
	    int __Vsaved_debug = Verilated::debug();
	    Verilated::debug(1);
	    __Vchange = _change_request(vlSymsp);
	    Verilated::debug(__Vsaved_debug);
	    VL_FATAL_MT(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
	} else {
	    __Vchange = _change_request(vlSymsp);
	}
    } while (VL_UNLIKELY(__Vchange));
}

//--------------------
// Internal Methods

void Vvga_unit::_initial__TOP__1(Vvga_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_unit::_initial__TOP__1\n"); );
    Vvga_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at ../vga_unit_modules.sv:360
    vlTOPp->VGA_SYNC_n = 0U;
}

VL_INLINE_OPT void Vvga_unit::_sequent__TOP__2(Vvga_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_unit::_sequent__TOP__2\n"); );
    Vvga_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__Vfuncout,0,0);
    VL_SIG8(__Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__Vfuncout,0,0);
    VL_SIG8(__Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__Vfuncout,0,0);
    VL_SIG8(__Vdly__vga_unit__DOT__bus_adp__DOT__read_state,2,0);
    VL_SIG8(__Vdly__vga_unit__DOT__bus_adp__DOT__rec_state,1,0);
    VL_SIG8(__Vdly__vga_unit__DOT__bus_adp__DOT__write_state,2,0);
    VL_SIG8(__Vdlyvdim0__vga_unit__DOT__master__DOT__pixel_buffer__v0,4,0);
    VL_SIG8(__Vdlyvset__vga_unit__DOT__master__DOT__pixel_buffer__v0,0,0);
    VL_SIG8(__Vdlyvdim0__vga_unit__DOT__master__DOT__pixel_buffer__v1,4,0);
    VL_SIG8(__Vdlyvset__vga_unit__DOT__master__DOT__pixel_buffer__v1,0,0);
    VL_SIG8(__Vdly__vga_unit__DOT__master__DOT__buffer__DOT__counter,3,0);
    VL_SIG8(__Vdlyvdim0__vga_unit__DOT__master__DOT__buffer__DOT__buffer__v0,3,0);
    VL_SIG8(__Vdlyvset__vga_unit__DOT__master__DOT__buffer__DOT__buffer__v0,0,0);
    VL_SIG8(__Vdly__vga_unit__DOT__buffer__DOT__clk_counter,0,0);
    VL_SIG8(__Vdly__vga_unit__DOT__pixel_read,0,0);
    VL_SIG16(__Vdly__vga_unit__DOT__bus_adp__DOT__read_data_cache,15,0);
    VL_SIG16(__Vdly__vga_unit__DOT__buffer__DOT__hcount,10,0);
    VL_SIG16(__Vdly__vga_unit__DOT__buffer__DOT__vcount,9,0);
    VL_SIG(__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__addr,25,0);
    VL_SIG(__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__up,25,0);
    VL_SIG(__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__down,25,0);
    VL_SIG(__Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__first,25,0);
    VL_SIG(__Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__second,25,0);
    VL_SIG(__Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__first,25,0);
    VL_SIG(__Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__second,25,0);
    VL_SIG(__Vdly__vga_unit__DOT__bus_adp__DOT__read_addr_cache,25,0);
    VL_SIG(__Vdly__vga_unit__DOT__bus_adp__DOT__write_addr_cache,25,0);
    VL_SIG(__Vdly__vga_unit__DOT__master__DOT__cur_addr,25,0);
    VL_SIG(__Vdlyvval__vga_unit__DOT__master__DOT__pixel_buffer__v0,31,0);
    VL_SIG(__Vdlyvval__vga_unit__DOT__master__DOT__pixel_buffer__v1,31,0);
    VL_SIG(__Vdlyvval__vga_unit__DOT__master__DOT__buffer__DOT__buffer__v0,25,0);
    VL_SIG(__Vdly__vga_unit__DOT__buffer__DOT__read_state,31,0);
    // Body
    __Vdly__vga_unit__DOT__buffer__DOT__clk_counter 
	= vlTOPp->vga_unit__DOT__buffer__DOT__clk_counter;
    __Vdly__vga_unit__DOT__bus_adp__DOT__rec_state 
	= vlTOPp->vga_unit__DOT__bus_adp__DOT__rec_state;
    __Vdly__vga_unit__DOT__bus_adp__DOT__read_data_cache 
	= vlTOPp->vga_unit__DOT__bus_adp__DOT__read_data_cache;
    __Vdly__vga_unit__DOT__buffer__DOT__hcount = vlTOPp->vga_unit__DOT__buffer__DOT__hcount;
    __Vdly__vga_unit__DOT__buffer__DOT__vcount = vlTOPp->vga_unit__DOT__buffer__DOT__vcount;
    __Vdly__vga_unit__DOT__master__DOT__cur_addr = vlTOPp->vga_unit__DOT__master__DOT__cur_addr;
    __Vdly__vga_unit__DOT__bus_adp__DOT__write_addr_cache 
	= vlTOPp->vga_unit__DOT__bus_adp__DOT__write_addr_cache;
    __Vdly__vga_unit__DOT__bus_adp__DOT__write_state 
	= vlTOPp->vga_unit__DOT__bus_adp__DOT__write_state;
    __Vdly__vga_unit__DOT__master__DOT__buffer__DOT__counter 
	= vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__counter;
    __Vdlyvset__vga_unit__DOT__master__DOT__pixel_buffer__v0 = 0U;
    __Vdlyvset__vga_unit__DOT__master__DOT__pixel_buffer__v1 = 0U;
    __Vdly__vga_unit__DOT__bus_adp__DOT__read_addr_cache 
	= vlTOPp->vga_unit__DOT__bus_adp__DOT__read_addr_cache;
    __Vdly__vga_unit__DOT__bus_adp__DOT__read_state 
	= vlTOPp->vga_unit__DOT__bus_adp__DOT__read_state;
    __Vdly__vga_unit__DOT__buffer__DOT__read_state 
	= vlTOPp->vga_unit__DOT__buffer__DOT__read_state;
    __Vdly__vga_unit__DOT__pixel_read = vlTOPp->vga_unit__DOT__pixel_read;
    __Vdlyvset__vga_unit__DOT__master__DOT__buffer__DOT__buffer__v0 = 0U;
    // ALWAYS at ../vga_unit_modules.sv:234
    __Vdly__vga_unit__DOT__buffer__DOT__clk_counter 
	= ((IData)(vlTOPp->reset) & ((IData)(1U) + (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__clk_counter)));
    // ALWAYS at ..//fifo.sv:40
    if (vlTOPp->reset) {
	if (((IData)(vlTOPp->vga_unit__DOT__slave_readdatavalid) 
	     & (0U != (IData)(vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__counter)))) {
	    vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__rd_ptr 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__rd_ptr)));
	}
    } else {
	vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__rd_ptr = 0U;
    }
    // ALWAYS at ../vga_unit_modules.sv:333
    if (vlTOPp->reset) {
	if ((1U & (~ (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__clk_counter)))) {
	    __Vdly__vga_unit__DOT__buffer__DOT__hcount 
		= (0x7ffU & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__counters__DOT__endOfLine)
			      ? 0U : ((IData)(1U) + (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount))));
	}
    } else {
	__Vdly__vga_unit__DOT__buffer__DOT__hcount = 0U;
    }
    // ALWAYS at ../vga_unit_modules.sv:345
    if (vlTOPp->reset) {
	if (((0x63fU == (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount)) 
	     & (~ (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__clk_counter)))) {
	    __Vdly__vga_unit__DOT__buffer__DOT__vcount 
		= (0x3ffU & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__counters__DOT__endOfField)
			      ? 0U : ((IData)(1U) + (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__vcount))));
	}
    } else {
	__Vdly__vga_unit__DOT__buffer__DOT__vcount = 0U;
    }
    // ALWAYS at ../bus_adapter.sv:158
    if (vlTOPp->reset) {
	if ((4U & (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__write_state))) {
	    if ((1U & (~ ((IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__write_state) 
			  >> 1U)))) {
		if ((1U & (~ (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__write_state)))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_write = 0U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__write_state 
			    = vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state_w;
		    } else {
			vlTOPp->master_write = 0U;
			vlTOPp->vga_unit__DOT__bus_adp__DOT__write_busy = 0U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__write_state = 0U;
		    }
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__write_state))) {
		if ((1U & (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__write_state))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_write = 0U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__write_state 
			    = vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state_w;
		    } else {
			vlTOPp->vga_unit__DOT__bus_adp__DOT__master_address_w 
			    = (0x3ffffffU & ((IData)(2U) 
					     + vlTOPp->vga_unit__DOT__bus_adp__DOT__write_addr_cache));
			vlTOPp->master_writedata = 
			    (0xffffU & vlTOPp->vga_unit__DOT__slave_writedata);
			vlTOPp->master_write = 1U;
			vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state_w = 2U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__write_state = 4U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__write_addr_cache 
			    = (0x3ffffffU & ((IData)(2U) 
					     + vlTOPp->vga_unit__DOT__bus_adp__DOT__write_addr_cache));
		    }
		} else {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_write = 0U;
		    } else {
			vlTOPp->vga_unit__DOT__bus_adp__DOT__master_address_w 
			    = vlTOPp->vga_unit__DOT__bus_adp__DOT__write_addr_cache;
			vlTOPp->master_writedata = 
			    (0xffffU & vlTOPp->vga_unit__DOT__slave_writedata);
			vlTOPp->master_write = 1U;
			vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state_w = 2U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__write_state = 4U;
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__write_state))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_write = 0U;
		    } else {
			vlTOPp->vga_unit__DOT__bus_adp__DOT__master_address_w 
			    = vlTOPp->vga_unit__DOT__bus_adp__DOT__write_addr_cache;
			vlTOPp->master_writedata = 
			    (0xffffU & (vlTOPp->vga_unit__DOT__bus_adp__DOT__write_data_cache 
					>> 0x10U));
			vlTOPp->master_write = 1U;
			vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state_w = 1U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__write_state = 3U;
		    }
		} else {
		    if (vlTOPp->vga_unit__DOT__slave_write) {
			vlTOPp->vga_unit__DOT__bus_adp__DOT__write_busy = 1U;
			if (vlTOPp->master_waitrequest) {
			    __Vdly__vga_unit__DOT__bus_adp__DOT__write_addr_cache 
				= vlTOPp->vga_unit__DOT__slave_address;
			    vlTOPp->master_write = 0U;
			    vlTOPp->vga_unit__DOT__bus_adp__DOT__write_data_cache 
				= vlTOPp->vga_unit__DOT__slave_writedata;
			    __Vdly__vga_unit__DOT__bus_adp__DOT__write_state = 1U;
			} else {
			    __Vdly__vga_unit__DOT__bus_adp__DOT__write_addr_cache 
				= vlTOPp->vga_unit__DOT__slave_address;
			    vlTOPp->vga_unit__DOT__bus_adp__DOT__master_address_w 
				= vlTOPp->vga_unit__DOT__slave_address;
			    vlTOPp->master_writedata 
				= (0xffffU & (vlTOPp->vga_unit__DOT__slave_writedata 
					      >> 0x10U));
			    vlTOPp->master_write = 1U;
			    vlTOPp->vga_unit__DOT__bus_adp__DOT__write_data_cache 
				= vlTOPp->vga_unit__DOT__slave_writedata;
			    vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state_w = 1U;
			    __Vdly__vga_unit__DOT__bus_adp__DOT__write_state = 3U;
			}
		    } else {
			vlTOPp->master_write = 0U;
		    }
		}
	    }
	}
    } else {
	__Vdly__vga_unit__DOT__bus_adp__DOT__write_state = 0U;
	vlTOPp->master_write = 0U;
	vlTOPp->vga_unit__DOT__bus_adp__DOT__write_busy = 0U;
	vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state_w = 0U;
    }
    // ALWAYS at ..//fifo.sv:40
    if (vlTOPp->reset) {
	vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__new_counter 
	    = vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__counter;
	if (((IData)(vlTOPp->vga_unit__DOT__slave_readdatavalid) 
	     & (~ (IData)(vlTOPp->vga_unit__DOT__master__DOT__empty)))) {
	    vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__new_counter 
		= (0xfU & ((IData)(vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__new_counter) 
			   - (IData)(1U)));
	}
	if (vlTOPp->vga_unit__DOT__master__DOT__wr) {
	    vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__new_counter 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__new_counter)));
	}
	__Vdly__vga_unit__DOT__master__DOT__buffer__DOT__counter 
	    = vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__new_counter;
    } else {
	vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__new_counter = 0U;
	__Vdly__vga_unit__DOT__master__DOT__buffer__DOT__counter = 0U;
    }
    // ALWAYS at ../bus_adapter.sv:55
    if (vlTOPp->reset) {
	if ((4U & (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__read_state))) {
	    if ((1U & (~ ((IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__read_state) 
			  >> 1U)))) {
		if ((1U & (~ (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__read_state)))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_read = 0U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__read_state 
			    = vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state;
		    } else {
			vlTOPp->master_read = 0U;
			vlTOPp->vga_unit__DOT__bus_adp__DOT__read_busy = 0U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__read_state = 0U;
		    }
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__read_state))) {
		if ((1U & (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__read_state))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_read = 0U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__read_state 
			    = vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state;
		    } else {
			vlTOPp->vga_unit__DOT__bus_adp__DOT__master_address_r 
			    = (0x3ffffffU & ((IData)(2U) 
					     + vlTOPp->vga_unit__DOT__bus_adp__DOT__read_addr_cache));
			vlTOPp->master_read = 1U;
			vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state = 2U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__read_state = 4U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__read_addr_cache 
			    = (0x3ffffffU & ((IData)(2U) 
					     + vlTOPp->vga_unit__DOT__bus_adp__DOT__read_addr_cache));
		    }
		} else {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_read = 0U;
		    } else {
			vlTOPp->vga_unit__DOT__bus_adp__DOT__master_address_r 
			    = vlTOPp->vga_unit__DOT__bus_adp__DOT__read_addr_cache;
			vlTOPp->master_read = 1U;
			vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state = 2U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__read_state = 4U;
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__read_state))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_read = 0U;
		    } else {
			vlTOPp->vga_unit__DOT__bus_adp__DOT__master_address_r 
			    = vlTOPp->vga_unit__DOT__bus_adp__DOT__read_addr_cache;
			vlTOPp->master_read = 1U;
			vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state = 1U;
			__Vdly__vga_unit__DOT__bus_adp__DOT__read_state = 3U;
		    }
		} else {
		    if (vlTOPp->vga_unit__DOT__slave_read) {
			vlTOPp->vga_unit__DOT__bus_adp__DOT__read_busy = 1U;
			if (vlTOPp->master_waitrequest) {
			    __Vdly__vga_unit__DOT__bus_adp__DOT__read_addr_cache 
				= vlTOPp->vga_unit__DOT__slave_address;
			    vlTOPp->master_read = 0U;
			    __Vdly__vga_unit__DOT__bus_adp__DOT__read_state = 1U;
			} else {
			    __Vdly__vga_unit__DOT__bus_adp__DOT__read_addr_cache 
				= vlTOPp->vga_unit__DOT__slave_address;
			    vlTOPp->vga_unit__DOT__bus_adp__DOT__master_address_r 
				= vlTOPp->vga_unit__DOT__slave_address;
			    vlTOPp->master_read = 1U;
			    vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state = 1U;
			    __Vdly__vga_unit__DOT__bus_adp__DOT__read_state = 3U;
			}
		    } else {
			vlTOPp->master_read = 0U;
		    }
		}
	    }
	}
    } else {
	__Vdly__vga_unit__DOT__bus_adp__DOT__read_state = 0U;
	vlTOPp->master_read = 0U;
	vlTOPp->vga_unit__DOT__bus_adp__DOT__read_busy = 0U;
	vlTOPp->vga_unit__DOT__bus_adp__DOT__prev_state = 0U;
    }
    // ALWAYS at ../vga_unit_modules.sv:250
    if (vlTOPp->reset) {
	if ((3U == vlTOPp->vga_unit__DOT__buffer__DOT__read_state)) {
	    if (VL_UNLIKELY((1U & (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount)))) {
		VL_WRITEF("vga_buffer: hcount = %4#\n",
			  10,(0x3ffU & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
					>> 1U)));
		if (((0x280U > (0x3ffU & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
					  >> 1U))) 
		     & (0x1e0U > (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__vcount)))) {
		    __Vdly__vga_unit__DOT__pixel_read = 1U;
		}
		__Vdly__vga_unit__DOT__buffer__DOT__read_state = 1U;
	    }
	} else {
	    if ((1U == vlTOPp->vga_unit__DOT__buffer__DOT__read_state)) {
		__Vdly__vga_unit__DOT__buffer__DOT__read_state = 0U;
		__Vdly__vga_unit__DOT__pixel_read = 0U;
	    } else {
		if ((0U == vlTOPp->vga_unit__DOT__buffer__DOT__read_state)) {
		    if (VL_LIKELY(vlTOPp->vga_unit__DOT__pixel_valid)) {
			vlTOPp->VGA_B = (0xffU & (vlTOPp->vga_unit__DOT__pixel_data 
						  >> 0x10U));
			vlTOPp->VGA_G = (0xffU & (vlTOPp->vga_unit__DOT__pixel_data 
						  >> 8U));
			vlTOPp->VGA_R = (0xffU & vlTOPp->vga_unit__DOT__pixel_data);
		    } else {
			VL_WRITEF("vga_buffer: no pixel\n");
			vlTOPp->VGA_B = 0xffU;
			vlTOPp->VGA_G = 0xffU;
			vlTOPp->VGA_R = 0xffU;
		    }
		    vlTOPp->VGA_CLK = 1U;
		    __Vdly__vga_unit__DOT__buffer__DOT__read_state = 2U;
		} else {
		    if ((2U == vlTOPp->vga_unit__DOT__buffer__DOT__read_state)) {
			vlTOPp->VGA_CLK = 0U;
			__Vdly__vga_unit__DOT__buffer__DOT__read_state = 3U;
		    }
		}
	    }
	}
    } else {
	vlTOPp->VGA_R = 0xffU;
	vlTOPp->VGA_G = 0U;
	vlTOPp->VGA_B = 0xffU;
	__Vdly__vga_unit__DOT__pixel_read = 0U;
	__Vdly__vga_unit__DOT__buffer__DOT__read_state = 3U;
    }
    // ALWAYS at ..//fifo.sv:40
    if (vlTOPp->reset) {
	if (vlTOPp->vga_unit__DOT__master__DOT__wr) {
	    __Vdlyvval__vga_unit__DOT__master__DOT__buffer__DOT__buffer__v0 
		= vlTOPp->vga_unit__DOT__master__DOT__din;
	    __Vdlyvset__vga_unit__DOT__master__DOT__buffer__DOT__buffer__v0 = 1U;
	    __Vdlyvdim0__vga_unit__DOT__master__DOT__buffer__DOT__buffer__v0 
		= vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__wr_ptr;
	    vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__wr_ptr 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__wr_ptr)));
	}
    } else {
	vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__wr_ptr = 0U;
    }
    vlTOPp->vga_unit__DOT__buffer__DOT__clk_counter 
	= __Vdly__vga_unit__DOT__buffer__DOT__clk_counter;
    vlTOPp->vga_unit__DOT__bus_adp__DOT__write_state 
	= __Vdly__vga_unit__DOT__bus_adp__DOT__write_state;
    vlTOPp->vga_unit__DOT__bus_adp__DOT__write_addr_cache 
	= __Vdly__vga_unit__DOT__bus_adp__DOT__write_addr_cache;
    vlTOPp->vga_unit__DOT__bus_adp__DOT__read_state 
	= __Vdly__vga_unit__DOT__bus_adp__DOT__read_state;
    vlTOPp->vga_unit__DOT__bus_adp__DOT__read_addr_cache 
	= __Vdly__vga_unit__DOT__bus_adp__DOT__read_addr_cache;
    vlTOPp->vga_unit__DOT__buffer__DOT__read_state 
	= __Vdly__vga_unit__DOT__buffer__DOT__read_state;
    vlTOPp->vga_unit__DOT__buffer__DOT__vcount = __Vdly__vga_unit__DOT__buffer__DOT__vcount;
    vlTOPp->vga_unit__DOT__buffer__DOT__hcount = __Vdly__vga_unit__DOT__buffer__DOT__hcount;
    // ALWAYSPOST at ..//fifo.sv:56
    if (__Vdlyvset__vga_unit__DOT__master__DOT__buffer__DOT__buffer__v0) {
	vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__buffer[__Vdlyvdim0__vga_unit__DOT__master__DOT__buffer__DOT__buffer__v0] 
	    = __Vdlyvval__vga_unit__DOT__master__DOT__buffer__DOT__buffer__v0;
    }
    // ALWAYS at ../bus_adapter.sv:40
    vlTOPp->master_address = ((IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__read_busy)
			       ? vlTOPp->vga_unit__DOT__bus_adp__DOT__master_address_r
			       : vlTOPp->vga_unit__DOT__bus_adp__DOT__master_address_w);
    vlTOPp->vga_unit__DOT__buffer__DOT__counters__DOT__endOfField 
	= (0x20cU == (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__vcount));
    vlTOPp->VGA_VS = (0xf5U != (0x1ffU & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__vcount) 
					  >> 1U)));
    vlTOPp->vga_unit__DOT__buffer__DOT__counters__DOT__endOfLine 
	= (0x63fU == (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount));
    vlTOPp->VGA_HS = (1U & (~ ((5U == (7U & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
					     >> 8U))) 
			       & (7U != (7U & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
					       >> 5U))))));
    vlTOPp->VGA_BLANK_n = (1U & ((~ (((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
				      >> 0xaU) & (((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
						   >> 9U) 
						  | ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
						     >> 8U)))) 
				 & (~ (((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__vcount) 
					>> 9U) | (0xfU 
						  == 
						  (0xfU 
						   & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__vcount) 
						      >> 5U)))))));
    // ALWAYS at ../vga_unit_modules.sv:117
    if (VL_UNLIKELY(vlTOPp->reset)) {
	VL_WRITEF("vga_master: -------------------------\n");
	VL_WRITEF("vga_master: up_addr = %8#, down_addr = %8#\n",
		  26,vlTOPp->vga_unit__DOT__master__DOT__up_addr,
		  26,vlTOPp->vga_unit__DOT__master__DOT__down_addr);
	vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress_next 
	    = vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress;
	vlTOPp->vga_unit__DOT__master__DOT__up_addr_next 
	    = vlTOPp->vga_unit__DOT__master__DOT__up_addr;
	vlTOPp->vga_unit__DOT__master__DOT__down_addr_next 
	    = vlTOPp->vga_unit__DOT__master__DOT__down_addr;
	vlTOPp->vga_unit__DOT__master__DOT__sync = 0U;
	if (VL_UNLIKELY((0x10U == (IData)(vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress)))) {
	    VL_WRITEF("vga_master: pixel buffer full\n");
	}
	if (VL_UNLIKELY(vlTOPp->vga_unit__DOT__slave_waitrequest)) {
	    VL_WRITEF("vga_master: sdram asks us to wait\n");
	}
	if (VL_UNLIKELY(((~ (IData)(vlTOPp->vga_unit__DOT__slave_waitrequest)) 
			 & (0x10U > (IData)(vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress))))) {
	    VL_WRITEF("vga_master: sending request %8#\n",
		      26,vlTOPp->vga_unit__DOT__master__DOT__offset8_cur_addr);
	    vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress_next 
		= (0x1fU & ((IData)(1U) + (IData)(vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress_next)));
	    vlTOPp->vga_unit__DOT__master__DOT__wr = 1U;
	    vlTOPp->vga_unit__DOT__master__DOT__din 
		= vlTOPp->vga_unit__DOT__master__DOT__offset8_cur_addr;
	    vlTOPp->vga_unit__DOT__slave_read = 1U;
	    vlTOPp->vga_unit__DOT__slave_address = vlTOPp->vga_unit__DOT__master__DOT__offset8_cur_addr;
	    __Vdly__vga_unit__DOT__master__DOT__cur_addr 
		= vlTOPp->vga_unit__DOT__master__DOT__offset8_cur_addr;
	} else {
	    vlTOPp->vga_unit__DOT__master__DOT__wr = 0U;
	    vlTOPp->vga_unit__DOT__slave_address = vlTOPp->vga_unit__DOT__master__DOT__cur_addr;
	    if ((1U & (~ (IData)(vlTOPp->vga_unit__DOT__slave_waitrequest)))) {
		vlTOPp->vga_unit__DOT__slave_read = 0U;
	    }
	}
	if (VL_UNLIKELY(vlTOPp->vga_unit__DOT__pixel_read)) {
	    // Function: addr_in_range at ../vga_unit_modules.sv:158
	    __Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__down 
		= vlTOPp->vga_unit__DOT__master__DOT__down_addr;
	    __Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__up 
		= vlTOPp->vga_unit__DOT__master__DOT__up_addr;
	    __Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__addr 
		= vlTOPp->vga_unit__DOT__cur_vga_addr;
	    {
		if ((__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__up 
		     > __Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__down)) {
		    __Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__Vfuncout 
			= ((__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__up 
			    > __Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__addr) 
			   & (__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__addr 
			      >= __Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__down));
		    goto __Vlabel1;
		} else {
		    if ((__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__up 
			 < __Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__down)) {
			__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__Vfuncout 
			    = ((__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__addr 
				>= __Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__down) 
			       | (__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__addr 
				  < __Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__up));
			goto __Vlabel1;
		    } else {
			__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__Vfuncout = 0U;
			goto __Vlabel1;
		    }
		}
	    }
	    __Vlabel1: ;
	    if (VL_UNLIKELY(__Vfunc_vga_unit__DOT__master__DOT__addr_in_range__0__Vfuncout)) {
		vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress_next 
		    = (0x1fU & ((IData)(vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress_next) 
				- (IData)(1U)));
		vlTOPp->vga_unit__DOT__pixel_data = 
		    vlTOPp->vga_unit__DOT__master__DOT__pixel_buffer
		    [(0x1fU & VL_MODDIV_III(32, (vlTOPp->vga_unit__DOT__cur_vga_addr 
						 >> 3U), (IData)(0x20U)))];
		VL_WRITEF("write pixel succeed\n");
		vlTOPp->vga_unit__DOT__pixel_valid = 1U;
	    } else {
		vlTOPp->vga_unit__DOT__pixel_valid = 0U;
	    }
	    VL_WRITEF("vga_master: pixel_read cur_vga_addr = %8#\n",
		      26,vlTOPp->vga_unit__DOT__cur_vga_addr);
	    // Function: addr_lt at ../vga_unit_modules.sv:170
	    __Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__second 
		= vlTOPp->vga_unit__DOT__master__DOT__down_addr;
	    __Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__first 
		= vlTOPp->vga_unit__DOT__cur_vga_addr;
	    {
		if ((__Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__first 
		     < __Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__second)) {
		    __Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__Vfuncout = 1U;
		    goto __Vlabel2;
		} else {
		    if ((((IData)(0x100U) + (__Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__first 
					     - vlTOPp->frame_buffer_ptr)) 
			 > ((IData)(0x258000U) + (__Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__second 
						  - vlTOPp->frame_buffer_ptr)))) {
			__Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__Vfuncout = 1U;
			goto __Vlabel2;
		    } else {
			__Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__Vfuncout = 0U;
			goto __Vlabel2;
		    }
		}
	    }
	    __Vlabel2: ;
	    if ((1U & (~ (IData)(__Vfunc_vga_unit__DOT__master__DOT__addr_lt__1__Vfuncout)))) {
		vlTOPp->vga_unit__DOT__master__DOT__down_addr_next 
		    = (0x3ffffffU & ((0x258000U < vlTOPp->vga_unit__DOT__master__DOT__next_vga)
				      ? ((vlTOPp->vga_unit__DOT__master__DOT__next_vga 
					  - (IData)(0x258000U)) 
					 + vlTOPp->frame_buffer_ptr)
				      : (vlTOPp->vga_unit__DOT__master__DOT__next_vga 
					 + vlTOPp->frame_buffer_ptr)));
	    }
	    // Function: addr_lt at ../vga_unit_modules.sv:173
	    __Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__second 
		= vlTOPp->vga_unit__DOT__master__DOT__up_addr;
	    __Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__first 
		= vlTOPp->vga_unit__DOT__cur_vga_addr;
	    {
		if ((__Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__first 
		     < __Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__second)) {
		    __Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__Vfuncout = 1U;
		    goto __Vlabel3;
		} else {
		    if ((((IData)(0x100U) + (__Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__first 
					     - vlTOPp->frame_buffer_ptr)) 
			 > ((IData)(0x258000U) + (__Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__second 
						  - vlTOPp->frame_buffer_ptr)))) {
			__Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__Vfuncout = 1U;
			goto __Vlabel3;
		    } else {
			__Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__Vfuncout = 0U;
			goto __Vlabel3;
		    }
		}
	    }
	    __Vlabel3: ;
	    if (VL_UNLIKELY((1U & ((~ (IData)(__Vfunc_vga_unit__DOT__master__DOT__addr_lt__2__Vfuncout)) 
				   & (~ (IData)(vlTOPp->vga_unit__DOT__master__DOT__addr_invalid)))))) {
		vlTOPp->vga_unit__DOT__master__DOT__sync = 1U;
		VL_WRITEF("vga_master: syncing!\n");
		vlTOPp->vga_unit__DOT__master__DOT__down_addr_next 
		    = (0x3ffffffU & ((0x258000U < vlTOPp->vga_unit__DOT__master__DOT__next_vga128)
				      ? ((vlTOPp->vga_unit__DOT__master__DOT__next_vga128 
					  - (IData)(0x258000U)) 
					 + vlTOPp->frame_buffer_ptr)
				      : (vlTOPp->vga_unit__DOT__master__DOT__next_vga128 
					 + vlTOPp->frame_buffer_ptr)));
		vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress_next = 0U;
		vlTOPp->vga_unit__DOT__master__DOT__up_addr_next 
		    = vlTOPp->vga_unit__DOT__master__DOT__down_addr_next;
		__Vdly__vga_unit__DOT__master__DOT__cur_addr 
		    = (0x3ffffffU & ((0x258000U < vlTOPp->vga_unit__DOT__master__DOT__next_vga120)
				      ? ((vlTOPp->vga_unit__DOT__master__DOT__next_vga120 
					  - (IData)(0x258000U)) 
					 + vlTOPp->frame_buffer_ptr)
				      : (vlTOPp->vga_unit__DOT__master__DOT__next_vga120 
					 + vlTOPp->frame_buffer_ptr)));
	    }
	}
	if (VL_UNLIKELY(((IData)(vlTOPp->vga_unit__DOT__slave_readdatavalid) 
			 & (~ (IData)(vlTOPp->vga_unit__DOT__master__DOT__sync))))) {
	    VL_WRITEF("vga_master: pixel data at %8#: %10#\n",
		      26,vlTOPp->vga_unit__DOT__master__DOT__dout,
		      32,vlTOPp->vga_unit__DOT__slave_readdata);
	    if (VL_UNLIKELY((0U == (IData)(vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__counter)))) {
		VL_WRITEF("[%0t] %%Error: vga_unit_modules.sv:187: Assertion failed in %Nvga_unit.master\n",
			  64,VL_TIME_Q(),vlSymsp->name());
		VL_STOP_MT("../vga_unit_modules.sv",187,"");
	    }
	    if (vlTOPp->vga_unit__DOT__master__DOT__addr_invalid) {
		__Vdlyvval__vga_unit__DOT__master__DOT__pixel_buffer__v0 
		    = vlTOPp->vga_unit__DOT__slave_readdata;
		__Vdlyvset__vga_unit__DOT__master__DOT__pixel_buffer__v0 = 1U;
		__Vdlyvdim0__vga_unit__DOT__master__DOT__pixel_buffer__v0 
		    = (0x1fU & VL_MODDIV_III(32, (vlTOPp->vga_unit__DOT__master__DOT__dout 
						  >> 3U), (IData)(0x20U)));
		vlTOPp->vga_unit__DOT__master__DOT__up_addr_next 
		    = vlTOPp->vga_unit__DOT__master__DOT__offset8_dout;
		vlTOPp->vga_unit__DOT__master__DOT__down_addr_next 
		    = vlTOPp->vga_unit__DOT__master__DOT__up_addr_next;
		vlTOPp->vga_unit__DOT__master__DOT__addr_invalid = 0U;
	    } else {
		if ((vlTOPp->vga_unit__DOT__master__DOT__dout 
		     == vlTOPp->vga_unit__DOT__master__DOT__up_addr)) {
		    __Vdlyvval__vga_unit__DOT__master__DOT__pixel_buffer__v1 
			= vlTOPp->vga_unit__DOT__slave_readdata;
		    __Vdlyvset__vga_unit__DOT__master__DOT__pixel_buffer__v1 = 1U;
		    __Vdlyvdim0__vga_unit__DOT__master__DOT__pixel_buffer__v1 
			= (0x1fU & VL_MODDIV_III(32, 
						 (vlTOPp->vga_unit__DOT__master__DOT__up_addr 
						  >> 3U), (IData)(0x20U)));
		    vlTOPp->vga_unit__DOT__master__DOT__up_addr_next 
			= vlTOPp->vga_unit__DOT__master__DOT__offset8_dout;
		}
	    }
	}
	vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress 
	    = vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress_next;
	vlTOPp->vga_unit__DOT__master__DOT__up_addr 
	    = vlTOPp->vga_unit__DOT__master__DOT__up_addr_next;
	vlTOPp->vga_unit__DOT__master__DOT__down_addr 
	    = vlTOPp->vga_unit__DOT__master__DOT__down_addr_next;
    } else {
	__Vdly__vga_unit__DOT__master__DOT__cur_addr 
	    = (0x3ffffffU & ((IData)(0x80U) + vlTOPp->vga_unit__DOT__cur_vga_addr));
	vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress = 0U;
	vlTOPp->vga_unit__DOT__master__DOT__pixel_in_progress_next = 0U;
	vlTOPp->vga_unit__DOT__pixel_valid = 0U;
	vlTOPp->vga_unit__DOT__master__DOT__up_addr = 0U;
	vlTOPp->vga_unit__DOT__master__DOT__down_addr = 0U;
	vlTOPp->vga_unit__DOT__master__DOT__addr_invalid = 1U;
    }
    vlTOPp->vga_unit__DOT__pixel_read = __Vdly__vga_unit__DOT__pixel_read;
    vlTOPp->vga_unit__DOT__slave_waitrequest = ((IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__read_busy) 
						| (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__write_busy));
    // ALWAYSPOST at ../vga_unit_modules.sv:190
    if (__Vdlyvset__vga_unit__DOT__master__DOT__pixel_buffer__v0) {
	vlTOPp->vga_unit__DOT__master__DOT__pixel_buffer[__Vdlyvdim0__vga_unit__DOT__master__DOT__pixel_buffer__v0] 
	    = __Vdlyvval__vga_unit__DOT__master__DOT__pixel_buffer__v0;
    }
    if (__Vdlyvset__vga_unit__DOT__master__DOT__pixel_buffer__v1) {
	vlTOPp->vga_unit__DOT__master__DOT__pixel_buffer[__Vdlyvdim0__vga_unit__DOT__master__DOT__pixel_buffer__v1] 
	    = __Vdlyvval__vga_unit__DOT__master__DOT__pixel_buffer__v1;
    }
    vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__counter 
	= __Vdly__vga_unit__DOT__master__DOT__buffer__DOT__counter;
    vlTOPp->vga_unit__DOT__master__DOT__cur_addr = __Vdly__vga_unit__DOT__master__DOT__cur_addr;
    vlTOPp->vga_unit__DOT__master__DOT__dout = vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__buffer
	[vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__rd_ptr];
    vlTOPp->vga_unit__DOT__master__DOT__empty = (0U 
						 == (IData)(vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__counter));
    // ALWAYS at ../bus_adapter.sv:129
    if (vlTOPp->reset) {
	if ((0U == (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__rec_state))) {
	    vlTOPp->vga_unit__DOT__slave_readdatavalid = 0U;
	    if (vlTOPp->master_readdatavalid) {
		__Vdly__vga_unit__DOT__bus_adp__DOT__read_data_cache 
		    = vlTOPp->bus_data;
		__Vdly__vga_unit__DOT__bus_adp__DOT__rec_state = 1U;
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__rec_state))) {
		if (vlTOPp->master_readdatavalid) {
		    vlTOPp->vga_unit__DOT__slave_readdata 
			= ((0xffffU & vlTOPp->vga_unit__DOT__slave_readdata) 
			   | ((IData)(vlTOPp->bus_data) 
			      << 0x10U));
		    vlTOPp->vga_unit__DOT__slave_readdatavalid = 1U;
		    __Vdly__vga_unit__DOT__bus_adp__DOT__rec_state = 0U;
		    vlTOPp->vga_unit__DOT__slave_readdata 
			= ((0xffff0000U & vlTOPp->vga_unit__DOT__slave_readdata) 
			   | (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__read_data_cache));
		}
	    }
	}
    } else {
	__Vdly__vga_unit__DOT__bus_adp__DOT__rec_state = 0U;
	vlTOPp->vga_unit__DOT__slave_readdatavalid = 0U;
    }
    vlTOPp->vga_unit__DOT__bus_adp__DOT__read_data_cache 
	= __Vdly__vga_unit__DOT__bus_adp__DOT__read_data_cache;
    vlTOPp->vga_unit__DOT__bus_adp__DOT__rec_state 
	= __Vdly__vga_unit__DOT__bus_adp__DOT__rec_state;
}

void Vvga_unit::_settle__TOP__3(Vvga_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_unit::_settle__TOP__3\n"); );
    Vvga_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->vga_unit__DOT__buffer__DOT__counters__DOT__endOfLine 
	= (0x63fU == (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount));
    vlTOPp->vga_unit__DOT__buffer__DOT__counters__DOT__endOfField 
	= (0x20cU == (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__vcount));
    vlTOPp->VGA_HS = (1U & (~ ((5U == (7U & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
					     >> 8U))) 
			       & (7U != (7U & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
					       >> 5U))))));
    vlTOPp->VGA_VS = (0xf5U != (0x1ffU & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__vcount) 
					  >> 1U)));
    vlTOPp->VGA_BLANK_n = (1U & ((~ (((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
				      >> 0xaU) & (((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
						   >> 9U) 
						  | ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
						     >> 8U)))) 
				 & (~ (((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__vcount) 
					>> 9U) | (0xfU 
						  == 
						  (0xfU 
						   & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__vcount) 
						      >> 5U)))))));
    // ALWAYS at ../bus_adapter.sv:40
    vlTOPp->master_address = ((IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__read_busy)
			       ? vlTOPp->vga_unit__DOT__bus_adp__DOT__master_address_r
			       : vlTOPp->vga_unit__DOT__bus_adp__DOT__master_address_w);
    vlTOPp->vga_unit__DOT__slave_waitrequest = ((IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__read_busy) 
						| (IData)(vlTOPp->vga_unit__DOT__bus_adp__DOT__write_busy));
    vlTOPp->vga_unit__DOT__master__DOT__dout = vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__buffer
	[vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__rd_ptr];
    vlTOPp->vga_unit__DOT__cur_vga_addr = (0x3ffffffU 
					   & (vlTOPp->frame_buffer_ptr 
					      + (((0x3ffU 
						   & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
						      >> 1U)) 
						  + 
						  ((IData)(0x280U) 
						   * (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__vcount))) 
						 << 3U)));
    vlTOPp->vga_unit__DOT__master__DOT__empty = (0U 
						 == (IData)(vlTOPp->vga_unit__DOT__master__DOT__buffer__DOT__counter));
    vlTOPp->vga_unit__DOT__master__DOT__next_cur = 
	(0x3ffffffU & ((IData)(8U) + (vlTOPp->vga_unit__DOT__master__DOT__cur_addr 
				      - vlTOPp->frame_buffer_ptr)));
    vlTOPp->vga_unit__DOT__master__DOT__next_dout = 
	(0x3ffffffU & ((IData)(8U) + (vlTOPp->vga_unit__DOT__master__DOT__dout 
				      - vlTOPp->frame_buffer_ptr)));
    vlTOPp->vga_unit__DOT__master__DOT__next_vga = 
	(0x3ffffffU & ((IData)(8U) + (vlTOPp->vga_unit__DOT__cur_vga_addr 
				      - vlTOPp->frame_buffer_ptr)));
    vlTOPp->vga_unit__DOT__master__DOT__next_vga128 
	= (0x3ffffffU & ((IData)(0x80U) + (vlTOPp->vga_unit__DOT__cur_vga_addr 
					   - vlTOPp->frame_buffer_ptr)));
    vlTOPp->vga_unit__DOT__master__DOT__next_vga120 
	= (0x3ffffffU & ((IData)(0x78U) + (vlTOPp->vga_unit__DOT__cur_vga_addr 
					   - vlTOPp->frame_buffer_ptr)));
    // ALWAYS at ../vga_unit_modules.sv:53
    vlTOPp->vga_unit__DOT__master__DOT__offset8_cur_addr 
	= (0x3ffffffU & ((0x258000U < vlTOPp->vga_unit__DOT__master__DOT__next_cur)
			  ? ((vlTOPp->vga_unit__DOT__master__DOT__next_cur 
			      - (IData)(0x258000U)) 
			     + vlTOPp->frame_buffer_ptr)
			  : (vlTOPp->vga_unit__DOT__master__DOT__next_cur 
			     + vlTOPp->frame_buffer_ptr)));
    // ALWAYS at ../vga_unit_modules.sv:81
    vlTOPp->vga_unit__DOT__master__DOT__offset8_dout 
	= (0x3ffffffU & ((0x258000U < vlTOPp->vga_unit__DOT__master__DOT__next_dout)
			  ? ((vlTOPp->vga_unit__DOT__master__DOT__next_dout 
			      - (IData)(0x258000U)) 
			     + vlTOPp->frame_buffer_ptr)
			  : (vlTOPp->vga_unit__DOT__master__DOT__next_dout 
			     + vlTOPp->frame_buffer_ptr)));
}

VL_INLINE_OPT void Vvga_unit::_combo__TOP__4(Vvga_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_unit::_combo__TOP__4\n"); );
    Vvga_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->vga_unit__DOT__cur_vga_addr = (0x3ffffffU 
					   & (vlTOPp->frame_buffer_ptr 
					      + (((0x3ffU 
						   & ((IData)(vlTOPp->vga_unit__DOT__buffer__DOT__hcount) 
						      >> 1U)) 
						  + 
						  ((IData)(0x280U) 
						   * (IData)(vlTOPp->vga_unit__DOT__buffer__DOT__vcount))) 
						 << 3U)));
    vlTOPp->vga_unit__DOT__master__DOT__next_cur = 
	(0x3ffffffU & ((IData)(8U) + (vlTOPp->vga_unit__DOT__master__DOT__cur_addr 
				      - vlTOPp->frame_buffer_ptr)));
    vlTOPp->vga_unit__DOT__master__DOT__next_dout = 
	(0x3ffffffU & ((IData)(8U) + (vlTOPp->vga_unit__DOT__master__DOT__dout 
				      - vlTOPp->frame_buffer_ptr)));
    vlTOPp->vga_unit__DOT__master__DOT__next_vga = 
	(0x3ffffffU & ((IData)(8U) + (vlTOPp->vga_unit__DOT__cur_vga_addr 
				      - vlTOPp->frame_buffer_ptr)));
    vlTOPp->vga_unit__DOT__master__DOT__next_vga128 
	= (0x3ffffffU & ((IData)(0x80U) + (vlTOPp->vga_unit__DOT__cur_vga_addr 
					   - vlTOPp->frame_buffer_ptr)));
    vlTOPp->vga_unit__DOT__master__DOT__next_vga120 
	= (0x3ffffffU & ((IData)(0x78U) + (vlTOPp->vga_unit__DOT__cur_vga_addr 
					   - vlTOPp->frame_buffer_ptr)));
    // ALWAYS at ../vga_unit_modules.sv:53
    vlTOPp->vga_unit__DOT__master__DOT__offset8_cur_addr 
	= (0x3ffffffU & ((0x258000U < vlTOPp->vga_unit__DOT__master__DOT__next_cur)
			  ? ((vlTOPp->vga_unit__DOT__master__DOT__next_cur 
			      - (IData)(0x258000U)) 
			     + vlTOPp->frame_buffer_ptr)
			  : (vlTOPp->vga_unit__DOT__master__DOT__next_cur 
			     + vlTOPp->frame_buffer_ptr)));
    // ALWAYS at ../vga_unit_modules.sv:81
    vlTOPp->vga_unit__DOT__master__DOT__offset8_dout 
	= (0x3ffffffU & ((0x258000U < vlTOPp->vga_unit__DOT__master__DOT__next_dout)
			  ? ((vlTOPp->vga_unit__DOT__master__DOT__next_dout 
			      - (IData)(0x258000U)) 
			     + vlTOPp->frame_buffer_ptr)
			  : (vlTOPp->vga_unit__DOT__master__DOT__next_dout 
			     + vlTOPp->frame_buffer_ptr)));
}

void Vvga_unit::_eval(Vvga_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_unit::_eval\n"); );
    Vvga_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
	 | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_combo__TOP__4(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vvga_unit::_eval_initial(Vvga_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_unit::_eval_initial\n"); );
    Vvga_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vvga_unit::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_unit::final\n"); );
    // Variables
    Vvga_unit__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vvga_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vvga_unit::_eval_settle(Vvga_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_unit::_eval_settle\n"); );
    Vvga_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vvga_unit::_change_request(Vvga_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_unit::_change_request\n"); );
    Vvga_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vvga_unit::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_unit::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
	Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((frame_buffer_ptr & 0xfc000000U))) {
	Verilated::overWidthError("frame_buffer_ptr");}
    if (VL_UNLIKELY((master_readdatavalid & 0xfeU))) {
	Verilated::overWidthError("master_readdatavalid");}
    if (VL_UNLIKELY((master_waitrequest & 0xfeU))) {
	Verilated::overWidthError("master_waitrequest");}
}
#endif // VL_DEBUG

void Vvga_unit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vvga_unit::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    frame_buffer_ptr = VL_RAND_RESET_I(26);
    master_readdatavalid = VL_RAND_RESET_I(1);
    master_waitrequest = VL_RAND_RESET_I(1);
    master_read = VL_RAND_RESET_I(1);
    master_write = VL_RAND_RESET_I(1);
    master_writedata = VL_RAND_RESET_I(16);
    bus_data = VL_RAND_RESET_I(16);
    master_address = VL_RAND_RESET_I(26);
    VGA_R = VL_RAND_RESET_I(8);
    VGA_G = VL_RAND_RESET_I(8);
    VGA_B = VL_RAND_RESET_I(8);
    VGA_CLK = VL_RAND_RESET_I(1);
    VGA_HS = VL_RAND_RESET_I(1);
    VGA_VS = VL_RAND_RESET_I(1);
    VGA_BLANK_n = VL_RAND_RESET_I(1);
    VGA_SYNC_n = VL_RAND_RESET_I(1);
    vga_unit__DOT__pixel_read = VL_RAND_RESET_I(1);
    vga_unit__DOT__cur_vga_addr = VL_RAND_RESET_I(26);
    vga_unit__DOT__pixel_data = VL_RAND_RESET_I(32);
    vga_unit__DOT__pixel_valid = VL_RAND_RESET_I(1);
    vga_unit__DOT__slave_readdatavalid = VL_RAND_RESET_I(1);
    vga_unit__DOT__slave_waitrequest = VL_RAND_RESET_I(1);
    vga_unit__DOT__slave_readdata = VL_RAND_RESET_I(32);
    vga_unit__DOT__slave_write = VL_RAND_RESET_I(1);
    vga_unit__DOT__slave_read = VL_RAND_RESET_I(1);
    vga_unit__DOT__slave_writedata = VL_RAND_RESET_I(32);
    vga_unit__DOT__slave_address = VL_RAND_RESET_I(26);
    vga_unit__DOT__bus_adp__DOT__read_state = VL_RAND_RESET_I(3);
    vga_unit__DOT__bus_adp__DOT__rec_state = VL_RAND_RESET_I(2);
    vga_unit__DOT__bus_adp__DOT__write_state = VL_RAND_RESET_I(3);
    vga_unit__DOT__bus_adp__DOT__master_address_r = VL_RAND_RESET_I(26);
    vga_unit__DOT__bus_adp__DOT__master_address_w = VL_RAND_RESET_I(26);
    vga_unit__DOT__bus_adp__DOT__read_busy = VL_RAND_RESET_I(1);
    vga_unit__DOT__bus_adp__DOT__write_busy = VL_RAND_RESET_I(1);
    vga_unit__DOT__bus_adp__DOT__read_addr_cache = VL_RAND_RESET_I(26);
    vga_unit__DOT__bus_adp__DOT__prev_state = VL_RAND_RESET_I(3);
    vga_unit__DOT__bus_adp__DOT__read_data_cache = VL_RAND_RESET_I(16);
    vga_unit__DOT__bus_adp__DOT__write_data_cache = VL_RAND_RESET_I(32);
    vga_unit__DOT__bus_adp__DOT__write_addr_cache = VL_RAND_RESET_I(26);
    vga_unit__DOT__bus_adp__DOT__prev_state_w = VL_RAND_RESET_I(3);
    vga_unit__DOT__master__DOT__cur_addr = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__wr = VL_RAND_RESET_I(1);
    vga_unit__DOT__master__DOT__din = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__dout = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__up_addr = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__up_addr_next = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__down_addr = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__down_addr_next = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__addr_invalid = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
	    vga_unit__DOT__master__DOT__pixel_buffer[__Vi0] = VL_RAND_RESET_I(32);
    }}
    vga_unit__DOT__master__DOT__pixel_in_progress = VL_RAND_RESET_I(5);
    vga_unit__DOT__master__DOT__pixel_in_progress_next = VL_RAND_RESET_I(5);
    vga_unit__DOT__master__DOT__empty = VL_RAND_RESET_I(1);
    vga_unit__DOT__master__DOT__sync = VL_RAND_RESET_I(1);
    vga_unit__DOT__master__DOT__next_cur = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__offset8_cur_addr = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__next_vga = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__next_vga128 = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__next_vga120 = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__next_dout = VL_RAND_RESET_I(26);
    vga_unit__DOT__master__DOT__offset8_dout = VL_RAND_RESET_I(26);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    vga_unit__DOT__master__DOT__buffer__DOT__buffer[__Vi0] = VL_RAND_RESET_I(26);
    }}
    vga_unit__DOT__master__DOT__buffer__DOT__wr_ptr = VL_RAND_RESET_I(4);
    vga_unit__DOT__master__DOT__buffer__DOT__rd_ptr = VL_RAND_RESET_I(4);
    vga_unit__DOT__master__DOT__buffer__DOT__counter = VL_RAND_RESET_I(4);
    vga_unit__DOT__master__DOT__buffer__DOT__new_counter = VL_RAND_RESET_I(4);
    vga_unit__DOT__buffer__DOT__hcount = VL_RAND_RESET_I(11);
    vga_unit__DOT__buffer__DOT__vcount = VL_RAND_RESET_I(10);
    vga_unit__DOT__buffer__DOT__clk_counter = VL_RAND_RESET_I(1);
    vga_unit__DOT__buffer__DOT__read_state = 0;
    vga_unit__DOT__buffer__DOT__counters__DOT__endOfLine = VL_RAND_RESET_I(1);
    vga_unit__DOT__buffer__DOT__counters__DOT__endOfField = VL_RAND_RESET_I(1);
}
