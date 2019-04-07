module vga_buffer(
    input clk,
    input logic [25:0] base_addr,
    output logic [7:0] VGA_R, VGA_G, VGA_B,
    output logic       VGA_CLK, VGA_HS, VGA_VS,
                       VGA_BLANK_n,
    output logic       VGA_SYNC_n);

    logic [10:0] h_count;
    logic [9:0] v_count;
    logic [319:0] buffer; 

    vga_counters counters(.clk50(clk, .*));
    

end module;


// for reference 
//buffer addr_bit = 4, store 16 elements
//data_bits = 26 [addr is 26 bits]

module fifo (
    input logic clk,
    input logic reset,
    input logic wr,
    input logic rd,
    input logic en,
    input logic [25:0] din,
    output logic empty,
    output logic full,
    output logic [25:0] dout);

    //DBITS: # of address bits
	//SIZE: 2^SZIE elements in buffer
    parameter DBITS = 26,
              SIZE = 4;
    
	//16 element fifo, each element is 26 bis
    logic [25:0] buffer[3:0];
    //write pointer
    logic [3:0] wr_ptr;
    //read pointer
    logic [3:0] rd_ptr;
    logic isFull, isEmpty;

    assign wr_ptr = 4'b0000;
    assign rd_ptr = 4'b0000;
    //counter keeps track of number of elements in buffer
    assign counter = 0;
    assign empty = (counter == 0) ? 1'b1 : 1'b0;
    assign full = (counter == 2**SIZE) ? 1'b1 : 1'b0;

	always @(posedge clk)
	begin
	    //en is 1 if buffer not full 
        if (en) begin
            if (reset) begin
                wr_ptr <= 4'b0000;
                rd_ptr <= 4'b0000;
                counter <= 0;
		    end 
		    else if (rd == 1'b1 && ~empty) begin
                dout = buffer[rd_ptr];
                rd_ptr = rd_ptr + 1;
                counter <= counter - 1;
			end
            else if (wr == 1'b1 && ~full) begin
                buffer[wr_ptr] = din;
                wr_ptr = rd_ptr + 1;
                counter <= counter + 1;
            end 
 
            if (wr_ptr == 4'd16)
                wr_ptr = 4'b0000;
	
            if (rd_ptr == 4'd16)
                rd_ptr = 4'b0000);

            empty = (counter == 0) > 1'b1 : 1'b0;
            full = (counter == 2**SIZE) ? 1'b1 : 1'b0;
         end
    end 

end module;  



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

   always_ff @(posedge clk50 or posedge reset)
     if (reset)          hcount <= 0;
     else if (endOfLine) hcount <= 0;
     else  	         hcount <= hcount + 11'd 1;

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
