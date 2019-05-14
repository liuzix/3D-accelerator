module config_reg(
    input logic clk,
    input logic reset_n,
    input logic [31:0] writedata,
    input logic write,
    input logic read,
    input logic [15:0] address,
    output logic [31:0] readdata,
    
    output logic [31:0] MV [15:0],
    output logic [31:0] MVP [15:0],
    output logic [31:0] lighting [2:0],
    output logic [25:0] frame_buffer_base,
    output logic [25:0] vertex_buffer_base,

    input logic done_in,
	 output logic test,
    output logic start_render
);

logic done_latch;

always_latch begin
    if (!reset_n)
        done_latch <= 0;
    else
    if (done_in)
        done_latch <= 1;
end

always_ff @(posedge clk or negedge reset_n)begin
    if (!reset_n) begin
        start_render <= 0;
        frame_buffer_base <= 0;
        vertex_buffer_base <= 26'h300000;
		  test <= 1;
    end
    else if (write) begin
        case (address)
            'h0: begin 
                frame_buffer_base <= writedata;
                $display("frame_buffer_base: %d", writedata);
            end
            'h4: begin
                vertex_buffer_base <= writedata;
                $display("vertex_buffer_base: %d", writedata);
            end
            'h8: begin
                start_render <= writedata;
					 test <= 0;
                $display("start_render: %d", writedata);
            end
            default:
                if ('h100 <= address && address <= 'h13C)
                    MV[(address - 'h100) / 4] <= writedata;
                else if ('h200 <= address && address <= 'h23C)
                    MVP[(address - 'h200) / 4] <= writedata;
                else if ('h300 <= address & address <= 'h308)
                    lighting[(address - 'h300) / 4] <= writedata;
        endcase
      end
    else if (read && address == 'h8)
        readdata <= done_latch;
	else if (read && address == 'h500) begin
		  readdata <= 'hdeadbeef;
		  test <= 1;
    end
    else if (start_render == 1)
        start_render <= 0;
   end
endmodule // config_reg
