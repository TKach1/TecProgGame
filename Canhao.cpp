#include "Canhao.hpp"

Canhao::Canhao(float x, float y) {
	id = 2;
	anim = 1;
	px = x, py = y;
	bola = new Projetil(x, y);
	initOBJ();
}

Canhao::~Canhao() {

}

void Canhao::initOBJ() {
	timer = 0;
}

bool Canhao::tomarDano() {
	setEnabled(false);
	return true;
}

void Canhao::atirar() {
	int temp = 0;
	float pPos = getX();
	float pos = player->getX();
	temp = pPos - pos;

	if (temp >= 0) {
		bola->initOBJ(-1);
		anim = 1;
	}
	else {
		//atira direita
		bola->initOBJ(1);
		anim = 2;
	}
}

void Canhao::setPlayer(Jogador* p)
{
	player = p;
}

void Canhao::executarOBJ() {
	if (timer >= 1000) {
		atirar();
		timer = 0;
	}
	else {
		timer++;
	}
}

bool Canhao::isHarmfull() {
	//O canhão não será Danoso, apenas seu projetil
	return false;
}