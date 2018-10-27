#pragma once
#include "ArbolBinario.h"
#include "ManejaArchivos.h"
#include <iostream>
using namespace std;

class Controladora
{
private:
	ArbolBinario arbolito;
	Nodo* actual;
	Nodo* padre;
public:
	Controladora();
	~Controladora();
	void controlInicial();
};

