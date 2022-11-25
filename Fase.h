#pragma once
#include "Plataforma.h"
#include "Jogador.hpp"
#include "ListaEntidades.hpp"
#include "GerenColisao.hpp"
#include "Canhao.hpp"
#include "Serra.hpp"
#include"Vampiro.h"

#include "Morcego.h"
class Fase {
protected:
	ListaEntidades listEn;
	//Lista listEn;
	Jogador* player;
	Plataforma* plat;
	Canhao* canhao;
	Serra* serra;
	Vampiro* vamp;
	
	bool isComplete;
	Morcego* morcego;
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