#include "Fase.h"


Fase::Fase(Jogador* play, sf::RenderWindow* _window) {
	window = _window;
	initFase1(play, window);
}
Fase::~Fase() {
	deleteFase();
}
void Fase::initFase1(Jogador* play, sf::RenderWindow* _window) {
	player = play;
	player->setwindow(window);
	player->setPosition(0.f, 0.f);


	for (int i = 0; i < 20; i++) {
		plat = new Plataforma(35.f * i, 500.f);
		plat->setwindow(window);
		listEn.push(plat);
	}

	canhao = new Canhao(140.f, 480.f);
	canhao->setPlayer(player);
	canhao->setwindow(window);
	listEn.push(canhao);
	canhao->getProjetil()->setwindow(window);
	listEn.push(canhao->getProjetil());
}
void Fase::run() {
	player->move();
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
	window->clear();

	player->drawWindow();

	for (int i = 0; i <= listEn.getLen(); i++) {
		listEn.getItem(i)->executarOBJ();
		listEn.getItem(i)->drawWindow();
		if (listEn.getItem(i)->isHarmfull() == false) {
			listEn.getItem(i)->getCollider().checkCollision((Entidade&)player->getCollider(), direction, 1.f);
			player->emColisao(direction);
		}
		else {
			if (listEn.getItem(i)->getCollider().checkCollision((Entidade&)player->getCollider(), direction, 1.f) == true) {
				//causar dano & colidir(caso haja mais que 1 hp)
				//metodo dano aqui
				player->emColisao(direction);
			}
		}
	}
	window->display();
}

void Fase::deleteFase() {
	for (int i = 0; i <= listEn.getLen(); i++) {
		listEn.pop(listEn.getItem(i));
	}
}