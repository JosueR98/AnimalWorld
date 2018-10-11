#include "utilidades.h"
#include <sstream>

int stringToInt(string valor)
{
	std::stringstream r(valor);
	int p;
	r >> p;
	return p;

}
