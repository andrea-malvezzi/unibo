#include <iostream>

#define MAX 20

struct Node {
    int value;
    Node* next;
};
typedef Node *pnode;

// memory_friendly function to swap two variables
void swap(int &item_1, int &item_2) {
    item_1 += item_2;
    item_2 = item_1 - item_2;
    item_1 -= item_2;
}

// sorts an array of integers. The sorting order is
// specified via boolean parameter.
// data[] -> the array to sort.
// data_size -> the length of the array.
// ascending -> true means that the array will be sorted with an ascending approach, and false means the opposite.
void sort_array(int data[], const int data_size, const bool ascending) {
    for (int i = 0; i < data_size; i++) {
        for (int j = 0; j < data_size - i - 1; j++) {
            if (ascending) {
                if (data[j] > data[j+1])
                    swap(data[j], data[j+1]);
            } else
                if (data[j] < data[j+1])
                    swap(data[j], data[j+1]);
        }
    }
}

// deletes a list to free up memory
void free_memory(pnode root) {
    pnode current = root;
    while (root != NULL) {
        root = root -> next;
        delete current;
        current = root;
    }
}

int main() {
    // setup
    int values[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 19, 11, 18, 12, 17, 13, 16, 14, 15, 20};
    pnode head = new Node;
    pnode current = head;
    for(int i = 0; i < MAX-1; i++) {
        current -> next = new Node;
        current = current -> next;
        current -> value = values[i+1];
    }

    // sorting here
    std::cout << "Array in partenza:" << std::endl;
    for (int i = 0; i < MAX; i++)
        std::cout << values[i] << ' ';
    std::cout << std::endl;

    sort_array(values, MAX, true);
    std::cout << "Array ordinato in ordine crescente:" << std::endl;
    for (int i = 0; i < MAX; i++)
        std::cout << values[i] << ' ';
    std::cout << std::endl;

    sort_array(values, MAX, false);
    std::cout << "Array ordinato in ordine decrescente:" << std::endl;
    for (int i = 0; i < MAX; i++)
        std::cout << values[i] << ' ';
    std::cout << std::endl;

    // libera memoria
    free_memory(head);

    return 0;
}
