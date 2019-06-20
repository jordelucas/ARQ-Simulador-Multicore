#include <iostream>
#include "memoria.h"

Memoria::Memoria(int qtd){
    totalPosicoes = qtd;
    memory = new Dado[totalPosicoes];
    for (int i = 0; i < 10; i++) {
        memory[i] = Dado(i+1,i);
    }
}

Memoria::~Memoria() {
    delete[] memory;
}

bool Memoria::verificarEnd(int endereco) {
    for (int i = 0; i < totalPosicoes; i++) {
        if(memory[i].getEndereco() == endereco) {         
            return true;
        }
    }
    return false;
}

Dado * Memoria::getDado(int endereco) {
    for (int i = 0; i < totalPosicoes; i++) {
        if(memory[i].getEndereco() == endereco) {
            return &memory[i];
        }
    } 
    return nullptr;    
}


void Memoria::getMemoria() {
    for (int i = 0; i < totalPosicoes; i++) {
        std::cout << memory[i].getValor() << "|" << memory[i].getEndereco() << "\n";
    }
    std::cout << "\n";
}