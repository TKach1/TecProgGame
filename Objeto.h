#pragma once
#include "Entidade.hpp"
class Objeto : public Entidade {
protected:
	float defaultX, defaultY;
	bool _isHarmfull;
public:
	Objeto() { initOBJ(); }
	~Objeto(){}

	virtual void initOBJ() {
		defaultX = 35.f;
		defaultY = 35.f;
		_isHarmfull = false;
		body.setFillColor(sf::Color::Red);
		setBodySize(defaultX, defaultY);
	}

	void setColor(sf::Color c){ body.setFillColor(c); }

	virtual void executarOBJ() {}

	virtual bool isHarmfull() { return _isHarmfull; }

};