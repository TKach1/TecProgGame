#pragma once
#include "Personagem.hpp"
#include "Objeto.h"
class Jogador : public Personagem
{
private:
	float vx, vy;
	sf::Vector2f inicio;
	bool podePular;
	float jumpHeight;
	int vidas, jumpTimer;
	Objeto espada;
	float espadaX;
	bool isFaced;
	int time;
	bool attack;
	
public:
	int anim;

	void move();
	//void attack();
	Jogador();
	~Jogador();

	Objeto* getEspada() { return &espada; }
	float getPositionx() { return px; }
	void emColisao(float dx, float dy);
	sf::Vector2f getInicio();
	void Dano();
	void reset() { px = getInicio().x; }

	void initOBJ();
	void executarOBJ();
};

