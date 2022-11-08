#pragma once
#include "Plataforma.h"
#include"Jogador.hpp"
#include "Lista.h"

class Fase {
private:
	Lista listEn;
	Jogador* player;
	Plataforma* plat;
	sf::RenderWindow* window;
	sf::View view;
	sf::Vector2f direction;
	
public:

	Fase(Jogador* play, sf::RenderWindow* window);
	~Fase();
	void initFase1();
	void run();
	void deleteFase();
};