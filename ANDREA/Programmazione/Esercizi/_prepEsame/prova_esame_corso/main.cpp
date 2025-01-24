#include <iostream>

/*
* es.1
* Scrivere una funzione ricorsiva there are primes che prende in input un array di interi e
* ritorna vero se l’array contiene soltanto numeri primi, falso altrimenti. E possibile usare funzioni ausiliarie,
* se ricorsive.
*/

// ausiliarie

bool dividi(const int dividendo, const int divisore) {
    if (divisore == 1)
        return true;
    if (dividendo % divisore != 0)
        return dividi(dividendo, divisore - 1);
    return false;
}

bool is_prime(const int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    return dividi(n, n / 2);
}

bool there_are_primes(const int* A, const int size) {
    if (size <= 0) return true;
    if (size == 1)
        return is_prime(A[0]);
    if (is_prime(A[0])) return there_are_primes(A + 1, size - 1);
    return false;
}

/* es.2
 * Un ristorante usa una lista di tavoli per memorizzare i tavoli liberi per la giornata.
 * Ogni elemento della lista memorizza il numero di persone che il tavolo ospita,
 * l'orario dal quale risulta disponibile (rappresentanto come un double es. 19.45)
 * ed un booleano che indica se il tavolo si trova all’interno o all’esterno (true: interno, false: esterno).
 * Definire le strutture dati necessarie a rappresentare la lista di tavoli e le seguenti funzioni:
 *
 * prenota_tavolo che prende come parametri il numero di persone per le quali si vuole prenotare e
 * un orario. La funzione cancella dalla lista il tavolo che si prenota, se disponibile.
 *
 * quale_orario che prende come parametro il numero di persone per le quali si desidera un tavolo e
 * l’opzione dentro/fuori. La funzione ritorna il primo orario disponibile.
 *
 * quanti_tavoli che prende come parametro un booleano e ritorna il numero di tavoli disponibili
 * dentro al ristorante (se il booleano == true) o all’esterno del ristorante (se il booleano == false).
 *
 * NB. Se non si trova un tavolo disponibile per il numero esatto delle persone per cui si vuole prenotare, le
 * funzioni considerano il primo tavolo con un numero sufficiente di posti disponibili.
*/

struct Tavolo{
    int max_persone;
    double orario_disponibile;
    bool interno;
    Tavolo* next;
};
typedef Tavolo* ptavolo;

// ritorna la head della nuova lista
ptavolo prenota_tavolo(ptavolo L, const int persone, const double orario, const bool interno) {
    ptavolo prev = NULL;
    ptavolo head = L;

    while(L != NULL) {
        // TODO: trova il nodo corretto o la prima approx corretta
        // TODO: cancella il nodo trovato e sistema prev ed eventualmente head
        // TODO: ritorna
        prev = L;
        L = L -> next;
    }
}

// works
double quale_orario(ptavolo L, const int persone, const bool interno) {
    ptavolo curr = NULL;
    bool approx_found = false;
    while(L != NULL) {
        // match esatto
        if (L -> max_persone == persone && L -> interno == interno) {
            curr = L;
            break;
        }
        // primo match approx
        if (L -> max_persone < persone && L -> interno == interno && !approx_found) {
            approx_found = true;
            curr = L;
        }
        L = L -> next;
    }

    // caso limite
    if (curr == NULL)
        return 0;
    return curr -> orario_disponibile;
}

// DEBUG
void clear_memo(ptavolo L) {
    while(L != NULL) {
        const ptavolo temp = L;
        L = L -> next;
        delete temp;
    }
}

int main() {
    // es.1
    const int length = 10;
    const int not_prime[] = {1, 3, 5, 7, 11, 13, 17, 19, 21, 23};
    const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    const bool should_be_false = there_are_primes(not_prime, length);
    const bool should_be_true = there_are_primes(primes, length);
    std::cout << should_be_false << std::endl;
    std::cout << should_be_true << std::endl;

    // es.2
    ptavolo head = new Tavolo;
    head -> max_persone = 10;
    head -> interno = true;
    head -> orario_disponibile = 20.30;
    head -> next = new Tavolo;

    head -> next -> max_persone = 10;
    head -> next -> interno = false;
    head -> next -> orario_disponibile = 20.30;
    head -> next -> next = new Tavolo;

    head -> next -> next -> max_persone = 5;
    head -> next -> next -> interno = true;
    head -> next -> next -> orario_disponibile = 20.00;
    head -> next -> next -> next = NULL;

    const ptavolo found = prenota_tavolo(head, 10, 20.30, true);
    std::cout << head -> max_persone << ", " << head -> orario_disponibile << std::endl;
    std::cout << found -> max_persone << ", " << found -> orario_disponibile << std::endl;

    const double should_be_last = quale_orario(head, 5, true);
    std::cout << should_be_last << std::endl;
    std::cout << head -> max_persone << ", " << head -> orario_disponibile << std::endl;

    clear_memo(head);

    return 0;
}
