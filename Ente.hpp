#pragma once
#include "GerenGraf.h"

class Ente {
private:
	GerenGraf* g;
protected:
	int id;
	float px, py;
	//float sx, sy;
public:
	Ente(int _id);
	~Ente();

	float getX() { return px; }
	float getY() { return py; }
	void mover(float dx, float dy) { px += dx; py += dy; }
	virtual void executarOBJ();
	void print();
};