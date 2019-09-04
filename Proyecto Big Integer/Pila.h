// Main.cpp
// Autor: Dorian Vallecillo
// Descripción: Estructura Last-In/First-Out ---> Stack
//
#ifndef PILA_H
#define PILA_H
#include <iostream>
#include "Nodo.h"
using namespace std;
template<class T>
class Pila
{
private:
	Nodo<T>* pila;
public:

	Pila();
	bool empty();
	T* pop();
	void push(T*);
	~Pila();
	Nodo<T>* getPila();
};
#endif // 

template<class T>
Pila<T>::Pila()
{
	pila = nullptr;
}

template<class T>
 bool Pila<T>::empty()
{
	 return (pila == nullptr) ? true : false;
}

 template<class T>
  T* Pila<T>::pop()
 {
	  Nodo<T>* aux = pila;
	  T* dato = aux->Dato;
	  pila = aux->siguiente;
	  delete aux;
	  return dato;

 }

  template<class T>
   void Pila<T>::push(T* entrante)
  {
	   Nodo<T>* aux = new Nodo<T>();
	   aux->Dato = entrante;
	   aux->siguiente = pila;
	   pila = aux;
  }

   template<class T>
   inline Pila<T>::~Pila()
   {
	   Nodo<T>* aux;
	   while (pila != nullptr) {
		   aux = pila;
		   pila = pila->siguiente;
		   delete aux;

	   }
   }

   template<class T>
   inline Nodo<T>* Pila<T>::getPila()
   {
	   return pila;
   }
