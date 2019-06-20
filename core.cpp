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
        std::cout << "O valor do endereço solicitado é: " << dado.getValor() << "\n";
        cache.listar();
        nivelInferior->listar();
        return true;
    }else{
        dado = nivelInferior->getDado(endereco);
        if(dado.getEndereco() != -1){
            std::cout << "\nencontrei\n";
            cache.setDado(dado);
            std::cout << "O valor do endereço solicitado é: " << dado.getValor() << "\n";
            cache.listar();
            nivelInferior->listar();
            return true;
        }else{
            std::cout << "\nnão encontrei\n";
            cache.listar();
            nivelInferior->listar();
            return false;
        }
    }
}

bool Core::escrita(){
    return true;
}

void Core::setCache(Dado dado) {
    nivelInferior->setDado(dado);
    cache.setDado(dado);
}
