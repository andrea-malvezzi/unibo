#include <iostream>
using namespace std;

int fattoriale(int n) {
    if (n == 0) return 1;
    else return n * fattoriale(n - 1);
}

// n!/(n-k)!k!
int binomio_newton(int n, int k) {
    int binomio = fattoriale(n) / (fattoriale(n-k) * fattoriale(k));
    return binomio;
}

// sistemare lo spacing per n > 8
void piramide(int n) {
    for(int i = 0; i < n; i++) {
        // spacing: inizio con i=0, e n=3 (esempio), perciò mette 3-(0+1) tab (4 spazi), poi 1, etc...
        cout << string(n-(i + 1), '\t');
        for(int j = 0; j < i+1; j++) {
            // dopo ogni numero, metto due tab per allineare tra i due numeri del livello superiore
            cout << binomio_newton(i, j) << string(2, '\t');
        }
        cout << endl;
    }
}
int main() {
    int input;
    do {
        cout << "Inserisci un valore:" << endl;
        cin >> input;
    } while(input < 0 || input > 15);
    piramide(input);
    return 0;
}
