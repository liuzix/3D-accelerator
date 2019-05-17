// 16 X 8 synchronous RAM with old data read-during-write behavior
module memory(input logic clk,
	      input logic [31:0]  addr,
		  input logic [31:0]  data_in,
	      input logic w_enable,
	      input logic r_enable,
		  output logic done,
	      output logic [31:0] data_out);
   
   logic [7:0] 			 mem [15:0];

   always_ff @(posedge clk) begin
      if (we) mem[a] <= din;
      dout <= mem[a];
   end
        
endmodule
