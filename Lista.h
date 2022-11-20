#pragma once
#include "Elemento.h"

//Lista tirada dos videos disponibilizados no moodle

//adaptada a mando do professor(pediu que percorresse dentro da lista, impossivel para listas template)
class Lista
{
private:
	Elemento* pPrim;
	Elemento* pUlt;
	int len;
public:
	Lista() {
		pPrim = nullptr;
		pUlt = nullptr;
		len = 0;
	}
	~Lista() {

	}
	int getLen() { return len; }
	Entidade* getItem(int pos) {
		Elemento* temp = pPrim;
		if (pos == 0) {
			return temp->getitem();
		}
		for (int i = 0; i < pos-1; i++) {
			temp = temp->getpProx();
		}

		return temp->getitem();
	}

	void percorrer(Jogador* player) {
		float f = 1.f;
		Elemento* temp = pPrim;
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

	void push(Entidade* it) {
		if (pPrim == nullptr) {
			pPrim = new Elemento;
			pPrim->setItem(it);
			pUlt = pPrim;
		}
		else {
			Elemento* temp = new Elemento;
			temp->setItem(it);
			pUlt->setpProx(temp);
			pUlt = temp;
		}
		len++;
	}

	void pop(Entidade* it) {
		Elemento* temp = pPrim;
		Elemento* tempAU = nullptr;
		while (temp->getitem() != it) {
			tempAU = temp;
			temp = temp->getpProx();
		}
		if (temp == pPrim) {
			pPrim = temp->getpProx();
		}
		else if (temp == pUlt) {
			tempAU->setpProx(nullptr);
			pUlt = tempAU;
		}
		else {
			tempAU->setpProx(temp->getpProx());
		}
		delete temp;
		len--;
	}
};