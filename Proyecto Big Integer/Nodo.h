// Nodo.h
// Autor: Dorian Vallecillo
// Descripción: Se encarga de contener el dato y el puntero a siguiente
//
#ifndef NODO_H
#define NODO_H
using namespace std;
template<class T>
struct Nodo
{
public:
	T* Dato;
	Nodo<T>* siguiente;

};
#endif
