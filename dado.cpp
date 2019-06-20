#include "dado.h"

Dado::Dado() : valor(-1), endereco(-1) {};

Dado::Dado(int num, int id) : valor(num), endereco(id) {};

int Dado::getValor() {
    return valor;
}

int Dado::getEndereco() {
    return endereco;
}

void Dado::setValor(int num) {
    valor = num;
}