interface avalon_bus_32;
    output [25:0] master_address;
    output master_read;
    output master_write;
    output [3:0] master_byteenable;
    input [31:0] master_readdata;
    input master_readdatavalid;
    output [31:0]master_writedata;
    input master_waitrequest;
endinterface

module rasterizer_fetch_logic (
    input clock,
    input reset,

    input input_valid,
    input [25:0] addr_in,
    input [23:0] color_in,
    input [31:0] depth_in,
    
    output output_valid,
    output [25:0] addr_out,
    output [31:0] old_depth_out,
    output [31:0] new_depth_out,
    output [23:0] color_out,
    output wait_request,

    avalon_bus_32 sdram
);

logic [95:0] data_in;
logic [95:0] data_out;
logic rdreq;
logic wrreq;
logic almost_full;
logic almost_empty;
logic full;
logic empty;

reg [95:0] fifo_out_reg;
reg fifo_out_reg_valid;

reg [32:0] sdram_out_reg;
reg sdram_out_reg_valid;


assign data_in[25:0] = addr_in;
assign data_in[49:26] = color_in;
assign data_in[81:50] = depth_in;
assign data_in[95:82] = 0;

assign addr_out = fifo_out_reg[25:0];
assign color_out = fifo_out_reg[49:26];
assign new_depth_out = fifo_out_reg[81:50];

rasterizer_fifo fifo(
    .*,
    .data(data_in),
    .q(data_out)
);

always_ff @(posedge clock or negedge reset) begin
    if (!reset) begin
        rdreq <= 0;
        wrreq <= 0;
        data_valid <= 0;
        wait_request <= 0;
        in_state <= IN_IDLE;
        read_request_state <= 0;
        fifo_out_reg_valid <= 0;
        sdram_out_reg_valid <= 0;
    end else begin
        // deal with input port
        if (input_valid && !full)
        begin
            // enqueue the fetch request
            wrreq <= 1;
            sdram.master_address <= addr_in;
            sdram.master_read <= 1;
            sdram.master_write <= 0;
            sdram.master_byteenable <= 2'b11;
            wait_request <= almost_full;
        end
        if (wait_request && !full)
            wait_requeset <= 0;

        // pop one from fifo by default
        if (!fifo_out_reg_valid && !empty)
            rdreq = 1;
        if (rdreq && almost_empty)
            rdreq = 0;
        if (rdreq) begin
            fifo_out_reg_valid <= 1;
            fifo_out_reg <= data_out;
        end

        // check if there is any output from sdram
        if (sdram.master_readdatavalid) begin
            if (fifo_out_reg_valid) begin
                output_valid <= 1;
                old_depth_out <= sdram.master_readdata;
                fifo_out_reg_valid <= 0;
				end
            else begin
                output_valid <= 0;
                rdreq = 0;
                sdram_out_reg <= sdram.master_readdata;
                sdram_out_reg_valid <= 1;
            end
        end else
        if (sdram_out_reg_valid && fifo_out_reg_valid) begin
            output_valid <= 1;
            old_depth_out <= sdram_out_reg; 
            sdram_out_reg_valid <= 0;
            fifo_out_reg_valid <= 0;
        end else
            output_valid <= 0;
    end
end

endmodule
