#pragma once
#include"Objeto.h"
class Plataforma : public Objeto{
private:

public:
	Plataforma(float x, float y) { initOBJ(); px = x; py = y; } // px py
	Plataforma() { initOBJ(); }
	void initOBJ();
	void executarOBJ();

};