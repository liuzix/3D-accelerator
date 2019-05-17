
module fifo (
    input logic clk,
    input logic reset,
    input logic wr,
    input logic rd,
    input logic [DBITS-1:0] din,
    output logic empty,
    output logic full,
    output logic almost_full,
    output logic half_full,
    output logic almost_empty,
    output logic [DBITS-1:0] dout);

    //DBITS: # of address bits
    //SIZE: 2^SZIE elements in buffer
    parameter DBITS = 96,
              SIZE = 4;
    
    //16 element fifo, each element is 26 bis
    logic [DBITS-1:0] buffer[2**SIZE - 1:0];
    //write pointer
    logic [SIZE - 1:0] wr_ptr;
    //read pointer
    logic [SIZE - 1:0] rd_ptr;
    logic [SIZE:0] counter;

    //wire almost_full;
    //wire almost_empty;

    assign almost_full = counter >= (2**SIZE - 1);
    assign almost_empty = counter < 2;

    //counter keeps track of number of elements in buffer
    assign empty = (counter == 0); 
    assign full = (counter == 2**SIZE);
    assign half_full = (counter >= ((2**SIZE) >> 1));

    assign dout = buffer[rd_ptr];

    logic [SIZE:0] new_counter;
    always_ff @(posedge clk or negedge reset)
    begin
        if (!reset) begin
            wr_ptr <= 0;
            rd_ptr <= 0;
            counter <= 0;
            new_counter = 0;
        end

        else begin 
            assert(rd_ptr + counter == wr_ptr);
            new_counter = counter;
            if (rd && !empty) begin
                buffer[rd_ptr] <= 0; // poison
                rd_ptr <= rd_ptr + 1;
                new_counter = new_counter - 1;
            end
              
            if (wr && !full) begin
                buffer[wr_ptr] <= din;
                wr_ptr <= wr_ptr + 1;
                new_counter = new_counter + 1;
            end 
            counter <= new_counter;
        end
    end 

endmodule 

