#pragma once
#include "Inimigo.h"
class Morcego :
    public Inimigo
{
private:
    int flyrange, fly;
public:
    Morcego(float x, float y);
    ~Morcego();

    bool tomarDano();
    void initOBJ();
    void executarOBJ();
};

