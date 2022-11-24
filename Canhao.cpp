#include "Canhao.hpp"

Canhao::Canhao(float x, float y) {
	id = 2;
	px = x, py = y;
	bola = new Projetil(x, y);
	initOBJ();
}

Canhao::~Canhao() {

}

void Canhao::initOBJ() {

}

void Canhao::atirar() {
	int temp = 0;
	float pPos = getX();
	float pos = player->getX();
	temp = pPos - pos;

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