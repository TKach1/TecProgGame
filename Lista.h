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

	Elemento* getFirst() { return pPrim; };

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