#pragma once
#include "Entidade.hpp"
class Objeto : public Entidade {
protected:
	float defaultX, defaultY;
	bool isHarmful
public:
	Objeto() { defaultX = 35.f; defaultY = 35.f; isHarmful = false; initOBJ(); }
	~Objeto(){}

	virtual void initOBJ() {
		body.setFillColor(sf::Color::Red);
		setBodySize(defaultX, defaultY);
	}
	virtual void executarOBJ() {}

};