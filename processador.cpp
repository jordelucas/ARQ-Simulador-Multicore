#include <iostream>

#include "processador.h"

Processador::Processador() {
    L2 = Cache(6);
    c1 = Core(&L2);
    c2 = Core(&L2);
    memory = nullptr;
}

void Processador::defineMemoriaPrincipal(Memoria * memoryPrimary){
    memory = memoryPrimary;
}

void Processador::leitura(int id_cache, int end){
    if(id_cache == 2){
        /*if(c2->verificarEnd(end) == false) {
            if(L2->verificarEnd(end) == false) {
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
    */}
    //memory->getMemoria();
    //L2.listar();
    //c1->getCache();
    //c2->getCache();
}

/* void Processador::escrita(int id_cache, int end){
    if(id_cache == 2){
        if(c2->verificarEnd(end) == false) {
            if(L2->verificarEnd(end) == false) {
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
            Dado d1 = c2->getDado(end);
            d1.setValor(10);            
            do{
                d1 = *(d1.getInferior());
                d1.setValor(10);
            }while(d1.getInferior() != nullptr);
        }
    }else{
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
}*/

Core * Processador::getCore(int idCore) {
    if(idCore == 1) {
        return &c1;
    }else{
        return &c2;
    }
}

