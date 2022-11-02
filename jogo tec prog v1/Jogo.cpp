#include "Jogo.hpp"
#include <iostream>


Jogo::Jogo() : window(sf::VideoMode(900, 900), "high levels of Tomfoolery") {

    executar();
}
Jogo::~Jogo() {

}

void Jogo::executar() {
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    while (window.isOpen()) {
        
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            window.draw(shape);
            window.display();
    }
}