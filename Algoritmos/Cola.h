#pragma once
#ifndef COLA_H
#define COLA_H

class Cola {
private:
    static const int MAX = 1000;
    int elementos[MAX];
    int frente;
    int final;

public:
    Cola();
    void encolar(int elemento);
    void desencolar();
    int obtenerfrente();
    bool estavacia();
    int obtenertamanio();
};
#endif // COLA_H