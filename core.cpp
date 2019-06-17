#include <iostream>
#include "core.h"

Core::Core() {} ;

Core::Core(int qtd){
    totalPosicoes = qtd;
    L1 = new Dado*[totalPosicoes];
    for (int i = 0; i < totalPosicoes; i++) {
        L1[i] = nullptr;
    }
}

void Core::leitura(Dado * dado){
    L1[posicaoAtual] = dado;
    posicaoAtual++;
}

void Core::getL1 () {
    for (int i = 0; i < totalPosicoes; i++) {
        std::cout << "L1 - " << L1[i]->getValor() << "\n";
    }
    std::cout << "\n";
}

bool Core::verificarEnd(int end) {
    for (int i = 0; i < totalPosicoes; i++) {
        if(L1[i] == nullptr){
            return false;
        }else{
            if(L1[i]->getEndereco() == end) {
                return true;
            }
        }
    }
    return false;
}