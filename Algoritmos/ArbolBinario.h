#pragma once
#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

class ArbolBinario {
private:
	class Nodo {
	public:
		int info;
		Nodo* izq;
		Nodo* der;
	};
	int nivel;
	Nodo* raiz;
	void borrar(Nodo* reco);
	void imprimirPre(Nodo* reco);
	void imprimirEntre(Nodo* reco);
	void imprimirPost(Nodo* reco);
public:
	ArbolBinario();
	~ArbolBinario();
	void insertar(int x);
	void imprimirPre();
	void imprimirEntre();
	void imprimirPost();
};

#endif // ARBOLBINARIO_H