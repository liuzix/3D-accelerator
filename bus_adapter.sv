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
    output [15:0]master_writedata
);
// write to sram
//three states: IDLE, read data, write data,WAIT

    typedef enum logic[1:0] {IDLE_R, READ1, READ2} read_t;
    read_t read_state;

    typedef enum logic[1:0] {IDLE_REC, DONE} rec_t;
    rec_t rec_state;

    typedef enum logic[1:0] {IDLE_W, WRITE1, WRITE2} write_t;
    write_t write_state;


    logic read_busy;
    logic write_busy;
    logic[25:0] read_addr_cache;

    assign slave_waitrequest = read_busy | write_busy;

    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            read_state <= IDLE_R;
            master_read <= 0;
            read_busy <= 0;
        end
        else begin
            case(read_state)
                IDLE_R: begin
                    if (slave_read) begin
                        read_busy <= 1;
                        if (!master_waitrequest) begin
                            master_address <= slave_address;
                            master_read <= 1;
                            read_addr_cache <= slave_address + 2;
                            read_state <= READ2;
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
                        master_address <= read_addr_cache;
                        master_read <= 1;
                        read_addr_cache <= read_addr_cache + 2;
                        read_state <= READ2;
                    end else
                        master_read <= 0;
                end
                READ2: begin
                    if (!master_waitrequest) begin
                        master_address <= read_addr_cache;
                        master_read <= 1;

                        read_busy <= 0;
                        read_state <= IDLE_R;
                    end else
                        master_read <= 0;
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
                        slave_readdata[15:0] <= master_readdata;
                        slave_readdata[31:16] <= read_data_cache;
                        slave_readdatavalid <= 1;
                        rec_state <= IDLE_REC;
                    end
                end
                default: begin end
            endcase
        end
    end

endmodule
