#include "Jogo.hpp"
#include <iostream>


Jogo::Jogo() {
    player1 = new Jogador;
    //player1->setwindow(&window);
    fase1 = new Fase1(player1);
    fase2 = new Fase2(player1);
    
    executar();
}

Jogo::~Jogo() {
    delete player1;
}

void Jogo::executar() {
    GerenGraf::getWindow()->create(sf::VideoMode(900, 900), "My window");
    while (GerenGraf::getWindow()->isOpen()) {
        GerenGraf::run();
        if (fase1->getComplete() == false)
            fase1->executar();
        else {
            if (fase2->getComplete() == false)
                fase2->executar();
        }
    }
}
