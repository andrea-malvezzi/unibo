#include <iostream>
#define MAX 6

int push(int A[], int size, int elem) {
    if (size >= MAX) {
        std::cout << "La pila contiene il massimo degli oggetti consentiti.\n";
        return -1;
    }

    A[size] = elem;
    // size++ ritorna e poi aumenta, ++size aumenta e poi ritorna,
    // size+1 ritorna sommando 1 alla variabile ma non la modifica.
    return size+1;
}

int pop(int A[], int size) {
    if (size <= 0) {
        std::cout << "La pila non contiene elementi.\n";
        return -1;
    }

    // placeholder value che indica che un elemento è vuoto
    A[size] = -1;
    return size-1;
}

int top(int A[], int size) {
    if (size <= 0) {
        std::cout << "La pila non contiene elementi.\n";
        return -1;
    }

    return A[size-1];
}

void stampaStack(int A[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << i << "-esimo elemento della pila: " << A[i] << '\n';

    std::cout << "Fine pila.\n";
}

int main() {
    int A[MAX];
    int length = 0;
    int topElem;

    length = push(A, length, 1);
    topElem = top(A, length);

    std::cout << "Elemento top dopo il push: " << topElem << '\n';

    length = pop(A, length);
    topElem = top(A, length);

    std::cout << "Elemento top dopo il pop: " << topElem << '\n';

    // sarebbe meglio aumentare direttamente nella funzione length, passandola per reference (&)? si.
    // Nell'esercizio c'è scritto di farlo? no. Questo mi rende felice? Still no. Ma va fatto così.
    length = push(A, length, 1);
    length = push(A, length, 10);
    length = push(A, length, 20);
    length = push(A, length, 30);
    length = push(A, length, 40);

    stampaStack(A, length);

    return 0;
}
