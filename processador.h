#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "dado.h"
#include "core.h"

class Processador {
    private:
        Core * c1;
        Core * c2;
        Dado ** L2;
        int posicaoAtual;
        int totalPosicoes;
    
    public:
        Processador();
        void leitura(int cache, Dado * dado);
        void getL2();
};

#endif