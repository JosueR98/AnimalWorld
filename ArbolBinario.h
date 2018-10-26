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

	void insertar(Rama elemento);
  

	static bool esHoja(Nodo*);
	void setPrioridades(Nodo* raiz);
	void agregar(Nodo* pos, Nodo* posPadre, string pregunta, string respuesta);  


};

