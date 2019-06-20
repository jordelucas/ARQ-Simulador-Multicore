#include <iostream>
#include "core.h"
#include "dado.h"

Core::Core() {}

Core::Core(Cache * ni){                 //ni = Nível Inferior
    nivelInferior = ni;
    cache = Cache(4);
}

bool Core::leitura(int endereco){
    Dado * dado = cache.getDado(endereco);
    if(dado != nullptr){
        std::cout << "\nO valor do endereço solicitado é: " << dado->getValor() << "\n";
        return true;
    }else{
        dado = nivelInferior->getDado(endereco);
        if(dado != nullptr){
            cache.setDado(dado);
            std::cout << "\nO valor do endereço solicitado é: " << dado->getValor() << "\n";
            return true;
        }else{
            return false;
        }
    }
}

bool Core::escrita(int endereco, int novoValor){
    Dado * dado = cache.getDado(endereco);
    if(dado != nullptr){
        dado->setValor(novoValor);
        /*do{
            std::cout << dado->getInferior()->getInferior() << "|entrou|\n";
            dado->getInferior()->setValor(novoValor);
            dado = dado->getInferior();
        }while(dado->getInferior() != nullptr); */
        std::cout << "O valor do endereço informado foi alterado para: " << dado->getValor() << "\n";
        return true;
    }else{
        dado = nivelInferior->getDado(endereco);
        if(dado != nullptr){
            cache.setDado(dado);
            escrita(endereco, novoValor);
            return true;
        }else{
            return false;
        }
    }
}

void Core::setCache(Dado * dado) {
    nivelInferior->setDado(dado);
    cache.setDado(nivelInferior->getDado(dado->getEndereco()));
}

void Core::listarDados(){
    std::cout << "\nEstado das memórias cache:\n";
    std::cout << "\n- Cache L1 -\n";
    cache.listar();
    std::cout << "- Cache L2 -\n";
    nivelInferior->listar();
}