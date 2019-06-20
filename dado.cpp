#include "dado.h"

Dado::Dado() : valor(-1), endereco(-1), nivelInferior(nullptr) {};

Dado::Dado(int num, int id, Dado * inferior) : valor(num), endereco(id), nivelInferior(inferior){};

int Dado::getValor() {
    return valor;
}

int Dado::getEndereco() {
    return endereco;
}

void Dado::setValor(int num) {
    valor = num;
}

void Dado::setInferior(Dado * inferior) {
    nivelInferior = inferior;
}

Dado * Dado::getInferior() {
    return nivelInferior;
}