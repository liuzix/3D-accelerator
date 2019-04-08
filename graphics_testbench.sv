module graphics_testbench;
  logic rst;
  logic clk;
  logic input_valid;
  logic [5:0]input_length;
  logic [15:0]data_in;
  logic compute_done;
  logic input_done;
  logic[1:0] state;
  logic[1:0] nextstate;
  logic [15:0]v1;
  logic [15:0]v2;
  logic [15:0]v3;
  logic [15:0]v4;
  
  //logic [15:0]data_out[3:0];
  assign data_in=1;
  assign input_length=20;
  initial begin
     rst=0;
	 clk=0;
	 input_valid=0;
	 #5 rst=1; 
	 #10 rst=0;
	 #15 input_valid=1;
	 #15 input_valid=0;
  end
  always #5 clk=~clk;
  graphics_accelerator inst1(
  .clk(clk),
  .rst(rst),
  .input_valid(input_valid),
  .data_in(data_in),
  .compute_done(compute_done),
 .state(state),
 .nextstate(nextstate),
 .input_done(input_done),
 .v1(v1),
 .v2(v2),
 .v3(v3),
 .v4(v4)
  );
endmodule