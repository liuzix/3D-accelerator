module vga_master(
    input clk,
    input reset,
	input pixel_read,
	input [25:0] cur_vga_addr,
	input [31:0] bus_data, //data returned by bus
	input master_readdatavalid, 
	input master_waitrequest,
	output [25:0] master_address,
	output master_read,
    output [31:0] pixel_data,
	output pixel_valid);

	logic sync_valid;
	logic [25:0] sync_addr;
	reg [25:0] cur_addr; 

	reg wr;
	reg rd;
	reg [25:0] din;
	wire [25:0] dout;

	reg signed [31:0] signed_addr;

	assign signed_addr[25:0] = cur_vga_addr;
	assign signed_addr[31:26] = 0;

	integer up_addr;
	integer down_addr;
	logic [31:0] pixel_buffer[4:0];
	logic [3:0] pixel_rd_ptr;
	logic [3:0] pixel_wr_ptr;
	logic [3:0] pixel_in_progress;
    assign rd = master_readdatavalid; 

	//fifo
	logic full;
	logic empty;
	logic almost_empty;
	logic almost_full;

	fifo #(.DBITS(26)) buffer(
				.clk(clk),
			    .reset(reset),
				.wr(wr),
				.rd(rd),
				.din(din),
				.*);
    
	always_ff @(posedge clk)
	begin
		if (!reset) begin
			cur_addr <= cur_vga_addr + 128;
			pixel_in_progress <= 0;
			pixel_valid <= 0;
			up_addr <= 0;
			down_addr = 0;
		end

		if (!master_waitrequest) begin	
			wr <= 1;
			din <= cur_addr;
			master_read <= 1;
			master_address <= cur_addr;
			cur_addr <= cur_addr + 8;
			pixel_in_progress = pixel_in_progress + 1;
		end
		else begin
			wr <= 0;
			master_read <= 0;
		end

		if (pixel_read) begin
			pixel_in_progress = pixel_in_progress - 1;
			if (up_addr - signed_addr > 0 && signed_addr - down_addr > 0) begin
				pixel_data <= pixel_buffer[cur_vga_addr % 32];
				down_addr[25:0] = cur_vga_addr + 26'd8;
				pixel_valid <= 1;
			end
			else 
				pixel_valid <= 0;
		end

		if (master_readdatavalid) begin
			if (empty)
				$fatal("fifo empty");

			if (dout == up_addr[25:0] + 8) 
				pixel_buffer[up_addr % 32] <= bus_data;
		end
	end
endmodule



module vga_buffer(
	input logic clk,
	input logic reset, 
	input [31:0] pixel_data,
	input logic pixel_valid,
	input [25:0] frame_buffer_ptr,
	output pixel_read,
	output [25:0] cur_vga_addr,
	output logic [7:0] VGA_R, VGA_G, VGA_B,
	output logic 	   VGA_CLK, VGA_HS, VGA_VS,
					   VGA_BLANK_n,
	output logic	   VGA_SYNC_n);

	logic [10:0]    hcount;
	logic [9:0]     vcount;

	logic clk50;
	logic [1:0] clk_counter;

	always_ff @(posedge clk)
		clk_counter = clk_counter + 1;
	

	assign pixel_read = (clk_counter == 3);	
	assign clk50 = (clk_counter == 0); 	
 
	vga_counters counters(.clk50(clk50), .reset(!reset), .*);		
	
	always_ff @(posedge clk)
		if (reset) begin
			{VGA_R, VGA_G, VGA_B} = {8'h0, 8'h0, 8'h0};
			cur_vga_addr = frame_buffer_ptr;
			pixel_read = 0;
		end 
	
	always_comb begin
		if (pixel_valid) begin
			{VGA_R, VGA_G, VGA_B} = {pixel_data[31:24], pixel_data[23:16], pixel_data[15:8]};
			cur_vga_addr = frame_buffer_ptr + (hcount + 640) * vcount;
		end
	end
endmodule




module vga_counters(
 input logic 	     clk50, reset,
 output logic [10:0] hcount,  // hcount[10:1] is pixel column
 output logic [9:0]  vcount,  // vcount[9:0] is pixel row
 output logic 	     VGA_CLK, VGA_HS, VGA_VS, VGA_BLANK_n, VGA_SYNC_n);

/*
 * 640 X 480 VGA timing for a 50 MHz clock: one pixel every other cycle
 *
 * HCOUNT 1599 0             1279       1599 0
 *             _______________              ________
 * ___________|    Video      |____________|  Video
 *
 *
 * |SYNC| BP |<-- HACTIVE -->|FP|SYNC| BP |<-- HACTIVE
 *       _______________________      _____________
 * |____|       VGA_HS          |____|
 */
   // Parameters for hcount
   parameter HACTIVE      = 11'd 1280,
             HFRONT_PORCH = 11'd 32,
             HSYNC        = 11'd 192,
             HBACK_PORCH  = 11'd 96,
             HTOTAL       = HACTIVE + HFRONT_PORCH + HSYNC +
                            HBACK_PORCH; // 1600

   // Parameters for vcount
   parameter VACTIVE      = 10'd 480,
             VFRONT_PORCH = 10'd 10,
             VSYNC        = 10'd 2,
             VBACK_PORCH  = 10'd 33,
             VTOTAL       = VACTIVE + VFRONT_PORCH + VSYNC +
                            VBACK_PORCH; // 525

   logic endOfLine;

   always_ff @(posedge clk50 or posedge reset) begin
     if (reset)          hcount <= 0;
     else if (endOfLine) hcount <= 0;
     else begin
         hcount <= hcount + 11'd 1;
     end
   end

   assign endOfLine = hcount == HTOTAL - 1;

   logic endOfField;

   always_ff @(posedge clk50 or posedge reset)
     if (reset)          vcount <= 0;
     else if (endOfLine)
       if (endOfField)   vcount <= 0;
       else              vcount <= vcount + 10'd 1;

   assign endOfField = vcount == VTOTAL - 1;

   // Horizontal sync: from 0x520 to 0x5DF (0x57F)
   // 101 0010 0000 to 101 1101 1111
   assign VGA_HS = !( (hcount[10:8] == 3'b101) &
		      !(hcount[7:5] == 3'b111));
   assign VGA_VS = !( vcount[9:1] == (VACTIVE + VFRONT_PORCH) / 2);

   assign VGA_SYNC_n = 1'b0; // For putting sync on the green signal; unused

   // Horizontal active: 0 to 1279     Vertical active: 0 to 479
   // 101 0000 0000  1280	       01 1110 0000  480
   // 110 0011 1111  1599	       10 0000 1100  524
   assign VGA_BLANK_n = !( hcount[10] & (hcount[9] | hcount[8]) ) &
			!( vcount[9] | (vcount[8:5] == 4'b1111) );

   /* VGA_CLK is 25 MHz
    *             __    __    __
    * clk50    __|  |__|  |__|
    *
    *             _____       __
    * hcount[0]__|     |_____|
    */
   assign VGA_CLK = hcount[0]; // 25 MHz clock: rising edge sensitive

endmodule
