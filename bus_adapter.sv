module bus_adapter(
    input clk,
	input reset,
	input [15:0] master_readdata,//read from sram
	input master_readdatavalid,
	input master_waitrequest,
	input 
	output [25:0] master_address,//to sram
	output master_read,
	output master_write,
	output [1:0] master_byteenable,	
	output [15:0]master_writedata,// write to sram
	
//request_type=1  read from sram; =0 write to sram
//burst_num is the number of data in one transaction,maximum burst is 16
logic flag;
always_ff @(posedge clk or posedge rst)
begin
  if(rst==1)flag<=0;
  if(request_type==1)begin
       
  end
end

endmodule
