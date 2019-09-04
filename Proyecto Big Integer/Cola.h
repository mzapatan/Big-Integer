// Main.cpp
// Autor: Dorian Vallecillo
// Descripción: Estructura First-In/First-Out ---> Cola/Fila
//
#ifndef COLA_H
#define COLA_H
#include "Nodo.h"
using namespace std;
template<class T>
class Cola
{
private:
	Nodo<T>* tail;
	Nodo<T>* head;
public:
	Nodo<T>* getTail();
	Nodo<T>* getHead();
	Cola();
	void queue(T*);
	bool empty();
	T* dequeue();
	~Cola();

};
#endif 

template<class T>
inline Nodo<T>* Cola<T>::getTail()
{
	return tail;
}

template<class T>
inline Nodo<T>* Cola<T>::getHead()
{
	return head;
}

template<class T>
inline Cola<T>::Cola()
{
	tail = nullptr;
	head = nullptr;
}

template<class T>
inline void Cola<T>::queue(T* datoEntrante)
{
	Nodo<T>* temporal = new Nodo<T>();
	temporal->Dato = datoEntrante;
	temporal->siguiente = nullptr;
	if (empty()) {
		head = temporal;
		tail = head;
	}
	else {
		tail->siguiente=temporal;
	}
	tail = temporal;

}

template<class T>
inline bool Cola<T>::empty()
{
	return (head == nullptr) ? true : false;
}

template<class T>
inline T* Cola<T>::dequeue()
{
	T* dato = head->Dato;
	Nodo<T>* aux = head;
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
		delete aux;
		return dato;
	}
	else {
		head = head->siguiente;
		return dato;
	}

}

template<class T>
inline Cola<T>::~Cola()
{
	Nodo<T>* aux;
	while (head!= tail) {
		aux = head;
		head = head->siguiente;
		delete aux;
		
	}
	delete tail;
	
}
