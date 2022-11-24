#include "Morcego.h"

Morcego::Morcego(float x, float y)
{
	id = 4;
	px = x, py = y;
	initOBJ();
}

Morcego::~Morcego()
{
}

void Morcego::initOBJ()
{
	flyrange = 600;
	fly = 0;
}

void Morcego::executarOBJ()
{
	if (fly < flyrange && fly >= 0) {
		mover(0.3f, 0.f);
		fly++;
		if (fly == flyrange - 1.f)
			fly = -flyrange;
	}
	else if (fly < 0) {
		mover(-0.3f, 0.f);
		fly++;
		if (fly == -1.f)
			fly = 0;
	}
}
