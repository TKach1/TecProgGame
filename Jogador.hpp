#pragma once
#include "Entidade.hpp"
class Jogador : public Entidade
{
private:
	sf::Vector2f velocidade;
	sf::Vector2f inicio;
	bool podePular;
	float jumpHeight;
	int vidas, jumpTimer;
public:
	void move();
	//void attack();
	Jogador();
	~Jogador();
	sf::Vector2f getPosition() { return body.getPosition(); }
	void emColisao(sf::Vector2f direction);
	sf::Vector2f getInicio();
	void Dano();
	void reset() { body.setPosition(getInicio()); }

	void initOBJ();
};

