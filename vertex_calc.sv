//refernce: https://stackoverflow.com/questions/27758667/verilog-floating-points-multiplication

module vertex_calc (input clock,
                    input reset,
                    input logic [31:0] mat[15:0],
                    input logic [31:0] v_in [14:0],
                    input logic input_data_valid,
                    input logic done_in,
                    input logic stall_in,
                    output logic [31:0] x_out[3:0],
                    output logic [31:0] y_out[3:0],
                    output logic [31:0] z_out[3:0],
                    output logic [31:0] w_out[3:0],
                    output logic out_data_valid,
                    output logic done_out,
                    output logic stall_out);

    //v_in 0-14 = x1 y1 z1 rgb1 x2 y2 z2 rgb2 x3 y3 z3 rgb3 nx ny nz
    
    //fixed point multiplication
    function logic signed [31:0] fp_m(
        input logic signed [31:0] a,
        input logic signed [31:0] b
    );
        logic [63:0] tmp_a;
        logic [63:0] tmp_b;
        tmp_a[63:32] = 0;
        tmp_a[31:0] = a;
        tmp_b[63:32] = 0;
        tmp_b[31:0] = b;
        fp_m = (tmp_a * tmp_b) >> 16;
    endfunction 

    logic [31:0] w;

    logic signed [31:0] width;
    logic signed [31:0] height;
    logic signed [31:0] tmp_x[2:0];
    logic signed [31:0] tmp_y[2:0];
    logic signed [31:0] tmp_z[2:0];
    logic signed [31:0] tmp_w[2:0];
    
    assign w = 1;
    assign width[31:16] = 16'd640;
    assign width[15:0] = 0;
    assign height[31:16] = 16'd480;
    assign height[15:0] = 0;

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
    


    always_ff @(posedge clock or negedge reset) begin
        if (reset) begin
            done_out <= 0;
            stall_out <= 0;
        end

        if (!out_data_valid) begin
            x_out[0] <= fp_m(tmp_x[0], width) + width; 
            y_out[0] <= fp_m(tmp_y[0], height) + height;
            z_out[0] <= fp_m(tmp_x[0], width) + width;
            w_out[0] <= fp_m(tmp_y[0], height) + height;
            
            x_out[1] <= fp_m(tmp_x[1], width) + width; 
            y_out[1] <= fp_m(tmp_y[1], height) + height;
            z_out[1] <= fp_m(tmp_x[1], width) + width;
            w_out[1] <= fp_m(tmp_y[1], height) + height;

            x_out[2] <= fp_m(tmp_x[2], width) + width; 
            y_out[2] <= fp_m(tmp_y[2], height) + height;
            z_out[2] <= fp_m(tmp_x[2], width) + width;
            w_out[2] <= fp_m(tmp_y[2], height) + height;

            done_out <= 1;
            out_data_valid <= 1;
            stall_out <= 0;
        end else begin 
            if (!stall_in) begin
                x_out[0] <= tmp_x[0];
                y_out[0] <= tmp_y[0];
                z_out[0] <= tmp_z[0];
                w_out[0] <= tmp_w[0];

                x_out[1] <= tmp_x[1];
                y_out[1] <= tmp_y[1];
                z_out[1] <= tmp_z[1];
                w_out[1] <= tmp_w[1];

                x_out[2] <= tmp_x[2];
                y_out[2] <= tmp_y[2];
                z_out[2] <= tmp_z[2];
                w_out[2] <= tmp_w[2];
                done_out <= 1;
                out_data_valid <= 1;
                stall_out <= 0;
            end else 
                stall_out <= 1;
        end
    end
endmodule
