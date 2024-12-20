//
// Created by andre on 17/12/2024.
//

#ifndef CONTOINTERESSI_H
#define CONTOINTERESSI_H
#include "ContoBanca.h"

class ContoInteressi : public ContoBanca {
public:
    ContoInteressi() : ContoBanca() {};
    ContoInteressi(const double _saldo) : ContoBanca(_saldo) {};
    void interessiSaldo() { saldo += saldo/100*2; }
};

#endif //CONTOINTERESSI_H
