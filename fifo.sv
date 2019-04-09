
module fifo (
    input logic clk,
    input logic reset,
    input logic wr,
    input logic rd,
    input logic [95:0] din,
    output logic empty,
    output logic full,
    output logic almost_full,
    output logic almost_empty,
    output logic [95:0] dout);

    //DBITS: # of address bits
	//SIZE: 2^SZIE elements in buffer
    parameter DBITS = 26,
              SIZE = 4;
    
	//16 element fifo, each element is 26 bis
    logic [95:0] buffer[15:0];
    //write pointer
    logic [3:0] wr_ptr;
    //read pointer
    logic [3:0] rd_ptr;
    logic isFull, isEmpty;
    logic [3:0] counter;

    wire almost_full;
    wire almost_empty;

    assign almost_full = counter >= (2**SIZE - 2);
    assign almost_empty = counter <= 2;

    assign wr_ptr = 4'b0000;
    assign rd_ptr = 4'b0000;
    //counter keeps track of number of elements in buffer
    assign counter = 0;
    assign empty = (counter == 0) ? 1'b1 : 1'b0;
    assign full = (counter == 2**SIZE) ? 1'b1 : 1'b0;

	always @(posedge clk)
	begin
	    //en is 1 if buffer not full 
            if (reset) begin
                wr_ptr <= 4'b0000;
                rd_ptr <= 4'b0000;
                counter <= 0;
		    end 
		    else if (rd == 1'b1 && ~empty) begin
                dout = buffer[rd_ptr];
                rd_ptr = rd_ptr + 1;
                counter <= counter - 1;
			end
            else if (wr == 1'b1 && ~full) begin
                buffer[wr_ptr] = din;
                wr_ptr = rd_ptr + 1;
                counter <= counter + 1;
            end 
 
            //if (wr_ptr == 4'd16)
             //   wr_ptr = 4'b0000;
	
            //if (rd_ptr == 4'd16)
              //  rd_ptr = 4'b0000);

    end 

endmodule;  

