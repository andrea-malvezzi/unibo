#include <iostream>

#define MAX 5

// head: dove gli item escono (arriva il turno di una persona)
// back: dove gli item entrano (una persona si mette in fila)
struct Queue {
    int data[MAX];
    int head;       // Indice del primo elemento della coda
    int size;       // Numero di elementi nella coda
};

void init(Queue &queue) {
    queue.head = 0;
    queue.size = 0;
}

// Ritorna se una coda è vuota o meno
bool empty(const Queue &queue) {
    return queue.size == 0;
}

// Ritorna se una coda è piena o meno
bool full(const Queue &queue) {
    return queue.size == MAX;
}

// Restituisce il primo elemento di una coda
int front(const Queue &queue) {
    if (queue.size == 0) {
        std::cout << "La coda non contiene elementi.\n";
        return -1;
    }

    return queue.data[queue.head];
}

// Restituisce ultimo elemento di una coda
int back(const Queue &queue) {
    if (queue.size == 0) {
        std::cout << "La coda non contiene elementi.\n";
        return -1;
    }

    // Primo elemento index 1, con 3 elementi totali: posizione 4 - 1, quindi 3!
    const int backIndex = queue.head + queue.size - 1;
    return queue.data[backIndex];
}

// Aggiunge elemento in fondo alla coda
void enqueue(Queue &queue, int elem) {
    if (queue.head + queue.size == MAX)
        std::cout << "La coda contiene il massimo di elementi concessi.\n";
    else {
        int backIndex = queue.head + queue.size;
        queue.data[backIndex] = elem;
        queue.size++;
    }
}

// Rimuove elemento dalla cima della coda
void dequeue(Queue &queue) {
    if (queue.size == 0)
        std::cout << "La coda non contiene elementi.\n";
    else {
        queue.data[queue.head] = -1;
        queue.head++;
        queue.size--;
    }
}

// Stampa tutti gli elementi in una coda
void printQueue(const Queue &queue) {
    int nextIndex = queue.head;
    for (int i = 0; i < queue.size; i++) {
        nextIndex++;
        std::cout << nextIndex << "-esimo elemento della coda:" << queue.data[nextIndex] << "\n";
    }
}

int main() {
    Queue queue{};
    init(queue);

    // Riempio la coda
    for(int i = 0; i < 4; i++)
        enqueue(queue, i);

    // Stampo la coda
    printQueue(queue);

    std::cout << '\n';

    // Rimuovo primo elemento dalla coda
    dequeue(queue);
    // Ristampo la coda
    printQueue(queue);

    // Chiudo writing stream
    std::cout << std::endl;
    return 0;
}
