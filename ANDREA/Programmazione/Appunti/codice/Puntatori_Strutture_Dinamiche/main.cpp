#include <iostream>

struct Nodo{
    int value;
    Nodo *next;
};

Nodo* init_lista(){
    Nodo *nodo = new Nodo;
    nodo->next = nullptr;
    return nodo;
}

void add_item(Nodo *head, const int value){
    while(head -> next != nullptr)
        head = head -> next;

    head -> next = new Nodo;
    (head -> next) -> value = value;
    (head -> next) -> next = nullptr;
}

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

void empty(Nodo *&head){
    while(head != nullptr)
    {
        Nodo *temp = head;
        head = head -> next;
        delete temp;
    }
}

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
    return 0;
}
