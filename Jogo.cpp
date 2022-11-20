#include "Jogo.hpp"
#include <iostream>


Jogo::Jogo() {
    player1 = new Jogador;
    //player1->setwindow(&window);
    fase = new Fase(player1);
    
    executar();
}

Jogo::~Jogo() {
    delete player1;
}

void Jogo::executar() {
    GerenGraf::getWindow()->create(sf::VideoMode(900, 900), "My window");
    while (GerenGraf::getWindow()->isOpen()) {
        GerenGraf::run();
        fase->run();
    }
}