#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "dado.h"
#include "cache.h"
#include "memoria.h"

class Processador {
    private:
        Cache * c1;
        Cache * c2;
        Cache * L2;
        Memoria * memory;
        int posicaoAtual;
        int totalPosicoes;
    
    public:
        Processador();
        void defineMemoriaPrincipal(Memoria * memoryPrimary);
        void leitura(int id_cache, int end);
        void getL2();
};

#endif