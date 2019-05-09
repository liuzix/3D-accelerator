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

    typedef enum logic[1:0] {IDLE_S, SEND, TRI_SEND} send_t;
    send_t send_state;

    typedef enum logic[1:0] {IDLE_R, FETCH, TRI_FETCH} rec_t;
    rec_t rec_state;


    logic [25:0] addr;
    int tri_num = 0;
    int total_count;

    assign master_byteenable = 4'b1111;

    assign done_out = (tri_num != 0) && (output_count == tri_num);

    logic [3:0] s_count;
    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            send_state <= IDLE_S;
            master_read <= 0;
            s_count <= 0;
            tri_num = 0;
            total_count <= 0;
        end
        else begin
            case(send_state)
                IDLE_S: begin
                    $display("triangles: [%d] addr: [%d]",tri_num, addr);
                    if (total_count < tri_num && !stall_in) begin
                        master_address <= addr;
                        master_read <= 1;
                        addr <= addr + 4;
                        total_count <= total_count + 1;
                        s_count <= s_count + 1;
                        send_state <= SEND;
                    end
                    if (tri_num == 0 && fetch_enable) begin
                        master_address <= addr_in;
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

    logic [31:0] vertex_out_buf[14:0];
    logic [3:0] r_count;
    int output_count;
    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            rec_state <= IDLE_R;
            output_valid <= 0;
            r_count <= 0;
            output_count <= 0;
        end
        else begin
            case (rec_state)
                IDLE_R: begin
                    output_valid <= 0;
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
                            vertex_out[13:0] <= vertex_out_buf[13:0];
                            vertex_out[r_count] <= master_readdata;
                            output_valid <= 1;
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
