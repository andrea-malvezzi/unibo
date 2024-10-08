#include <iostream>
using namespace std;

int main() {
    int input;
    cout << "Inserisci un numero: " << endl;
    cin >> input;
    for (int i = 1; i <= input; i++) {
        for (int j = input - i; j >= 0; j--)
            cout << "*";
        cout << endl;
    }
}
