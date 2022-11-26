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
    int timer;
public:
    Canhao(float x, float y);
    ~Canhao();

    Projetil* getProjetil() { return bola; }
    void atirar();
    void setPlayer(Jogador* p);

    bool tomarDano();
    void initOBJ();
    void executarOBJ();
    bool isHarmfull();
};