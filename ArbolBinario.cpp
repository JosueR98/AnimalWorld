#include "ArbolBinario.h"



ArbolBinario::ArbolBinario()
{
	raiz = nullptr;
}

Nodo * ArbolBinario::getRaiz()
{
	return raiz;
}

void ArbolBinario::setRaiz(Nodo* p)
{
	this->raiz = p;
}

void ArbolBinario::insertar(Rama elemento)
{
	Nodo* nuevo = new Nodo(elemento); 
	Nodo* root = this->raiz;
	Nodo* padre = nullptr;
	if (raiz == nullptr) {
		raiz = nuevo;
	}
	else {
		while (root != nullptr) {
			padre = root;
			if (elemento < root->dato) {
				root = root->izq;
			}
			else {
				root = root->der;
			}
		}
		if (elemento < padre->dato) {
			padre->izq = nuevo;
		}
		else
			padre->der = nuevo;

	}
}


bool ArbolBinario::esHoja(Nodo *n)
{
	return n->izq == nullptr && n->der == nullptr;
}

void ArbolBinario::setPrioridades(Nodo* raiz)
{
	if (raiz != nullptr) {
		setPrioridades(raiz->izq);
		raiz->dato.setPrioridad(++tmp);
		setPrioridades(raiz->der);
	}
}

void ArbolBinario::agregar(Nodo * pos, Nodo * posPadre, string pregunta, string respuesta)
{
	Nodo* tmp = nullptr;
	Nodo* a = new Nodo(*new Rama(pregunta));
	Nodo* b = new Nodo(*new Rama(respuesta));


	if (posPadre->izq == pos) {
		tmp = pos;
		posPadre->izq = a;
		a->izq = tmp;
		a->der = b;

	}
	if (posPadre->der == pos) {
		tmp = pos;
		posPadre->der = a;
		a->izq = tmp;
		a->der = b;
	}

	tmp->izq = nullptr;
	tmp->der = nullptr;

	setPrioridades(raiz);
}


