module ztest (
    input clock,
    input reset,
    
    input input_valid,
    input [25:0] addr_in, //addr_out from rasterizer_fetch_logic
    input [31:0] old_depth_out,
    output [31:0] new_depth_out,//input->output
    input [31:0] color_in, //color out from rasterizer_fetch_logic
    //output [31:0] color_out,
    //output [25:0] addr_out,
    
    input done_in,
    output stall_out,
    output done_out,
    
    output [25:0] master_address,
    output master_read,
    output master_write,
    output [3:0] master_byteenable,
    input [31:0] master_readdata,
    input master_readdatavalid,
    output [31:0]master_writedata,
    input master_waitrequest
);

assign master_byteenable = 4'b1111;
logic [114:0] data_in;
logic [114:0] data_out;
logic wrreq;
logic rdreq;
logic almost_full;
logic almost_empty;
logic full;
logic empty;
logic half_full;

fifo #(.DBITS(115), .SIZE(6))fifo(
    .din(data_in),
    .dout(data_out),
    .wr(wrreq),
    .rd(rdreq),
    .reset(reset),
    .clk(clock),
    .full(full),
    .empty(empty),
    .half_full(half_full),
    .almost_full(almost_full),
    .almost_empty(almost_empty)
);

assign stall_out = half_full;

always_ff @(posedge clock or negedge reset) begin
    if (!reset) begin
	 end else begin
        if (!almost_full && input_valid) begin
            $display("ztest: receive data from addr = %d", addr_in);
            wrreq <= 1;
            data_in[25:0] <= addr_in;
            data_in[49:26] <= color_in;
            data_in[81:50] <= old_depth_out;
            data_in[113:82] <= new_depth_out;
            data_in[114] <= done_in;
        end

        else begin
            if (almost_full)
                $display("ztest: almost full!");
            wrreq <= 0;
        end
    end
end

wire [25:0] addr_out;
wire [23:0] color_out;
//wire [31:0] old_depth_out;
//wire [31:0] new_depth_out;
wire done_out_temp;
logic [31:0]real_old_depth_out;
reg [31:0] real_new_depth_out;
assign addr_out = data_out[25:0];
assign color_out = data_out[49:26];
assign real_old_depth_out = data_out[81:50];
assign new_depth_out = data_out[113:82];
assign done_out_temp = data_out[114];

typedef enum logic[1:0] {S_IDLE, S_WRITE_COLOR, S_WRITE_DEPTH, S_POP} state_t;
state_t state;

always_ff @(posedge clock or negedge reset) begin
    if (!reset) begin
        done_out <= 0;
        state <= S_IDLE;
    end else begin
        case (state)
        S_IDLE: begin
            if (!empty) begin
                if (new_depth_out < real_old_depth_out) begin
                    rdreq <= 1;
                    $display("ztest: writing color to %d", addr_out);
                    master_address <= addr_out;
                    master_writedata <= color_out;
                    master_write <= 1;
                    real_new_depth_out <= new_depth_out;
                    state <= S_WRITE_COLOR;
                end else begin
                    $display("ztest: failed");
                    rdreq <= 1;
                    master_write <= 0;
                    done_out <= done_out_temp;
                    state <= S_POP;
                end
            end
        end

        S_WRITE_COLOR: begin
            rdreq <= 0;
            if (!master_waitrequest) begin
                $display("ztest: writing depth to %d", master_address + 4);
               master_address <= master_address + 4; 
               master_writedata <= real_new_depth_out;
               master_write <= 1;
               state <= S_WRITE_DEPTH;
            end
        end

        S_WRITE_DEPTH: begin
            if (!master_waitrequest) begin
                if (!empty) begin
                    if (new_depth_out < real_old_depth_out) begin
                        rdreq <= 1;
                        $display("ztest: writing color to %d", addr_out);
                        master_address <= addr_out;
                        master_writedata <= color_out;
                        master_write <= 1;
                        real_new_depth_out <= new_depth_out;
                        state <= S_WRITE_COLOR;
                    end else begin
                        $display("ztest: failed");
                        rdreq <= 1;
                        master_write <= 0;
                        done_out <= done_out_temp;
                        state <= S_IDLE;
                    end
                end else begin
                    master_write <= 0;
                    state <= S_IDLE;
                end
            end
        end

        S_POP: begin
            rdreq <= 0;
            state <= S_IDLE;
        end
        endcase
    end
end

endmodule // ztest







