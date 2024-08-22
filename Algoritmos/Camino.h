#ifndef CAMINO_H
#define CAMINO_H

class Nodo;  // Forward declaration de Nodo

class Camino {
public:
    int valor;
    Nodo* Origen;
    Nodo* Destino;

    Camino(Nodo* Origen, Nodo* Destino, int valor)
        : Origen(Origen), Destino(Destino), valor(valor) {}
};

#endif // CAMINO_H
