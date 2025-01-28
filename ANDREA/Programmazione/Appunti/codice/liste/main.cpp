#include <iostream>

struct Nodo {
    int value;
    Nodo* next;
};
typedef Nodo* pnodo;

// ok!
pnodo insert(pnodo head, const int value) {
    pnodo current = head;

    if (head == NULL) {
        pnodo newNode = new Nodo;
        newNode -> value = value;
        newNode -> next = NULL;
        head = newNode;
        return head;
    }

    while (current -> next != NULL) {
        current = current -> next;
    }

    pnodo newNode = new Nodo;
    newNode -> value = value;
    newNode -> next = NULL;
    current -> next = newNode;
    return head;
};

/*
 * cancella un solo elemento: no valori duplicati
 * se ci fossero duplicati, invece di ritornare dovrei continuare con il ciclo.
 * Ok!
*/
pnodo remove(pnodo head, const int value) {
    if (head == NULL) {
        return NULL;
    }

    pnodo current = head;
    pnodo prev = head;

    while (current != NULL) {
        if (current -> value == value) {
            // primo elemento
            if (prev == current) {
                head = current -> next;
                delete current;
                return head;
            }
            // non primo elemento
            prev -> next = current -> next;
            delete current;
            return head;
        }
        prev = current;
        current = current -> next;
    }

    return head;
}

// ok!
pnodo search(const pnodo head, const int value) {
    pnodo current = head;
    while (current != NULL) {
        if (current -> value == value)
            return current;
        current = current -> next;
    }
    return NULL;
}

// ok!
pnodo ordina(const pnodo head, const int flag) {
    // se flag >= 0, ordine crescente
    // flag < 0 decrescente
    pnodo current = head;
    pnodo interno = current;
    while (current != NULL) {
        interno = current;
        while (interno != NULL) {
            if (flag >= 0) {
                if (current -> value > interno -> value) {
                    const int temp = current -> value;
                    current -> value = interno -> value;
                    interno -> value = temp;
                }
            } else {
                if (current -> value < interno -> value) {
                    const int temp = current -> value;
                    current -> value = interno -> value;
                    interno -> value = temp;
                }
            }
            interno = interno -> next;
        }
        current = current -> next;
    }
    return head;
}

// ok!
void stampa(const pnodo head) {
    pnodo current = head;
    while(current != NULL) {
        std::cout << current -> value << std::endl;
        current = current -> next;
    }
}

// ok!
void pulisci(const pnodo head) {
    pnodo current = head;
    while (current != NULL) {
        pnodo temp = current;
        current = current -> next;
        delete temp;
    }
}

int main()
{
    // ricordati di mettere NULL al puntatore next dell'ultimo, altrimenti va all'infinito
    pnodo head = NULL;
    head = insert(head, 20);
    head = insert(head, 10);
    head = insert(head, 40);
    head = insert(head, 30);
    // head = remove(head, 20);
    // const pnodo found = search(head, 30);
    head = ordina(head, -1);
    // stampa(found);
    // std::cout << std::endl;
    stampa(head);
    head = ordina(head, 1);
    std::cout << std::endl;
    stampa(head);
    pulisci(head);
    return 0;
}
