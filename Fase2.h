#pragma once
#include "Fase.h"
class Fase2 :
    public Fase
{
public:
    Fase2(Jogador* play);
    Fase2(){}
    ~Fase2();
    void initFase2(Jogador* play);
    void executar();
    bool getComplete() { return isComplete; }
};

