#include "Interfaz.h"
void Interfaz::manuInicial(Nodo* actual, Nodo* padre, ArbolBinario* arbolito)
{
	string n;
	string res;
	do {
		actual = arbolito->getRaiz();
		while (!ArbolBinario::esHoja(actual)) {
			padre = actual;
			actual = pregunta(actual, padre);
		}
		esGanador(actual, padre, arbolito);
		system("pause");
		system("cls");
		cout << "Jugamos de nuevo : ";
		getline(cin, n);
	} while (boolCorrecto(n));
}

Nodo* Interfaz::pregunta(Nodo* actual, Nodo* padre)
{
	string res;
	cout << actual->dato.getCadena() << "?" << endl;
	cout << "0- No" << endl << "1- Si" << endl << "Seleccion : ";
	getline(cin, res);
	system("cls"); 
	if (boolCorrecto(res)) {
		return actual->der;
	}
	else {
		return actual->izq;
	}
}

void Interfaz::esGanador(Nodo* actual, Nodo* padre, ArbolBinario* arbolito)
{
	string res;
	cout << "Pensaste en : " << actual->dato.getCadena() << endl;
	cout << "0- No" << endl << "1- Si" << endl << "Seleccion : ";
	getline(cin, res);
	cout << endl;
	if (boolCorrecto(res)) {
		cout << "Gane izi pizi" << endl;
	}
	else {
		string pregunta, respuesta;
		cout << "Perdi" << endl << "Pregunta : ";
		getline(cin, pregunta);
		cout << endl << "Respuesta : ";
		getline(cin, respuesta);
		arbolito->agregar(actual, padre, pregunta, respuesta);
		ManejaArchivos::guardarArbol(*arbolito);
	}
}

bool Interfaz::boolCorrecto(string in)
{
	while (in != "SI" && in != "si" && in != "NO" && in != "no")
	{
		cout << " DIGITE CORRECTAMENTE EL VALOR ( SI O NO )\n";
		getline(cin, in);
	}
	return in == "SI" || in == "si";
}