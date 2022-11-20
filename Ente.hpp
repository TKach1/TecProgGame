#pragma once
#include "GerenGraf.h"

class Ente {
private:
	GerenGraf* g;
protected:
	int id;
	float px, py;
public:
	Ente(int _id);
	~Ente();
	
	virtual void executarOBJ();
	void print();
};