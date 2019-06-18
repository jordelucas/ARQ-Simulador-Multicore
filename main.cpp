#include <iostream>

#include "dado.h"
#include "cache.h"
#include "processador.h"
#include "memoria.h"

int main() {

/* Cria memória principal */

    Memoria memory(10);  
    Memoria * pontMemory = &memory;

/* Cria memórias cache */    
    int qtd_cores = 0;
    do {
        std::cout << "Quantos cores deseja adicionar? ";
        std::cin >> qtd_cores;
        if(qtd_cores % 2 != 0) {
            std::cout << "\nÉ necerrário entrar com um número multiplo de 2!\n";
        }
    } while (qtd_cores % 2 != 0);
    Processador * lista = new Processador[qtd_cores/2];

    for(int i = 0; i < qtd_cores/2; i++){
        lista[i].defineMemoriaPrincipal(pontMemory);
    }
/* Verificação da tarefa a ser executada */    
    int op = 0;
    std::cout << "Deseja fazer leitura(1), atualizar dado(2) ou sair(3)? ";
    std::cin >> op;
    std::cout << "\n\n";

    if(op == 1) {
        int endereco = 0;
        std::cout << "Informe o endereco: ";
        std::cin >> endereco;
        int IDcache = 0;
        std::cout << "Informe a cache: ";
        std::cin >> IDcache;

        int temp = 0;
        int p = 0;
        if(IDcache % 2 == 0) {
            temp = 2;
            p = IDcache/2;
        }else{
            temp = 1;
            p = (IDcache+1)/2;
        }

        lista[p-1].leitura(temp, endereco); //Seleciona o processador correto 
                                            //e passa como parâmetro a cache e
                                            //o endereço da memoria principal 
        lista[p-1].leitura(temp, endereco+1);
        lista[p-1].leitura(temp, endereco+2);
        lista[p-1].leitura(temp, endereco+3);
        lista[p-1].leitura(temp, endereco+4);
        lista[p-1].leitura(temp, endereco+5);
        lista[p-1].leitura(temp, endereco+12);

        //lista[p-1].getL2();

        //lista[0].leitura(cache, &memory[1]);
    }
    
    return 0;
}