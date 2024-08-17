#pragma once
#ifndef CAMINO_H
#define CAMINO_H

#include "Nodo.h"

class Camino {
public:
	int valor;
	Nodo* Origen;
	Nodo* Destino;
	Camino(Nodo* Origen, Nodo* Destino, int valor);
};

#endif // CAMINO_H