#include <iostream>

/*
 * es.1
 * funzione ricorsiva che prende in input un array di interi e ritorna
 * il numero massimo di duplicati che contiene.
 * Es.
 * [1, 2, 3, 1, 2, 3, 3, 2, 2] -> 4 (il 2 compare 4 volte).
 * Si possono usare funzione ausiliarie se ricorsive.
*/

// fanculo Crozza FAMMI USARE I LOOP MALEDETTO
int scorri(const int searching_for, const int* next, int remaining, int count=1) {
    if (*next == searching_for)
        count++;
    if (--remaining <= 0)
        return count;
    return scorri(searching_for, ++next, remaining, count);
}

// prendiamo anche la lunghezza dell'array per facilitare le cose
int ricorsiva(const int numbers[], const int size, const int prev_max=1) {
    const int count = scorri(numbers[0], &numbers[1], size - 1);
    if (count >= prev_max) {
        if (size == 0)
            return count;
        return ricorsiva(numbers + 1, size - 1, count);
    }
    if (size == 0)
        return prev_max;
    return ricorsiva(numbers + 1, size - 1, prev_max);
}

/*
 * es.2
 * Ogni appunto ha un testo (array di char), un numero di pagine (int)
 * e una data (si considera solo il giorno come int). Ogni appunto
 * si collega al successivo e al precedente e la lista ottenuta deve essere
 * ordinata per data in ordine crescente.
*/

struct Appunto {
    char* testo;    // array di lunghezza non definita
    int pagine;
    int giorno_data;
    Appunto* prev;
    Appunto* next;
};
typedef Appunto* papp;

/*
 * ora definire le seguenti funzioni:
 * 1) rimuovi_appunto: prende in input la lista ed il giorno di un appunto
 *      e rimuove tutti gli appunti presi in quel giorno.
 * 2) inverti_lista: inverte l'ordine (da crescente a decrescente e viceversa) della lista
 *      modificando l'originale (non crearne un'altra).
 * 3) testo: prende in input la lista e un array di char e copia il testo dell'appunto di maggiore lunghezza
 *      (quindi quello avente il maggior numero di pagine) all'interno dell'array.
*/

papp rimuovi_appunto(papp head, const int giorno) {
    if (head == NULL)
        return NULL;

    papp scorri = head;
    papp temp = NULL;
    while(scorri != NULL) {
        if (scorri -> giorno_data == giorno) {
            if (head == scorri) {
                temp = head;
                head = head -> next;
                // se head NULL cancello e ritorno
                if (head == NULL) {
                    delete temp;
                    return NULL;
                }
                // altrimenti modifico head, cancello e continuo
                head -> prev = NULL;
                delete temp;
                scorri = head;
            } else {
                temp = scorri;
                // successivo del prev = next
                scorri -> prev -> next = scorri -> next;
                // SE next esiste (non NULL), allora precedente del next = prev
                if (scorri -> next == NULL) {
                    delete temp;
                    return head;
                }
                scorri -> next -> prev = scorri -> prev;
                scorri = scorri -> prev;
                delete temp;
            }
        }
        scorri = scorri -> next;
    }
    return head;
}

void inverti_lista(papp* testa) {
    papp attuale = *testa;
    papp temp = NULL;

    // mette in prev il next e in next il prev.
    // Essenzialmente funziona al contrario: per andare avanti devo andare indietro
    // (that's why usiamo attuale = attuale -> prev)
    while (attuale != NULL) {
        temp = attuale->prev;
        attuale->prev = attuale->next;
        attuale->next = temp;
        attuale = attuale->prev;
    }

    if (temp != NULL) {
        *testa = temp->prev;
    }
}

// TODO es.3

// DEBUG, non servono per l'esame
void stampa_lista(papp head) {
    while (head != NULL) {
        std::cout << "Appunti del: " << head -> giorno_data << " lunghi " << head -> pagine << " pagine." << std::endl;
        head = head -> next;
    }
}

void delete_lista(papp head) {
    while (head != NULL) {
        const papp temp = head;
        head = head -> next;
        delete temp -> testo;
        delete temp;
    }
}

int main() {
    // es.1 TEST
    const int numbers[] = {1, 2, 3, 1, 2, 3, 3, 2, 2};
    const int count = ricorsiva(numbers, 9);
    std::cout << count << std::endl;

    // es.2 TEST
    papp head = new Appunto;
    head -> pagine = 2;
    head -> giorno_data = 1;
    head -> testo = new char[] {"a"};
    head -> prev = NULL;
    head -> next = new Appunto;

    head -> next -> pagine = 2;
    head -> next -> giorno_data = 2;
    head -> next -> testo = new char[] {"ab"};
    head -> next -> prev = head;
    head -> next -> next = new Appunto;

    head -> next -> next -> pagine = 3;
    head -> next -> next -> giorno_data = 1;
    head -> next -> next -> testo = new char[] {"abc"};
    head -> next -> next -> prev = head -> next;
    head -> next -> next -> next = NULL;

    std::cout << std::endl;
    stampa_lista(head);
    std::cout << std::endl;
    inverti_lista(&head);
    stampa_lista(head);
    head = rimuovi_appunto(head, 1);
    std::cout << std::endl;
    stampa_lista(head);
    delete_lista(head);

    return 0;
}
