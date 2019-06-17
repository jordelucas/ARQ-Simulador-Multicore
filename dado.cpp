#include "dado.h"

Dado::Dado() : valor(0), endereco(0){};

Dado::Dado(int num, int endereco) : valor(num), endereco(endereco){};

int Dado::getValor() {
    return valor;
}

int Dado::getEndereco() {
    return endereco;
}

void Dado::setValor(int num) {
    valor = num;
}