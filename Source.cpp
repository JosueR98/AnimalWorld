#include "Controladora.h"
#include "utilidades.h"
//inline void jugar(ArbolBinario &); // ERROR al ingresar la pregunta o respuesta si se pone un espacio no sirve

int main() {
	system("mode con: cols=97 lines=17");
	system("color 2f");
	Controladora* c = new Controladora();
	c->controlInicial();
	delete c;
	//ArbolBinario arbolito;
	//ManejaArchivos::cargarArbol(arbolito);
	//cout << arbolito.encontrarCaracteristica(arbolito.getRaiz(), nullptr, "Mamifero", 2);
	////arbolito.setPrioridades(arbolito.getRaiz());
	////ManejaArchivos::guardarArbol(arbolito);
	//arbolito.toString(arbolito.getRaiz(), 0);
	//system("pause");
	//Interfaz::manuInicial(arbolito.getRaiz(), new Nodo(), &arbolito);
	// hola
	//ArbolBinario arbolito;
	//
	//ManejaArchivos::cargarArbol(arbolito);
	//bool res = 0;
	//do {
	//	jugar(arbolito);
	//	system("cls");
	//	cout << "Jugamos de nuevo : "; cin >> res;
	//} while (res != 0);
	//system("pause");
	return 0;
}

//inline void jugar(ArbolBinario &arbolito)
//{
//	Nodo* actual = arbolito.getRaiz();
//	Nodo* padre = nullptr;
//	bool res;
//	while (!ArbolBinario::esHoja(actual)) {
//		cout << actual->dato.getCadena() << "?" << endl;
//		cout << "0- No" << endl << "1- Si" << endl << "Seleccion : ";
//		cin >> res;
//		system("cls");
//		if (res) {
//			padre = actual;
//			actual = actual->der;
//		}
//		else {
//			padre = actual;
//			actual = actual->izq;
//		}
//	}
//
//	cout << "Pensaste en : " << actual->dato.getCadena() << endl;
//	cout << "0- No" << endl << "1- Si" << endl << "Seleccion : ";
//	cin >> res;
//	cout << endl;
//	if (res) {
//		cout << "Gane izi pizi" << endl;
//	}
//	else {
//		string pregunta, respuesta;
//		cout << "Perdi" << endl << "Pregunta : ";
//		cin >> pregunta;
//
//		cout << endl << "Respuesta : ";
//		cin >> respuesta;
//
//		arbolito.agregar(actual, padre, pregunta, respuesta);
//		ManejaArchivos::guardarArbol(arbolito);
//	}
//
//}
