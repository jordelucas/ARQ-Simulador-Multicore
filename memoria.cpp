#include <iostream>
#include "memoria.h"

Memoria::Memoria(int qtd){
    totalPosicoes = qtd;
    memory = new Dado[totalPosicoes];
    for (int i = 0; i < 10; i++) {
        memory[i] = Dado(i+1,i,nullptr);
    }
}

Memoria::~Memoria() {
    delete[] memory;
}

bool Memoria::verificarEnd(int end) {
    std::cout << "verificando se o endereço solicitado está na memória principal\n";
    for (int i = 0; i < totalPosicoes; i++) {
        std::cout << "Buscando...\n";
        std::cout << memory[i].getValor() << "\n";
        if(memory[i].getEndereco() == end) {
            std::cout << "Está na posicao: " << i << "\n";            
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