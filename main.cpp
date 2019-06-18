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
    int op = -1; 
    while(op != 0) {
        std::cout << "Deseja fazer leitura(1), atualizar dado(2) ou sair(0)? ";
        std::cin >> op;
        std::cout << "\n\n";

        int endereco = 0;
        int IDcache = 0;
        int temp = 0;
        int p = 0;

        switch (op) {
            case 1:
                std::cout << "Informe o endereco: ";
                std::cin >> endereco;
                std::cout << "Informe a cache: ";
                std::cin >> IDcache;

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
                break;
            /*case 2:
                break;*/
            case 0:
                break;
            default:
                std::cout << "Opção inválida!\n";
                break;
        }
    }
    
    
    return 0;
}