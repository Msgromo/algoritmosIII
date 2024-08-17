#pragma once
#ifndef NODO_H
#define NODO_H

#include <iostream>

class Nodo {
public:
	std::string label;
	//vector<Camino> caminos = {};
	Nodo(std::string label);
	//void agregarCamino(Camino camino);
};

#endif // NODO_H