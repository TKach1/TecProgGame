#include "Vampiro.h"
#define TIMER 800
Vampiro::Vampiro(float x, float y)
{
	id = 7;
	px = x, py = y;
	initOBJ();
}

Vampiro::~Vampiro()
{
}

void Vampiro::initOBJ()
{
	timer = 0;
	life = 3;
	isImmune = true;
	cooldown = 0;
	invert = 1;
}

void Vampiro::executarOBJ()
{
	//temporario? permanente talvez?
	if (timer < TIMER && cooldown == 0) {
		mover(2.5f * invert, 0.f);
		timer++;
		isImmune = true;
	}
	else if (timer == TIMER) {
		cooldown = 1000;
		timer = 0;
		invert = -invert;
		isImmune = false;
	}
	else {
		cooldown--;
	}

}
