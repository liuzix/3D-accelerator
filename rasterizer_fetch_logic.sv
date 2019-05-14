module rasterizer_fetch_logic (
    input clock,
    input reset,
    
    /* bus interface */
    output [25:0] master_address,
    output master_read,
    output master_write,
    output [3:0] master_byteenable,
    input [31:0] master_readdata,
    input master_readdatavalid,
    output [31:0]master_writedata,
    input master_waitrequest,

    /* pipeline control */
    input stall_in,
    output stall_out,
    input done_in,
    output done_out,
    

    /* data input */
    input input_valid,
    input [25:0] addr_in,
    //input [23:0] color_in,
    input [23:0] color_in_1,
    input [23:0] color_in_2,
    input [23:0] color_in_3,

    input signed [31:0] w1,
    input signed [31:0] w2,
    input signed [31:0] w3,
    input [31:0] depth_in,
    
    /* data output */
    output output_valid,
    output [25:0] addr_out,
    output [31:0] old_depth_out,
    output [31:0] new_depth_out,
    output [23:0] color_out
);

reg [25:0] addr_in_r;
reg [23:0] color_in_r;
reg [31:0] depth_in_r;
reg input_valid_r;
reg done_in_r;

logic [95:0] data_in;
logic [95:0] data_out;
logic rdreq;
logic wrreq;
logic almost_full;
logic almost_empty;
logic full;
logic empty;
logic half_full;

reg [95:0] data_out_reg;
assign addr_out = data_out_reg[25:0];
assign color_out = data_out_reg[49:26];
assign new_depth_out = data_out_reg[81:50];
assign done_out = data_out_reg[82];

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
    .half_full(half_full),
    .almost_full(almost_full),
    .almost_empty(almost_empty)
);

//fixed point multiplication
function logic signed [31:0] fp_m(
    input logic signed [31:0] a,
    input logic signed [31:0] b
);
    fp_m = (32'(a) * 64'(b)) >>> 16;
endfunction 

function logic signed [31:0] byte_to_fp(
    input logic [7:0] b
);
    
    byte_to_fp = {8'b0, b, 16'b0};
endfunction

function logic [7:0] fp_to_byte(
    input logic signed [31:0] f
);
    fp_to_byte = f[23:16]; 
endfunction

reg signed [31:0] color_step [8:0];
always_ff @(posedge clock or negedge reset) begin 
    if (!reset) begin

    end else begin
        if (enqueue || !input_valid_r) begin
            //color_in_r[7:0] = fp_to_byte(w1 * color_in_1[7:0] + w2 * color_in_2[7:0] + w3 * color_in_3[7:0]);
            //color_in_r[15:8] = fp_to_byte(w1 * color_in_1[15:8] + w2 * color_in_2[15:8] + w3 * color_in_3[15:8]);
            //color_in_r[23:16] = fp_to_byte(w1 * color_in_1[23:16] + w2 * color_in_2[23:16] + w3 * color_in_3[23:16]);
            
            color_step[0] <= w1 * color_in_1[7:0];
            color_step[1] <= w2 * color_in_2[7:0];
            color_step[2] <= w3 * color_in_3[7:0];
            color_step[3] <= w1 * color_in_1[15:8];
            color_step[4] <= w2 * color_in_2[15:8];
            color_step[5] <= w3 * color_in_3[15:8];
            color_step[6] <= w1 * color_in_1[23:16];
            color_step[7] <= w2 * color_in_2[23:16];
            color_step[8] <= w3 * color_in_3[23:16];
//color_in_r[15:8] = fp_to_byte(fp_m(w1, byte_to_fp(color_in_1[15:8])) + fp_m(w2, byte_to_fp(color_in_2[15:8])) + fp_m(w3, byte_to_fp(color_in_3[15:8])));
//            color_in_r[23:16] = fp_to_byte(fp_m(w1, byte_to_fp(color_in_1[23:16])) + fp_m(w2, byte_to_fp(color_in_2[23:16])) + fp_m(w3, byte_to_fp(color_in_3[23:16])));
            addr_in_r <= addr_in;
            depth_in_r <= depth_in;
            input_valid_r <= input_valid;
        end
    end
end

assign color_in_r[7:0] = fp_to_byte(color_step[0] + color_step[1] + color_step[2]);
assign color_in_r[15:8] = fp_to_byte(color_step[3] + color_step[4] + color_step[5]);
assign color_in_r[23:16] = fp_to_byte(color_step[6] + color_step[7] + color_step[8]);

typedef enum logic { S_IDLE,  S_HOLD } state_t;
state_t state;
state_t next_state;

reg enqueue;
always @* begin
    enqueue = 0;
    case (state)
        S_IDLE: begin
            if (full) begin
                next_state = S_IDLE;
            end
            else if (input_valid_r) begin
                next_state = S_HOLD;
                enqueue = 1;
            end else
                next_state = S_IDLE;
        end

        S_HOLD: begin
            if (!master_waitrequest && !stall_in) begin
                if (!almost_full && input_valid_r) begin
                    next_state = S_HOLD;
                    enqueue = 1;
                end else begin
                    enqueue = 0;
                    next_state = S_IDLE;
                end
            end else begin
                if (master_waitrequest) begin
                    next_state = S_HOLD;
                end else begin
                    next_state = S_IDLE;
                end
                enqueue = 0;
            end
        end
    endcase
end

assign stall_out = !enqueue;

always_ff @(posedge clock or negedge reset) begin
    if (!reset) begin
        wrreq <= 0;
        output_valid <= 0;
        state <= S_IDLE;
        //stall_out <= 1;
    end else begin
        if (full)
            $display("depth_fetcher: fifo is full");
        // deal with input port
        //
        $display("depth_fetcher: master_waitrequest = %d", master_waitrequest);
        $display("input_valid = %d", input_valid);
        if (enqueue)
        begin
            // enqueue the fetch request
            $display("depth_fetcher: enqueue fetch request addr = %x", addr_in);
            wrreq <= 1;
            data_in[25:0] <= addr_in_r;
            data_in[49:26] <= color_in_r;
            data_in[81:50] <= depth_in_r;
            data_in[82] <= done_in_r;
            data_in[95:83] <= 0;

            master_address <= addr_in_r + 4;
            master_write <= 0;
            master_byteenable <= 4'b11;
        end
        else begin
            wrreq <= 0;
            $display("depth_fetcher: not enqueuing.");
        end

        if (next_state == S_IDLE) begin
            $display("depth_fetcher: master_read = 0");
            master_read <= 0;
        end else begin
            master_read <= 1;
            $display("depth_fetcher: master_read = 1");
        end

        $display("depth_fetcher: next_state = %d", next_state);
        
        state <= next_state;
       
        // check if there is any output from sdram
        if (master_readdatavalid) begin
            $display("depth_fetcher: got fetch request addr = %x", data_out[25:0]);
            assert(data_out[25:0] != addr_out);
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
