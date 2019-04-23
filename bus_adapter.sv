module bus_adapter (
    input clock,
    input reset,
    //connect to upper master
    output slave_readdatavalid,
    output slave_waitrequest,
    input slave_write,//write enable signal
    input slave_read,//read enable signal
    input [31:0] slave_writedata,
    output [31:0] slave_readdata,
    input [25:0] slave_address,
    //connect to sram controller
    //read from sram
    input [15:0] master_readdata,
    input master_readdatavalid,
    input master_waitrequest,
    //to sram
    output [25:0] master_address,
    output master_read,
    output master_write,
    output [1:0] master_byteenable,
    output [15:0]master_writedata,
    output test_output
);
// write to sram
//three states: IDLE, read data, write data,WAIT

    typedef enum logic[2:0] {IDLE_R, READ1, READ2, CHECK1, CHECK2} read_t;
    read_t read_state;

    typedef enum logic[1:0] {IDLE_REC, DONE} rec_t;
    rec_t rec_state;

    typedef enum logic[2:0] {IDLE_W, WRITE1, WRITE2, CHECK_W1, CHECK_W2} write_t;
    write_t write_state;

    assign master_byteenable = 2'b11;

	 logic [25:0] master_address_r;
	 logic [25:0] master_address_w;
	 always_comb begin
		if (read_busy)
			master_address = master_address_r;
		else
		   master_address = master_address_w;
	 end
	 
    
    wire test_output;

    always_comb begin
        if (master_readdatavalid)
            test_output = 1;
        else 
            test_output = 0;
    end

    logic read_busy;
    logic write_busy;

    assign slave_waitrequest = read_busy | write_busy;

    logic[25:0] read_addr_cache;
    read_t prev_state;
    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            read_state <= IDLE_R;
            master_read <= 0;
            read_busy <= 0;
            prev_state <= IDLE_R;
        end
        else begin
            case(read_state)
                IDLE_R: begin
                    if (slave_read) begin
                        read_busy <= 1;
                        if (!master_waitrequest) begin
                            master_address_r <= slave_address;
                            master_read <= 1;
                            read_addr_cache <= slave_address;
                            prev_state <= READ1;
                            read_state <= CHECK1;
                        end else begin
                            master_read <= 0;
                            read_addr_cache <= slave_address;
                            read_state <= READ1;
                        end
                    end else
                        master_read <= 0;
                end
                READ1: begin
                    if (!master_waitrequest) begin
                        master_address_r <= read_addr_cache;
                        master_read <= 1;
                        prev_state <= READ1;
                        read_state <= CHECK1;
                    end else
                        master_read <= 0;
                end
                READ2: begin
                    if (!master_waitrequest) begin
                        master_address_r <= read_addr_cache;
                        master_read <= 1;

                        prev_state <= READ2;
                        read_state <= CHECK2;
                    end else
                        master_read <= 0;
                end            

                CHECK1: begin
                    if (master_waitrequest) begin
                        master_read <= 0;
                        read_state <= prev_state;
                    end else begin
                        master_address_r	<= read_addr_cache + 2;
                        master_read <= 1;
                        read_addr_cache <= read_addr_cache + 2;
                        prev_state <= READ2;
                        read_state <= CHECK2;
                    end
                end
                CHECK2: begin
                    if (master_waitrequest) begin
                        master_read <= 0;
                        read_state <= prev_state;
                    end else begin
                        master_read <= 0;
                        read_busy <= 0;
                        read_state <= IDLE_R;
                    end
                end
                default: begin end
            endcase
        end
    end

    logic[15:0] read_data_cache;
    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            rec_state <= IDLE_REC;
            slave_readdatavalid <= 0;
        end else begin
            case(rec_state)
                IDLE_REC: begin
                    slave_readdatavalid <= 0;
                    if (master_readdatavalid) begin
                        read_data_cache <= master_readdata;
                        rec_state <= DONE;
                    end
                end
                DONE: begin
                    if (master_readdatavalid) begin
                        slave_readdata[31:16] <= master_readdata;
                        slave_readdata[15:0] <= read_data_cache;
                        slave_readdatavalid <= 1;
                        rec_state <= IDLE_REC;
                    end
                end
                default: begin end
            endcase
        end
    end

    logic[31:0] write_data_cache;
    logic[25:0] write_addr_cache;
    write_t prev_state_w;
    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            write_state <= IDLE_W;
            master_write <= 0;
            write_busy <= 0;
            prev_state_w <= IDLE_W;
        end else begin
            case(write_state)
                IDLE_W: begin
                    if (slave_write) begin
                        write_busy <= 1;
                        if (!master_waitrequest) begin
                            master_address_w <= slave_address;
                            master_writedata <= slave_writedata[31:16];
                            master_write <= 1;
                            write_data_cache <= slave_writedata;
                            write_addr_cache <= slave_address;

                            prev_state_w <= WRITE1;
                            write_state <= CHECK_W1;
                        end else begin
                            master_write <= 0;
                            write_data_cache <= slave_writedata;
                            write_addr_cache <= slave_address;
                            write_state <= WRITE1;
                        end
                    end else
                        master_write <= 0;
                end
                WRITE1: begin
                    if (!master_waitrequest) begin
                        master_address_w <= write_addr_cache;
                        master_writedata <= write_data_cache[31:16];
                        master_write <= 1;
                        
                        prev_state_w <= WRITE1;
                        write_state <= CHECK_W1;
                    end else
                        master_write <= 0;
                end
                WRITE2: begin
                    if (!master_waitrequest) begin
                        master_address_w <= write_addr_cache;
                        master_writedata <= slave_writedata[15:0];
                        master_write <= 1;
                        
                        prev_state_w <= WRITE2;
                        write_state <= CHECK_W2;
                    end else
                        master_write <= 0;
                end
                CHECK_W1: begin            

                    if (master_waitrequest) begin
                        master_write <= 0;
                        write_state <= prev_state_w;
                    end else begin
                        master_address_w <= write_addr_cache + 2;
                        master_writedata <= slave_writedata[15:0];
                        master_write <= 1;
                        
                        write_addr_cache <= write_addr_cache + 2;
                        prev_state_w <= WRITE2;
                        write_state <= CHECK_W2;
                    end
                end
                CHECK_W2: begin
                    if (master_waitrequest) begin
                        master_write <= 0;
                        write_state <= prev_state_w;
                    end else begin
                        master_write <= 0;
                        write_busy <= 0;
                        write_state <= IDLE_W;
                    end
                end
                default: begin end
            endcase
        end
    end

endmodule
