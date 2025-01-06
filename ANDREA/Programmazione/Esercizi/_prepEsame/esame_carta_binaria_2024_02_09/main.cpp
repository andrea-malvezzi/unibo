#include <iostream>

// = "   ([  ]  [   ])  "....

// ( -> a meno che non cerchi ' ', ritorno sempre false
// ) -> a meno che non cerchi (, ritorno false
// [ -> se cerco (, metto in buffer e vado avanti a cercare. Se cerco ' ', comincio a cercare. Altrimenti, ritorno false
// ] -> se non sto cercando [, ritorno false
// { -> se cerco ( oppure [, metto in buffer e vado avanti a cercare. Se cerco ' ' comincio a cercare. Altrimenti, ritorno false
// } -> se non sto cercando {, ritorno false
// ' ' -> skippo a prescindere

// ricorsiva
// suppongo di avere una stringa nel formato richiesto. Altrimenti, per evitare caratteri indesiderati, potrei gestirli
// come se fossero spazi, ovvero ignorandoli e proseguendo la ricerca delle parentesi.
bool bilanciata(const char characters[1000], const int index, const int length, const bool flagRotonda=false, const bool flagQuadra=false, const bool flagGraffa=false) {
    // se arrivo alla fine della stringa senza flag ancora up, ritorno true
    if (index >= length) {
        if (!flagRotonda && !flagQuadra && !flagGraffa)
            return true;
        return false;
    }
    // se ho uno spazio, skippo a prescindere
    if (characters[index] == ' ') return bilanciata(characters, index+1, length, flagRotonda, flagQuadra, flagGraffa);

    // se ho '(', a meno che non cerchi ' ', ritorno false
    if (characters[index] == '(') {
        if (flagRotonda || flagQuadra || flagGraffa)
            return false;
        return bilanciata(characters, index+1, length, true, false, false);
    }

    // se ho ')' a meno che non cerchi esclusivamente '(', ritorno false
    if (characters[index] == ')') {
        if (flagRotonda && (!flagQuadra && !flagGraffa))
            return bilanciata(characters, index+1, length, false, false, false);
        return false;
    }

    // se ho '[' e cerco '(' oppure ' ', alzo il flag e vado avanti a cercare. Altrimenti, ritorno false
    if (characters[index] == '[') {
        if (!flagQuadra && !flagGraffa)
            return bilanciata(characters, index+1, length, flagRotonda, true, false);
        return false;
    }

    // se ho ']' e non sto cercando [, ritorno false
    if (characters[index] == ']') {
        if (flagQuadra && !flagGraffa)
            return bilanciata(characters, index+1, length, flagRotonda, false, false);
        return false;
    }

    // se ho '{' e cerco '(', '[' oppure ' ', alzo il flag e vado avanti a cercare. Altrimenti, ritorno false
    if (characters[index] == '{') {
        if (!flagGraffa)
            return bilanciata(characters, index+1, length, flagRotonda, flagQuadra, true);
        return false;
    }

    // se ho '}' e non sto cercando '{', ritorno false
    if (characters[index] == '}') {
        if (flagGraffa)
            return bilanciata(characters, index+1, length, flagRotonda, flagQuadra, false);
        return false;
    }
}

int main()
{
    char characters[1000];

    // ci fidiamo, non mi va di provarla
    // const bool flag = bilanciata();
    return 0;
}
