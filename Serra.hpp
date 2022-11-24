#pragma once
#include "Objeto.h"

class Serra : public Objeto {
private: 
	int dano;
	float inix, iniy;
	bool dir;
public: 
	Serra(float x, float y);
	~Serra();

	void initOBJ();
	bool isHarmfull();
	void executarOBJ();
};