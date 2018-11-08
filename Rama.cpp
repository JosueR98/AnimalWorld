#include "Rama.h"
#include <exception>

Rama::Rama()
{
	cadena = "";
	prioridad = -1;
}

Rama::Rama(string c)
{
	this->cadena = c;
	prioridad = -1;
}

Rama::Rama(string cadena,int prioridad)
{
	this->cadena = cadena;
	this->prioridad = prioridad;
}

Rama::Rama(const Rama &copia)
{
	this->cadena = copia.cadena;
	this->prioridad = copia.prioridad;
}

Rama & Rama::operator=(const Rama &copia)
{
	this->cadena = copia.cadena;
	this->prioridad = copia.prioridad;

	return *this;
}

bool Rama::operator==(const Rama &rama2)
{
	return rama2.prioridad == this->prioridad;
}

bool Rama::operator<(const Rama &rama2)
{
	return  this->prioridad < rama2.prioridad;
}

string Rama::getCadena()
{
	return string(cadena);
}

void Rama::setCadena(string cadena)
{
	this->cadena = cadena;
}

int Rama::getPrioridad()
{
	return prioridad;
}

void Rama::setPrioridad(int prioridad)
{
	this->prioridad = prioridad;
}

string Rama::toString()
{
	return string(cadena + "\t" + std::to_string(prioridad));
}

Rama::~Rama()
{

}

ostream& operator << (ostream &o, const Rama &p) {
	o << p.cadena;
	return o;
}
