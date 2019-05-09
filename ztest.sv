module ztest (
    input clock,
    input reset,
    input output_valid,
    input [25:0] addr_in, //addr_out from rasterizer_fetch_logic
    input [31:0] old_depth_out,
    input [31:0] new_depth_out,
    input [31:0] color_in, //color out from rasterizer_fetch_logic
    input master_waitrequest,
    input done_in,
    output [31:0] color_out,
    output [25:0] addr_out,
    output stall_out,
    output done_out
);

logic [113:0] data_in;
logic [113:0] data_out;
logic wrreq;
logic rdreq;
logic almost_full;
logic almost_empty;
logic full;
logic empty;

fifo #(.DBITS(115))fifo(
    .din(data_in),
    .dout(data_out),
    .wr(wrreq),
    .rd(rdreq),
    .reset(reset),
    .clk(clock),
    .full(full),
    .empty(empty),
    .almost_full(almost_full),
    .almost_empty(almost_empty)
);


always_ff @(posedge clock) begin
    if (!full) begin
        wrreq <= 1;
        data_in[25:0] <= addr_in;
        data_in[49:26] <= color_in;
        data_in[81:50] <= old_depth_out;
        data_in[113:82] <= in_depth_out;
        data_in[114] <= done_in;
    end
end


always_ff @(posedge clock or negedge reset) begin
    if (!reset) begin
        done_out <= 0;
        stall_out <= 0;
    end
    
    if (master_waitrequest & full)
        stall_out <= 1;
    else
        stall_out <= 0;
    
    if (!empty) begin
        rdreq <= 1;
        addr_in <= data_out[25:0];
        color_in <= data_out[49:26];
        old_depth_out <= data[81:50];
        in_depth_out <= data[113:82];
        done_out <= data[114]
    end
    
    if (new_depth_out < out_depth_out) begin
        addr_out <= addr_in;
        color_out <= color_in;
    end
end

endmodule // ztest







