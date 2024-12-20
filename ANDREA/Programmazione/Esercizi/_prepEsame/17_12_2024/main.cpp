#include <iostream>

// Riceve in input l'array e la sua dimensione n, e restituisce il valore massimo contenuto nell'array
int trovaMassimo(const int arr[], const int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];
    return max;
}

// Riceve l'array e la sua dimensione, e restituisce il valore minimo contenuto nell'array.
int trovaMinimo(const int arr[], const int n) {
    int min = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] < min) min = arr[i];
    return min;
}

// Riceve l'array e la sua dimensione, e restituisce la media aritmetica
// dei valori contenuti nell'array (come double)
double calcolaMedia(const int arr[], const int n) {
    double mean = 0;
    for (int i = 0; i < n; i++)
        mean += arr[i];
    mean /= n;
    return mean;
}

// Riceve l'array e la sua dimensione, e inverte l'ordine
// dei suoi elementi in loco (modificando l'array originale)
void invertiArray(int arr[], const int n) {
    for (int i = 0; i < n/2; i++) {
        arr[i] += arr[n-(i+1)];
        arr[n-(i+1)] = arr[i] - arr[n-(i+1)];
        arr[i] -= arr[n-(i+1)];
    }
}

int main() {
    bool exitFlag = false;
    int size = 0;

    while(!exitFlag) {
        std::cout << "Inserisci un numero compreso tra 1 e 100 (estremi inclusi): " << std::endl;
        std::cin >> size;
        if (size <= 100 && size >= 1) exitFlag = true;
        else std::cout << "Input non valido." << std::endl;
    }

    int myArr[size];
    for (int i = 0; i < size; i++) {
        std::cout << "Inserisci un numero intero da inserire nella collezione (ancora " << size - i << "): " << std::endl;
        std::cin >> myArr[i];
    }

    std::cout << "Collezione creata!" << std::endl;

    std::cout << "INIZIO TEST ---------------------------" << std::endl;

    std::cout << "Array inserito: " << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << myArr[i] << ' ';
    std::cout << std::endl;

    std::cout << "Massimo inserito: " << trovaMassimo(myArr, size) << std::endl;
    std::cout << "Minimo inserito: " << trovaMinimo(myArr, size) << std::endl;
    std::cout << "Media aritmetica dei valori inseriti: " << calcolaMedia(myArr, size) << std::endl;

    std::cout << "Array invertito: " << std::endl;
    invertiArray(myArr, size);
    for (int i = 0; i < size; i++)
        std::cout << myArr[i] << ' ';
    std::cout << std::endl;

    return 0;
}
