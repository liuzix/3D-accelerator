module bus_adapter #(parameter N=8)(
    input clk,
	input reset,
	//connect to upper master
	output logic valid,
	output logic wait,
	input logic write,
	input logic read,
	inout logic [31:0]data,
	input logic[25:0]address,
	input logic [N-1:0]burst_num,
	//connect to sram controller 
	//read from sram
	input [15:0] master_readdata,
	input master_readdatavalid,
	input master_waitrequest, 
	//to sram
	output [25:0] master_address,
	output master_read,
	output master_write,
	output [1:0] master_byteenable,	
	output [15:0]master_writedata);// write to sram
	
//pointer of fifo queue
logic [7:0]head;
logic[7:0]tail;
logic [15:0]queue[2**N-1:0];//default maximum burst is 256
//three states: IDLE, read data, write data
parameter IDLE=2'b00;
parameter READ_DATA=2'b01;
parameter WRITE_DATA=2'b10;
parameter WAIT=2'b11;
logic[1:0] state,
logic[1:0] nextstate,
//state register
always_ff@(posedge clk or posedge rst)
begin
  if(rst)state<=init;
   else state<=nextstate;
  
end
//next_state logic
logic burst_done;
always_comb
begin
   case(state)
	  WAIT:nextstate=IDLE;
	  IDLE: begin if(write)nextstate=WRITE_DATA;//if write=1, write data to sram
	        else if(read)nextstate=READ_DATA;
	        end
	  WRITE_DATA:begin 
	        if(burst_done)nextstate=IDLE;
	        else nextstate=WRITE_DATA;
	        end
	  READ_DATA:begin if(burst_done)nextstate=IDLE;
	        else nextstate=READ_DATA;
	        end
	endcase
end
//computation in each state
int endofqueue;
int i;
int j;
logic flag;
always_ff@(posedge clk)
begin
   case(state)
	  S3: begin end
	  IDLE: begin 
	           burst_done<=0;
	           head<=0;//head of the queue
	           tail<=0;
	           i<=0;
	           j<=0;
	           endofqueue=2**N;
	           flag<=0;
			  end
	  WRITE_DATA:begin
	                master_read<=0;
					master_write<=1;	               
				    for(i;i<burst_num;i++)begin
				       queue[tail]<=data[31:16];
				       queue[tail+1]<=data[15:0];
				       tail<=tail+2;
				       master_address<=address+i;
				       if(i==0)master_writedata<=data[31:16];
				       else begin
				           master_writedata<=queue[head];
				           head<=head+1;
				          end
				        if(tail>=endofqueue)tail<=0;
				        if(head>=endofqueue)head<=0;
				    end
				    if(i>=burst_num)burst_done<=1;
	              end
	  READ_DATA:begin
	              master_read<=1;
	              master_write<=0;
	              valid<=1;
	              for(j;j<2*burst_num;j++)begin
	                  if(flag==0)queue[0]<=master_writedata[15:0];
	                  else data={queue[0],master_writedata[15:0]};
	                  flag=!flag;
	                end
				 end
	endcase
end




endmodule
