#ifndef MEMORIA_H
#define MEMORIA_H

#include <iostream>
#include <fstream>
#include "dado.h"

class Memoria {
    private:
        Dado * memory;
        int totalPosicoes;
    
    public:
        Memoria(int qtd);
        ~Memoria();
        void carregar(std::ifstream & arq_in);
        bool verificarEnd(int endereco);
        Dado * getDado(int endereco);
        void getMemoria();
};

#endif