#include "Ente.hpp"

Ente::Ente(int _id) {
	id = _id;
	px = 0.f;
	py = 0.f;
	g = GerenGraf::GetInstance();
}

Ente::~Ente() {

}

void Ente::executarOBJ() {

}

void Ente::print() {
	g->imprime(id, px, py);
}