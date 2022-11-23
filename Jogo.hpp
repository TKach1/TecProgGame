#pragma once
//#include <SFML/Graphics.hpp> 
#include "Fase1.h"
#include"Fase2.h"
#include "Jogador.hpp"

class Jogo {
private:

	//sf::RenderWindow window;
	Jogador* player1;
	//Fase fase;
	//ListaEntidades* LEn;
	Fase1* fase1;
	Fase2* fase2;
public:
	Jogo();
	~Jogo();
	void executar();
};
