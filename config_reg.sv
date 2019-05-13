module config_reg(
    input logic clk,
    input logic reset_n,
    input logic [32:0] writedata,
    input logic write,
    input logic read,
    input logic [15:0] address,
    output logic [32:0] readdata,
    
    output logic [31:0] MV [15:0],
    output logic [31:0] MVP [15:0],
    output logic [31:0] lighting [2:0],
    output logic [25:0] frame_buffer_base,
    output logic [25:0] vertex_buffer_base,

    input logic done_in,
    output logic start_render,
	 
	 output logic test,
	 output logic [6:0] hex [3:0]
);

logic done_latch;
hex7seg h1(
	.a(address[3:0]),
	.y(hex[0])
);
hex7seg h2(
	.a(address[7:4]),
	.y(hex[1])
);
hex7seg h3(
	.a(address[11:8]),
	.y(hex[2])
);
hex7seg h4(
	.a(address[15:12]),
	.y(hex[3])
);

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
		  readdata <= 'habcd9102;
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
					 test <= 1;
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
			test <= 1;
    end
	 else if (read) begin
			case (address)
				'h8: readdata <= done_latch;
				'h500: readdata <= 'hdeadbeef;
				default:
					if (address >'h500)
						readdata <= 'habcd2019;
			endcase
			test <= 0;
	 end else if (!read || !write) begin
		test <= 0;
	 end
	end
endmodule // config_reg
