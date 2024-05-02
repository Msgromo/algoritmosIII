#include <iostream>
#include "Cola.h"

Cola::Cola() {
    frente = -1;
    final = -1;
}

void Cola::encolar(int elemento) {
    if (final >= MAX - 1) {
        std::cout << "Error: cola llena." << std::endl;
    }
    else {
        if (frente == -1) {
            frente = 0;
        }
        elementos[++final] = elemento;
    }
}

void Cola::desencolar() {
    if (frente == -1 || frente > final) {
        std::cout << "Error: Cola vacia." << std::endl;
    }
    else {
        ++frente;
    }
}

int Cola::obtenerfrente() {
    if (frente == -1 || frente > final) {
        std::cout << "tu cola esta vacia." << std::endl;
        return -1; //  indica que la cola esta vacia
    }
    else {
        return elementos[frente];
    }
}

bool Cola::estavacia() {
    return frente == -1 || frente > final;
}

int Cola::obtenertamanio() {
    return final - frente + 1;
}
