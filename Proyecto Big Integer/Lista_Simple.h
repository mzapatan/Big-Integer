// Main.cpp
// Autor: Dorian Vallecillo
// Descripción: Estructura Lineal Dinamica Lista
//
#ifndef LISTA_SIMPLE
#define LISTA_SIMPLE
#include "Nodo.h"
using namespace std;
template<class T>
class Lista_Simple
{private:
	Nodo<T>* head;
	Nodo<T>* actual;
public:
	Nodo<T>* getHead();
	Nodo<T>* getActual();
	Lista_Simple() {
		head = nullptr;
		actual = nullptr;
	}
	T* getDato(int);
	int cuentaNodos();
	bool listaVacia();
	void insertarAdelante(T*);
	void insertarFinal(T*);
	void eliminarFinal();
	~Lista_Simple();
};

#endif // !LISTA_SIMPLE

template<class T>
inline Nodo<T>* Lista_Simple<T>::getHead()
{
	return head;
}

template<class T>
inline Nodo<T>* Lista_Simple<T>::getActual()
{
	return actual;
}

template<class T>
inline T* Lista_Simple<T>::getDato(int indice)
{
	actual = head;
	int i = 0;
	for (int i = 0; i < indice; i++) {
		if (actual!= nullptr) {
			actual = actual->siguiente;
		}
		
	}
	if (actual != nullptr) {
		return actual->Dato;
	}
	else {
		return nullptr;
	}
}

template<class T>
inline int Lista_Simple<T>::cuentaNodos()
{
	actual = head;
	unsigned can = 0;
	while (actual != nullptr)
	{
		can++;
		actual = actual->siguiente;
	}
	return can;
}

template<class T>
inline bool Lista_Simple<T>::listaVacia()
{
	return  (head == nullptr) ? true : false;
}

template<class T>
inline void Lista_Simple<T>::insertarAdelante(T* newDato)
{
	
	if (head == nullptr) {
		Nodo<T>* aux= new Nodo<T>();
		aux->Dato = newDato;
		aux->siguiente = nullptr;
		head = aux;
	}
	else {
		Nodo<T>* aux = new Nodo<T>();
		aux->Dato = newDato;
		aux->siguiente = head;
		head = aux;
	}
}

template<class T>
inline void Lista_Simple<T>::insertarFinal(T* dat)
{
	
	if (head != nullptr) {
		actual = head;
		while (actual->siguiente != nullptr) {
			actual = actual->siguiente;
		}
		Nodo<T>* aux = new Nodo<T>();
		aux->Dato = dat;
		aux->siguiente = nullptr;
		actual->siguiente = aux;
	}
	else {
		head = new Nodo<T>();
		head->Dato = dat;
		head->siguiente = nullptr;
	}
}

template<class T>
inline void Lista_Simple<T>::eliminarFinal()
{
	if (head != nullptr) {
		actual = head;
		while (actual->siguiente != nullptr) {
			actual = actual->siguiente;

		}
		delete actual->siguiente;

	}
}

template<class T>
inline Lista_Simple<T>::~Lista_Simple()
{
	actual = head;
	while (head != nullptr) {
		actual = head;
		head = head->siguiente;
		delete actual;
	}
}
