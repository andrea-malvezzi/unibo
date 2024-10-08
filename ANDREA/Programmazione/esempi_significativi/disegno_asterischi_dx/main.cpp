#include <iostream>
using namespace std;

int main() {
    int input;
    cout << "Inserisci un numero: " << endl;
    cin >> input;
    for (int i = 1; i <= input; i++) {
        // esegue n volte
        for (int j = input; j >= i+1; j--) {
            /* parto da input volte (j = input) e stampo spazi finché non arrivo a j < i+1.
            *  Esempio: input=5. Primo ciclo: i = 1, j = input (5), k = i (1).
            */
            cout << ' ';
        }
        for (int k = i; k > 0; k--)
            cout << '*';
        cout << endl;
    }
}
