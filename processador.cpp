#include <iostream>
#include "processador.h"

Processador::Processador() {
    totalPosicoes = 6;
    c1 = new Core(totalPosicoes/3);
    c2 = new Core(totalPosicoes/3);

    L2 = new Dado*[totalPosicoes];
    for (int i = 0; i < totalPosicoes; i++) {
        L2[i] = nullptr;
    }
}

void Processador::leitura(int cache, Dado * dado){
    if(cache == 0){
        if(c2->verificarEnd(dado->getEndereco()) == false) {
            bool situacao = false;
            for (int i = 0; i < totalPosicoes; i++) {
                if(L2[i] == nullptr){
                    situacao = false;
                    break;
                }else{
                    if(L2[i]->getEndereco() == dado->getEndereco()) {
                        situacao = true;
                        break;
                    }
                }
            }
            if(situacao == false) {
                L2[posicaoAtual] = dado;
                posicaoAtual++;
            }
            c2->leitura(dado);
        }
    }else{
        if(c1->verificarEnd(dado->getEndereco()) == false) {
            bool situacao = false;
            for (int i = 0; i < totalPosicoes; i++) {
                if(L2[i] == nullptr){
                    situacao = false;
                    break;
                }else{
                    if(L2[i]->getEndereco() == dado->getEndereco()) {
                        situacao = true;
                        break;
                    }
                }
            }
            if(situacao == false) {
                L2[posicaoAtual] = dado;
                posicaoAtual++;
            }
            c1->leitura(dado);
        }        
    }


}

void Processador::getL2() {
    for (int i = 0; i < totalPosicoes; i++) {
        if(L2[i] == nullptr){
            break;
        }
        std::cout << "L2 - " << L2[i]->getValor() << "\n";
    }
    std::cout << "\n";
}