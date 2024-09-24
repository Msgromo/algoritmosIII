#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <set>
#include <string>

#include <fstream> // Archivos

#include <cstdlib> // Para system()

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

void caminosNodo(Nodo* nodo) {
	std::cout << "Nodo origen: " << nodo->label << std::endl;
	std::cout << "Nodos destino: " << std::endl;
	for (int i = 0; i < nodo->caminos.size(); i++) {
		std::cout << "-> Nodo: " << nodo->caminos[i]->Destino->label << " Valor: " << nodo->caminos[i]->valor << std::endl;
	}
}

*/

#pragma endregion

bool esConocido(vector<Nodo*> nodosConocidos, Nodo* x, size_t index = 0) {
	if (index >= nodosConocidos.size()) {
		return false;
	}
	if (nodosConocidos[index]->label == x->label) {
		return true;
	}
	return esConocido(nodosConocidos, x, index + 1);
}

//sumo el valor de los recorridos de forma recursiva
int sumarValorRecorridos(std::vector<Camino*> recorridos, int indice = 0, int suma = 0) {
	if (indice == recorridos.size()) {
		return suma;
	}
	else {
		suma += recorridos[indice]->valor;
		return sumarValorRecorridos(recorridos, ++indice, suma);
	}
}


// Función que recorre los caminos del nodo de forma recursiva
void recorroCaminosDelNodo(Nodo* nodoARecorrer, std::vector<Nodo*>* nodosConocidos, std::vector<Camino*>* recorridos, std::vector<Camino*>* mejorCamino, int* mejorCosto, std::string destino, size_t index = 0) {
	if (nodoARecorrer->label == destino) {
		//int costoActual = 0;
		//for (Camino* camino : *recorridos) { // solo para sumar jeje
		//	costoActual += camino->valor;
		//}
		int costoActual = sumarValorRecorridos(*recorridos);
		if (costoActual < *mejorCosto) {
			*mejorCosto = costoActual;
			*mejorCamino = *recorridos;
		}
		else if (costoActual == *mejorCosto && mejorCamino->size() > recorridos->size()) {
			*mejorCamino = *recorridos;
		}

		return;
	}

	if (index >= nodoARecorrer->caminos.size()) {
		return;
	}

	Camino* camino = nodoARecorrer->caminos[index];
	if (!esConocido(*nodosConocidos, camino->Destino)) {
		nodosConocidos->push_back(nodoARecorrer);
		recorridos->push_back(camino);

		recorroCaminosDelNodo(camino->Destino, nodosConocidos, recorridos, mejorCamino, mejorCosto, destino);

		recorridos->pop_back();
		nodosConocidos->pop_back();
	}

	recorroCaminosDelNodo(nodoARecorrer, nodosConocidos, recorridos, mejorCamino, mejorCosto, destino, index + 1);
}

std::vector<Camino*> caminoOptimo(Nodo* nodoA, std::string busco, std::vector<Nodo*> nodosConocidos = {}, std::vector<Camino*> recorridos = {}) {
	std::vector<Camino*> mejorCamino;
	int mejorCosto = std::numeric_limits<int>::max();
	recorroCaminosDelNodo(nodoA, &nodosConocidos, &recorridos, &mejorCamino, &mejorCosto, busco);
	return mejorCamino;
}

#pragma region IMAGEN 
//funciones y rutas relacionadas a la imagen del grafo
const std::string GRAPHVIZ_PATH = "C:\\Program Files\\Graphviz\\bin\\dot.exe"; //Ruta donde tengas instalado graphviz
const std::string DOT_FILE = "../grafo.dot";
const std::string PNG_FILE = "../grafo.png";

void generarImagen() {
	std::string comando = "\"" + GRAPHVIZ_PATH + "\"" + " -Tpng " + DOT_FILE + " -o " + PNG_FILE;
	std::cout << comando << std::endl; // Mostrar el comando que se va a ejecutar

	int result = system(comando.c_str());
	if (result == 0) {
		std::cout << "Imagen generada correctamente." << std::endl;
	}
	else {
		std::cerr << "Error al generar la imagen usando: " << comando << std::endl;
		throw std::runtime_error("Error al ejecutar el comando dot.");
	}
}

void abrirImagen() {
	int result = system(("start " + PNG_FILE).c_str());
	if (result != 0) {
		std::cerr << "Error al abrir la imagen " << PNG_FILE << std::endl;
	}
	else {
		std::cout << "Abriendo GRAFO." << std::endl;
	}
}

#pragma endregion

int main()
{
	// Inicializo el grafo
	/*Nodo* nodoA = new Nodo("A");
	Nodo* nodoB = new Nodo("B");
	Nodo* nodoC = new Nodo("C");
	Nodo* nodoD = new Nodo("D");
	Nodo* nodoE = new Nodo("E");
	Nodo* nodoF = new Nodo("F");
	Nodo* nodoG = new Nodo("G");


	nodoA->agregarCamino(nodoB, 1);
	nodoA->agregarCamino(nodoC, 8);
	nodoA->agregarCamino(nodoG, 20);

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
	nodoF->agregarCamino(nodoG, 50);

	nodoG->agregarCamino(nodoF, 50);
	nodoG->agregarCamino(nodoA, 20);*/

	Nodo* nodoA = new Nodo("A");
	Nodo* nodoB = new Nodo("B");
	Nodo* nodoC = new Nodo("C");
	Nodo* nodoD = new Nodo("D");
	Nodo* nodoE = new Nodo("E");
	Nodo* nodoF = new Nodo("F");
	Nodo* nodoG = new Nodo("G");
	Nodo* nodoH = new Nodo("H");
	Nodo* nodoI = new Nodo("I");
	Nodo* nodoJ = new Nodo("J");
	Nodo* nodoK = new Nodo("K");

	nodoA->agregarCamino(nodoB, 2); nodoB->agregarCamino(nodoA, 2);
	nodoB->agregarCamino(nodoC, 2); nodoC->agregarCamino(nodoB, 2);
	nodoC->agregarCamino(nodoD, 2); nodoD->agregarCamino(nodoC, 2);
	nodoD->agregarCamino(nodoE, 2); nodoE->agregarCamino(nodoD, 2);

	nodoA->agregarCamino(nodoF, 1); nodoF->agregarCamino(nodoA, 1);
	nodoE->agregarCamino(nodoH, 3); nodoH->agregarCamino(nodoE, 3);

	nodoF->agregarCamino(nodoG, 40); nodoG->agregarCamino(nodoF, 40);
	nodoG->agregarCamino(nodoH, 4); nodoH->agregarCamino(nodoG, 4);

	nodoF->agregarCamino(nodoI, 4); nodoI->agregarCamino(nodoF, 4);
	nodoI->agregarCamino(nodoK, 6); nodoK->agregarCamino(nodoI, 6);

	nodoH->agregarCamino(nodoJ, 5); nodoJ->agregarCamino(nodoH, 5);
	nodoJ->agregarCamino(nodoK, 6); nodoK->agregarCamino(nodoJ, 6);

	nodoI->agregarCamino(nodoJ, 1); nodoJ->agregarCamino(nodoI, 1);

	auto inicio = std::chrono::steady_clock::now(); // inicio contador

	std::vector<Camino*> mejorCamino = caminoOptimo(nodoA, "G");

	auto fin = std::chrono::steady_clock::now(); // paro el contador cuando termino el algoritmo
	auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

	// Muestro en consola el mejor camino
	if (mejorCamino.size() == 0) {
		std::cout << "No hay camino disponible" << std::endl;
	}
	else {
		for (Camino* camino : mejorCamino) {
			std::cout << camino->Origen->label << " -> " << camino->Destino->label << " con costo " << camino->valor << std::endl;
		}
	}
	// Fin Muestro en consola el mejor camino

	// Dibujo el grafo
	std::ofstream outFile("../grafo.dot");
	outFile << "graph G {\n";
	outFile << "	rankdir=\"LR\";\n";
	std::set<std::pair<std::string, std::string>> conexiones;

	for (Nodo* nodo : { nodoA,nodoB,nodoC,nodoD,nodoE,nodoF,nodoG,nodoH,nodoI,nodoJ,nodoK }) {
		//	for (Nodo* nodo : { nodoA, nodoB, nodoC, nodoD, nodoE, nodoF }) {
		for (Camino* camino : nodo->caminos) {
			std::string origen = nodo->label;
			std::string destino = camino->Destino->label;
			// Inserto en el json del grafo solo una ves los caminos, si se comenta este if en el grafico se ven las idas y vueltas de cada camino
			if (conexiones.insert(std::make_pair(std::min(origen, destino), std::max(origen, destino))).second) {
				outFile << "    \"" << origen << "\" -- \"" << destino
					<< "\" [label=\"" << camino->valor << "\"];\n";
			}
		}
	}
	outFile << "}\n";
	outFile.close();
	// Fin Dibujo el grafo

	// Elimino los nodos
	/*delete nodoA;
	delete nodoB;
	delete nodoC;
	delete nodoD;
	delete nodoE;
	delete nodoF;*/

	delete nodoA;
	delete nodoB;
	delete nodoC;
	delete nodoD;
	delete nodoE;
	delete nodoF;
	delete nodoG;
	delete nodoH;
	delete nodoI;
	delete nodoJ;
	delete nodoK;

	// Fin Elimino los nodos

	// Imprimo salida
	std::cout << "Tiempo de busqueda: " << duracion << " us." << std::endl;
	
	try {
		generarImagen();
		abrirImagen();
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what() << std::endl;
	}

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