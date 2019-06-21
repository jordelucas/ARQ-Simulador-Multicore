#ifndef CORE_H
#define CORE_H

#include "cache.h"
#include "dado.h"

class Core {
    private:
        Cache cache;
        Cache * nivelInferior;
    
    public:
        Core();
        Core(Cache * nivelInferior);
        bool leitura(int endereco);
        bool escrita(int endereco, int novoValor);
        void setCache(Dado * dado);
        void setL1(Dado * dado);
        void setL2(Dado * dado);
        void listarDados();
};

#endif