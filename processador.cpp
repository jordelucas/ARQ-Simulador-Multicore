#include <iostream>
#include "processador.h"

Processador::Processador() {
    totalPosicoes = 6;
    c1 = new Cache[totalPosicoes/3];
    c2 = new Cache[totalPosicoes/3];
    L2 = new Cache[totalPosicoes];
    memory = nullptr;
}

void Processador::defineMemoriaPrincipal(Memoria * memoryPrimary){
    memory = memoryPrimary;
}

void Processador::leitura(int id_cache, int end){
    std::cout << "oi\n";
    std::cout << memory->getDado(7).getValor();
    if(id_cache == 2){
        std::cout << "ent2\n";
        if(c2->verificarEnd(end) == false) {
            std::cout << "nao passou na verificação do endereço da L1\n";
            if(L2->verificarEnd(end) == false) {
                std::cout << "nao passou na verificação do endereço da L2\n";
                if(memory->verificarEnd(end) == false) {
                    std::cout << "O endereço solicitado não faz parte da memória principal!\n";
                    return;
                }else{
                    L2->setDado(memory->getDado(end));
                    c2->setDado(L2->getDado(end));
                }
            }else{
                c2->setDado(L2->getDado(end));
            }      
        }else{
            std::cout << "Cache hit!\n";
        }
    }else{
        std::cout << "ent1\n";
        if(c1->verificarEnd(end) == false) {
            if(L2->verificarEnd(end) == false) {
                if(memory->verificarEnd(end) == false) {
                    std::cout << "O endereço solicitado não faz parte da memória principal!\n";
                    return;
                }else{
                    L2->setDado(memory->getDado(end));
                    c1->setDado(L2->getDado(end));
                }
            }else{
                c1->setDado(L2->getDado(end));
            }      
        }else{
            std::cout << "Cache hit!\n";
        }        
    }
}

void Processador::getL2() {
    for (int i = 0; i < totalPosicoes; i++) {
        std::cout << "Memoria - " << memory->getDado(i).getValor() << "\n";
    }
    std::cout << "\n";
}
