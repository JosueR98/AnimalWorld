#include "ArbolBinario.h"
#include <iostream>
using namespace std;


bool ArbolBinario::cambioPosicion(Nodo * root, Nodo * rootp, bool i)
{
	Nodo* aux = root->izq;
	if (!esHoja(aux))
	{
		if (i) {//por la izquierda
			rootp->der = aux;
		}
		else {//por la derecha
			rootp->izq = aux;
		}
		root->izq = aux->izq;
		aux->izq = root;
		return true;
	}
	return false;
}


void ArbolBinario::toString(Nodo* root, int n)
{
	if (root)
	{
		string t = "";
		cout << root->dato; cout << "\n";
		n++;
		if (!esHoja(root))
		{
			for (size_t i = 0; i < n; i++)
			{
				t += "\t";
			}
			cout << t; toString(root->izq, n);
			cout << t; toString(root->der, n);
		}
	}
}

Nodo * ArbolBinario::encontrarCaracteristica(Nodo * root, Nodo* rootp, string inf, int v, bool i)
{
	if (root) {
		if (root->dato.getCadena() == inf) {
			while (cambioPosicion(root, rootp, i) && v--);
		}
		else {
			Nodo* n = encontrarCaracteristica(root->izq, root, inf, v, true);
			Nodo* m = encontrarCaracteristica(root->der, root, inf, v, false);
			if (n) {
				return n;
			}
			else {
				return m;
			}
		}
	}
	return nullptr;
}

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
	if (n) {
		return n->izq == nullptr && n->der == nullptr;
	}
	else {
		return false;
	}
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


