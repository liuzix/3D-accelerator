// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _Vrasterizer_unit_H_
#define _Vrasterizer_unit_H_

#include "verilated_heavy.h"

class Vrasterizer_unit__Syms;

//----------

VL_MODULE(Vrasterizer_unit) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    // Begin mtask footprint  all: 
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(write,0,0);
    VL_IN8(read,0,0);
    VL_OUT8(master_read,0,0);
    VL_OUT8(master_write,0,0);
    VL_OUT8(master_byteenable,3,0);
    VL_IN8(master_readdatavalid,0,0);
    VL_IN8(master_waitrequest,0,0);
    VL_OUT8(master_read_2,0,0);
    VL_OUT8(master_write_2,0,0);
    VL_OUT8(master_byteenable_2,3,0);
    VL_IN8(master_readdatavalid_2,0,0);
    VL_IN8(master_waitrequest_2,0,0);
    VL_OUT8(master_read_3,0,0);
    VL_OUT8(master_write_3,0,0);
    VL_OUT8(master_byteenable_3,3,0);
    VL_IN8(master_readdatavalid_3,0,0);
    VL_IN8(master_waitrequest_3,0,0);
    VL_IN16(address,15,0);
    VL_IN(writedata,31,0);
    VL_OUT(readdata,31,0);
    VL_OUT(master_address,25,0);
    VL_IN(master_readdata,31,0);
    VL_OUT(master_writedata,31,0);
    VL_OUT(master_address_2,25,0);
    VL_IN(master_readdata_2,31,0);
    VL_OUT(master_writedata_2,31,0);
    VL_OUT(master_address_3,25,0);
    VL_IN(master_readdata_3,31,0);
    VL_OUT(master_writedata_3,31,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
	// Begin mtask footprint  all: 
	VL_SIG8(rasterizer_unit__DOT__stall1,0,0);
	VL_SIG8(rasterizer_unit__DOT__stall2,0,0);
	VL_SIG8(rasterizer_unit__DOT__done2,0,0);
	VL_SIG8(rasterizer_unit__DOT__done3,0,0);
	VL_SIG8(rasterizer_unit__DOT__done5,0,0);
	VL_SIG8(rasterizer_unit__DOT__do_render,0,0);
	VL_SIG8(rasterizer_unit__DOT__input_data_valid,0,0);
	VL_SIG8(rasterizer_unit__DOT__out_data_valid,0,0);
	VL_SIG8(rasterizer_unit__DOT__rasterizer_output_valid,0,0);
	VL_SIG8(rasterizer_unit__DOT__fetch_output_valid,0,0);
	VL_SIG8(rasterizer_unit__DOT__c_reg__DOT__done_latch,0,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__send_state,1,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__rec_state,1,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__r_count,3,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__s_count,3,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__wrreq,0,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__rdreq,0,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__full,0,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__empty,0,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__fetch_tri,0,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__recv_valid,0,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__already_pop,0,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__wr_ptr,3,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__rd_ptr,3,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__counter,4,0);
	VL_SIG8(rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__new_counter,4,0);
	VL_SIG8(rasterizer_unit__DOT__v_calc__DOT__state,1,0);
	VL_SIG8(rasterizer_unit__DOT__raster__DOT__e12,0,0);
	VL_SIG8(rasterizer_unit__DOT__raster__DOT__e23,0,0);
	VL_SIG8(rasterizer_unit__DOT__raster__DOT__e31,0,0);
	VL_SIG8(rasterizer_unit__DOT__raster__DOT__is_inside,0,0);
	VL_SIG8(rasterizer_unit__DOT__raster__DOT__r_state,1,0);
	VL_SIG8(rasterizer_unit__DOT__raster__DOT__div_counter,3,0);
	VL_SIG8(rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_q,0,0);
	VL_SIG8(rasterizer_unit__DOT__raster__DOT__area_divider__DOT__sign_d,0,0);
	VL_SIG8(rasterizer_unit__DOT__fetch_logic__DOT__wrreq,0,0);
	VL_SIG8(rasterizer_unit__DOT__fetch_logic__DOT__full,0,0);
	VL_SIG8(rasterizer_unit__DOT__fetch_logic__DOT__empty,0,0);
	VL_SIG8(rasterizer_unit__DOT__fetch_logic__DOT__state,0,0);
	VL_SIG8(rasterizer_unit__DOT__fetch_logic__DOT__next_state,0,0);
	VL_SIG8(rasterizer_unit__DOT__fetch_logic__DOT__enqueue,0,0);
	VL_SIG8(rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__wr_ptr,3,0);
	VL_SIG8(rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__rd_ptr,3,0);
	VL_SIG8(rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter,4,0);
	VL_SIG8(rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__new_counter,4,0);
	VL_SIG8(rasterizer_unit__DOT__z_test__DOT__wrreq,0,0);
	VL_SIG8(rasterizer_unit__DOT__z_test__DOT__rdreq,0,0);
	VL_SIG8(rasterizer_unit__DOT__z_test__DOT__full,0,0);
	VL_SIG8(rasterizer_unit__DOT__z_test__DOT__empty,0,0);
	VL_SIG8(rasterizer_unit__DOT__z_test__DOT__state,1,0);
	VL_SIG8(rasterizer_unit__DOT__z_test__DOT__fifo__DOT__wr_ptr,5,0);
	VL_SIG8(rasterizer_unit__DOT__z_test__DOT__fifo__DOT__rd_ptr,5,0);
	VL_SIG8(rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter,6,0);
	VL_SIG8(rasterizer_unit__DOT__z_test__DOT__fifo__DOT__new_counter,6,0);
	VL_SIG(rasterizer_unit__DOT__frame_buffer_base,25,0);
	VL_SIG(rasterizer_unit__DOT__vertex_buffer_base,25,0);
	VL_SIG(rasterizer_unit__DOT__color1,23,0);
	VL_SIG(rasterizer_unit__DOT__color2,23,0);
	VL_SIG(rasterizer_unit__DOT__color3,23,0);
	VL_SIG(rasterizer_unit__DOT__addr_out,25,0);
	VL_SIG(rasterizer_unit__DOT__color_out_1,23,0);
	VL_SIG(rasterizer_unit__DOT__color_out_2,23,0);
	VL_SIG(rasterizer_unit__DOT__color_out_3,23,0);
	VL_SIG(rasterizer_unit__DOT__w1,31,0);
    };
    struct {
	VL_SIG(rasterizer_unit__DOT__w2,31,0);
	VL_SIG(rasterizer_unit__DOT__depth_in,31,0);
	VL_SIG(rasterizer_unit__DOT__old_depth_out,31,0);
	VL_SIG(rasterizer_unit__DOT__new_depth_out,31,0);
	VL_SIG(rasterizer_unit__DOT__vertex_fetch__DOT__output_count,31,0);
	VL_SIG(rasterizer_unit__DOT__vertex_fetch__DOT__addr,25,0);
	VL_SIG(rasterizer_unit__DOT__vertex_fetch__DOT__tri_num,31,0);
	VL_SIG(rasterizer_unit__DOT__vertex_fetch__DOT__input_count,31,0);
	VL_SIGW(rasterizer_unit__DOT__vertex_fetch__DOT__data_in,479,0,15);
	VL_SIGW(rasterizer_unit__DOT__vertex_fetch__DOT__data_out,479,0,15);
	VL_SIG(rasterizer_unit__DOT__vertex_fetch__DOT__fifo_counter,31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__width,31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__height,31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__color1_r,31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__color1_g,31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__color1_b,31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__color2_r,31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__color2_g,31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__color2_b,31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__color3_r,31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__color3_g,31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__color3_b,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__x1_t,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__y1_t,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__z1_t,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__x2_t,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__y2_t,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__z2_t,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__x3_t,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__y3_t,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__z3_t,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__color1_t,23,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__color2_t,23,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__color3_t,23,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__addr_in_t,25,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__cur_x,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__cur_y,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__minX,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__minY,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__maxX,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__maxY,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__w1,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__w2,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__w1_tmp,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__w2_tmp,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__denom,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__denom_inv_reg,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__cur_x_int,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__cur_y_int,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__x1_t_int,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__y1_t_int,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__x2_t_int,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__y2_t_int,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__x3_t_int,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__y3_t_int,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__area_divider__DOT__tmp_remain,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_denom,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_r,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr,31,0);
	VL_SIG(rasterizer_unit__DOT__fetch_logic__DOT__color_in,23,0);
	VL_SIGW(rasterizer_unit__DOT__fetch_logic__DOT__data_in,95,0,3);
	VL_SIGW(rasterizer_unit__DOT__fetch_logic__DOT__data_out,95,0,3);
	VL_SIGW(rasterizer_unit__DOT__fetch_logic__DOT__data_out_reg,95,0,3);
	VL_SIG(rasterizer_unit__DOT__fetch_logic__DOT__w3,31,0);
    };
    struct {
	VL_SIGW(rasterizer_unit__DOT__z_test__DOT__data_in,114,0,4);
	VL_SIGW(rasterizer_unit__DOT__z_test__DOT__data_out,114,0,4);
	VL_SIG(rasterizer_unit__DOT__z_test__DOT__real_new_depth_out,31,0);
	VL_SIG64(rasterizer_unit__DOT__raster__DOT__area_divider__DOT__tmp_quotient,63,0);
	VL_SIG64(rasterizer_unit__DOT__raster__DOT__area_divider__DOT__t_q,63,0);
	VL_SIG64(rasterizer_unit__DOT__raster__DOT__area_divider__DOT__lpm_remainderpositive,40,1);
	VL_SIG(rasterizer_unit__DOT__MVP[16],31,0);
	VL_SIG(rasterizer_unit__DOT__vertex_out[15],31,0);
	VL_SIG(rasterizer_unit__DOT__x_out[4],31,0);
	VL_SIG(rasterizer_unit__DOT__y_out[4],31,0);
	VL_SIG(rasterizer_unit__DOT__z_out[4],31,0);
	VL_SIG(rasterizer_unit__DOT__vertex_fetch__DOT__vertex_out_buf[15],31,0);
	VL_SIGW(rasterizer_unit__DOT__vertex_fetch__DOT__fifo__DOT__buffer[16],479,0,15);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__tmp_x[3],31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__tmp_y[3],31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__tmp_z[3],31,0);
	VL_SIG(rasterizer_unit__DOT__v_calc__DOT__tmp_w[3],31,0);
	VL_SIG64(rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe[14],63,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__area_divider__DOT__remain_pipe[14],31,0);
	VL_SIGW(rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__buffer[16],95,0,3);
	VL_SIGW(rasterizer_unit__DOT__z_test__DOT__fifo__DOT__buffer[64],114,0,4);
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
	// Begin mtask footprint  all: 
	VL_SIG8(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__80__Vfuncout,7,0);
	VL_SIG8(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__84__b,7,0);
	VL_SIG8(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__85__b,7,0);
	VL_SIG8(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__86__b,7,0);
	VL_SIG8(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__87__Vfuncout,7,0);
	VL_SIG8(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__91__b,7,0);
	VL_SIG8(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__92__b,7,0);
	VL_SIG8(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__93__b,7,0);
	VL_SIG8(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__94__Vfuncout,7,0);
	VL_SIG8(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__98__b,7,0);
	VL_SIG8(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__99__b,7,0);
	VL_SIG8(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__100__b,7,0);
	VL_SIG8(__Vtableidx1,5,0);
	VL_SIG8(__Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__MV__v0,0,0);
	VL_SIG8(__Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__MVP__v0,0,0);
	VL_SIG8(__Vdlyvset__rasterizer_unit__DOT____Vcellout__c_reg__lighting__v0,0,0);
	VL_SIG8(__Vdly__rasterizer_unit__DOT__out_data_valid,0,0);
	VL_SIG8(__Vdly__rasterizer_unit__DOT__raster__DOT__r_state,1,0);
	VL_SIG8(__Vdly__rasterizer_unit__DOT__rasterizer_output_valid,0,0);
	VL_SIG8(__Vdly__rasterizer_unit__DOT__raster__DOT__div_counter,3,0);
	VL_SIG8(__Vdly__rasterizer_unit__DOT__fetch_logic__DOT__fifo__DOT__counter,4,0);
	VL_SIG8(__Vdly__rasterizer_unit__DOT__z_test__DOT__fifo__DOT__counter,6,0);
	VL_SIG8(__Vdlyvdim0__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0,3,0);
	VL_SIG8(__Vdlyvset__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0,0,0);
	VL_SIG8(__Vclklast__TOP__clock,0,0);
	VL_SIG8(__Vclklast__TOP__reset,0,0);
	VL_SIG(rasterizer_unit__DOT__c_reg__DOT____Vlvbound1,31,0);
	VL_SIG(rasterizer_unit__DOT__vertex_fetch__DOT____Vlvbound1,31,0);
	VL_SIG(rasterizer_unit__DOT__vertex_fetch__DOT____Vlvbound2,31,0);
	VL_SIG(rasterizer_unit__DOT__vertex_fetch__DOT____Vlvbound3,31,0);
	VL_SIG(rasterizer_unit__DOT__raster__DOT__area_divider__DOT____Vlvbound6,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__61__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__62__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__63__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__64__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__65__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__66__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__67__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__raster__DOT__fp_m__68__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__80__f,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__81__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__82__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__a,31,0);
    };
    struct {
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__83__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__84__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__85__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__86__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__87__f,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__88__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__89__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__90__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__91__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__92__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__93__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_to_byte__94__f,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__95__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__96__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__a,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__fp_m__97__b,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__98__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__99__Vfuncout,31,0);
	VL_SIG(__Vfunc_rasterizer_unit__DOT__fetch_logic__DOT__byte_to_fp__100__Vfuncout,31,0);
	VL_SIG(__Vdly__rasterizer_unit__DOT__addr_out,25,0);
	VL_SIG(__Vdly__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__pipe_ptr,31,0);
	VL_SIG64(rasterizer_unit__DOT____Vcellout__c_reg__readdata,32,0);
	VL_SIG64(rasterizer_unit__DOT__raster__DOT__area_divider__DOT____Vlvbound5,63,0);
	VL_SIG64(__Vdlyvval__rasterizer_unit__DOT__raster__DOT__area_divider__DOT__quotient_pipe__v0,63,0);
	VL_SIG(rasterizer_unit__DOT____Vcellout__c_reg__lighting[3],31,0);
	VL_SIG(rasterizer_unit__DOT____Vcellout__c_reg__MVP[16],31,0);
	VL_SIG(rasterizer_unit__DOT____Vcellout__c_reg__MV[16],31,0);
	VL_SIG(rasterizer_unit__DOT____Vcellout__vertex_fetch__vertex_out[15],31,0);
	VL_SIG(rasterizer_unit__DOT____Vcellout__v_calc__w_out[4],31,0);
	VL_SIG(rasterizer_unit__DOT____Vcellout__v_calc__z_out[4],31,0);
	VL_SIG(rasterizer_unit__DOT____Vcellout__v_calc__y_out[4],31,0);
	VL_SIG(rasterizer_unit__DOT____Vcellout__v_calc__x_out[4],31,0);
	VL_SIG(rasterizer_unit__DOT____Vcellinp__v_calc__v_in[15],31,0);
	VL_SIG(rasterizer_unit__DOT____Vcellinp__v_calc__mat[16],31,0);
    };
    static VL_ST_SIG8(__Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__enqueue[64],0,0);
    static VL_ST_SIG8(__Vtable1_rasterizer_unit__DOT__fetch_logic__DOT__next_state[64],0,0);
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vrasterizer_unit__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vrasterizer_unit);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vrasterizer_unit(const char* name="TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vrasterizer_unit();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vrasterizer_unit__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vrasterizer_unit__Syms* symsp, bool first);
  private:
    static QData _change_request(Vrasterizer_unit__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__7(Vrasterizer_unit__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset();
  public:
    static void _eval(Vrasterizer_unit__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(Vrasterizer_unit__Syms* __restrict vlSymsp);
    static void _eval_settle(Vrasterizer_unit__Syms* __restrict vlSymsp);
    static void _initial__TOP__1(Vrasterizer_unit__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vrasterizer_unit__Syms* __restrict vlSymsp);
    static void _sequent__TOP__3(Vrasterizer_unit__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(Vrasterizer_unit__Syms* __restrict vlSymsp);
    static void _sequent__TOP__6(Vrasterizer_unit__Syms* __restrict vlSymsp);
    static void _settle__TOP__4(Vrasterizer_unit__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(128);

#endif // guard
