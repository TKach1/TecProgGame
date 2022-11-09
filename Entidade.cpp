#include "Entidade.hpp"

Entidade::~Entidade() {

}

void Entidade::initOBJ() {
    //por padrao nao havera nada aqui
    
}

void Entidade::executarOBJ() {
	//por padrao nao havera nada aqui
}

Entidade::Entidade(sf::RectangleShape& corpo) :window(nullptr), corpo(corpo) {

}

Entidade::Entidade() : window(nullptr), corpo(body)
{

}

void Entidade::setPosition(float x, float y) {
	body.setPosition(sf::Vector2f(x, y));
}

bool Entidade::checkCollision(Entidade& other, sf::Vector2f& direction, float pushValue)
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
	sf::Vector2f intersect = getIntersect(other);
	sf::Vector2f delta = getDelta(other);
	//float intersectX = intersect.x;
	//float intersectY =  intersect.y;
	//float deltaX = delta.x;
	//float deltaY = delta.y;

	//checa se estao colidindo
	if (intersect.x < 0.f && intersect.y < 0.f) {

		pushValue = std::min(std::max(pushValue, 0.f), 1.f);

		if (intersect.x > intersect.y) {
			if (delta.x >= 0.f) {
				mover(intersect.x * (1.f - pushValue), 0.f);
				other.mover(-intersect.x * pushValue, 0.f);
				printf("sada ");

				direction.x = 1.f;
				direction.y = 0.f;
			}
			else {
				mover(-intersect.x * (1.f - pushValue), 0.f);
				other.mover(intersect.x * pushValue, 0.f);

				direction.x = -1.f;
				direction.y = 0.f;
			}
		}
		else {
			if (delta.y >= 0.f) {
				mover(0.f, intersect.y * (1.f - pushValue));
				other.mover(0.f, -intersect.y * pushValue);
				direction.x = 0.f;
				direction.y = 1.f;
			}
			else {
				mover(0.f, -intersect.y * (1.f - pushValue));
				other.mover(0.f, intersect.y * pushValue);
				direction.x = 0.f;
				direction.y = -1.f;
			}
		}

		return true;
	}

	return false;
}

sf::Vector2f Entidade::getIntersect(Entidade& other) {
	//pega as posicoes dos objetos e a metade do tamanho deles(afinal sao cubos)
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();
	sf::Vector2f thisPosition = getPosition();
	sf::Vector2f thisHalfSize = getHalfSize();
	//comecamos a calcular o delta tanto de x quanto de y
	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	//finalmente calculamos a intercessao(e assim que se fala??) dos objetos
	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
	sf::Vector2f intersect(sf::Vector2f(intersectX, intersectY));
	return intersect;
}

sf::Vector2f Entidade::getDelta(Entidade& other) {
	//pega as posicoes dos objetos e a metade do tamanho deles(afinal sao cubos)
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = other.getHalfSize();
	sf::Vector2f thisPosition = getPosition();
	sf::Vector2f thisHalfSize = getHalfSize();
	//comecamos a calcular o delta tanto de x quanto de y
	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;
	sf::Vector2f delta;
	delta.x = deltaX;
	delta.y = deltaY;
	return delta;
}

