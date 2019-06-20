#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "dado.h"
#include "cache.h"
#include "memoria.h"
#include "core.h"

class Processador {
    private:
        Core c1;
        Core c2;
        Cache L2;
        Memoria * memory;
        int posicaoAtual;
        int totalPosicoes;
    
    public:
        Processador();
        void defineMemoriaPrincipal(Memoria * memoryPrimary);
        Core * getCore(int idCore);
        void leitura(int id_cache, int end);
        void escrita(int id_cache, int end);
};

#endif