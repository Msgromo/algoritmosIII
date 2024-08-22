#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <vector>

class Camino;  // Forward declaration de Camino

class Nodo {
public:
    std::string label;
    std::vector<Camino*> caminos;
    Nodo(std::string label);

    void agregarCamino(Nodo* destino, int valor);
};

#endif // NODO_H
