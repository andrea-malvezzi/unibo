#include <cmath>
#include <iostream>
#include <math.h>

// padovani 20 Dicembre 2024 (ultima lezione!)

// TODO finisci
// funzione ricorsiva che prende in input un arryay di itneri e ritorna
// se l'array contiene soltanto numeri primi, falso altrimenti. Si possono
// usare funzioni ausiliarie, purché ricorsive.

bool divide(const int dividendo, const int divisore) {
    if (divisore == dividendo || divisore == 1) return true;
    if (dividendo / divisore > 1 && dividendo % divisore != 0) return false;
    if (divisore == 2) return true;
    return divide(dividendo, divisore - 1);
}

// ritorna se un array di numeri contiene solo primi o meno
bool there_are_primes(const int numbers[], const int length) {
    if (length < 1) return true;
    if (!divide(numbers[0], numbers[0] / (numbers[0] / 2))) return false;
    if (length != 1)
        return there_are_primes(&numbers[1], length - 1);
    return true;
}

// TODO esercizio 2
struct tavolo {
    int maxPeople;
    double hoursFree;
    bool inside;
    tavolo *next;
};

typedef tavolo *ptavolo;

int main()
{
    const int falseNumbers[] = { 1, 2, 3, 4, 5 };
    const int trueNumbers[] = { 1, 5, 2, 3 };

    std::cout << "Primo array: " << std::endl;
    // stampa trueNumbers
    for (int i = 0; i < 4; i++) {
        std::cout << trueNumbers[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << "Risulta: " << there_are_primes(trueNumbers, 4) << std::endl;

    std::cout << "Secondo array: " << std::endl;
    // stampa falseNumbers
    for (int i = 0; i < 5; i++) {
        std::cout << falseNumbers[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << "Risulta: " << there_are_primes(falseNumbers, 5) << std::endl;

    return 0;
}
