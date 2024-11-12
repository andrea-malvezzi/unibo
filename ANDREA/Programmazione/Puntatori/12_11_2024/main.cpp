#include <iostream>
using namespace std;

// ecco perché nei cicli è meglio assegnare e basta i valori alle variabili,
// invece di ri-inizializzarle ad ogni iterazione. Uso meno celle di memoria,
// cambiando solamente il valore di una di esse
void demonstrate_memory_leak() {
    int *p;
    p = new int;
    cout << "*p is pointing at " << *p << endl;
    cout << "p has value of " << p << endl;
    p = new int;
    cout << "*p is pointing at " << *p << endl;
    cout << "p has value of " << p << endl;
}

void demonstrate_operators() {
    // Un intero con valore 10
    int x = 10;

    // Il simbolo & davanti ad una variabile ne estrae l'indirizzo
    // int *p = &5 sarebbe errore, in quanto 5 non è una variabile o comunque qualcosa salvato in memoria
    int *pointer_x = &x;

    int *new_pointer = new int;

    // Il comando Delete "libera" la cella di memoria corrispondente a "new_pointer":
    // cancellerà il suo valore, quindi non punterà più a x.
    // La variabile x tuttavia rimarrà invariata: questo serve solo a rilasciare memoria.
    // QUESTO SI USA SOLAMENTE ABBINATO AD UN'INIZIALIZZAZIONE TRAMITE NEW, ALTRIMENTI DA ERRORE.
    delete new_pointer;
}

void demonstrate_aliasing() {
    int *p, *q;
    int x = 1;

    p = &x;                         // p copia il valore dell'indirizzo dov'è contenuto in x
    // avendo passato per reference (&) l'indirizzo di x a p, modificando p modificherò x
    *p = 2;                         // ciò che si trova all'indirizzo salvato in *p pari a 2: p = 2
    // ora x è 2, vedi il commento sotto a p = &x
    cout << "p*: " << *p << endl;   // scrivo ciò che si trova all'indirizzo salvato in *p
    cout << "x: " << x << endl;     // scrivo la variabile x

    q = p;                          // q = 2
    *q = 1;                         // ciò che si trova all'indirizzo di memoria salvato in *q, pari ad 1: q = 1
    cout << "q*: " << *q << endl;   // scrivo ciò che si trova all'indirizzo q*: q = 1
    cout << "x: " << x << endl;     // scrivo la variabile x
}

int main() {
    demonstrate_aliasing();
    return 0;
}
