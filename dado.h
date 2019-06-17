#ifndef DADO_H
#define DADO_H

class Dado {
    private:
        int valor;
        int endereco;
        Dado * camadaInferior;

    public:
        Dado();
        Dado(int num, int endereco, Dado * camadaInferior);
        int getValor();
        int getEndereco();
        void setValor(int num);
        void setInferior(Dado inferior);
};

#endif