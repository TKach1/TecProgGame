#pragma once
#include"Objeto.h"
class Plataforma : public Objeto{
private:

public:
	Plataforma(float x, float y) { initOBJ(); body.setPosition(sf::Vector2f(x, y));}
	Plataforma() { initOBJ(); }
	void initOBJ();
	void executarOBJ();

};