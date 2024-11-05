#include <iostream>
using namespace std;

int posizione_seconda_occorrenza(const char word[], const int length) {
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            if (word[i] == word[j])
                return j;
        }
    }

    return -1;
}

int parola(const char str[], const int length, int n, char dest[]) {


    return 0;
}

int give_max(const int a[], const int length) {
    int count = 0, current = 0;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (a[i] == a[j])
                current++;
        }
        if (current > count) count = current;
        current = 0;
    }

    return count;
}

int main() {
    constexpr int LENGTH = 8;
    constexpr char word[LENGTH] = "lettera";
    cout << posizione_seconda_occorrenza(word, LENGTH) << endl;

    constexpr int numbers[LENGTH] = {1, 2, 3, 3, 3, 4, 4, 5};
    cout << give_max(numbers, LENGTH) << endl;

    constexpr int PHRASE_LENGTH = 15;
    constexpr char phrase[PHRASE_LENGTH] = "la mia frasona";
    char word_looking_for[];
    cout << parola(phrase, PHRASE_LENGTH, 2, word_looking_for) << endl;

    return 0;
}
