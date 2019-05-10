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

    input fetch_enable,
    input [25:0] vertex_buffer_base,
    /* tasterizer_unit pipeling interface*/
    input stall_in,
    //output stall_out,
    //input done_in,
    output done_out,

    output output_valid,
    output [31:0] vertex_out[14:0]
);

    parameter FIFO_SIZE = 4;

    typedef enum logic[1:0] {IDLE_S, SEND, TRI_SEND} send_t;
    send_t send_state;

    typedef enum logic[1:0] {IDLE_R, FETCH, TRI_FETCH} rec_t;
    rec_t rec_state;

    logic [31:0] vertex_out_buf[14:0];
    logic [3:0] r_count;
    int output_count;
    logic [25:0] addr;
    int tri_num = 0;
    int input_count;

    assign master_byteenable = 4'b1111;

    assign done_out = (tri_num != 0) && (output_count == tri_num);

    logic [3:0] s_count;

    logic [479:0] data_in;
    logic [479:0] data_out;
    logic wrreq;
    logic rdreq;
    logic full;
    logic empty;
    logic almost_full;
    logic half_full;
    logic almost_empty;

    logic recv_valid;
    int fifo_size = 2**FIFO_SIZE;
    int fifo_counter;
    
    fifo #(.DBITS(480), .SIZE(FIFO_SIZE))fifo(
        .clk(clock),
        .reset(reset),
        .wr(wrreq),
        .rd(rdreq),
        .din(data_in),
        .empty(empty),
        .full(full),
        .almost_full(almost_full),
        .half_full(half_full),
        .almost_empty(almost_empty),
        .dout(data_out)   
    );

    assign vertex_out = {>>{data_out}};

    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            fifo_counter = 0;
        end

        if (recv_valid && !full) begin
            wrreq <= 1;
            data_in <= {>>{vertex_out_buf}};
        end else
            wrreq <= 0;

        if (!stall_in && !empty) begin
            rdreq <= 1;
            fifo_counter = fifo_counter - 1;
            output_valid <= 1;
        end else begin
            rdreq <= 0;
            output_valid <= 0;
        end
    end

    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            send_state <= IDLE_S;
            master_read <= 0;
            s_count <= 0;
            tri_num = 0;
            input_count <= 0;
        end
        else begin
            case(send_state)
                IDLE_S: begin
                    if (input_count < tri_num && fifo_counter < fifo_size) begin
                        master_address <= addr;
                        master_read <= 1;
                        addr <= addr + 4;
                        input_count <= input_count + 1;
                        fifo_counter = fifo_counter + 1;
                        s_count <= s_count + 1;
                        send_state <= SEND;
                    end
                    if (tri_num == 0 && fetch_enable) begin
                        master_address <= vertex_buffer_base;
                        master_read <= 1;
                        addr <= addr + 4;
                        send_state <= TRI_SEND;
                    end
                end
                SEND: begin
                    if (s_count < 15) begin
                        if (!master_waitrequest) begin
                            master_address <= addr;
                            master_read <= 1;
                            addr <= addr + 4;
                            s_count <= s_count + 1;
                        end else begin
                            master_address <= addr - 4;
                            master_read <= 1;
                        end
                    end else begin
                        if (!master_waitrequest) begin
                            master_read <= 0;
                            s_count <= 0;
                            send_state <= IDLE_S;
                        end else begin
                            master_address <= addr - 4;
                            master_read <= 1;
                        end
                    end
                end
                TRI_SEND: begin
                    if (!master_waitrequest) begin
                        master_read <= 0;
                        send_state <= IDLE_S;
                    end else begin
                        master_address <= addr - 4;
                        master_read <= 1;
                    end
                end
                default: begin end
            endcase
        end
    end

    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            rec_state <= IDLE_R;
            recv_valid <= 0;
            r_count <= 0;
            output_count <= 0;
        end
        else begin
            case (rec_state)
                IDLE_R: begin
                    recv_valid <= 0;
                    if (master_readdatavalid && tri_num != 0) begin
                        vertex_out_buf[r_count] <= master_readdata;
                        r_count <= r_count + 1;
                        rec_state <= FETCH;
                    end

                    if (master_readdatavalid && tri_num == 0) begin
                        tri_num = master_readdata;
                    end
                end
                FETCH: begin
                    if (master_readdatavalid) begin
                        if (r_count == 14) begin
                            r_count <= 0;
                            //vertex_out[13:0] <= vertex_out_buf[13:0];
                            vertex_out[r_count] <= master_readdata;
                            recv_valid <= 1;
                            output_count <= output_count + 1;
                            rec_state <= IDLE_R;
                        end else begin
                            vertex_out_buf[r_count] <= master_readdata;
                            r_count <= r_count + 1;
                        end
                    end
                end
                default: begin end
            endcase
        end
    end
endmodule
