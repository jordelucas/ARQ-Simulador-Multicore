#include <iostream>
#include "processador.h"

Processador::Processador() {
    totalPosicoes = 6;
    c1 = new Cache[totalPosicoes/3];
    c2 = new Cache[totalPosicoes/3];
    L2 = new Cache[totalPosicoes];
    for(int i = 0; i < totalPosicoes/3; i++){
        c1[i].setInferior(L2);
    }
}

void Processador::leitura(int id_cache, int end){
    if(id_cache == 2){
        if(c2->verificarEnd(end) == false) {
            
        }else{
            std::cout << "Cache hit!\n"
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