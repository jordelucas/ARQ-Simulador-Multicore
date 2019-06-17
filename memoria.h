#ifndef MEMORIA_H
#define MEMORIA_H

#include "dado.h"

class Memoria {
    private:
        Dado * memory;
        int totalPosicoes;
    
    public:
        Memoria(int qtd);
        ~Memoria();
        bool verificarEnd(int endereco);
        Dado getDado(int endereco);
        void getMemoria();
};

#endif