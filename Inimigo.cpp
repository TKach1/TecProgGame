#include "Inimigo.h"



Inimigo::Inimigo() {
	initOBJ();
}
Inimigo::~Inimigo() {

}

void Inimigo::initOBJ() {
	body.setFillColor(sf::Color::Cyan);
	setBodySize(35.f, 50.f);
	setOrigin();
}

void Inimigo::executarOBJ() {


}