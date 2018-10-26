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

string ArbolBinario::enOrden(Nodo * r, char delimitador)
{
	string tmp;
	if (r != nullptr) {
		enOrden(r->izq, delimitador);
		s << r->dato.toString() << delimitador;
		enOrden(r->der, delimitador);
	}
	tmp = s.str();
	s.clear();
	return tmp;
}

string ArbolBinario::postOrden(Nodo * r, char delimitador)
{
	string tmp;
	if (r != nullptr) {
		enOrden(r->izq, delimitador);
		enOrden(r->der, delimitador);
		s << r->dato.toString() << delimitador;
	}
	tmp = s.str();
	s.clear();
	return tmp;
}

string ArbolBinario::preOrden(Nodo * r, char delimitador)
{
	string tmp;
	if (r != nullptr) {
		s << r->dato.toString() << delimitador;
		enOrden(r->izq, delimitador);
		enOrden(r->der, delimitador);
	}
	tmp = s.str();
	s.clear();
	return tmp;
}

int ArbolBinario::getAltura(Nodo * r)
{
	int altura_iz = 0, altura_der = 0;
	if (r != nullptr) {
		if (r->izq == nullptr && r->der == nullptr) {
			return 0;
		}
		else {
			altura_iz = this->getAltura(r->izq);
			altura_der = this->getAltura(r->der);
			return ((altura_iz > altura_der) ? altura_iz : altura_der) + 1;
		}
	}
	else {
		return 0;
	}
}

Nodo * ArbolBinario::buscarElemento(Nodo * r, Rama e)
{
	if (r != nullptr) {
		if (r->dato == e)
			return r;
		if (e < r->dato) {
			buscarElemento(r->izq, e);
		}
		else {
			buscarElemento(r->der, e);
		}
	}
	else {
		return nullptr;
	}
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

bool ArbolBinario::borrarElemento(Nodo * r, Nodo * rp, Rama elemento)
{
	return false;
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


