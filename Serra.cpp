#include "Serra.hpp"

Serra::Serra(float x, float y) {
	px = x, py = y;
	initOBJ();
}
Serra::~Serra() {

}

void Serra::initOBJ() {
	id = 5;
	inix = px, iniy = py;
}
bool Serra::isHarmfull() {
	return true;
}
void Serra::executarOBJ() {
	if (px - inix >= 100.f)
		dir = false;
	if (px - inix <= 0.f)
		dir = true;

	if (dir) {
		px += 0.1f;
	}
	else {
		px -= 0.1f;
	}
}