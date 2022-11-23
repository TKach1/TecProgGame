#pragma once
#include "Entidade.hpp"
class Objeto : public Entidade {
protected:
	float defaultX, defaultY;
	bool _isHarmfull;
public:
	Objeto() { initOBJ(); }
	~Objeto(){}

	void setPos(float x, float y) {
		px = x;
		py = y;
	}

	virtual void initOBJ() {
		defaultX = 35.f;
		defaultY = 35.f;
		_isHarmfull = false;
	}

	void setColor(sf::Color c){  }

	virtual void executarOBJ() {}

	virtual bool isHarmfull() { return _isHarmfull; }

};