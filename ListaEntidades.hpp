#pragma once
#include "Lista.h"
//#include "Fase.h"

class ListaEntidades {
private:
	Lista lista;
public:

	ListaEntidades() {

	}

	~ListaEntidades() {

	}
	void percorrer(Jogador* player);

	void push(Entidade* it) {
		lista.pop(it);
	}

	void del() {
		for (int i = 0; i <= lista.getLen(); i++) {
			lista.pop(lista.getItem(i));
		}
	}
};