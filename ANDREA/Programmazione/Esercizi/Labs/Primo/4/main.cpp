#include <iostream>

// Per pura comodità faccio una variabile globale
#define MAX 10

struct Stack {
    int data[MAX];
    int size;       // numero di elementi nello stack
};

void init(Stack &stack) {
    stack.size = 0;
}

// Aggiunge un elemento in cima (prima posizione libera) allo stack
void push(Stack &stack, int elem) {
    if(stack.size >= MAX)
        std::cout << "Stack pieno.\n";
    else {
        stack.data[stack.size] = elem;
        stack.size++;   // aggiungo 1 al counter degli elementi dello stack
    }
}

// Cancella un elemento in cima (ultima posizione occupata) allo stack
void pop(Stack &stack) {
    if(stack.size <= 0)
        std::cout << "Stack vuoto.\n";
    else {
        stack.size--;       // Un elemento in meno, abbasso il contatore
        stack.data[stack.size] = -1;
    }
}

// Per mostrare il risultato, non era richiesto
void stampaTop(Stack &stack) {
    if(stack.size <= 0)
        std::cout << "Stack vuoto.\n";
    else
        std::cout << "Ultimo elemento: " << stack.data[stack.size - 1] << '\n';
}

int main() {
    // Per ora fare Stack stack oppure Stack stack{} non fa differenza,
    // ma più avanti la cosa cambierà
    Stack stack{};
    init(stack);

    int result;
    char nextChar;
    bool quitFlag = false;

    // Si può semplificare con funzioni helper per il codice in comune
    // tra i vari casi dello switch, ma NOT TODAY HEHE
    while(!quitFlag) {
        std::cout << "Inserisci un numero oppure un operatore: \n";
        std::cin >> nextChar;
        switch(nextChar) {
            case 'q':
                quitFlag = true;
                break;
            case '=':
                stampaTop(stack);
                break;
            case '+':
                if (stack.size <= 1)
                    std::cout << "Inserire almeno due cifre prima di un operando.\n";
                else {
                    result = stack.data[stack.size - 1] + stack.data[stack.size - 2];
                    pop(stack);
                    pop(stack);
                    push(stack, result);
                }
                break;
            case '-':
                if (stack.size <= 1)
                    std::cout << "Inserire almeno due cifre prima di un operando.\n";
                else {
                    result = stack.data[stack.size - 2] - stack.data[stack.size - 1];
                    pop(stack);
                    pop(stack);
                    push(stack, result);
                }
                break;
            case '*':
                if (stack.size <= 1)
                    std::cout << "Inserire almeno due cifre prima di un operando.\n";
                else {
                    result = stack.data[stack.size - 1] * stack.data[stack.size - 2];
                    pop(stack);
                    pop(stack);
                    push(stack, result);
                }
                break;
            case '/':
                if (stack.size <= 1)
                    std::cout << "Inserire almeno due cifre prima di un operando.\n";
                else if (stack.data[stack.size - 1] == 0)
                    std::cout << "Il divisore corrisponde a zero. Divisione impossibile.\n";
                else {
                    result = stack.data[stack.size - 2] / stack.data[stack.size - 1];
                    pop(stack);
                    pop(stack);
                    push(stack, result);
                }
                break;
            default:
                push(stack, nextChar - '0');
        }
    }

    // Chiudo stream writing
    std::cout << std::endl;

    return 0;
}
