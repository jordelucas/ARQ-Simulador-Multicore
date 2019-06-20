#include <iostream>

#include "dado.h"
#include "cache.h"
#include "processador.h"
#include "memoria.h"

int main() {

/* Solicita quantidade de memórias cache */    
    int qtd_cores = 0;
    do {
        std::cout << "Quantos cores deseja adicionar? ";
        std::cin >> qtd_cores;
        if(qtd_cores % 2 != 0) {
            std::cout << "\nÉ necerrário entrar com um número multiplo de 2!\n";
        }
    } while (qtd_cores % 2 != 0);

/* Cria array de processadores */
    Processador * lista = new Processador[qtd_cores/2];

/* Cria memória principal */
    Memoria memory(10);  

/* Vincula memória principal aos processadores */
    Memoria * pontMemory = &memory;
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
        int idCore = 0;
        int temp = 0;
        int p = 0;
        int novoValor = 0;

        if(op == 1){
            std::cout << "Informe o core que será utilizado: ";
            std::cin >> idCore;

            /*  Identifica o processador em que se encontra o 
                core solicitado e determina qual dos dois foi 
                o escolhido */
            if(idCore % 2 == 0) {
                temp = 2;
                p = idCore/2;
            }else{
                temp = 1;
                p = (idCore+1)/2;
            }
            Core * core = lista[p-1].getCore(idCore);

            std::cout << "Informe o endereço que deseja fazer leitura: ";
            std::cin >> endereco;

            /*  Busca pelo respectivo dado do endereço informado */
            /*  Caso não encontre nas memórias cache, é feita 
                uma busca na memória principal.*/
            if(core->leitura(endereco) == false){
                Dado dado = memory.getDado(endereco);
                if(dado.getEndereco() != -1){
                    /*  Ao encontrar o endereço na emória principal, 
                        o dado é carregado nas memórias cache para
                        novamente ser chamada a leitura */
                    core->setCache(dado);
                    core->leitura(endereco);
                }else{
                    /*  Não encontrando o endereço informado, é exibida 
                        a mensagem de notificação do ocorrigo*/
                    std::cout << "O endereço solicitado não faz parte da memória principal!\n";
                }
            }
        }else if (op == 2) {
            std::cout << "Informe o core que será utilizado: ";
            std::cin >> idCore;

            /*  Identifica o processador em que se encontra o 
                core solicitado e determina qual dos dois foi 
                o escolhido */
            if(idCore % 2 == 0) {
                temp = 2;
                p = idCore/2;
            }else{
                temp = 1;
                p = (idCore+1)/2;
            }
            Core * core = lista[p-1].getCore(idCore);

            std::cout << "Informe o endereço que deseja alterar valor: ";
            std::cin >> endereco;
            std::cout << "Informe o novo valor: ";
            std::cin >> novoValor;

            /*  Busca pelo respectivo dado do endereço informado */
            /*  Caso não encontre nas memórias cache, é feita 
                uma busca na memória principal.*/
            if(core->escrita(endereco, novoValor) == false){
                Dado dado = memory.getDado(endereco);
                if(dado.getEndereco() != -1){
                    /*  Ao encontrar o endereço na emória principal, 
                        o dado é carregado nas memórias cache para
                        novamente ser chamada a escrita */
                    core->setCache(dado);
                    core->escrita(endereco, novoValor);
                }else{
                    /*  Não encontrando o endereço informado, é exibida 
                        a mensagem de notificação do ocorrigo*/
                    std::cout << "O endereço solicitado não faz parte da memória principal!\n";
                }
            }
        }
        
                //lista[p-1].leitura(temp, endereco); //Seleciona o processador correto 
                                                    //e passa como parâmetro a cache e
                                                    //o endereço da memoria principal
                //break;

            /*case 2:
                std::cout << "Informe a cache que será utilizada: ";
                std::cin >> idCore;
                std::cout << "Informe o endereco que deseja atualizar o valor: ";
                std::cin >> endereco;  
                std::cout << "Informe o novo valor: ";
                std::cin >> novoValor;

                if(idCore % 2 == 0) {
                    temp = 2;
                    p = idCore/2;
                }else{
                    temp = 1;
                    p = (idCore+1)/2;
                }          

                //lista[p-1].escrita(temp, endereco); //Seleciona o processador correto 
                                                    //e passa como parâmetro a cache e
                                                    //o endereço da memoria principal 
                                                    //que deseja alterar valor               
                break;
            case 0:
                break; */
            //default:
            //    std::cout << "Opção inválida!\n";
            //    break;
        //}
    }
    return 0;
}