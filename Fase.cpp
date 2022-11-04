#include "Fase.h"


Fase::Fase(Jogador* play, sf::RenderWindow* window) {
	initFase1(play, window);
}
Fase::~Fase() {
	deleteFase();
}
void Fase::initFase1(Jogador* play, sf::RenderWindow* window) {
	player = play;
	player->setwindow(&window);
	playe->body.setPosition(sf::Vector2f(0.f, 0.f));

	for (int i = 0; i < 20; i++) {
		plat = new Plataforma(35.f * i, 100.f);
		listEn->push(plat);

	}
}
void Fase::run() {
	player->move();
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	window.clear();

	player->drawWindow();
	while (int i = 0; i <= listEn.getLen(); i++) {
		listEn.getItem(i)->drawWindow();
	}
	window.display();
}

void Fase::deleteFase() {
	for (int i = 0; i <= listEn.getLen(); i++) {
		listEn.pop(listEn.getItem(i));
	}
}