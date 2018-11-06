#include "Interfaz.h"
string Interfaz::manuInicial(Nodo* actual, Nodo* padre, ArbolBinario* arbolito)
{
	string n;
	string res;
	actual = arbolito->getRaiz();
	while (!ArbolBinario::esHoja(actual)) {
		padre = actual;
		actual = pregunta(actual, padre);
	}
	esGanador(actual, padre, arbolito);
	system("pause");
	system("cls");
	cout << "Jugamos de nuevo?\n";
	getline(cin, n);
	return n;
}

Nodo* Interfaz::pregunta(Nodo* actual, Nodo* padre)
{
	string res;
	cout << "\t.-------------------------------------------------------------------------------.\n";
	cout << "\t|\t\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t| Animal: "<< actual->dato.getCadena() <<" ?\t\t\t\t\t\t\t\t|\n";
	cout << "\t|\t\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t*-------------------------------------------------------------------------------*\n";
	cout << "\t\t\t.-----------.\t\t.-----------.\n";
	cout << "\t\t\t|           |\t\t|           |\n";
	cout << "\t\t\t|    NO     |\t\t|     SI    |\n";
	cout << "\t\t\t|           |\t\t|           |\n";
	cout << "\t\t\t*-----------*\t\t*-----------*\n";
	gotoxy(6,6);
	getline(cin, res);
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
	cout << "Pensaste en :" << actual->dato.getCadena() << " ?" << endl;
	cout << "No o Si" << endl;
	getline(cin, res);
	cout << endl;
	if (boolCorrecto(res)) {
		cout << "Yo he gane!! " << endl;
		for (int i = 0; i < 10; i++)
		{
			system("color 0F");
			system("color 1F");
			system("color 2F");
			system("color 3F");
			system("color 4F");
			system("color 5F");
			system("color 6F");
			system("color 7F");
			system("color 8F");
			system("color 9F");
		}
		system("color 0F");
	}
	else {
		string pregunta, respuesta;
		cout << "He perdido\nDame una caracteristica del animal que pensaste ";
		getline(cin, pregunta);
		cout << endl << "Cual fue el animal que pensaste";
		getline(cin, respuesta);
		arbolito->agregar(actual, padre, pregunta, respuesta);
		ManejaArchivos::guardarArbol(*arbolito);
	}
}

bool Interfaz::boolCorrecto(string in)
{
	while (in != "SI" && in != "si" && in != "NO" && in != "no")
	{
		cout << "Digita el valor corre\actamente ( SI O NO )\n";
		getline(cin, in);
	}
	return in == "SI" || in == "si";
}