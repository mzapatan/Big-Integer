// Vector.h
// Autor: Dorian Vallecillo
// Descripción: Genera un modelo vector dinamico de short int de 4 posiciones
//
#ifndef VECTOR
#define VECTOR
class Vector
{
private:
	 short int **vector;
	
public:
	int const tamano = 12;
	Vector();
	short int** getVector();
	void setVector( short int** NewArray);
	int size();
	~Vector();
};

#endif // !VECTOR