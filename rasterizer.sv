module rasterizer (
    input clock,
    input reset,
    input [31:0] x1,
    input [31:0] y1,
    input [31:0] x2,
    input [31:0] y2,
    input [31:0] x3,
    input [31:0] y3,
    input [23:0] color1, //RGB for v1 = (x1, y1)
    input [23:0] color2, //RGB for v2 = (x2, y2)
    input [23:0] color3, //RGB for v3 = (x3, y3)
    input [25:0] addr_in, //frame buffer base 
    input ready,
    output [25:0] addr_out,
    output [31:0] color_out
    output fetch_enable,
    output done
);

    logic [31:0] cur_pixel_x;
    logic [31:0] cur_pixel_y;
    logic e12, e23, e31;
    logic is_inside;

    //640 x 480
    
    logic [31:0] minX;
    logic [31:0] minY;
    logic [31:0] maxX;
    logic [31:0] maxY;
    
    //bounding box
    logic [31:0] v1_x;
    logic [31:0] v1_y;
    logic [31:0] v2_x;
    logic [31:0] v2_y;
    logic [31:0] v3_x;
    logic [31:0] v3_y;
    logic [31:0] v4_x;
    logic [31:0] v4_y;

    logic [24:0] v1_color;
    logic [24:0] v2_color;
    logic [24:0] v3_color;
    logic [24:0] v4_color;

    logic [31:0] w1;
    logic [31:0] w2;
    logic [31:0] w3;

    //fixed point multiplication
    function logic [32:0] fp_mult(
        input logic [32:0] a,
        input logic [32:0] b
    );
        logic [63:0] tmp_a;
        logic [63:0] tmp_b;
        tmp_a[63:33] <= 0;
        tmp_a[32:0] <= a;
        tmp_b[63:33] <= 0;
        tmp_b[32:0] <= b;
        fp_mult <= (tmp_a * tmp_b) >> 16;
    endfunction 

    //fixed point division
    function logic [32:0] fp_divide(
        input logic [32:0] a,
        input logic [32:0] b
    );
        logic [63:0] tmp_a;
        logic [63:0] tmp_b;
        tmp_a[63:33] <= 0;
        tmp_a[32:0] <= a;
        tmp_b[63:33] <= 0;
        tmp_b[32:0] <= b;
        fp_divide <= (tmp_a * (1 << 16)) / tmp_b;
    endfunction 


    always_comb begin
        v1_x <= minX;
        v1_y <= minY;
        v2_x <= minX;
        v2_y <= maxY;
        v3_x <= maxX;
        v3_y <= minY;
        v4_x <= maxX;
        v4_y <= maxY;

        //w1 <= ((y2-y3)*(v1_x-x3)+(x3-x2)*(v1_y-y3))/((y2-y3)*(x1-x3))


    end

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

        cur_pixel_x = minX;
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

        cur_pixel_y = minY;
    end

    
    
    always_comb begin 
        if (cur_pixel_y < ((minY + maxY) << 1))
            color_out <= color1;
        
        if (cur_pixel_y >= ((minY + maxY) << 1) & cur_pixel_x < ((minX + maxX) << 1))
            color_out <= color2;

        if (cur_pixel_y >= ((minY + maxY) << 1) & cur_pixel_x > ((minX + maxX) << 1))
            color_out <= color3;
    end


    always_ff @(posedge clock or negedge reset) begin
        if (reset) begin 
            cur_pixel_x <= minX;
            cur_pixel_y <= minY;
            done <= 0;
        end 
        
        e12 <= ((cur_pixel_x - x1) * (y2 - y1) - (cur_pixel_y - y1) * (x2 - x1)) >= 0;
        e23 <= ((cur_pixel_x - x2) * (y3 - y2) - (cur_pixel_y - y2) * (x3 - x2)) >= 0; 
        e31 <= ((cur_pixel_x - x3) * (y1 - y3) - (cur_pixel_y - y3) * (x1 - x3)) >= 0;

        is_inside = e12 & e23 & e31;
    
        if (is_inside)
            addr_out = addr_in + ((cur_pixel_y - 1) * 640 + cur_pixel_x);

        cur_pixel_x = cur_pixel_x + 1;
    
        if (cur_pixel_x > maxX) begin
            cur_pixel_x <= minX;
            cur_pixel_y <= cur_pixel_y + 1;
        end

        if (cur_pixel_y > maxY) begin
            fetch_enable <= 1;
            done <= 1;
        end
    end

endmodule;
