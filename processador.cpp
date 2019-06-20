#include <iostream>

#include "processador.h"

Processador::Processador() {
    L2 = Cache(6);
    c1 = Core(&L2);
    c2 = Core(&L2);
}

Core * Processador::getCore(int idCore) {
    if(idCore == 1) {
        return &c1;
    }else{
        return &c2;
    }
}

