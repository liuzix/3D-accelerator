
int datalength=16;//8bit integer, 8bits decimal

module graphics_accelerator(
input logic rst,
input logic clk,
input logic input_valid,
input logic [5:0]input_length,
input logic[15:0]data_in,
output logic compute_done,
output logic[1:0] state,
output logic[1:0] nextstate,
output logic input_done,
output logic [15:0]v1,
output logic [15:0]v2,
output logic [15:0]v3,
output logic [15:0]v4);
//typedef enum logic[1:0]{S3, init, store_input,compute}statetype;
parameter init=2'b00;
parameter store_input=2'b01;
parameter compute=2'b10;
parameter S3=2'b11;
logic [15:0] input_vertice[3:0]; //vertice coordinates (x,y,z,w)
logic [15:0] model_matrix[15:0];
logic [15:0] view_matrix[15:0];
logic [15:0] projection_matrix[15:0];
logic [15:0]data_out[3:0];
int i;
int j;


//state register
always_ff@(posedge clk or posedge rst)
begin
  if(rst)state<=init;
   else state<=nextstate;
  
end
//next_state logic
always_comb
begin
   case(state)
	  S3:nextstate=init;
	  init: begin if(input_valid)nextstate=store_input;
	        else nextstate=init;
	        end
	  store_input:begin 
	        if(input_done)nextstate=compute;
	        else nextstate=store_input;
	        end
	  compute:begin if(compute_done)nextstate=init;
	        else nextstate=compute;
	        end
	endcase
   v1=data_out[0];
   v2=data_out[1];
   v3=data_out[2];
   v4=data_out[3];
end
//computation in each state
always_ff@(posedge clk)
begin
   case(state)
	  S3: begin end
	  init: begin 
	           input_done<=0;
	           compute_done<=0;
	           i<=0;
	           j<=0;
			  end
	  store_input:begin	               
				    if(j<4)input_vertice[j]<=data_in;
					else if(j<20) model_matrix[j-4]<=data_in;
					j<=j+1;						 
				    if(j>=20)input_done<=1;
	              end
	  compute:begin
	              i<=i+1;
	              data_out[i]<=input_vertice[0]*model_matrix[i*4]+input_vertice[1]*model_matrix[i*4+1]+input_vertice[2]*model_matrix[i*4+2]+input_vertice[3]*model_matrix[i*4+3];	
                 if(i>=4)compute_done<=1;
				 end
	endcase
end


endmodule


module fixed_add(input logic operand1,input logic operand2,output logic sum);
assign sum=operand1+operand2;
endmodule


module matrix_buffer(input logic        clk,
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