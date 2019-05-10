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

always_ff @(posedge clk or negedge reset_n)begin
    if (!reset_n) begin
        MV <= 0;
        MVP <= 0;
        frame_buffer_base <= 0;
        vertex_buffer_base <= 26'h300000;
    end
    else if (write) begin
        case (address)
            'h0: frame_buffer_base <= writedata;
            'h4: vertex_buffer_base <= writedata;
            'h8: do_render <= writedata;
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
   end
endmodule // config_reg
