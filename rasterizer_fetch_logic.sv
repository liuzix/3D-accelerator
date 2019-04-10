module rasterizer_fetch_logic (
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

    input input_valid,
    input [25:0] addr_in,
    input [23:0] color_in,
    input [31:0] depth_in,
    
    output output_valid,
    output [25:0] addr_out,
    output [31:0] old_depth_out,
    output [31:0] new_depth_out,
    output [23:0] color_out,
    output wait_request
);

logic [95:0] data_in;
logic [95:0] data_out;
logic rdreq;
logic wrreq;
logic almost_full;
logic almost_empty;
logic full;
logic empty;

reg [95:0] data_out_reg;
assign addr_out = data_out_reg[25:0];
assign color_out = data_out_reg[49:26];
assign new_depth_out = data_out_reg[81:50];

assign wait_request = almost_full;
assign rdreq = master_readdatavalid;

fifo fifo(
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

always_ff @(posedge clock or negedge reset) begin
    if (!reset) begin
        wrreq <= 0;
        output_valid <= 0;
    end else begin
        if (full)
            $display("fifo is full");
        // deal with input port
        if (input_valid && !full)
        begin
            // enqueue the fetch request
            $display("enqueue fetch request addr = %x", addr_in);
            wrreq <= 1;
            data_in[25:0] <= addr_in;
            data_in[49:26] <= color_in;
            data_in[81:50] <= depth_in;
            data_in[95:82] <= 0;

            master_address <= addr_in + 4;
            master_read <= 1;
            master_write <= 0;
            master_byteenable <= 4'b11;
        end
        else begin
            wrreq <= 0;
            master_read <= 0;
        end
       
        // check if there is any output from sdram
        if (master_readdatavalid) begin
            old_depth_out <= master_readdata;
            data_out_reg <= data_out;
            output_valid <= 1;
            if (empty)
                $fatal("fifo is empty!");
        end else
            output_valid <= 0;
    end
end

endmodule
