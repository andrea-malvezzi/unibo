#include <iostream>

// le seguenti due servono per il random
#include <cstdlib>  // contiene rand() e srand()
#include <ctime>    // contiene time()

/*
 * funzione che dato un numero intero scrive 0
 * se il numero è pari e 1 se il numero è dispari
 */
void isEven(const int n){
    /*
     * Questo si chiama operatore ternario.
     * Segue la seguente forma: operazione ? caso_true : caso_false.
     * In questo caso, se n%2==0, allora scrivi n pari, altrimenti n dispari.
     */
    n%2==0 ? std::cout << n << " pari" << std::endl : std::cout << n << " dispari" << std::endl;
}

// funzione che trasforma miglia in km (fattore di conversione 1.609)
float convertToKM(const float n){
    const float CONVERSION_RATE = 1.609;
    float kms = (n * CONVERSION_RATE);
    return kms;
}

/*
 * funzione che prende una quantita` in denaro e stampa
 * prima gli euro e poi i centesimi
 */
void stampaDenaro(const double somma){
    // Potremmo anche chiedere direttamente da qui la somma con cin >> ...

    // Otteniamo la parte intera del numero
    int euro = somma;

    // Per la parte decimale, sottraiamo al numero la parte intera e moltiplichiamo per 100
    int centesimi = 100*(somma - euro);

    std::cout << "Euro: " << euro << std::endl;
    std::cout << "Centesimi: " << centesimi << std::endl;
}

/*
 *dato questo frammento di codice
 *char x, y ;
 *cin >> x >> y ;
 *…
 *cout << x << y ;
 *scrivere una sequenza di comandi che scambia il valore di due
 *identificatori (quando gli identificatori sono int o double, si può
 *fare senza un terzo identificatore…)
 */
void scambia(char& x, char& y){
    // Potremmo anche prendere l'input con cin...
    x += y;     // es. x = 1 + 2 = 3
    y = x - y;  // es. y = 3 - 2 = 1 = x originale
    x -= y;     // es. x = 3 - 1 = 2 = y originale

    // Funziona anche con i char dato che il PC salva i caratteri come sequenze di cifra specifiche.
    // Questo torna utile quando si vogliono effettuare operazioni con essi, come in questo caso.
}

// funzione che prende in input tre reali e li stampa in modo invertito
void stampaInvertiti(){
    // Per mostrare come usare cin, qui useremo questa funzione
    int a, b, c;
    std::cout << "Inserisci tre interi, uno alla volta, premendo enter dopo averli inseriti. " << std::endl;

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    std::cout << "Hai inserito: " << a << ", " << b << " e " << c << '.' << std::endl;
    std::cout << "Al contrario: " << c << ", " << b << " e " << a << '.' << std::endl;
}

// funzione che stampa media di 3 numeri interi
void media(int a, int b, int c){
    double media = (a + b + c) / 3;
    std::cout << "Media: " << media << std::endl;
}

// programma che genera un numero random tra 0 e 89
int random(){
    // ritorno un random (rand()), tra 0 e 89 quindi %90.
    // es. 100%90 darebbe 10, 89%90 rimane 89 e 90%90 darebbe 0.
    return std::rand()%90;
}

/*
 * programma che prende in input  la lunghezza di due
 * cateti di un triangolo rettangolo e stampa la lunghezza
 * dell'ipotenusa
 */


/*
 * programma che calcola l'area di un cerchio dato il raggio
 * dichiarare le variabili usate == pi_greco * raggio * raggio
 */

/*
 *programma che prende in input un prezzo in euro (inclusi centesimi) e stampa quante e quali
 *monete sono necessarie per pagarlo (con un numero minimo di monete)
 */

/*
 * scrivere un programma che prende in input 3 numeri interi e produce in output
 * una tabella con la differenza dei numeri a due a due.
 */



int main()
{
    // Imposto il seme del random (SeedRAND) al tempo corrente,
    // per far si che non esca sempre lo stesso valore a causa di un seme uguale.
    // Mettendo il seme nella funzione si avrebbe sempre lo stesso valore alla chiamata,
    // mentre mettendolo qui si avranno numeri sempre diversi.
    std::srand( std::time(0));

    std::cout << "isEven -----------------------" << std::endl;
    isEven(2);
    isEven(3);

    std::cout << std::endl;

    std::cout << "convertToKM ------------------" << std::endl;
    float kms=convertToKM(1);
    std::cout << "test 1 da miglia a km. Miglia: " << 1 << ". Km: " << kms << std::endl;
    kms=convertToKM(1.5);
    std::cout << "test 2 da miglia a km. Miglia: " << 1.5 << ". Km:" << kms << std::endl;

    std::cout << std::endl;

    std::cout << "stampaDenaro -----------------" << std::endl;
    stampaDenaro(1.50);
    stampaDenaro(2.50);

    std::cout << std::endl;

    std::cout << "scambia ---------------------" << std::endl;
    char x = 'a';
    char y = 'b';
    std::cout << "X equal to: " << x << std::endl;
    std::cout << "Y equal to: " << y << std::endl;
    scambia(x, y);
    std::cout << "X now equal to: " << x << std::endl;
    std::cout << "Y now equal to: " << y << std::endl;

    std::cout << std::endl;

    std::cout << "stampaInvertiti ------------" << std::endl;
    stampaInvertiti();

    std::cout << std::endl;

    std::cout << "media ----------------------" << std::endl;
    std::cout << "Prova 1. ";
    media(1, 2, 3);
    std::cout << "Prova 2. ";
    media(1, 2, 2);

    std::cout << std::endl;

    std::cout << "random -------------------- " << std::endl;
    int random_n = random();
    std::cout << "Numero uscito al primo giro: " << random_n << std::endl;
    random_n = random();
    std::cout << "Numero uscito al secondo giro: " << random_n << std::endl;

    std::cout << std::endl;



    return 0;
}
