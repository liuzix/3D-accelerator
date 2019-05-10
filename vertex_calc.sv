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

    logic [63:0] tmp_x[2:0];
    logic [63:0] tmp_y[2:0];
    logic [63:0] tmp_z[2:0];
    logic [63:0] tmp_w[2:0];

    assign  tmp_x[0] = mat[0] * v_in[0] + mat[1] * v_in[1] + mat[2] * v_in[2] + mat[3]; //w = 1
    assign  tmp_y[0] = mat[4] * v_in[0] + mat[5] * v_in[1] + mat[6] * v_in[2] + mat[7];
    assign  tmp_z[0] = mat[8] * v_in[0] + mat[9] * v_in[1] + mat[10] * v_in[2] + mat[11];
    assign  tmp_w[0] = mat[12] * v_in[0] + mat[13] * v_in[1] + mat[14] * v_in[2] + mat[15];
      
    assign  tmp_x[1] = mat[0] * v_in[4] + mat[1] * v_in[5] + mat[2] * v_in[6] + mat[3]; //w = 1
    assign  tmp_y[1] = mat[4] * v_in[4] + mat[5] * v_in[5] + mat[6] * v_in[6] + mat[7];
    assign  tmp_z[1] = mat[8] * v_in[4] + mat[9] * v_in[5] + mat[10] * v_in[6] + mat[11];
    assign  tmp_w[1] = mat[12] * v_in[4] + mat[13] * v_in[5] + mat[14] * v_in[6] + mat[15];
        
    assign  tmp_x[2] = mat[0] * v_in[8] + mat[1] * v_in[9] + mat[2] * v_in[10] + mat[3]; //w = 1
    assign  tmp_y[2] = mat[4] * v_in[8] + mat[5] * v_in[9] + mat[6] * v_in[10] + mat[7];
    assign  tmp_z[2] = mat[8] * v_in[8] + mat[9] * v_in[9] + mat[10] * v_in[10] + mat[11];
    assign  tmp_w[2] = mat[12] * v_in[8] + mat[13] * v_in[9] + mat[14] * v_in[10] + mat[15];
    


    always_ff @(posedge clock or negedge reset) begin
        if (reset) begin
            done_out <= 0;
            stall_out <= 0;
        end

        if (!out_data_valid) begin
            x_out[0] <= tmp_x[0][47:16];
            y_out[0] <= tmp_y[0][47:16];
            z_out[0] <= tmp_z[0][47:16];
            w_out[0] <= tmp_w[0][47:16];

            x_out[1] <= tmp_x[1][47:16];
            y_out[1] <= tmp_y[1][47:16];
            z_out[1] <= tmp_z[1][47:16];
            w_out[1] <= tmp_w[1][47:16];

            x_out[2] <= tmp_x[2][47:16];
            y_out[2] <= tmp_y[2][47:16];
            z_out[2] <= tmp_z[2][47:16];
            w_out[2] <= tmp_w[2][47:16];
            done_out <= 1;
            out_data_valid <= 1;
            stall_out <= 0;
        end else begin 
            if (!stall_in) begin
                x_out[0] <= tmp_x[0][47:16];
                y_out[0] <= tmp_y[0][47:16];
                z_out[0] <= tmp_z[0][47:16];
                w_out[0] <= tmp_w[0][47:16];

                x_out[1] <= tmp_x[1][47:16];
                y_out[1] <= tmp_y[1][47:16];
                z_out[1] <= tmp_z[1][47:16];
                w_out[1] <= tmp_w[1][47:16];

                x_out[2] <= tmp_x[2][47:16];
                y_out[2] <= tmp_y[2][47:16];
                z_out[2] <= tmp_z[2][47:16];
                w_out[2] <= tmp_w[2][47:16];
                done_out <= 1;
                out_data_valid <= 1;
                stall_out <= 0;
            end else 
                stall_out <= 1;
        end
    end
endmodule
