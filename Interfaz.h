#pragma once
#include "Controladora.h"

class Interfaz
{
public:
	static void manuInicial(Nodo * actual, Nodo * padre, ArbolBinario* arbolito);
	static Nodo* pregunta(Nodo * actual, Nodo * padre);
	static void esGanador(Nodo * actual, Nodo * padre, ArbolBinario* arbolito);
	static bool boolCorrecto(string in);
};

