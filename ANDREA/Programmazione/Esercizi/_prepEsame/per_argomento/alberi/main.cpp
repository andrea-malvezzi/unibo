#include <iostream>

// setup

struct nodo {
    int val;
    nodo *right;
    nodo *left;
};

typedef nodo* pnodo;

pnodo makeNodo(const int val) {
    pnodo newNodo = new nodo;
    newNodo -> val = val;
    newNodo -> right = NULL;
    newNodo -> left = NULL;
    return newNodo;
}

void deleteTree(pnodo root) {
    if (root == NULL) return;
    deleteTree(root -> left);
    deleteTree(root -> right);
    delete root;
}

// esercizi
// restituisce la max depth dell'albero
int max_depth(const pnodo root) {
    if (root == NULL) return 0;
    const int max_left = 1 + max_depth(root -> left);
    const int max_right = 1 + max_depth(root -> right);
    return max_left > max_right ? max_left : max_right;
}

// restituisce il numero di nodi presenti in un albero
int node_count(const pnodo root) {
    if (root == NULL) return 0;
    const int right = node_count(root -> right);
    const int left = node_count(root -> left);
    return left + right + 1;
}

// ricerca di un valore in un albero non ordinato
bool find_value(const pnodo root, const int val) {
    if (root == NULL) return false;
    if (root -> val == val) return true;
    const bool leftCheck = find_value(root -> left, val);
    const bool rightCheck = find_value(root -> right, val);
    return leftCheck || rightCheck;
}



int main() {
    auto newNodo = makeNodo(1);
    newNodo -> right = makeNodo(10);
    newNodo -> right -> right = makeNodo(100);
    newNodo -> left = makeNodo(2);
    newNodo -> left -> left = makeNodo(3);
    newNodo -> left -> left -> left = makeNodo(4);

    const auto testNodo = makeNodo(1);

    const int maxDepth = max_depth(newNodo);
    std::cout << maxDepth << std::endl;

    const int totalNodes = node_count(testNodo);
    std::cout << totalNodes << std::endl;

    const int valueToBeSearched = 10;
    std::cout << "L'albero contiene il valore " << valueToBeSearched << '?' << std::endl;
    const bool findCheck = find_value(newNodo, valueToBeSearched);
    findCheck ? std::cout << 'y' << std::endl : std::cout << 'n' << std::endl;

    deleteTree(newNodo);
    deleteTree(testNodo);
    return 0;
}
