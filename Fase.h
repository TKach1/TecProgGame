#pragma once
#include "Plataforma.h"
#include "Jogador.hpp"
#include "Lista.h"
#include "Canhao.hpp"

class Fase {
private:
	Lista listEn;
	Jogador* player;
	Plataforma* plat;
	Canhao* canhao;
	/*sf::RenderWindow* window;
	sf::View view;
	sf::Vector2f direction;*/
	
public:

	Fase(Jogador* play);
	~Fase();
	void initFase1(Jogador* play);
	void run();
	void deleteFase();
};