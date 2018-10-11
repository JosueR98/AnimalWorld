#pragma once
#include "Rama.h"
#include <sstream>
using std::stringstream;


struct Nodo {
	Rama dato;
	Nodo* izq;
	Nodo* der;

	Nodo() { izq = der = nullptr; }
	Nodo(Rama elemento) {
		this->dato = elemento;
		izq = der = nullptr;
	}
};

class ArbolBinario {
private:
	Nodo * raiz;
	stringstream s; // Para los recorridos
	int tmp = 0; // Para el metodos setPrioridades, contador que ira aumentando 
public:
	// Basicos
	ArbolBinario();
	Nodo* getRaiz();
	void setRaiz(Nodo*);

	// Recorridos
	string enOrden(Nodo* r, char delimitador);
	string postOrden(Nodo* r, char delimitador);
	string preOrden(Nodo* r, char delimitador);

	// Complejos
	int  getAltura(Nodo* r);
	Nodo* buscarElemento(Nodo* r, Rama e); 
	void insertar(Rama elemento);
    bool borrarElemento(Nodo* r, Nodo* rp, Rama elemento);

	static bool esHoja(Nodo*);
	void setPrioridades(Nodo* raiz);

	// Faltantes
	void agregar(Nodo* pos, Nodo* posPadre, string pregunta, string respuesta);  


};

