#include <iostream>

/*
 * es.1
 * funzione ricorsiva che prende in input un array di interi e ritorna
 * il numero massimo di duplicati che contiene.
 * Es.
 * [1, 2, 3, 1, 2, 3, 3, 2, 2] -> 4 (il 2 compare 4 volte).
 * Si possono usare funzione ausiliarie se ricorsive.
*/

// fanculo Crozza FAMMI USARE I LOOP MALEDETTO
int scorri(const int searching_for, const int* next, int remaining, int count=1) {
    if (*next == searching_for)
        count++;
    if (--remaining <= 0)
        return count;
    return scorri(searching_for, ++next, remaining, count);
}

// prendiamo anche la lunghezza dell'array per facilitare le cose
int ricorsiva(const int numbers[], const int size, const int prev_max=1) {
    const int count = scorri(numbers[0], &numbers[1], size - 1);
    if (count >= prev_max) {
        if (size == 0)
            return count;
        return ricorsiva(numbers + 1, size - 1, count);
    }
    if (size == 0)
        return prev_max;
    return ricorsiva(numbers + 1, size - 1, prev_max);
}

int main()
{
    const int numbers[] = {1, 2, 3, 1, 2, 3, 3, 2, 2};
    const int count = ricorsiva(numbers, 9);
    std::cout << count << std::endl;
    return 0;
}
