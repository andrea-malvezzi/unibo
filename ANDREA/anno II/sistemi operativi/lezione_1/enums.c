#include <stdio.h>

// [p] << [n] corrisponde ad uno shift a sinitra di [n] bit nella maschera bit del valore [p]
// i.e. 1 << 1 corrisponde a 00000010 invece che 00000001
enum Permessi {
    READ    = 1 << 0,
    WRITE   = 1 << 1,
    EXECUTE = 1 << 2,
};

void combina() {
    // combinare significa fare la somma. La somma binaria corrisponde all'or.
    // non ricordo il % giusto :(
    printf("r/w: %d\n", (READ | WRITE));
    printf("r/x: %u\n", (READ | EXECUTE));
    printf("w/x: %i\n", (WRITE | EXECUTE));
    printf("r/w/x: %d\n", (READ | WRITE | EXECUTE));
}

void modifica() {
    printf("---------- Modifiche & ----------\n");
    printf("r & w: %\n", (READ & WRITE));
    printf("w & x: %\n", (WRITE & EXECUTE));
    printf("r & x: %\n", (READ & EXECUTE));
    printf("r & w & x: %\n\n", (READ & WRITE & EXECUTE));

    printf("---------- Modifiche ^ ----------\n");
    printf("r ^ w: %\n", (READ ^ WRITE));
    printf("w ^ x: %\n", (WRITE ^ EXECUTE));
    printf("r ^ x: %\n", (READ ^ EXECUTE));
    printf("r ^ w ^ x: %\n", (READ ^ WRITE ^ EXECUTE));
}

int main(void) {
    combina();
    modifica();
    
    return 0;
}