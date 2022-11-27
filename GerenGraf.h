#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>
class GerenGraf
{
private:
	static sf::Event event;
	static GerenGraf* instance;
	GerenGraf() : corpo(body) {
		texturaPlayer.loadFromFile("./Texturas/samubit.png");
		printf("texturas loaded...");

		texturaPlat.loadFromFile("./Texturas/bricks.png");

		texturaMorc.loadFromFile("./Texturas/Morceguinho.png");

		texturaCanhao.loadFromFile("./Texturas/Canhao.png");
		
		texturaVamp.loadFromFile("./Texturas/vamp.png");

		texturaBola.loadFromFile("./Texturas/bola.png");

		texturaSpike.loadFromFile("./Texturas/Spike.png");

		texturaSerra.loadFromFile("./Texturas/Serra.png");

		texturaCoracao.loadFromFile("./Texturas/coracao.png");

		font.loadFromFile("./MenuRelated/ethn.otf");
		pTime = 0;
	}
	static bool isFaced;
	static bool dano;
	int pTime;
	static int points;
	static sf::Text texto;

protected:
	sf::RectangleShape body;
	sf::RectangleShape& corpo;
	static sf::RenderWindow* window;
	static sf::View* view;

	static sf::Font font;
	sf::Texture texturaPlayer;
	sf::Texture texturaBola;
	sf::Texture texturaPlat;
	sf::Texture texturaCanhao;
	sf::Texture texturaMorc;
	sf::Texture texturaVamp;
	sf::Texture texturaSpike;
	sf::Texture texturaSerra;
	sf::Texture texturaCoracao;
public:
	static GerenGraf* GetInstance() {
		if (instance == NULL) {
			instance = new GerenGraf();
		}
		return instance;
	}

	~GerenGraf();
	static void setPoints(int p) { points = p; }
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

		texto.setFillColor(sf::Color::White);
		texto.setCharacterSize(24);
		texto.setFont(font);
		std::stringstream ss;
		ss << "Pontos: " << points;
		texto.setString(ss.str().c_str());
		texto.setPosition(view->getCenter().x - 300.f, window->getSize().y - 30.f);

		window->draw(texto);
		window->setView(*view);
		window->display();
		window->clear();
	}

	static std::string getNome() {
		sf::String playerInput;
		sf::Text playerText;

		playerText.setFillColor(sf::Color::White);
		playerText.setCharacterSize(24);
		playerText.setFont(font);
		playerText.setPosition(view->getCenter().x - 300.f, window->getSize().y - 30.f);
			while (window->pollEvent(event))
			{
				if (event.type == sf::Event::Closed) {
					window->close();
				}

				if (event.type == sf::Event::TextEntered)
				{
					playerInput += event.text.unicode;
					playerText.setString(playerInput);
				}

				window->draw(playerText);
			}
		return playerInput;
	}
};

