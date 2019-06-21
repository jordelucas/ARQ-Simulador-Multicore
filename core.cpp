#include <iostream>
#include <unistd.h>
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
        std::cout << "L1 - CACHE HIT\n";
        usleep(2000000);
        std::cout << "\n\nO valor do endereço solicitado é: " << dado->getValor() << "\n\n";
        usleep(2000000);
        return true;
    }else{
        std::cout << "L1 - CACHE MISS\n";
        usleep(2000000);
        dado = nivelInferior->getDado(endereco);
        if(dado != nullptr){
            std::cout << "L2 - CACHE HIT\n";
            usleep(1000000);
            std::cout << "Carregando dado em L1...\n";
            cache.setDado(dado);
            usleep(2000000);            
            leitura(endereco);
            return true;
        }else{
            std::cout << "L2 - CACHE MISS\n";
            usleep(2000000);
            return false;
        }
    }
}

bool Core::escrita(int endereco, int novoValor){
    Dado * dado = cache.getDado(endereco);
    if(dado != nullptr){
        std::cout << "L1 - CACHE HIT\n";
        usleep(2000000);        
        dado->setValor(novoValor);
        std::cout << "\n\nO valor do endereço informado foi alterado para: " << dado->getValor() << "\n\n";
        usleep(2000000);
        return true;
    }else{
        std::cout << "L1 - CACHE MISS\n";
        usleep(2000000);
        dado = nivelInferior->getDado(endereco);
        if(dado != nullptr){
            std::cout << "L2 - CACHE HIT\n";
            usleep(1000000);
            std::cout << "Carregando dado em L1...\n";
            cache.setDado(dado);
            usleep(2000000);
            escrita(endereco, novoValor);
            return true;
        }else{
            std::cout << "L2 - CACHE MISS\n";
            usleep(2000000);
            return false;
        }
    }
}

void Core::setCache(Dado * dado) {
    setL2(dado);
    //setL1(dado);
}

void Core::setL2(Dado * dado) {
    Dado * dadoTemp = nivelInferior->getDado(dado->getEndereco());
    if(dadoTemp == nullptr){
        nivelInferior->setDado(dado);
    }
}

void Core::setL1(Dado * dado) {
    cache.setDado(dado);
}


void Core::listarDados(){
    std::cout << "Situação das memórias Cache:\n\n\n";
    std::cout << "Cache L1\n";
    cache.listar();
    std::cout << "Cache L2\n";
    nivelInferior->listar();
    std::cout << "Obs.: A representação é dada por 'endereco'|'valor'\n\n\n";
}