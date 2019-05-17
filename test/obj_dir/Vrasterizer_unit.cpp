// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrasterizer_unit.h for the primary calling header

#include "Vrasterizer_unit.h"
#include "Vrasterizer_unit__Syms.h"


//--------------------
// STATIC VARIABLES

// Begin mtask footprint  all: 
VL_ST_SIG8(Vrasterizer_unit::__Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[64],0,0);
VL_ST_SIG8(Vrasterizer_unit::__Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[64],0,0);

//--------------------

VL_CTOR_IMP(Vrasterizer_unit) {
    Vrasterizer_unit__Syms* __restrict vlSymsp = __VlSymsp = new Vrasterizer_unit__Syms(this, name());
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vrasterizer_unit::__Vconfigure(Vrasterizer_unit__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vrasterizer_unit::~Vrasterizer_unit() {
    delete __VlSymsp; __VlSymsp=NULL;
}

//--------------------


void Vrasterizer_unit::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrasterizer_unit::eval\n"); );
    Vrasterizer_unit__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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

void Vrasterizer_unit::_eval_initial_loop(Vrasterizer_unit__Syms* __restrict vlSymsp) {
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

void Vrasterizer_unit::_initial__TOP__1(Vrasterizer_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_initial__TOP__1\n"); );
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__extract_param_value,0,0);
    VL_SIG8(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__extract_param_name,0,0);
    VL_SIG8(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found,0,0);
    VL_SIG8(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__include_white_space,0,0);
    VL_SIG8(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__tmp,8,1);
    VL_SIGW(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout,1600,1,50);
    VL_SIGW(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name,400,1,13);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value_char_count,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name_char_count,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__white_space_count,31,0);
    VL_SIGW(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__reg_string,1600,1,50);
    VL_SIGW(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name,400,1,13);
    VL_SIGW(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value,160,1,5);
    VL_SIGW(__Vtemp1,160,1,5);
    VL_SIGW(__Vtemp4,415,0,13);
    VL_SIGW(__Vtemp6,159,0,5);
    VL_SIGW(__Vtemp10,159,0,5);
    VL_SIGW(__Vtemp14,415,0,13);
    VL_SIGW(__Vtemp19,1600,1,50);
    VL_SIGW(__Vtemp22,415,0,13);
    VL_SIGW(__Vtemp23,1600,1,50);
    VL_SIG(__Vilp,31,0);
    // Body
    // INITIAL at ..//rasterizer_vertex_fetch.sv:41
    vlTOPp->master_byteenable = 0xfU;
    // INITIAL at ..//lpm_divide.v:95
    // Function: GET_PARAMETER_VALUE at ..//lpm_divide.v:126
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[0U] = 0x54495645U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[1U] = 0x504f5349U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[2U] = 0x4e444552U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[3U] = 0x454d4149U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[4U] = 0x504d5f52U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[5U] = 0x4cU;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[6U] = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[7U] = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[8U] = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[9U] = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[0xaU] = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[0xbU] = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[0xcU] = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__reg_string[0U] = 0x54525545U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__reg_string[1U] = 0x4956453dU;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__reg_string[2U] = 0x4f534954U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__reg_string[3U] = 0x44455250U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__reg_string[4U] = 0x4d41494eU;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__reg_string[5U] = 0x4d5f5245U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__reg_string[6U] = 0x4c50U;
    __Vilp = 7U;
    while ((__Vilp <= 0x31U)) {
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__reg_string[__Vilp] = 0U;
	__Vilp = ((IData)(1U) + __Vilp);
    }
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value_char_count = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name_char_count = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__extract_param_value = 1U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__extract_param_name = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__include_white_space = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__white_space_count = 0U;
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__tmp = 0x45U;
    while (((0U != (IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__tmp)) 
	    & (~ (IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)))) {
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__tmp 
	    = (0xffU & __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__reg_string[0U]);
	if (((0x20U != (IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__tmp)) 
	     | (IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__include_white_space))) {
	    if ((0x20U == (IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__tmp))) {
		__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__white_space_count = 1U;
	    } else {
		if ((0x3dU == (IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__tmp))) {
		    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__extract_param_value = 0U;
		    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__extract_param_name = 1U;
		    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__include_white_space = 0U;
		    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__white_space_count = 0U;
		    VL_SHIFTR_WWI(160,160,32, __Vtemp1, __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value, 
				  VL_MULS_III(32,32,32, (IData)(8U), 
					      ((IData)(0x14U) 
					       - __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value_char_count)));
		    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[0U] 
			= __Vtemp1[0U];
		    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[1U] 
			= __Vtemp1[1U];
		    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[2U] 
			= __Vtemp1[2U];
		    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[3U] 
			= __Vtemp1[3U];
		    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[4U] 
			= __Vtemp1[4U];
		    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value_char_count = 0U;
		} else {
		    if ((0x2cU == (IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__tmp))) {
			VL_SHIFTR_WWI(400,400,32, __Vtemp4, __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name, 
				      VL_MULS_III(32,32,32, (IData)(8U), 
						  ((IData)(0x32U) 
						   - __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name_char_count)));
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0U] 
			    = __Vtemp4[0U];
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[1U] 
			    = __Vtemp4[1U];
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[2U] 
			    = __Vtemp4[2U];
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[3U] 
			    = __Vtemp4[3U];
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[4U] 
			    = __Vtemp4[4U];
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[5U] 
			    = __Vtemp4[5U];
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[6U] 
			    = __Vtemp4[6U];
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[7U] 
			    = __Vtemp4[7U];
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[8U] 
			    = __Vtemp4[8U];
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[9U] 
			    = __Vtemp4[9U];
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xaU] 
			    = __Vtemp4[0xaU];
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xbU] 
			    = __Vtemp4[0xbU];
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xcU] 
			    = (0xffffU & __Vtemp4[0xcU]);
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__extract_param_value = 1U;
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__extract_param_name = 0U;
			__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name_char_count = 0U;
			if ((0U == (((((((((((((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0U] 
						^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[0U]) 
					       | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[1U] 
						  ^ 
						  __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[1U])) 
					      | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[2U] 
						 ^ 
						 __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[2U])) 
					     | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[3U] 
						^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[3U])) 
					    | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[4U] 
					       ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[4U])) 
					   | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[5U] 
					      ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[5U])) 
					  | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[6U] 
					     ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[6U])) 
					 | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[7U] 
					    ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[7U])) 
					| (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[8U] 
					   ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[8U])) 
				       | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[9U] 
					  ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[9U])) 
				      | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xaU] 
					 ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[0xaU])) 
				     | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xbU] 
					^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[0xbU])) 
				    | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xcU] 
				       ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[0xcU])))) {
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found = 1U;
			}
		    } else {
			if (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__extract_param_value) {
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value_char_count 
				= ((IData)(1U) + (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value_char_count 
						  + __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__white_space_count));
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__include_white_space = 1U;
			    if (VL_LTS_III(1,32,32, 0U, __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__white_space_count)) {
				__Vtemp6[1U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[2U] 
						 << 0x18U) 
						| (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[1U] 
						   >> 8U));
				__Vtemp6[2U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[3U] 
						 << 0x18U) 
						| (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[2U] 
						   >> 8U));
				__Vtemp6[3U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[4U] 
						 << 0x18U) 
						| (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[3U] 
						   >> 8U));
				__Vtemp6[4U] = (0x20000000U 
						| (0xffffffU 
						   & (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[4U] 
						      >> 8U)));
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[0U] 
				    = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[1U] 
					<< 0x18U) | 
				       (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[0U] 
					>> 8U));
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[1U] 
				    = __Vtemp6[1U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[2U] 
				    = __Vtemp6[2U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[3U] 
				    = __Vtemp6[3U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[4U] 
				    = __Vtemp6[4U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__white_space_count = 0U;
			    }
			    __Vtemp10[1U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[2U] 
					      << 0x18U) 
					     | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[1U] 
						>> 8U));
			    __Vtemp10[2U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[3U] 
					      << 0x18U) 
					     | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[2U] 
						>> 8U));
			    __Vtemp10[3U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[4U] 
					      << 0x18U) 
					     | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[3U] 
						>> 8U));
			    __Vtemp10[4U] = ((0xff000000U 
					      & ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__tmp) 
						 << 0x18U)) 
					     | (0xffffffU 
						& (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[4U] 
						   >> 8U)));
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[0U] 
				= ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[1U] 
				    << 0x18U) | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[0U] 
						 >> 8U));
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[1U] 
				= __Vtemp10[1U];
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[2U] 
				= __Vtemp10[2U];
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[3U] 
				= __Vtemp10[3U];
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value[4U] 
				= __Vtemp10[4U];
			} else {
			    if (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__extract_param_name) {
				__Vtemp14[1U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[2U] 
						  << 0x18U) 
						 | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[1U] 
						    >> 8U));
				__Vtemp14[2U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[3U] 
						  << 0x18U) 
						 | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[2U] 
						    >> 8U));
				__Vtemp14[3U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[4U] 
						  << 0x18U) 
						 | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[3U] 
						    >> 8U));
				__Vtemp14[4U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[5U] 
						  << 0x18U) 
						 | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[4U] 
						    >> 8U));
				__Vtemp14[5U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[6U] 
						  << 0x18U) 
						 | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[5U] 
						    >> 8U));
				__Vtemp14[6U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[7U] 
						  << 0x18U) 
						 | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[6U] 
						    >> 8U));
				__Vtemp14[7U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[8U] 
						  << 0x18U) 
						 | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[7U] 
						    >> 8U));
				__Vtemp14[8U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[9U] 
						  << 0x18U) 
						 | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[8U] 
						    >> 8U));
				__Vtemp14[9U] = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xaU] 
						  << 0x18U) 
						 | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[9U] 
						    >> 8U));
				__Vtemp14[0xaU] = (
						   (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xbU] 
						    << 0x18U) 
						   | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xaU] 
						      >> 8U));
				__Vtemp14[0xbU] = (
						   (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xcU] 
						    << 0x18U) 
						   | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xbU] 
						      >> 8U));
				__Vtemp14[0xcU] = (
						   (0xffffff00U 
						    & ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__tmp) 
						       << 8U)) 
						   | (0xffU 
						      & (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xcU] 
							 >> 8U)));
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0U] 
				    = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[1U] 
					<< 0x18U) | 
				       (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0U] 
					>> 8U));
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[1U] 
				    = __Vtemp14[1U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[2U] 
				    = __Vtemp14[2U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[3U] 
				    = __Vtemp14[3U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[4U] 
				    = __Vtemp14[4U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[5U] 
				    = __Vtemp14[5U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[6U] 
				    = __Vtemp14[6U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[7U] 
				    = __Vtemp14[7U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[8U] 
				    = __Vtemp14[8U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[9U] 
				    = __Vtemp14[9U];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xaU] 
				    = __Vtemp14[0xaU];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xbU] 
				    = __Vtemp14[0xbU];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xcU] 
				    = __Vtemp14[0xcU];
				__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name_char_count 
				    = ((IData)(1U) 
				       + __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name_char_count);
			    }
			}
		    }
		}
	    }
	}
	VL_SHIFTR_WWI(1600,1600,32, __Vtemp19, __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__reg_string, 8U);
	__Vilp = 0U;
	while ((__Vilp <= 0x31U)) {
	    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__reg_string[__Vilp] 
		= __Vtemp19[__Vilp];
	    __Vilp = ((IData)(1U) + __Vilp);
	}
    }
    if (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__extract_param_name) {
	VL_SHIFTR_WWI(400,400,32, __Vtemp22, __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name, 
		      VL_MULS_III(32,32,32, (IData)(8U), 
				  ((IData)(0x32U) - __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name_char_count)));
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0U] 
	    = __Vtemp22[0U];
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[1U] 
	    = __Vtemp22[1U];
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[2U] 
	    = __Vtemp22[2U];
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[3U] 
	    = __Vtemp22[3U];
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[4U] 
	    = __Vtemp22[4U];
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[5U] 
	    = __Vtemp22[5U];
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[6U] 
	    = __Vtemp22[6U];
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[7U] 
	    = __Vtemp22[7U];
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[8U] 
	    = __Vtemp22[8U];
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[9U] 
	    = __Vtemp22[9U];
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xaU] 
	    = __Vtemp22[0xaU];
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xbU] 
	    = __Vtemp22[0xbU];
	__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xcU] 
	    = (0xffffU & __Vtemp22[0xcU]);
	if ((0U == (((((((((((((__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0U] 
				^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[0U]) 
			       | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[1U] 
				  ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[1U])) 
			      | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[2U] 
				 ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[2U])) 
			     | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[3U] 
				^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[3U])) 
			    | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[4U] 
			       ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[4U])) 
			   | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[5U] 
			      ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[5U])) 
			  | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[6U] 
			     ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[6U])) 
			 | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[7U] 
			    ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[7U])) 
			| (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[8U] 
			   ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[8U])) 
		       | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[9U] 
			  ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[9U])) 
		      | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xaU] 
			 ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[0xaU])) 
		     | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xbU] 
			^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[0xbU])) 
		    | (__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_name[0xcU] 
		       ^ __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__compare_param_name[0xcU])))) {
	    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found = 1U;
	}
    }
    VL_EXTEND_WW(1600,160, __Vtemp23, __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_value);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[1U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[1U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[2U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[2U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[3U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[3U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[4U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[4U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[5U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[5U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[6U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[6U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[7U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[7U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[8U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[8U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[9U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[9U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0xaU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0xaU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0xbU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0xbU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0xcU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0xcU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0xdU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0xdU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0xeU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0xeU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0xfU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0xfU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x10U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x10U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x11U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x11U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x12U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x12U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x13U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x13U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x14U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x14U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x15U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x15U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x16U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x16U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x17U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x17U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x18U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x18U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x19U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x19U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x1aU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x1aU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x1bU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x1bU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x1cU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x1cU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x1dU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x1dU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x1eU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x1eU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x1fU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x1fU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x20U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x20U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x21U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x21U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x22U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x22U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x23U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x23U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x24U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x24U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x25U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x25U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x26U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x26U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x27U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x27U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x28U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x28U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x29U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x29U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x2aU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x2aU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x2bU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x2bU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x2cU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x2cU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x2dU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x2dU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x2eU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x2eU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x2fU] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x2fU] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x30U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x30U] : 0U);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0x31U] 
	= ((IData)(__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__param_found)
	    ? __Vtemp23[0x31U] : 0U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__lpm_remainderpositive 
	= (VL_ULL(0xffffffffff) & (((QData)((IData)(
						    __Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[1U])) 
				    << 0x20U) | (QData)((IData)(
								__Vfunc_rasterizer_unit__DOT__raster__DOT__area_divider__DOT__eva__DOT__GET_PARAMETER_VALUE__79__Vfuncout[0U]))));
    if (VL_UNLIKELY(((VL_ULL(0x54525545) == vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__lpm_remainderpositive) 
		     & (VL_ULL(0x46414c5345) == vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__lpm_remainderpositive)))) {
	VL_WRITEF("Error!  LPM_REMAINDERPOSITIVE value must be \"TRUE\" or \"FALSE\".\n");
	VL_WRITEF("Time: %0t  Instance: %Nrasterizer_unit.raster.area_divider\n",
		  64,VL_TIME_Q(),vlSymsp->name());
	VL_FINISH_MT("..//lpm_divide.v",132,"");
    }
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[0U] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[0U] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[1U] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[1U] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[2U] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[2U] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[3U] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[3U] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[4U] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[4U] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[5U] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[5U] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[6U] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[6U] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[7U] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[7U] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[8U] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[8U] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[9U] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[9U] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[0xaU] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[0xaU] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[0xbU] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[0xbU] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[0xcU] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[0xcU] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[0xdU] = VL_ULL(0);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[0xdU] = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr = 0U;
}

VL_INLINE_OPT void Vrasterizer_unit::_sequent__TOP__2(Vrasterizer_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_sequent__TOP__2\n"); );
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__s_count,3,0);
    VL_SIG8(__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__send_state,1,0);
    VL_SIG8(__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__already_pop,0,0);
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v0,3,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v0,0,0);
    VL_SIG8(__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__rec_state,1,0);
    VL_SIG8(__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__r_count,3,0);
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v1,3,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v1,0,0);
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v2,3,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v2,0,0);
    VL_SIG8(__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter,4,0);
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0,3,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0,0,0);
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1,3,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1,0,0);
    VL_SIG8(__Vdly__rasterizer_unit__DOT__stall1,0,0);
    VL_SIG8(__Vdly__rasterizer_unit__DOT__v_calc__DOT__state,1,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v0,0,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v1,0,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v2,0,0);
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v0,3,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v0,0,0);
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1,3,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1,0,0);
    VL_SIG8(__Vdly__rasterizer_unit__DOT__z_test__DOT__state,1,0);
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v0,5,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v0,0,0);
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1,5,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1,0,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__1__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__1__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__1__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__2__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__2__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__2__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__3__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__3__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__3__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__4__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__4__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__4__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__5__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__5__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__5__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__6__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__6__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__6__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__7__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__7__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__7__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__8__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__8__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__8__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__9__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__9__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__9__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__10__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__10__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__10__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__11__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__11__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__11__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__12__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__12__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__12__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__13__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__13__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__13__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__14__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__14__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__14__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__15__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__15__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__15__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__16__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__16__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__17__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__17__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__17__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__18__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__18__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__18__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__19__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__19__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__19__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__20__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__20__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__21__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__21__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__21__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__22__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__22__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__22__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__23__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__23__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__23__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__24__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__24__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__25__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__25__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__25__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__26__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__26__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__26__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__27__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__27__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__27__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__28__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__28__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__29__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__29__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__29__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__30__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__30__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__30__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__31__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__31__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__31__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__32__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__32__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__33__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__33__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__33__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__34__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__34__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__34__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__35__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__35__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__35__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__36__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__36__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__37__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__37__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__37__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__38__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__38__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__38__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__39__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__39__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__39__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__40__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__40__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__41__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__41__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__41__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__42__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__42__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__42__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__43__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__43__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__43__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__44__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__44__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__45__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__45__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__45__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__46__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__46__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__46__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__47__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__47__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__47__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__48__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__48__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__49__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__49__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__49__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__50__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__50__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__50__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__51__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__51__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__51__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__52__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__52__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__53__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__53__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__53__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__54__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__54__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__54__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__55__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__55__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__55__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__56__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__56__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__57__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__57__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__57__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__58__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__58__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__58__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__59__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__59__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__59__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__60__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__60__a,31,0);
    VL_SIG(__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__addr,25,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v0,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v1,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v2,31,0);
    VL_SIGW(__Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1,479,0,15);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v0,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_y__v0,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_z__v0,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_w__v0,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v1,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_y__v1,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_z__v1,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_w__v1,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v2,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_y__v2,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_z__v2,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_w__v2,31,0);
    VL_SIGW(__Vdlyvval__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1,95,0,3);
    VL_SIG(__Vdly__master_address_3,25,0);
    VL_SIG(__Vdly__rasterizer_unit__DOT__z_test__DOT__real_new_depth_out,31,0);
    VL_SIGW(__Vdlyvval__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1,114,0,4);
    // Body
    __Vdly__rasterizer_unit__DOT__z_test__DOT__real_new_depth_out 
	= vlTOPp->rasterizer_unit__DOT__z_test__DOT__real_new_depth_out;
    __Vdly__master_address_3 = vlTOPp->master_address_3;
    __Vdly__rasterizer_unit__DOT__z_test__DOT__state 
	= vlTOPp->rasterizer_unit__DOT__z_test__DOT__state;
    __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__r_count 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__r_count;
    __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__rec_state 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__rec_state;
    __Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v0 = 0U;
    __Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v1 = 0U;
    __Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v2 = 0U;
    vlTOPp->__Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__lighting__v0 = 0U;
    vlTOPp->__Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__MV__v0 = 0U;
    vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__div_counter 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__div_counter;
    vlTOPp->__Vdly__rasterizer_unit__DOT__addr_out 
	= vlTOPp->rasterizer_unit__DOT__addr_out;
    vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__r_state 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__r_state;
    vlTOPp->__Vdly__rasterizer_unit__DOT__rasterizer_output_valid 
	= vlTOPp->rasterizer_unit__DOT__rasterizer_output_valid;
    vlTOPp->__Vdly__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter;
    vlTOPp->__Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__MVP__v0 = 0U;
    __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__already_pop 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__already_pop;
    __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__addr 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__addr;
    __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__send_state 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__send_state;
    __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__s_count 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__s_count;
    vlTOPp->__Vdly__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter 
	= vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter;
    __Vdly__rasterizer_unit__DOT__v_calc__DOT__state 
	= vlTOPp->rasterizer_unit__DOT__v_calc__DOT__state;
    vlTOPp->__Vdly__rasterizer_unit__DOT__out_data_valid 
	= vlTOPp->rasterizer_unit__DOT__out_data_valid;
    __Vdly__rasterizer_unit__DOT__stall1 = vlTOPp->rasterizer_unit__DOT__stall1;
    __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter;
    __Vdlyvset__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v0 = 0U;
    __Vdlyvset__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1 = 0U;
    __Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v0 = 0U;
    __Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v1 = 0U;
    __Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v2 = 0U;
    __Vdlyvset__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v0 = 0U;
    __Vdlyvset__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1 = 0U;
    __Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0 = 0U;
    __Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1 = 0U;
    // ALWAYS at ..//fifo.sv:42
    if (vlTOPp->reset) {
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__new_counter 
	    = vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter;
	if (((IData)(vlTOPp->master_readdatavalid_2) 
	     & (~ (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__empty)))) {
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__new_counter 
		= (0x1fU & ((IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__new_counter) 
			    - (IData)(1U)));
	}
	if (((IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__wrreq) 
	     & (~ (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__full)))) {
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__new_counter 
		= (0x1fU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__new_counter)));
	}
	vlTOPp->__Vdly__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter 
	    = vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__new_counter;
    } else {
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__new_counter = 0U;
	vlTOPp->__Vdly__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter = 0U;
    }
    // ALWAYS at ..//fifo.sv:42
    if (vlTOPp->reset) {
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__new_counter 
	    = vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter;
	if (((IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__rdreq) 
	     & (~ (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__empty)))) {
	    vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__new_counter 
		= (0x7fU & ((IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__new_counter) 
			    - (IData)(1U)));
	}
	if (((IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__wrreq) 
	     & (~ (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__full)))) {
	    vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__new_counter 
		= (0x7fU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__new_counter)));
	}
	vlTOPp->__Vdly__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter 
	    = vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__new_counter;
    } else {
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__new_counter = 0U;
	vlTOPp->__Vdly__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter = 0U;
    }
    // ALWAYS at ..//fifo.sv:42
    if (vlTOPp->reset) {
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__new_counter 
	    = vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter;
	if (((IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__rdreq) 
	     & (~ (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__empty)))) {
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__new_counter 
		= (0x1fU & ((IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__new_counter) 
			    - (IData)(1U)));
	}
	if (((IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__wrreq) 
	     & (~ (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__full)))) {
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__new_counter 
		= (0x1fU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__new_counter)));
	}
	__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter 
	    = vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__new_counter;
    } else {
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__new_counter = 0U;
	__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter = 0U;
    }
    // ALWAYS at ..//fifo.sv:42
    if (vlTOPp->reset) {
	if (((IData)(vlTOPp->master_readdatavalid_2) 
	     & (0U != (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter)))) {
	    __Vdlyvset__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v0 = 1U;
	    __Vdlyvdim0__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v0 
		= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__rd_ptr;
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__rd_ptr 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__rd_ptr)));
	}
	if (((IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__wrreq) 
	     & (0x10U != (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter)))) {
	    __Vdlyvval__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1[0U] 
		= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[0U];
	    __Vdlyvval__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1[1U] 
		= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[1U];
	    __Vdlyvval__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1[2U] 
		= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[2U];
	    __Vdlyvset__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1 = 1U;
	    __Vdlyvdim0__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1 
		= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__wr_ptr;
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__wr_ptr 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__wr_ptr)));
	}
    } else {
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__wr_ptr = 0U;
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__rd_ptr = 0U;
    }
    // ALWAYS at ..//vertex_calc.sv:143
    if (VL_UNLIKELY(vlTOPp->reset)) {
	VL_WRITEF("vertex_calc: state = %1#\n",2,vlTOPp->rasterizer_unit__DOT__v_calc__DOT__state);
	VL_WRITEF("vertex_calc: input_data_valid = %1#\n",
		  1,vlTOPp->rasterizer_unit__DOT__input_data_valid);
	VL_WRITEF("vertex_calc: stall_out = %1#\n",
		  1,vlTOPp->rasterizer_unit__DOT__stall1);
	if ((2U & (IData)(vlTOPp->rasterizer_unit__DOT__v_calc__DOT__state))) {
	    if (VL_LIKELY((1U & (IData)(vlTOPp->rasterizer_unit__DOT__v_calc__DOT__state)))) {
		__Vdly__rasterizer_unit__DOT__stall1 = 1U;
		if ((1U & (~ (IData)(vlTOPp->rasterizer_unit__DOT__stall2)))) {
		    vlTOPp->__Vdly__rasterizer_unit__DOT__out_data_valid = 0U;
		    __Vdly__rasterizer_unit__DOT__v_calc__DOT__state = 0U;
		}
	    } else {
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__1__b 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__2__b 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__3__b 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__4__b 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__1__a 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_x
		    [0U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__2__a 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_y
		    [0U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__3__a 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_z
		    [0U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__4__a 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_w
		    [0U];
		VL_WRITEF("vertex_calc: triangle = (%11d, %11d, %11d), (%11d, %11d, %11d), (%11d, %11d, %11d)\n",
			  32,VL_SHIFTRS_III(32,32,32, 
					    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
					    [0U], 0x10U),
			  32,VL_SHIFTRS_III(32,32,32, 
					    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
					    [1U], 0x10U),
			  32,VL_SHIFTRS_III(32,32,32, 
					    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
					    [2U], 0x10U),
			  32,VL_SHIFTRS_III(32,32,32, 
					    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
					    [4U], 0x10U),
			  32,VL_SHIFTRS_III(32,32,32, 
					    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
					    [5U], 0x10U),
			  32,VL_SHIFTRS_III(32,32,32, 
					    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
					    [6U], 0x10U),
			  32,VL_SHIFTRS_III(32,32,32, 
					    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
					    [8U], 0x10U),
			  32,VL_SHIFTRS_III(32,32,32, 
					    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
					    [9U], 0x10U),
			  32,VL_SHIFTRS_III(32,32,32, 
					    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
					    [0xaU], 0x10U));
		vlTOPp->rasterizer_unit__DOT__color1 
		    = ((0xff0000U & vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color1_r) 
		       | ((0xff00U & (vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color1_g 
				      >> 8U)) | (0xffU 
						 & (vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color1_b 
						    >> 0x10U))));
		vlTOPp->rasterizer_unit__DOT__color2 
		    = ((0xff0000U & vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color2_r) 
		       | ((0xff00U & (vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color2_g 
				      >> 8U)) | (0xffU 
						 & (vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color2_b 
						    >> 0x10U))));
		vlTOPp->rasterizer_unit__DOT__color3 
		    = ((0xff0000U & vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color3_r) 
		       | ((0xff00U & (vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color3_g 
				      >> 8U)) | (0xffU 
						 & (vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color3_b 
						    >> 0x10U))));
		vlTOPp->rasterizer_unit__DOT__done2 
		    = ((0U != vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__tri_num) 
		       & (vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__output_count 
			  == vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__tri_num));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__1__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__1__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__1__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__2__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__2__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__2__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__3__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__3__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__3__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__4__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__4__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__4__b)), 0x10U));
		VL_WRITEF("vertex_calc: color = %8#, %8#, %8#\n",
			  24,(0xffffffU & vlTOPp->rasterizer_unit__DOT__vertex_out
			      [3U]),24,(0xffffffU & 
					vlTOPp->rasterizer_unit__DOT__vertex_out
					[7U]),24,(0xffffffU 
						  & vlTOPp->rasterizer_unit__DOT__vertex_out
						  [0xbU]));
		vlTOPp->__Vdly__rasterizer_unit__DOT__out_data_valid = 1U;
		__Vdly__rasterizer_unit__DOT__stall1 = 0U;
		__Vdly__rasterizer_unit__DOT__v_calc__DOT__state = 3U;
		vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__x_out[0U] 
		    = (__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__1__Vfuncout 
		       + vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width);
		vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__y_out[0U] 
		    = (__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__2__Vfuncout 
		       + vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height);
		vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__z_out[0U] 
		    = (__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__3__Vfuncout 
		       + vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width);
		vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__w_out[0U] 
		    = (__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__4__Vfuncout 
		       + vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height);
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__5__b 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__6__b 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__7__b 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__8__b 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__5__a 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_x
		    [1U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__6__a 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_y
		    [1U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__7__a 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_z
		    [1U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__8__a 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_w
		    [1U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__5__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__5__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__5__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__6__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__6__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__6__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__7__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__7__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__7__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__8__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__8__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__8__b)), 0x10U));
		vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__x_out[1U] 
		    = (__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__5__Vfuncout 
		       + vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width);
		vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__y_out[1U] 
		    = (__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__6__Vfuncout 
		       + vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height);
		vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__z_out[1U] 
		    = (__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__7__Vfuncout 
		       + vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width);
		vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__w_out[1U] 
		    = (__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__8__Vfuncout 
		       + vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height);
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__9__b 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__10__b 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__11__b 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__12__b 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__9__a 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_x
		    [2U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__10__a 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_y
		    [2U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__11__a 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_z
		    [2U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__12__a 
		    = vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_w
		    [2U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__9__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__9__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__9__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__10__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__10__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__10__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__11__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__11__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__11__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__12__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__12__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__12__b)), 0x10U));
		vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__x_out[2U] 
		    = (__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__9__Vfuncout 
		       + vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width);
		vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__y_out[2U] 
		    = (__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__10__Vfuncout 
		       + vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height);
		vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__z_out[2U] 
		    = (__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__11__Vfuncout 
		       + vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width);
		vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__w_out[2U] 
		    = (__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__12__Vfuncout 
		       + vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height);
	    }
	} else {
	    if ((1U & (IData)(vlTOPp->rasterizer_unit__DOT__v_calc__DOT__state))) {
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__16__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [3U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__20__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [7U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__24__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xbU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__28__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xfU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__16__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, VL_ULL(0x10000), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__16__a)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__20__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, VL_ULL(0x10000), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__20__a)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__24__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, VL_ULL(0x10000), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__24__a)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__28__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, VL_ULL(0x10000), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__28__a)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__15__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [2U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__19__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [2U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__23__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [2U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__27__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [2U];
		vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color1_r 
		    = (0xff0000U & vlTOPp->rasterizer_unit__DOT__vertex_out
		       [3U]);
		vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color1_g 
		    = (0xff0000U & (vlTOPp->rasterizer_unit__DOT__vertex_out
				    [3U] << 8U));
		vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color1_b 
		    = (0xff0000U & (vlTOPp->rasterizer_unit__DOT__vertex_out
				    [3U] << 0x10U));
		vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color2_r 
		    = (0xff0000U & vlTOPp->rasterizer_unit__DOT__vertex_out
		       [7U]);
		vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color2_g 
		    = (0xff0000U & (vlTOPp->rasterizer_unit__DOT__vertex_out
				    [7U] << 8U));
		vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color2_b 
		    = (0xff0000U & (vlTOPp->rasterizer_unit__DOT__vertex_out
				    [7U] << 0x10U));
		vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color3_r 
		    = (0xff0000U & vlTOPp->rasterizer_unit__DOT__vertex_out
		       [0xbU]);
		vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color3_g 
		    = (0xff0000U & (vlTOPp->rasterizer_unit__DOT__vertex_out
				    [0xbU] << 8U));
		vlTOPp->rasterizer_unit__DOT__v_calc__DOT__color3_b 
		    = (0xff0000U & (vlTOPp->rasterizer_unit__DOT__vertex_out
				    [0xbU] << 0x10U));
		__Vdly__rasterizer_unit__DOT__v_calc__DOT__state = 2U;
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__15__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [2U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__19__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [6U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__23__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xaU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__27__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xeU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__15__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__15__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__15__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__19__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__19__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__19__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__23__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__23__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__23__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__27__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__27__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__27__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__14__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [1U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__18__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [1U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__22__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [1U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__26__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [1U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__14__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [1U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__18__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [5U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__22__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [9U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__26__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xdU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__14__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__14__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__14__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__18__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__18__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__18__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__22__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__22__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__22__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__26__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__26__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__26__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__13__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [0U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__17__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [0U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__21__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [0U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__25__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [0U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__13__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__17__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [4U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__21__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [8U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__25__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xcU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__13__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__13__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__13__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__17__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__17__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__17__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__21__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__21__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__21__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__25__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__25__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__25__b)), 0x10U));
		__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v0 
		    = (((__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__13__Vfuncout 
			 + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__14__Vfuncout) 
			+ __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__15__Vfuncout) 
		       + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__16__Vfuncout);
		__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v0 = 1U;
		__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_y__v0 
		    = (((__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__17__Vfuncout 
			 + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__18__Vfuncout) 
			+ __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__19__Vfuncout) 
		       + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__20__Vfuncout);
		__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_z__v0 
		    = (((__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__21__Vfuncout 
			 + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__22__Vfuncout) 
			+ __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__23__Vfuncout) 
		       + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__24__Vfuncout);
		__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_w__v0 
		    = (((__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__25__Vfuncout 
			 + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__26__Vfuncout) 
			+ __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__27__Vfuncout) 
		       + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__28__Vfuncout);
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__32__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [3U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__36__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [7U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__40__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xbU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__44__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xfU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__32__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, VL_ULL(0x10000), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__32__a)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__36__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, VL_ULL(0x10000), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__36__a)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__40__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, VL_ULL(0x10000), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__40__a)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__44__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, VL_ULL(0x10000), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__44__a)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__31__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [6U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__35__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [6U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__39__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [6U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__43__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [6U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__31__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [2U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__35__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [6U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__39__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xaU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__43__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xeU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__31__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__31__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__31__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__35__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__35__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__35__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__39__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__39__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__39__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__43__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__43__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__43__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__30__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [5U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__34__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [5U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__38__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [5U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__42__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [5U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__30__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [1U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__34__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [5U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__38__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [9U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__42__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xdU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__30__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__30__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__30__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__34__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__34__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__34__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__38__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__38__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__38__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__42__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__42__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__42__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__29__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [4U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__33__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [4U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__37__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [4U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__41__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [4U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__29__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__33__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [4U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__37__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [8U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__41__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xcU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__29__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__29__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__29__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__33__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__33__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__33__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__37__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__37__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__37__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__41__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__41__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__41__b)), 0x10U));
		__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v1 
		    = (((__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__29__Vfuncout 
			 + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__30__Vfuncout) 
			+ __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__31__Vfuncout) 
		       + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__32__Vfuncout);
		__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v1 = 1U;
		__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_y__v1 
		    = (((__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__33__Vfuncout 
			 + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__34__Vfuncout) 
			+ __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__35__Vfuncout) 
		       + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__36__Vfuncout);
		__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_z__v1 
		    = (((__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__37__Vfuncout 
			 + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__38__Vfuncout) 
			+ __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__39__Vfuncout) 
		       + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__40__Vfuncout);
		__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_w__v1 
		    = (((__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__41__Vfuncout 
			 + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__42__Vfuncout) 
			+ __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__43__Vfuncout) 
		       + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__44__Vfuncout);
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__48__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [3U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__52__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [7U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__56__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xbU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__60__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xfU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__48__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, VL_ULL(0x10000), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__48__a)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__52__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, VL_ULL(0x10000), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__52__a)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__56__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, VL_ULL(0x10000), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__56__a)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__60__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, VL_ULL(0x10000), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__60__a)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__47__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [0xaU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__51__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [0xaU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__55__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [0xaU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__59__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [0xaU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__47__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [2U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__51__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [6U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__55__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xaU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__59__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xeU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__47__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__47__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__47__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__51__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__51__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__51__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__55__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__55__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__55__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__59__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__59__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__59__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__46__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [9U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__50__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [9U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__54__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [9U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__58__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [9U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__46__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [1U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__50__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [5U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__54__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [9U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__58__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xdU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__46__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__46__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__46__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__50__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__50__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__50__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__54__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__54__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__54__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__58__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__58__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__58__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__45__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [8U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__49__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [8U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__53__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [8U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__57__b 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in
		    [8U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__45__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__49__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [4U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__53__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [8U];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__57__a 
		    = vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat
		    [0xcU];
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__45__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__45__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__45__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__49__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__49__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__49__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__53__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__53__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__53__b)), 0x10U));
		__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__57__Vfuncout 
		    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
					     VL_MULS_QQQ(64,64,64, 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__57__a), 
							 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__57__b)), 0x10U));
		__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v2 
		    = (((__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__45__Vfuncout 
			 + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__46__Vfuncout) 
			+ __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__47__Vfuncout) 
		       + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__48__Vfuncout);
		__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v2 = 1U;
		__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_y__v2 
		    = (((__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__49__Vfuncout 
			 + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__50__Vfuncout) 
			+ __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__51__Vfuncout) 
		       + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__52__Vfuncout);
		__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_z__v2 
		    = (((__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__53__Vfuncout 
			 + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__54__Vfuncout) 
			+ __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__55__Vfuncout) 
		       + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__56__Vfuncout);
		__Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_w__v2 
		    = (((__Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__57__Vfuncout 
			 + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__58__Vfuncout) 
			+ __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__59__Vfuncout) 
		       + __Vfunc_rasterizer_unit__DOT__v_calc__DOT__fp_m__60__Vfuncout);
	    } else {
		if (vlTOPp->rasterizer_unit__DOT__input_data_valid) {
		    __Vdly__rasterizer_unit__DOT__stall1 = 1U;
		    __Vdly__rasterizer_unit__DOT__v_calc__DOT__state = 1U;
		}
	    }
	}
    } else {
	vlTOPp->rasterizer_unit__DOT__done2 = 0U;
	__Vdly__rasterizer_unit__DOT__stall1 = 0U;
	vlTOPp->__Vdly__rasterizer_unit__DOT__out_data_valid = 0U;
    }
    // ALWAYS at ..//fifo.sv:42
    if (vlTOPp->reset) {
	if (((IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__rdreq) 
	     & (0U != (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter)))) {
	    __Vdlyvset__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v0 = 1U;
	    __Vdlyvdim0__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v0 
		= vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr;
	    vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr 
		= (0x3fU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr)));
	}
	if (((IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__wrreq) 
	     & (0x40U != (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter)))) {
	    __Vdlyvval__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1[0U] 
		= vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[0U];
	    __Vdlyvval__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1[1U] 
		= vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[1U];
	    __Vdlyvval__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1[2U] 
		= vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[2U];
	    __Vdlyvval__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1[3U] 
		= vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[3U];
	    __Vdlyvset__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1 = 1U;
	    __Vdlyvdim0__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1 
		= vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__wr_ptr;
	    vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__wr_ptr 
		= (0x3fU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__wr_ptr)));
	}
    } else {
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__wr_ptr = 0U;
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr = 0U;
    }
    // ALWAYS at ..//fifo.sv:42
    if (vlTOPp->reset) {
	if (((IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__rdreq) 
	     & (0U != (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter)))) {
	    __Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0 = 1U;
	    __Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr)));
	}
	if (((IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__wrreq) 
	     & (0x10U != (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter)))) {
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[0U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0U];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[1U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[1U];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[2U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[2U];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[3U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[3U];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[4U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[4U];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[5U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[5U];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[6U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[6U];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[7U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[7U];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[8U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[8U];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[9U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[9U];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[0xaU] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xaU];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[0xbU] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xbU];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[0xcU] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xcU];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[0xdU] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xdU];
	    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[0xeU] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xeU];
	    __Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1 = 1U;
	    __Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__wr_ptr;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__wr_ptr 
		= (0xfU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__wr_ptr)));
	}
    } else {
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__wr_ptr = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr = 0U;
    }
    // ALWAYSPOST at ..//fifo.sv:55
    if (__Vdlyvset__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v0) {
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v0][0U] = 0U;
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v0][1U] = 0U;
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v0][2U] = 0U;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1) {
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1][0U] 
	    = __Vdlyvval__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1[0U];
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1][1U] 
	    = __Vdlyvval__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1[1U];
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1][2U] 
	    = __Vdlyvval__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer__v1[2U];
    }
    vlTOPp->rasterizer_unit__DOT__v_calc__DOT__state 
	= __Vdly__rasterizer_unit__DOT__v_calc__DOT__state;
    // ALWAYSPOST at ..//vertex_calc.sv:166
    if (__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v0) {
	vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_w[0U] 
	    = __Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_w__v0;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v1) {
	vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_w[1U] 
	    = __Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_w__v1;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v2) {
	vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_w[2U] 
	    = __Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_w__v2;
    }
    // ALWAYSPOST at ..//vertex_calc.sv:165
    if (__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v0) {
	vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_z[0U] 
	    = __Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_z__v0;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v1) {
	vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_z[1U] 
	    = __Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_z__v1;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v2) {
	vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_z[2U] 
	    = __Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_z__v2;
    }
    // ALWAYSPOST at ..//vertex_calc.sv:164
    if (__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v0) {
	vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_y[0U] 
	    = __Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_y__v0;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v1) {
	vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_y[1U] 
	    = __Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_y__v1;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v2) {
	vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_y[2U] 
	    = __Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_y__v2;
    }
    // ALWAYSPOST at ..//vertex_calc.sv:163
    if (__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v0) {
	vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_x[0U] 
	    = __Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v0;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v1) {
	vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_x[1U] 
	    = __Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v1;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v2) {
	vlTOPp->rasterizer_unit__DOT__v_calc__DOT__tmp_x[2U] 
	    = __Vdlyvval__rasterizer_unit__DOT__v_calc__DOT__tmp_x__v2;
    }
    // ALWAYSPOST at ..//fifo.sv:55
    if (__Vdlyvset__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v0) {
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v0][0U] = 0U;
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v0][1U] = 0U;
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v0][2U] = 0U;
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v0][3U] = 0U;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1) {
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1][0U] 
	    = __Vdlyvval__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1[0U];
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1][1U] 
	    = __Vdlyvval__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1[1U];
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1][2U] 
	    = __Vdlyvval__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1[2U];
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1][3U] 
	    = __Vdlyvval__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer__v1[3U];
    }
    // ALWAYSPOST at ..//fifo.sv:55
    if (__Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0) {
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][0U] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][1U] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][2U] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][3U] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][4U] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][5U] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][6U] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][7U] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][8U] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][9U] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][0xaU] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][0xbU] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][0xcU] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][0xdU] = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v0][0xeU] = 0U;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1) {
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][0U] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[0U];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][1U] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[1U];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][2U] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[2U];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][3U] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[3U];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][4U] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[4U];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][5U] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[5U];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][6U] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[6U];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][7U] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[7U];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][8U] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[8U];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][9U] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[9U];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][0xaU] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[0xaU];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][0xbU] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[0xbU];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][0xcU] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[0xcU];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][0xdU] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[0xdU];
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1][0xeU] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer__v1[0xeU];
    }
    // ALWAYS at ..//ztest.sv:87
    if (vlTOPp->reset) {
	if ((2U & (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__state))) {
	    if ((1U & (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__state))) {
		vlTOPp->rasterizer_unit__DOT__z_test__DOT__rdreq = 0U;
		__Vdly__rasterizer_unit__DOT__z_test__DOT__state = 0U;
	    } else {
		if ((1U & (~ (IData)(vlTOPp->master_waitrequest_3)))) {
		    if ((0U == (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter))) {
			vlTOPp->master_write_3 = 0U;
			__Vdly__rasterizer_unit__DOT__z_test__DOT__state = 0U;
		    } else {
			if ((vlTOPp->rasterizer_unit__DOT__new_depth_out 
			     < ((vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[2U] 
				 << 0xeU) | (vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[1U] 
					     >> 0x12U)))) {
			    VL_WRITEF("ztest: writing color to %8#\n",
				      26,(0x3ffffffU 
					  & vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[0U]));
			    vlTOPp->rasterizer_unit__DOT__z_test__DOT__rdreq = 1U;
			    __Vdly__master_address_3 
				= (0x3ffffffU & vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[0U]);
			    vlTOPp->master_writedata_3 
				= (0xffffffU & ((vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[1U] 
						 << 6U) 
						| (vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[0U] 
						   >> 0x1aU)));
			    vlTOPp->master_write_3 = 1U;
			    __Vdly__rasterizer_unit__DOT__z_test__DOT__real_new_depth_out 
				= vlTOPp->rasterizer_unit__DOT__new_depth_out;
			    __Vdly__rasterizer_unit__DOT__z_test__DOT__state = 1U;
			} else {
			    VL_WRITEF("ztest: failed\n");
			    vlTOPp->rasterizer_unit__DOT__z_test__DOT__rdreq = 1U;
			    vlTOPp->master_write_3 = 0U;
			    vlTOPp->rasterizer_unit__DOT__done5 
				= (1U & (vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[3U] 
					 >> 0x12U));
			    __Vdly__rasterizer_unit__DOT__z_test__DOT__state = 0U;
			}
		    }
		}
	    }
	} else {
	    if ((1U & (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__state))) {
		vlTOPp->rasterizer_unit__DOT__z_test__DOT__rdreq = 0U;
		if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->master_waitrequest_3))))) {
		    VL_WRITEF("ztest: writing depth to %10#\n",
			      32,((IData)(4U) + vlTOPp->master_address_3));
		    __Vdly__master_address_3 = (0x3ffffffU 
						& ((IData)(4U) 
						   + vlTOPp->master_address_3));
		    vlTOPp->master_writedata_3 = vlTOPp->rasterizer_unit__DOT__z_test__DOT__real_new_depth_out;
		    vlTOPp->master_write_3 = 1U;
		    __Vdly__rasterizer_unit__DOT__z_test__DOT__state = 2U;
		}
	    } else {
		if ((0U != (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter))) {
		    if ((vlTOPp->rasterizer_unit__DOT__new_depth_out 
			 < ((vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[2U] 
			     << 0xeU) | (vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[1U] 
					 >> 0x12U)))) {
			VL_WRITEF("ztest: writing color to %8#\n",
				  26,(0x3ffffffU & 
				      vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[0U]));
			vlTOPp->rasterizer_unit__DOT__z_test__DOT__rdreq = 1U;
			__Vdly__master_address_3 = 
			    (0x3ffffffU & vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[0U]);
			vlTOPp->master_writedata_3 
			    = (0xffffffU & ((vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[1U] 
					     << 6U) 
					    | (vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[0U] 
					       >> 0x1aU)));
			vlTOPp->master_write_3 = 1U;
			__Vdly__rasterizer_unit__DOT__z_test__DOT__real_new_depth_out 
			    = vlTOPp->rasterizer_unit__DOT__new_depth_out;
			__Vdly__rasterizer_unit__DOT__z_test__DOT__state = 1U;
		    } else {
			VL_WRITEF("ztest: failed\n");
			vlTOPp->rasterizer_unit__DOT__z_test__DOT__rdreq = 1U;
			vlTOPp->master_write_3 = 0U;
			vlTOPp->rasterizer_unit__DOT__done5 
			    = (1U & (vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[3U] 
				     >> 0x12U));
			__Vdly__rasterizer_unit__DOT__z_test__DOT__state = 3U;
		    }
		}
	    }
	}
    } else {
	vlTOPp->rasterizer_unit__DOT__done5 = 0U;
	__Vdly__rasterizer_unit__DOT__z_test__DOT__state = 0U;
    }
    // ALWAYS at ..//rasterizer_vertex_fetch.sv:84
    if (vlTOPp->reset) {
	if ((0U == (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__send_state))) {
	    if (VL_UNLIKELY((VL_LTS_III(1,32,32, vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__input_count, vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__tri_num) 
			     & VL_GTS_III(1,32,32, 0x10U, vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo_counter)))) {
		VL_WRITEF("vertex_fetch: read addr = %8#\n",
			  26,vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__addr);
		vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo_counter 
		    = ((IData)(1U) + vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo_counter);
		vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__input_count 
		    = ((IData)(1U) + vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__input_count);
		__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__s_count 
		    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__s_count)));
		vlTOPp->master_address = vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__addr;
		vlTOPp->master_read = 1U;
		__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__send_state = 1U;
		__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__addr 
		    = (0x3ffffffU & ((IData)(4U) + vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__addr));
	    }
	    if (VL_UNLIKELY((((0U == vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__tri_num) 
			      & (IData)(vlTOPp->rasterizer_unit__DOT__do_render)) 
			     & (~ (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fetch_tri))))) {
		VL_WRITEF("vertex_fetch: vertex_buffer_base = %8#\n",
			  26,vlTOPp->rasterizer_unit__DOT__vertex_buffer_base);
		vlTOPp->master_address = vlTOPp->rasterizer_unit__DOT__vertex_buffer_base;
		vlTOPp->master_read = 1U;
		vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fetch_tri = 1U;
		__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__addr 
		    = (0x3ffffffU & ((IData)(4U) + vlTOPp->rasterizer_unit__DOT__vertex_buffer_base));
		__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__send_state = 2U;
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__send_state))) {
		if ((0xfU > (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__s_count))) {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_address = (0x3ffffffU 
						  & (vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__addr 
						     - (IData)(4U)));
			vlTOPp->master_read = 1U;
		    } else {
			__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__s_count 
			    = (0xfU & ((IData)(1U) 
				       + (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__s_count)));
			vlTOPp->master_address = vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__addr;
			vlTOPp->master_read = 1U;
			__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__addr 
			    = (0x3ffffffU & ((IData)(4U) 
					     + vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__addr));
		    }
		} else {
		    if (vlTOPp->master_waitrequest) {
			vlTOPp->master_address = (0x3ffffffU 
						  & (vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__addr 
						     - (IData)(4U)));
			vlTOPp->master_read = 1U;
		    } else {
			__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__s_count = 0U;
			vlTOPp->master_read = 0U;
			__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__send_state = 0U;
		    }
		}
	    } else {
		if ((2U == (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__send_state))) {
		    if (VL_LIKELY(vlTOPp->master_waitrequest)) {
			vlTOPp->master_address = (0x3ffffffU 
						  & (vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__addr 
						     - (IData)(4U)));
			vlTOPp->master_read = 1U;
		    } else {
			VL_WRITEF("vertex_fetch: tri_num read request sent\n");
			vlTOPp->master_read = 0U;
			__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__send_state = 0U;
		    }
		}
	    }
	}
	if (VL_UNLIKELY(((IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__recv_valid) 
			 & (0xfU > (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter))))) {
	    VL_WRITEF("vertex_fetch: triangle:\n");
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[0U];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[1U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[1U];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[2U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[2U];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[3U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[3U];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[4U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[4U];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[5U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[5U];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[6U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[6U];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[7U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[7U];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[8U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[8U];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[9U] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[9U];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xaU] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[0xaU];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xbU] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[0xbU];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xcU] 
		= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		[0xcU];
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xdU] 
		= (IData)((((QData)((IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
					    [0xeU])) 
			    << 0x20U) | (QData)((IData)(
							vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
							[0xdU]))));
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xeU] 
		= (IData)(((((QData)((IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
					     [0xeU])) 
			     << 0x20U) | (QData)((IData)(
							 vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
							 [0xdU]))) 
			   >> 0x20U));
	    VL_WRITEF("vertex_fetch: [%x], [%x], [%x]\n",
		      32,vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		      [0U],32,vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		      [1U],32,vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		      [2U]);
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__wrreq = 1U;
	    VL_WRITEF("vertex_fetch: [%x], [%x], [%x]\n",
		      32,vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		      [4U],32,vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		      [5U],32,vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		      [6U]);
	    VL_WRITEF("vertex_fetch: [%x], [%x], [%x]\n",
		      32,vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		      [8U],32,vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		      [9U],32,vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf
		      [0xaU]);
	    VL_WRITEF("vertex_fetch: =====\n");
	} else {
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__wrreq = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0U] = 0xffU;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[1U] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[2U] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[3U] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[4U] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[5U] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[6U] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[7U] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[8U] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[9U] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xaU] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xbU] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xcU] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xdU] = 0U;
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_in[0xeU] = 0U;
	}
	if ((((~ (IData)(vlTOPp->rasterizer_unit__DOT__stall1)) 
	      & (0U != (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter))) 
	     & (~ (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__already_pop)))) {
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo_counter 
		= (vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo_counter 
		   - (IData)(1U));
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__rdreq = 1U;
	    vlTOPp->rasterizer_unit__DOT__input_data_valid = 1U;
	    __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__already_pop = 1U;
	} else {
	    if (vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__already_pop) {
		vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__rdreq = 0U;
		vlTOPp->rasterizer_unit__DOT__input_data_valid = 0U;
		__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__already_pop = 0U;
	    } else {
		vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__rdreq = 0U;
		if ((0U != (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter))) {
		    vlTOPp->rasterizer_unit__DOT__input_data_valid = 1U;
		}
		if ((0U == (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter))) {
		    vlTOPp->rasterizer_unit__DOT__input_data_valid = 0U;
		}
	    }
	}
    } else {
	__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__s_count = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo_counter = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__input_count = 0U;
	__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__send_state = 0U;
	vlTOPp->master_read = 0U;
	__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__already_pop = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fetch_tri = 0U;
    }
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][0U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[1U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][1U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[2U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][2U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[3U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][3U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[4U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][4U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[5U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][5U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[6U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][6U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[7U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][7U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[8U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][8U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[9U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][9U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xaU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][0xaU];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xbU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][0xbU];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xcU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][0xcU];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xdU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][0xdU];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xeU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][0xeU];
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__state 
	= __Vdly__rasterizer_unit__DOT__z_test__DOT__state;
    vlTOPp->master_address_3 = __Vdly__master_address_3;
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__real_new_depth_out 
	= __Vdly__rasterizer_unit__DOT__z_test__DOT__real_new_depth_out;
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[0U] 
	= vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr][0U];
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[1U] 
	= vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr][1U];
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[2U] 
	= vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr][2U];
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[3U] 
	= vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr][3U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__s_count 
	= __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__s_count;
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__send_state 
	= __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__send_state;
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__addr 
	= __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__addr;
    vlTOPp->rasterizer_unit__DOT__stall1 = __Vdly__rasterizer_unit__DOT__stall1;
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__already_pop 
	= __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__already_pop;
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter 
	= __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter;
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[0xeU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xeU];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[0xdU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xdU];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[0xcU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xcU];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[0xbU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xbU];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[0xaU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xaU];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[9U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[9U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[8U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[8U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[7U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[7U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[6U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[6U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[5U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[5U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[4U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[4U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[3U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[3U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[2U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[2U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[1U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[1U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[0U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__empty 
	= (0U == (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter));
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__full 
	= (0x10U == (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter));
    // ALWAYS at ..//rasterizer_vertex_fetch.sv:187
    if (vlTOPp->reset) {
	if ((0U == (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__rec_state))) {
	    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__recv_valid = 0U;
	    if (VL_UNLIKELY(((IData)(vlTOPp->master_readdatavalid) 
			     & (0U != vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__tri_num)))) {
		vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT____Vlvbound1 
		    = vlTOPp->master_readdata;
		VL_WRITEF("vertex_fetch: data = %10#\n",
			  32,(vlTOPp->master_readdata 
			      >> 0x10U));
		if (VL_LIKELY((0xeU >= (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__r_count)))) {
		    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v0 
			= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT____Vlvbound1;
		    __Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v0 = 1U;
		    __Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v0 
			= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__r_count;
		}
		__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__rec_state = 1U;
		__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__r_count 
		    = (0xfU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__r_count)));
	    }
	    if (VL_UNLIKELY(((IData)(vlTOPp->master_readdatavalid) 
			     & (0U == vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__tri_num)))) {
		VL_WRITEF("vertex_fetch: tri_num = %10#\n",
			  32,vlTOPp->master_readdata);
		vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__tri_num 
		    = vlTOPp->master_readdata;
	    }
	} else {
	    if ((1U == (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__rec_state))) {
		if (vlTOPp->master_readdatavalid) {
		    if ((0xeU == (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__r_count))) {
			vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT____Vlvbound2 
			    = vlTOPp->master_readdata;
			VL_WRITEF("vertex_fetch: data = %10#\n",
				  32,(vlTOPp->master_readdata 
				      >> 0x10U));
			vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__output_count 
			    = ((IData)(1U) + vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__output_count);
			if (VL_LIKELY((0xeU >= (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__r_count)))) {
			    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v1 
				= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT____Vlvbound2;
			    __Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v1 = 1U;
			    __Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v1 
				= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__r_count;
			}
			vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__recv_valid = 1U;
			__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__rec_state = 0U;
			__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__r_count = 0U;
		    } else {
			vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT____Vlvbound3 
			    = vlTOPp->master_readdata;
			VL_WRITEF("vertex_fetch: data = %10#\n",
				  32,(vlTOPp->master_readdata 
				      >> 0x10U));
			if (VL_LIKELY((0xeU >= (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__r_count)))) {
			    __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v2 
				= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT____Vlvbound3;
			    __Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v2 = 1U;
			    __Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v2 
				= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__r_count;
			}
			__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__r_count 
			    = (0xfU & ((IData)(1U) 
				       + (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__r_count)));
		    }
		}
	    }
	}
    } else {
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__output_count = 0U;
	__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__rec_state = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__recv_valid = 0U;
	__Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__r_count = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__tri_num = 0U;
    }
    vlTOPp->rasterizer_unit__DOT__vertex_out[0xeU] 
	= vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[0xeU];
    vlTOPp->rasterizer_unit__DOT__vertex_out[0xdU] 
	= vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[0xdU];
    vlTOPp->rasterizer_unit__DOT__vertex_out[0xcU] 
	= vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[0xcU];
    vlTOPp->rasterizer_unit__DOT__vertex_out[0xbU] 
	= vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[0xbU];
    vlTOPp->rasterizer_unit__DOT__vertex_out[0xaU] 
	= vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[0xaU];
    vlTOPp->rasterizer_unit__DOT__vertex_out[9U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[9U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[8U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[8U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[7U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[7U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[6U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[6U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[5U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[5U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[4U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[4U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[3U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[3U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[2U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[2U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[1U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[1U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[0U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[0U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__rec_state 
	= __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__rec_state;
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__r_count 
	= __Vdly__rasterizer_unit__DOT__vertex_fetch__DOT__r_count;
    // ALWAYSPOST at ..//rasterizer_vertex_fetch.sv:200
    if (__Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v0) {
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v0] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v0;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v1) {
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v1] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v1;
    }
    if (__Vdlyvset__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v2) {
	vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf[__Vdlyvdim0__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v2] 
	    = __Vdlyvval__rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf__v2;
    }
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[0xeU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[0xeU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[0xdU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[0xdU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[0xcU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[0xcU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[0xbU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[0xbU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[0xaU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[0xaU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[9U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[9U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[8U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[8U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[7U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[7U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[6U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[6U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[5U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[5U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[4U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[4U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[3U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[3U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[2U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[2U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[1U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[1U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[0U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[0U];
}

VL_INLINE_OPT void Vrasterizer_unit::_sequent__TOP__3(Vrasterizer_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_sequent__TOP__3\n"); );
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe__v0,3,0);
    VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe__v0,0,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe__v0,31,0);
    // Body
    vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr;
    __Vdlyvset__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe__v0 = 0U;
    vlTOPp->__Vdlyvset__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0 = 0U;
    // ALWAYS at ..//lpm_divide.v:186
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT____Vlvbound5 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__tmp_quotient;
    if (VL_LIKELY((0xdU >= (0xfU & vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr)))) {
	vlTOPp->__Vdlyvval__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0 
	    = vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT____Vlvbound5;
	vlTOPp->__Vdlyvset__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0 = 1U;
	vlTOPp->__Vdlyvdim0__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0 
	    = (0xfU & vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr);
    }
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT____Vlvbound6 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__tmp_remain;
    if (VL_LIKELY((0xdU >= (0xfU & vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr)))) {
	__Vdlyvval__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe__v0 
	    = vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT____Vlvbound6;
	__Vdlyvset__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe__v0 = 1U;
	__Vdlyvdim0__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe__v0 
	    = (0xfU & vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr);
    }
    vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr 
	= VL_MODDIVS_III(32, ((IData)(1U) + vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr), (IData)(0xcU));
    // ALWAYS at ..//ztest.sv:53
    if (VL_UNLIKELY(((0x3fU > (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter)) 
		     & (IData)(vlTOPp->rasterizer_unit__DOT__fetch_output_valid)))) {
	VL_WRITEF("ztest: receive data from addr = %8#\n",
		  26,(0x3ffffffU & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out_reg[0U]));
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__wrreq = 1U;
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[0U] 
	    = ((0xfc000000U & vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[0U]) 
	       | (0x3ffffffU & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out_reg[0U]));
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[0U] 
	    = ((0x3ffffffU & vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[0U]) 
	       | (0xfc000000U & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out_reg[0U]));
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[1U] 
	    = ((0xfffc0000U & vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[1U]) 
	       | (0x3ffffU & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out_reg[1U]));
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[1U] 
	    = ((0x3ffffU & vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[1U]) 
	       | (0xfffc0000U & (vlTOPp->rasterizer_unit__DOT__old_depth_out 
				 << 0x12U)));
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[2U] 
	    = ((0xfffc0000U & vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[2U]) 
	       | (0x3ffffU & (vlTOPp->rasterizer_unit__DOT__old_depth_out 
			      >> 0xeU)));
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[2U] 
	    = ((0x3ffffU & vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[2U]) 
	       | (0xfffc0000U & (vlTOPp->rasterizer_unit__DOT__new_depth_out 
				 << 0x12U)));
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[3U] 
	    = ((0x40000U & vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[3U]) 
	       | (0x3ffffU & (vlTOPp->rasterizer_unit__DOT__new_depth_out 
			      >> 0xeU)));
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[3U] 
	    = ((0x3ffffU & vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_in[3U]) 
	       | (0x40000U & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out_reg[2U]));
    } else {
	if (VL_UNLIKELY((0x3fU <= (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter)))) {
	    VL_WRITEF("ztest: almost full!\n");
	}
	vlTOPp->rasterizer_unit__DOT__z_test__DOT__wrreq = 0U;
    }
    // ALWAYSPOST at ..//lpm_divide.v:200
    if (__Vdlyvset__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe__v0) {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[__Vdlyvdim0__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe__v0] 
	    = __Vdlyvval__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe__v0;
    }
}

void Vrasterizer_unit::_settle__TOP__4(Vrasterizer_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_settle__TOP__4\n"); );
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->rasterizer_unit__DOT__v_calc__DOT__width = 0x1400000U;
    vlTOPp->rasterizer_unit__DOT__v_calc__DOT__height = 0xf00000U;
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][0U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[1U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][1U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[2U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][2U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[3U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][3U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[4U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][4U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[5U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][5U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[6U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][6U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[7U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][7U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[8U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][8U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[9U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][9U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xaU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][0xaU];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xbU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][0xbU];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xcU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][0xcU];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xdU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][0xdU];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xeU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr][0xeU];
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[0U] 
	= vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr][0U];
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[1U] 
	= vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr][1U];
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[2U] 
	= vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr][2U];
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[3U] 
	= vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr][3U];
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__empty 
	= (0U == (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter));
    vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__full 
	= (0x10U == (IData)(vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter));
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__empty 
	= (0U == (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter));
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__full 
	= (0x40U == (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter));
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out[0U] 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__rd_ptr][0U];
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out[1U] 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__rd_ptr][1U];
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out[2U] 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__rd_ptr][2U];
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__empty 
	= (0U == (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter));
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__full 
	= (0x10U == (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter));
    vlTOPp->rasterizer_unit__DOT__z_out[3U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__z_out
	[3U];
    vlTOPp->rasterizer_unit__DOT__z_out[2U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__z_out
	[2U];
    vlTOPp->rasterizer_unit__DOT__z_out[1U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__z_out
	[1U];
    vlTOPp->rasterizer_unit__DOT__z_out[0U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__z_out
	[0U];
    vlTOPp->rasterizer_unit__DOT__y_out[3U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__y_out
	[3U];
    vlTOPp->rasterizer_unit__DOT__y_out[2U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__y_out
	[2U];
    vlTOPp->rasterizer_unit__DOT__y_out[1U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__y_out
	[1U];
    vlTOPp->rasterizer_unit__DOT__y_out[0U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__y_out
	[0U];
    vlTOPp->rasterizer_unit__DOT__x_out[3U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__x_out
	[3U];
    vlTOPp->rasterizer_unit__DOT__x_out[2U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__x_out
	[2U];
    vlTOPp->rasterizer_unit__DOT__x_out[1U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__x_out
	[1U];
    vlTOPp->rasterizer_unit__DOT__x_out[0U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__x_out
	[0U];
    // ALWAYS at ..//rasterizer.sv:86
    vlTOPp->rasterizer_unit__DOT__raster__DOT__minX 
	= (VL_LTS_III(1,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t, vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t)
	    ? vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t
	    : vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t);
    if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__minX 
	 > vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t)) {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__minX 
	    = vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t;
    }
    // ALWAYS at ..//rasterizer.sv:86
    vlTOPp->rasterizer_unit__DOT__raster__DOT__maxX 
	= (VL_LTS_III(1,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t, vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t)
	    ? vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t
	    : vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t);
    if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__maxX 
	 < vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t)) {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__maxX 
	    = vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t;
    }
    // ALWAYS at ..//rasterizer.sv:103
    vlTOPp->rasterizer_unit__DOT__raster__DOT__minY 
	= (VL_LTS_III(1,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t, vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t)
	    ? vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t
	    : vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t);
    if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__minY 
	 > vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t)) {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__minY 
	    = vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t;
    }
    // ALWAYS at ..//rasterizer.sv:103
    vlTOPp->rasterizer_unit__DOT__raster__DOT__maxY 
	= (VL_LTS_III(1,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t, vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t)
	    ? vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t
	    : vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t);
    if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__maxY 
	 < vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t)) {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__maxY 
	    = vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t;
    }
    // ALWAYS at ..//rasterizer_fetch_logic.sv:110
    vlTOPp->__Vtableidx1 = (((0x10U == (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter)) 
			     << 5U) | (((IData)(vlTOPp->rasterizer_unit__DOT__rasterizer_output_valid) 
					<< 4U) | ((
						   (0xfU 
						    <= (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter)) 
						   << 3U) 
						  | (((0x20U 
						       <= (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter)) 
						      << 2U) 
						     | (((IData)(vlTOPp->master_waitrequest_2) 
							 << 1U) 
							| (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__state))))));
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__enqueue 
	= vlTOPp->__Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue
	[vlTOPp->__Vtableidx1];
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__next_state 
	= vlTOPp->__Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state
	[vlTOPp->__Vtableidx1];
    // ALWAYS at ..//rasterizer.sv:134
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__b 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__a 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__b 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__a 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__b)), 0x10U));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__w1_tmp 
	= (vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__Vfuncout 
	   + vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__Vfuncout);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__b 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__denom_inv_reg;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__a 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__w1_tmp;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__b)), 0x10U));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__w1 = vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__Vfuncout;
    // ALWAYS at ..//rasterizer.sv:134
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__b 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__a 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__b 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__a 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__b)), 0x10U));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__w2_tmp 
	= (vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__Vfuncout 
	   + vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__Vfuncout);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__b 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__denom_inv_reg;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__a 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__w2_tmp;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__b)), 0x10U));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__w2 = vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__Vfuncout;
    // ALWAYS at ..//rasterizer.sv:158
    vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__e12 
	= VL_LTES_III(1,32,32, 0U, (VL_MULS_III(32,32,32, 
						(vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x_int 
						 - vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t_int), 
						(vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t_int 
						 - vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t_int)) 
				    - VL_MULS_III(32,32,32, 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y_int 
						   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t_int), 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t_int 
						   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t_int))));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__e23 
	= VL_LTES_III(1,32,32, 0U, (VL_MULS_III(32,32,32, 
						(vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x_int 
						 - vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t_int), 
						(vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t_int 
						 - vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t_int)) 
				    - VL_MULS_III(32,32,32, 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y_int 
						   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t_int), 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t_int 
						   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t_int))));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__e31 
	= VL_LTES_III(1,32,32, 0U, (VL_MULS_III(32,32,32, 
						(vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x_int 
						 - vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t_int), 
						(vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t_int 
						 - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t_int)) 
				    - VL_MULS_III(32,32,32, 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y_int 
						   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t_int), 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t_int 
						   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t_int))));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__is_inside 
	= (((IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__e12) 
	    & (IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__e23)) 
	   & (IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__e31));
    // ALWAYS at ..//rasterizer.sv:134
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__b 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__a 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__b 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__a 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__b)), 0x10U));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__denom 
	= (vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__Vfuncout 
	   + vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__Vfuncout);
    // ALWAYS at ..//rasterizer_fetch_logic.sv:97
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__w3 
	= (((IData)(0x10000U) - vlTOPp->rasterizer_unit__DOT__w1) 
	   - vlTOPp->rasterizer_unit__DOT__w2);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__84__b 
	= (0xffU & vlTOPp->rasterizer_unit__DOT__color_out_3);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__84__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__84__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__84__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__a 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__w3;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__85__b 
	= (0xffU & vlTOPp->rasterizer_unit__DOT__color_out_2);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__85__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__85__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__85__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__a 
	= vlTOPp->rasterizer_unit__DOT__w2;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__86__b 
	= (0xffU & vlTOPp->rasterizer_unit__DOT__color_out_1);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__86__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__86__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__86__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__a 
	= vlTOPp->rasterizer_unit__DOT__w1;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__80__f 
	= ((vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__Vfuncout 
	    + vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__Vfuncout) 
	   + vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__Vfuncout);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__80__Vfuncout 
	= (0xffU & (vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__80__f 
		    >> 0x10U));
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in 
	= ((0xffff00U & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in) 
	   | (IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__80__Vfuncout));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__91__b 
	= (0xffU & (vlTOPp->rasterizer_unit__DOT__color_out_3 
		    >> 8U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__91__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__91__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__91__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__a 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__w3;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__92__b 
	= (0xffU & (vlTOPp->rasterizer_unit__DOT__color_out_2 
		    >> 8U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__92__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__92__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__92__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__a 
	= vlTOPp->rasterizer_unit__DOT__w2;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__93__b 
	= (0xffU & (vlTOPp->rasterizer_unit__DOT__color_out_1 
		    >> 8U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__93__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__93__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__93__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__a 
	= vlTOPp->rasterizer_unit__DOT__w1;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__87__f 
	= ((vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__Vfuncout 
	    + vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__Vfuncout) 
	   + vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__Vfuncout);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__87__Vfuncout 
	= (0xffU & (vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__87__f 
		    >> 0x10U));
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in 
	= ((0xff00ffU & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in) 
	   | ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__87__Vfuncout) 
	      << 8U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__98__b 
	= (0xffU & (vlTOPp->rasterizer_unit__DOT__color_out_3 
		    >> 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__98__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__98__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__98__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__a 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__w3;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__99__b 
	= (0xffU & (vlTOPp->rasterizer_unit__DOT__color_out_2 
		    >> 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__99__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__99__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__99__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__a 
	= vlTOPp->rasterizer_unit__DOT__w2;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__100__b 
	= (0xffU & (vlTOPp->rasterizer_unit__DOT__color_out_1 
		    >> 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__100__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__100__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__100__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__a 
	= vlTOPp->rasterizer_unit__DOT__w1;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__94__f 
	= ((vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__Vfuncout 
	    + vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__Vfuncout) 
	   + vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__Vfuncout);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__94__Vfuncout 
	= (0xffU & (vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__94__f 
		    >> 0x10U));
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in 
	= ((0xffffU & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in) 
	   | ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__94__Vfuncout) 
	      << 0x10U));
    // ALWAYS at ..//config_reg.sv:22
    if (vlTOPp->reset) {
	if (vlTOPp->rasterizer_unit__DOT__done5) {
	    vlTOPp->rasterizer_unit__DOT__c_reg__DOT__done_latch = 1U;
	}
    } else {
	vlTOPp->rasterizer_unit__DOT__c_reg__DOT__done_latch = 0U;
    }
    vlTOPp->readdata = (IData)(vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__readdata);
    vlTOPp->rasterizer_unit__DOT__MVP[0xfU] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0xfU];
    vlTOPp->rasterizer_unit__DOT__MVP[0xeU] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0xeU];
    vlTOPp->rasterizer_unit__DOT__MVP[0xdU] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0xdU];
    vlTOPp->rasterizer_unit__DOT__MVP[0xcU] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0xcU];
    vlTOPp->rasterizer_unit__DOT__MVP[0xbU] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0xbU];
    vlTOPp->rasterizer_unit__DOT__MVP[0xaU] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0xaU];
    vlTOPp->rasterizer_unit__DOT__MVP[9U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[9U];
    vlTOPp->rasterizer_unit__DOT__MVP[8U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[8U];
    vlTOPp->rasterizer_unit__DOT__MVP[7U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[7U];
    vlTOPp->rasterizer_unit__DOT__MVP[6U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[6U];
    vlTOPp->rasterizer_unit__DOT__MVP[5U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[5U];
    vlTOPp->rasterizer_unit__DOT__MVP[4U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[4U];
    vlTOPp->rasterizer_unit__DOT__MVP[3U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[3U];
    vlTOPp->rasterizer_unit__DOT__MVP[2U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[2U];
    vlTOPp->rasterizer_unit__DOT__MVP[1U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[1U];
    vlTOPp->rasterizer_unit__DOT__MVP[0U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[0xeU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xeU];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[0xdU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xdU];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[0xcU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xcU];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[0xbU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xbU];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[0xaU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0xaU];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[9U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[9U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[8U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[8U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[7U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[7U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[6U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[6U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[5U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[5U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[4U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[4U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[3U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[3U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[2U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[2U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[1U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[1U];
    vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[0U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_fetch__DOT__data_out[0U];
    vlTOPp->rasterizer_unit__DOT__new_depth_out = (
						   (vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[3U] 
						    << 0xeU) 
						   | (vlTOPp->rasterizer_unit__DOT__z_test__DOT__data_out[2U] 
						      >> 0x12U));
    // ALWAYS at ../rasterizer_unit.sv:163
    VL_WRITEF("vertex_cal_out x1:%5# y1:%5# z1:%5#\n",
	      16,(0xffffU & (vlTOPp->rasterizer_unit__DOT__x_out
			     [0U] >> 0x10U)),16,(0xffffU 
						 & (vlTOPp->rasterizer_unit__DOT__y_out
						    [0U] 
						    >> 0x10U)),
	      16,(0xffffU & (vlTOPp->rasterizer_unit__DOT__z_out
			     [0U] >> 0x10U)));
    VL_WRITEF("vertex_cal_out x2:%5# y2:%5# z2:%5#\n",
	      16,(0xffffU & (vlTOPp->rasterizer_unit__DOT__x_out
			     [1U] >> 0x10U)),16,(0xffffU 
						 & (vlTOPp->rasterizer_unit__DOT__y_out
						    [1U] 
						    >> 0x10U)),
	      16,(0xffffU & (vlTOPp->rasterizer_unit__DOT__z_out
			     [1U] >> 0x10U)));
    VL_WRITEF("vertex_cal_out x3:%5# y3:%5# z3:%5#\n",
	      16,(0xffffU & (vlTOPp->rasterizer_unit__DOT__x_out
			     [2U] >> 0x10U)),16,(0xffffU 
						 & (vlTOPp->rasterizer_unit__DOT__y_out
						    [2U] 
						    >> 0x10U)),
	      16,(0xffffU & (vlTOPp->rasterizer_unit__DOT__z_out
			     [2U] >> 0x10U)));
    // ALWAYS at ..//lpm_divide.v:145
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_d = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_denom 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__denom;
    if ((0x80000000U & vlTOPp->rasterizer_unit__DOT__raster__DOT__denom)) {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_denom 
	    = ((IData)(1U) + (~ vlTOPp->rasterizer_unit__DOT__raster__DOT__denom));
	vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_d = 1U;
    }
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_q 
	= VL_DIV_QQQ(64, VL_ULL(0x100000000), (QData)((IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_denom)));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_r 
	= (IData)(VL_MODDIV_QQQ(64, VL_ULL(0x100000000), (QData)((IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_denom))));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_q 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_d;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__tmp_quotient 
	= ((IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_q)
	    ? (VL_ULL(1) + (~ vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_q))
	    : vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_q);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__tmp_remain 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_r;
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0xfU] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0xfU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0xeU] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0xeU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0xdU] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0xdU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0xcU] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0xcU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0xbU] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0xbU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0xaU] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0xaU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[9U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[9U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[8U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[8U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[7U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[7U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[6U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[6U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[5U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[5U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[4U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[4U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[3U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[3U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[2U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[2U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[1U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[1U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[0xeU] 
	= vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[0xeU];
    vlTOPp->rasterizer_unit__DOT__vertex_out[0xdU] 
	= vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[0xdU];
    vlTOPp->rasterizer_unit__DOT__vertex_out[0xcU] 
	= vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[0xcU];
    vlTOPp->rasterizer_unit__DOT__vertex_out[0xbU] 
	= vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[0xbU];
    vlTOPp->rasterizer_unit__DOT__vertex_out[0xaU] 
	= vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[0xaU];
    vlTOPp->rasterizer_unit__DOT__vertex_out[9U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[9U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[8U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[8U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[7U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[7U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[6U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[6U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[5U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[5U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[4U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[4U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[3U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[3U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[2U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[2U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[1U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[1U];
    vlTOPp->rasterizer_unit__DOT__vertex_out[0U] = 
	vlTOPp->rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out
	[0U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[0xeU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[0xeU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[0xdU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[0xdU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[0xcU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[0xcU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[0xbU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[0xbU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[0xaU] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[0xaU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[9U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[9U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[8U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[8U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[7U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[7U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[6U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[6U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[5U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[5U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[4U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[4U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[3U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[3U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[2U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[2U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[1U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[1U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__v_in[0U] 
	= vlTOPp->rasterizer_unit__DOT__vertex_out[0U];
}

VL_INLINE_OPT void Vrasterizer_unit::_sequent__TOP__5(Vrasterizer_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_sequent__TOP__5\n"); );
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    // Begin mtask footprint  all: 
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT____Vcellout__c_reg__MV__v0,3,0);
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT____Vcellout__c_reg__MVP__v0,3,0);
    VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT____Vcellout__c_reg__lighting__v0,1,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__69__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__69__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__69__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__70__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__70__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__70__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__71__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__71__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__71__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__74__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__74__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__74__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__75__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__75__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__75__b,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__76__Vfuncout,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__76__a,31,0);
    VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__76__b,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT____Vcellout__c_reg__MV__v0,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT____Vcellout__c_reg__MVP__v0,31,0);
    VL_SIG(__Vdlyvval__rasterizer_unit__DOT____Vcellout__c_reg__lighting__v0,31,0);
    // Body
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter 
	= vlTOPp->__Vdly__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter;
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__empty 
	= (0U == (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter));
    vlTOPp->rasterizer_unit__DOT__z_test__DOT__full 
	= (0x40U == (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter));
    // ALWAYS at ..//rasterizer_fetch_logic.sv:147
    if (VL_UNLIKELY(vlTOPp->reset)) {
	if (VL_UNLIKELY((0x10U == (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter)))) {
	    VL_WRITEF("depth_fetcher: fifo is full\n");
	}
	VL_WRITEF("depth_fetcher: master_waitrequest = %1#\n",
		  1,vlTOPp->master_waitrequest_2);
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__state 
	    = vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__next_state;
	VL_WRITEF("input_valid = %1#\n",1,vlTOPp->rasterizer_unit__DOT__rasterizer_output_valid);
	if (vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__enqueue) {
	    VL_WRITEF("depth_fetcher: enqueue fetch request addr = %x\n",
		      26,vlTOPp->rasterizer_unit__DOT__addr_out);
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__wrreq = 1U;
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[0U] 
		= ((0xfc000000U & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[0U]) 
		   | vlTOPp->rasterizer_unit__DOT__addr_out);
	    vlTOPp->master_address_2 = (0x3ffffffU 
					& ((IData)(4U) 
					   + vlTOPp->rasterizer_unit__DOT__addr_out));
	    vlTOPp->master_write_2 = 0U;
	    vlTOPp->master_byteenable_2 = 3U;
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[0U] 
		= ((0x3ffffffU & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[0U]) 
		   | (0xfc000000U & (vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in 
				     << 0x1aU)));
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[1U] 
		= ((0xfffc0000U & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[1U]) 
		   | (0x3ffffffU & (vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in 
				    >> 6U)));
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[1U] 
		= ((0x3ffffU & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[1U]) 
		   | (0xfffc0000U & (vlTOPp->rasterizer_unit__DOT__depth_in 
				     << 0x12U)));
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[2U] 
		= ((0xfffc0000U & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[2U]) 
		   | (0x3ffffU & (vlTOPp->rasterizer_unit__DOT__depth_in 
				  >> 0xeU)));
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[2U] 
		= ((0xfffbffffU & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[2U]) 
		   | (0xfffc0000U & ((IData)(vlTOPp->rasterizer_unit__DOT__done3) 
				     << 0x12U)));
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[2U] 
		= (0x7ffffU & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_in[2U]);
	} else {
	    VL_WRITEF("depth_fetcher: not enqueuing.\n");
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__wrreq = 0U;
	}
	if (vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__next_state) {
	    VL_WRITEF("depth_fetcher: master_read = 1\n");
	    vlTOPp->master_read_2 = 1U;
	} else {
	    VL_WRITEF("depth_fetcher: master_read = 0\n");
	    vlTOPp->master_read_2 = 0U;
	}
	VL_WRITEF("depth_fetcher: next_state = %1#\n",
		  1,vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__next_state);
	if (VL_UNLIKELY(vlTOPp->master_readdatavalid_2)) {
	    VL_WRITEF("depth_fetcher: got fetch request addr = %x\n",
		      26,(0x3ffffffU & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out[0U]));
	    vlTOPp->rasterizer_unit__DOT__old_depth_out 
		= vlTOPp->master_readdata_2;
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out_reg[0U] 
		= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out[0U];
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out_reg[1U] 
		= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out[1U];
	    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out_reg[2U] 
		= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out[2U];
	    vlTOPp->rasterizer_unit__DOT__fetch_output_valid = 1U;
	    if (VL_UNLIKELY((0U == (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter)))) {
		VL_WRITEF("[%0t] %%Error: rasterizer_fetch_logic.sv:200: Assertion failed in %Nrasterizer_unit.fetch_logic\n",
			  64,VL_TIME_Q(),vlSymsp->name());
		VL_STOP_MT("..//rasterizer_fetch_logic.sv",200,"");
	    }
	} else {
	    vlTOPp->rasterizer_unit__DOT__fetch_output_valid = 0U;
	}
    } else {
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__wrreq = 0U;
	vlTOPp->rasterizer_unit__DOT__fetch_output_valid = 0U;
	vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__state = 0U;
    }
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out[0U] 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__rd_ptr][0U];
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out[1U] 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__rd_ptr][1U];
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out[2U] 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer
	[vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__rd_ptr][2U];
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter 
	= vlTOPp->__Vdly__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter;
    vlTOPp->rasterizer_unit__DOT__new_depth_out = (
						   (vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out_reg[2U] 
						    << 0xeU) 
						   | (vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__data_out_reg[1U] 
						      >> 0x12U));
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__empty 
	= (0U == (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter));
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__full 
	= (0x10U == (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter));
    // ALWAYS at ..//rasterizer.sv:215
    if (VL_UNLIKELY(vlTOPp->reset)) {
	VL_WRITEF(" rasterizer: [%1#]==x[%11d]==y[%11d]\n",
		  2,vlTOPp->rasterizer_unit__DOT__raster__DOT__r_state,
		  32,(vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
		      >> 0x10U),32,(vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
				    >> 0x10U));
	VL_WRITEF(" rasterizer: MAXY:[%10#]\n",32,(vlTOPp->rasterizer_unit__DOT__raster__DOT__maxY 
						   >> 0x10U));
	VL_WRITEF(" rasterizer: MAXX:[%10#]\n",32,(vlTOPp->rasterizer_unit__DOT__raster__DOT__maxX 
						   >> 0x10U));
	VL_WRITEF(" rasterizer: OUTPUT_VALID[%1#]\n",
		  1,vlTOPp->rasterizer_unit__DOT__rasterizer_output_valid);
	if ((2U & (IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__r_state))) {
	    if (VL_UNLIKELY((1U & (IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__r_state)))) {
		VL_WRITEF(" rasterizer: STALL_IN[%1#]\n",
			  1,(1U & (~ (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__enqueue))));
		if (vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__enqueue) {
		    if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
			 > vlTOPp->rasterizer_unit__DOT__raster__DOT__maxY)) {
			vlTOPp->rasterizer_unit__DOT__done3 
			    = vlTOPp->rasterizer_unit__DOT__done2;
			vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__r_state = 0U;
		    } else {
			if (VL_UNLIKELY(vlTOPp->rasterizer_unit__DOT__raster__DOT__is_inside)) {
			    vlTOPp->__Vdly__rasterizer_unit__DOT__addr_out 
				= (0x3ffffffU & (vlTOPp->rasterizer_unit__DOT__raster__DOT__addr_in_t 
						 + 
						 ((((IData)(0x280U) 
						    * 
						    (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
						     >> 0x10U)) 
						   + 
						   (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
						    >> 0x10U)) 
						  << 3U)));
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__71__b 
				= vlTOPp->rasterizer_unit__DOT__raster__DOT__z3_t;
			    VL_WRITEF(" rasterizer: addr_out = %x\n",
				      26,vlTOPp->rasterizer_unit__DOT__addr_out);
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__71__a 
				= (((IData)(0x10000U) 
				    - vlTOPp->rasterizer_unit__DOT__raster__DOT__w1) 
				   - vlTOPp->rasterizer_unit__DOT__raster__DOT__w2);
			    vlTOPp->rasterizer_unit__DOT__color_out_1 
				= vlTOPp->rasterizer_unit__DOT__raster__DOT__color1_t;
			    vlTOPp->rasterizer_unit__DOT__color_out_2 
				= vlTOPp->rasterizer_unit__DOT__raster__DOT__color2_t;
			    vlTOPp->rasterizer_unit__DOT__color_out_3 
				= vlTOPp->rasterizer_unit__DOT__raster__DOT__color3_t;
			    vlTOPp->rasterizer_unit__DOT__w1 
				= vlTOPp->rasterizer_unit__DOT__raster__DOT__w1;
			    vlTOPp->rasterizer_unit__DOT__w2 
				= vlTOPp->rasterizer_unit__DOT__raster__DOT__w2;
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__71__Vfuncout 
				= (IData)(VL_SHIFTRS_QQI(64,64,32, 
							 VL_MULS_QQQ(64,64,64, 
								     VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__71__a), 
								     VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__71__b)), 0x10U));
			    vlTOPp->__Vdly__rasterizer_unit__DOT__rasterizer_output_valid = 1U;
			    vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
				= ((IData)(0x10000U) 
				   + vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x);
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__70__b 
				= vlTOPp->rasterizer_unit__DOT__raster__DOT__z2_t;
			    if (VL_UNLIKELY((vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
					     > vlTOPp->rasterizer_unit__DOT__raster__DOT__maxX))) {
				VL_WRITEF("newline\n");
				vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
				    = ((IData)(0x10000U) 
				       + vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y);
				vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
				    = vlTOPp->rasterizer_unit__DOT__raster__DOT__minX;
			    }
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__70__a 
				= vlTOPp->rasterizer_unit__DOT__raster__DOT__w2;
			    if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
				 > vlTOPp->rasterizer_unit__DOT__raster__DOT__maxY)) {
				vlTOPp->rasterizer_unit__DOT__done3 
				    = vlTOPp->rasterizer_unit__DOT__done2;
				vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__r_state = 0U;
			    }
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__70__Vfuncout 
				= (IData)(VL_SHIFTRS_QQI(64,64,32, 
							 VL_MULS_QQQ(64,64,64, 
								     VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__70__a), 
								     VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__70__b)), 0x10U));
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__69__b 
				= vlTOPp->rasterizer_unit__DOT__raster__DOT__z1_t;
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__69__a 
				= vlTOPp->rasterizer_unit__DOT__raster__DOT__w1;
			    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__69__Vfuncout 
				= (IData)(VL_SHIFTRS_QQI(64,64,32, 
							 VL_MULS_QQQ(64,64,64, 
								     VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__69__a), 
								     VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__69__b)), 0x10U));
			    vlTOPp->rasterizer_unit__DOT__depth_in 
				= ((__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__69__Vfuncout 
				    + __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__70__Vfuncout) 
				   + __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__71__Vfuncout);
			} else {
			    vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
				= ((IData)(0x10000U) 
				   + vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x);
			    vlTOPp->__Vdly__rasterizer_unit__DOT__rasterizer_output_valid = 0U;
			    if (VL_UNLIKELY((vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
					     > vlTOPp->rasterizer_unit__DOT__raster__DOT__maxX))) {
				VL_WRITEF("newline\n");
				vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
				    = ((IData)(0x10000U) 
				       + vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y);
				vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
				    = vlTOPp->rasterizer_unit__DOT__raster__DOT__minX;
			    }
			    if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
				 > vlTOPp->rasterizer_unit__DOT__raster__DOT__maxY)) {
				vlTOPp->rasterizer_unit__DOT__done3 
				    = vlTOPp->rasterizer_unit__DOT__done2;
				vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__r_state = 0U;
			    } else {
				vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__r_state = 2U;
			    }
			}
		    }
		}
	    } else {
		if (VL_UNLIKELY(vlTOPp->rasterizer_unit__DOT__raster__DOT__is_inside)) {
		    VL_WRITEF(" rasterizer: is inside\n");
		    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->rasterizer_unit__DOT__rasterizer_output_valid))))) {
			vlTOPp->__Vdly__rasterizer_unit__DOT__addr_out 
			    = (0x3ffffffU & (vlTOPp->rasterizer_unit__DOT__raster__DOT__addr_in_t 
					     + ((((IData)(0x280U) 
						  * 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
						   >> 0x10U)) 
						 + 
						 (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
						  >> 0x10U)) 
						<< 3U)));
			__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__76__b 
			    = vlTOPp->rasterizer_unit__DOT__raster__DOT__z3_t;
			VL_WRITEF(" rasterizer: addr_out = %x\n",
				  26,vlTOPp->rasterizer_unit__DOT__addr_out);
			__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__76__a 
			    = (((IData)(0x10000U) - vlTOPp->rasterizer_unit__DOT__raster__DOT__w1) 
			       - vlTOPp->rasterizer_unit__DOT__raster__DOT__w2);
			vlTOPp->rasterizer_unit__DOT__color_out_1 
			    = vlTOPp->rasterizer_unit__DOT__raster__DOT__color1_t;
			vlTOPp->rasterizer_unit__DOT__color_out_2 
			    = vlTOPp->rasterizer_unit__DOT__raster__DOT__color2_t;
			vlTOPp->rasterizer_unit__DOT__color_out_3 
			    = vlTOPp->rasterizer_unit__DOT__raster__DOT__color3_t;
			vlTOPp->rasterizer_unit__DOT__w1 
			    = vlTOPp->rasterizer_unit__DOT__raster__DOT__w1;
			vlTOPp->rasterizer_unit__DOT__w2 
			    = vlTOPp->rasterizer_unit__DOT__raster__DOT__w2;
			__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__76__Vfuncout 
			    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
						     VL_MULS_QQQ(64,64,64, 
								 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__76__a), 
								 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__76__b)), 0x10U));
			vlTOPp->__Vdly__rasterizer_unit__DOT__rasterizer_output_valid = 1U;
			vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
			    = ((IData)(0x10000U) + vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x);
			__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__75__b 
			    = vlTOPp->rasterizer_unit__DOT__raster__DOT__z2_t;
			if (VL_UNLIKELY((vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
					 > vlTOPp->rasterizer_unit__DOT__raster__DOT__maxX))) {
			    VL_WRITEF("newline\n");
			    vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
				= ((IData)(0x10000U) 
				   + vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y);
			    vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
				= vlTOPp->rasterizer_unit__DOT__raster__DOT__minX;
			}
			__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__75__a 
			    = vlTOPp->rasterizer_unit__DOT__raster__DOT__w2;
			if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
			     > vlTOPp->rasterizer_unit__DOT__raster__DOT__maxY)) {
			    vlTOPp->rasterizer_unit__DOT__done3 
				= vlTOPp->rasterizer_unit__DOT__done2;
			    vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__r_state = 0U;
			} else {
			    vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__r_state = 3U;
			}
			__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__75__Vfuncout 
			    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
						     VL_MULS_QQQ(64,64,64, 
								 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__75__a), 
								 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__75__b)), 0x10U));
			__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__74__b 
			    = vlTOPp->rasterizer_unit__DOT__raster__DOT__z1_t;
			__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__74__a 
			    = vlTOPp->rasterizer_unit__DOT__raster__DOT__w1;
			__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__74__Vfuncout 
			    = (IData)(VL_SHIFTRS_QQI(64,64,32, 
						     VL_MULS_QQQ(64,64,64, 
								 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__74__a), 
								 VL_EXTENDS_QI(64,32, __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__74__b)), 0x10U));
			vlTOPp->rasterizer_unit__DOT__depth_in 
			    = ((__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__74__Vfuncout 
				+ __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__75__Vfuncout) 
			       + __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__76__Vfuncout);
		    }
		} else {
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
			= ((IData)(0x10000U) + vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x);
		    vlTOPp->__Vdly__rasterizer_unit__DOT__rasterizer_output_valid = 0U;
		    if (VL_UNLIKELY((vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
				     > vlTOPp->rasterizer_unit__DOT__raster__DOT__maxX))) {
			VL_WRITEF("newline\n");
			vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
			    = ((IData)(0x10000U) + vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y);
			vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
			    = vlTOPp->rasterizer_unit__DOT__raster__DOT__minX;
		    }
		    if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
			 > vlTOPp->rasterizer_unit__DOT__raster__DOT__maxY)) {
			vlTOPp->rasterizer_unit__DOT__done3 
			    = vlTOPp->rasterizer_unit__DOT__done2;
			vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__r_state = 0U;
		    }
		}
	    }
	} else {
	    if (VL_LIKELY((1U & (IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__r_state)))) {
		vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
		    = vlTOPp->rasterizer_unit__DOT__raster__DOT__minX;
		vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
		    = vlTOPp->rasterizer_unit__DOT__raster__DOT__minY;
		vlTOPp->rasterizer_unit__DOT__stall2 = 1U;
		if (VL_UNLIKELY((0xcU == (IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__div_counter)))) {
		    VL_WRITEF(" rasaterizer: denom = %f, denom_inv = %f\n",
			      64,(VL_ITOR_D_I(vlTOPp->rasterizer_unit__DOT__raster__DOT__denom) 
				  / 6.55360000000000000e+04),
			      64,(VL_ITOR_D_I((IData)(
						      ((0xdU 
							>= 
							(0xfU 
							 & vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr))
						        ? 
						       vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe
						       [
						       (0xfU 
							& vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr)]
						        : VL_ULL(0)))) 
				  / 6.55360000000000000e+04));
		    vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__div_counter = 0U;
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__denom_inv_reg 
			= (IData)(((0xdU >= (0xfU & vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr))
				    ? vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe
				   [(0xfU & vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr)]
				    : VL_ULL(0)));
		    vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__r_state = 2U;
		} else {
		    vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__div_counter 
			= (0xfU & ((IData)(1U) + (IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__div_counter)));
		}
	    } else {
		VL_WRITEF("rasterizer: in_data_valid = [%1#]\n",
			  1,vlTOPp->rasterizer_unit__DOT__out_data_valid);
		if (VL_UNLIKELY(vlTOPp->rasterizer_unit__DOT__out_data_valid)) {
		    VL_WRITEF(" rasterizer: new triangle\n");
		    vlTOPp->rasterizer_unit__DOT__stall2 = 0U;
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t 
			= vlTOPp->rasterizer_unit__DOT__x_out
			[0U];
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t 
			= vlTOPp->rasterizer_unit__DOT__y_out
			[0U];
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__z1_t 
			= vlTOPp->rasterizer_unit__DOT__z_out
			[0U];
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t 
			= vlTOPp->rasterizer_unit__DOT__x_out
			[1U];
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t 
			= vlTOPp->rasterizer_unit__DOT__y_out
			[1U];
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__z2_t 
			= vlTOPp->rasterizer_unit__DOT__z_out
			[1U];
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t 
			= vlTOPp->rasterizer_unit__DOT__x_out
			[2U];
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t 
			= vlTOPp->rasterizer_unit__DOT__y_out
			[2U];
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__z3_t 
			= vlTOPp->rasterizer_unit__DOT__z_out
			[2U];
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__color1_t 
			= vlTOPp->rasterizer_unit__DOT__color1;
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__color2_t 
			= vlTOPp->rasterizer_unit__DOT__color2;
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__color3_t 
			= vlTOPp->rasterizer_unit__DOT__color3;
		    vlTOPp->rasterizer_unit__DOT__raster__DOT__addr_in_t 
			= vlTOPp->rasterizer_unit__DOT__frame_buffer_base;
		    vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__div_counter = 0U;
		    vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__r_state = 1U;
		}
		vlTOPp->__Vdly__rasterizer_unit__DOT__rasterizer_output_valid = 0U;
	    }
	}
    } else {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x = 0U;
	vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y = 0U;
	vlTOPp->rasterizer_unit__DOT__done3 = 0U;
	vlTOPp->__Vdly__rasterizer_unit__DOT__rasterizer_output_valid = 0U;
	vlTOPp->rasterizer_unit__DOT__stall2 = 1U;
	vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__div_counter = 0U;
	vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__r_state = 0U;
    }
    vlTOPp->rasterizer_unit__DOT__out_data_valid = vlTOPp->__Vdly__rasterizer_unit__DOT__out_data_valid;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__r_state 
	= vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__r_state;
    vlTOPp->rasterizer_unit__DOT__addr_out = vlTOPp->__Vdly__rasterizer_unit__DOT__addr_out;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__div_counter 
	= vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__div_counter;
    vlTOPp->rasterizer_unit__DOT__rasterizer_output_valid 
	= vlTOPp->__Vdly__rasterizer_unit__DOT__rasterizer_output_valid;
    vlTOPp->rasterizer_unit__DOT__x_out[3U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__x_out
	[3U];
    vlTOPp->rasterizer_unit__DOT__x_out[2U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__x_out
	[2U];
    vlTOPp->rasterizer_unit__DOT__x_out[1U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__x_out
	[1U];
    vlTOPp->rasterizer_unit__DOT__x_out[0U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__x_out
	[0U];
    vlTOPp->rasterizer_unit__DOT__y_out[3U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__y_out
	[3U];
    vlTOPp->rasterizer_unit__DOT__y_out[2U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__y_out
	[2U];
    vlTOPp->rasterizer_unit__DOT__y_out[1U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__y_out
	[1U];
    vlTOPp->rasterizer_unit__DOT__y_out[0U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__y_out
	[0U];
    vlTOPp->rasterizer_unit__DOT__z_out[3U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__z_out
	[3U];
    vlTOPp->rasterizer_unit__DOT__z_out[2U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__z_out
	[2U];
    vlTOPp->rasterizer_unit__DOT__z_out[1U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__z_out
	[1U];
    vlTOPp->rasterizer_unit__DOT__z_out[0U] = vlTOPp->rasterizer_unit__DOT____Vcellout__v_calc__z_out
	[0U];
    // ALWAYS at ../rasterizer_unit.sv:163
    VL_WRITEF("vertex_cal_out x1:%5# y1:%5# z1:%5#\n",
	      16,(0xffffU & (vlTOPp->rasterizer_unit__DOT__x_out
			     [0U] >> 0x10U)),16,(0xffffU 
						 & (vlTOPp->rasterizer_unit__DOT__y_out
						    [0U] 
						    >> 0x10U)),
	      16,(0xffffU & (vlTOPp->rasterizer_unit__DOT__z_out
			     [0U] >> 0x10U)));
    VL_WRITEF("vertex_cal_out x2:%5# y2:%5# z2:%5#\n",
	      16,(0xffffU & (vlTOPp->rasterizer_unit__DOT__x_out
			     [1U] >> 0x10U)),16,(0xffffU 
						 & (vlTOPp->rasterizer_unit__DOT__y_out
						    [1U] 
						    >> 0x10U)),
	      16,(0xffffU & (vlTOPp->rasterizer_unit__DOT__z_out
			     [1U] >> 0x10U)));
    VL_WRITEF("vertex_cal_out x3:%5# y3:%5# z3:%5#\n",
	      16,(0xffffU & (vlTOPp->rasterizer_unit__DOT__x_out
			     [2U] >> 0x10U)),16,(0xffffU 
						 & (vlTOPp->rasterizer_unit__DOT__y_out
						    [2U] 
						    >> 0x10U)),
	      16,(0xffffU & (vlTOPp->rasterizer_unit__DOT__z_out
			     [2U] >> 0x10U)));
    // ALWAYS at ..//rasterizer_fetch_logic.sv:97
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__w3 
	= (((IData)(0x10000U) - vlTOPp->rasterizer_unit__DOT__w1) 
	   - vlTOPp->rasterizer_unit__DOT__w2);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__84__b 
	= (0xffU & vlTOPp->rasterizer_unit__DOT__color_out_3);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__84__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__84__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__84__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__a 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__w3;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__85__b 
	= (0xffU & vlTOPp->rasterizer_unit__DOT__color_out_2);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__85__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__85__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__85__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__a 
	= vlTOPp->rasterizer_unit__DOT__w2;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__86__b 
	= (0xffU & vlTOPp->rasterizer_unit__DOT__color_out_1);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__86__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__86__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__86__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__a 
	= vlTOPp->rasterizer_unit__DOT__w1;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__80__f 
	= ((vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__Vfuncout 
	    + vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__Vfuncout) 
	   + vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__Vfuncout);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__80__Vfuncout 
	= (0xffU & (vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__80__f 
		    >> 0x10U));
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in 
	= ((0xffff00U & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in) 
	   | (IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__80__Vfuncout));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__91__b 
	= (0xffU & (vlTOPp->rasterizer_unit__DOT__color_out_3 
		    >> 8U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__91__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__91__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__91__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__a 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__w3;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__92__b 
	= (0xffU & (vlTOPp->rasterizer_unit__DOT__color_out_2 
		    >> 8U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__92__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__92__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__92__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__a 
	= vlTOPp->rasterizer_unit__DOT__w2;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__93__b 
	= (0xffU & (vlTOPp->rasterizer_unit__DOT__color_out_1 
		    >> 8U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__93__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__93__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__93__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__a 
	= vlTOPp->rasterizer_unit__DOT__w1;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__87__f 
	= ((vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__Vfuncout 
	    + vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__Vfuncout) 
	   + vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__Vfuncout);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__87__Vfuncout 
	= (0xffU & (vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__87__f 
		    >> 0x10U));
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in 
	= ((0xff00ffU & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in) 
	   | ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__87__Vfuncout) 
	      << 8U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__98__b 
	= (0xffU & (vlTOPp->rasterizer_unit__DOT__color_out_3 
		    >> 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__98__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__98__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__98__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__a 
	= vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__w3;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__99__b 
	= (0xffU & (vlTOPp->rasterizer_unit__DOT__color_out_2 
		    >> 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__99__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__99__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__99__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__a 
	= vlTOPp->rasterizer_unit__DOT__w2;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__100__b 
	= (0xffU & (vlTOPp->rasterizer_unit__DOT__color_out_1 
		    >> 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__100__Vfuncout 
	= ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__100__b) 
	   << 0x10U);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__b 
	= vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__100__Vfuncout;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__a 
	= vlTOPp->rasterizer_unit__DOT__w1;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__94__f 
	= ((vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__Vfuncout 
	    + vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__Vfuncout) 
	   + vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__Vfuncout);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__94__Vfuncout 
	= (0xffU & (vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__94__f 
		    >> 0x10U));
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in 
	= ((0xffffU & vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__color_in) 
	   | ((IData)(vlTOPp->__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__94__Vfuncout) 
	      << 0x10U));
    // ALWAYS at ..//rasterizer.sv:86
    vlTOPp->rasterizer_unit__DOT__raster__DOT__minX 
	= (VL_LTS_III(1,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t, vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t)
	    ? vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t
	    : vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t);
    if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__minX 
	 > vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t)) {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__minX 
	    = vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t;
    }
    // ALWAYS at ..//rasterizer.sv:86
    vlTOPp->rasterizer_unit__DOT__raster__DOT__maxX 
	= (VL_LTS_III(1,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t, vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t)
	    ? vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t
	    : vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t);
    if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__maxX 
	 < vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t)) {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__maxX 
	    = vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t;
    }
    // ALWAYS at ..//rasterizer.sv:103
    vlTOPp->rasterizer_unit__DOT__raster__DOT__minY 
	= (VL_LTS_III(1,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t, vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t)
	    ? vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t
	    : vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t);
    if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__minY 
	 > vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t)) {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__minY 
	    = vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t;
    }
    // ALWAYS at ..//rasterizer.sv:103
    vlTOPp->rasterizer_unit__DOT__raster__DOT__maxY 
	= (VL_LTS_III(1,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t, vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t)
	    ? vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t
	    : vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t);
    if ((vlTOPp->rasterizer_unit__DOT__raster__DOT__maxY 
	 < vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t)) {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__maxY 
	    = vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t;
    }
    // ALWAYS at ..//rasterizer.sv:134
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__b 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__a 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__b 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__a 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__b)), 0x10U));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__w1_tmp 
	= (vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__Vfuncout 
	   + vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__Vfuncout);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__b 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__denom_inv_reg;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__a 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__w1_tmp;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__b)), 0x10U));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__w1 = vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__Vfuncout;
    // ALWAYS at ..//rasterizer.sv:134
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__b 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__a 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__b 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__a 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__b)), 0x10U));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__w2_tmp 
	= (vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__Vfuncout 
	   + vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__Vfuncout);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__b 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__denom_inv_reg;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__a 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__w2_tmp;
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__b)), 0x10U));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__w2 = vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__Vfuncout;
    // ALWAYS at ..//rasterizer.sv:158
    vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t_int 
	= VL_SHIFTRS_III(32,32,32, vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t, 0x10U);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__e12 
	= VL_LTES_III(1,32,32, 0U, (VL_MULS_III(32,32,32, 
						(vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x_int 
						 - vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t_int), 
						(vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t_int 
						 - vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t_int)) 
				    - VL_MULS_III(32,32,32, 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y_int 
						   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t_int), 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t_int 
						   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t_int))));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__e23 
	= VL_LTES_III(1,32,32, 0U, (VL_MULS_III(32,32,32, 
						(vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x_int 
						 - vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t_int), 
						(vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t_int 
						 - vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t_int)) 
				    - VL_MULS_III(32,32,32, 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y_int 
						   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t_int), 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t_int 
						   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t_int))));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__e31 
	= VL_LTES_III(1,32,32, 0U, (VL_MULS_III(32,32,32, 
						(vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_x_int 
						 - vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t_int), 
						(vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t_int 
						 - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t_int)) 
				    - VL_MULS_III(32,32,32, 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__cur_y_int 
						   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t_int), 
						  (vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t_int 
						   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t_int))));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__is_inside 
	= (((IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__e12) 
	    & (IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__e23)) 
	   & (IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__e31));
    // ALWAYS at ..//rasterizer.sv:134
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__b 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__y1_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__a 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x2_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__b)), 0x10U));
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__b 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__x1_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__x3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__a 
	= (vlTOPp->rasterizer_unit__DOT__raster__DOT__y2_t 
	   - vlTOPp->rasterizer_unit__DOT__raster__DOT__y3_t);
    vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__Vfuncout 
	= (IData)(VL_SHIFTRS_QQI(64,64,32, VL_MULS_QQQ(64,64,64, 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__a), 
						       VL_EXTENDS_QI(64,32, vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__b)), 0x10U));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__denom 
	= (vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__Vfuncout 
	   + vlTOPp->__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__Vfuncout);
    // ALWAYS at ..//config_reg.sv:30
    if (vlTOPp->reset) {
	if (vlTOPp->write) {
	    if (VL_UNLIKELY((0U == (IData)(vlTOPp->address)))) {
		VL_WRITEF("frame_buffer_base: %10#\n",
			  33,(QData)((IData)(vlTOPp->writedata)));
		vlTOPp->rasterizer_unit__DOT__frame_buffer_base 
		    = (0x3ffffffU & (IData)((QData)((IData)(vlTOPp->writedata))));
	    } else {
		if (VL_UNLIKELY((4U == (IData)(vlTOPp->address)))) {
		    VL_WRITEF("vertex_buffer_base: %10#\n",
			      33,(QData)((IData)(vlTOPp->writedata)));
		    vlTOPp->rasterizer_unit__DOT__vertex_buffer_base 
			= (0x3ffffffU & (IData)((QData)((IData)(vlTOPp->writedata))));
		} else {
		    if (VL_UNLIKELY((8U == (IData)(vlTOPp->address)))) {
			VL_WRITEF("start_render: %10#\n",
				  33,(QData)((IData)(vlTOPp->writedata)));
			vlTOPp->rasterizer_unit__DOT__do_render 
			    = (1U & (IData)((QData)((IData)(vlTOPp->writedata))));
		    } else {
			if (((0x100U <= (IData)(vlTOPp->address)) 
			     & (0x13cU >= (IData)(vlTOPp->address)))) {
			    __Vdlyvval__rasterizer_unit__DOT____Vcellout__c_reg__MV__v0 
				= vlTOPp->writedata;
			    vlTOPp->__Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__MV__v0 = 1U;
			    __Vdlyvdim0__rasterizer_unit__DOT____Vcellout__c_reg__MV__v0 
				= (0xfU & (((IData)(vlTOPp->address) 
					    - (IData)(0x100U)) 
					   >> 2U));
			} else {
			    if (((0x200U <= (IData)(vlTOPp->address)) 
				 & (0x23cU >= (IData)(vlTOPp->address)))) {
				__Vdlyvval__rasterizer_unit__DOT____Vcellout__c_reg__MVP__v0 
				    = vlTOPp->writedata;
				vlTOPp->__Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__MVP__v0 = 1U;
				__Vdlyvdim0__rasterizer_unit__DOT____Vcellout__c_reg__MVP__v0 
				    = (0xfU & (((IData)(vlTOPp->address) 
						- (IData)(0x200U)) 
					       >> 2U));
			    } else {
				if (((0x300U <= (IData)(vlTOPp->address)) 
				     & (0x308U >= (IData)(vlTOPp->address)))) {
				    vlTOPp->rasterizer_unit__DOT__c_reg__DOT____Vlvbound1 
					= vlTOPp->writedata;
				    if (VL_LIKELY((2U 
						   >= 
						   (3U 
						    & (((IData)(vlTOPp->address) 
							- (IData)(0x300U)) 
						       >> 2U))))) {
					__Vdlyvval__rasterizer_unit__DOT____Vcellout__c_reg__lighting__v0 
					    = vlTOPp->rasterizer_unit__DOT__c_reg__DOT____Vlvbound1;
					vlTOPp->__Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__lighting__v0 = 1U;
					__Vdlyvdim0__rasterizer_unit__DOT____Vcellout__c_reg__lighting__v0 
					    = (3U & 
					       (((IData)(vlTOPp->address) 
						 - (IData)(0x300U)) 
						>> 2U));
				    }
				}
			    }
			}
		    }
		}
	    }
	} else {
	    if (((IData)(vlTOPp->read) & (8U == (IData)(vlTOPp->address)))) {
		vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__readdata 
		    = (QData)((IData)(vlTOPp->rasterizer_unit__DOT__c_reg__DOT__done_latch));
	    }
	}
    } else {
	vlTOPp->rasterizer_unit__DOT__do_render = 0U;
	vlTOPp->rasterizer_unit__DOT__frame_buffer_base = 0U;
	vlTOPp->rasterizer_unit__DOT__vertex_buffer_base = 0x300000U;
    }
    // ALWAYS at ..//lpm_divide.v:145
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_d = 0U;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_denom 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__denom;
    if ((0x80000000U & vlTOPp->rasterizer_unit__DOT__raster__DOT__denom)) {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_denom 
	    = ((IData)(1U) + (~ vlTOPp->rasterizer_unit__DOT__raster__DOT__denom));
	vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_d = 1U;
    }
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_q 
	= VL_DIV_QQQ(64, VL_ULL(0x100000000), (QData)((IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_denom)));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_r 
	= (IData)(VL_MODDIV_QQQ(64, VL_ULL(0x100000000), (QData)((IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_denom))));
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_q 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_d;
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__tmp_quotient 
	= ((IData)(vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_q)
	    ? (VL_ULL(1) + (~ vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_q))
	    : vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_q);
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__tmp_remain 
	= vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_r;
    // ALWAYSPOST at ..//config_reg.sv:52
    if (vlTOPp->__Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__MV__v0) {
	vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MV[__Vdlyvdim0__rasterizer_unit__DOT____Vcellout__c_reg__MV__v0] 
	    = __Vdlyvval__rasterizer_unit__DOT____Vcellout__c_reg__MV__v0;
    }
    // ALWAYSPOST at ..//config_reg.sv:56
    if (vlTOPp->__Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__lighting__v0) {
	vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__lighting[__Vdlyvdim0__rasterizer_unit__DOT____Vcellout__c_reg__lighting__v0] 
	    = __Vdlyvval__rasterizer_unit__DOT____Vcellout__c_reg__lighting__v0;
    }
    // ALWAYSPOST at ..//config_reg.sv:54
    if (vlTOPp->__Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__MVP__v0) {
	vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP[__Vdlyvdim0__rasterizer_unit__DOT____Vcellout__c_reg__MVP__v0] 
	    = __Vdlyvval__rasterizer_unit__DOT____Vcellout__c_reg__MVP__v0;
    }
    vlTOPp->readdata = (IData)(vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__readdata);
    vlTOPp->rasterizer_unit__DOT__MVP[0xfU] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0xfU];
    vlTOPp->rasterizer_unit__DOT__MVP[0xeU] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0xeU];
    vlTOPp->rasterizer_unit__DOT__MVP[0xdU] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0xdU];
    vlTOPp->rasterizer_unit__DOT__MVP[0xcU] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0xcU];
    vlTOPp->rasterizer_unit__DOT__MVP[0xbU] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0xbU];
    vlTOPp->rasterizer_unit__DOT__MVP[0xaU] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0xaU];
    vlTOPp->rasterizer_unit__DOT__MVP[9U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[9U];
    vlTOPp->rasterizer_unit__DOT__MVP[8U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[8U];
    vlTOPp->rasterizer_unit__DOT__MVP[7U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[7U];
    vlTOPp->rasterizer_unit__DOT__MVP[6U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[6U];
    vlTOPp->rasterizer_unit__DOT__MVP[5U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[5U];
    vlTOPp->rasterizer_unit__DOT__MVP[4U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[4U];
    vlTOPp->rasterizer_unit__DOT__MVP[3U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[3U];
    vlTOPp->rasterizer_unit__DOT__MVP[2U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[2U];
    vlTOPp->rasterizer_unit__DOT__MVP[1U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[1U];
    vlTOPp->rasterizer_unit__DOT__MVP[0U] = vlTOPp->rasterizer_unit__DOT____Vcellout__c_reg__MVP
	[0U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0xfU] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0xfU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0xeU] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0xeU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0xdU] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0xdU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0xcU] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0xcU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0xbU] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0xbU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0xaU] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0xaU];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[9U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[9U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[8U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[8U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[7U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[7U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[6U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[6U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[5U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[5U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[4U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[4U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[3U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[3U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[2U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[2U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[1U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[1U];
    vlTOPp->rasterizer_unit__DOT____Vcellinp__v_calc__mat[0U] 
	= vlTOPp->rasterizer_unit__DOT__MVP[0U];
}

VL_INLINE_OPT void Vrasterizer_unit::_sequent__TOP__6(Vrasterizer_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_sequent__TOP__6\n"); );
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr 
	= vlTOPp->__Vdly__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr;
    // ALWAYSPOST at ..//lpm_divide.v:199
    if (vlTOPp->__Vdlyvset__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0) {
	vlTOPp->rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[vlTOPp->__Vdlyvdim0__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0] 
	    = vlTOPp->__Vdlyvval__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0;
    }
}

VL_INLINE_OPT void Vrasterizer_unit::_combo__TOP__7(Vrasterizer_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_combo__TOP__7\n"); );
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // ALWAYS at ..//rasterizer_fetch_logic.sv:110
    vlTOPp->__Vtableidx1 = (((0x10U == (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter)) 
			     << 5U) | (((IData)(vlTOPp->rasterizer_unit__DOT__rasterizer_output_valid) 
					<< 4U) | ((
						   (0xfU 
						    <= (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter)) 
						   << 3U) 
						  | (((0x20U 
						       <= (IData)(vlTOPp->rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter)) 
						      << 2U) 
						     | (((IData)(vlTOPp->master_waitrequest_2) 
							 << 1U) 
							| (IData)(vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__state))))));
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__enqueue 
	= vlTOPp->__Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue
	[vlTOPp->__Vtableidx1];
    vlTOPp->rasterizer_unit__DOT__fetch_logic__DOT__next_state 
	= vlTOPp->__Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state
	[vlTOPp->__Vtableidx1];
    // ALWAYS at ..//config_reg.sv:22
    if (vlTOPp->reset) {
	if (vlTOPp->rasterizer_unit__DOT__done5) {
	    vlTOPp->rasterizer_unit__DOT__c_reg__DOT__done_latch = 1U;
	}
    } else {
	vlTOPp->rasterizer_unit__DOT__c_reg__DOT__done_latch = 0U;
    }
}

void Vrasterizer_unit::_eval(Vrasterizer_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_eval\n"); );
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
	 | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
	vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__3(vlSymsp);
    }
    if ((((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))) 
	 | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
	vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
	vlTOPp->_sequent__TOP__6(vlSymsp);
    }
    vlTOPp->_combo__TOP__7(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vrasterizer_unit::_eval_initial(Vrasterizer_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_eval_initial\n"); );
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
}

void Vrasterizer_unit::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::final\n"); );
    // Variables
    Vrasterizer_unit__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vrasterizer_unit::_eval_settle(Vrasterizer_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_eval_settle\n"); );
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__4(vlSymsp);
}

VL_INLINE_OPT QData Vrasterizer_unit::_change_request(Vrasterizer_unit__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_change_request\n"); );
    Vrasterizer_unit* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vrasterizer_unit::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
	Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
	Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((write & 0xfeU))) {
	Verilated::overWidthError("write");}
    if (VL_UNLIKELY((read & 0xfeU))) {
	Verilated::overWidthError("read");}
    if (VL_UNLIKELY((master_readdatavalid & 0xfeU))) {
	Verilated::overWidthError("master_readdatavalid");}
    if (VL_UNLIKELY((master_waitrequest & 0xfeU))) {
	Verilated::overWidthError("master_waitrequest");}
    if (VL_UNLIKELY((master_readdatavalid_2 & 0xfeU))) {
	Verilated::overWidthError("master_readdatavalid_2");}
    if (VL_UNLIKELY((master_waitrequest_2 & 0xfeU))) {
	Verilated::overWidthError("master_waitrequest_2");}
    if (VL_UNLIKELY((master_readdatavalid_3 & 0xfeU))) {
	Verilated::overWidthError("master_readdatavalid_3");}
    if (VL_UNLIKELY((master_waitrequest_3 & 0xfeU))) {
	Verilated::overWidthError("master_waitrequest_3");}
}
#endif // VL_DEBUG

void Vrasterizer_unit::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrasterizer_unit::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    writedata = VL_RAND_RESET_I(32);
    write = VL_RAND_RESET_I(1);
    read = VL_RAND_RESET_I(1);
    address = VL_RAND_RESET_I(16);
    readdata = VL_RAND_RESET_I(32);
    master_address = VL_RAND_RESET_I(26);
    master_read = VL_RAND_RESET_I(1);
    master_write = VL_RAND_RESET_I(1);
    master_byteenable = VL_RAND_RESET_I(4);
    master_readdata = VL_RAND_RESET_I(32);
    master_readdatavalid = VL_RAND_RESET_I(1);
    master_writedata = VL_RAND_RESET_I(32);
    master_waitrequest = VL_RAND_RESET_I(1);
    master_address_2 = VL_RAND_RESET_I(26);
    master_read_2 = VL_RAND_RESET_I(1);
    master_write_2 = VL_RAND_RESET_I(1);
    master_byteenable_2 = VL_RAND_RESET_I(4);
    master_readdata_2 = VL_RAND_RESET_I(32);
    master_readdatavalid_2 = VL_RAND_RESET_I(1);
    master_writedata_2 = VL_RAND_RESET_I(32);
    master_waitrequest_2 = VL_RAND_RESET_I(1);
    master_address_3 = VL_RAND_RESET_I(26);
    master_read_3 = VL_RAND_RESET_I(1);
    master_write_3 = VL_RAND_RESET_I(1);
    master_byteenable_3 = VL_RAND_RESET_I(4);
    master_readdata_3 = VL_RAND_RESET_I(32);
    master_readdatavalid_3 = VL_RAND_RESET_I(1);
    master_writedata_3 = VL_RAND_RESET_I(32);
    master_waitrequest_3 = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__stall1 = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__stall2 = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__done2 = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__done3 = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__done5 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    rasterizer_unit__DOT__MVP[__Vi0] = VL_RAND_RESET_I(32);
    }}
    rasterizer_unit__DOT__frame_buffer_base = VL_RAND_RESET_I(26);
    rasterizer_unit__DOT__vertex_buffer_base = VL_RAND_RESET_I(26);
    rasterizer_unit__DOT__do_render = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__color1 = VL_RAND_RESET_I(24);
    rasterizer_unit__DOT__color2 = VL_RAND_RESET_I(24);
    rasterizer_unit__DOT__color3 = VL_RAND_RESET_I(24);
    { int __Vi0=0; for (; __Vi0<15; ++__Vi0) {
	    rasterizer_unit__DOT__vertex_out[__Vi0] = VL_RAND_RESET_I(32);
    }}
    rasterizer_unit__DOT__input_data_valid = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    rasterizer_unit__DOT__x_out[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    rasterizer_unit__DOT__y_out[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    rasterizer_unit__DOT__z_out[__Vi0] = VL_RAND_RESET_I(32);
    }}
    rasterizer_unit__DOT__out_data_valid = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__addr_out = VL_RAND_RESET_I(26);
    rasterizer_unit__DOT__color_out_1 = VL_RAND_RESET_I(24);
    rasterizer_unit__DOT__color_out_2 = VL_RAND_RESET_I(24);
    rasterizer_unit__DOT__color_out_3 = VL_RAND_RESET_I(24);
    rasterizer_unit__DOT__w1 = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__w2 = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__rasterizer_output_valid = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__depth_in = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__fetch_output_valid = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__old_depth_out = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__new_depth_out = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    rasterizer_unit__DOT____Vcellout__c_reg__lighting[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    rasterizer_unit__DOT____Vcellout__c_reg__MVP[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    rasterizer_unit__DOT____Vcellout__c_reg__MV[__Vi0] = VL_RAND_RESET_I(32);
    }}
    rasterizer_unit__DOT____Vcellout__c_reg__readdata = VL_RAND_RESET_Q(33);
    { int __Vi0=0; for (; __Vi0<15; ++__Vi0) {
	    rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    rasterizer_unit__DOT____Vcellout__v_calc__w_out[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    rasterizer_unit__DOT____Vcellout__v_calc__z_out[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    rasterizer_unit__DOT____Vcellout__v_calc__y_out[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<4; ++__Vi0) {
	    rasterizer_unit__DOT____Vcellout__v_calc__x_out[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<15; ++__Vi0) {
	    rasterizer_unit__DOT____Vcellinp__v_calc__v_in[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    rasterizer_unit__DOT____Vcellinp__v_calc__mat[__Vi0] = VL_RAND_RESET_I(32);
    }}
    rasterizer_unit__DOT__c_reg__DOT__done_latch = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__c_reg__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__vertex_fetch__DOT__send_state = VL_RAND_RESET_I(2);
    rasterizer_unit__DOT__vertex_fetch__DOT__rec_state = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<15; ++__Vi0) {
	    rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf[__Vi0] = VL_RAND_RESET_I(32);
    }}
    rasterizer_unit__DOT__vertex_fetch__DOT__r_count = VL_RAND_RESET_I(4);
    rasterizer_unit__DOT__vertex_fetch__DOT__output_count = 0;
    rasterizer_unit__DOT__vertex_fetch__DOT__addr = VL_RAND_RESET_I(26);
    rasterizer_unit__DOT__vertex_fetch__DOT__tri_num = 0;
    rasterizer_unit__DOT__vertex_fetch__DOT__input_count = 0;
    rasterizer_unit__DOT__vertex_fetch__DOT__s_count = VL_RAND_RESET_I(4);
    VL_RAND_RESET_W(480,rasterizer_unit__DOT__vertex_fetch__DOT__data_in);
    VL_RAND_RESET_W(480,rasterizer_unit__DOT__vertex_fetch__DOT__data_out);
    rasterizer_unit__DOT__vertex_fetch__DOT__wrreq = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__vertex_fetch__DOT__rdreq = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__vertex_fetch__DOT__full = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__vertex_fetch__DOT__empty = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__vertex_fetch__DOT__fetch_tri = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__vertex_fetch__DOT__recv_valid = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__vertex_fetch__DOT__fifo_counter = 0;
    rasterizer_unit__DOT__vertex_fetch__DOT__already_pop = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__vertex_fetch__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__vertex_fetch__DOT____Vlvbound2 = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__vertex_fetch__DOT____Vlvbound3 = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    VL_RAND_RESET_W(480,rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[__Vi0]);
    }}
    rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__wr_ptr = VL_RAND_RESET_I(4);
    rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr = VL_RAND_RESET_I(4);
    rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter = VL_RAND_RESET_I(5);
    rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__new_counter = VL_RAND_RESET_I(5);
    rasterizer_unit__DOT__v_calc__DOT__width = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__v_calc__DOT__height = VL_RAND_RESET_I(32);
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    rasterizer_unit__DOT__v_calc__DOT__tmp_x[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    rasterizer_unit__DOT__v_calc__DOT__tmp_y[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    rasterizer_unit__DOT__v_calc__DOT__tmp_z[__Vi0] = VL_RAND_RESET_I(32);
    }}
    { int __Vi0=0; for (; __Vi0<3; ++__Vi0) {
	    rasterizer_unit__DOT__v_calc__DOT__tmp_w[__Vi0] = VL_RAND_RESET_I(32);
    }}
    rasterizer_unit__DOT__v_calc__DOT__color1_r = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__v_calc__DOT__color1_g = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__v_calc__DOT__color1_b = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__v_calc__DOT__color2_r = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__v_calc__DOT__color2_g = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__v_calc__DOT__color2_b = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__v_calc__DOT__color3_r = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__v_calc__DOT__color3_g = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__v_calc__DOT__color3_b = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__v_calc__DOT__state = VL_RAND_RESET_I(2);
    rasterizer_unit__DOT__raster__DOT__x1_t = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__y1_t = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__z1_t = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__x2_t = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__y2_t = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__z2_t = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__x3_t = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__y3_t = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__z3_t = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__color1_t = VL_RAND_RESET_I(24);
    rasterizer_unit__DOT__raster__DOT__color2_t = VL_RAND_RESET_I(24);
    rasterizer_unit__DOT__raster__DOT__color3_t = VL_RAND_RESET_I(24);
    rasterizer_unit__DOT__raster__DOT__addr_in_t = VL_RAND_RESET_I(26);
    rasterizer_unit__DOT__raster__DOT__cur_x = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__cur_y = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__e12 = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__raster__DOT__e23 = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__raster__DOT__e31 = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__raster__DOT__is_inside = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__raster__DOT__minX = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__minY = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__maxX = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__maxY = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__w1 = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__w2 = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__w1_tmp = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__w2_tmp = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__denom = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__denom_inv_reg = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__cur_x_int = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__cur_y_int = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__x1_t_int = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__y1_t_int = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__x2_t_int = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__y2_t_int = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__x3_t_int = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__y3_t_int = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__r_state = VL_RAND_RESET_I(2);
    rasterizer_unit__DOT__raster__DOT__div_counter = VL_RAND_RESET_I(4);
    { int __Vi0=0; for (; __Vi0<14; ++__Vi0) {
	    rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    { int __Vi0=0; for (; __Vi0<14; ++__Vi0) {
	    rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[__Vi0] = VL_RAND_RESET_I(32);
    }}
    rasterizer_unit__DOT__raster__DOT__area_divider__DOT__tmp_quotient = VL_RAND_RESET_Q(64);
    rasterizer_unit__DOT__raster__DOT__area_divider__DOT__tmp_remain = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_q = VL_RAND_RESET_Q(64);
    rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_denom = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_r = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_q = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_d = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__raster__DOT__area_divider__DOT__lpm_remainderpositive = VL_RAND_RESET_Q(40);
    rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__raster__DOT__area_divider__DOT____Vlvbound5 = VL_RAND_RESET_Q(64);
    rasterizer_unit__DOT__raster__DOT__area_divider__DOT____Vlvbound6 = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__fetch_logic__DOT__color_in = VL_RAND_RESET_I(24);
    VL_RAND_RESET_W(96,rasterizer_unit__DOT__fetch_logic__DOT__data_in);
    VL_RAND_RESET_W(96,rasterizer_unit__DOT__fetch_logic__DOT__data_out);
    rasterizer_unit__DOT__fetch_logic__DOT__wrreq = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__fetch_logic__DOT__full = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__fetch_logic__DOT__empty = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(96,rasterizer_unit__DOT__fetch_logic__DOT__data_out_reg);
    rasterizer_unit__DOT__fetch_logic__DOT__w3 = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__fetch_logic__DOT__state = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__fetch_logic__DOT__next_state = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__fetch_logic__DOT__enqueue = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
	    VL_RAND_RESET_W(96,rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer[__Vi0]);
    }}
    rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__wr_ptr = VL_RAND_RESET_I(4);
    rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__rd_ptr = VL_RAND_RESET_I(4);
    rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter = VL_RAND_RESET_I(5);
    rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__new_counter = VL_RAND_RESET_I(5);
    VL_RAND_RESET_W(115,rasterizer_unit__DOT__z_test__DOT__data_in);
    VL_RAND_RESET_W(115,rasterizer_unit__DOT__z_test__DOT__data_out);
    rasterizer_unit__DOT__z_test__DOT__wrreq = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__z_test__DOT__rdreq = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__z_test__DOT__full = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__z_test__DOT__empty = VL_RAND_RESET_I(1);
    rasterizer_unit__DOT__z_test__DOT__real_new_depth_out = VL_RAND_RESET_I(32);
    rasterizer_unit__DOT__z_test__DOT__state = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<64; ++__Vi0) {
	    VL_RAND_RESET_W(115,rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer[__Vi0]);
    }}
    rasterizer_unit__DOT__z_test__DOT__fifo__DOT__wr_ptr = VL_RAND_RESET_I(6);
    rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr = VL_RAND_RESET_I(6);
    rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter = VL_RAND_RESET_I(7);
    rasterizer_unit__DOT__z_test__DOT__fifo__DOT__new_counter = VL_RAND_RESET_I(7);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__80__Vfuncout = VL_RAND_RESET_I(8);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__80__f = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__84__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__84__b = VL_RAND_RESET_I(8);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__85__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__85__b = VL_RAND_RESET_I(8);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__86__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__86__b = VL_RAND_RESET_I(8);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__87__Vfuncout = VL_RAND_RESET_I(8);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__87__f = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__91__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__91__b = VL_RAND_RESET_I(8);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__92__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__92__b = VL_RAND_RESET_I(8);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__93__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__93__b = VL_RAND_RESET_I(8);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__94__Vfuncout = VL_RAND_RESET_I(8);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__94__f = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__a = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__b = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__98__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__98__b = VL_RAND_RESET_I(8);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__99__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__99__b = VL_RAND_RESET_I(8);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__100__Vfuncout = VL_RAND_RESET_I(32);
    __Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__100__b = VL_RAND_RESET_I(8);
    __Vtableidx1 = VL_RAND_RESET_I(6);
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[0] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[1] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[2] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[3] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[4] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[5] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[6] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[7] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[8] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[9] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[10] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[11] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[12] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[13] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[14] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[15] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[16] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[17] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[18] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[19] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[20] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[21] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[22] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[23] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[24] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[25] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[26] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[27] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[28] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[29] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[30] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[31] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[32] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[33] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[34] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[35] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[36] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[37] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[38] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[39] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[40] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[41] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[42] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[43] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[44] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[45] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[46] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[47] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[48] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[49] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[50] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[51] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[52] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[53] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[54] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[55] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[56] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[57] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[58] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[59] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[60] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[61] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[62] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[63] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[0] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[1] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[2] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[3] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[4] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[5] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[6] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[7] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[8] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[9] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[10] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[11] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[12] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[13] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[14] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[15] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[16] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[17] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[18] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[19] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[20] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[21] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[22] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[23] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[24] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[25] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[26] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[27] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[28] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[29] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[30] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[31] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[32] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[33] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[34] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[35] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[36] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[37] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[38] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[39] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[40] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[41] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[42] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[43] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[44] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[45] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[46] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[47] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[48] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[49] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[50] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[51] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[52] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[53] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[54] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[55] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[56] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[57] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[58] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[59] = 1U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[60] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[61] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[62] = 0U;
    __Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[63] = 1U;
    __Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__MV__v0 = VL_RAND_RESET_I(1);
    __Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__MVP__v0 = VL_RAND_RESET_I(1);
    __Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__lighting__v0 = VL_RAND_RESET_I(1);
    __Vdly__rasterizer_unit__DOT__out_data_valid = VL_RAND_RESET_I(1);
    __Vdly__rasterizer_unit__DOT__raster__DOT__r_state = VL_RAND_RESET_I(2);
    __Vdly__rasterizer_unit__DOT__addr_out = VL_RAND_RESET_I(26);
    __Vdly__rasterizer_unit__DOT__rasterizer_output_valid = VL_RAND_RESET_I(1);
    __Vdly__rasterizer_unit__DOT__raster__DOT__div_counter = VL_RAND_RESET_I(4);
    __Vdly__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter = VL_RAND_RESET_I(5);
    __Vdly__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter = VL_RAND_RESET_I(7);
    __Vdlyvdim0__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0 = VL_RAND_RESET_I(4);
    __Vdlyvval__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0 = VL_RAND_RESET_Q(64);
    __Vdlyvset__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0 = VL_RAND_RESET_I(1);
    __Vdly__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr = VL_RAND_RESET_I(32);
}
