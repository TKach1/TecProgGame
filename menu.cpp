#include "menu.hpp"
#include "Jogo.hpp"
#include <fstream>
//Menu com base no vídeo: https://www.youtube.com/watch?v=h8-Q4eu3Qt4
Menu::Menu(){
  window = new sf::RenderWindow();
  winclose = new sf::RectangleShape();
  font = new sf::Font();
  image = new sf::Texture();
  bg = new sf::Sprite();

  set_values();
}

Menu::~Menu(){
  delete window;
  delete winclose;
  delete font;
  delete image;
  delete bg;
}

void Menu::set_values(){
  window->create(sf::VideoMode(1280,720), "Menu SFML", sf::Style::Titlebar | sf::Style::Close);
  window->setPosition(sf::Vector2i(0,0));

  pos = 0;
  pressed = theselect = false;
  font->loadFromFile("./MenuRelated/ethn.otf");
  image->loadFromFile("./MenuRelated/menu-sci-fi-game.png");

  bg->setTexture(*image);

  pos_mouse = {0,0};
  mouse_coord = {0, 0};

  options = {"Vampire's Tale", "Fase 1", "Fase 2", "Sobre", "Sair"};
  texts.resize(5);
  coords = {{558,40},{610,195},{610,282},{605,370},{623,457}};
  sizes = {18,20,18,24,24};

  for (std::size_t i{}; i < texts.size(); ++i){
   texts[i].setFont(*font); 
   texts[i].setString(options[i]); 
   texts[i].setCharacterSize(sizes[i]);
   texts[i].setOutlineColor(sf::Color::Red);
   texts[i].setPosition(coords[i]);
  }
  texts[1].setOutlineThickness(4);
  pos = 1;

  winclose->setSize(sf::Vector2f(23,26));
  winclose->setPosition(1178,39);
  winclose->setFillColor(sf::Color::Transparent);

}

void Menu::loop_events(){
  sf::Event event;
  while(window->pollEvent(event)){
    if( event.type == sf::Event::Closed){
      window->close();
    }

    pos_mouse = sf::Mouse::getPosition(*window);
    mouse_coord = window->mapPixelToCoords(pos_mouse);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
      if( pos < 4){
        ++pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos - 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
      if( pos > 1){
        --pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos + 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
      theselect = true;
      if( pos == 4){
        window->close();
      }
      if (pos == 1) {
          window->close();
          Jogo jogo;
      }
      if (pos == 2) {
          window->close();
          Jogo jogo;
      }
      if (pos == 3) {

          std::string line;
          std::fstream myfile;

          std::cout << std::endl << "\tRANKING" << std::endl << std::endl;

          myfile.open("ranking.txt", std::fstream::in);
          if (myfile.is_open()) {
              for (int i = 0; i < 5; i++) {
                  getline(myfile, line);
                  std::cout << line << std::endl;
              }
              myfile.close();
          }

          std::cout << '\n' << "Sobre: Trabalho realizado pelos Alunos: Wesley Brandao e Gustavo Tomazzoni" << '\n' << "Juntamente com o professor Jean M. Simao como orientador";
      }
      //std::cout << options[pos] << '\n';
    }

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
      if(winclose->getGlobalBounds().contains(mouse_coord)){
        window->close();
      }
    }
  }
}

void Menu::draw_all(){
  window->clear();
  window->draw(*bg);
  for(auto t : texts){
   window->draw(t); 
  }
  window->display();
}

void Menu::run_menu(){
  while(window->isOpen()){
    loop_events();
    draw_all();
  }
}
