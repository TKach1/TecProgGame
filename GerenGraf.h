#pragma once
#include <SFML/Graphics.hpp>
class GerenGraf
{
private:
	static sf::Event event;
	static GerenGraf* instance;
	GerenGraf() : corpo(body) {
		texturaPlayer.loadFromFile("./Texturas/samubit.png");
		printf("texturas loaded...");

		texturaPlat.loadFromFile("./Texturas/bricks.png");
		pTime = 0;
	}
	static bool isFaced;
	static bool dano;
	int pTime;
protected:
	sf::RectangleShape body;
	sf::RectangleShape& corpo;
	static sf::RenderWindow* window;
	static sf::View* view;

	sf::Texture texturaPlayer;
	sf::Texture texturaPlat;
	sf::Texture texturaCanhao;
	sf::Texture texturaMorc;
public:
	static GerenGraf* GetInstance() {
		if (instance == NULL) {
			instance = new GerenGraf();
		}
		return instance;
	}

	~GerenGraf();
	static void setFaced(bool b) { isFaced = b; }
	static void setDano(bool b) { dano = b; }
	sf::RectangleShape getCollider() { return corpo; }
	//void setwindow(sf::RenderWindow* w) { window = &w; };
	void drawWindow() { window->draw(body); }
	void setBodySize(float x, float y) { body.setSize(sf::Vector2f(x, y)); }
	void setOrigin() { body.setOrigin(body.getSize() / 2.f); }
	void applyGravity() { body.move(sf::Vector2f(0.f, 0.5f)); }
	void setTexture(sf::Texture *t) { body.setTexture(t); }
	void setTextureRect(sf::IntRect r) { body.setTextureRect(r);}
	void setScale(sf::Vector2f s) { body.setScale(s); }
	void scale(sf::Vector2f s) { body.scale(s); }
	sf::Vector2f getPosition() { return corpo.getPosition(); }
	void setPosition(float x, float y);

	static sf::RenderWindow* getWindow() { return window; }

	void imprime(int id, float x, float y, int anim);
	static void run() {
		view->setSize((sf::Vector2f(0.0f, 0.0f), sf::Vector2f(900.0f, 900.0f)));
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window->close();
			}
		}
		window->setView(*view);
		window->display();
		window->clear();
	}
};

