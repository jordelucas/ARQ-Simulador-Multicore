#include <iostream>
#include "cache.h"

Cache::Cache() {} ;

Cache::Cache(int qtd){
    totalPosicoes = qtd;
    L1 = new Dado*[totalPosicoes];
    for(int i = 0; i < totalPosicoes; i++){
        L1[i] = nullptr;
    }
    posicaoAtual = 0;
    nivelInferio = nullptr;
}

void Cache::setDado(Dado * dado){
    L1[posicaoAtual] = dado;
    
    if(posicaoAtual == totalPosicoes-1){
        posicaoAtual = 0;
    }else{
        posicaoAtual++;
    }
}

Dado * Cache::getDado(int endereco){
    for (int i = 0; i < totalPosicoes; i++) {
        if(L1[i] != nullptr) {
            if(L1[i]->getEndereco() == endereco) {
                return L1[i];
            }
        }
    }  
    return nullptr;    
}


void Cache::listar () {
    for (int i = 0; i < totalPosicoes; i++) {
        if(L1[i] == nullptr){
            std::cout << "disponível\n";
        }else{
            std::cout << L1[i]->getValor() << "|" << L1[i]->getEndereco() << "\n";
        }
    }
    std::cout << "\n";
}

bool Cache::verificarEnd(int end) {
    for (int i = 0; i < totalPosicoes; i++) {
        if(L1[i] == nullptr) {
            return true;
        }
    }
    return false;
}