#pragma once
#include "ArbolBinario.h"
#include "ManejaArchivos.h"
#include "utilidades.h"
#include <iostream>
using namespace std;

class Interfaz
{
public:
	static string manuInicial(Nodo * actual, Nodo * padre, ArbolBinario* arbolito);
	static Nodo* pregunta(Nodo * actual, Nodo * padre);
	static void esGanador(Nodo * actual, Nodo * padre, ArbolBinario* arbolito);
	static bool boolCorrecto(string in);
};

