#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3;

    cout << "Inserisci tre numeri interi: " << endl;
    cin >> n1 >> n2 >> n3;

    cout << "\t" << n1 << "\t" << n2 << "\t" << n3 << endl;
    cout << n1 << "\t" << 0 << "\t" << n1 - n2 << "\t" << n1 - n3 << endl;
    cout << n2 << "\t" << n2 - n1 << "\t" << 0 << "\t" << n2 - n3 << endl;
    cout << n3 << "\t" << n3 - n1 << "\t" << n3 - n2 << "\t" << 0 << endl;
    return 0;
}