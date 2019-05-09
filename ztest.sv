module ztest (
    input clock,
    input reset,
    
    input output_valid,
    input [25:0] addr_in, //addr_out from rasterizer_fetch_logic
    input [31:0] old_depth_out,
    input [31:0] new_depth_out,
    input [31:0] color_in, //color out from rasterizer_fetch_logic
    //output [31:0] color_out,
    //output [25:0] addr_out,
    
    input done_in,
    output stall_out,
    output done_out
    
    output [25:0] master_address,
    output master_read,
    output master_write,
    output [3:0] master_byteenable,
    input [31:0] master_readdata,
    input master_readdatavalid,
    output [31:0]master_writedata,
    input master_waitrequest,
);

logic [113:0] data_in;
logic [113:0] data_out;
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
    if (!reset) 
        stall_out <= 1;
    else begin
        if (!full) begin
            wrreq <= 1;
            data_in[25:0] <= addr_in;
            data_in[49:26] <= color_in;
            data_in[81:50] <= old_depth_out;
            data_in[113:82] <= in_depth_out;
            data_in[114] <= done_in;
        end 
    end
end

wire [25:0] addr_out;
wire [23:0] color_out;
wire [31:0] old_depth_out;
wire [31:0] new_depth_out;
wire done_out_temp;

assign addr_out = data_out[25:0];
assign color_out = data_out[49:26];
assign old_depth_out = data[81:50];
assign new_depth_out = data[113:82];
assign done_out_reg = data[114];

always_ff @(posedge clock or negedge reset) begin
    if (!reset) begin
        done_out <= 0;
    end else
    if (!empty) begin
        if (new_depth_out > old_depth_out) begin
            rdreq <= 1;
            master_write <= 0;
            done_out <= done_out_temp;
        end else
        if (!master_write || !master_waitrequest) begin
            rdreq <= 1;
            master_address <= addr_out;
            master_writedata <= color_out;
            master_write <= 1;
        end
        else begin
            rdreq <= 0;
            master_write <= 0;
        end
    end
end

endmodule // ztest







