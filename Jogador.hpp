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
	
public:
	void move();
	//void attack();
	Jogador();
	~Jogador();

	Objeto* getEspada() { return &espada; }
	sf::Vector2f getPosition() { return body.getPosition(); }
	void emColisao(sf::Vector2f direction);
	sf::Vector2f getInicio();
	void Dano();
	void reset() { body.setPosition(getInicio()); }

	void initOBJ();
	void executarOBJ();
};

