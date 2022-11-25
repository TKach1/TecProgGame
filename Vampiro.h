#pragma once
#include "Inimigo.h"
class Vampiro :
    public Inimigo
{
private:
    int timer, life, cooldown;
    int invert;
    bool isImmune;
public:
    Vampiro(float x, float y);
    ~Vampiro();
    void initOBJ();
    void executarOBJ();
};

