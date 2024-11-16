#include <iostream>

struct struttura5int {
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
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

}

int main()
{
    incrementaVarDueVolte();
    allocAndDeallocInt();
    loadDataInArray();
    return 0;
}
