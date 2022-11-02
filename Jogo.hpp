#pragma once
#include <SFML/Graphics.hpp>
#include "Jogador.hpp"

class Jogo {
private:

	sf::RenderWindow window;
	Jogador* player1;
	//ListaEntidades* LEn;
	//Fase* fase;
public:
	Jogo();
	~Jogo();
	void executar();
};
