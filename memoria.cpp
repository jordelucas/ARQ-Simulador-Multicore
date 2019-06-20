#include <iostream>
#include "memoria.h"

Memoria::Memoria(int qtd){
    totalPosicoes = qtd;
    memory = new Dado[totalPosicoes];
}

Memoria::~Memoria() {
    delete[] memory;
}

void Memoria::carregar(std::ifstream & arq_in) {
    int valor = 0;
    for (int i = 0; i < totalPosicoes; ++i) {
        arq_in >> valor;
        memory[i] = Dado(valor,i);
    }
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