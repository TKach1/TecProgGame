#include "Espinho.hpp"

Espinho::Espinho(float x, float y) {
	px = x, py = y;
	initOBJ();
}
Espinho::~Espinho() {

}

void Espinho::initOBJ() {
	id = 6;
}
bool Espinho::isHarmfull() {
	return true;
}
void Espinho::executarOBJ() {
	
}