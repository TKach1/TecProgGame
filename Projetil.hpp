#pragma once
#include "Entidade.hpp"

class Projetil :
    public Entidade
{
private:
    sf::Vector2f velocidade;
    sf::Vector2f initialPos;
    int multi;
public:

    Projetil(sf::Vector2f pos);
    ~Projetil();

    void projetar();

    virtual void initOBJ(int m);
    virtual void executarOBJ();
    bool isHarmfull();
};

