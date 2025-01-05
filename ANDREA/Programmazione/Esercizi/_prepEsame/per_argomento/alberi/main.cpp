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

// BT

void add_value(const pnodo root, const int val) {

}

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

// albero bilanciato = tutti i nodi hanno o 2 figli o 0.
bool is_balanced(const pnodo root) {
    // if (node_count(root) % 2 == 0) return false;
    bool leftCheck;
    bool rightCheck;
    if (root -> left != NULL && root -> right != NULL) {
        leftCheck = is_balanced(root -> left);
        rightCheck = is_balanced(root -> right);
    }
    else if (root -> right == NULL && root -> left == NULL) return true;
    else return false;

    return leftCheck && rightCheck;
}

// BST

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
    std::cout << "L'albero contiene il valore " << valueToBeSearched << "? ";
    const bool findCheck = find_value(newNodo, valueToBeSearched);
    findCheck ? std::cout << 'y' << std::endl : std::cout << 'n' << std::endl;

    std::cout << "Albero bilanciato? ";
    const bool balancedCheck = is_balanced(newNodo);
    balancedCheck ? std::cout << 'y' << std::endl : std::cout << 'n' << std::endl;

    std::cout << "Test bilanciato positivo: ";
    const bool balancePositiveCheck = is_balanced(testNodo);
    balancePositiveCheck ? std::cout << 'y' << std::endl : std::cout << 'n' << std::endl;



    deleteTree(newNodo);
    deleteTree(testNodo);
    return 0;
}
