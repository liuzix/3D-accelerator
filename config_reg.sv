module config_reg(
    input logic clk,
    input logic reset_n,
    input logic [32:0] writedata,
    input logic write,
    input logic read,
    input logic [15:0] address,
    output logic [32:0] readdata,
    
    output logic [511:0] MV,
    output logic [511:0] MVP,
    output logic [96:0] lighting,
    output logic [25:0] frame_buffer_base,
    output logic [25:0] vertex_buffer_base,

    inout logic do_render
);

<<<<<<< HEAD
always_ff @(posedge clk or negedge reset)
    if (!reset) begin
=======
always_ff @(posedge clk or negedge reset_n)
    if (!reset_n) begin
>>>>>>> 2f2036e50a521ce868f4a2cbde8ef74ebec26316
        MV <= 0;
        MVP <= 0;
        frame_buffer_base <= 0;
        vertex_buffer_base <= 26'h300000;
    end
    else if (write) begin
        case (address)
<<<<<<< HEAD
            h0: frame_buffer_base <= writedata;
            h4: vertex_buffer_base <= writedata;
            h8: do_render <= writedata;//?
=======
            'h0: frame_buffer_base <= writedata;
            'h4: vertex_buffer_base <= writedata;
            'h8: do_render <= writedata;
>>>>>>> 2f2036e50a521ce868f4a2cbde8ef74ebec26316
            default:
                if ('h100 <= address && address <= 'h13C)
                    MV[(address - 'h100) * 8 + 31: (address - 'h100) * 8] <= writedata;
                else if ('h200 <= address && address <= 'h23C)
                    MVP[(address - 'h200) * 8 + 31: (address - 'h200) * 8] <= writedata;
                else if ('h300 <= address & address <= 'h308)
                    lighting[(address - 'h300) * 8 + 31: (address - 'h300) * 8] <= writedata;
        endcase
    end
    else if (read && address == 'h8)
        readdata <= do_render;

endmodule // config_reg
