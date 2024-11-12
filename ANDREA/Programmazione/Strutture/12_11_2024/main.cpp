#include <iostream>
using namespace std;

struct Node {
    int value;
    int next;
};

void stampa(Node A[], const int length) {
    int nextIndex = 0;
    Node currentNode;

    do {
        currentNode = A[nextIndex];
        cout << "Node at index " << nextIndex << " has value of " << currentNode.value << endl;
        nextIndex = currentNode.next;
    } while (nextIndex != -1);
}

// usando una variabile temp, salvo il valore di next del nodo corrente
// posiziono il nodo corrente nel nuovo array, al suo posto
// 0 1 2 3 4
// 4 3 2 1 0
// 0   1   2
// 2   1   0
// 0     1
// 1     0
// 0 1 2 3
// 3 2 1 0
void revert(Node A[], const int length) {
    Node newArray[length];
    int nextIndex = 0;
    // Si suppone che ad indice 0 si abbia la Head
    do {
        // TODO
    } while (nextIndex != -1);

    stampa(newArray, length);
}

int main() {
    constexpr int length = 5;
    Node testArray[length];
    Node head;
    head.value = 0;
    head.next = 2;

    Node end;
    end.value = 1;
    end.next = -1;
    testArray[0] = head;
    testArray[head.next] = end;

    stampa(testArray, length);
    revert(testArray, length);

}
