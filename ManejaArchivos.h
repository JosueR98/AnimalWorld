#pragma once
#include "ArbolBinario.h"
#include <fstream>
using std::ofstream;


class ManejaArchivos {
private:
	static void guardarRE(Nodo*,ofstream&);
public:
	static void cargarArbol(ArbolBinario&);
	static void guardarArbol(ArbolBinario&);

};