#ifndef PROCESSADOR_H
#define PROCESSADOR_H

#include "dado.h"
#include "cache.h"
#include "memoria.h"
#include "core.h"

class Processador {
    private:
        Core c1;
        Core c2;
        Cache L2;
    
    public:
        Processador();
        Core * getCore(int idCore);
};

#endif