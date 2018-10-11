#pragma once
#include <string>
using std::string;

class Rama {
	string cadena;
	int prioridad;
public:
	Rama();
	Rama(string);
    Rama(string, int);
    Rama(const Rama&);
    Rama& operator=(const Rama&);
	bool operator==(const Rama&);
	bool operator <(const Rama&);
	string getCadena();
	void setCadena(string);
	int getPrioridad();
	void setPrioridad(int);
	string toString();
	~Rama();
};