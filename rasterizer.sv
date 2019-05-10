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
    function logic signed [31:0] fp_m(
        input logic signed [31:0] a,
        input logic signed [31:0] b
    );
        logic signed [63:0] tmp_a;
        logic signed [63:0] tmp_b;
        tmp_a[63:32] <= 0;
        tmp_a[31:0] <= a;
        tmp_b[63:32] <= 0;
        tmp_b[31:0] <= b;
        fp_m <= (tmp_a * tmp_b) >> 16;
    endfunction 

    //fixed point division
    function logic signed [31:0] fp_d(
        input logic signed [31:0] a,
        input logic signed [31:0] b
    );
        logic signed [63:0] tmp_a;
        logic signed [63:0] tmp_b;
        tmp_a[63:32] <= 0;
        tmp_a[31:0] <= a;
        tmp_b[63:32] <= 0;
        tmp_b[31:0] <= b;
        fp_d <= (tmp_a * (1 << 16)) / tmp_b;
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

    always_comb begin
        if (x1 < x2) begin
            maxX = x2;
            minX = x1;
        end else begin
            maxX = x1;
            minX = x2;
        end

        if (minX > x3)
            minX = x3;

        if (maxX < x3)
            maxX = x3;

        cur_x = minX;
    end
        

    always_comb begin
        if (y1 < y2) begin
            maxY = y2;
            minY = y1;
        end else begin
            maxY = y1;
            minY = y2;
        end

        if (minY > y3)
            minY = y3;

        if (maxY < y3)
            maxY = y3;

        cur_y = minY;
    end
    
    logic signed [31:0] w1;
    logic signed [31:0] w2;
    logic signed [31:0] w3;
    logic signed [31:0] w1_tmp;
    logic signed [31:0] w2_tmp;
    logic signed [31:0] denom;
    logic [23:0] cur_color;
    logic signed[31:0] cur_depth;

    logic [25:0] tmp_addr_out;
    logic [23:0] tmp_color_out;

    //color interpolation using Barycentric Coordinates
    always_ff @(posedge clock or negedge reset) begin
        w1_tmp <= fp_m(y2 - y3, cur_x - x3) + fp_m(x3 - x2, cur_y - y3); 
        w2_tmp <= fp_m(y3 - y1, cur_x - x3) + fp_m(x1 - x3, cur_y - y3);
        denom <= fp_m(y2 - y3, x1 - x3) + fp_m(x3 - x2, y1 - y3);
        w1 = fp_d(w1_tmp, denom);
        w2 = fp_d(w1_tmp, denom);
        w3 = 1 - w1 - w2;
        cur_color[7:0] = fp_to_byte(fp_m(w1, byte_to_fp(color1[7:0])) + fp_m(w2, byte_to_fp(color2[7:0])) + fp_m(w3, byte_to_fp(color3[7:0])));
        cur_color[15:8] = fp_to_byte(fp_m(w1, byte_to_fp(color1[15:8])) + fp_m(w2, byte_to_fp(color2[15:8])) + fp_m(w3, byte_to_fp(color3[15:8])));
        cur_color[23:16] = fp_to_byte(fp_m(w1, byte_to_fp(color1[23:16])) + fp_m(w2, byte_to_fp(color2[23:16])) + fp_m(w3, byte_to_fp(color3[23:16])));
        cur_depth = fp_m(w1, z1) + fp_m(w2, z2) + fp_m(w3, z3);
    end 


    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin 
            cur_x = minX;
            cur_y = minY;
            output_valid <= 0;
            done_out <= 0;
            stall_out = 0;
        end else begin
        
            stall_out = 1;
            
            $display("rasterizer: in_data_valid = %d", in_data_valid);
            if (in_data_valid) begin
                e12 <= (signed'(cur_x - x1) * signed'(y2 - y1) - signed'(cur_y - y1) * signed'(x2 - x1)) >= 0;
                e23 <= (signed'(cur_x - x2) * signed'(y3 - y2) - signed'(cur_y - y2) * signed'(x3 - x2)) >= 0; 
                e31 <= (signed'(cur_x - x3) * signed'(y1 - y3) - signed'(cur_y - y3) * signed'(x1 - x3)) >= 0;

                is_inside = e12 & e23 & e31;
        
                if (is_inside) begin
                    output_valid <= 1;
                    tmp_addr_out <= addr_in + (fp_m(cur_y - (1 << 16), (640 << 16) + cur_x) >> 16);
                    tmp_color_out <= cur_color;
                end else begin
                    output_valid <= 0;
                end

                cur_x = cur_x + (1 << 16);
        
                if (cur_x > maxX) begin
                    cur_x = minX;
                    cur_y = cur_y + (1 << 16);
                end

                if (cur_y > maxY) begin
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
    end

endmodule

