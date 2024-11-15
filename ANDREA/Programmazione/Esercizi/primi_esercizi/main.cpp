#include <iostream>
#include <cmath>

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
    n%2==0 ? std::cout << n << " pari" << '\n' : std::cout << n << " dispari" << '\n';
}

// funzione che trasforma miglia in km (fattore di conversione 1.609)
float convertToKM(const float n){
    const float CONVERSION_RATE = 1.609;
    float kms = (n * CONVERSION_RATE);
    return kms;
}

/*
 * funzione che prende una quantita` in denaro e stampa
 * prima gli euro e poi i Centesimi
 */
void stampaDenaro(const double somma){
    // Potremmo anche chiedere direttamente da qui la somma con cin >> ...

    // Otteniamo la parte intera del numero
    int euro = somma;

    // Per la parte decimale, sottraiamo al numero la parte intera e moltiplichiamo per 100
    int Centesimi = 100*(somma - euro);

    std::cout << "Euro: " << euro << '\n';
    std::cout << "Centesimi: " << Centesimi << '\n';
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
    std::cout << "Inserisci tre interi, uno alla volta, premendo enter dopo averli inseriti. " << '\n';

    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    std::cout << "Hai inserito: " << a << ", " << b << " e " << c << '.' << '\n';
    std::cout << "Al contrario: " << c << ", " << b << " e " << a << '.' << '\n';
}

// funzione che stampa media di 3 numeri interi
void media(int a, int b, int c){
    double media = (a + b + c) / 3;
    std::cout << "Media: " << media << '\n';
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
double calcolaIpotenusa(double cat1, double cat2){
    // Si poteva accorciare? certo. Sarebbe stato leggibile? no. Quindi, evitate.
    double ipotenusa = sqrt((cat1 * cat1) + (cat2 * cat2));
    return ipotenusa;
}

/*
 * programma che calcola l'area di un cerchio dato il raggio
 * dichiarare le variabili usate == pi_greco * raggio * raggio
 */
double areaCerchio(double raggio){
    const double PI = 3.141592653589793;

    // Di nuovo: potrei accorciare. Ma sarebbe meno leggibile, quindi scrivo una riga extra e bona.
    double area = PI * raggio * raggio;
    return area;
}

/*
 *programma che prende in input un prezzo in euro (inclusi Centesimi) e stampa quante e quali
 *monete sono necessarie per pagarlo (con un numero minimo di monete)
 */
void moneteMinimePrezzoEuro(double prezzo){
    int numero2Euro = 0;
    int numero1Euro = 0;
    int numero50Cent = 0;
    int numero20Cent = 0;
    int numero10Cent = 0;
    int numero5Cent = 0;
    int numero2Cent = 0;
    int numero1Cent = 0;

    // Aggiungendo 0.5 garantiamo che il numero sia arrotondato correttamente, dato che
    // di base CPP arrotonda per difetto. (x.5 + 0.5 = x+1; x.3 + 0.5 = x)
    int totaleCentesimi = static_cast<int>(prezzo * 100 + 0.5);

    numero2Euro = totaleCentesimi / 200;
    totaleCentesimi -= numero2Euro * 200;

    numero1Euro = totaleCentesimi / 100;
    totaleCentesimi -= numero1Euro * 100;

    numero50Cent = totaleCentesimi / 50;
    totaleCentesimi -= numero50Cent * 50;

    numero20Cent = totaleCentesimi / 20;
    totaleCentesimi -= numero20Cent * 20;

    numero10Cent = totaleCentesimi / 10;
    totaleCentesimi -= numero10Cent * 10;

    numero5Cent = totaleCentesimi / 5;
    totaleCentesimi -= numero5Cent * 5;

    numero2Cent = totaleCentesimi / 2;
    totaleCentesimi -= numero2Cent * 2;

    numero1Cent = totaleCentesimi;

    std::cout << "Per pagare " << prezzo << " euro ci vogliono un minimo di:" << '\n';
    std::cout << numero2Euro << " monete da 2 euro;" << '\n';
    std::cout << numero1Euro << " monete da 1 euro;" << '\n';
    std::cout << numero50Cent << " monete da 50 centesimi;" << '\n';
    std::cout << numero20Cent << " monete da 20 centesimi;" << '\n';
    std::cout << numero10Cent << " monete da 10 centesimi;" << '\n';
    std::cout << numero5Cent << " monete da 5 centesimi;" << '\n';
    std::cout << numero2Cent << " monete da 2 centesimi;" << '\n';
    std::cout << numero1Cent << " monete da 1 centesimo;" << '\n';
}

/*
 * scrivere un programma che prende in input 3 numeri interi e produce in output
 * una tabella con la differenza dei numeri a due a due.
 */
void tabellaInput(){
    int a, b, c;
    std::cout << "Inserisci 3 numeri, premendo enter dopo ognuno di essi: \n";
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;

    // Heading
    std::cout << " - |\t " << a << " \t " << b << " \t " << c << " \n";
    std::cout << ' ' << a << " | \t  0 \t  " << b-a << "  \t  " << c-a << " \n";
    std::cout << ' ' << b << " | \t  " << a-b << " \t  0 \t  " << c-b << " \n";
    std::cout << ' ' << c << " | \t  " << a-c << " \t  " << b-c << " \t  0 \n";
}



int main()
{
    // Imposto il seme del random (SeedRAND) al tempo corrente,
    // per far si che non esca sempre lo stesso valore a causa di un seme uguale.
    // Mettendo il seme nella funzione si avrebbe sempre lo stesso valore alla chiamata,
    // mentre mettendolo qui si avranno numeri sempre diversi.
    std::srand( std::time(0));

    // Variabili
    float kms=convertToKM(1);

    char x = 'a';
    char y = 'b';

    int random_n;

    double cat1 = 2;
    double cat2 = sqrt(5);
    double ipotenusa;

    double raggio = 5;
    double area;

    // Test cases
    std::cout << "isEven -----------------------" << '\n';
    isEven(2);
    isEven(3);

    std::cout << '\n';

    std::cout << "convertToKM ------------------" << '\n';

    std::cout << "test 1 da miglia a km. Miglia: " << 1 << ". Km: " << kms << '\n';
    kms=convertToKM(1.5);
    std::cout << "test 2 da miglia a km. Miglia: " << 1.5 << ". Km:" << kms << '\n';

    std::cout << '\n';

    std::cout << "stampaDenaro -----------------" << '\n';
    stampaDenaro(1.50);
    stampaDenaro(2.50);

    std::cout << '\n';

    std::cout << "scambia ---------------------" << '\n';
    std::cout << "X equal to: " << x << '\n';
    std::cout << "Y equal to: " << y << '\n';
    scambia(x, y);
    std::cout << "X now equal to: " << x << '\n';
    std::cout << "Y now equal to: " << y << '\n';

    std::cout << '\n';

    std::cout << "stampaInvertiti ------------" << '\n';
    stampaInvertiti();

    std::cout << '\n';

    std::cout << "media ----------------------" << '\n';
    std::cout << "Prova 1. ";
    media(1, 2, 3);
    std::cout << "Prova 2. ";
    media(1, 2, 2);

    std::cout << '\n';

    std::cout << "random -------------------- " << '\n';
    random_n = random();
    std::cout << "Numero uscito al primo giro: " << random_n << '\n';
    random_n = random();
    std::cout << "Numero uscito al secondo giro: " << random_n << '\n';

    std::cout << '\n';

    std::cout << "ipotenusa -------------------" << '\n';

    ipotenusa = calcolaIpotenusa(cat1, cat2);
    std::cout << "Cateto 1: " << cat1 << ". Cateto 2: " << cat2 << ". Ipotenusa: " << ipotenusa << '\n';

    std::cout << '\n';

    std::cout << "areaCerchio -------------------" << '\n';

    area = areaCerchio(raggio);
    std::cout << "Raggio cerchio: " << raggio << ". Area: " << area << '\n';

    std::cout << '\n';

    std::cout << "monete -------------------------" << '\n';

    moneteMinimePrezzoEuro(1);
    std::cout << '\n';
    moneteMinimePrezzoEuro(17.53);

    std::cout << '\n';

    std::cout << "tabella ------------------------" << '\n';

    tabellaInput();

    return 0;
}
