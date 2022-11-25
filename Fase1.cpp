#include "Fase1.h"


Fase1::Fase1(Jogador* play) {
	isComplete = false;
	initFase1(play);
}
Fase1::~Fase1() {
}

void Fase1::initFase1(Jogador* play) {
	/*sf::Texture texture;
	texture.loadFromFile("./Texturas/background.jpg");
	Entidade *bg;
	bg = new Entidade;
	sf::Vector2u size = texture.getSize();
	bg->setTexture(&texture);
	bg->setOrigin();
	bg->setBodySize(size.x, size.y);
	bg->setwindow(window);
	listEn.push(bg);*/

	player = play;
	//player->setwindow(window);
	//player->getEspada()->setwindow(window);
	//player->setPosition(50.f, 50.f);
	listEn.push(player->getEspada());

	for (int i = 0; i < 140; i++) {
		plat = new Plataforma(35.f * i, 500.f);
		//plat->setwindow(window);
		listEn.push(plat);

		if (i % 20 == 0) {
			//cria uma chance de certas plataformas terem canhoes em cima dela
			if (rand() % 4 == 0) {
				canhao = new Canhao((35.f * i) + 35.f, 385.f - 17.5f - 25.f);
				canhao->setPlayer(player);
				//canhao->setwindow(window);
				listEn.push(canhao);
				//canhao->getProjetil()->setwindow(window);
				listEn.push(canhao->getProjetil());
			}
			for (int j = 0; j < 3; j++) {
				plat = new Plataforma(35.f * (i + j), 385.f);
				//plat->setwindow(window);
				listEn.push(plat);
			}
		}
	}


	canhao = new Canhao(140.f, 500.f - 17.5f - 25.f);
	canhao->setPlayer(player);
	morcego = new Morcego(140.f, 500.f - 17.5f - 25.f);
	listEn.push(morcego);
	//canhao->setwindow(window);
	//canhao->setEnabled(false); //para "destruir" os inimigos 
	listEn.push(canhao);
	//canhao->getProjetil()->setwindow(window);
	listEn.push(canhao->getProjetil());
}

void Fase1::executar() {
	if(isComplete == false)
	player->move();
	//sf::Event event;
	/*while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}
	window->clear();*/
	//player->drawWindow();
	listEn.percorrer(player);
	player->print(1);
	if (player->getPositionx() >= 4800) {
		isComplete = true;
		player->reset();
	}
}