module rasterizer_unit (
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

    input [25:0] addr_in,
    output [25:0] addr_out 
);

// to rasterizer
logic output_valid;
logic fetch_busy;
logic [31:0] vertex_out[3:0];

// from rasterizer output
logic fetch_enable;
output done;

rasterizer_vertex_fetch vfetch (
    .clock(clock),
    .reset(reset),
    .master_address(master_address),
    .master_read(master_read),
    .master_write(master_write),
    .master_byteenable(master_byteenable),
    .master_readdata(master_readdata),
    .master_readdatavalid(master_readdatavalid),
    .master_writedata(master_writedata),
    .master_waitrequest(master_waitrequest),
    .output_valid(output_valid),
    .fetch_enable(fetch_enable),
    .fetch_busy(fetch_busy),
    .vertex_out(vertex_out));

logic [31:0] v1[3:0];
logic [31:0] v2[3:0];
logic [31:0] v3[3:0];
logic [1:0] counter;
logic ready;

//can begin fetching next set of vertices if done
always_comb begin
    if (done)
        ready <= 0
end

always_ff @(posedge clock or negedge reset) begin
    if (reset) begin
        counter <= 0;
        ready <= 0;
    end

    if (!ready & output_valid) begin
        if (counter == 0) begin
            v1 <= vertex_out;
            counter <= counter + 1;
        end else if (counter == 1) begin
            v2 <= vertex_out;
            counter <= counter + 1;
        end else if counter == 2) begin
            v3 <= vertex_out;
            ready <= 1;
            counter <= 0;
        end
    end
end


rasterizer rast (
    .clock(clock),
    .reset(reset),
    .x1(v1[0]),
    .y1(v1[1]),
    .x2(v2[0]),
    .y2(v2[1]),
    .x3(v3[0]),
    .y3(v3[1]),
    .ready(ready),
    .addr_in(addr_in),
    .addr_out(addr_out),
    .fetch_enable(fetch_enable),
    .done(done));


