
module fifo (
    input logic clk,
    input logic reset,
    input logic wr,
    input logic rd,
    input logic [DBITS-1:0] din,
    output logic empty,
    output logic full,
    output logic almost_full,
    output logic almost_empty,
    output logic [DBITS-1:0] dout);

    //DBITS: # of address bits
    //SIZE: 2^SZIE elements in buffer
    parameter DBITS = 96,
              SIZE = 4;
    
    //16 element fifo, each element is 26 bis
    logic [DBITS-1:0] buffer[15:0];
    //write pointer
    logic [3:0] wr_ptr;
    //read pointer
    logic [3:0] rd_ptr;
    logic [3:0] counter;

    wire almost_full;
    wire almost_empty;

    assign almost_full = counter >= (2**SIZE - 1);
    assign almost_empty = counter < 2;

    //counter keeps track of number of elements in buffer
    assign empty = (counter == 0); 
    assign full = (counter == 2**SIZE);

    assign dout = buffer[rd_ptr];

    logic [3:0] new_counter;
    always @(posedge clk or negedge reset)
    begin
        if (!reset) begin
            wr_ptr <= 4'b0000;
            rd_ptr <= 4'b0000;
            counter <= 0;
            new_counter = 0;
        end 
        new_counter = counter;
        if (rd == 1'b1 && ~empty) begin
            rd_ptr <= rd_ptr + 1;
            new_counter = new_counter - 1;
        end
        
        if (wr == 1'b1 && ~full) begin
            buffer[wr_ptr] <= din;
            wr_ptr <= wr_ptr + 1;
            new_counter = new_counter + 1;
        end 
        counter <= new_counter;
    end 

endmodule;  

