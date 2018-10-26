#include "ManejaArchivos.h"
#include "utilidades.h"
using std::ifstream;

void ManejaArchivos::guardarRE(Nodo *raiz, ofstream& out)
{
	if (raiz != nullptr) {
		out << raiz->dato.toString() << '\n';
		guardarRE(raiz->izq,out);
		guardarRE(raiz->der,out);
	}
}


void ManejaArchivos::cargarArbol(ArbolBinario &arbolito)
{
	arbolito.setRaiz(nullptr); // Elimina lo que hay en el arbolito

	ifstream in;
	string cadena;
	string prioridad;
	Rama* tmp = nullptr;

	in.open("datos.txt",std::ios::in);
	
	while (in.good()) {
		getline(in, cadena, '\t');
		getline(in, prioridad, '\n');	
		if (!in.good())break;
		tmp = new Rama(cadena, stringToInt(prioridad));
		arbolito.insertar(*tmp);
	}

	in.close();
}

void ManejaArchivos::guardarArbol(ArbolBinario &arbolito)
{

	ofstream out;

	out.open("datos.txt", std::ios::trunc);

	guardarRE(arbolito.getRaiz(), out);

	out.close();

}

