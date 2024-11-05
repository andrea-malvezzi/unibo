#include <iostream>
using namespace std;

/* Scambia il valore di due variabili passandole per reference (reference = puoi modificare nella funzione le variabili stesse passate come parametro) */
void scambia (int& x, int&y) {
    const int tmp = x;
    x = y;
    y = tmp;
}

/*
 * L'idea alla base del selection sort è lo scambio tra l'i-esimo membro di una struttura dati
 * con un altro, minore (o maggiore, con i dovuti cambiamenti) di esso,
 * dopo aver analizzato tutti i membri della data struttura.
 * Occorreranno quindi due loop:
 * uno per muovermi di membro in membro (i-esimo membro) e
 * uno per analizzare tutti i membri da quel punto in avanti per trovare un valore
 * con cui scambiare il primo (j-esimo membro).
 * Ogni volta che si trova un valore minore di quello preso in partenza,
 * occorrerà salvarne l'indice in una variabile (min nel nostro caso).
 * Dopo aver effettuato questa analisi e prima del passare al membro successivo,
 * occorre scambiare, mediante indici, i due valori trovati (scambio i-esimo e min-esimo membro).
 */
void selection_sort(int numbers[], const int length) {
    int min;

    for (int i = 0; i < length; i++) {
        min = i;
        for (int j = i + 1; j < length; j++) {
            if (numbers[min] > numbers[j])
                min = j;
        }
        scambia(numbers[i], numbers[min]);
    }
}

int main() {
    // Fisso una lunghezza con cui inizializzare l'array
    constexpr int LENGTH = 10;

    // L'array NON DEVE essere inizializzato come const, altrimenti non potremmo modificarne i valori nell'algoritmo!
    int numbers[LENGTH] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    cout << "Dimostrazione Selection Sort:" << endl;

    cout << "Array non ordinato:" << endl;
    // Uso un foreach per scrivere tutti gli elementi di numbers (per ogni number in numbers, fai...)
    for (const int number: numbers) {
        cout << number << ' ';
    }
    cout << endl;

    cout << "Array ordinato:" << endl;
    selection_sort(numbers, LENGTH);

    for (const int number: numbers) {
        cout << number << ' ';
    }
    cout << endl;

    return 0;
}
