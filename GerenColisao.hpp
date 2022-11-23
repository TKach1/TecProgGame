#pragma once
#include "Fase.h"

class GerenColisao {
private:

public:
	static bool checkCollision(Ente& from, Ente& other, float& dx, float& dy, float pushValue);
	static sf::Vector2f getIntersect(Ente& from, Ente& other);
	static sf::Vector2f getDelta(Ente& from, Ente& other);
};