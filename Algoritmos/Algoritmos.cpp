#include <iostream>
#include <vector>

#include "Pila.h"

using namespace std;

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
        return sum(A - 1,J);
    }
}

string esPrimo(int A,int cuenta = 2) {
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
        vector<int> nuevaLista = {1};
        printLine(listaAnterior, nuevaLista);
        
        nuevaLista.push_back(1);
        lista.push_back(nuevaLista);
        return trianguloPascal(nivel - 1, lista);
    } else {
        return lista;
    }
}

void esFibonacci(int entrada,int var1 = 0, int var2 = 1) {
    int resultado = var1 + var2;
    //cout << resultado;
    if (resultado <= entrada) {
        if (entrada == resultado) {
            cout << "es fibo";
        }
        else {
            esFibonacci(entrada, var2, resultado);
        }
    }
    else if(resultado > entrada) {
        cout << "no es fibo";
    }
}

void torreHanoi(int n, char from, char to,char aux) 
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
        delete aux; // Liberar la memoria de la pila auxiliar
        return;
    }
    else {
        if (!desde->estaVacia()) {
            aux->apilar(desde->obtenerTope());
            desde->desapilar();
            pasoEntrePilas(desde, hacia, aux); // Llamada recursiva antes de apilar en 'hacia'
        }
        if (!aux->estaVacia()) {
            hacia->apilar(aux->obtenerTope());
            aux->desapilar();
        }
    }
}

int main()
{
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

    torreHanoi(5, 'A', 'C', 'B');
    */

    Pila p1 = Pila();
    Pila p2 = Pila();

    p1.apilar(5);
    p1.apilar(4);
    p1.apilar(3);
    p1.apilar(2);
    p1.apilar(1);

    pasoEntrePilas(&p1, &p2);

    cout << p2.obtenerTope();

    return 0;
}