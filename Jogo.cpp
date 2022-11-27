#include "Jogo.hpp"
#include <fstream>
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

void Jogo::salvarRanking() {
    std::string nome[6];
    std::string pontos[6];
    std::string line;
    std::string nick = "ROGER";
    std::fstream myfile;
    int ponto[6];
    int j = 0;
    int temp = 0;
    myfile.open("ranking.txt", std::fstream::in);
    if (myfile.is_open())
    {
        for (int i = 0; i < 5; i++) {
            getline(myfile, line);
            //for (int j = 0; j <= line.length(); j++){
            j = 0;
            while (line[j] != ',') {
                j++;
            }
            nome[i] = line.substr(0, j);
            j++;
            temp = j;
            while (j != line.length()) {
                j++;
            }
            pontos[i] = line.substr(temp, j);
            //}
        }
        myfile.close();
    }

    for (int i = 0; i < 5; i++) {
        ponto[i] = atoi(pontos[i].c_str());
    }

    sf::String playerInput;
    sf::Text playerText;
    sf::Event event;
    sf::RenderWindow window;


    std::cout << "DIGITE SEU NOME:";
    std::cin >> nome[5];
    ponto[5] = player1->getPoints();

    for (int step = 1; step < 6; step++) {
        int key = ponto[step];
        std::string nkey = nome[step];
        int j = step - 1;

        while (key > ponto[j] && j >= 0) {
            ponto[j + 1] = ponto[j];
            nome[j + 1] = nome[j];
            --j;
        }
        ponto[j + 1] = key;
        nome[j + 1] = nkey;
    }

    std::cout << std::endl << "\tRANKING" << std::endl << std::endl;

    for (int i = 0; i < 5; i++) {
        std::cout << nome[i] << "\t - " << ponto[i] << std::endl;;
    }

    myfile.open("ranking.txt", std::fstream::out);
    if (myfile.is_open()) {
        for (int i = 0; i < 5; i++) {
            myfile << nome[i] << "," << ponto[i] << std::endl;
        }
        myfile.close();
    }


    system("pause");
    /*myfile.open("ranking.txt", std::fstream::out);
    std::cout << nick;
    myfile << nick << "," << player1->getPoints();
    myfile.close();*/
}

void Jogo::executar() {
    GerenGraf::getWindow()->create(sf::VideoMode(900, 900), "Game2D");
    while (GerenGraf::getWindow()->isOpen()) {
        GerenGraf::run();
        if (fase1->getComplete() == true)
            fase1->executar();
        else if (fase2->getComplete() == false) { //false
            fase2->executar();
        }
        if (fase2->getComplete() == true) { //true
            GerenGraf::getWindow()->close();
            salvarRanking();
        }
    }
}
