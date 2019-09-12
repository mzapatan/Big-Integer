// Integer.h
// Autor: Dorian Vallecillo
// Descripción: Modelo del Big Integer
//
#ifndef INTEGER_H
#define INTEGER_H
#include "Estructuras_Lineales.h"
#include "Vector.h"
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
class Integer
{
private:
	Doubly_Linked_List<Vector> bigInteger;
	int tamano;
public:
	Integer(string);
	string toString();
};

#endif // !INTEGER_H