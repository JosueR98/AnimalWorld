#include "Controladora.h"
#include "Interfaz.h"


Controladora::Controladora():arbolito(ArbolBinario()),actual(new Nodo),padre(new Nodo())
{
	ManejaArchivos::cargarArbol(arbolito);
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
		n = Interfaz::manuInicial(arbolito.getRaiz(), new Nodo(), &arbolito);
		system("cls");
	} while (Interfaz::boolCorrecto(n));
}
