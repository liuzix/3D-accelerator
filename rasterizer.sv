module rasterizer (
    input clock,
    input reset,
    input [31:0] x1,
    input [31:0] y1,
    input [31:0] x2,
    input [31:0] y2,
    input [31:0] x3,
    input [31:0] y3,
    //input [23:0] color1, //RGB for v1 = (x1, y1)
    //input [23:0] color2, //RGB for v2 = (x2, y2)
    //input [23:0] color3, //RGB for v3 = (x3, y3)
    output [25:0] addr_in; //frame buffer base 
    output [25:0] addr_out;
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

    always_comb begin begin
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
        

    always_comb begin begin
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

