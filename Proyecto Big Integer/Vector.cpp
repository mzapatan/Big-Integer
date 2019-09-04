#include "Vector.h"

Vector::Vector()
{
	
	vector = new unsigned short int*[tamano];
	for (int i = 0; i < tamano; i++) {
		vector[i] = nullptr;
	}
}

unsigned short int** Vector::getVector()
{
	return vector;
}

void Vector::setVector(unsigned short int** NewArray)
{
	if (NewArray != nullptr) {
		this->vector = NewArray;
}
}
