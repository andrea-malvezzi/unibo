#include <iostream>
#include "ContoInteressi.h"

int main() {
    // es1 */
    auto conto = ContoInteressi(100);
    std::cout << "Conto pre-interessi: " << conto.getSaldo() << std::endl;
    conto.interessiSaldo();
    std::cout << "Conto post-interessi: " << conto.getSaldo() << std::endl;

    // es2


    return 0;
}
