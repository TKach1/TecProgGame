#include "GerenColisao.hpp"

bool GerenColisao::checkCollision(Ente& from, Ente& other, float& dx, float& dy, float pushValue)
{
	////pega as posicoes dos objetos e a metade do tamanho deles(afinal sao cubos)
	//sf::Vector2f otherPosition = other.getPosition();
	//sf::Vector2f otherHalfSize = other.getHalfSize();
	//sf::Vector2f thisPosition = getPosition();
	//sf::Vector2f thisHalfSize = getHalfSize();
	////comecamos a calcular o delta tanto de x quanto de y
	//float deltaX = otherPosition.x - thisPosition.x;
	//float deltaY = otherPosition.y - thisPosition.y;
	////finalmente calculamos a intercessao(e assim que se fala??) dos objetos
	//float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	//float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	//printf("colisao: %f, %f -=- ", from.getX(), from.getY());
	//printf("colisao: %f, %f -=- ", other.getX(), other.getY());
	sf::Vector2f intersect = getIntersect(from, other);
	sf::Vector2f delta = getDelta(from, other);
	//float intersectX = intersect.x;
	//float intersectY =  intersect.y;
	//float deltaX = delta.x;
	//float deltaY = delta.y;

	//checa se estao colidindo
	if (intersect.x < 0.f && intersect.y < 0.f) {

		pushValue = std::min(std::max(pushValue, 0.f), 1.f);

		if (intersect.x > intersect.y) {
			if (delta.x >= 0.f) {
				from.mover(intersect.x * (1.f - pushValue), 0.f);
				//other.mover(-intersect.x * pushValue, 0.f);

				dx = 1.f;
				dy = 0.f;
			}
			else {
				from.mover(-intersect.x * (1.f - pushValue), 0.f);
				//other.mover(intersect.x * pushValue, 0.f);

				dx = -1.f;
				dy = 0.f;
			}
		}
		else {
			if (delta.y >= 0.f) {
				from.mover(0.f, intersect.y * (1.f - pushValue));
				//other.mover(0.f, -intersect.y * pushValue);
				dx = 0.f;
				dy = 1.f;
			}
			else {
				from.mover(0.f, -intersect.y * (1.f - pushValue));
				//other.mover(0.f, intersect.y * pushValue);
				dx = 0.f;
				dy = -1.f;
			}
		}
		return true;
	}

	return false;
}

sf::Vector2f GerenColisao::getIntersect(Ente& from, Ente& other) {
	//pega as posicoes dos objetos e a metade do tamanho deles(afinal sao cubos)
	sf::Vector2f otherPosition = sf::Vector2f(other.getX(), other.getY());
	//sf::Vector2f otherHalfSize = (sf::Vector2f(other.getX(), other.getY()) / 2.0f);
	sf::Vector2f otherHalfSize = (sf::Vector2f(35.0f, 35.0f) / 2.0f);
	sf::Vector2f thisPosition = sf::Vector2f(from.getX(), from.getY());;
	//sf::Vector2f thisHalfSize = (sf::Vector2f(from.getX(), from.getY()) / 2.0f);
	sf::Vector2f thisHalfSize = (sf::Vector2f(35.0f, 35.0f) / 2.0f);


	//comecamos a calcular o delta tanto de x quanto de y
	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	//finalmente calculamos a intercessao(e assim que se fala??) dos objetos
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	sf::Vector2f intersect(sf::Vector2f(intersectX, intersectY));
	return intersect;
}

sf::Vector2f GerenColisao::getDelta(Ente& from, Ente& other) {
	//pega as posicoes dos objetos e a metade do tamanho deles(afinal sao cubos)
	sf::Vector2f otherPosition = sf::Vector2f(other.getX(), other.getY());
	//sf::Vector2f otherHalfSize = (sf::Vector2f(other.getX(), other.getY()) / 2.0f);
	sf::Vector2f otherHalfSize = (sf::Vector2f(35.0f, 35.0f) / 2.0f);
	sf::Vector2f thisPosition = sf::Vector2f(from.getX(), from.getY());;
	//sf::Vector2f thisHalfSize = (sf::Vector2f(from.getX(), from.getY()) / 2.0f);
	sf::Vector2f thisHalfSize = (sf::Vector2f(35.0f, 35.0f) / 2.0f);


	//comecamos a calcular o delta tanto de x quanto de y
	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	sf::Vector2f delta;
	delta.x = deltaX;
	delta.y = deltaY;
	return delta;
}