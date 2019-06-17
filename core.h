#ifndef CORE_H
#define CORE_H

#include "dado.h"

class Core {
    private:
        Dado ** L1;
        int posicaoAtual;
        int totalPosicoes;
    
    public:
        Core();
        Core(int qtd);
        void leitura(Dado * dado);
        void getL1();
};

#endif