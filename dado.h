#ifndef DADO_H
#define DADO_H

class Dado {
    private:
        int valor;
        int endereco;

    public:
        Dado();
        Dado(int num, int endereco);
        int getValor();
        int getEndereco();
        void setValor(int num);
};

#endif