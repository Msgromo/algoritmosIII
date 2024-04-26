#pragma once
#ifndef PILA_H
#define PILA_H

class Pila {
private:
	const static int MAX = 1000;
	int elementos[MAX];
	int tope;
public:
	Pila();
	~Pila();
	void apilar(int elemento);
	void desapilar();
	int obtenerTope();
	bool estaVacia();
	int obtenerTamaño();
};

#endif // PILA_H