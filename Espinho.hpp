#pragma once
#include "Objeto.h"

class Espinho : public Objeto {
private:
	int dano;
public:
	Espinho(float x, float y);
	~Espinho();

	void initOBJ();
	bool isHarmfull();
	void executarOBJ();
};