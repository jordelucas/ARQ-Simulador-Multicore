#include <iostream>

class core {
    private:
        int ** L1;
    
    public:
        core(int);
};

core::core(int posicoes){
    L1 = new int*[posicoes];
    for(int i = 0; i < posicoes; ++i) {
        L1[i] = nullptr;
    }
};

class processador {
    private:
        core c1;
        core c2;
        int ** L2;
    
    public: 
        processador();
};

int main() {
    int * memory = new int[10];
    for (int i = 0; i < 10; i++) {
        memory[i] = i;
    }

    for (int i = 0; i < 10; i++) {
        std::cout << memory[i] << "\n";
    }
    
    int qtd_cores = 0;

    std::cout << "Quantos cores deseja adicionar? ";
    std::cin >> qtd_cores;
    while (qtd_cores % 2 != 0) {
        std::cout << "\nÉ necerrário entrar com um número multiplo de 2!\n";
        std::cout << "Quantos cores deseja adicionar?";
        std::cin >> qtd_cores;
    }
    processador * lista = new processador[qtd_cores/2];
    
    delete [] memory;
    return 0;
}