#include <iostream>

#define MAX 10

struct Stack {
    int data[MAX];
    int size;       // numero elemento dello Stack
};

void init(Stack &stack) {
    stack.size = 0;
}

void push(Stack &stack, int elem) {
    if (stack.size >= MAX) {
        std::cout  << "Stack pieno.\n";
    } else {
        stack.data[stack.size] = elem;
        stack.size++;
    }
}

void pop(Stack &stack) {
    if (stack.size <= 0) {
        std::cout << "Stack vuoto.\n";
    } else {
        stack.data[stack.size - 1] = -1;
        stack.size--;
    }
}

int top(Stack &stack) {
    if (stack.size <= 0) {
        std::cout << "Stack vuoto.\n";
        return -1;
    }
    return stack.data[stack.size-1];
}

void print_stack(Stack stack) {
    for (int i = 0; i < stack.size; i++)
        std::cout << i << "-esimo elemento dello stack: " << stack.data[i] << '\n';

    std::cout << "Fine stack.\n";
}

int main() {
    // Setup stack
    Stack stack;
    init(stack);

    push(stack, 1);
    push(stack, 10);
    push(stack, 20);
    pop(stack);

    print_stack(stack);
    int topElement = top(stack);
    std::cout << "Elemento in cima allo stack: " << topElement << std::endl;

    return 0;
}
