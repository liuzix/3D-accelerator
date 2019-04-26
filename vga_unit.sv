module vga_unit(input clk,
   input reset,
   input [25:0] frame_buffer_ptr,
   input master_readdatavalid,
   input master_waitrequest,
   output master_read,
   output master_write,
	output [3:0] master_byteenable,
   output [31:0] master_writedata,
   input [31:0] bus_data,
   output [25:0] master_address,
   output logic [7:0] VGA_R, VGA_G, VGA_B,
   output logic 	   VGA_CLK, VGA_HS, VGA_VS,
   VGA_BLANK_n,
   output logic	   VGA_SYNC_n,
   output test_master_read,
	output test_slave_read,
	output test_waitrequest,
	output [6:0] read_state);

   assign master_write = 0;
   assign master_byteenable = 4'b1111;

   logic pixel_read;
   logic [25:0] cur_vga_addr;
   logic [31:0] pixel_data;
   logic pixel_valid;
   
   //----- bus adapter ------//
   //output
   logic slave_readdatavalid;
   logic slave_waitrequest;
   logic [31:0] slave_readdata;
   //logic [15:0] master_writedata;

   //input
   logic slave_write;
   logic slave_read;
   logic [31:0] slave_writedata;
   logic [25:0] slave_address;
   logic [15:0] master_readdata;
   //------------------------//
	
	logic [3:0] tmp_state;
   /*
   bus_adapter bus_adp(.clock(clk),
   .reset(reset),
   .master_readdatavalid(master_readdatavalid),
   .master_waitrequest(master_waitrequest), 
   .master_read(master_read),
   .master_readdata(bus_data),
   .master_write(master_write),
	.master_byteenable(master_byteenable),
   .slave_readdatavalid(slave_readdatavalid),
   .slave_waitrequest(slave_waitrequest),
   .slave_readdata(slave_readdata),
   .slave_write(0),
   .slave_read(slave_read),
   .slave_writedata(slave_writedata),
   .slave_address(slave_address),
   .master_address(master_address),
   .master_writedata(master_writedata),
   .test_master_read(test_master_read),
	.test_slave_read(test_slave_read),
	.test_waitrequest(test_waitrequest),
	.state(tmp_state));
  
    
   vga_master master (.clk(clk),
   .reset(reset),
   .pixel_read(pixel_read),
   .pixel_valid(pixel_valid),
   .bus_data(slave_readdata),
   .cur_vga_addr(cur_vga_addr),
   .pixel_data(pixel_data),
   .master_readdatavalid(slave_readdatavalid),
   .master_waitrequest(slave_waitrequest),
   .master_address(slave_address),
   .master_read(slave_read),
   .base(frame_buffer_ptr));
	*/

   vga_master master (.clk(clk),
   .reset(reset),
   .pixel_read(pixel_read),
   .pixel_valid(pixel_valid),
   .bus_data(bus_data),
   .cur_vga_addr(cur_vga_addr),
   .pixel_data(pixel_data),
   .master_readdatavalid(master_readdatavalid),
   .master_waitrequest(master_waitrequest),
   .master_address(master_address),
   .master_read(master_read),
   .base(frame_buffer_ptr));

   vga_buffer buffer (.clk(clk),
   .reset(reset),
   .pixel_data(pixel_data),
   .pixel_valid(pixel_valid),
   .frame_buffer_ptr(frame_buffer_ptr),
   .pixel_read(pixel_read),
   .cur_vga_addr(cur_vga_addr),
   .*);
	
	hex7seg hex(
	.a(tmp_state),
	.y(read_state)
	);

endmodule
