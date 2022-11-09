#pragma once
#include <SFML/Graphics.hpp>
class Entidade
{
protected:
	sf::RectangleShape body;
	sf::RectangleShape& corpo;
	sf::RenderWindow* window;
public:
	Entidade(sf::RectangleShape& corpo);
	Entidade();
	~Entidade();
	Entidade getCollider() { return Entidade(corpo); }
	void setwindow(sf::RenderWindow* w) { this->window = w; };
	void drawWindow() { window->draw(body); }
	void setBodySize(float x, float y) { body.setSize(sf::Vector2f(x, y)); }
	void setOrigin() { body.setOrigin(body.getSize() / 2.f); }
	void applyGravity() { body.move(sf::Vector2f(0.f, 0.5f)); }
	void setPosition(float x, float y);

	virtual void initOBJ();
	virtual void executarOBJ();
	virtual bool isHarmfull() { return false; }
	//toda a parte de colisao foi retirada e adaptada deste video: https://www.youtube.com/watch?v=l2iCYCLi6MU&t=942s
	bool checkCollision(Entidade& other, sf::Vector2f& direction, float pushValue);
	sf::Vector2f getPosition() { return corpo.getPosition(); }
	sf::Vector2f getHalfSize() { return corpo.getSize() / 2.f; }
	void mover(float dx, float dy) { corpo.move(dx, dy); }
	sf::Vector2f getIntersect(Entidade& other);
	sf::Vector2f getDelta(Entidade& other);
};

