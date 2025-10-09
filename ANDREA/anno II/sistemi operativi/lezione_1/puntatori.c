#include <stdio.h>
#include <stdlib.h>

void stampaValori_1() {
    int var = 1;
    int* pvar = &var;

    printf("Valore var (usando la variabile): %d\n", var);
    printf("Indirizzo var (usando la variabile): %p\n", &var);

    printf("Valore var (usando il puntatore): %d\n", *pvar);
    printf("Valore puntatore: %d\n", pvar);
}

void swap_2(int* a, int* b) {
    printf("Valore a (prima dello swap): %d\n", *a);
    printf("Valore b (prima dello swap): %d\n", *b);
    
    int temp = *a;
    *a = *b;
    *b = temp;

    printf("Valore a (dopo lo swap): %d\n", *a);
    printf("Valore b (dopo lo swap): %d\n", *b);
}

int* genera_array_3(int n) {
    // calloc([n], [size]) => prepara [n] slot in memoria grandi [size] e ritorna un puntatore al primo di essi.
    // Per muoversi tra queste celle basta usare +/-.
    // Ognuno di questi slot viene inizializzato a 0.
    int* p = calloc(n, sizeof(int));
    return p;
}

int** genera_matrice_4(int n, int m) {
    // invece di * uso ** perché voglio puntare ad un array di puntatori ad int, non ad un array di int.
    int** p_matrice = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) p_matrice[i] = genera_array_3(m);

    return p_matrice;
}

// in C struct NON fa il typedef come in cpp, quindi dovrei ripetere ogni volta struct davanti a Node.
// Con typedef evito questa cosa, basta ricordarsi di mettere il nome corretto dopo la graffa di chiusura.
typedef struct Node {
    int value;
    // qui serve ancora lo struct davanti a Node perché la definizione viene completata nella riga dopo
    struct Node* next;
} Node;

// TODO: Add following methods
// insert head
// print list
// free list

int main(void) {
    printf("---------- INIZIO TEST ----------\n\n");

    stampaValori_1();

    printf("\n");

    int a = 5;
    int b = 10;
    swap_2(&a, &b);

    printf("\n");

    int* array = genera_array_3(b);
    for (int i = 0; i < b; i++) printf("Slot %d: %d\n", i, array[i]);

    printf("\n");

    int** matrice = genera_matrice_4(a, b);

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) printf("%d", matrice[i][j]);
        printf("\n");
    }
    

    return 0;
}