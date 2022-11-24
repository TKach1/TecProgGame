#pragma once
#include "Entidade.hpp"

class Projetil :
    public Entidade
{
private:
    float inix, iniy;
    float vx, vy;
    int multi;
public:

    Projetil(float x, float y);
    ~Projetil();

    void projetar();

    virtual void initOBJ(int m);
    virtual void executarOBJ();
    bool isHarmfull();
};

