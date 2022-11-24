#pragma once
#include "Plataforma.h"
#include "Jogador.hpp"
#include "ListaEntidades.hpp"
#include "GerenColisao.hpp"
#include "Canhao.hpp"
#include "Serra.hpp"

class Fase {
private:
	ListaEntidades listEn;
	//Lista listEn;
	Jogador* player;
	Plataforma* plat;
	Canhao* canhao;
	Serra* serra;
	
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