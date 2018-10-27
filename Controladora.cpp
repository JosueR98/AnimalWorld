#include "Controladora.h"



Controladora::Controladora():arbolito(ArbolBinario()),actual(new Nodo),padre(new Nodo())
{
}


Controladora::~Controladora()
{
	delete actual;
	delete padre;
}

void Controladora::controlInicial()
{
	string n;
	string res;
	do {

	} while (n == "SI" || n == "si");
}
