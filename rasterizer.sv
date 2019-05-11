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
    input [23:0] color1, //RGB for v1 = (x1_t, y1_t)
    input [23:0] color2, //RGB for v2 = (x2_t, y2_t)
    input [23:0] color3, //RGB for v3 = (x3_t, y3_t)
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

    reg signed [31:0] x1_t;
    reg signed [31:0] y1_t;
    reg signed [31:0] z1_t;
    reg signed [31:0] x2_t;
    reg signed [31:0] y2_t;
    reg signed [31:0] z2_t;
    reg signed [31:0] x3_t;
    reg signed [31:0] y3_t;
    reg signed [31:0] z3_t;
    reg [23:0] color1_t;
    reg [23:0] color2_t;
    reg [23:0] color3_t;
    reg [25:0] addr_in_t; 

    logic [1:0] counter;


    logic signed [31:0] cur_x;
    logic signed [31:0] cur_y;
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
        fp_m = (64'(a) * 64'(b)) >>> 16;
    endfunction 
    //fixed point division
    function logic signed [31:0] fp_d(
        input logic signed [31:0] a,
        input logic signed [31:0] b
    );
        fp_d = (64'(a) << 16) / 64'(b);
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
        if (x1_t < x2_t) begin
            maxX = x2_t;
            minX = x1_t;
        end else begin
            maxX = x1_t;
            minX = x2_t;
        end

        if (minX > x3_t)
            minX = x3_t;

        if (maxX < x3_t)
            maxX = x3_t;
    end
        

    always_comb begin
        if (y1_t < y2_t) begin
            maxY = y2_t;
            minY = y1_t;
        end else begin
            maxY = y1_t;
            minY = y2_t;
        end

        if (minY > y3_t)
            minY = y3_t;

        if (maxY < y3_t)
            maxY = y3_t;
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
    always_comb begin
        w1_tmp = fp_m(y2_t - y3_t, cur_x - x3_t) + fp_m(x3_t - x2_t, cur_y - y3_t); 
        w2_tmp = fp_m(y3_t - y1_t, cur_x - x3_t) + fp_m(x1_t - x3_t, cur_y - y3_t);
        denom = fp_m(y2_t - y3_t, x1_t - x3_t) + fp_m(x3_t - x2_t, y1_t - y3_t);
        w1 = fp_d(w1_tmp, denom);
        w2 = fp_d(w1_tmp, denom);
        w3 = 1 - w1 - w2;
        //cur_color[7:0] = fp_to_byte(fp_m(w1, byte_to_fp(color1_t[7:0])) + fp_m(w2, byte_to_fp(color2_t[7:0])) + fp_m(w3, byte_to_fp(color3_t[7:0])));
        //cur_color[15:8] = fp_to_byte(fp_m(w1, byte_to_fp(color1_t[15:8])) + fp_m(w2, byte_to_fp(color2_t[15:8])) + fp_m(w3, byte_to_fp(color3_t[15:8])));
        //cur_color[23:16] = fp_to_byte(fp_m(w1, byte_to_fp(color1_t[23:16])) + fp_m(w2, byte_to_fp(color2_t[23:16])) + fp_m(w3, byte_to_fp(color3_t[23:16])));
        cur_color = -1;
        cur_depth = fp_m(w1, z1_t) + fp_m(w2, z2_t) + fp_m(w3, z3_t);
    end 


    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin 
            cur_x = 0;
            cur_y = 0;
            output_valid <= 0;
            done_out <= 0;
            stall_out = 1;
            counter = 0;
        end else begin
            if (counter == 0) begin
                if (in_data_valid) begin
                    x1_t <= x1;
                    y1_t <= y1;
                    z1_t <= z1;
                    x2_t <= x2;
                    y2_t <= y2;
                    z2_t <= z2;
                    x3_t <= x3;
                    y3_t <= y3;
                    z3_t <= z3;
                    color1_t <= color1;
                    color2_t <= color2;
                    color3_t <= color3;
                    addr_in_t <= addr_in;
                    stall_out = 0;
                    counter = counter + 1;
                    
                    $display("rasterizer: triangle = (%d, %d, %d), (%d, %d, %d), (%d, %d, %d)",
                        $signed(x1) >>> 16, $signed(y1) >>> 16, $signed(z1) >>> 16,
                        $signed(x2) >>> 16, $signed(y2) >>> 16, $signed(z2) >>> 16,
                        $signed(x3) >>> 16, $signed(y3) >>> 16, $signed(z3) >>> 16);
                end
                output_valid <= 0;
            end else begin
                if (counter == 1) begin
                    cur_x = minX;
                    cur_y = minY;
                    counter = counter + 1;
                end


                $display("rasterizer: cur_point = (%d, %d)", cur_x >> 16, cur_y >> 16);
                stall_out = 1;
                e12 = (fp_m(signed'(cur_x - x1_t),signed'(y2_t - y1_t)) - fp_m(signed'(cur_y - y1_t), signed'(x2_t - x1_t))) >= 0;
                e23 = (fp_m(signed'(cur_x - x2_t),signed'(y3_t - y2_t)) - fp_m(signed'(cur_y - y2_t), signed'(x3_t - x2_t))) >= 0; 
                e31 = (fp_m(signed'(cur_x - x3_t),signed'(y1_t - y3_t)) - fp_m(signed'(cur_y - y3_t), signed'(x1_t - x3_t))) >= 0;

                is_inside = e12 & e23 & e31;
    
                if (is_inside) begin
                    $display("rasterizer: w1 = %f, w2 = %f, w3 = %f",
                        $itor(w1) / $itor(1 << 16), $itor(w2) / $itor(1 << 16), $itor(w3) / $itor(1 << 16)); 
                    $display("rasterizer: input color %d, %d, %d", color1_t, color2_t, color3_t);
                    $display("rasterizer: output color %d, %d, %d", cur_color[7:0], cur_color[15:8], cur_color[23:16]);
                    output_valid <= 1;
                    tmp_addr_out = addr_in_t + ((fp_m((640 << 16), cur_y)  + cur_x) >> 16) << 3;
                    
                    if (!output_valid) begin
                        addr_out <= tmp_addr_out;
                        color_out <= cur_color;
                        depth_out <= cur_depth;

                    end else begin
                        if (!stall_in) begin
                            addr_out <= tmp_addr_out;
                            color_out <= cur_color;
                            depth_out <= cur_depth;

                            cur_x = cur_x + (1 << 16);
                
                            if (cur_x > maxX) begin
                                cur_x = minX;
                                cur_y = cur_y + (1 << 16);
                            end

                            if (cur_y > maxY) begin
                                done_out <= done_in;
                                counter = 0;
                            end
                        end
                    end
                end else begin
                    output_valid <= 0;
                    cur_x = cur_x + (1 << 16);
        
                    if (cur_x > maxX) begin
                        cur_x = minX;
                        cur_y = cur_y + (1 << 16);
                    end

                    if (cur_y > maxY) begin
                        done_out <= done_in;
                        counter = 0;
                    end
                end


            end
        end
    end

endmodule

