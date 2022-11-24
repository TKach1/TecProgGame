#include "ListaEntidades.hpp"
#include "Fase.h"

ListaEntidades::ListaEntidades() {

}

ListaEntidades::~ListaEntidades() {

}

void ListaEntidades::percorrer(Jogador* player) {
	float f = 1.f;
	float dy = 0, dx = 0;
	float a = 0;
	Elemento* temp = lista.getFirst();
	while (temp != nullptr) {
		Personagem* b = dynamic_cast<Personagem*>((temp->getitem())); //casting
		if (b) {
			if (!b->isEnabled()) {
				temp = temp->getpProx();
				continue;
			}
		}
		if (temp->getitem()->isSolid()) {
			f = 0.0f;
		}
		else {
			f = 1.0f;
		}
		temp->getitem()->executarOBJ();
		if (temp->getitem()->isHarmfull() == false) {
			GerenColisao::checkCollision(*player, (Entidade&)*(temp->getitem()), dx, dy, f);
			player->emColisao(dx, dy);
		}
		else {
			if (GerenColisao::checkCollision(*player, (Entidade&)*(temp->getitem()), dx, dy, f) == true) {
				//causar dano & colidir(caso haja mais que 1 hp)
				//metodo dano aqui
				GerenGraf::setDano(true);
				player->emColisao(dx, dy);
			}
		}
		if (GerenColisao::checkCollision(*(player->getEspada()), (Entidade&)*(temp->getitem()), a, a, 0.0f) == true) {
			if (b) {
				b->setEnabled(false);
			}
		}
		temp->getitem()->print(0);
		temp = temp->getpProx();
	}
}