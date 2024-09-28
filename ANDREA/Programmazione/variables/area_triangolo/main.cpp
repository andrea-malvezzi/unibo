#include <iostream>
using namespace std;

int main()
{
    float height, base;
    float area;
    cout << "Inserire l\'altezza del triangolo:" << endl;
    cin>>height;
    cout << "Inserire la base del triangolo:" << endl;
    cin>>base;
    area = (height * base) / 2;
    cout << "Area del triangolo: " << area << "cm^3" << endl;
    return 0;
}