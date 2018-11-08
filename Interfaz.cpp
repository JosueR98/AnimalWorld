#include "Interfaz.h"
string Interfaz::manuInicial(Nodo* actual, Nodo* padre, ArbolBinario* arbolito)
{
	string n;
	string res;
	actual = arbolito->getRaiz();
	gotoxy(0, 2);
	cout << "\t.-------------------------------------------------------------------------------.\n";
	cout << "\t|\t\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t|\n";
	cout << "\t|\t\t\t\t\t\t\t\t\t\t|\n";
	cout << "\t*-------------------------------------------------------------------------------*\n\n\n";
	cout << "\t\t\t.-----------.\t\t\t.-----------.\n";
	cout << "\t\t\t|           |\t\t\t|           |\n";
	cout << "\t\t\t|    NO     |\t\t\t|     SI    |\n";
	cout << "\t\t\t|           |\t\t\t|           |\n";
	cout << "\t\t\t*-----------*\t\t\t*-----------*\n";
	gotoxy(88, 4);
	cout << '|';
	while (!ArbolBinario::esHoja(actual)) {
		padre = actual;
		actual = pregunta(actual, padre);
	}
	esGanador(actual, padre, arbolito);
	gotoxy(10, 4);
	cout << "Jugamos de nuevo?                         ";
	gotoxy(40, 4);
	getline(cin, n);
	return n;
}

Nodo* Interfaz::pregunta(Nodo* actual, Nodo* padre)
{
	string res;
	gotoxy(10, 4);
	cout << "Animal: "<< actual->dato.getCadena() <<" ?                                 ";
	gotoxy(40,4);
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
	gotoxy(10, 4);
	cout << "Pensaste en un@: " <<actual->dato.getCadena()<< " ?                     ";
	gotoxy(40, 4);
	getline(cin, res);
	if (boolCorrecto(res)) {
		gotoxy(10, 4);
		cout << "Yo he ganado!!                                   " << endl;
		for (int i = 0; i < 7; i++)
		{
			system("color 0F");
			system("color 1F");
			system("color 3F");
			system("color 4F");
			system("color 5F");
			system("color 6F");
			system("color 7F");
			system("color 8F");
			system("color 9F");
			system("color AF");
			system("color BF");
			system("color CF");
			system("color DF");
			system("color EF");
		}
		system("color 2F");
	}
	else {
		string pregunta, respuesta;
		gotoxy(10, 4);
		cout << "He perdido                                        ";
		gotoxy(25, 15);
		system("pause");
		gotoxy(10, 4);
		cout << "Dame una caracteristica del animal que pensaste:      ";
		getline(cin, pregunta);
		gotoxy(10, 4);
		cout << "Cual fue el animal que pensaste:                               ";
		gotoxy(44, 4);
		getline(cin, respuesta);
		arbolito->agregar(actual, padre, pregunta, respuesta);
		ManejaArchivos::guardarArbol(*arbolito);
	}
}

bool Interfaz::boolCorrecto(string in)
{
	while (in != "SI" && in != "si" && in != "NO" && in != "no")
	{
		gotoxy(25, 1);
		cout << "Digita el valor corre\actamente ( SI O NO )";
		gotoxy(40, 4);
		cout << "                                             ";
		gotoxy(40, 4);
		getline(cin, in);
	}
	gotoxy(25, 1);
	cout << "                                          ";
	return in == "SI" || in == "si";
}