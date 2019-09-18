// Vector.cpp
// Autor: Dorian Vallecillo
// Descripción: Genera un modelo vector dinamico de short int de 4 posiciones
//
#include "Vector.h"

Vector::Vector()
{
	
	vector = new short int*[tamano];
	for (int i = 0; i < tamano; i++) {
		vector[i] = nullptr;
	}
}

 short int** Vector::getVector()
{
	return vector;
}

void Vector::setVector( short int** NewArray)
{
	if (NewArray != nullptr) {
		this->vector = NewArray;
		}


}

int Vector::size()
{
	int retorno = 0;
	for (int i = 0; i < tamano; i++) {
		if (vector[i] != nullptr) {
			retorno++;
		}
	}
	return retorno;
}

Vector::~Vector()
{
	for (int i = 0; i < tamano; i++) {
		if (vector[i] != nullptr) {
			delete vector[i];
		}
		
	}
	
}
