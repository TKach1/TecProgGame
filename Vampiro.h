#pragma once
#include "Inimigo.h"
class Vampiro :
    public Inimigo
{
private:
    int timer, life, cooldown, timerD;
    int invert;
    bool isImmune;
public:

    bool isDead;
    Vampiro(float x, float y);
    ~Vampiro();

    int getVida() { return life; }
    int getIniVida() { return 3; }
    void initOBJ();
    void executarOBJ();
    bool tomarDano();
};

