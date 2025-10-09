//replica:
//j=1
//while( j <= i ){
//	k = k++
//	j = j + 3
//}
//k = j + 1
//sapendo che j, i, k salvati in RAM[0..2]
// --------------------------------------------------start
@0	// j var
D=M	// RAM[0] counter loop

(LOOP)
	@1	// i var
	D=D-M	// RAM[0] - RAM[1]
	@SET	// prima uso l'etichetta, poi faccio il salto
	D;JGT	// se D > 0, finisco il loop

	@2	// k var
	D=M	// prendo il valore nel registro RAM[2]
	D=D+1	// aumento di 1 il valore nel registro RAM[2]
	M=D	// salvo k nel registro RAM[2]

	@0	// j var
	D=M	// RAM[0] valore di j
	@3	
	D=D+A	// D+3 non esiste, devo usare D+A
	@0
	M=D	// salvo j nel registro RAM[0]

	@LOOP
	0;JMP	// torna all'inizio

// fine loop

(SET)
	@0	// j var
	D=M	// RAM[0] valore di j
	
	@2
	M=D+1	// RAM[2] = j++
	@END
	0;JMP	// Termino

(END)
	@END	// ciclo dummy, rimetto la A al valore di END e termino
	0;JMP	// termina

// works!