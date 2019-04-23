//refernce: https://stackoverflow.com/questions/27758667/verilog-floating-points-multiplication

module vertex_calc (input logic [127:0] matrix[1:0],
                    input logic [31:0] x_in,
                    input logic [31:0] y_in,
                    input logic [31:0] z_in,
                    input logic [31:0] w_in,
                    output logic [31:0] x_out,
                    output logic [31:0] y_out,
                    output logic [31:0] z_out,
                    output logic [31:0] w_out)

    logic [61:0] tmp_x;
    logic [61:0] tmp_y;
    logic [61:0] tmp_z;
    logic [61:0] tmp_w;

    always_comb
        tmp_x = matrix[0][127:96] * x_in + matrix[0][95:64] * y_in + matrix[0][63:32] * z_in + matrix[0][31:0] * w_in;
        tmp_y = matrix[1][127:96] * x_in + matrix[1][95:64] * y_in + matrix[1][63:32] * z_in + matrix[1][31:0] * w_in;
        tmp_z = matrix[2][127:96] * x_in + matrix[2][95:64] * y_in + matrix[2][63:32] * z_in + matrix[2][31:0] * w_in;
        tmp_w = matrix[3][127:96] * x_in + matrix[3][95:64] * y_in + matrix[3][63:32] * z_in + matrix[3][31:0] * w_in;
        
    assign x_out = tmp_x[31:0];
    assign y_out = tmp_y[31:0];
    assign z_out = tmp_z[31:0];
    assign w_out <= tmp_w[31:0];

endmodule
