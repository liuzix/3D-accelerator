module rasterizer (
    input clock,
    input reset,
    input [31:0] x1,
    input [31:0] y1,
    input [31:0] z1,
    input [31:0] x2,
    input [31:0] y2,
    input [31:0] z2,
    input [31:0] x3,
    input [31:0] y3,
    input [31:0] z3,
    input [23:0] color1, //RGB for v1 = (x1, y1)
    input [23:0] color2, //RGB for v2 = (x2, y2)
    input [23:0] color3, //RGB for v3 = (x3, y3)
    input [25:0] addr_in, //frame buffer base 
    input in_data_valid,

    input done_in,//
    input stall_in,//
    output [25:0] addr_out,
    output [23:0] color_out,
    output [31:0] depth_out,
    output fetch_enable,
    output output_valid,
    output stall_out,//
    output done_out//
);

    logic [31:0] cur_x;
    logic [31:0] cur_y;
    logic e12, e23, e31;
    logic is_inside;

    //640 x 480
    
    logic [31:0] minX;
    logic [31:0] minY;
    logic [31:0] maxX;
    logic [31:0] maxY;
    
    //fixed point multiplication
    function logic [32:0] fp_m(
        input logic [32:0] a,
        input logic [32:0] b
    );
        logic [63:0] tmp_a;
        logic [63:0] tmp_b;
        tmp_a[63:33] <= 0;
        tmp_a[32:0] <= a;
        tmp_b[63:33] <= 0;
        tmp_b[32:0] <= b;
        fp_m <= (tmp_a * tmp_b) >> 16;
    endfunction 

    //fixed point division
    function logic [32:0] fp_d(
        input logic [32:0] a,
        input logic [32:0] b
    );
        logic [63:0] tmp_a;
        logic [63:0] tmp_b;
        tmp_a[63:33] <= 0;
        tmp_a[32:0] <= a;
        tmp_b[63:33] <= 0;
        tmp_b[32:0] <= b;
        fp_d <= (tmp_a * (1 << 16)) / tmp_b;
    endfunction 

    always_comb begin
        if (x1 < x2) begin
            maxX <= x2;
            minX <= x1;
        end else begin
            maxX <= x1;
            minX <= x2;
        end

        if (minX > x3)
            minX <= x3;

        if (maxX < x3)
            maxX <= x3;

        cur_x = minX;
    end
        

    always_comb begin
        if (y1 < y2) begin
            maxY <= y2;
            minY <= y1;
        end else begin
            maxY <= y1;
            minY <= y2;
        end

        if (minY > y3)
            minY <= y3;

        if (maxY < y3)
            maxY <= y3;

        cur_y = minY;
    end
    
    logic [31:0] w1;
    logic [31:0] w2;
    logic [31:0] w3;
    logic [31:0] w1_tmp;
    logic [31:0] w2_tmp;
    logic [31:0] denom;
    logic [23:0] cur_color;
    logic [31:0] cur_depth;

    logic [25:0] tmp_addr_out;
    logic [23:0] tmp_color_out;

    //color interpolation using Barycentric Coordinates
    always_ff @(posedge clock or negedge reset) begin
        w1_tmp <= (y2 - y3) * (cur_x - x3) + (x3 - x2) * (cur_y - y3); 
        w2_tmp <= (y3 - y1) * (cur_x - x3) + (x1 - x3) * (cur_y - y3);
        denom <= (y2 - y3) * (x1 - x3) + (x3 - x2) * (y1 - y3);
        w1 = w1_tmp / denom;
        w2 = w1_tmp / denom;
        w3 = 1 - w1 - w2;
        cur_color = fp_m(w1, color1) + fp_m(w2, color2) + fp_m(w3, color3);
        cur_depth = fp_m(w1, z1) + fp_m(w2, z2) + fp_m(w3, z3);
    end 


    always_ff @(posedge clock or negedge reset) begin
        if (reset) begin 
            cur_x = minX;
            cur_y = minY;
            fetch_enable <= 0;
            output_valid <= 0;
            done_out <= 0;
            stall_out = 0;
        end 
        
        stall_out = 1;
        
        if (in_data_valid) begin
            e12 <= ((cur_x - x1) * (y2 - y1) - (cur_y - y1) * (x2 - x1)) >= 0;
            e23 <= ((cur_x - x2) * (y3 - y2) - (cur_y - y2) * (x3 - x2)) >= 0; 
            e31 <= ((cur_x - x3) * (y1 - y3) - (cur_y - y3) * (x1 - x3)) >= 0;

            is_inside = e12 & e23 & e31;
    
            if (is_inside) begin
                output_valid <= 1;
                tmp_addr_out <= addr_in + ((cur_y - 1) * 640 + cur_x);
                tmp_color_out <= cur_color;
            end else begin
                output_valid <= 0;
            end

            cur_x = cur_x + 1;
    
            if (cur_x > maxX) begin
                cur_x = minX;
                cur_y = cur_y + 1;
            end

            if (cur_y > maxY) begin
                fetch_enable <= 1;
                done_out <= done_in;
                stall_out = 0;
            end

            if (!output_valid) begin
                addr_out <= tmp_addr_out;
                color_out <= tmp_color_out;
                depth_out <= cur_depth;
            end else begin
                if (!stall_in) begin
                    addr_out <= tmp_addr_out;
                    color_out <= tmp_color_out;
                    depth_out <= cur_depth;
                end
            end
        end
    end

endmodule

