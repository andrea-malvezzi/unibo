#include <iostream>

struct Nodo {
    int valore;
    Nodo *next;
};

void crivello_eratostene(Nodo *head) {
    if (head == nullptr) return;

    // itera ogni elemento della lista
    Nodo *current = head;

    // itera a partire dal Nodo corrente per cercare multipli del valore corrente
    Nodo *valueIter = current;

    // copia l'iteratore nel caso in cui ci sia da cancellare un valore in quanto multiplo del current
    Nodo *temp = current;

    // quando cancello la copia di temp, prevNode -> next diventa il nodo successivo a quello cancellato
    // non serve un nextNode in quanto sposteremo temp al Nodo successivo (scelta di implementazione)
    Nodo *prevNode = temp;

    // il valore di current
    int current_val;

    while(current -> next != nullptr) {
        // imposto il valore corrente
        current_val = current -> valore;

        
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
