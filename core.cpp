#include <iostream>
#include "core.h"
#include "dado.h"

Core::Core() {}

Core::Core(Cache * ni){                 //ni = Nível Inferior
    nivelInferior = ni;
    cache = Cache(2);
}

bool Core::leitura(int endereco){
    Dado dado = cache.getDado(endereco);
    if(dado.getEndereco() != -1){
        std::cout << "\nO valor do endereço solicitado é: " << dado.getValor() << "\n";
        return true;
    }else{
        dado = nivelInferior->getDado(endereco);
        if(dado.getEndereco() != -1){
            cache.setDado(&dado);
            std::cout << "\nO valor do endereço solicitado é: " << dado.getValor() << "\n";
            return true;
        }else{
            return false;
        }
    }
}

bool Core::escrita(int endereco, int novoValor){
    Dado dado = cache.getDado(endereco);
    if(dado.getEndereco() != -1){
        dado.setValor(novoValor);
        do{
            dado.getInferior()->setValor(novoValor);
            dado = *dado.getInferior();
        }while(dado.getInferior() != nullptr);
        std::cout << "O novo valor do endereço informado é: " << dado.getValor() << "\n";
        return true;
    }else{
        dado = nivelInferior->getDado(endereco);
        if(dado.getEndereco() != -1){
            cache.setDado(&dado);
            escrita(endereco, novoValor);
            return true;
        }else{
            return false;
        }
    }
}

void Core::setCache(Dado * dado) {
    nivelInferior->setDado(dado);
    cache.setDado(dado);
}

void Core::listarDados(){
    std::cout << "\nEstado das memórias cache:\n";
    std::cout << "\n- Cache L1 -\n";
    cache.listar();
    std::cout << "- Cache L2 -\n";
    nivelInferior->listar();
}