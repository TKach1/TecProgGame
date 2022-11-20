#include "Projetil.hpp"



Projetil::Projetil(sf::Vector2f pos) {
	initialPos = pos;
	//body.setPosition(pos);
	initOBJ(-1);
}
Projetil::~Projetil() {
	
}

void Projetil::projetar() {
	//body.move(sf::Vector2f(velocidade.x*multi, velocidade.y));
	velocidade.y += 0.00981f;
}

void Projetil::initOBJ(int m) {
	//body.setPosition(initialPos);
	velocidade.x = 0.7f;
	velocidade.y = -2.0f;
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