module rasterizer_vertex_fetch (
	input clock,
	input reset,

	output [25:0] master_address,
	output master_read,
	output master_write,
	output [3:0] master_byteenable,
	input [31:0] master_readdata,
	input master_readdatavalid,
	output [31:0]master_writedata,
	input master_waitrequest,

	input read_enable,
	input [25:0] addr_in,

	output output_valid,
	output fetch_busy,
	output [95:0] vertex_out
);

	typedef enum logic[1:0] {IDLE_S, SEND1, SEND2, SEND3} send_t;
	send_t send_state;

	typedef enum logic[1:0] {IDLE_R, FETCH1, FETCH2} rec_t;
	rec_t rec_state;


	logic [31:0] coordinate[1:0];
	logic [25:0] addr;

	assign master_byteenable = 4'b1111;

	always_ff @(posedge clock or negedge reset) begin
		if (!reset) begin
			send_state <= IDLE_S;
			master_read <= 0;
			fetch_busy <= 0;
		end
		else begin
			case(send_state)
				IDLE_S: begin
					if (read_enable) begin
						fetch_busy <= 1;
						if (!master_waitrequest) begin
							master_address <= addr_in;
							master_read <= 1;
							addr <= addr_in + 4;
							send_state <= SEND2;
						end else begin
							master_read <= 0;
							addr <= addr_in;
							send_state <= SEND1;
						end
					end
				end
				SEND1: begin
					if (!master_waitrequest) begin
						master_address <= addr;
						master_read <= 1;
						addr <= addr + 4;
						send_state <= SEND2;
					end else
						master_read <= 0;
				end
				SEND2: begin
					if (!master_waitrequest) begin
						master_address <= addr;
						master_read <= 1;
						addr <= addr + 4;
						send_state <= SEND3;
					end else
						master_read <= 0;
				end
				SEND3: begin
					if (!master_waitrequest) begin
						master_address <= addr;
						master_read <= 1;
						fetch_busy <= 0;
						send_state <= IDLE_S;
					end else
						master_read <= 0;
				end
			endcase
		end
	end

	always_ff @(posedge clock or negedge reset) begin
		if (!reset) begin
			rec_state <= IDLE_R;
			output_valid <= 0;
		end
		else begin
			case (rec_state)
				IDLE_R: begin
					output_valid <= 0;
					if (master_readdatavalid) begin
						coordinate[0] <= master_readdata;
						rec_state <= FETCH1;
					end
				end
				FETCH1: begin
					if (master_readdatavalid) begin
						coordinate[1] <= master_readdata;
						rec_state <= FETCH2;
					end
				end
				FETCH2: begin
					if (master_readdatavalid) begin
						vertex_out[31:0] <= coordinate[0];
						vertex_out[63:32] <= coordinate[1];
						vertex_out[95:64] <= master_readdata;
						output_valid <= 1;

						rec_state <= IDLE_R;
					end
				end
				default: rec_state <= IDLE_R;
			endcase
		end
	end


endmodule
