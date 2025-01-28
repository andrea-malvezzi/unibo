(LOOP)
    @1
    D = M
    @0
    M = M + D
    @5
    D = D - A
    @INCR
    D;JLT
    (POST)
    @0
    D = M
    @1
    D = D - M
    D = D - M
    @LOOP
    D;JLE
    @END
    0;JMP

(INCR)
    @1
    M = M + 1
    @POST
    0;JMP

(END)
    @END
    0;JMP