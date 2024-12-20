#include <iostream>
#include <ctime>

// alberi!

struct Btree {
    int data;
    Btree *left;
    Btree *right;
};

// bst functions
// binary search tree (valori minori a sx, maggiori a dx)

// crea un nuovo nodo per il BST e lo ritorna
Btree* prepareNode() {
    auto *newNode = new Btree;
    newNode -> left = nullptr;
    newNode -> right = nullptr;
    return newNode;
}

// inserisce un valore nell'albero:
// - se il nodo corrente non ha valore, imposta data pari al valore passato
// - se il valore è già presente, stampa un messaggio apposito
// - se il valore è minore di quello del nodo attuale, si sposta in basso a sx e richiama se stessa
// - se il valore è maggiore di quello del nodo attuale, si sposta in basso a dx e richiama se stessa
void insertBST(Btree *&tree, const int value){
    // nodo non esiste -> creo nodo -> metto valore -> sx e dx nullptr
    if (tree == nullptr) {
        tree = prepareNode();
        tree -> data = value;
        return;
    }

    const int currentValue = tree -> data;
    if (value < currentValue) {
        insertBST(tree -> left, value);
    } else if (value > currentValue) {
        insertBST(tree -> right, value);
    } else {
        std::cout << "Value already in the tree." << std::endl;
    }
}

// stampa i valori del BST in ordine crescente.
// Questo approcio si dice "attraversamento per ordine infisso":
// - prima tutto il ramo di sinistra
// - poi la radice
// - infine tutto il ramo di destra
void traverseTree(const Btree *tree) {
    // equivale a fare (tree == NULL) ...
    if (!tree) return;
    traverseTree(tree -> left);
    std::cout << tree -> data << ' ';
    traverseTree(tree -> right);
}

// std Tree functions

// inizializza l'albero e lo prepara ad essere utilizzato
Btree* initTree(int depth) {
    if (depth == 0) return(NULL);
    auto* tree = new Btree;
    tree -> data = rand() % 50;
    depth--;
    tree -> right = initTree(depth);
    tree -> left = initTree(depth);
    return tree;
}

// versione del prof per stampare il contenuto
// dell'albero binario (bruttina)
void visit(const Btree* tree) {
    if (tree != NULL) {
        std::cout << tree -> data;
        visit(tree -> left);
        visit(tree -> right);
    }
}

// mia version per pretty print
// (fa cagare uguale, ci son tools apposta)
void printTree(const Btree *tree, const int depth=1, const int orientation=0) {
    if (tree == NULL) return;
    switch(orientation) {
        case 0:
            std::cout << "root: " << tree -> data << std::endl;
        case 1:
            std::cout << "right " << depth << ": " << tree -> data << std::endl;
        case 2:
            std::cout << "left " << depth << ": " << tree -> data << std::endl;
    }

    printTree(tree -> left, depth + 1, 2);
    printTree(tree -> right, depth + 1, 1);
}

// esegue il delete dei nodi dell'albero passato per
// evitare memory leaks
void clearMemory(const Btree* tree) {
    if (tree == NULL) return;
    clearMemory(tree -> left);
    clearMemory(tree -> right);
    delete tree;
}

int main() {
    srand(time(NULL));
    const Btree* stdTree = initTree(5);
    Btree* bst = nullptr;

    /* for(int i = 0; i < 5; i++)
        insertBST(bst, rand() % 100);
    */

    for (int i = 1; i <= 10; i++) {
        int value;
        std::cout << "Enter value: ";
        std::cin >> value;
        std::cout << std::endl;
        insertBST(bst, value);
    }

    // printTree(stdTree);
    // visit(tree);
    traverseTree(bst);

    clearMemory(stdTree);
    clearMemory(bst);
    return 0;
}
