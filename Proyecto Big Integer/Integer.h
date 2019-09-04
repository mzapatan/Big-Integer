#ifndef INTEGER_H
#define INTEGER_H
#include "Estructuras_Lineales.h"
#include "Vector.h"
#include <string>
#include <sstream>
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