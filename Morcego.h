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
    void initOBJ();
    void executarOBJ();
};

