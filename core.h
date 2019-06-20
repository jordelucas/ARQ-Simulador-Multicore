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
        bool escrita();
        void setCache(Dado dado);
};

#endif