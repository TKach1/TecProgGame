#include "Vampiro.h"
#define TIMER 800
Vampiro::Vampiro(float x, float y)
{
	id = 20;
	px = x, py = y;
	initOBJ();
}

Vampiro::~Vampiro()
{
}

void Vampiro::initOBJ()
{
	timer = 0;
	timerD = 0;
	life = 3;
	isImmune = true;
	cooldown = 0;
	invert = 1;
	isDead = false;
}

bool Vampiro::tomarDano() {
	if (timerD <= 0) {
		life--;
		timerD = 500;
		return false;
	}
	if (life <= 0) {
		setEnabled(false);
		isDead = true;
		return true;
		//morreu vamp
	}
}

void Vampiro::executarOBJ()
{
	if (timerD > 0) {
		timerD--;
	}
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
