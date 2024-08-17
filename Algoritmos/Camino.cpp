#include "Camino.h"

Camino::Camino(Nodo* Origen, Nodo* Destino, int valor) {
	this->valor = valor;
	this->Origen = Origen;
	this->Destino = Destino;
}