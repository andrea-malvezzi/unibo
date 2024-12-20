#include <iostream>

// Calcoli e stampi la lunghezza della parola (numero di caratteri inseriti fino al carattere '\0'
int textLength(const char text[]) {
    int counter = 0;

    while(text[counter] != '\0')
        ++counter;

    return counter;
}

// Chieda all'utente un carattere specifico e conti quante volte questo carattere compare nella parola
int countChar(const char text[], const char &chosenChar) {
    int counter = 0;

    for(int i = 0; i < textLength(text); i++) {
        if(text[i] == chosenChar)
            ++counter;
    }

    return counter;
}

// Inverte l'ordine dei caratteri dell'array in loco (modificando l'array originale)
void invertiArray(char text[], const int length) {
    for(int i = 0; i < length / 2; i++) {
        text[i] += text[length - (i + 1)];
        text[length - (i + 1)] = text[i] - text[length - (i + 1)];
        text[i] = text[i] - text[length - (i + 1)];
    }
}

// Verifichi se la parola è palindroma
bool palindroma(const char text[], const int length) {
    for(int i = 0; i < length / 2; i++)
        if (text[i] != text[length - (i + 1)]) return false;
    return true;
}

// controlla che un carattere sia compreso in un array
bool isIn(const char text[], const char &chosenChar) {
    for(int i = 0; i < textLength(text); i++)
        if(text[i] == chosenChar)
            return true;
    return false;
}

// Crei una nuova sequenza di caratteri, eliminando tutte le vocali (a, e, i, o, u maiuscole e minuscole)
char* senzaVocali(const char text[], const int length) {
    int counter = 0;
    const char vocali[11] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
    char* nuovo = new char[length];

    // controllo che sia vocale
    for(int i = 0; i < length; i++) {
        if(!isIn(vocali, text[i]))
            nuovo[counter++] = text[i];
    }

    nuovo[counter] = '\0';
    return nuovo;
}

// controlla che una lettera sia minuscola
bool isLowerCase(const char &letter) { return !(letter >= 'A' && letter <= 'Z'); }

// Converta tutte le lettere minuscole dell'array in maiuscole (usando il codice ASCII) (+-32)
void changeCase(char text[], const int length) {
    for(int i = 0; i < textLength(text); i++)
        isLowerCase(text[i]) ? text[i] -= 32 : text[i] += 32;
}

int main() {
    // 100 caratteri max => 101, includo '\0'
    char myText[101];
    char chosenChar = ' ';

    std::cout << "Inserisci una parola lunga massimo 100 caratteri: " << std::endl;
    std::cin >> myText;

    std::cout << "TEST------------------------------------" << std::endl;

    std::cout << "La parola inserita ha " << textLength(myText) << " caratteri." << std::endl;
    std::cout << "Inserisci un carattere da contare: " << std::endl;
    std::cin >> chosenChar;
    std::cout << "Il carattere \'" << chosenChar << "\' compare " << countChar(myText, chosenChar) << " volte." << std::endl;

    std::cout << "Array attuale: " << std::endl;
    std::cout << myText << std::endl;
    std::cout << std::endl;

    invertiArray(myText, textLength(myText));

    std::cout << "Array invertito: " << std::endl;
    std::cout << myText << std::endl;
    std::cout << std::endl;

    std::cout << "Palindroma: " << (palindroma(myText, textLength(myText)) ? "vero" : "falso") << '.' << std::endl;

    const char* nuovoArr = senzaVocali(myText, textLength(myText));

    std::cout << "Nuovo array: " << nuovoArr << std::endl;

    std::cout << myText << std::endl;
    changeCase(myText, textLength(myText));
    std::cout << myText << std::endl;

    delete[] nuovoArr;
    return 0;
}
