#include "GerenGraf.h"

//GerenGraf::GerenGraf(sf::RectangleShape& corpo) : window(nullptr), corpo(corpo)
//{
//}
//GerenGraf::GerenGraf() : window(nullptr), corpo(body) {
//
//}

GerenGraf::~GerenGraf()
{
}
void GerenGraf::setPosition(float x, float y) {
	body.setPosition(sf::Vector2f(x, y));
}

//bool GerenGraf::checkCollision(GerenGraf& other, sf::Vector2f& direction, float pushValue)
//{
//	////pega as posicoes dos objetos e a metade do tamanho deles(afinal sao cubos)
//	//sf::Vector2f otherPosition = other.getPosition();
//	//sf::Vector2f otherHalfSize = other.getHalfSize();
//	//sf::Vector2f thisPosition = getPosition();
//	//sf::Vector2f thisHalfSize = getHalfSize();
//	////comecamos a calcular o delta tanto de x quanto de y
//	//float deltaX = otherPosition.x - thisPosition.x;
//	//float deltaY = otherPosition.y - thisPosition.y;
//	////finalmente calculamos a intercessao(e assim que se fala??) dos objetos
//	//float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
//	//float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
//	sf::Vector2f intersect = getIntersect(other);
//	sf::Vector2f delta = getDelta(other);
//	//float intersectX = intersect.x;
//	//float intersectY =  intersect.y;
//	//float deltaX = delta.x;
//	//float deltaY = delta.y;
//
//	//checa se estao colidindo
//	if (intersect.x < 0.f && intersect.y < 0.f) {
//
//		pushValue = std::min(std::max(pushValue, 0.f), 1.f);
//
//		if (intersect.x > intersect.y) {
//			if (delta.x >= 0.f) {
//				mover(intersect.x * (1.f - pushValue), 0.f);
//				other.mover(-intersect.x * pushValue, 0.f);
//
//				direction.x = 1.f;
//				direction.y = 0.f;
//			}
//			else {
//				mover(-intersect.x * (1.f - pushValue), 0.f);
//				other.mover(intersect.x * pushValue, 0.f);
//
//				direction.x = -1.f;
//				direction.y = 0.f;
//			}
//		}
//		else {
//			if (delta.y >= 0.f) {
//				mover(0.f, intersect.y * (1.f - pushValue));
//				other.mover(0.f, -intersect.y * pushValue);
//				direction.x = 0.f;
//				direction.y = 1.f;
//			}
//			else {
//				mover(0.f, -intersect.y * (1.f - pushValue));
//				other.mover(0.f, intersect.y * pushValue);
//				direction.x = 0.f;
//				direction.y = -1.f;
//			}
//		}
//
//		return true;
//	}
//
//	return false;
//}
//
//sf::Vector2f GerenGraf::getIntersect(GerenGraf& other) {
//	//pega as posicoes dos objetos e a metade do tamanho deles(afinal sao cubos)
//	sf::Vector2f otherPosition = other.getPosition();
//	sf::Vector2f otherHalfSize = other.getHalfSize();
//	sf::Vector2f thisPosition = getPosition();
//	sf::Vector2f thisHalfSize = getHalfSize();
//	//comecamos a calcular o delta tanto de x quanto de y
//	float deltaX = otherPosition.x - thisPosition.x;
//	float deltaY = otherPosition.y - thisPosition.y;
//	//finalmente calculamos a intercessao(e assim que se fala??) dos objetos
//	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
//	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);
//	sf::Vector2f intersect(sf::Vector2f(intersectX, intersectY));
//	return intersect;
//}
//
//sf::Vector2f GerenGraf::getDelta(GerenGraf& other) {
//	//pega as posicoes dos objetos e a metade do tamanho deles(afinal sao cubos)
//	sf::Vector2f otherPosition = other.getPosition();
//	sf::Vector2f otherHalfSize = other.getHalfSize();
//	sf::Vector2f thisPosition = getPosition();
//	sf::Vector2f thisHalfSize = getHalfSize();
//	//comecamos a calcular o delta tanto de x quanto de y
//	float deltaX = otherPosition.x - thisPosition.x;
//	float deltaY = otherPosition.y - thisPosition.y;
//	sf::Vector2f delta;
//	delta.x = deltaX;
//	delta.y = deltaY;
//	return delta;
//}

void GerenGraf::imprime(int id, float x, float y, int anim) {
	if (id == 1) { //Jogador
		setBodySize(35.f, 35.f);
		setOrigin();
		setPosition(x, y);
		//printf("%d -=- ", isFaced);
		if (isFaced) {
			setScale(sf::Vector2f(2.f, 2.f));
		}
		else if(!isFaced) {
			setScale(sf::Vector2f(-2.f, 2.f));
		}
		sf::Vector2f cameraPos;
		if (x < 450.0f) {
			cameraPos = sf::Vector2f(450.0f, 450.0f);
		}
		else {
			cameraPos = sf::Vector2f(x, 450.0f);
		}
		view->setCenter(cameraPos);
		if (dano) {
			body.setFillColor(sf::Color::Red);
			pTime++;
			if (pTime >= 500) {
				pTime = 0;
				dano = false;
			}
		}
		else {
			body.setFillColor(sf::Color::White);
		}
		sf::Vector2u TextureSize = texturaPlayer.getSize();
		TextureSize.x /= 3;
		TextureSize.y /= 11;
		if (anim == 0) {
			setTextureRect(sf::IntRect(TextureSize.x * 1, (TextureSize.y * 6) + 15, TextureSize.x, TextureSize.y));
		}else if (anim == 1) {
			setTextureRect(sf::IntRect(TextureSize.x * 2, (TextureSize.y * 6) + 15, TextureSize.x, TextureSize.y));
		}else if (anim == 2) {
			setTextureRect(sf::IntRect(TextureSize.x * 0, (TextureSize.y * 7) + 15, TextureSize.x, TextureSize.y));
		}
		setTexture(&texturaPlayer);
	}
	else if (id == 2) { // Canhao
		setBodySize(50.f, 50.f);
		setOrigin();
		setPosition(x, y);
		setScale(sf::Vector2f(1.f, 1.f));
		body.setFillColor(sf::Color::Blue);
		setTexture(NULL);
	}
	else if (id == 3) { // Plataforma
		setBodySize(35.f, 35.f);
		setOrigin();
		setPosition(x, y);
		setScale(sf::Vector2f(1.f, 1.f));
		body.setFillColor(sf::Color::Red);
		sf::Vector2u TextureSize = texturaPlat.getSize();
		setTextureRect(sf::IntRect(0, 0, TextureSize.x, TextureSize.y));
		setTexture(&texturaPlat);
	}
	else if (id == 4) { // Projetil
		setBodySize(10.f, 10.f);
		setOrigin();
		setPosition(x, y);
		setScale(sf::Vector2f(1.f, 1.f));
		body.setFillColor(sf::Color::Magenta);
		setTexture(NULL);
	}
	else if (id == 5) { // Plataforma
		setBodySize(35.f, 35.f);
		setOrigin();
		setPosition(x, y);
		setScale(sf::Vector2f(1.f, 1.f));
		body.setFillColor(sf::Color::Green);
		/*sf::Vector2u TextureSize = texturaPlat.getSize();
		setTextureRect(sf::IntRect(0, 0, TextureSize.x, TextureSize.y));*/
		setTexture(NULL);
	}
	drawWindow();
	setScale(sf::Vector2f(1.f, 1.f));
}


GerenGraf* GerenGraf::instance = NULL;
sf::RenderWindow* GerenGraf::window = new sf::RenderWindow;
sf::View* GerenGraf::view = new sf::View;
sf::Event GerenGraf::event;
bool GerenGraf::isFaced = true;
bool GerenGraf::dano = false;