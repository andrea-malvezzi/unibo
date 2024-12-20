#include <iostream>

struct Node{
    int value;
    Node* next;
};

void write_vertical_rec(const int n) {
    if(n == 0) return;
    std::cout << n << std::endl;
    write_vertical_rec(n-1);
}

void write_vertical_iter(const int n) {
    for (int i = 0; i < n; i++)
        std::cout << n-i << std::endl;
}

void stampa_lista_interi(const Node* head) {
    std::cout << head -> value << ' ';
    // fino a che il prossimo del prossimo è non null, richiama
    // [1] [2] [3] [4] [5], [5] è nullptr, quindi a 4 mi fermo
    if (head -> next -> next != nullptr)
        stampa_lista_interi(head -> next);
}

void write_vertical_rec_inv(const int n) {
    if(n < 10) std::cout << n << std::endl;
    else {
        std::cout << n%10 << std::endl;
        write_vertical_rec_inv(n/10);
    }
}

Node* genera_lista_rec(const int n) {
    if(n == 0) {
        Node* last = new Node;
        last -> value = n;
        last -> next = nullptr;
        return last;
    };
    Node* head = new Node;
    head -> value = n;
    head -> next = genera_lista_rec(n-1);
    return head;
}

Node* genera_lista_crescente_rec(const int n, const int substract=0) {
    if(n == 0) {
        Node* last = new Node;
        last -> value = n;
        last -> next = nullptr;
        return last;
    };
    Node* head = new Node;
    head -> value = n-(n-substract);
    head -> next = genera_lista_crescente_rec(n-1, substract+1);
    return head;
}

void genera_lista(Node* head) {
    for (int i = 0; i < 10; i++) {
        head -> value = i;
        head -> next = new Node;
        head = head -> next;
        if(i == 9) head -> next = nullptr;
    }
}

void svuota_lista(Node* head) {
    Node* temp;
    while(head -> next != nullptr) {
        temp = head;
        head = head -> next;
        delete temp;
    }
}

int main() {
    /* std::cout << "Iterativamente: " << std::endl;
    write_vertical_iter(5);

    std::cout << std::endl;

    std::cout << "Ricorsivamente: " << std::endl;
    write_vertical_rec(5); */
    Node* head = new Node;
    head -> next = nullptr;
    genera_lista(head);

    // operazioni
    stampa_lista_interi(head);
    std::cout << std::endl;
    write_vertical_rec_inv(123);
    std::cout << std::endl;
    Node* newHead = genera_lista_rec(10);
    stampa_lista_interi(newHead);
    std::cout << std::endl;
    Node* headCrescente = genera_lista_crescente_rec(10);
    stampa_lista_interi(headCrescente);

    // evita memory leaks
    svuota_lista(head);
    svuota_lista(newHead);
    svuota_lista(headCrescente);
    return 0;
}
