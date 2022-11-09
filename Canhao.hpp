#pragma once
#include "Inimigo.h"
#include "Projetil.hpp"
#include "Jogador.hpp"
class Canhao :
	public Inimigo 
{
private:
    Projetil* bola;
    Jogador* player;
public:

    Canhao(float x, float y);
    ~Canhao();

    Projetil* getProjetil() { return bola; }
    void atirar();
    void setPlayer(Jogador* p);

    virtual void initOBJ();
    virtual void executarOBJ();
    bool isHarmfull();
};