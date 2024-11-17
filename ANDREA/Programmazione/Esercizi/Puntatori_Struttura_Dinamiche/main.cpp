#include <iostream>

// serve per l'ultimo esercizio
struct struttura5int {
    int arr[5];
};

/*
 * definire una variabile di tipo intero, incrementarla due volte attraverso due
 * puntatori distinti e stampare il risultato
*/
void incrementaVarDueVolte(){
    int myVar = 0;
    int *p1, *p2;

    p1 = &myVar;
    p2 = &myVar;

    /*
     * fare *p1++ non funzionerebbe, in quanto aumenterebbe di 1 il valore dell'indirizzo di p1.
     * Semplicemente il puntatore passerebbe all'indirizzo successivo.
     * Questo potrebbe servire lavorando con array o altre strutture dati.
    */
    (*p1)++;
    (*p2)++;

    std::cout << "la variabile ora ha valore pari a: " << myVar << '\n';
}

/*
 * allocare una variabile di tipo intero, incrementarla attraverso puntatore,
 * stampare il risultato e deallocarla
*/
void allocAndDeallocInt(){
    int *p = new int;
    (*p) = 0;
    (*p)++;

    std::cout << "Il mio puntatore punta a un valore intero pari a: " << *p << '\n';

    delete p;
    p = NULL;   // Evitiamo dangling pointers
}

/*
 * prendere in input 10 interi e memorizzarli in un array di 10 interi utilizzando i
 * puntatori (le lhs degli assegnamenti sono sempre operazioni *p). Poi stampare
 * i valori
*/
void loadDataInArray(){
    int myArr[10];      // dichiaro l'array
    int *p = myArr;     // punto all'indirizzo dell'array (al suo primo item, myArr[0])
    std::cout << "Inserisci dieci interi premendo invio dopo ognuno di essi: \n";

    for (int i = 0; i < 10; i++){
        std::cin >> *p; // spazio di memoria corrente = n-simo item array
        p++;            // aumento di 1 l'indirizzo corrente (passo all'item successivo)
    }

    // Questo serve a stampare l'array, non serve per l'esercizio...
    p = myArr;
    for (int i = 0; i < 10; i++){
        std::cout << *p << ' '; // scrive l'item corrente
        p++;                    // aumenta indirizzo (passa al prossimo item)
    }
    std::cout << std::endl;
}

/*
 * definire una struttura di 5 campi interi e memorizzarci 5 interi presi in input
 * utilizzando i puntatori (le lhs degli assegnamenti sono sempre operazioni *p).
 * Poi stampare i valori.
*/
void get5inputsAndWrite(){
    struttura5int myStruct;

    // In cpp il nome degli array agisce come puntatore all'indirizzo del primo oggetto contenuto.
    // Quindi arr equivale a dire &arr[0], e *p = arr equivale a dire *p = &arr[0].
    int *p = myStruct.arr;

    // potremmo riscrivere la funzione loadDataInArray per prendere in input un array e una length
    // e riusare quella, ma per lasciare intatto l'esempio precedente non lo farò

    std::cout << "Inserisci 5 interi premendo enter dopo ognuno di essi: \n";
    for (int i = 0; i < 5; i++) {
        std::cin >> *p;
        p++;
    }

    std::cout << "Struttura dati: \n";

    p = myStruct.arr;
    for (int i = 0; i < 5; i++) {
        std::cout << *p << ' ';
        p++;
    }

    std:: cout << '\n';
}

int main()
{
    incrementaVarDueVolte();
    allocAndDeallocInt();
    loadDataInArray();
    get5inputsAndWrite();
    return 0;
}
