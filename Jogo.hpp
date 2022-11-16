#pragma once
#include <SFML/Graphics.hpp> 
#include "Fase.h"

class Jogo {
private:

	sf::RenderWindow window;
	Jogador* player1;
	//Fase fase;
	//ListaEntidades* LEn;
	Fase* fase;
public:
	Jogo();
	~Jogo();
	void executar();
};
