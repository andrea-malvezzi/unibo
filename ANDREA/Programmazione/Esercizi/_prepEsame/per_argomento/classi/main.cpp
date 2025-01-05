#include <iostream>

class Frazione {
    int numeratore;
    int denominatore;

    public:
        Frazione (int numeratore, int denominatore);

        void stampa() const;
        void moltiplica(Frazione moltiplicatore);
        void addizione(Frazione addendo);
        void sottrazione(Frazione sottraendo);
};

// costruttore.
Frazione::Frazione(const int numeratore, const int denominatore=1) {
    this -> numeratore = numeratore;

    if (denominatore == 0) {
        std::cout << "Il denominatore deve essere diverso da 0. Imposto ad 1." << std::endl;
        this -> denominatore = 1;
    } else
        this -> denominatore = denominatore;
}

// stampa il valore della frazione con un format accettabile.
void Frazione::stampa() const {
    if (this -> denominatore != 1)
        std::cout << numeratore << '/' << denominatore << std::endl;
    else
        std::cout << numeratore << std::endl;
}

// somma due frazioni tra loro.
void Frazione::addizione(const Frazione addendo) {
    if (this -> denominatore == addendo.denominatore)
        this -> numeratore += addendo.numeratore;
    // denom di questa frazione maggiore di quella dell'addendo
    else if (this -> denominatore % addendo.denominatore == 0)
        this -> numeratore += addendo.numeratore * (this -> denominatore / addendo.denominatore);
    // denom dell'addendo maggiore di quello della frazione corrente
    else if (addendo.denominatore % this -> denominatore == 0) {
        this -> numeratore = this -> numeratore * (addendo.denominatore / this -> denominatore) + addendo.numeratore;
        this -> denominatore = addendo.denominatore;
    }   // altrimenti moltiplicali
    else {
        this -> numeratore = this -> numeratore * addendo.denominatore + addendo.numeratore * this -> denominatore;
        this -> denominatore *= addendo.denominatore;
    }
}

// sottrae due frazioni tra loro
void Frazione::sottrazione(Frazione sottraendo) {
    // 1/3 - 1/2 = -1/6
    if (this -> denominatore == sottraendo.denominatore)
        this -> numeratore -= sottraendo.numeratore;
    // denom di questa frazione maggiore di quella dell'addendo
    else if (this -> denominatore % sottraendo.denominatore == 0)
        this -> numeratore -= sottraendo.numeratore * (this -> denominatore / sottraendo.denominatore);
    // denom dell'addendo maggiore di quello della frazione corrente
    else if (sottraendo.denominatore % this -> denominatore == 0) {
        this->numeratore = this->numeratore * (sottraendo.denominatore / this->denominatore) - sottraendo.numeratore;
        this -> denominatore = sottraendo.denominatore;
    }   // altrimenti moltiplicali
    else {
        this->numeratore = this->numeratore * sottraendo.denominatore - sottraendo.numeratore * this->denominatore;
        this -> denominatore *= sottraendo.denominatore;
    }
}

int main() {
    Frazione startFrac = Frazione(1, 2);
    const Frazione opFrac = Frazione(1, 3);

    std::cout << "Operazioni svolte su:" << std::endl;
    startFrac.stampa();
    opFrac.stampa();

    std::cout << "Addizione:" << std::endl;
    startFrac.addizione(opFrac);
    startFrac.stampa();

    std::cout << "Sottrazione:" << std::endl;
    startFrac.sottrazione(opFrac);
    startFrac.stampa();

    return 0;
}
