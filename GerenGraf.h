#pragma once
#include <SFML/Graphics.hpp>
class GerenGraf
{
protected:
	sf::RectangleShape body;
	sf::RectangleShape& corpo;
	sf::RenderWindow* window;
public:
	GerenGraf(sf::RectangleShape& corpo);
	GerenGraf();
	~GerenGraf();
	GerenGraf getCollider() { return GerenGraf(corpo); }
	void setwindow(sf::RenderWindow* w) { this->window = w; };
	void drawWindow() { window->draw(body); }
	void setBodySize(float x, float y) { body.setSize(sf::Vector2f(x, y)); }
	void setOrigin() { body.setOrigin(body.getSize() / 2.f); }
	void applyGravity() { body.move(sf::Vector2f(0.f, 0.5f)); }
	bool checkCollision(GerenGraf& other, sf::Vector2f& direction, float pushValue);
	sf::Vector2f getPosition() { return corpo.getPosition(); }
	sf::Vector2f getHalfSize() { return corpo.getSize() / 2.f; }
	void mover(float dx, float dy) { corpo.move(dx, dy); }
	sf::Vector2f getIntersect(GerenGraf& other);
	sf::Vector2f getDelta(GerenGraf& other);
	void setPosition(float x, float y);
};

