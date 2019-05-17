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

hex7seg digit_0 (.a(data[3:0]), .y(HEX0));
hex7seg digit_1 (.a(data[7:4]), .y(HEX1));
hex7seg digit_2 (.a(data[11:8]), .y(HEX2));
hex7seg digit_3 (.a(data[15:12]), .y(HEX3));

always_ff @(posedge clk)
begin
	case(bus_trans_state) 
		IDLE: begin
			if (master_waitrequest)
				bus_trans_state <= BLOCKED;
			else
			begin
				master_address <= 26'h0;
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
