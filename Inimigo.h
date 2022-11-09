#pragma once
#include "Personagem.hpp"
class Inimigo :
    public Personagem
{
private:

public:

    Inimigo();
    ~Inimigo();

    virtual void initOBJ();
    virtual void executarOBJ();
    bool isHarmfull();
};

