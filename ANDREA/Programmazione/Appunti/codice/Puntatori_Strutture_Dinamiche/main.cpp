#include <iostream>

// un nodo corrisponde a un elemento della lista.
// Il primo nodo di una lista si dice head
struct Nodo{
    int value;
    Nodo *next;     // punta al prossimo nodo
};

// crea un puntatore rivolto verso un nodo senza valore e con un puntatore vuoto (un head)
// e lo ritorna
Nodo* init_lista(){
    Nodo *nodo = new Nodo;
    nodo->next = nullptr;
    return nodo;
}

// ritorna vero se la lista è vuota
// (se l'head passata come parametro corrisponde a un puntatore vuoto-null).
bool is_empty(const Nodo *head){
    return head == nullptr;
}

// aggiunge un item alla fine della lista
void add_item(Nodo *head, const int value){
    while(head -> next != nullptr)
        head = head -> next;

    head -> next = new Nodo;
    (head -> next) -> value = value;
    (head -> next) -> next = nullptr;
}

// aggiunge un item in una certa posizione della lista specificata
// tramite index (partendo da 0 come negli array)
void insert_at(Nodo *&head, const int value, const int index){
    if(index == 0){
        Nodo *currentHead = head;
        head = new Nodo;
        head -> value = value;
        head -> next = currentHead;
        return;
    }

    if(index < 0){
        std::cerr << "Errore: index out of bounds" << std::endl;    // come usare cout, ma fancy
        return;
    }

    Nodo *current = head;
    int currentIndex = 0;

    while(current != nullptr){
        // inserisco a index 3, quindi il quarto elemento, quindi {n, n, n, QUI, n}
        if(currentIndex == index - 1){
            Nodo *nextNode = current -> next;
            current -> next = new Nodo;
            current -> next -> value = value;
            current -> next -> next = nextNode;

            return;
        }

        if(currentIndex > index){
            std::cerr << "Errore: index out of bounds" << std::endl;
            return;
        }

        current = current -> next;
        currentIndex++;
    }

}

// elimina tutti i nodi della lista per evitare i memory leaks
void empty(Nodo *&head){
    while(head != nullptr)
    {
        Nodo *temp = head;
        head = head -> next;
        delete temp;
    }
}

// elimina il primo Nodo della lista e sposta head al Nodo successivo ad esso
int delete_first(Nodo *&head) {
    if (head == nullptr) return -1;

    // punto alla head passata alla funzione
    const Nodo *temp = head;
    // ho passato head per reference, quindi così modifico il next dell'head passato alla funzione
    head = head -> next;

    // cancello la head originale, a cui sta ancora puntando *temp;
    delete temp;

    // così posso checkare il risultato, se 1 allora ok, altrimenti ...
    return 1;
}

// elimina il Nodo in posizione [index]
int delete_at(Nodo *head, int index) {
    if (head == nullptr) return -1;

    Nodo *current;
    // itero fino a che il nodo successivo non è l'[index]-esimo
    while(head -> next != nullptr && index != 0) {
        current = head;
        head = head -> next;
        index--;
    }

    Nodo *nextNode = nullptr;
    if(head -> next != nullptr)
        nextNode = head -> next;
    delete head;
    current -> next = nextNode;

    return 1;
}

// elimina l'ultimo Nodo della lista
int delete_last(Nodo *head) {
    if (head == nullptr) return -1;

    Nodo *current = head;

    // altro modo per iterare fino alla fine, con una variabile in meno
    // controllo che tra due nodi non finisca la lista
    while(current -> next -> next != nullptr) {
        // il nodo corrente diviene quello successivo
        current = current -> next;
    }

    // cancello il nodo successivo (quello che ha fatto uscire dal loop, avendo successivo null)
    delete current -> next;

    // non sono sicuro sia necessario ma better safe then sorry
    current -> next = nullptr;
    return 1;
}

// stampa tutti i valori contenuti nella lista
void print(const Nodo *head){
    while(head != nullptr){
        std::cout << head -> value << std::endl;
        head = head -> next;
    }
}

int main(){
    Nodo *head = init_lista();
    head -> value = 0;

    add_item(head, 10);
    add_item(head, 20);
    add_item(head, 40);

    print(head);

    std::cout << std::endl << "Inserting at index 3:" << std::endl;
    insert_at(head, 30, 3);
    print(head);

    std::cout << std::endl << "Deleting at index 1:" << std::endl;
    delete_at(head, 1);
    print(head);

    std::cout << std::endl << "Deleting first elem:" << std::endl;
    delete_first(head);
    print(head);

    std::cout << std::endl << "Deleting last elem:" << std::endl;
    // delete_at(head, length-1) se si ha length, altrimenti occorre implementare delete_last
    delete_last(head);
    print(head);

    std::cout << std::endl << "Emptying list:" << std::endl;
    empty(head);
    std::cout << "Lista vuota: " << is_empty(head) << std::endl;
    return 0;
}