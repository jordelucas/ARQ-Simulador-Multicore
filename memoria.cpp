#include <iostream>
#include "memoria.h"

Memoria::Memoria(int qtd){
    totalPosicoes = qtd;
    memory = new Dado[totalPosicoes];
    for (int i = 0; i < 10; i++) {
        memory[i] = Dado(i,i,nullptr);
    }
}

Memoria::~Memoria() {
    delete[] memory;
}

bool Memoria::verificarEnd(int end) {
    for (int i = 0; i < totalPosicoes; i++) {
        if(memory[i].getEndereco() == end) {
            return true;
        }
    }
    return false;
}

Dado Memoria::getDado(int endereco) {
    for (int i = 0; i < totalPosicoes; i++) {
        if(memory[i].getEndereco() == endereco) {
            return memory[i];
        }
    }    
}


void Memoria::getMemoria() {
    std::cout << "\n";
    for (int i = 0; i < totalPosicoes; i++) {
        std::cout << memory[i].getValor() << " ";
    }
    std::cout << "\n";

}