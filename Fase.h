#pragma once
#include "Plataforma.h"
#include "Jogador.hpp"
#include "Lista.h"
#include "Canhao.hpp"

class Fase {
protected:
	Lista listEn;
	Jogador* player;
	Plataforma* plat;
	Canhao* canhao;
	bool isComplete;
	/*sf::RenderWindow* window;
	sf::View view;
	sf::Vector2f direction;*/
	
public:

	Fase(Jogador* play);
	Fase(){}
	~Fase();
	//void initFase1(Jogador* play);
	virtual void executar(){}
	void deleteFase();
	virtual bool getComplete() { return isComplete; }
};