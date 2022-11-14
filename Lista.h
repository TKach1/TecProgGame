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
	Lista();
	~Lista();
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

	void percorrer(Jogador* player, sf::Vector2f direction) {
		Elemento* temp = pPrim;
		while (temp != nullptr) {
			Personagem* b = dynamic_cast<Personagem*>((temp->getitem())); //casting
			temp->getitem()->executarOBJ();
			temp->getitem()->drawWindow();
			if (temp->getitem()->isHarmfull() == false) {
				temp->getitem()->getCollider().checkCollision((Entidade&)player->getCollider(), direction, 1.f);
				player->emColisao(direction);
			}
			else {
				if (temp->getitem()->getCollider().checkCollision((Entidade&)player->getCollider(), direction, 1.f) == true) {
					//causar dano & colidir(caso haja mais que 1 hp)
					//metodo dano aqui
					player->emColisao(direction);
				}
			}
			if (player->getEspada()->getCollider().checkCollision((Entidade&)temp->getitem()->getCollider(), direction, 0) == true) {
				if (b) {
					b->setEnabled(false);
				}
				temp = temp->getpProx();
			}
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

	void pop(Entidade* it);
};

Lista::Lista()
{
	pPrim = nullptr;
	pUlt = nullptr;
	len = 0;
}

 Lista::~Lista()
{
}

void Lista::pop(Entidade* it)
{
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

