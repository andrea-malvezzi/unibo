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
        if(currentIndex == index){
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

    std::cout << std::endl;
    insert_at(head, 30, 2);
    print(head);

    empty(head);
    std::cout << "Lista vuota: " << is_empty(head) << std::endl;
    return 0;
}