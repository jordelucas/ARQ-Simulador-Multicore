#include <iostream>
#include "processador.h"

Processador::Processador() {
    totalPosicoes = 6;
    c1 = new Core(totalPosicoes/3);
    c2 = new Core(totalPosicoes/3);

    L2 = new Dado*[totalPosicoes];
    for (int i = 0; i < totalPosicoes; i++) {
        L2[i] = nullptr;
    }
}

void Processador::leitura(int cache, Dado * dado){
    L2[posicaoAtual] = dado;
    posicaoAtual++;
    if(cache == 0){
        c2->leitura(dado);
    }
}

void Processador::getL2() {
    for (int i = 0; i < totalPosicoes; i++) {
        if(L2[i] == nullptr){
            break;
        }
        std::cout << "L2 - " << L2[i]->getValor() << "\n";
    }
    std::cout << "\n";
}