
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
