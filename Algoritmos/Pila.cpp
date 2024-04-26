#include <iostream>
#include "Pila.h"

Pila::Pila() {
	tope = -1;
}

Pila::~Pila() {
}

void Pila::apilar(int elemento) {
	if (tope >= MAX - 1) {
		std::cout << "Error: Pila llena." << std::endl;
	}
	else {
		elementos[++tope] = elemento;
	}
}

void Pila::desapilar() {
	if (tope < 0) {
		std::cout << "Error: Pila vacia." << std::endl;
	}
	else {
		--tope;
	}
}

int Pila::obtenerTope() {
	if (tope >= 0) {
		return elementos[tope];
	}
	else {
		std::cout << "La pila esta vacia" << std::endl;
		return -1;
	}
}

bool Pila::estaVacia() {
	return tope < 0;
}

int Pila::obtenerTamaño() {
	return tope + 1;
}