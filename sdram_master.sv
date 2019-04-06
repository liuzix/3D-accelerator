module sdram_master(
	input clk,
	input reset,
	output [25:0] master_address,
	output master_read,
	output master_write,
	output [1:0] master_byteenable,
	input [15:0] master_readdata,
	input master_readdatavalid,
	output [15:0]master_writedata,
	input master_waitrequest,
   output [6:0]  HEX0,
   output [6:0]  HEX1,
   output [6:0]  HEX2,
   output [6:0]  HEX3
);

typedef enum logic[1:0] {IDLE, WAITING, BLOCKED} bus_trans_t;

bus_trans_t bus_trans_state = IDLE;
logic [15:0] data = 0;

hexto7segment digit_0 (.x(data[3:0]), .z(HEX0));
hexto7segment digit_1 (.x(data[7:4]), .z(HEX1));
hexto7segment digit_2 (.x(data[11:8]), .z(HEX2));
hexto7segment digit_3 (.x(data[15:12]), .z(HEX3));

always_ff @(posedge clk)
begin
	case(bus_trans_state) 
		IDLE: begin
			if (master_waitrequest)
				bus_trans_state <= BLOCKED;
			else
			begin
				master_address <= 26'h10000;
				master_read <= 1;
				master_write <= 0;
				master_byteenable <= 2'b11;
				bus_trans_state <= WAITING;
			end
		end
		WAITING: begin
			if (master_readdatavalid)
			begin
				data <= master_readdata;
				bus_trans_state <= IDLE;
			end
		end
		BLOCKED: begin
			if (!master_waitrequest)
				bus_trans_state <= IDLE;
		end
	endcase
end

endmodule

module hexto7segment(
    input  [3:0]x,
    output reg [6:0]z
    );
	 
always_comb
	case (x)
		4'b0000 :      	//Hexadecimal 0
		z = 7'b1111110;
		4'b0001 :    		//Hexadecimal 1
		z = 7'b0110000  ;
		4'b0010 :  		// Hexadecimal 2
		z = 7'b1101101 ; 
		4'b0011 : 		// Hexadecimal 3
		z = 7'b1111001 ;
		4'b0100 :		// Hexadecimal 4
		z = 7'b0110011 ;
		4'b0101 :		// Hexadecimal 5
		z = 7'b1011011 ;  
		4'b0110 :		// Hexadecimal 6
		z = 7'b1011111 ;
		4'b0111 :		// Hexadecimal 7
		z = 7'b1110000;
		4'b1000 :     		 //Hexadecimal 8
		z = 7'b1111111;
		4'b1001 :    		//Hexadecimal 9
		z = 7'b1111011 ;
		4'b1010 :  		// Hexadecimal A
		z = 7'b1110111 ; 
		4'b1011 : 		// Hexadecimal B
		z = 7'b0011111;
		4'b1100 :		// Hexadecimal C
		z = 7'b1001110 ;
		4'b1101 :		// Hexadecimal D
		z = 7'b0111101 ;
		4'b1110 :		// Hexadecimal E
		z = 7'b1001111 ;
		4'b1111 :		// Hexadecimal F
		z = 7'b1000111 ;
	endcase
 
endmodule