#pragma once
#include "Entidade.hpp"
class Inimigo :
    public Entidade
{
private:

public:

    Inimigo();
    ~Inimigo();

    virtual void initOBJ();
    virtual void executarOBJ();
    bool isHarmfull();
};

