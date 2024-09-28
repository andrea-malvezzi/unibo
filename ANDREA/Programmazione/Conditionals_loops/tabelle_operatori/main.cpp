#include <iostream>
using namespace std;

int main()
{
    double n1, n2, n3;  // double per le divisioni, altrimenti fa int e bon
    char operation;

    cout << "Inserisci tre numeri interi: " << endl;
    cin >> n1 >> n2 >> n3;
    cout << R"(Inserisci un operazione tra "/" e "-":)" << endl;
    cin >> operation;

    if (operation == '-')
    {
        cout << "\t" << n1 << "\t" << n2 << "\t" << n3 << endl;
        cout << n1 << "\t" << 0 << "\t" << n1 - n2 << "\t" << n1 - n3 << endl;
        cout << n2 << "\t" << n2 - n1 << "\t" << 0 << "\t" << n2 - n3 << endl;
        cout << n3 << "\t" << n3 - n1 << "\t" << n3 - n2 << "\t" << 0 << endl;
        return 0;
    } else if (operation == '/')
    {
        cout << "\t" << n1 << "\t" << n2 << "\t" << n3 << endl;
        cout << n1 << "\t" << 1 << "\t" << n1 / n2 << "\t" << n1 / n3 << endl;
        cout << n2 << "\t" << n2 / n1 << "\t" << 1 << "\t" << n2 / n3 << endl;
        cout << n3 << "\t" << n3 / n1 << "\t" << n3 / n2 << "\t" << 1 << endl;
    } else
    {
        cout << "operazione non valida." << endl;
        return 1;
    }

    return 0;
}