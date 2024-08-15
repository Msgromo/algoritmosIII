#pragma once
#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <vector>

using namespace std;

class Grafo{
private:
	vector<Nodo> nodos;
public:
	void agregarCamino();
	void agregarNodo();
};

class Nodo {
	string label;
	vector<Camino> caminos;
};

class Camino {
	int valor;
	Nodo Origen;
	Nodo Destino;
};

#endif // GRAFO_H