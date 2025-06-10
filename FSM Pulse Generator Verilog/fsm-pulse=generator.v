module fsm_pulse_generator (
    input        clk,
    input  [1:0] I,
    output reg [1:0] Z
);

    // State encoding
    parameter A = 4'b0000, B = 4'b0001, C = 4'b0010, D = 4'b0011,
              E = 4'b0100, F = 4'b0101, G = 4'b0110, H = 4'b0111,
              I_ = 4'b1000, J = 4'b1001, K = 4'b1010, L = 4'b1011;

    reg [3:0] state;

    // State transition logic 
    always @(posedge clk) begin
        if (state == L)
            state <= A; // Reset to A after last state
        else
            state <= state + 1; // Move to next state
    end

    // Output logic
    always @(state or I) begin
        case (I)
            2'b00: begin
                case (state)
                    A: Z = 2'b11;
                    B: Z = 2'b10;
                    C: Z = 2'b00;
                    D: Z = 2'b11;
                    E: Z = 2'b11;
                    F: Z = 2'b11;
                    G: Z = 2'b11;
                    H: Z = 2'b11;
                    I_: Z = 2'b10;
                    J: Z = 2'b10;
                    K: Z = 2'b10;
                    L: Z = 2'b01;
                    default: Z = 2'bxx;
                endcase
            end
            2'b10: begin
                case (state)
                    A: Z = 2'b10;
                    B: Z = 2'b01;
                    C: Z = 2'b10;
                    D: Z = 2'bxx; // Don't care
                    E: Z = 2'bxx;
                    F: Z = 2'bxx;
                    G: Z = 2'bxx;
                    H: Z = 2'bxx;
                    I_: Z = 2'bxx;
                    J: Z = 2'bxx;
                    K: Z = 2'bxx;
                    L: Z = 2'bxx;
                    default: Z = 2'bxx;
                endcase
            end
            2'b01: begin
                case (state)
                    A: Z = 2'b01;
                    B: Z = 2'b11;
                    C: Z = 2'b11;
                    D: Z = 2'b00;
                    E: Z = 2'bxx; // Don't care
                    F: Z = 2'bxx;
                    G: Z = 2'bxx;
                    H: Z = 2'bxx;
                    I_: Z = 2'bxx;
                    J: Z = 2'bxx;
                    K: Z = 2'bxx;
                    L: Z = 2'bxx;
                    default: Z = 2'bxx;
                endcase
            end
            2'b11: begin
                case (state)
                    A: Z = 2'b00;
                    B: Z = 2'b01;
                    C: Z = 2'b00;
                    D: Z = 2'b00;
                    E: Z = 2'bxx; // Don't care
                    F: Z = 2'bxx;
                    G: Z = 2'bxx;
                    H: Z = 2'bxx;
                    I_: Z = 2'bxx;
                    J: Z = 2'bxx;
                    K: Z = 2'bxx;
                    L: Z = 2'bxx;
                    default: Z = 2'bxx;
                endcase
            end
            default: Z = 2'bxx;
        endcase
    end

endmodule
