@17 // preparo counter
D=A
@1  // counter
M=D
@0  // temp per la somma
M=0

(LOOP)
    @1
    D=M

    @ESCI       // preparo a uscire dal loop se counter=0
    D;JEQ
    
    @1
    M=M-1       // abbasso counter

    @DISPARI    // preparo a saltare al caso in cui il numero sia dispari
    M=D         // MEM[DISPARI] = counter
    @1          
    D=D&A       // se D dispari
    @DISPARI
    D;JNE

    @LOOP       // ricomincio
    0;JMP

(DISPARI)
    D=M
    @0
    M=M+D
    @LOOP
    0;JMP

(ESCI)
    @0
    D=M
    A=D
    M=D
    @END
    0;JMP

(END)
    @END
    0;JMP