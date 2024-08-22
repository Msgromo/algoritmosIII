#include "Nodo.h"
#include "Camino.h"  // Incluir Camino.h aqu� para acceso completo a la clase Camino

Nodo::Nodo(std::string label) : label(label) {
    // No se necesita hacer nada m�s aqu�
}

void Nodo::agregarCamino(Nodo* destino, int valor) {
    Camino* camino = new Camino(this, destino, valor);
    this->caminos.push_back(camino);
}
