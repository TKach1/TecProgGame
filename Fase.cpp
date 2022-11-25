#include "Fase.h"
#include <stdlib.h>
using std::rand;
using std::srand;
#include <time.h>
using std::time;

Fase::Fase(Jogador* play) {
	//window = _window;
	//view.setSize((sf::Vector2f(0.0f, 0.0f), sf::Vector2f(900.0f, 900.0f)));
	//window->setView(view);
	srand(time(NULL));
	isComplete = false;
	//initFase1(play);
}
Fase::~Fase() {
	deleteFase();
}
//movido para Fase1

void Fase::deleteFase() {
	listEn.del();
}