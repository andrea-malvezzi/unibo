@9      // A=9
D=A     // D=9
@11     // A=11
M=D     // RAM[11]=9, contatore
@9      // A=9
D=M     // D=RAM[9], il primo valore equivale a max
@10     // A=10
M=D     // RAM[10]=RAM[9]
    
(LOOP)          // Dichiaro inizio loop
	    @11     // A=11
        D=M     // D=RAM[11], contatore
        @END    // Preparo a terminare
        D;JEQ   // Se D equivale a 0, JUMP

        @11     // Rimetto A=11
        M=M-1   // RAM[11]--
        A=M     // A=RAM[11]
        D=M     // D=RAM[A]
        @10
        D=M-D   // D=(Max)-(valore corrente)
        @SET    // Preparo a cambiare max
        D;JLT   // Se D<0, JUMP

        @LOOP   // Preparo a rifare
        0;JMP   // Salto incondizionato   

    (SET)
        @11     // A=11
        D=M     // D=RAM[11], contatore
        A=D     // A=contatore
        D=M     // D=(valore corrente)
        @10     // A=10
        M=D     // Cambio max
        
        @LOOP   // Preparo a rientrare nel loop
        0;JMP   // Salto incondizionato

    (END)       // Ciclo dummy finale
        @END
        0;JMP