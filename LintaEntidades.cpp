#include "ListaEntidades.hpp"
#include "Fase.h"

void ListaEntidades::percorrer(Jogador* player) {
	float f = 1.f;
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
			f = 1.0f;
		}
		else {
			f = 0.0f;
		}
		temp->getitem()->executarOBJ();
		temp->getitem()->print();
		//if (temp->getitem()->isharmfull() == false) {
		//	temp->getitem()->getcollider().checkcollision((entidade&)player->getcollider(), direction, f);
		//	player->emcolisao(direction);
		//}
		//else {
		//	if (temp->getitem()->getcollider().checkcollision((entidade&)player->getcollider(), direction, f) == true) {
		//		//causar dano & colidir(caso haja mais que 1 hp)
		//		//metodo dano aqui
		//		player->emcolisao(direction);
		//	}
		//}
		//if (player->getespada()->getcollider().checkcollision((entidade&)temp->getitem()->getcollider(), direction, 0) == true) {
		//	if (b) {
		//		b->setenabled(false);
		//	}
		//}
		temp = temp->getpProx();
	}
}