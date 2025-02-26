#include <iostream>
#include <string.h>

/*
 * es.1
 * funzione che prende in input un seq di 1000 char e ritorna
 * true se l'input risulta bilanciato, oppure false in caso contrario.
 * Per essere bilanciata, una sequenza deve contenere egual numero di parentesi aperte
 * e chiuse e l'ultima chiusa deve corrispondere alla prima aperta.
 * Ad esempio ({[}] ritornerebbe false, mentre (  [  {  }] ) ritornerebbe true.
 * La funzione potrebbe ricevere anche parametri aggiuntivi a scelta e
 * si possono usare funzioni ausiliarie.
*/

// ausiliarie

// ritorna la prio maggiore tra quelle assegnate alle tre parentesi
int get_prio(const int tonda, const int quadra, const int graffa) {
    int max = tonda;
    if (max < quadra)
        max = quadra;
    if (max < graffa)
        max = graffa;
    return max;
}

// ([{}{}{}]{}) ok
// prio order: 1-2-3 (3 equivale all'ultima trovata aperta, quindi la prima da chiudere)
bool bilanciata(char seq[1001], int current_index=0, int tonda=0, int quadra=0, int graffa=0) {
    // stringa vuota
    if (seq[0] == '\0')
        return true;

    // fine stringa
    if (seq[current_index] == '\0')
        return tonda == 0 && quadra == 0 && graffa == 0;

    const int max = get_prio(tonda, quadra, graffa);
    // ordine parentesi assente: controllo e creo hierarchy

    // apro tonda
    if (seq[current_index] == '(' && tonda == 0)
        return bilanciata(seq, current_index + 1, max + 1, quadra, graffa);
    if (seq[current_index] == '(' && tonda != 0)
        return false;

    // chiudo tonda
    if (seq[current_index] == ')' && tonda == max)
        return bilanciata(seq, current_index + 1, 0, quadra, graffa);
    if (seq[current_index] == ')' && tonda != 0)
        return false;

    // apro quadra
    if (seq[current_index] == '[' && quadra == 0)
        return bilanciata(seq, current_index + 1, tonda, max + 1, graffa);
    if (seq[current_index] == '[' && quadra != 0)
        return false;

    // chiudo quadra
    if (seq[current_index] == ']' && quadra == max)
        return bilanciata(seq, current_index + 1, tonda, 0, graffa);
    if (seq[current_index] == ']' && quadra != 0)
        return false;

    // apro graffa
    if (seq[current_index] == '{' && graffa == 0)
        return bilanciata(seq, current_index + 1, tonda, quadra, max + 1);
    if (seq[current_index] == '{' && graffa != 0)
        return false;

    // chiudo graffa
    if (seq[current_index] == '}' && graffa == max)
        return bilanciata(seq, current_index + 1, tonda, quadra, 0);
    if (seq[current_index] == '}' && graffa != 0)
        return false;

    if (seq[current_index] == ' ')
        return bilanciata(seq, current_index + 1, tonda, quadra, graffa);
}

/* es.2
 * Un manuale corrisponde ad una lista di istruzioni per la costruzione di un singolo mobile.
 * Ogni istruzione ha: una descrizione e i pezzi necessari per quell'istruzione.
 * La descrizione viene memorizzata come array di char e i pezzi si memorizzano come un array di bool.\
 * Se il pezzo in posizione i corrisponde a true, allora serve per quell'istruzione.
*/
struct Istruzione {
    char desc[26];
    bool pezzi[5];
    Istruzione *next;
};
typedef Istruzione *pist;

/*
 * prende in input una lista L e una descrizione e cancella tutte le istruzioni
 * dalla lista dove la descrizione equivale a quella passata.
 * Ritorna l'inizio della nuova lista.
*/
pist remove_istruzioni(pist L, char desc[]) {
    pist prev = L;
    pist head = L;
    while(L != NULL) {
        if (strcmp(L->desc, desc) == 0) {
            // primo item della lista
            if (head == L) {
                const pist temp = L;
                L = L -> next;
                delete temp;
                prev = L;
                head = prev;
            }
            else {
                const pist temp = L;
                if (L -> next == NULL)
                    L = NULL;
                else
                    L = L -> next;
                prev -> next = L;
                delete temp;
                continue;
            }
        }
        prev = L;
        L = L -> next;
    }
    return head;
}

/*
 * prende in input una lista L e la posizione di un pezzo nell'array (int)
 * e restituisce un intero che indica il numero di volte che quel pezzo
 * viene utilizzato per tutta la lista di istruzioni.
*/
int occorrenze_pezzo(const pist L, const int posizione) {
    if (L == NULL) return 0;
    if (L -> pezzi[posizione]) return 1 + occorrenze_pezzo(L -> next, posizione);
    return occorrenze_pezzo(L -> next, posizione);
}

/*
 * prende in input una lista L, una descrizione d e una posizione i di un pezzo
 * e ritorna la lista L modificata in cui l'istruzione corrispondente a d ha anche
 * il pezzo i.
*/
pist aggiungi_pezzo(pist L, const char d[], const int i) {
    const pist head = L;
    while (L != NULL) {
        if (strcmp(L -> desc, d) == 0) {
            L -> pezzi[i] = true;
            return head;
        }
        L = L -> next;
    }
    return head;
}

// DEBUG ONLY
void scrivi(pist L) {
    while(L != NULL) {
        std::cout << L -> desc << std::endl;
        for (int i = 0; i < 3; i++)
            std::cout << L -> pezzi[i] << std::endl;
        L = L -> next;
    }
}

/* es.3
 *
*/

int main() {
    // es. 1
    char seq[1001] = "(   {  [ ] } )   ([] {} )";
    seq[1001] = '\0';
    bool res = bilanciata(seq);
    std::cout << res << std::endl;

    // es.2
    bool pezzi[] = {true, false, true};
    char test1[] = "test 1";
    char test2[] = "test 2";
    pist istr = new Istruzione;
    strncpy(istr -> desc, test1, 7);
    for (int i = 0; i < 3; ++i) {
        istr -> pezzi[i] = pezzi[i];
    }
    istr -> next = new Istruzione;
    for (int i = 0; i < 3; ++i) {
        istr -> next -> pezzi[i] = pezzi[i];
    }
    strncpy(istr -> next -> desc, test2, 7);
    istr -> next -> next = new Istruzione;
    for (int i = 0; i < 3; ++i) {
        istr -> next -> next -> pezzi[i] = pezzi[i];
    }
    strncpy(istr -> next -> next -> desc, test2, 7);
    scrivi(istr);
    const int amount = occorrenze_pezzo(istr, 0);
    std::cout << amount << std::endl;
    std::cout << std::endl;
    istr = remove_istruzioni(istr, test2);
    scrivi(istr);
    istr = aggiungi_pezzo(istr, test1, 1);
    scrivi(istr);

    // es.3


    return 0;
}
