#include <iostream>
#include <fstream>
#include <unistd.h>

#include "dado.h"
#include "cache.h"
#include "processador.h"
#include "memoria.h"

void cabecalho();

int main() {

    cabecalho();
    std::cout << "- Bem vindo!\n\n\n";
/* Solicita quantidade de memórias cache */    
    int qtd_cores = 0;
    do {
        std::cout << "Quantos cores deseja adicionar? ";
        std::cin >> qtd_cores;
        if(qtd_cores % 2 != 0) {
            cabecalho();
            std::cout << "ATENÇÃO!!\n";
            std::cout << "- É necerrário entrar com um número múltiplo de 2!\n";
            std::cout << "- Vamos tentar novamente!\n\n\n";
        }
    } while (qtd_cores % 2 != 0);

/* Cria array de processadores */
    Processador * lista = new Processador[qtd_cores/2];

/* Cria memória principal */
    int tamanho = 32;
    Memoria memoriaPincipal(tamanho); 

    std::ifstream arq_in;
    arq_in.open("teste.txt");
    memoriaPincipal.carregar(arq_in);

/* Verificação da tarefa a ser executada */   
    int op = -1; 

    while(op != 0) {
        cabecalho();
        std::cout << "- Para continuar, escolha uma das opções abaixo:\n\n";
        std::cout << "1 - Leitura\n2 - Escrita\n0 - Sair\n\n";
        std::cout << "Escolha: ";
        std::cin >> op;

        int endereco = 0;
        int idCore = 0;
        int processador = 0;
        int novoValor = 0;
        Core * core = nullptr;

        switch (op) {
        case 1:
            cabecalho();
            do {
                std::cout << "- Informe o core que realizará a leitura: ";
                std::cin >> idCore;
                if(idCore > qtd_cores){
                    cabecalho();
                    std::cout << "ATENÇÃO!!\n";
                    std::cout << "- É necerrário entrar com um número inferior ou igual a " << qtd_cores << "\n";
                    std::cout << "- Vamos tentar novamente!\n\n\n";
                }
            }while(idCore > qtd_cores);

            /*  Identifica o processador em que se encontra o 
                core solicitado e determina qual dos dois foi 
                o escolhido */
            if(idCore % 2 == 0) {
                processador = idCore/2;
                idCore = 2;
            }else{
                processador = (idCore+1)/2;
                idCore = 1;
            }
            core = lista[processador-1].getCore(idCore);

            /*  Lista os dados das memórias cache e solicita endereço
                para leitura */
            core->listarDados();
            std::cout << " - Informe o endereço que deseja fazer leitura (0-31): ";
            std::cin >> endereco;

            /*  Busca pelo respectivo dado do endereço informado */
            /*  Caso não encontre nas memórias cache, é feita 
                uma busca na memória principal.*/
            if(core->leitura(endereco) == false){
                Dado * dado = memoriaPincipal.getDado(endereco);
                if(dado != nullptr){
                    /*  Ao encontrar o endereço na emória principal, 
                        o dado é carregado nas memórias cache para
                        novamente ser chamada a leitura */
                    core->setCache(dado);
                    core->leitura(endereco);
                    core->listarDados();
                }else{
                    /*  Não encontrando o endereço informado, é exibida 
                        a mensagem de notificação do ocorrigo*/
                    std::cout << "O endereço solicitado não faz parte da memória principal!\n";
                }
            }else{
                core->listarDados();
            }
            /* code */
            break;
        case 2:
            cabecalho();
            do {
                std::cout << "- Informe o core que realizará a escrita: ";
                std::cin >> idCore;
                if(idCore > qtd_cores){
                    cabecalho();
                    std::cout << "ATENÇÃO!!\n";
                    std::cout << "- É necerrário entrar com um número inferior ou igual a " << qtd_cores << "\n";
                    std::cout << "- Vamos tentar novamente!\n\n\n";
                }
            }while(idCore > qtd_cores);

            /*  Identifica o processador em que se encontra o 
                core solicitado e determina qual dos dois foi 
                o escolhido */
            if(idCore % 2 == 0) {
                processador = idCore/2;
                idCore = 2;
            }else{
                processador = (idCore+1)/2;
                idCore = 1;
            }
            core = lista[processador-1].getCore(idCore);

            /*  Lista os dados das memórias cache e solicita o endereço
                para escrita e o novo valor a ser atribuído */
            core->listarDados();
            std::cout << "Informe o endereço que deseja alterar valor (0-31): ";
            std::cin >> endereco;
            std::cout << "Informe o novo valor: ";
            std::cin >> novoValor;

            /*  Busca pelo respectivo dado do endereço informado */
            /*  Caso não encontre nas memórias cache, é feita 
                uma busca na memória principal.*/
            if(core->escrita(endereco, novoValor) == false){
                Dado * dado = memoriaPincipal.getDado(endereco);
                if(dado != nullptr){
                    /*  Ao encontrar o endereço na emória principal, 
                        o dado é carregado nas memórias cache para
                        novamente ser chamada a escrita */
                        std::cout << "veio pra ca!\n";
                    core->setCache(dado);
                    core->escrita(endereco, novoValor);
                    core->listarDados();
                }else{
                    /*  Não encontrando o endereço informado, é exibida 
                        a mensagem de notificação do ocorrigo*/
                    std::cout << "O endereço solicitado não faz parte da memória principal!\n";
                }
            }else{
                core->listarDados();
            }
            break;
        case 0:
            break;
        default:
            std::cout << "Opção inválida!\n";
            std::cout << "Aguarde...\n";
            usleep(3000000);
            break;
        }
        if(op == 1){
        }else if (op == 2) {
        }else if (op == 0) {
            break;
        }
    }
    return 0;
}

void cabecalho() {
    system("clear");
    std::cout << "#####################################\n";
    std::cout << "####                             ####\n";
    std::cout << "####   SIMULADOR DE HIERARQUIA   ####\n";
    std::cout << "####   DE MEMÓRIA EM MULTICORE   ####\n";
    std::cout << "####                             ####\n";
    std::cout << "#####################################\n";
    std::cout << "                   Por: Jordevá Lucas\n\n\n";
}