#include <iostream>
using namespace std ;

// 1)
// scrivere un programma che prende in input un prezzo in euro (inclusi
// centesimi) e stampa quante e quali monete sono necessarie per
// pagarlo (con un numero minimo di monete)

int main(){
    double price;
    int quantity_2e, quantity_1e, quantity_50c, quantity_20c, quantity_10c, quantity_5c, quantity_2c;
    int total_coins;
    // poi fallo coi breakpoint in un array;

    cout<<"Inserisci un prezzo in euro (includendo i centesimi ed escludendo il simbolo dell'euro) :";
    cin>>price;

    // per evitare problemi con il calcolo dei centesimi, trasformo tutto nell'intero corrispondente
    price = price * 100;

    quantity_2e = price / 200; // 2 volte 100 centesimi -> 200
    price -= quantity_2e * 200;

    quantity_1e = price / 100;
    price -= quantity_1e * 100;

    quantity_50c = price / 50;
    price -= quantity_50c * 50;

    quantity_20c = price / 20;
    price -= quantity_20c * 20;

    quantity_10c = price / 10;
    price -= quantity_10c * 10;

    quantity_5c = price / 5;
    price -= quantity_5c * 5;

    quantity_2c = price / 2;
    price -= quantity_2c * 2;

    /*
     * non serve 1c in quanto se ci sono centesimi rimanenti, 1c sarebbe pari a price,
     * quindi lo ometto (risparmio memoria = nice!)
    */

    total_coins = quantity_2e + quantity_1e + quantity_50c + quantity_20c + quantity_10c + quantity_5c + quantity_2c;

    cout<<"Per pagare il prezzo inserito sono necessarie un minimo di " << total_coins <<" monete:" << endl;
    cout<<"Monete da 2 euro: "<<quantity_2e<<endl;
    cout<<"Monete da 1 euro: "<<quantity_1e<<endl;
    cout<<"Monete da 50 centesimi: "<<quantity_50c<<endl;
    cout<<"Monete da 20 centesimi: "<<quantity_20c<<endl;
    cout<<"Monete da 10 centesimi: "<<quantity_10c<<endl;
    cout<<"Monete da 5 centesimi: "<<quantity_5c<<endl;
    cout<<"Monete da 2 centesimi: "<<quantity_2c<<endl;
    cout<<"Monete da 1 centesimo: "<<price<<endl;

    return 0;
}