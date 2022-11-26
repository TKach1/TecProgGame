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
	Ente* hp;
	float espadaX;
	bool isFaced;
	int time;
	int timerD;
	bool attack;
	int points;
	
public:
	int anim;

	void operator++() { points++; }
	void move();
	//void attack();
	Jogador();
	~Jogador();

	int getPoints() { return points; }
	Objeto* getEspada() { return &espada; }
	float getPositionx() { return px; }
	void emColisao(float dx, float dy);
	sf::Vector2f getInicio();
	bool Dano();
	void reset() { px = getInicio().x; py = getInicio().y; points = 0; }

	void initOBJ();
	void executarOBJ();
};

