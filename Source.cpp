#include "ArbolBinario.h"
#include "ManejaArchivos.h"
#include <iostream>

using namespace std;

int main() {

	// hola

	ArbolBinario arbolito;
	
	ManejaArchivos::cargarArbol(arbolito);
	

	//cout << arbolito.enOrden(arbolito.getRaiz(), '\n');
	
	//Jugando 

	Nodo* actual = arbolito.getRaiz();

	bool res;

	while (!ArbolBinario::esHoja(actual)) {
		cout << actual->dato.getCadena() << "?" << endl;
		cout << "0- No" << endl << "1- Si" << endl << "Seleccion : ";
		cin >> res;
		system("cls");
		if (res) {
			actual = actual->der;
		}else{
			actual = actual->izq;
		}

	}
	cout << "Pensaste en : " << actual->dato.getCadena() << endl;

	// Actualizado

	system("pause");

	return 0;

}