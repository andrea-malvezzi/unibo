#include <iostream>

/* es.1
 * scrivere una funzione che prende in input un array di interi non ordinato e la sua lunghezza
 * (ed eventualmente altri parametri a scelta) e ritorna il maggior numero di occorrenze di un intero nell'array.
 * Si possono usare funzioni ausiliarie.
 * NOTA PERSONALE: il testo non dice di fare una funzione ricorsiva.
 * Io la faccio ricorsiva dato che la soluzione iterativa sarebbe banale e non la chiede spesso.
*/

int conta(const int searching, const int A[], const int size, int count=0) {
    if (size == 0) return count;
    if (A[0] == searching)
        count++;
    return conta(searching, A + 1, size - 1, count);
}

int max_occorrenze(const int A[], const int size, const int prev=0) {
    // edge cases
    if (size <= 0) return prev;

    // struttura normale
    int count = conta(A[0], A, size);
    if (count < prev)
        count = prev;
    return max_occorrenze(A + 1, size - 1, count);
}

/* es.2
 * crea la struttura dati per gestire BST e BST invertiti (a sx i maggiori e dx i minori).
 * Serviranno anche le liste per le funzioni.
*/

struct List_Node {
    int value;
    List_Node* next;
};

struct Tree_Node {
    int value;
    Tree_Node* left;
    Tree_Node* right;
};

typedef List_Node* plist;
typedef Tree_Node* ptree;

/*
 * definisci le seguenti funzioni:
 *
 * create_tree: prende come parametri un albero binario di ricerca e una lista di interi
 * e inserisce gli elementi della lista nell'albero.
 *
 * facimm_ammuina: inverte un albero (maggiori a sx e minori a dx)
 *
 * max_depth: fa esattamente quello che dice il nome.
*/

void add_node(ptree& node, const int value) {
    // edge cases
    if (node == NULL) {
        node = new Tree_Node;
        node -> value = value;
        node -> right = NULL;
        node -> left = NULL;
        return;
    }

    if (value == node -> value)
        return;
    if (value < node -> value)
        add_node(node -> left, value);
    if (value > node -> value)
        add_node(node -> right, value);
}

void create_tree(ptree& node, plist list) {
    if (list == NULL) return;
    while (list != NULL) {
        add_node(node, list -> value);
        list = list -> next;
    }
}

void facimm_ammuina(const ptree head) {
    // edge case
    if (head == NULL) return;

    const ptree temp = head -> left;
    head -> left = head -> right;
    head -> right = temp;

    facimm_ammuina(head -> left);
    facimm_ammuina(head -> right);
}

int max_depth(const ptree head) {
    if (head == NULL) return 0;

    const int left = 1 + max_depth(head -> left);
    const int right = 1 + max_depth(head -> right);

    return left > right ? left : right;
};

// DEBUG ONLY
void scrivi_primi_livelli(const ptree head) {
    if (head == NULL) return;
    std::cout << head -> value << std::endl;
    std::cout << head -> left -> value << ' ' << head -> right -> value << std::endl;
}

// DEBUG ONLY
void clear_tree(const ptree head) {
    if (head == NULL) return;
    const ptree temp = head;
    clear_tree(head -> left);
    clear_tree(head -> right);
    delete temp;
}

// DEBUG ONLY
void clear_list(const plist head) {
    if (head == NULL) return;
    const plist temp = head;
    clear_list(head -> next);
    delete temp;
}

int main() {
    // test es.1: OK
    const int A[] = {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
    const int count = max_occorrenze(A, 10);
    std::cout << count << std::endl;

    // test es.2: OK
    plist head_l = new List_Node;
    head_l -> value = 10;
    head_l -> next = new List_Node;
    head_l -> next -> value = 5;
    head_l -> next -> next = new List_Node;
    head_l -> next -> next -> value = 15;
    head_l -> next -> next -> next = new List_Node;
    head_l -> next -> next -> next -> value = 20;
    head_l -> next -> next -> next -> next = new List_Node;
    head_l -> next -> next -> next -> next -> value = 25;
    head_l -> next -> next -> next -> next -> next = new List_Node;
    head_l -> next -> next -> next -> next -> next -> value = -1;
    head_l -> next -> next -> next -> next -> next -> next = new List_Node;
    head_l -> next -> next -> next -> next -> next -> next -> value = 4;
    head_l -> next -> next -> next -> next -> next -> next -> next = new List_Node;
    head_l -> next -> next -> next -> next -> next -> next -> next -> value = 18;
    head_l -> next -> next -> next -> next -> next -> next -> next -> next = new List_Node;
    head_l -> next -> next -> next -> next -> next -> next -> next -> next -> value = 19;
    head_l -> next -> next -> next -> next -> next -> next -> next -> next -> next = NULL;

    ptree head_t = NULL;
    create_tree(head_t, head_l);         // ok!

    scrivi_primi_livelli(head_t);
    facimm_ammuina(head_t);                 // ok!
    scrivi_primi_livelli(head_t);

    const int depth = max_depth(head_t);    // ok!
    std::cout << "Altezza massima albero binario fornito: " << depth << '.' << std::endl;

    clear_tree(head_t);
    clear_list(head_l);

    // es.3 non ho voglia di fare sta classe ew
    return 0;
}
