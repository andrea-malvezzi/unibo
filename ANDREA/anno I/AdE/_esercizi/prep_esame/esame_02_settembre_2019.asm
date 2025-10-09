@40	            // A = 40
D = A	        // D = 40

(NEXT)
	@10	        // A = 10
	M = D	    // inizialmente 40
	@51
	D = D - A
	@END
	D;JGE	    // se D = 51 salta
	@LOOP	    // prepara ad andare nel loop
	0;JMP	    // salta

(LOOP)
	@10		    // A = 10
	D = A		// D = 10
	A = M		// A = 40
	M = D		// RAM[40] = 10
	D = A		// D = 40
	D = D + 1	// D = 40 + 1
	@NEXT
	0;JMP

(END)
    @END
    0;JMP