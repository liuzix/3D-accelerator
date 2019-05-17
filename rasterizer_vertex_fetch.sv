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
    int tri_num ;
    int input_count;

    assign master_byteenable = 4'b1111;

    assign done_out = (tri_num != 0) && (ccounter == tri_num);

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

    logic fetch_tri;
    logic recv_valid;
    int fifo_size = 2**FIFO_SIZE;
    int fifo_counter;
    logic already_pop;

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

    assign vertex_out = '{data_out[479:448],data_out[447:416],
        data_out[415:384],data_out[383:352],data_out[351:320],
        data_out[319:288],data_out[287:256],data_out[255:224],
        data_out[223:192],data_out[191:160],data_out[159:128],
        data_out[127:96],data_out[95:64],data_out[63:32],data_out[31:0]};

    int ccounter;
    //send vertices data from fifo to vertex_cal; receive vertices data from bus
    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            send_state <= IDLE_S;
            master_read <= 0;
            s_count <= 0;
            fifo_counter = 0;
            already_pop <= 0;
            input_count <= 0;
            fetch_tri <= 0;
            ccounter <= 0;
            output_valid <= 0;
        end
        else begin
            //deal with fifo counter

            case(send_state)
                IDLE_S: begin
                    if (input_count < tri_num && fifo_counter < fifo_size) begin
                        $display("vertex_fetch: read addr = %d", addr);
                        master_address <= addr;
                        master_read <= 1;
                        addr <= addr + 4;
                        input_count <= input_count + 1;
                        fifo_counter = fifo_counter + 1;
                        s_count <= s_count + 1;
                        send_state <= SEND;
                    end
                    if (tri_num == 0 && fetch_enable && !fetch_tri) begin
                        $display("vertex_fetch: vertex_buffer_base = %d", vertex_buffer_base);
                        master_address <= vertex_buffer_base;
                        master_read <= 1;
                        fetch_tri <= 1;
                        addr <= vertex_buffer_base + 4;
                        send_state <= TRI_SEND;
                    end else if (done_out)
                    fetch_tri <= 0;
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
                        $display("vertex_fetch: tri_num read request sent");
                        master_read <= 0;
                        send_state <= IDLE_S;
                    end else begin
                        master_address <= addr - 4;
                        master_read <= 1;
                    end
                end
                default: begin end
            endcase
            if (recv_valid && !full) begin
                data_in <= {vertex_out_buf[14],vertex_out_buf[13],vertex_out_buf[12],vertex_out_buf[11],
                    vertex_out_buf[10],vertex_out_buf[9],vertex_out_buf[8],vertex_out_buf[7],
                    vertex_out_buf[6],vertex_out_buf[5],vertex_out_buf[4],vertex_out_buf[3],
                    vertex_out_buf[2],vertex_out_buf[1],vertex_out_buf[0]};
                $display("vertex_fetch: triangle:");
                $display("vertex_fetch: [%x], [%x], [%x]", vertex_out_buf[0], vertex_out_buf[1], vertex_out_buf[2]);
                $display("vertex_fetch: [%x], [%x], [%x]", vertex_out_buf[4], vertex_out_buf[5], vertex_out_buf[6]);
                $display("vertex_fetch: [%x], [%x], [%x]", vertex_out_buf[8], vertex_out_buf[9], vertex_out_buf[10]);
                $display("vertex_fetch: =====");
                wrreq <= 1;
            end else begin
                wrreq <= 0;
                data_in <= 'hff;
            end

            if (!stall_in && !empty && !already_pop) begin
                rdreq <= 1;
                fifo_counter = fifo_counter - 1;
                ccounter <= ccounter + 1;
                $display("ccalc:[%d]",ccounter);
                output_valid <= 1;
                already_pop <= 1;
            end else if (already_pop) begin
                rdreq <= 0;
                output_valid <= 0;
                already_pop <= 0;
            end else begin
                rdreq <= 0;
                if (!empty)
                    output_valid <= 1;
                if (empty)
                    output_valid <= 0;
            end
        end
    end

    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            rec_state <= IDLE_R;
            recv_valid <= 0;
            r_count <= 0;
            tri_num <= 0;//number of total vertices
            output_count <= 0;
        end
        else begin
            case (rec_state)
                IDLE_R: begin//fetch total number
                    recv_valid <= 0;
                    if (master_readdatavalid && tri_num != 0) begin
                        vertex_out_buf[r_count] <= master_readdata;
                        $display("vertex_fetch: data = %d", master_readdata >> 16);
                        r_count <= r_count + 1;
                        rec_state <= FETCH;
                    end

                    if (master_readdatavalid && tri_num == 0) begin
                        $display("vertex_fetch: tri_num = %d", master_readdata);
                        tri_num <= master_readdata;
                    end
                    else if (done_out)
                        tri_num <= 0;
                end
                FETCH: begin//fetch vertices
                    if (master_readdatavalid) begin
                        if (r_count == 14) begin
                            r_count <= 0;
                            vertex_out_buf[r_count] <= master_readdata;
                            $display("vertex_fetch: data = %d", master_readdata >> 16);
                            recv_valid <= 1;
                            output_count <= output_count + 1;
                            rec_state <= IDLE_R;
                        end else begin
                            vertex_out_buf[r_count] <= master_readdata;
                            $display("vertex_fetch: data = %d", master_readdata >> 16);
                            r_count <= r_count + 1;
                        end
                    end
                end
                default: begin end
            endcase
        end
    end
endmodule
