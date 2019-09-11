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

Vector::~Vector()
{
	for (int i = 0; i < tamano; i++) {
		delete vector[i];
	}
	delete[]vector;
}
