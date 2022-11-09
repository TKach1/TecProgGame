#include "Canhao.hpp"

Canhao::Canhao(float x, float y) {
	bola = new Projetil(sf::Vector2f(x, y));
	body.setPosition(sf::Vector2f(x, y));
	initOBJ();
}

Canhao::~Canhao() {

}

void Canhao::initOBJ() {
	body.setFillColor(sf::Color::Cyan);
	setBodySize(50.f, 50.f);
	setOrigin();
}

void Canhao::atirar() {
	int temp = 0;
	sf::Vector2f pPos = getPosition();
	sf::Vector2f pos = player->getPosition();
	temp = pPos.x - pos.x;

	if (temp >= 0) {
		bola->initOBJ(-1);
	}
	else {
		//atira direita
		bola->initOBJ(1);
	}
}

void Canhao::setPlayer(Jogador* p)
{
	player = p;
}

void Canhao::executarOBJ() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) { //sera alterado para cada x segundos atirar
		atirar();
	}
}

bool Canhao::isHarmfull() {
	//O canhão não será Danoso, apenas seu projetil
	return false;
}