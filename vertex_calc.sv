//refernce: https://stackoverflow.com/questions/27758667/verilog-floating-points-multiplication

module vertex_calc (input clock,
                    input reset,
                    input logic [31:0] mat[15:0],
                    input logic [31:0] v_in [14:0],
                    input logic [31:0] lighting[2:0],
                    input logic [23:0] color_in1,
                    input logic [23:0] color_in2,
                    input logic [23:0] color_in3,
                    input logic input_data_valid,
                    input logic done_in,
                    input logic stall_in,
                    output logic [31:0] x_out[3:0],
                    output logic [31:0] y_out[3:0],
                    output logic [31:0] z_out[3:0],
                    output logic [31:0] w_out[3:0],
                    output logic [23:0] color_out1,
                    output logic [23:0] color_out2,
                    output logic [23:0] color_out3,
                    output logic out_data_valid,
                    output logic done_out,
                    output logic stall_out);

    //v_in 0-14 = x1 y1 z1 rgb1 x2 y2 z2 rgb2 x3 y3 z3 rgb3 nx ny nz
    
    //fixed point multiplication
    function logic signed [31:0] fp_m(
        input logic signed [31:0] a,
        input logic signed [31:0] b
    );
        fp_m = (64'(a) * 64'(b)) >>> 16;
    endfunction 

    logic [31:0] w;

    logic signed [31:0] width;
    logic signed [31:0] height;
    logic signed [31:0] tmp_x[2:0];
    logic signed [31:0] tmp_y[2:0];
    logic signed [31:0] tmp_z[2:0];
    logic signed [31:0] tmp_w[2:0];
    logic [31:0] color1_r;
    logic [31:0] color1_g;
    logic [31:0] color1_b;
    logic [31:0] color2_r;
    logic [31:0] color2_g;
    logic [31:0] color2_b;
    logic [31:0] color3_r;
    logic [31:0] color3_g;
    logic [31:0] color3_b;
    logic [31:0] color1_rnew;
    logic [31:0] color1_gnew;
    logic [31:0] color1_bnew;
    logic [31:0] color2_rnew;
    logic [31:0] color2_gnew;
    logic [31:0] color2_bnew;
    logic [31:0] color3_rnew;
    logic [31:0] color3_gnew;
    logic [31:0] color3_bnew;
    logic [31:0]cosine;

    assign w = (1 << 16);
    assign width[31:16] = 16'd320;
    assign width[15:0] = 0;
    assign height[31:16] = 16'd240;
    assign height[15:0] = 0;
    //assign cosine = fp_m(v_in[12],lighting[0])+fp_m(v_in[13],lighting[1])+fp_m(v_in[14],lighting[2]);
    assign color1_r = {8'b0,color_in1[23:16],16'b0};
    assign color1_g = {8'b0,color_in1[15:8],16'b0};
    assign color1_b = {8'b0,color_in1[7:0],16'b0};
    assign color2_r = {8'b0,color_in2[23:16],16'b0};
    assign color2_g = {8'b0,color_in2[15:8],16'b0};
    assign color2_b = {8'b0,color_in2[7:0],16'b0};
    assign color3_r = {8'b0,color_in3[23:16],16'b0};
    assign color3_g = {8'b0,color_in3[15:8],16'b0};
    assign color3_b = {8'b0,color_in3[7:0],16'b0};
    /*
    assign color1_rnew=fp_m(color1_r,cosine);
    assign color1_gnew=fp_m(color1_g,cosine);
    assign color1_bnew=fp_m(color1_b,cosine);
    assign color2_rnew=fp_m(color2_r,cosine);
    assign color2_gnew=fp_m(color2_g,cosine);
    assign color2_bnew=fp_m(color2_b,cosine);
    assign color3_rnew=fp_m(color3_r,cosine);
    assign color3_gnew=fp_m(color3_g,cosine);
    assign color3_bnew=fp_m(color3_b,cosine);
    */
    assign  tmp_x[0] = fp_m(mat[0],v_in[0]) + fp_m(mat[1],v_in[1]) + fp_m(mat[2],v_in[2]) + fp_m(mat[3], w); //w = 1
    assign  tmp_y[0] = fp_m(mat[4],v_in[0]) + fp_m(mat[5],v_in[1]) + fp_m(mat[6],v_in[2]) + fp_m(mat[7], w);
    assign  tmp_z[0] = fp_m(mat[8],v_in[0]) + fp_m(mat[9],v_in[1]) + fp_m(mat[10],v_in[2]) + fp_m(mat[11], w);
    assign  tmp_w[0] = fp_m(mat[12],v_in[0]) + fp_m(mat[13],v_in[1]) + fp_m(mat[14],v_in[2]) + fp_m(mat[15], w);
      
    assign  tmp_x[1] = fp_m(mat[0],v_in[4]) + fp_m(mat[1],v_in[5]) + fp_m(mat[2],v_in[6]) + fp_m(mat[3], w); //w = 1
    assign  tmp_y[1] = fp_m(mat[4],v_in[4]) + fp_m(mat[5],v_in[5]) + fp_m(mat[6],v_in[6]) + fp_m(mat[7], w);
    assign  tmp_z[1] = fp_m(mat[8],v_in[4]) + fp_m(mat[9],v_in[5]) + fp_m(mat[10],v_in[6]) + fp_m(mat[11], w);
    assign  tmp_w[1] = fp_m(mat[12],v_in[4]) + fp_m(mat[13],v_in[5]) + fp_m(mat[14],v_in[6]) + fp_m(mat[15], w);
        
    assign  tmp_x[2] = fp_m(mat[0],v_in[8]) + fp_m(mat[1],v_in[9]) + fp_m(mat[2],v_in[10]) + fp_m(mat[3], w); //w = 1
    assign  tmp_y[2] = fp_m(mat[4],v_in[8]) + fp_m(mat[5],v_in[9]) + fp_m(mat[6],v_in[10]) + fp_m(mat[7], w);
    assign  tmp_z[2] = fp_m(mat[8],v_in[8]) + fp_m(mat[9],v_in[9]) + fp_m(mat[10],v_in[10]) + fp_m(mat[11], w);
    assign  tmp_w[2] = fp_m(mat[12],v_in[8]) + fp_m(mat[13],v_in[9]) + fp_m(mat[14],v_in[10]) + fp_m(mat[15], w);
    
    function void output_triangle();
        x_out[0] = fp_m(tmp_x[0], width) + width; 
        y_out[0] = fp_m(tmp_y[0], height) + height;
        z_out[0] = fp_m(tmp_z[0], width) + width;
        w_out[0] = fp_m(tmp_w[0], height) + height;
    
        x_out[1] = fp_m(tmp_x[1], width) + width; 
        y_out[1] = fp_m(tmp_y[1], height) + height;
        z_out[1] = fp_m(tmp_z[1], width) + width;
        w_out[1] = fp_m(tmp_w[1], height) + height;

        x_out[2] = fp_m(tmp_x[2], width) + width; 
        y_out[2] = fp_m(tmp_y[2], height) + height;
        z_out[2] = fp_m(tmp_z[2], width) + width;
        w_out[2] = fp_m(tmp_w[2], height) + height;

        $display("vertex_calc: triangle = (%d, %d, %d), (%d, %d, %d), (%d, %d, %d)",
            $signed(v_in[0]) >>> 16, $signed(v_in[1]) >>> 16, $signed(v_in[2]) >>> 16,
            $signed(v_in[4]) >>> 16, $signed(v_in[5]) >>> 16, $signed(v_in[6]) >>> 16,
            $signed(v_in[8]) >>> 16, $signed(v_in[9]) >>> 16, $signed(v_in[10]) >>> 16);
        /*
        color_out1 = {color1_rnew[23:16],color1_gnew[23:16],color1_bnew[23:16]};
        color_out2 = {color2_rnew[23:16],color2_gnew[23:16],color2_bnew[23:16]};
        color_out3 = {color3_rnew[23:16],color3_gnew[23:16],color3_bnew[23:16]};
        */
        color_out1 = {color1_r[23:16],color1_g[23:16],color1_b[23:16]};
        color_out2 = {color2_r[23:16],color2_g[23:16],color2_b[23:16]};
        color_out3 = {color3_r[23:16],color3_g[23:16],color3_b[23:16]};
        //$display("vertex_color: triangle = (%d, %d, %d), (%d, %d, %d), (%d, %d, %d)");
        done_out = done_in;
        $display("vertex_calc: color = %d, %d, %d", color_in1, color_in2, color_in3);
    endfunction

    typedef enum logic {S_IDLE, S_HOLD} state_t;
    state_t state;

    always_ff @(posedge clock or negedge reset) begin
        if (!reset) begin
            done_out = 0;
            stall_out <= 0;
            out_data_valid <= 0;
        end
        else begin
            $display("vertex_calc: state = %d", state);
            $display("vertex_calc: input_data_valid = %d", input_data_valid);
            $display("vertex_calc: stall_out = %d", stall_out);
            case (state)
            S_IDLE: begin
                assert(!out_data_valid);
                if (input_data_valid) begin
                    output_triangle();
                    out_data_valid <= 1;
                    stall_out <= 0;
                    state <= S_HOLD;
                end
            end

            S_HOLD: begin
                assert(out_data_valid);
                if (!stall_in) begin
                    if (input_data_valid) begin
                        output_triangle();
                        out_data_valid <= 1;
                        stall_out <= 0;
                    end else begin
                        out_data_valid <= 0;
                        stall_out <= 0;
                        state <= S_IDLE;
                    end
                end else begin
                    stall_out <= 1;
                end
            end

            endcase
        end
    end
endmodule
