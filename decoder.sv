// CSEE 4840 Lab 1: Display and modify the contents of a memory
//
// Spring 2019
//
// By: <Jie Huang><Kaige Zhang>
// Uni: <jh4000><kz2325>

module lab1( input logic        CLOCK_50,	     
	     input logic [3:0] 	KEY, // Pushbuttons; KEY[0] is rightmost
	     // 7-segment LED displays; HEX0 is rightmost
	     output logic [6:0] HEX0, HEX1, HEX2, HEX3, HEX4, HEX5
	     );
   logic [3:0] 		      a;         // Address
   logic [7:0] 		      din, dout; // RAM data in and out
   logic 		      we;        // RAM write enable
   logic 		      clk;
   assign clk = CLOCK_50;
   hex7seg h0( .a(a),         .y(HEX5) ), // Leftmost digit
           h1( .a(dout[7:4]), .y(HEX3) ), // left middle
           h2( .a(dout[3:0]), .y(HEX2) ); // right middle
   controller c( .* ); // Connect everything with matching names
   memory m( .* );
   assign HEX4 = 7'b111_1111; // Display a blank; LEDs are active-low
   assign HEX1 = 7'b111_1111;
   assign HEX0 = 7'b111_1111;
endmodule

module button(clk,in,out);
	input clk,in;
	output out;
	logic r1,r2,r3;
	always_ff @(posedge clk)
		begin
		r1<=in;
		r2<=r1;
		r3<=r2;
		end
	assign out=~r3&r2;
endmodule

module controller(input logic        clk,
		  input logic [3:0]  KEY,
		  input logic [7:0]  dout,
		  output logic [3:0] a,
		  output logic [7:0] din,
		  output logic 	     we);

   // Replace these with your code
   logic key3,key2,key1,key0;
   button button3(clk,KEY[3],key3);//press key3 to increment the address
   button button2(clk,KEY[2],key2);//press key2 to decrement the address
   button button1(clk,KEY[1],key1);//press key1 to increment the content
   button button0(clk,KEY[0],key0);//press key0 to decrement the content
   always_ff @( posedge clk) begin
		
      if(key1==1&&key0==0)
		begin
			din<=dout+1;
			we <= 1;
		end
      else if(key1==0&&key0==1)
		begin
			din<=dout-1;
			we <= 1;
		end
      else we <= 0;

      if(key3==1&&key2==0)a<=a+1; 
      else if(key3==0&&key2==1)a<=a-1;
      else a<=a;
   end
endmodule
		  
module hex7seg(input logic [3:0] a,
	       output logic [6:0] y);
  always_comb // Replace this with your code
     case(a)
        4'd0: y=7'b100_0000;
        4'd1: y=7'b111_1001;
        4'd2: y=7'b010_0100;
        4'd3: y=7'b011_0000;
        4'd4: y=7'b001_1001;
        4'd5: y=7'b001_0010;
        4'd6: y=7'b000_0010;
        4'd7: y=7'b111_1000;
        4'd8: y=7'b000_0000;
        4'd9: y=7'b001_0000;
		  4'd10: y=7'b010_0000;
		  4'd11: y=7'b000_0011;
		  4'd12: y=7'b010_0111;
		  4'd13: y=7'b010_0001;
		  4'd14: y=7'b000_0100;
		  4'd15: y=7'b000_1110;
        default: y=7'b111_1111;
     endcase
endmodule

// 16 X 8 synchronous RAM with old data read-during-write behavior
module memory(input logic        clk,
	      input logic [3:0]  a,
	      input logic [7:0]  din,
	      input logic 	 we,
	      output logic [7:0] dout);
   
   logic [7:0] 			 mem [15:0];

   always_ff @(posedge clk) begin
      if (we) mem[a] <= din;//write
      dout <= mem[a];//else read from memory location a
   end
        
endmodule
