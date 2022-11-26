#pragma once
#include "Lista.h"
#include "Jogador.hpp"

class ListaEntidades {
private:
	Lista lista;
public:

	ListaEntidades();
	~ListaEntidades();

	bool percorrer(Jogador* player);

	void push(Entidade* it) {
		lista.push(it);
	}

	void del() {
		for (int i = lista.getLen(); i > 0; i--) {
			lista.pop(lista.getItem(i));
		}
	}
};