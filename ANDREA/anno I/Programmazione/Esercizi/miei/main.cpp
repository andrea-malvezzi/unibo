#include <iostream>

struct Node {
    int value;
    Node *left;
    Node *right;
};
typedef Node *pnode;

struct Queue {
    int level[];
    Queue *next;
};
typedef Queue *pqueue;

// controllo depth
//      se ci son tot elementi, aggiungo all'array
//      altrimenti aggiungo array + elemento
void traverse_and_print(const pnode root, pqueue levels, int queue_length=0, int level_index=0, const int depth=0) {
    pqueue current = levels;
    if (queue_length >= depth) {
        for (int i = 0; i < depth; i++)
            current = current -> next;
        current -> level[level_index] = root -> value;
    }

    // printing part
    current = levels;
    while (current -> next != NULL) {
        int *level_index_ptr = current -> level;
        while(level_index_ptr != NULL) {
            std::cout << *level_index_ptr << ' ';
        }
        std::cout << std::endl;
    }
}

int main() {
    pqueue levels = new Queue;
    levels -> level[10];

    pnode root = new Node;
    root -> left = new Node;
    root -> right = new Node;

    root -> value = 1;
    root -> left -> value = 2;
    root -> right -> value = 3;

    traverse_and_print(root, levels);

    return 0;
}
