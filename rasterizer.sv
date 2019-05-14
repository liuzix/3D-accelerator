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
    //output [23:0] color_out,
    output logic [23:0] color_out_1,
    output logic [23:0] color_out_2,
    output logic [23:0] color_out_3,
    output logic [31:0] w1_out,
    output logic [31:0] w2_out,
    output logic [31:0] w3_out,

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
    logic signed [31:0] e12;
    logic signed [31:0] e23;
    logic signed [31:0] e31;
    logic is_inside;

    //640 x 480
    
    logic [31:0] minX_tmp;
    logic [31:0] minY_tmp;
    logic [31:0] maxX_tmp;
    logic [31:0] maxY_tmp;
    
    reg [31:0] minX;
    reg [31:0] minY;
    reg [31:0] maxX;
    reg [31:0] maxY;
    
    //fixed point multiplication
    function logic signed [31:0] fp_m(
        input logic signed [31:0] a,
        input logic signed [31:0] b
    );
        fp_m = (32'(a) * 64'(b)) >>> 16;
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
        if (x1[31:16] < x2[31:16])
            maxX_tmp = x2;
        else
            maxX_tmp = x1;

        if (maxX_tmp[31:16] < x3[31:16])
            maxX_tmp = x3;
    end
        
    always_comb begin
        if (x1[31:16] < x2[31:16])
            minX_tmp = x1;
        else
            minX_tmp = x2;

        if (minX_tmp[31:16] > x3[31:16])
            minX_tmp = x3;
    end

    always_comb begin
        if (y1[31:16] < y2[31:16])
            maxY_tmp = y2;
        else
            maxY_tmp = y1;

        if (maxY_tmp[31:16] < y3[31:16])
            maxY_tmp = y3;
    end
        
    always_comb begin
        if (y1[31:16] < y2[31:16])
            minY_tmp = y1;
        else
            minY_tmp = y2;

        if (minY_tmp[31:16] > y3[31:16])
            minY_tmp = y3;
    end

    logic signed [31:0] w1;
    logic signed [31:0] w2;
    logic signed [31:0] w3;
    logic signed [31:0] w1_tmp;
    logic signed [31:0] w1_tmp2;
    logic signed [31:0] w2_tmp;
    logic signed [31:0] w2_tmp2;
    logic signed [31:0] denom;
    logic [23:0] cur_color;
    logic signed[31:0] cur_depth;

    logic [25:0] tmp_addr_out;
    logic [23:0] tmp_color_out;

    reg signed [31:0] denom_inv;
    reg signed [31:0] denom_inv_reg;

    reg signed [31:0] denom1;
    reg signed [31:0] denom2;
    //color interpolation using Barycentric Coordinates
    always_comb begin
        //denom = fp_m(y2_t - y3_t, x1_t - x3_t) + fp_m(x3_t - x2_t, y1_t - y3_t);
    end 

    logic signed [31:0] cur_x_int;
    logic signed [31:0] cur_y_int;

    logic signed [31:0] x1_t_int;
    logic signed [31:0] y1_t_int;
    logic signed [31:0] x2_t_int;
    logic signed [31:0] y2_t_int;
    logic signed [31:0] x3_t_int;
    logic signed [31:0] y3_t_int;

    always_comb begin
        cur_x_int = cur_x >>> 16;
        cur_y_int = cur_y >>> 16;
        x1_t_int = x1_t >>> 16;
        y1_t_int = y1_t >>> 16;
        x2_t_int = x2_t >>> 16;
        y2_t_int = y2_t >>> 16;
        x3_t_int = x3_t >>> 16;
        y3_t_int = y3_t >>> 16;

        /*
        e12 = (signed'(cur_x_int - x1_t_int) * signed'(y2_t_int - y1_t_int) - signed'(cur_y_int - y1_t_int) * signed'(x2_t_int - x1_t_int)) >= 0;
        e23 = (signed'(cur_x_int - x2_t_int) * signed'(y3_t_int - y2_t_int) - signed'(cur_y_int - y2_t_int) * signed'(x3_t_int - x2_t_int)) >= 0;
        e31 = (signed'(cur_x_int - x3_t_int) * signed'(y1_t_int - y3_t_int) - signed'(cur_y_int - y3_t_int) * signed'(x1_t_int - x3_t_int)) >= 0;
        */
        //e23 = (signed'(cur_x - x2_t) * signed'(y3_t - y2_t)) - signed'(cur_y - y2_t), signed'(x3_t - x2_t))) >= 0; 
        //e31 = (fp_m(signed'(cur_x - x3_t),signed'(y1_t - y3_t)) - fp_m(signed'(cur_y - y3_t), signed'(x1_t - x3_t))) >= 0;

        is_inside = e12 >= 0 && e23 >= 0 && e31 >= 0;
    end

    function void  move_to_next();
        cur_x = cur_x + (1 << 16);

        if (cur_x > maxX) begin
            $display("newline");
            cur_x = minX;
            cur_y = cur_y + (1 << 16);
        end
    endfunction

    typedef enum logic[2:0] {R_IDLE, R_START_NEW_TRI, R_PIXEL_CALC, R_PIXEL_CALC2, R_RASTERIZE, R_WAIT} r_state_t;
    r_state_t r_state;


    lpm_divide
`ifdef VERILATOR
        #(.lpm_widthn(40),
          .lpm_widthd(32),
          .lpm_nrepresentation("SIGNED"),
          .lpm_drepresentation("SIGNED"),
          .lpm_pipeline(12)) area_divider(
`else
        #(.LPM_WIDTHN(40),
          .LPM_WIDTHD(32),
          .LPM_NREPRESENTATION("SIGNED"),
          .LPM_DREPRESENTATION("SIGNED"),
          .MAXIMIZE_SPEED(9),
          .LPM_PIPELINE(12)) area_divider(
`endif
            .clock(clock),
            .clken(1'b1),
            .numer(32'b1 << 32),
            .denom(denom),
            .quotient(denom_inv)
    );

    logic [3:0] div_counter;

    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin 
            cur_x = 0;
            cur_y = 0;
            output_valid <= 0;
            done_out = 0;
            stall_out <= 1;
            div_counter <= 0;
            r_state <= R_IDLE;
        end else begin
            $display(" rasterizer: [%d]==x[%d]==y[%d]", r_state, cur_x >> 16, cur_y >> 16);
            $display(" rasterizer: MAXY:[%d]", maxY>>16);
            $display(" rasterizer: MAXX:[%d]", maxX>>16);
            $display(" rasterizer: OUTPUT_VALID[%d]", output_valid);
            case(r_state)
                R_IDLE: begin
                    $display( "rasterizer: in_data_valid = [%d]", in_data_valid);
                    if (in_data_valid) begin
                        $display(" rasterizer: new triangle");
                        stall_out <= 0;
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
                        div_counter <= 0;

                        maxX <= maxX_tmp;
                        maxY <= maxY_tmp;
                        minX <= minX_tmp;
                        minY <= minY_tmp;

                        cur_x = minX_tmp;
                        cur_y = minY_tmp;
                        
                        denom1 <= fp_m(y2 - y3, x1 - x3);
                        denom2 <= fp_m(x3 - x2, y1 - y3);
                        r_state <= R_START_NEW_TRI;
                    end
                    output_valid <= 0;
                end
                R_START_NEW_TRI: begin
                    stall_out <= 1;
                    if (div_counter == 0) begin
                        denom <= denom1 + denom2;
                        div_counter <= div_counter + 1;
                    end else if (div_counter == 13) begin
                        div_counter <= 0;
                        denom_inv_reg <= denom_inv;
                        $display(" rasaterizer: denom = %f, denom_inv = %f",
                            $itor(denom) / $itor(1 << 16),
                            $itor(denom_inv) / $itor(1 << 16)
                        );
                        e12 <= signed'(cur_x_int - x1_t_int) * signed'(y2_t_int - y1_t_int);
                        e23 <= signed'(cur_x_int - x2_t_int) * signed'(y3_t_int - y2_t_int);
                        e31 <= signed'(cur_x_int - x3_t_int) * signed'(y1_t_int - y3_t_int);
        
                        w1_tmp <= fp_m(y2_t - y3_t, cur_x - x3_t); // + fp_m(x3_t - x2_t, cur_y - y3_t); 
                        w2_tmp <= fp_m(y3_t - y1_t, cur_x - x3_t); // + fp_m(x1_t - x3_t, cur_y - y3_t);
                        r_state <= R_PIXEL_CALC;
                    end else begin
                        div_counter <= div_counter + 1;
                    end
                end

                R_PIXEL_CALC: begin
                    e12 <= e12 - signed'(cur_y_int - y1_t_int) * signed'(x2_t_int - x1_t_int);
                    e23 <= e23 - signed'(cur_y_int - y2_t_int) * signed'(x3_t_int - x2_t_int);
                    e31 <= e31 - signed'(cur_y_int - y3_t_int) * signed'(x1_t_int - x3_t_int);
                    //e12 <= signed'(cur_x_int - x1_t_int) * signed'(y2_t_int - y1_t_int) - signed'(cur_y_int - y1_t_int) * signed'(x2_t_int - x1_t_int);
                    //e23 <= signed'(cur_x_int - x2_t_int) * signed'(y3_t_int - y2_t_int) - signed'(cur_y_int - y2_t_int) * signed'(x3_t_int - x2_t_int);
                    //e31 <= signed'(cur_x_int - x3_t_int) * signed'(y1_t_int - y3_t_int) - signed'(cur_y_int - y3_t_int) * signed'(x1_t_int - x3_t_int);
                    //w1 <= fp_m(w1_tmp, denom_inv_reg);
                    //w2 <= fp_m(w2_tmp, denom_inv_reg);
                    w1_tmp2 <= fp_m(x3_t - x2_t, cur_y - y3_t);
                    w2_tmp2 <= fp_m(x1_t - x3_t, cur_y - y3_t);
                    r_state <= R_PIXEL_CALC2;
                end

                R_PIXEL_CALC2: begin

                    w1_out <= fp_m(w1_tmp + w1_tmp2, denom_inv_reg);
                    w2_out <= fp_m(w2_tmp + w2_tmp2, denom_inv_reg);
                    r_state <= R_RASTERIZE;
                end
                R_RASTERIZE: begin
                    if (e12 >= 0 && e23 >= 0 && e31 >= 0) begin
                        $display(" rasterizer: is inside");
                        if (!output_valid) begin
                            addr_out <= addr_in_t + ((cur_y >> 16) * 640 + (cur_x >> 16) << 3);
                            $display(" rasterizer: addr_out = %x", addr_out);
                            color_out_1 <= color1_t;
                            color_out_2 <= color2_t;
                            color_out_3 <= color3_t;

                            depth_out <= fp_m(w1_out, z1_t) + fp_m(w2_out, z2_t) + fp_m((1 << 16) - w1_out - w2_out, z3_t);
                            output_valid <= 1;
                            move_to_next();
                            if (cur_y > maxY) begin
                                done_out = done_in;
                                r_state <= R_IDLE;
                            end else
                                r_state <= R_WAIT;
                        end
                    end else begin
                        output_valid <= 0;
                        move_to_next();
                        r_state <= R_WAIT;
                        if (cur_y > maxY) begin
                            done_out = done_in;
                            r_state <= R_IDLE;
                        end
                    end
                end
                R_WAIT: begin
                    $display(" rasterizer: STALL_IN[%d]", stall_in);
                    if (!is_inside) begin
                        e12 <= signed'(cur_x_int - x1_t_int) * signed'(y2_t_int - y1_t_int);
                        e23 <= signed'(cur_x_int - x2_t_int) * signed'(y3_t_int - y2_t_int);
                        e31 <= signed'(cur_x_int - x3_t_int) * signed'(y1_t_int - y3_t_int);
                        w1_tmp <= fp_m(y2_t - y3_t, cur_x - x3_t); // + fp_m(x3_t - x2_t, cur_y - y3_t); 
                        w2_tmp <= fp_m(y3_t - y1_t, cur_x - x3_t); // + fp_m(x1_t - x3_t, cur_y - y3_t);
                        r_state <= R_PIXEL_CALC;
                    end
                    if (!stall_in) begin
                        if (cur_y > maxY) begin
                            done_out = done_in;
                            r_state <= R_IDLE;
                        end else begin
                            //move_to_next();
                            e12 <= signed'(cur_x_int - x1_t_int) * signed'(y2_t_int - y1_t_int);
                            e23 <= signed'(cur_x_int - x2_t_int) * signed'(y3_t_int - y2_t_int);
                            e31 <= signed'(cur_x_int - x3_t_int) * signed'(y1_t_int - y3_t_int);
                            w1_tmp <= fp_m(y2_t - y3_t, cur_x - x3_t); // + fp_m(x3_t - x2_t, cur_y - y3_t); 
                            w2_tmp <= fp_m(y3_t - y1_t, cur_x - x3_t); // + fp_m(x1_t - x3_t, cur_y - y3_t);
                            output_valid <= 0;
                            r_state <= R_PIXEL_CALC;
                        end
                    end
                end
            endcase
        end
    end
endmodule
