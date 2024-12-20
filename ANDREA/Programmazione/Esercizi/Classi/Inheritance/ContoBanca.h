//
// Created by andre on 17/12/2024.
//

#ifndef CONTOBANCA_H
#define CONTOBANCA_H

class ContoBanca {
protected:
    double saldo;
public:
    ContoBanca() : saldo(0) {};
    ContoBanca(const double _saldo) { saldo = _saldo; }
    void versa(const double amount) { saldo += amount; }
    void preleva(const double amount) {
        if (saldo > amount) {
            std::cout << "Fondi insufficienti: prelievo non autorizzato." << std::endl;
        } else {
            saldo -= amount;
            std::cout << "Prelievo di " << amount << " autorizzato." << std::endl;
        }
    }
    double getSaldo() { return saldo; }
};

#endif //CONTOBANCA_H
