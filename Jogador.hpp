#pragma once
#include "Personagem.hpp"
#include "Objeto.h"
class Jogador : public Personagem
{
private:
	sf::Vector2f velocidade;
	sf::Vector2f inicio;
	bool podePular;
	float jumpHeight;
	int vidas, jumpTimer;
	Objeto espada;
	float espadaX;
	bool isFaced;
	
public:
	void move();
	//void attack();
	Jogador();
	~Jogador();

	Objeto* getEspada() { return &espada; }
	float getPositionx() { return px; }
	void emColisao(sf::Vector2f direction);
	sf::Vector2f getInicio();
	void Dano();
	void reset() { px = getInicio().x; }

	void initOBJ();
	void executarOBJ();
};

