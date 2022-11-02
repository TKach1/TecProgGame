#include "Jogo.hpp"
#include <iostream>


Jogo::Jogo() : window(sf::VideoMode(900, 900), "high levels of Tomfoolery") {
    player1 = new Jogador;
    player1->setwindow(&window);
    executar();
}

Jogo::~Jogo() {
    delete player1;
}

void Jogo::executar() {
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen()) {
        player1->move();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            player1->drawWindow();
            window.display();
    }
}