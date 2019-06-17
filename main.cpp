#include <iostream>

#include "dado.h"
#include "cache.h"
#include "processador.h"

int main() {
/* Criando memórias cache */
    int qtd_cores = 0;
    do {
        std::cout << "Quantos cores deseja adicionar? ";
        std::cin >> qtd_cores;
        if(qtd_cores % 2 != 0) {
            std::cout << "\nÉ necerrário entrar com um número multiplo de 2!\n";
        }
    } while (qtd_cores % 2 != 0);

    Processador * lista = new Processador[qtd_cores/2];

/* Criando memória principal */
    Dado * memory = new Dado[10];
    for (int i = 0; i < 10; i++) {
        memory[i] = Dado(i,i,nullptr);
    }

    memory[7].setValor(31);
    memory[8].setValor(33);

    std::cout << "\n";
    for (int i = 0; i < 10; i++) {
        std::cout << memory[i].getValor() << " ";
    }
    std::cout << "\n";

/* Verificação da tarefa a ser executada */    
    int op = 0;
    std::cout << "Deseja fazer leitura(1), atualizar dado(2) ou sair(3)? ";
    std::cin >> op;
    std::cout << "\n\n";

    if(op == 1) {
        int end = 0;
        std::cout << "Informe o endereco: ";
        std::cin >> end;
        int cache = 0;
        std::cout << "Informe a cache: ";
        std::cin >> cache;

        int temp = 0;
        int p = 0;
        if(cache % 2 == 0) {
            temp = 2;
            p = cache/2;
        }else{
            temp = 1;
            p = (cache+1)/2;
        }

        lista[p-1].leitura(temp, end);

        lista[p-1].getL2();

        //lista[0].leitura(cache, &memory[1]);
    }
    
    
    delete [] memory;
    return 0;
}