#include <iostream>
#include "cache.h"

Cache::Cache() {} ;

Cache::Cache(int qtd){
    totalPosicoes = qtd;
    L1 = new Dado[totalPosicoes];
    posicaoAtual = 0;
}

void Cache::setDado(Dado dado){
    L1[posicaoAtual] = dado;
    L1[posicaoAtual].setInferior(dado);
    posicaoAtual++;
}

Dado Cache::getDado(int endereco){
    for (int i = 0; i < totalPosicoes; i++) {
        if(L1[i].getEndereco() == endereco) {
            return L1[i];
        }
    }      
}

/*
void Cache::getL1 () {
    for (int i = 0; i < totalPosicoes; i++) {
        std::cout << "L1 - " << L1[i]->getValor() << "\n";
    }
    std::cout << "\n";
}
*/
bool Cache::verificarEnd(int end) {
    for (int i = 0; i < totalPosicoes; i++) {
        if(posicaoAtual == 0){
            return false;
        }else{
            if(L1[i].getEndereco() == end) {
                return true;
            }
        }
    }
    return false;
}