// preparo MEM[0] e il counter (MEM[21])
@0
M=0
@18
D=A
@21
M=D

@LOOP

(LOOP)
    // controllo il counter
    @21
    D=M
    @END    // preparo a terminare
    D;JLT

    // sommo a 2 il counter e vado a quell'indirizzo
    @2
    D=D+A
    A=D
    D=M

    // abbasso il counter
    @21
    M=M-1

    // controllo che il valore nell'indirizzo ottenuto sia minore di 5
    @5
    D=D-A
    @ADD    // preparo ad aggiungere 1 al contatore
    D;JLT

    // ricomincio
    @LOOP
    0;JMP

(ADD)
    @0
    M=M+1
    @LOOP
    0;JMP

(END)
    @END
    0;JMP
