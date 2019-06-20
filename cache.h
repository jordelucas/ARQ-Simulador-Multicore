#ifndef CACHE_H
#define CACHE_H

#include "dado.h"

class Cache {
    private:
        Dado ** L1;
        int posicaoAtual;
        int totalPosicoes;
        Cache * nivelInferio;
    
    public:
        Cache();
        Cache(int qtd);
        Dado * getDado(int endereco);
        void setDado(Dado *dado);
        bool verificarEnd(int endereco);
        void listar();
};

#endif