module bus_adapter (
        input clk,
	input reset,
	//connect to upper master
	output logic valid,
	output logic wait,
	input logic write,//write enable signal
	input logic read,//read enable signal
	input logic [31:0]write_data,
        output logic [31:0] read_data,
	input logic[25:0]address,	
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
//three states: IDLE, read data, write data,WAIT
parameter IDLE=2'b00;
parameter READ_DATA=2'b01;
parameter WRITE_DATA=2'b10;
parameter WAIT=2'b11;
logic[1:0] state,
logic[1:0] nextstate,
logic flag;
logic readflag;
//state register
always_ff@(posedge clk or posedge rst)
begin
  if(rst)state<=IDLE;
   else state<=nextstate;
  
end
//next_state logic

always_comb
begin
   case(state)
	  WAIT:begin
                if(master_waitrequest==0)nextstate=IDLE;
                else nextstate=WAIT;
               end
	  IDLE: begin 
                if(master_waitrequest)nextstate=WAIT;
                else begin
                  if(write)nextstate=WRITE_DATA;//if write=1, write data to sram
	          else if(read)nextstate=READ_DATA;
	        end
                end
	  WRITE_DATA:begin 	       
                if(master_waitrequest)next_state=WAIT;
	        else begin 
                if(write|flag==1)nextstate=WRITE;
                else if(write==0&&read==1)nextstate=READ;
                else if(write==0&&read==0)nextstate=IDLE;
                end
	        end
	  READ_DATA:begin 
                if(master_waitrequest)next_state=WAIT;
	        else begin 
                  if(read)nextstate=READ;
                  else if(write==1&&read==0)nextstate=WRITE;
                  else if(write==0&&read==0)nextstate=IDLE;
                end
	        end
	endcase
end
//computation in each state
logic[31:0]buffer[2:0];
logic[25:0] addressbuffer;

logic read_request_flag;
always_ff@(posedge clk)
begin
   case(state)
	  S3: begin end
	  IDLE: begin 
	          flag<=0;
                  readflag<=0;
	        end
	  WRITE_DATA:begin
	                master_read<=0;
                        master_write<=1;
                        buffer[31:0]<=write_data[31:0];
                        wait<=1;
                        flag<=1;
                        master_writedata[15:0]<=write_data[31:16];
                        master_address<=address;
                        if(read==1)begin
                           addressbuffer<=address;
                           read_request_flag<=1;
                        end
                        if(flag==1)begin 
                           master_writedata[15:0]<=buffer[15:0];
                           flag<=0;
                           wait<=0;
                           master_address<=master_address+1;
                           end
	              end
	  READ_DATA:begin
	              master_read<=1;
                      master_write<=0;
                      wait<=1;
                      master_address<=address;//send data to sram controller
                      
                        
		    end
	endcase
end
//go up
logic [31:0]read_data_buffer;
always_ff@(posedge clk)
begin
  if(master_readdatavalid)
     if(readflag==0)begin
       read_data_buffer[31:16]<=master_readdata[15:0];
       readflag=!readflag;
    end
    else begin
       read_data[31:0]<={read_data_buffer[31:16],master_readdata[15:0]};
       readflag=!readflag;
    end
     
end
endmodule
