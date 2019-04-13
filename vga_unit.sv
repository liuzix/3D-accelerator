module vga_unit(input clk,
   input reset,
   input [25:0] frame_buffer_ptr,
   input master_readdatavalid,
   input master_waitrequest,
   output master_read,
   output master_write,
   output [31:0] master_writedata,
   input [31:0] bus_data,
   output [25:0] master_address,
   output logic [7:0] VGA_R, VGA_G, VGA_B,
   output logic 	   VGA_CLK, VGA_HS, VGA_VS,
   VGA_BLANK_n,
   output logic	   VGA_SYNC_n);

   logic pixel_read;
   logic [25:0] cur_vga_addr;
   logic [31:0] pixel_data;
   logic pixel_valid;
   
   //----- bus adapter ------//
   //output
   logic slave_readdatavalid;
   logic slave_waitrequest;
   logic [31:0] slave_readdata;
   logic [1:0] master_byteenable;
   logic [15:0] master_writedata;

   //input
   logic slave_write;
   logic slave_read;
   logic [31:0] slave_writedata;
   logic [25:0] slave_address;
   //------------------------//


   bus_adapter bus_adp(.clk(clk),
   .reset(reset),
   .master_readdatavalid(master_readdatavalid),
   .master_waitrequest(master_waitrequest), 
   .master_read(master_read),
   .master_write(master_write),
   .*);

   vga_master master (.clk(clk),
   .reset(reset),
   .bus_data(bus_data),
   .master_readdatavalid(master_readdatavalid),
   .master_waitrequest(master_waitrequest),
   .base(frame_buffer_ptr),
   .*);

   vga_buffer buffer (.clk(clk),
   .reset(reset),
   .*);

endmodule
