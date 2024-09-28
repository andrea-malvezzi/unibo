#include <iostream>
using namespace std;

int main()
{
    int n1, n2;

    cout << "Inserisci due numeri interi: " << endl;
    cin >> n1 >> n2;

    if(n1 - n2 == 0)
        cout << "I due numeri inseriti sono uguali." << endl;
    else
        cout << "I due numeri inseriti sono diversi." << endl;

    return 0;
}
