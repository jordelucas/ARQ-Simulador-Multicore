#include <iostream>

#include "dado.h"
#include "core.h"
#include "processador.h"

int main() {

    int qtd_cores = 0;
    do {
        std::cout << "Quantos cores deseja adicionar? ";
        std::cin >> qtd_cores;
        if(qtd_cores % 2 != 0) {
            std::cout << "\nÉ necerrário entrar com um número multiplo de 2!\n";
        }
    } while (qtd_cores % 2 != 0);

    Dado * memory = new Dado[10];
    for (int i = 0; i < 10; i++) {
        memory[i] = Dado(i,i);
    }

    memory[7].setValor(31);
    memory[8].setValor(33);

    std::cout << "\n";
    for (int i = 0; i < 10; i++) {
        std::cout << memory[i].getValor() << " ";
    }
    std::cout << "\n";

    Processador * lista = new Processador[qtd_cores/2];
    /*
    int op = 0;
    std::cout << "Deseja fazer leitura(1) ou atualizar dado(2)? ";
    std::cin >> op;
    std::cout << "\n\n";

    if(op == 1) {
        int end = 0;
        std::cout << "Informe o endereco: ";
        std::cin >> end;
        int cache = 0;
        std::cout << "Informe a cache: ";
        std::cin >> cache;
        lista[0].leitura(cache, &memory[1]);
    }
    */
    
    delete [] memory;
    return 0;
}