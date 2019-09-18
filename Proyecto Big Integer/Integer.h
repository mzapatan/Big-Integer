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
	~Integer();
	bool operator ==(Integer&);
	string convertir_str_quitar_ceros();
	bool operator !=(Integer&);
	bool operator <(Integer&);
	bool operator >(Integer&);
	bool operator >=(Integer&);
	bool operator <=(Integer&);
	Integer& operator - (Integer& i);
	Integer& operator + (Integer& i);
	void acarreo();
	int getValor(int i) const;
	friend ostream& operator <<(ostream& o, Integer& i);
	Integer& operator * (Integer& i);
};

#endif // !INTEGER_H