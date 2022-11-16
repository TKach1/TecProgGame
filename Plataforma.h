#pragma once
#include"Objeto.h"
class Plataforma : public Objeto{
private:

public:
	Plataforma(float x, float y) { texture.loadFromFile("./Texturas/bricks.png"); initOBJ(); body.setPosition(sf::Vector2f(x, y));}
	Plataforma() { texture.loadFromFile("./Texturas/bricks.png"); initOBJ(); }
	void initOBJ();
	void executarOBJ();

};