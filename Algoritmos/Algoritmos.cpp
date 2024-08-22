#include <iostream>
#include <vector>

//#include "Pila.h"
//#include "Cola.h"
//#include "ArbolBinario.h"

#include "Nodo.h"
#include "Camino.h"

using namespace std;

#pragma region ALGORITMOS
/*
string esPar(int c) {

    if (c == 1) {
        return "Impar";
    }
    if (c == 0) {
        return "Par";
    }

    return esPar(c - 2);
}

int sum(int A, int J = 0) {
    if (A <= 0) {
        return J;
    }
    else {
        J = J + A;
        return sum(A - 1, J);
    }
}

string esPrimo(int A, int cuenta = 2) {
    if (A == cuenta) {
        return "Es primo";
    }

    if (A % cuenta == 0) {
        return "No es primo";
    }

    cuenta++;
    return esPrimo(A, cuenta++);
}

vector<int>printLine(vector<int> listaAnterior, vector<int> listaNueva, int i = 1) {
    if (i < listaAnterior.size()) {
        i++;
        listaNueva.push_back(listaAnterior[i - 1] + listaAnterior[i]);
        return printLine(listaAnterior, listaNueva, i);
    }
    else {
        return listaNueva;
    }
}

vector<vector<int>> trianguloPascal(int nivel, vector<vector<int>> lista = { {1} }) {
    if (nivel > 1) {
        vector<int> listaAnterior = lista.back();
        vector<int> nuevaLista = { 1 };
        printLine(listaAnterior, nuevaLista);

        nuevaLista.push_back(1);
        lista.push_back(nuevaLista);
        return trianguloPascal(nivel - 1, lista);
    }
    else {
        return lista;
    }
}

void esFibonacci(int entrada, int var1 = 0, int var2 = 1) {
    int resultado = var1 + var2;
    if (resultado <= entrada) {
        if (entrada == resultado) {
            cout << "es fibo";
        }
        else {
            esFibonacci(entrada, var2, resultado);
        }
    }
    else if (resultado > entrada) {
        cout << "no es fibo";
    }
}

void torreHanoi(int n, char from, char to, char aux)
{
    if (n == 0) {
        return;
    }
    torreHanoi(n - 1, from, aux, to);
    cout << "Muevo disco " << n << " de " << from << " a " << to << endl;
    torreHanoi(n - 1, aux, to, from);
}

void pasoEntrePilas(Pila* desde, Pila* hacia, Pila* aux = nullptr) {
    if (aux == nullptr) {
        aux = new Pila();
    }
    if (desde->estaVacia() && aux->estaVacia()) {
        cout << "Listo" << endl;
        delete aux;
        return;
    }
    else {
        if (!desde->estaVacia()) {
            aux->apilar(desde->obtenerTope());
            desde->desapilar();
            pasoEntrePilas(desde, hacia, aux);
        }
        if (!aux->estaVacia()) {
            hacia->apilar(aux->obtenerTope());
            aux->desapilar();
        }
    }
}

void pasoEntreColas(Cola* desde, Cola* hacia, Pila* pilaAux) {
    if (desde->estavacia() && pilaAux->estaVacia()) {
        cout << hacia->obtenerfrente();
    }
    else {
        if (!desde->estavacia()) {
            pilaAux->apilar(desde->obtenerfrente());
            desde->desencolar();
            pasoEntreColas(desde, hacia, pilaAux);
        }
        if (!pilaAux->estaVacia()) {
            hacia->encolar(pilaAux->obtenerTope());
            pilaAux->desapilar();
        }
    }
}

void invertirCola(Cola* cola, Pila* pila) {
    if (!cola->estavacia()) {
        int frente = cola->obtenerfrente();
        pila->apilar(frente);
        cola->desencolar();
        invertirCola(cola,pila);
    }
    int tope = pila->obtenerTope();
    cola->encolar(tope);
    pila->desapilar();
}
*/

#pragma endregion

void caminosNodo(Nodo* nodo) {
    std::cout << "Nodo origen: " << nodo->label << std::endl;
    std::cout << "Nodos destino: " << std::endl;
    for (int i = 0; i < nodo->caminos.size(); i++) {
        std::cout << "-> Nodo: " << nodo->caminos[i]->Destino->label << " Valor: " << nodo->caminos[i]->valor << std::endl;
    }
}

int main()
{
    Nodo* nodoA = new Nodo("A");
    Nodo* nodoB = new Nodo("B");
    Nodo* nodoC = new Nodo("C");
    Nodo* nodoD = new Nodo("D");
    Nodo* nodoE = new Nodo("E");
    Nodo* nodoF = new Nodo("F");

    nodoA->agregarCamino(nodoB, 1);
    nodoA->agregarCamino(nodoC, 8);

    nodoB->agregarCamino(nodoA, 1);
    nodoB->agregarCamino(nodoD, 2);
    nodoB->agregarCamino(nodoE, 4);

    nodoC->agregarCamino(nodoA, 8);
    nodoC->agregarCamino(nodoD, 1);
    nodoC->agregarCamino(nodoE, 4);

    nodoD->agregarCamino(nodoB, 2);
    nodoD->agregarCamino(nodoC, 1);
    nodoD->agregarCamino(nodoF, 5);

    nodoE->agregarCamino(nodoC, 4);
    nodoE->agregarCamino(nodoB, 4);
    nodoE->agregarCamino(nodoF, 5);

    nodoF->agregarCamino(nodoE, 5);
    nodoF->agregarCamino(nodoD, 5);

    
    caminosNodo(nodoA);
    caminosNodo(nodoB);
    caminosNodo(nodoC);
    caminosNodo(nodoD);
    caminosNodo(nodoE);
    caminosNodo(nodoF);

    delete nodoA;
    delete nodoB;
    delete nodoC;
    delete nodoD;
    delete nodoE;
    delete nodoF;

    return 0;
}

#pragma region FUNCIONES

//cout << "Hello World!\n";
    //int x;
    //cout << "x?: ";
    //cin >> x;
    //cout<<"Es: " << esPar(x) << endl; 
    //cout<<"Suma: " << sum(x) << endl;
    //cout << esPrimo(x) << endl;
    /*
    vector<vector<int>> resultado = trianguloPascal(20);

    // Imprimir el triángulo de Pascal
    for (const auto& lista : resultado) {
        for (int num : lista) {
            cout << num << " ";
        }
        cout << endl;
    }
    esFibonacci(144);


    Pila p1 = Pila();
    Pila p2 = Pila();

    p1.apilar(5);
    p1.apilar(4);
    p1.apilar(3);
    p1.apilar(2);
    p1.apilar(1);

    pasoEntrePilas(&p1, &p2);

    cout << p2.obtenerTope();


    Cola c1 = Cola();

    c1.encolar(1);
    c1.encolar(2);
    c1.encolar(3);
    c1.encolar(4);
    c1.encolar(5);

    Pila p1 = Pila();
    */

    //ArbolBinario* arbol = new ArbolBinario();

    //arbol->insertar(25);
    //arbol->insertar(100);
    //arbol->insertar(50);
    //arbol->insertar(75);
    //arbol->insertar(150);
    //arbol->insertar(500);
    //arbol->insertar(1500);
    //arbol->insertar(15012);
    //arbol->insertar(1504);
    //arbol->insertar(15066);

    //cout << "Impresion preorden: ";
    //arbol->imprimirPre();
    //cout << "Impresion entreorden: ";
    //arbol->imprimirEntre();
    //cout << "Impresion postorden: ";
    //arbol->imprimirPost();


    ////ArbolBinario buscado = arbol->buscar(100);
    //delete arbol;

    //torreHanoi(3, 'A', 'C', 'B');

    //Pila* pila1 = new Pila();
    //Cola* cola1 = new Cola();

    //cola1->encolar(1);
    //cola1->encolar(2);
    //cola1->encolar(3);
    //cola1->encolar(4);
    //cola1->encolar(5);

    //invertirCola(cola1, pila1);

    //cout << cola1->obtenerfrente();
    //cola1->desencolar();
    //cout << cola1->obtenerfrente();
    //cola1->desencolar();
    //cout << cola1->obtenerfrente();
    //cola1->desencolar();
    //cout << cola1->obtenerfrente();
    //cola1->desencolar();
    //cout << cola1->obtenerfrente();
    //cola1->desencolar();
    //cout << cola1->obtenerfrente();
    //cola1->desencolar();

#pragma endregion