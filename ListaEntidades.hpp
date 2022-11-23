#pragma once
#include "Lista.h"
#include "Jogador.hpp"

class ListaEntidades {
private:
	Lista lista;
public:

	ListaEntidades();
	~ListaEntidades();

	void percorrer(Jogador* player);

	void push(Entidade* it) {
		lista.push(it);
	}

	void del() {
		for (int i = 0; i <= lista.getLen(); i++) {
			lista.pop(lista.getItem(i));
		}
	}
};