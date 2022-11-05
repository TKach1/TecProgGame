#pragma once
#include "Entidade.hpp"
class Objeto : public Entidade {
protected:
	float defaultX, defaultY;
	bool isHarmful;
public:
	Objeto() { initOBJ(); }
	~Objeto(){}

	virtual void initOBJ() {
		defaultX = 35.f;
		defaultY = 35.f;
		isHarmful = false;
		body.setFillColor(sf::Color::Red);
		setBodySize(defaultX, defaultY);
	}
	virtual void executarOBJ() {}

	virtual bool isHarmfull() { return isHarmfull; }

};