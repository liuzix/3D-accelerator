module rasterizer_unit (
    input clock,
    input reset,
    // to config_reg
    input [31:0] writedata,
    input logic write,
    input logic read,
    input logic [15:0] address,

    output [25:0] master_address,
    output master_read,
    output master_write,
    output [3:0] master_byteenable,
    input [31:0] master_readdata,
    input master_readdatavalid,
    output [31:0]master_writedata,
    input master_waitrequest,
    
    output [25:0] master_address_2,
    output master_read_2,
    output master_write_2,
    output [3:0] master_byteenable_2,
    input [31:0] master_readdata_2,
    input master_readdatavalid_2,
    output [31:0]master_writedata_2,
    input master_waitrequest_2,

    output [25:0] master_address_3,
    output master_read_3,
    output master_write_3,
    output [3:0] master_byteenable_3,
    input [31:0] master_readdata_3,
    input master_readdatavalid_3,
    output [31:0]master_writedata_3,
    input master_waitrequest_3
);


wire stall1;
wire stall2;
wire stall3;
wire stall4;

wire done1;
wire done2;
wire done3;
wire done4;
wire done5;

//output of config_reg
logic [32:0] readdata;
logic [31:0] MV [15:0];
logic [31:0] MVP [15:0];
logic [31:0] lighting [2:0];
logic [25:0] frame_buffer_base;
logic [25:0] vertex_buffer_base;
logic do_render;


//output of vertex fetch
logic output_valid;
logic fetch_busy;
logic fetch_finish;
logic [31:0] vertex_out[14:0];
logic input_data_valid;

//output of vertex cal
logic [31:0] x_out[3:0];
logic [31:0] y_out[3:0];
logic [31:0] z_out[3:0];
logic [31:0] w_out[3:0];
logic out_data_valid;

//output of rasterizer
logic [25:0] addr_out;
logic [23:0] color_out;
logic rasterizer_output_valid;

//fetch logic
logic [31:0] depth_in;
logic fetch_output_valid;
logic [25:0] fetch_addr_out;
logic [31:0] old_depth_out;
logic [31:0] new_depth_out;
logic [23:0] fetch_color_out;
logic wait_request;

//final output
logic [25:0] final_addr_out;
logic [23:0] final_color_out;


config_reg c_reg (
    .clk(clock),
    .reset_n(reset),
    .writedata(writedata),
    .write(write),
    .read(read),
    .address(address),
    .readdata(readdata),
    .MV(MV),
    .MVP(MVP),
    .lighting(lighting),
    .frame_buffer_base(frame_buffer_base),
    .vertex_buffer_base(vertex_buffer_base),
    .start_render(do_render),
    .done_in(done5));


rasterizer_vertex_fetch vertex_fetch (
    .clock(clock),
    .reset(reset),
    .master_address(master_address),
    .master_read(master_read),
    .master_write(master_write),
    .master_byteenable(master_byteenable),
    .master_readdata(master_readdata),
    .master_readdatavalid(master_readdatavalid),
    .master_writedata(master_writedata),
    .master_waitrequest(master_waitrequest),
    /* pipeline interface */
    .fetch_enable(do_render),
    .vertex_buffer_base(vertex_buffer_base),
    .stall_in(stall1),
    .done_out(done1),
    /* data for one triangle is ready */
    .output_valid(input_data_valid),
    /* triangle data 15-32bits x1,y1,z1,rgb, ..., nx, ny, nz */
    .vertex_out(vertex_out));


vertex_calc v_calc (
    .clock(clock),
    .reset(reset),
    .mat(MVP),
    .v_in(vertex_out),
    .input_data_valid(input_data_valid),
    .x_out(x_out),
    .y_out(y_out),
    .z_out(z_out),
    .w_out(w_out),
    .done_in(done1),
    .done_out(done2),
    .stall_in(stall2), 
    .stall_out(stall1),
    .out_data_valid(out_data_valid));


rasterizer raster (
    .clock(clock),
    .reset(reset),
    .x1(x_out[0]),
    .y1(y_out[0]),
    .x2(x_out[1]),
    .y2(y_out[1]),
    .x3(x_out[2]),
    .y3(y_out[2]),
    .z1(z_out[0]),
    .z2(z_out[1]),
    .z3(z_out[2]),
    .color1(vertex_out[3][23:0]),
    .color2(vertex_out[7][23:0]),
    .color3(vertex_out[11][23:0]),
    .addr_in(frame_buffer_base), //from config_reg
    .in_data_valid(out_data_valid),

    .done_in(done2),
    .stall_in(stall3),
    .addr_out(addr_out),
    .color_out(color_out),
    .depth_out(depth_in),
    .output_valid(rasterizer_output_valid),
   
    .stall_out(stall2),
    .done_out(done3)
    
    
    );

rasterizer_fetch_logic fetch_logic (
    .clock(clock),
    .reset(reset),
    .master_address(master_address_2),
    .master_read(master_read_2),
    .master_write(master_write_2),
    .master_byteenable(master_byteenable_2),
    .master_readdata(master_readdata_2),
    .master_readdatavalid(master_readdatavalid_2),
    .master_writedata(master_writedata_2),
    .master_waitrequest(master_waitrequest_2),
    .input_valid(rasterizer_output_valid), //from rasterizer
    .addr_in(addr_out), //from rasterizer
    .color_in(color_out), //from rasterizer
    .depth_in(depth_in), /// from bus...
    .output_valid(fetch_output_valid),
    .addr_out(fetch_addr_out),
    .old_depth_out(old_depth_out),
    .new_depth_out(new_depth_out),
    .color_out(fetch_color_out),
    .done_in(done3), //from rasterizer
    .done_out(done4),
    .stall_in(stall4),
    .stall_out(stall3));

ztest z_test (
    .clock(clock),
    .reset(reset),
    .output_valid(fetch_output_valid),
    .addr_in(fetch_addr_out),
    .old_depth_out(old_depth_out),
    .new_depth_out(new_depth_out),
    .color_in(fetch_color_out),
    .done_in(done4),
    .done_out(done5),
    .master_address(master_address_3),
    .master_read(master_read_3),
    .master_write(master_write_3),
    .master_byteenable(master_byteenable_3),
    .master_readdata(master_readdata_3),
    .master_readdatavalid(master_readdatavalid_3),
    .master_writedata(master_writedata_3),
    .master_waitrequest(master_waitrequest_3),
    .stall_out(stall4));

//need one to write to SDRAM controller

endmodule // rasterizer_unit



