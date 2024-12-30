#include <cmath>
#include <iostream>
#include <math.h>

// padovani 20 Dicembre 2024 (ultima lezione!)

// funzione ricorsiva che prende in input un arryay di itneri e ritorna
// se l'array contiene soltanto numeri primi, falso altrimenti. Si possono
// usare funzioni ausiliarie, purché ricorsive.

bool is_prime(const int dividendo, const int divisore) {
    // mancava il caso divisore == 1 che faceva andare ad infinito
    if (dividendo == 2 || dividendo == 1 || divisore == 1) return true;
    if (dividendo % divisore == 0) return false;
    return is_prime(dividendo, divisore - 1);
}

// ritorna se un array di numeri contiene solo primi o meno
bool there_are_primes(const int numbers[], const int length) {
    if (!is_prime(numbers[0], numbers[0] / 2))
        return false;
    return length == 1 ? true : there_are_primes(&numbers[1], length - 1);
}

// esercizio 2

struct tavolo {
    int maxPeople;
    double hoursFree;
    bool inside;
    tavolo *next;
};

typedef tavolo *ptavolo;

// che prende come parametri il numero di persone per le quali si vuole prenotare e un orario.
// La funzione cancella dalla lista il tavolo che si prenota, se disponibile.
ptavolo prenota_tavolo(const ptavolo head, const int numberPeople, const double desiredTime) {
    ptavolo localHead = head;
    ptavolo previous = head;
    while (localHead != NULL && (localHead -> maxPeople != numberPeople && localHead -> hoursFree != desiredTime)) {
        previous = localHead;
        localHead = localHead -> next;
    }

    localHead != NULL && localHead -> next != NULL ? previous -> next = localHead -> next : previous -> next = NULL;
    return localHead;
}

// che prende come parametro il numero di persone per le quali si desidera un tavolo e l’ opzione dentro / fuori.
// La funzione ritorna il primo orario disponibile.
double quale_orario(const ptavolo head, const int numberPeople, const bool inside) {
    ptavolo localHead = head;
    while(localHead != NULL) {
        if (localHead -> inside == inside && localHead -> maxPeople == numberPeople)
            break;
        localHead = localHead -> next;
    }

    return localHead != NULL ? localHead -> hoursFree : -1;
}

// che prende come parametro un booleano e ritorna il numero di tavoli disponibili
// dentro al ristorante(se il booleano è true) o all’esterno del ristorante (se il booleano è false)
int quanti_tavoli(const ptavolo head, const bool inside) {
    int count = 0;
    ptavolo localHead = head;
    while(localHead != NULL) {
        if (localHead -> inside == inside) count++;
        localHead = localHead -> next;
    }

    return count;
}

// serviva a me per debug, dont mind this
void stampa(const ptavolo head) {
    ptavolo localHead = head;
    int counter = 1;
    while (localHead != NULL) {
        std::cout << "Tavolo " << counter << ": persone " << localHead->maxPeople << " orario " << localHead->hoursFree
            << " dentro " << localHead->inside << '.' << std::endl;
        counter++;
        localHead = localHead -> next;
    }
}

// TODO riscrivi le funzioni considerando il tavolo con il numero di persone max più vicino
// TODO a quello specificato nel caso in cui non ci siano tavoli con il numero esatto disponibili

// esericizio 3
struct Prodotto {
    int code;
    char name[40];
    int quantity;
    Prodotto *next;
};

typedef Prodotto* prodottoPtr;

class Magazzino {
protected:
    prodottoPtr firstProduct;

public:
    Magazzino();
    Magazzino(prodottoPtr head);
    int decrementa_disponibilita(int productCode, int quantity) const;
    // serve per debug, non nella consegna
    void stampa() const;
};

// constructors
Magazzino::Magazzino() {
    firstProduct = NULL;
}

Magazzino::Magazzino(const prodottoPtr head) {
    firstProduct = head;
}

int Magazzino::decrementa_disponibilita(const int productCode, const int quantity) const {
    int index = 0;
    prodottoPtr indexer = firstProduct;
    while (indexer != NULL) {
        // codice & quantity esatte, termino
        if (indexer -> code == productCode && indexer -> quantity >= quantity) {
            indexer -> quantity -= quantity;
            return index;
        }
        // codice esatto quantity sbagliata, ritorno per evitare iterazioni inutili
        if (indexer -> code == productCode && indexer -> quantity < quantity)
            return -1;
        // aumento counter e passo al nodo dopo
        ++index;
        indexer = indexer -> next;
    }
    // al termine del while non ho trovato il prodotto, ritorno -1
    return -1;
}

// serviva a me per debug, dont mind this
void Magazzino::stampa() const {
    prodottoPtr localHead = firstProduct;
    while(localHead != NULL) {
        std::cout << "Prodotto con codice: " << localHead -> code << "; quantita: " << localHead -> quantity << '.'
            << std::endl;
        localHead = localHead -> next;
    }
    std::cout << "Fine inventario." << std::endl;
}

// extra part
class MagazzinoPlus: Magazzino {
private:
    int toUpdateAmount;
    int minimumQuantity;

public:
    MagazzinoPlus();
    MagazzinoPlus(prodottoPtr head, int amount, int minQuantity);
    void da_approvvigionare(int codes[]);
    void aggiorna_disponibilita(const int codes[], const int quantities[], int length);
};

MagazzinoPlus::MagazzinoPlus() : Magazzino() {
    firstProduct = NULL;
    minimumQuantity = 2;
    toUpdateAmount = 0;
}

MagazzinoPlus::MagazzinoPlus(const prodottoPtr head, const int amount, const int minQuantity) : Magazzino(head) {
    toUpdateAmount = amount;
    minimumQuantity = minQuantity;
}

void MagazzinoPlus::da_approvvigionare(int codes[]) {
    int index = 0;
    prodottoPtr localHead = firstProduct;
    while (localHead != NULL && toUpdateAmount > 0) {
        if (localHead -> quantity <= minimumQuantity) {
            toUpdateAmount--;
            codes[index] = localHead -> code;
            index++;
        }
        localHead = localHead -> next;
    }
}

void MagazzinoPlus::aggiorna_disponibilita(const int codes[], const int quantities[], int length) {
    prodottoPtr localHead = firstProduct;
    // todo finisci
}

int main()
{
    // esercizio 1 TEST
    const int falseNumbers[] = { 1, 2, 3, 4, 5 };
    const int trueNumbers[] = { 1, 5, 2, 3 };

    std::cout << "Primo array: " << std::endl;
    // stampa trueNumbers
    for (int i = 0; i < 4; i++) {
        std::cout << trueNumbers[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << "Risulta: " << there_are_primes(trueNumbers, 4) << std::endl;

    std::cout << "Secondo array: " << std::endl;
    // stampa falseNumbers
    for (int i = 0; i < 5; i++) {
        std::cout << falseNumbers[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << "Risulta: " << there_are_primes(falseNumbers, 5) << std::endl;

    std::cout << std::endl;

    // esercizio 2 TEST
    ptavolo head = new tavolo;
    ptavolo table2 = new tavolo;
    ptavolo table3 = new tavolo;
    ptavolo table4 = new tavolo;

    head -> inside = true;
    head -> hoursFree = 18.00;
    head -> maxPeople = 12;
    head -> next = table2;
    table2 -> inside = false;
    table2 -> hoursFree = 19.00;
    table2 -> maxPeople = 4;
    table2 -> next = table3;
    table3 -> inside = false;
    table3 -> hoursFree = 20.00;
    table3 -> maxPeople = 5;
    table3 -> next = table4;
    table4 -> inside = false;
    table4 -> hoursFree = 18.30;
    table4 -> maxPeople = 12;
    table4 -> next = NULL;

    const ptavolo bookedTable = prenota_tavolo(head, 5, 20.00);
    std::cout << "Prenotato tavolo per le: " << bookedTable -> hoursFree << " per un totale di: " << bookedTable -> maxPeople << " persone." << std::endl;

    const double firstTimeAvailable = quale_orario(head, 12, false);
    std::cout << "Il primo orario disponibile per un tavolo con le condizioni specificate corrisponde alle: " << firstTimeAvailable << ". " << std::endl;

    const int amountTablesOutside = quanti_tavoli(head, false);
    std::cout << "Tavoli all\'esterno: " << amountTablesOutside << '.' << std::endl;

    std::cout << std::endl;

    // esercizio 3 TEST
    auto productHead = new Prodotto();
    productHead -> code = 1;
    productHead -> quantity = 10;

    auto secondProduct = new Prodotto();
    productHead -> next = secondProduct;
    secondProduct -> code = 2;
    secondProduct -> quantity = 20;

    auto const magazzino = new Magazzino(productHead);
    std::cout << "Il Magazzino contiene:" << std::endl;
    magazzino->stampa();
    std::cout << std::endl;
    std::cout << "Prodotto con codice 1 ritirato (5u) da indice: "
        << magazzino->decrementa_disponibilita(1, 5) << '.' << std::endl;
    std::cout << std::endl;
    std::cout << "Prodotto con codice 1 ritirato (5u) da indice: "
        << magazzino->decrementa_disponibilita(1, 5) << '.' << std::endl;

    std::cout << std::endl;
    magazzino -> stampa();

    delete head;
    delete table2;
    // non cancello table3 because so che equivale a bookedTable e farlo cancellerebbe memoria a cazzo di cane.
    delete bookedTable;
    delete table4;

    delete productHead;
    delete secondProduct;

    delete magazzino;

    return 0;
}
