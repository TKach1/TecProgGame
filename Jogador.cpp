#include "Jogador.hpp"


//TODO(opcional): adicionar deltaTime, um valor responsavel por manter o movimento constante independentemente da taxa de fps
      //resultando em uma experiencia mais suave e que pode rodar em diferentes computadores com o mesmo resultado(a (quase) qualquer fps o jogo roda igual)

Jogador::Jogador() {
	initOBJ();
}

Jogador::~Jogador() {

}
void Jogador::move() {
    //"atrito" do personagem
    velocidade.x *= 0.85f;


    //movimentos
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velocidade.x = 0.7f;
        espadaX = abs(espadaX);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velocidade.x = -0.7f;
        espadaX = abs(espadaX) * -1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && podePular == true && jumpTimer > 200) {
        podePular = false;
        //reseta o timer de pulo
        jumpTimer = 0;
        //aplica-se uma equacao
        //sfml trabalha com coordenadas y invertidas, negativo eh cima e positivo eh baixo
        velocidade.y = -sqrtf(2.f * 0.981f * jumpHeight);
    }
    //velocidade.y += 0.0981f;
    velocidade.y += 0.5f;
    //cooldown pulo
    if (podePular == true && jumpTimer <= 200) {
        jumpTimer++;
    }
    body.move(sf::Vector2f(velocidade.x, velocidade.y));
    espada.setPosition(getPosition().x + espadaX - 2, getPosition().y+(body.getSize().y/3));
}

void Jogador::emColisao(sf::Vector2f direction)
{
    podePular = false;
    if (direction.y < 0.f) {
        //Colisao em baixo
        velocidade.y = 0.f;
        podePular = true;

    }
    else if (direction.y > 0.f) {
        //Colisao em cima
        velocidade.y = 0.f;
    }
    if (direction.x < 0.f) {
        //Colisao na esquerda
        velocidade.x = 0.f;
    }
    else if (direction.x < 0.f) {
        //Colisao na direita
        velocidade.x = 0.f;
    }

}

sf::Vector2f Jogador::getInicio()
{
    return inicio;
}

void Jogador::Dano() {
    body.setPosition(getInicio());
    vidas--;
    if (vidas == 0) {
        //temporario
        window->close();
    }
}



void Jogador::initOBJ() {
    body.setFillColor(sf::Color::Green);
    setBodySize(25.f, 50.f);
    setOrigin();
    inicio = body.getPosition();
    jumpHeight = 500.f;
    podePular = false;
    vidas = 3;
    jumpTimer = 0;
    velocidade.x = 0; 
    velocidade.y = 0;

    espadaX = 35.0f;
    espada.setOrigin();
    espada.setBodySize(40.0f, 5.0f);
    espada.setPosition(inicio.x+espadaX + 0.1f, inicio.y + 0.1f);
}

void Jogador::executarOBJ() {
    //Executa as funcoes de Jogador
    move();
}