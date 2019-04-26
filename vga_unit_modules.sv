module vga_master (
    input clk,
    input reset,
    input pixel_read,
    input [25:0] base,
    input [25:0] cur_vga_addr,
    input [31:0] bus_data, //data returned by bus
    input master_readdatavalid,
    input master_waitrequest,
    output [25:0] master_address,
    output master_read,
    output [31:0] pixel_data,
    output pixel_valid
);

    reg [25:0] cur_addr;

    reg wr;
    reg rd;
    reg [25:0] din;
    wire [25:0] dout;

    reg [25:0] up_addr;
    reg [25:0] up_addr_next;
    reg [25:0] down_addr;
    reg [25:0] down_addr_next;
    reg addr_invalid;

    logic [31:0] pixel_buffer[32];
    logic [3:0] pixel_rd_ptr;
    logic [3:0] pixel_wr_ptr;
    logic [4:0] pixel_in_progress;
    logic [4:0] pixel_in_progress_next;
    assign rd = master_readdatavalid;

    //fifo
    logic full;
    logic empty;
    logic almost_empty;
    logic almost_full;

    fifo #(.DBITS(26)) buffer(
        .clk(clk),
        .reset(reset),
        .wr(wr),
        .rd(rd),
        .din(din),
        .*);

    reg sync;
    logic [25:0] next_cur, offset8_cur_addr;
    assign next_cur = cur_addr - base + 8;
    always_comb begin
        if (next_cur > 26'H258000) offset8_cur_addr = next_cur - 26'H258000 + base;
        else offset8_cur_addr = next_cur + base;
    end

    logic [25:0] next_vga, offset8_vga_addr;
    assign next_vga = cur_vga_addr - base + 8;
    always_comb begin
        if (next_vga > 26'H258000) offset8_vga_addr = next_vga - 26'H258000 + base;
        else offset8_vga_addr = next_vga + base;
    end

    logic [25:0] next_vga128, offset128_vga_addr;
    assign next_vga128 = cur_vga_addr - base + 128;
    always_comb begin
        if (next_vga128 > 26'H258000) offset128_vga_addr = next_vga128 - 26'H258000 + base;
        else offset128_vga_addr = next_vga128 + base;
    end

    logic [25:0] next_vga120, offset120_vga_addr;
    assign next_vga120 = cur_vga_addr - base + 120;
    always_comb begin
        if (next_vga120 > 26'H258000) offset120_vga_addr = next_vga120 - 26'H258000 + base;
        else offset120_vga_addr = next_vga120 + base;
    end

    logic [25:0] next_dout, offset8_dout;
    assign next_dout = dout - base + 8;
    always_comb begin
        if (next_dout > 26'H258000) offset8_dout = next_dout - 26'H258000 + base;
        else offset8_dout = next_dout + base;
    end

    function logic [25:0] addr_offset_add;
        input logic [25:0] first;
        input logic [25:0] second;

        return ((first - base + second) % 26'H258000) + base;
    endfunction

    function bit addr_in_range;
        input logic [25:0] addr;
        input logic [25:0] up;
        input logic [25:0] down;

        if (up > down) begin
            return up > addr && addr >= down;
        end
        else if (up < down) begin
            return addr >= down || addr < up;
        end
        else
            return 0;
    endfunction

    function bit addr_lt;
        input logic [25:0] first;
        input logic [25:0] second;

        if (first < second) return 1;
        else if ((first - base) + 32 * 8 > (second - base) + 26'H258000) return 1;
        else return 0;
    endfunction

    always_ff @(posedge clk or negedge reset)
        begin
            if (!reset) begin
                cur_addr <= cur_vga_addr + 128;
                pixel_in_progress <= 0;
                pixel_in_progress_next = 0;
                pixel_valid <= 0;
                up_addr <= 0;
                down_addr <= 0;
                addr_invalid <= 1;
                master_read <= 0;
            end
            else begin
                $display("vga_master: -------------------------");
                $display("vga_master: up_addr = %d, down_addr = %d", up_addr, down_addr);
                pixel_in_progress_next = pixel_in_progress;
                up_addr_next = up_addr;
                down_addr_next = down_addr;
                sync = 0;

                if (pixel_in_progress == 16)
                    $display("vga_master: pixel buffer full");
                if (master_waitrequest)
                    $display("vga_master: sdram asks us to wait");

                if (((master_read && !master_waitrequest) || !master_read) && pixel_in_progress < 16) begin
                    $display("vga_master: sending request %d", offset8_cur_addr);
                    wr <= 1;
                    din <= offset8_cur_addr;
                    master_read <= 1;
                    master_address <= offset8_cur_addr;
                    cur_addr <= offset8_cur_addr;
                    pixel_in_progress_next = pixel_in_progress_next + 1;
                end
                else begin
                    wr <= 0;
                    master_address <= cur_addr;
                    if (!master_waitrequest)
                        master_read <= 0;
                end

                if (pixel_read) begin
                    if (addr_in_range(cur_vga_addr, up_addr, down_addr)) begin
                        pixel_in_progress_next = pixel_in_progress_next - 1;
                        pixel_data <= pixel_buffer[(cur_vga_addr / 8) % 32];
                        $display("write pixel succeed");
                        pixel_valid <= 1;
                    end
                    else begin
                        pixel_valid <= 0;
                    end

                    $display("vga_master: pixel_read cur_vga_addr = %d", cur_vga_addr);

                    if (!addr_lt(cur_vga_addr,down_addr))
                        down_addr_next = offset8_vga_addr;

                    if (!addr_lt(cur_vga_addr, up_addr) && !addr_invalid) begin
                        sync = 1;
                        $display("vga_master: syncing!");
                        down_addr_next = offset128_vga_addr;
                        pixel_in_progress_next = 0;
                        up_addr_next = down_addr_next;
                        cur_addr <= offset120_vga_addr;
                    end

                end

                if (master_readdatavalid && !sync) begin
                    $display("vga_master: pixel data at %d: %d", dout, bus_data);
                    if (empty)
                        $fatal("fifo empty");

                    if (addr_invalid) begin
                        pixel_buffer[(dout / 8) % 32] <= bus_data;
                        up_addr_next = offset8_dout;
                        down_addr_next = up_addr_next;
                        addr_invalid <= 0;
                    end else
                        if (dout == up_addr) begin
                            pixel_buffer[(up_addr / 8) % 32] <= bus_data;
                            up_addr_next = offset8_dout;
                        end
                end

                pixel_in_progress <= pixel_in_progress_next;
                up_addr <= up_addr_next;
                down_addr <= down_addr_next;
            end
        end
endmodule



module vga_buffer (
    input logic clk,
    input logic reset,
    input [31:0] pixel_data,
    input logic pixel_valid,
    input [25:0] frame_buffer_ptr,
    output pixel_read,
    output [25:0] cur_vga_addr,
    output logic [7:0] VGA_R, VGA_G, VGA_B,
    output logic       VGA_CLK, VGA_HS, VGA_VS,
    VGA_BLANK_n,
    output logic       VGA_SYNC_n
);

    logic [10:0]    hcount;
    logic [9:0]     vcount;

    logic clk50;
	 logic clk100;
	 logic clk100_c;
    logic clk50_c;

    wire VGA_CLK_PRE;
    //assign VGA_CLK = VGA_CLK_PRE;
    reg [3:0] vga_clk_high_count;

    always_ff @(posedge clk or negedge reset)
        if (!reset) begin
            clk50_c <= 0;
				clk100_c <= 0;
		  end
        else begin
            clk100_c <= clk100_c + 1;
				clk50_c <= clk50_c + 1;
		  end


    //assign pixel_read = (clk_counter == 4);
    assign clk100        = (clk100_c == 0);
	 assign clk50         = (clk50_c == 0);
    assign cur_vga_addr = frame_buffer_ptr + (hcount[10:1] + 640 * vcount) * 8;

    vga_counters counters(.clk50(clk50), .reset(reset),.VGA_CLK(VGA_CLK_PRE), .clk100(clk), .clk(clk), .*);

    typedef enum { R_OUTPUT, R_WAIT, R_CLOCK, R_IDLE } read_state_t;
    read_state_t read_state;

    always_ff @(posedge clk or negedge reset)
        if (!reset) begin
            {VGA_R, VGA_G, VGA_B} <= {8'hFF, 8'h0, 8'hFF};
            pixel_read <= 0;
            vga_clk_high_count <= 0;
            read_state <= R_IDLE;
        end else begin
            case (read_state)
                R_IDLE: begin
                    if (VGA_CLK_PRE) begin
                        $display("vga_buffer: hcount = %d", hcount[10:1]);
                        if (hcount[10:1] < 640 && vcount < 480)
                            pixel_read <= 1;
                        read_state <= R_WAIT;
                    end
                end

                R_WAIT: begin
	            VGA_CLK <= 0;
                    read_state <= R_OUTPUT;
                    pixel_read <= 0;
                end

                R_OUTPUT: begin
                    if (pixel_valid)
                       {VGA_B, VGA_G, VGA_R} <= {pixel_data[23:16], pixel_data[15:8], pixel_data[7:0]};
			//{VGA_B, VGA_G, VGA_R} <= {8'hFF, 8'h0, 8'h0};
                    else begin
                        {VGA_B, VGA_G, VGA_R} <= {8'hFF, 8'hFF, 8'hFF};
                        $display("vga_buffer: no pixel");
                    end
                    //VGA_CLK <= 1;
                    read_state <= R_CLOCK;
                end

                R_CLOCK: begin
               	    VGA_CLK <= 1;
                    read_state <= R_IDLE;
                end
            endcase
        end
endmodule




module vga_counters (
    input logic         clk, clk50, reset, clk100,
    output logic [10:0] hcount,  // hcount[10:1] is pixel column
    output logic [9:0]  vcount,  // vcount[9:0] is pixel row
    output logic        VGA_CLK, VGA_HS, VGA_VS, VGA_BLANK_n, VGA_SYNC_n
);

/*
    * 640 X 480 VGA timing for a 50 MHz clock: one pixel every other cycle
    *
    * HCOUNT 1599 0             1279       1599 0
    *             _______________              ________
    * ___________|    Video      |____________|  Video
    *
    *
    * |SYNC| BP |<-- HACTIVE -->|FP|SYNC| BP |<-- HACTIVE
    *       _______________________      _____________
    * |____|       VGA_HS          |____|
    */
    // Parameters for hcount
    parameter HACTIVE      = 11'd 1280,
        HFRONT_PORCH = 11'd 32,
        HSYNC        = 11'd 192,
        HBACK_PORCH  = 11'd 96,
        HTOTAL       = HACTIVE + HFRONT_PORCH + HSYNC +
        HBACK_PORCH; // 1600

    // Parameters for vcount
    parameter VACTIVE      = 10'd 480,
        VFRONT_PORCH = 10'd 10,
        VSYNC        = 10'd 2,
        VBACK_PORCH  = 10'd 33,
        VTOTAL       = VACTIVE + VFRONT_PORCH + VSYNC +
        VBACK_PORCH; // 525

    logic endOfLine;

    always_ff @(posedge clk or negedge reset) begin
        if (!reset)          hcount <= 0;
        else if (clk50 & clk100) begin
            if (endOfLine) hcount <= 0;
            else hcount <= hcount + 11'd 1;
        end
    end

    assign endOfLine = hcount == HTOTAL - 1;

    logic endOfField;

    always_ff @(posedge clk or negedge reset)
        if (!reset)          vcount <= 0;
        else if (endOfLine & clk50 & clk100) begin
            if (endOfField)   vcount <= 0;
            else              vcount <= vcount + 10'd 1;
        end

    assign endOfField = vcount == VTOTAL - 1;

    // Horizontal sync: from 0x520 to 0x5DF (0x57F)
    // 101 0010 0000 to 101 1101 1111
    assign VGA_HS = !( (hcount[10:8] == 3'b101) &
        !(hcount[7:5] == 3'b111));
    assign VGA_VS = !( vcount[9:1] == (VACTIVE + VFRONT_PORCH) / 2);

    assign VGA_SYNC_n = 1'b0; // For putting sync on the green signal; unused

    // Horizontal active: 0 to 1279     Vertical active: 0 to 479
    // 101 0000 0000  1280          01 1110 0000  480
    // 110 0011 1111  1599          10 0000 1100  524
    assign VGA_BLANK_n = !( hcount[10] & (hcount[9] | hcount[8]) ) &
        !( vcount[9] | (vcount[8:5] == 4'b1111) );

    /* VGA_CLK is 25 MHz
    *             __    __    __
    * clk50    __|  |__|  |__|
    *
    *             _____       __
    * hcount[0]__|     |_____|
    */
    assign VGA_CLK = hcount[0]; // 25 MHz clock: rising edge sensitive

endmodule
