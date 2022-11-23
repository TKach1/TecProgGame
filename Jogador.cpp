#include "Jogador.hpp"


//TODO(opcional): adicionar deltaTime, um valor responsavel por manter o movimento constante independentemente da taxa de fps
      //resultando em uma experiencia mais suave e que pode rodar em diferentes computadores com o mesmo resultado(a (quase) qualquer fps o jogo roda igual)

Jogador::Jogador() {
    id = 1;
	initOBJ();
}

Jogador::~Jogador() {

}
void Jogador::move() {
    //"atrito" do personagem
    vx *= 0.85f;


    //movimentos
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        vx = 0.7f;
        espadaX = abs(espadaX);
        if (!isFaced) {
            //scale(sf::Vector2f(-1.0f, 1.0f));
            isFaced = true;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if (px >= 0) {
            vx = -0.7f;
            espadaX = abs(espadaX) * -1;
        }
        if (isFaced) {
            //scale(sf::Vector2f(-1.0f, 1.0f)); 
            isFaced = false;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && podePular == true && jumpTimer > 200) {
        podePular = false;
        //reseta o timer de pulo
        jumpTimer = 0;
        //aplica-se uma equacao
        //sfml trabalha com coordenadas y invertidas, negativo eh cima e positivo eh baixo
        vy = -sqrtf(2.f * 0.981f * jumpHeight);
    }
    //velocidade.y += 0.0981f;
    vy += 0.00981f;
    //cooldown pulo
    if (podePular == true && jumpTimer <= 200) {
        jumpTimer++;
    }

    //body.move(sf::Vector2f(velocidade.x, velocidade.y));
    px += vx;
    py += vy;
    //velocidade.x = 0.f;
    //velocidade.y = 0.f;
    //espada.setPosition(getPosition().x + espadaX + 12, getPosition().y+(body.getSize().y/3));
}

void Jogador::emColisao(float dx, float dy)
{
    podePular = false;
    if (dy > 0.f) {
        //Colisao em baixo
        vy = 0.f;
        podePular = true;

    }
    else if (dy < 0.f) {
        //Colisao em cima
        vy = 0.f;
    }
    if (dx < 0.f) {
        //Colisao na esquerda
        vx = 0.f;
    }
    else if (dx < 0.f) {
        //Colisao na direita
        vx = 0.f;
    }

}

sf::Vector2f Jogador::getInicio()
{
    return inicio;
}

void Jogador::Dano() {
    //body.setPosition(getInicio());
    vidas--;
    if (vidas == 0) {
        //temporario
        //window->close();
    }
}



void Jogador::initOBJ() {
    //body.setFillColor(sf::Color::White);
    //setBodySize(25.f, 25.f);
    //setOrigin();
    //inicio = body.getPosition();
    px = 50.f;
    py = 50.f;
    jumpHeight = 1.0f;
    podePular = false;
    isFaced = true;
    vidas = 3;
    jumpTimer = 0;
    vx = 0.f; 
    vy = 0.f;
    
    espada.setColor(sf::Color(0, 0, 0, 0));
    //espada.setOrigin();
    espadaX = 20.0f;
    //espada.setBodySize(10.0f, 5.0f);
    //espada.setPosition(inicio.x+espadaX + 0.1f, inicio.y + 0.1f);
    espada.setSolid(false);


    texture.loadFromFile("./Texturas/samubit.png");
    sf::Vector2u TextureSize = texture.getSize();
    TextureSize.x /= 3;
    TextureSize.y /= 11;
    //setTexture(&texture);
    //setScale(sf::Vector2f(2.f, 2.f));
    //setTextureRect(sf::IntRect(TextureSize.x * 2, (TextureSize.y * 6) + 15, TextureSize.x, TextureSize.y));
}

void Jogador::executarOBJ() {
    //Executa as funcoes de Jogador
    move();
}