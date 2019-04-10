// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrasterizer_fetch_logic.h for the primary calling header

#include "Vrasterizer_fetch_logic.h"
#include "Vrasterizer_fetch_logic__Syms.h"


//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vrasterizer_fetch_logic) {
    Vrasterizer_fetch_logic__Syms* __restrict vlSymsp = __VlSymsp = new Vrasterizer_fetch_logic__Syms(this, name());
    Vrasterizer_fetch_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vrasterizer_fetch_logic::__Vconfigure(Vrasterizer_fetch_logic__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vrasterizer_fetch_logic::~Vrasterizer_fetch_logic() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vrasterizer_fetch_logic::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrasterizer_fetch_logic::eval\n"); );
    Vrasterizer_fetch_logic__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vrasterizer_fetch_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vrasterizer_fetch_logic::_eval_initial_loop(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp) {
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

VL_INLINE_OPT void Vrasterizer_fetch_logic::_sequent__TOP__1(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_fetch_logic::_sequent__TOP__1\n"); );
    Vrasterizer_fetch_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__wr_ptr,3,0);
    VL_SIG8(__Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr,3,0);
    VL_SIG8(__Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__counter,3,0);
    VL_SIG8(__Vdlyvdim0__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0,3,0);
    VL_SIG8(__Vdlyvset__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0,0,0);
    VL_SIGW(__Vdlyvval__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0,95,0,3);
    // Body
    __Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr 
	= vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr;
    __Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__wr_ptr 
	= vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__wr_ptr;
    __Vdlyvset__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0 = 0U;
    __Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__counter 
	= vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__counter;
    // ALWAYS at ..//fifo.sv:40
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
	VL_WRITEF("reset\n");
	vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__new_counter = 0U;
	__Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__wr_ptr = 0U;
	__Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr = 0U;
	__Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__counter = 0U;
    }
    vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__new_counter 
	= vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__counter;
    VL_WRITEF("new_counter = %2#\n",4,vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__new_counter);
    if (VL_UNLIKELY(((IData)(vlTOPp->master_readdatavalid) 
		     & (~ (IData)(vlTOPp->rasterizer_fetch_logic__DOT__empty))))) {
	VL_WRITEF("fifo pop\n");
	__Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr 
	    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr)));
	vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__new_counter 
	    = (0xfU & ((IData)(vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__new_counter) 
		       - (IData)(1U)));
    }
    if (VL_UNLIKELY(vlTOPp->rasterizer_fetch_logic__DOT__wrreq)) {
	VL_WRITEF("fifo write\n");
	vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__new_counter 
	    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__new_counter)));
	__Vdlyvval__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0[0U] 
	    = vlTOPp->rasterizer_fetch_logic__DOT__data_in[0U];
	__Vdlyvval__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0[1U] 
	    = vlTOPp->rasterizer_fetch_logic__DOT__data_in[1U];
	__Vdlyvval__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0[2U] 
	    = vlTOPp->rasterizer_fetch_logic__DOT__data_in[2U];
	__Vdlyvset__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0 = 1U;
	__Vdlyvdim0__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0 
	    = vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__wr_ptr;
	__Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__wr_ptr 
	    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__wr_ptr)));
    }
    __Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__counter 
	= vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__new_counter;
    VL_WRITEF("new_counter = %2#\n",4,vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__new_counter);
    VL_WRITEF("counter = %2#\n",4,vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__counter);
    vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__wr_ptr 
	= __Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__wr_ptr;
    // ALWAYS at ../rasterizer_fetch_logic.sv:57
    if (vlTOPp->reset) {
	if (VL_UNLIKELY(vlTOPp->input_valid)) {
	    VL_WRITEF("enqueue fetch request addr = %x\n",
		      26,vlTOPp->addr_in);
	    vlTOPp->rasterizer_fetch_logic__DOT__wrreq = 1U;
	    vlTOPp->rasterizer_fetch_logic__DOT__data_in[0U] 
		= ((0xfc000000U & vlTOPp->rasterizer_fetch_logic__DOT__data_in[0U]) 
		   | vlTOPp->addr_in);
	    vlTOPp->master_address = (0x3ffffffU & 
				      ((IData)(4U) 
				       + vlTOPp->addr_in));
	    vlTOPp->master_read = 1U;
	    vlTOPp->master_write = 0U;
	    vlTOPp->master_byteenable = 3U;
	    vlTOPp->rasterizer_fetch_logic__DOT__data_in[0U] 
		= ((0x3ffffffU & vlTOPp->rasterizer_fetch_logic__DOT__data_in[0U]) 
		   | (0xfc000000U & (vlTOPp->color_in 
				     << 0x1aU)));
	    vlTOPp->rasterizer_fetch_logic__DOT__data_in[1U] 
		= ((0xfffc0000U & vlTOPp->rasterizer_fetch_logic__DOT__data_in[1U]) 
		   | (0x3ffffffU & (vlTOPp->color_in 
				    >> 6U)));
	    vlTOPp->rasterizer_fetch_logic__DOT__data_in[1U] 
		= ((0x3ffffU & vlTOPp->rasterizer_fetch_logic__DOT__data_in[1U]) 
		   | (0xfffc0000U & (vlTOPp->depth_in 
				     << 0x12U)));
	    vlTOPp->rasterizer_fetch_logic__DOT__data_in[2U] 
		= ((0xfffc0000U & vlTOPp->rasterizer_fetch_logic__DOT__data_in[2U]) 
		   | (0x3ffffU & (vlTOPp->depth_in 
				  >> 0xeU)));
	    vlTOPp->rasterizer_fetch_logic__DOT__data_in[2U] 
		= (0x3ffffU & vlTOPp->rasterizer_fetch_logic__DOT__data_in[2U]);
	} else {
	    vlTOPp->rasterizer_fetch_logic__DOT__wrreq = 0U;
	    vlTOPp->master_read = 0U;
	}
	if (vlTOPp->master_readdatavalid) {
	    if (VL_UNLIKELY((0U == (IData)(vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__counter)))) {
		VL_WRITEF("[%0t] %%Error: rasterizer_fetch_logic.sv:91: Assertion failed in %Nrasterizer_fetch_logic\n",
			  64,VL_TIME_Q(),vlSymsp->name());
		VL_STOP_MT("../rasterizer_fetch_logic.sv",91,"");
	    }
	    vlTOPp->old_depth_out = vlTOPp->master_readdata;
	    vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[0U] 
		= vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__buffer
		[vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr][0U];
	    vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[1U] 
		= vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__buffer
		[vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr][1U];
	    vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[2U] 
		= vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__buffer
		[vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr][2U];
	    vlTOPp->output_valid = 1U;
	} else {
	    vlTOPp->output_valid = 0U;
	}
    } else {
	vlTOPp->rasterizer_fetch_logic__DOT__wrreq = 0U;
	vlTOPp->output_valid = 0U;
    }
    vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr 
	= __Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr;
    // ALWAYSPOST at ..//fifo.sv:59
    if (__Vdlyvset__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0) {
	vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0][0U] 
	    = __Vdlyvval__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0[0U];
	vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0][1U] 
	    = __Vdlyvval__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0[1U];
	vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0][2U] 
	    = __Vdlyvval__rasterizer_fetch_logic__DOT__fifo__DOT__buffer__v0[2U];
    }
    vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__counter 
	= __Vdly__rasterizer_fetch_logic__DOT__fifo__DOT__counter;
    vlTOPp->wait_request = (0xfU <= (IData)(vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__counter));
    vlTOPp->rasterizer_fetch_logic__DOT__empty = (0U 
						  == (IData)(vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__counter));
    vlTOPp->addr_out = (0x3ffffffU & vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[0U]);
    vlTOPp->color_out = (0xffffffU & ((vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[1U] 
				       << 6U) | (vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[0U] 
						 >> 0x1aU)));
    vlTOPp->new_depth_out = ((vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[2U] 
			      << 0xeU) | (vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[1U] 
					  >> 0x12U));
}

void Vrasterizer_fetch_logic::_settle__TOP__2(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_fetch_logic::_settle__TOP__2\n"); );
    Vrasterizer_fetch_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->addr_out = (0x3ffffffU & vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[0U]);
    vlTOPp->color_out = (0xffffffU & ((vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[1U] 
				       << 6U) | (vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[0U] 
						 >> 0x1aU)));
    vlTOPp->new_depth_out = ((vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[2U] 
			      << 0xeU) | (vlTOPp->rasterizer_fetch_logic__DOT__data_out_reg[1U] 
					  >> 0x12U));
    vlTOPp->wait_request = (0xfU <= (IData)(vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__counter));
    vlTOPp->rasterizer_fetch_logic__DOT__empty = (0U 
						  == (IData)(vlTOPp->rasterizer_fetch_logic__DOT__fifo__DOT__counter));
}

void Vrasterizer_fetch_logic::_eval(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_fetch_logic::_eval\n"); );
    Vrasterizer_fetch_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
	 | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
	vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vrasterizer_fetch_logic::_eval_initial(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_fetch_logic::_eval_initial\n"); );
    Vrasterizer_fetch_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vrasterizer_fetch_logic::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_fetch_logic::final\n"); );
    // Variables
    Vrasterizer_fetch_logic__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vrasterizer_fetch_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vrasterizer_fetch_logic::_eval_settle(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_fetch_logic::_eval_settle\n"); );
    Vrasterizer_fetch_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData Vrasterizer_fetch_logic::_change_request(Vrasterizer_fetch_logic__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_fetch_logic::_change_request\n"); );
    Vrasterizer_fetch_logic* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vrasterizer_fetch_logic::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_fetch_logic::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
	Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((master_readdatavalid & 0xfeU))) {
	Verilated::overWidthError("master_readdatavalid");}
    if (VL_UNLIKELY((master_waitrequest & 0xfeU))) {
	Verilated::overWidthError("master_waitrequest");}
    if (VL_UNLIKELY((input_valid & 0xfeU))) {
	Verilated::overWidthError("input_valid");}
    if (VL_UNLIKELY((addr_in & 0xfc000000U))) {
	Verilated::overWidthError("addr_in");}
    if (VL_UNLIKELY((color_in & 0xff000000U))) {
	Verilated::overWidthError("color_in");}
}
#endif // VL_DEBUG

void Vrasterizer_fetch_logic::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_fetch_logic::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    master_address = VL_RAND_RESET_I(26);
    master_read = VL_RAND_RESET_I(1);
    master_write = VL_RAND_RESET_I(1);
    master_byteenable = VL_RAND_RESET_I(4);
    master_readdata = VL_RAND_RESET_I(32);
    master_readdatavalid = VL_RAND_RESET_I(1);
    master_writedata = VL_RAND_RESET_I(32);
    master_waitrequest = VL_RAND_RESET_I(1);
    input_valid = VL_RAND_RESET_I(1);
    addr_in = VL_RAND_RESET_I(26);
    color_in = VL_RAND_RESET_I(24);
    depth_in = VL_RAND_RESET_I(32);
    output_valid = VL_RAND_RESET_I(1);
    addr_out = VL_RAND_RESET_I(26);
    old_depth_out = VL_RAND_RESET_I(32);
    new_depth_out = VL_RAND_RESET_I(32);
    color_out = VL_RAND_RESET_I(24);
    wait_request = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(96,rasterizer_fetch_logic__DOT__data_in);
    rasterizer_fetch_logic__DOT__wrreq = VL_RAND_RESET_I(1);
    rasterizer_fetch_logic__DOT__empty = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(96,rasterizer_fetch_logic__DOT__data_out_reg);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    VL_RAND_RESET_W(96,rasterizer_fetch_logic__DOT__fifo__DOT__buffer[__Vi0]);
    }}
    rasterizer_fetch_logic__DOT__fifo__DOT__wr_ptr = VL_RAND_RESET_I(4);
    rasterizer_fetch_logic__DOT__fifo__DOT__rd_ptr = VL_RAND_RESET_I(4);
    rasterizer_fetch_logic__DOT__fifo__DOT__counter = VL_RAND_RESET_I(4);
    rasterizer_fetch_logic__DOT__fifo__DOT__new_counter = VL_RAND_RESET_I(4);
}
