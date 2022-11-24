#include "Projetil.hpp"



Projetil::Projetil(float x, float y) {
	id = 4;
	setSolid(false);
	px = x, py = y;
	inix = x, iniy = y;
	//body.setPosition(pos);
	initOBJ(-1);
}
Projetil::~Projetil() {
	
}

void Projetil::projetar() {
	//body.move(sf::Vector2f(velocidade.x*multi, velocidade.y));
	mover(vx * multi, vy);
	vy += 0.00981f;
}

void Projetil::initOBJ(int m) {
	//body.setPosition(initialPos);
	px = inix, py = iniy;
	vx = 0.7f;
	vy = -2.0f;
	multi = m;
	//body.setFillColor(sf::Color::Magenta);
	//setBodySize(10.f, 10.f);
	//setOrigin();
}


void Projetil::executarOBJ() {
	projetar();
}

bool Projetil::isHarmfull() {
	//Projeteis sempre serao danosos
	return true;
}