#include <iostream>
using namespace std;

void scambia(int& x, int&y) {
    const int temp = x;
    x = y;
    y = temp;
}

void bubble_sort(int arr[], const int length) {
    int min, temp;

    for (int i = 0; i < length / 2; i++) {
        for (int j = 0; j < length; j++) {
            if ()
        }
    }
}

int main() {
    constexpr int LENGTH = 10;
    int numbers[LENGTH] = {9, 8, 5, 7, 4, 2, 6, 3, 2, 1};

    cout << "Dimostrazione Bubble Sort:" << endl;

    cout << "Array non ordinato:" << endl;
    // Scrivo l'array usando un foreach loop (per ogni number in numbers, fai...)
    for (const int number : numbers) {
        cout << number << ' ';
    }
    cout << endl;

    // Chiamo la mia funzione di Bubble Sort
    bubble_sort(numbers, LENGTH);

    cout << "Array ordinato:" << endl;
    for (const int number : numbers) {
        cout << number << ' ';
    }
    cout << endl;

    return 0;
}
