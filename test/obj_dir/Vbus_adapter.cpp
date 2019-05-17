// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbus_adapter.h for the primary calling header

#include "Vbus_adapter.h"
#include "Vbus_adapter__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vbus_adapter) {
    Vbus_adapter__Syms* __restrict vlSymsp = __VlSymsp = new Vbus_adapter__Syms(this, name());
    Vbus_adapter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbus_adapter::__Vconfigure(Vbus_adapter__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vbus_adapter::~Vbus_adapter() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vbus_adapter::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbus_adapter::eval\n"); );
    Vbus_adapter__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vbus_adapter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vbus_adapter::_eval_initial_loop(Vbus_adapter__Syms* __restrict vlSymsp) {
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

void Vbus_adapter::_initial__TOP__1(Vbus_adapter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbus_adapter::_initial__TOP__1\n"); );
    Vbus_adapter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // INITIAL at ../bus_adapter.sv:36
    vlTOPp->master_byteenable = 3U;
}

VL_INLINE_OPT void Vbus_adapter::_sequent__TOP__2(Vbus_adapter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbus_adapter::_sequent__TOP__2\n"); );
    Vbus_adapter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdly__bus_adapter__DOT__read_state,2,0);
    VL_SIG8(__Vdly__bus_adapter__DOT__rec_state,1,0);
    VL_SIG8(__Vdly__bus_adapter__DOT__write_state,2,0);
    VL_SIG16(__Vdly__bus_adapter__DOT__read_data_cache,15,0);
    VL_SIG(__Vdly__bus_adapter__DOT__read_addr_cache,25,0);
    VL_SIG(__Vdly__bus_adapter__DOT__write_addr_cache,25,0);
    // Body
    __Vdly__bus_adapter__DOT__rec_state = vlTOPp->bus_adapter__DOT__rec_state;
    __Vdly__bus_adapter__DOT__read_data_cache = vlTOPp->bus_adapter__DOT__read_data_cache;
    __Vdly__bus_adapter__DOT__read_addr_cache = vlTOPp->bus_adapter__DOT__read_addr_cache;
    __Vdly__bus_adapter__DOT__read_state = vlTOPp->bus_adapter__DOT__read_state;
    __Vdly__bus_adapter__DOT__write_addr_cache = vlTOPp->bus_adapter__DOT__write_addr_cache;
    __Vdly__bus_adapter__DOT__write_state = vlTOPp->bus_adapter__DOT__write_state;
    // ALWAYS at ../bus_adapter.sv:129
    if (vlTOPp->reset) {
	if ((0U == (IData)(vlTOPp->bus_adapter__DOT__rec_state))) {
	    vlTOPp->slave_readdatavalid = 0U;
	    if (vlTOPp->master_readdatavalid) {
		__Vdly__bus_adapter__DOT__read_data_cache 
		    = vlTOPp->master_readdata;
		__Vdly__bus_adapter__DOT__rec_state = 1U;
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->bus_adapter__DOT__rec_state))) {
		if (vlTOPp->master_readdatavalid) {
		    vlTOPp->slave_readdata = ((0xffffU 
					       & vlTOPp->slave_readdata) 
					      | ((IData)(vlTOPp->master_readdata) 
						 << 0x10U));
		    vlTOPp->slave_readdatavalid = 1U;
		    __Vdly__bus_adapter__DOT__rec_state = 0U;
		    vlTOPp->slave_readdata = ((0xffff0000U 
					       & vlTOPp->slave_readdata) 
					      | (IData)(vlTOPp->bus_adapter__DOT__read_data_cache));
		}
	    }
	}
    } else {
	__Vdly__bus_adapter__DOT__rec_state = 0U;
	vlTOPp->slave_readdatavalid = 0U;
    }
    // ALWAYS at ../bus_adapter.sv:158
    if (vlTOPp->reset) {
	if ((4U & (IData)(vlTOPp->bus_adapter__DOT__write_state))) {
	    if ((1U & (~ ((IData)(vlTOPp->bus_adapter__DOT__write_state) 
			  >> 1U)))) {
		if ((1U & (~ (IData)(vlTOPp->bus_adapter__DOT__write_state)))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_write = 0U;
			__Vdly__bus_adapter__DOT__write_state 
			    = vlTOPp->bus_adapter__DOT__prev_state_w;
		    } else {
			vlTOPp->master_write = 0U;
			vlTOPp->bus_adapter__DOT__write_busy = 0U;
			__Vdly__bus_adapter__DOT__write_state = 0U;
		    }
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->bus_adapter__DOT__write_state))) {
		if ((1U & (IData)(vlTOPp->bus_adapter__DOT__write_state))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_write = 0U;
			__Vdly__bus_adapter__DOT__write_state 
			    = vlTOPp->bus_adapter__DOT__prev_state_w;
		    } else {
			vlTOPp->bus_adapter__DOT__master_address_w 
			    = (0x3ffffffU & ((IData)(2U) 
					     + vlTOPp->bus_adapter__DOT__write_addr_cache));
			vlTOPp->master_writedata = 
			    (0xffffU & vlTOPp->slave_writedata);
			vlTOPp->master_write = 1U;
			vlTOPp->bus_adapter__DOT__prev_state_w = 2U;
			__Vdly__bus_adapter__DOT__write_state = 4U;
			__Vdly__bus_adapter__DOT__write_addr_cache 
			    = (0x3ffffffU & ((IData)(2U) 
					     + vlTOPp->bus_adapter__DOT__write_addr_cache));
		    }
		} else {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_write = 0U;
		    } else {
			vlTOPp->bus_adapter__DOT__master_address_w 
			    = vlTOPp->bus_adapter__DOT__write_addr_cache;
			vlTOPp->master_writedata = 
			    (0xffffU & vlTOPp->slave_writedata);
			vlTOPp->master_write = 1U;
			vlTOPp->bus_adapter__DOT__prev_state_w = 2U;
			__Vdly__bus_adapter__DOT__write_state = 4U;
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->bus_adapter__DOT__write_state))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_write = 0U;
		    } else {
			vlTOPp->bus_adapter__DOT__master_address_w 
			    = vlTOPp->bus_adapter__DOT__write_addr_cache;
			vlTOPp->master_writedata = 
			    (0xffffU & (vlTOPp->bus_adapter__DOT__write_data_cache 
					>> 0x10U));
			vlTOPp->master_write = 1U;
			vlTOPp->bus_adapter__DOT__prev_state_w = 1U;
			__Vdly__bus_adapter__DOT__write_state = 3U;
		    }
		} else {
		    if (vlTOPp->slave_write) {
			vlTOPp->bus_adapter__DOT__write_busy = 1U;
			if (vlTOPp->master_waitrequest) {
			    __Vdly__bus_adapter__DOT__write_addr_cache 
				= vlTOPp->slave_address;
			    vlTOPp->master_write = 0U;
			    vlTOPp->bus_adapter__DOT__write_data_cache 
				= vlTOPp->slave_writedata;
			    __Vdly__bus_adapter__DOT__write_state = 1U;
			} else {
			    __Vdly__bus_adapter__DOT__write_addr_cache 
				= vlTOPp->slave_address;
			    vlTOPp->bus_adapter__DOT__master_address_w 
				= vlTOPp->slave_address;
			    vlTOPp->master_writedata 
				= (0xffffU & (vlTOPp->slave_writedata 
					      >> 0x10U));
			    vlTOPp->master_write = 1U;
			    vlTOPp->bus_adapter__DOT__write_data_cache 
				= vlTOPp->slave_writedata;
			    vlTOPp->bus_adapter__DOT__prev_state_w = 1U;
			    __Vdly__bus_adapter__DOT__write_state = 3U;
			}
		    } else {
			vlTOPp->master_write = 0U;
		    }
		}
	    }
	}
    } else {
	__Vdly__bus_adapter__DOT__write_state = 0U;
	vlTOPp->master_write = 0U;
	vlTOPp->bus_adapter__DOT__write_busy = 0U;
	vlTOPp->bus_adapter__DOT__prev_state_w = 0U;
    }
    // ALWAYS at ../bus_adapter.sv:55
    if (vlTOPp->reset) {
	if ((4U & (IData)(vlTOPp->bus_adapter__DOT__read_state))) {
	    if ((1U & (~ ((IData)(vlTOPp->bus_adapter__DOT__read_state) 
			  >> 1U)))) {
		if ((1U & (~ (IData)(vlTOPp->bus_adapter__DOT__read_state)))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_read = 0U;
			__Vdly__bus_adapter__DOT__read_state 
			    = vlTOPp->bus_adapter__DOT__prev_state;
		    } else {
			vlTOPp->master_read = 0U;
			vlTOPp->bus_adapter__DOT__read_busy = 0U;
			__Vdly__bus_adapter__DOT__read_state = 0U;
		    }
		}
	    }
	} else {
	    if ((2U & (IData)(vlTOPp->bus_adapter__DOT__read_state))) {
		if ((1U & (IData)(vlTOPp->bus_adapter__DOT__read_state))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_read = 0U;
			__Vdly__bus_adapter__DOT__read_state 
			    = vlTOPp->bus_adapter__DOT__prev_state;
		    } else {
			vlTOPp->bus_adapter__DOT__master_address_r 
			    = (0x3ffffffU & ((IData)(2U) 
					     + vlTOPp->bus_adapter__DOT__read_addr_cache));
			vlTOPp->master_read = 1U;
			vlTOPp->bus_adapter__DOT__prev_state = 2U;
			__Vdly__bus_adapter__DOT__read_state = 4U;
			__Vdly__bus_adapter__DOT__read_addr_cache 
			    = (0x3ffffffU & ((IData)(2U) 
					     + vlTOPp->bus_adapter__DOT__read_addr_cache));
		    }
		} else {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_read = 0U;
		    } else {
			vlTOPp->bus_adapter__DOT__master_address_r 
			    = vlTOPp->bus_adapter__DOT__read_addr_cache;
			vlTOPp->master_read = 1U;
			vlTOPp->bus_adapter__DOT__prev_state = 2U;
			__Vdly__bus_adapter__DOT__read_state = 4U;
		    }
		}
	    } else {
		if ((1U & (IData)(vlTOPp->bus_adapter__DOT__read_state))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_read = 0U;
		    } else {
			vlTOPp->bus_adapter__DOT__master_address_r 
			    = vlTOPp->bus_adapter__DOT__read_addr_cache;
			vlTOPp->master_read = 1U;
			vlTOPp->bus_adapter__DOT__prev_state = 1U;
			__Vdly__bus_adapter__DOT__read_state = 3U;
		    }
		} else {
		    if (vlTOPp->slave_read) {
			vlTOPp->bus_adapter__DOT__read_busy = 1U;
			if (vlTOPp->master_waitrequest) {
			    __Vdly__bus_adapter__DOT__read_addr_cache 
				= vlTOPp->slave_address;
			    vlTOPp->master_read = 0U;
			    __Vdly__bus_adapter__DOT__read_state = 1U;
			} else {
			    __Vdly__bus_adapter__DOT__read_addr_cache 
				= vlTOPp->slave_address;
			    vlTOPp->bus_adapter__DOT__master_address_r 
				= vlTOPp->slave_address;
			    vlTOPp->master_read = 1U;
			    vlTOPp->bus_adapter__DOT__prev_state = 1U;
			    __Vdly__bus_adapter__DOT__read_state = 3U;
			}
		    } else {
			vlTOPp->master_read = 0U;
		    }
		}
	    }
	}
    } else {
	__Vdly__bus_adapter__DOT__read_state = 0U;
	vlTOPp->master_read = 0U;
	vlTOPp->bus_adapter__DOT__read_busy = 0U;
	vlTOPp->bus_adapter__DOT__prev_state = 0U;
    }
    vlTOPp->bus_adapter__DOT__read_data_cache = __Vdly__bus_adapter__DOT__read_data_cache;
    vlTOPp->bus_adapter__DOT__rec_state = __Vdly__bus_adapter__DOT__rec_state;
    vlTOPp->bus_adapter__DOT__write_state = __Vdly__bus_adapter__DOT__write_state;
    vlTOPp->bus_adapter__DOT__write_addr_cache = __Vdly__bus_adapter__DOT__write_addr_cache;
    vlTOPp->bus_adapter__DOT__read_state = __Vdly__bus_adapter__DOT__read_state;
    vlTOPp->bus_adapter__DOT__read_addr_cache = __Vdly__bus_adapter__DOT__read_addr_cache;
    vlTOPp->slave_waitrequest = ((IData)(vlTOPp->bus_adapter__DOT__read_busy) 
				 | (IData)(vlTOPp->bus_adapter__DOT__write_busy));
    // ALWAYS at ../bus_adapter.sv:40
    vlTOPp->master_address = ((IData)(vlTOPp->bus_adapter__DOT__read_busy)
			       ? vlTOPp->bus_adapter__DOT__master_address_r
			       : vlTOPp->bus_adapter__DOT__master_address_w);
}

void Vbus_adapter::_settle__TOP__3(Vbus_adapter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbus_adapter::_settle__TOP__3\n"); );
    Vbus_adapter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->slave_waitrequest = ((IData)(vlTOPp->bus_adapter__DOT__read_busy) 
				 | (IData)(vlTOPp->bus_adapter__DOT__write_busy));
    // ALWAYS at ../bus_adapter.sv:40
    vlTOPp->master_address = ((IData)(vlTOPp->bus_adapter__DOT__read_busy)
			       ? vlTOPp->bus_adapter__DOT__master_address_r
			       : vlTOPp->bus_adapter__DOT__master_address_w);
}

void Vbus_adapter::_eval(Vbus_adapter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbus_adapter::_eval\n"); );
    Vbus_adapter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
	 | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vbus_adapter::_eval_initial(Vbus_adapter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbus_adapter::_eval_initial\n"); );
    Vbus_adapter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vbus_adapter::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbus_adapter::final\n"); );
    // Variables
    Vbus_adapter__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbus_adapter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbus_adapter::_eval_settle(Vbus_adapter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbus_adapter::_eval_settle\n"); );
    Vbus_adapter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vbus_adapter::_change_request(Vbus_adapter__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbus_adapter::_change_request\n"); );
    Vbus_adapter* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vbus_adapter::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbus_adapter::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
	Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((slave_write & 0xfeU))) {
	Verilated::overWidthError("slave_write");}
    if (VL_UNLIKELY((slave_read & 0xfeU))) {
	Verilated::overWidthError("slave_read");}
    if (VL_UNLIKELY((slave_address & 0xfc000000U))) {
	Verilated::overWidthError("slave_address");}
    if (VL_UNLIKELY((master_readdatavalid & 0xfeU))) {
	Verilated::overWidthError("master_readdatavalid");}
    if (VL_UNLIKELY((master_waitrequest & 0xfeU))) {
	Verilated::overWidthError("master_waitrequest");}
}
#endif // VL_DEBUG

void Vbus_adapter::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbus_adapter::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    slave_readdatavalid = VL_RAND_RESET_I(1);
    slave_waitrequest = VL_RAND_RESET_I(1);
    slave_write = VL_RAND_RESET_I(1);
    slave_read = VL_RAND_RESET_I(1);
    slave_writedata = VL_RAND_RESET_I(32);
    slave_readdata = VL_RAND_RESET_I(32);
    slave_address = VL_RAND_RESET_I(26);
    master_readdata = VL_RAND_RESET_I(16);
    master_readdatavalid = VL_RAND_RESET_I(1);
    master_waitrequest = VL_RAND_RESET_I(1);
    master_address = VL_RAND_RESET_I(26);
    master_read = VL_RAND_RESET_I(1);
    master_write = VL_RAND_RESET_I(1);
    master_byteenable = VL_RAND_RESET_I(2);
    master_writedata = VL_RAND_RESET_I(16);
    bus_adapter__DOT__read_state = VL_RAND_RESET_I(3);
    bus_adapter__DOT__rec_state = VL_RAND_RESET_I(2);
    bus_adapter__DOT__write_state = VL_RAND_RESET_I(3);
    bus_adapter__DOT__master_address_r = VL_RAND_RESET_I(26);
    bus_adapter__DOT__master_address_w = VL_RAND_RESET_I(26);
    bus_adapter__DOT__read_busy = VL_RAND_RESET_I(1);
    bus_adapter__DOT__write_busy = VL_RAND_RESET_I(1);
    bus_adapter__DOT__read_addr_cache = VL_RAND_RESET_I(26);
    bus_adapter__DOT__prev_state = VL_RAND_RESET_I(3);
    bus_adapter__DOT__read_data_cache = VL_RAND_RESET_I(16);
    bus_adapter__DOT__write_data_cache = VL_RAND_RESET_I(32);
    bus_adapter__DOT__write_addr_cache = VL_RAND_RESET_I(26);
    bus_adapter__DOT__prev_state_w = VL_RAND_RESET_I(3);
}
