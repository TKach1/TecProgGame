#pragma once
#include "Fase.h"
#include "Espinho.hpp"
class Fase1 :
    public Fase
{
private:
    Espinho* spike;
public:
    Fase1(Jogador* play);
    Fase1(){}
    ~Fase1();
    void initFase1(Jogador* play);
    void executar();
    bool getComplete() { return isComplete; }
};

