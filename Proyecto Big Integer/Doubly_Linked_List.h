// Main.cpp
// Autor: Dorian Vallecillo
// Descripción: Estructura Lineal Dimanica Doble Enlazada
//
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
#include "Nodo.h"
template<class T>
struct DoublyNodo {
public:
	DoublyNodo<T>* anterior;
	DoublyNodo<T>* siguiente;
	T* Dato;
};
template<class T>
class Doubly_Linked_List
{
private:
	DoublyNodo<T>* head;
	DoublyNodo<T>* actual;
public:
	Doubly_Linked_List();
	DoublyNodo<T>* getHead();
	DoublyNodo<T>* getActual();
	void setHead(DoublyNodo<T>*);
	void setActual(DoublyNodo<T>*);
	T* getFront();
	T* getBack();
	void addFront(T*);
	void addBack(T*);
	void removeFront();
	void removeBack();
	bool vacio();
	T* getDato(int);
	T* getDatoReverse(int);
	~Doubly_Linked_List();
	int tamano();


};
#endif

template<class T>
inline Doubly_Linked_List<T>::Doubly_Linked_List()
{

	head = new DoublyNodo<T>();
	actual = new DoublyNodo<T>();
	head->siguiente = actual;
	actual->anterior = head;
	head->anterior = nullptr;
	actual->siguiente = nullptr;


}

template<class T>
inline DoublyNodo<T>* Doubly_Linked_List<T>::getHead()
{
	return head;
}

template<class T>
inline DoublyNodo<T>* Doubly_Linked_List<T>::getActual()
{
	return actual;
}

template<class T>
inline void Doubly_Linked_List<T>::setHead(DoublyNodo<T>* newHead)
{
	head = newHead;
}

template<class T>
inline void Doubly_Linked_List<T>::setActual(DoublyNodo<T>* newActual)
{
	actual = newActual;
}

template<class T>
inline T* Doubly_Linked_List<T>::getFront()
{
	return head->siguiente->Dato;
}

template<class T>
inline T* Doubly_Linked_List<T>::getBack()
{
	return actual->anterior->Dato;
}

template<class T>
inline void Doubly_Linked_List<T>::addFront(T* newFront)
{
	DoublyNodo<T>* aux = new DoublyNodo<T>();
	aux->Dato = newFront;
	aux->anterior = head;
	aux->siguiente = head->siguiente;

	head->siguiente->anterior = aux;
	head->siguiente = aux;

}

template<class T>
inline void Doubly_Linked_List<T>::addBack(T* entrante)
{
	DoublyNodo<T>* aux = new DoublyNodo<T>();
	aux->Dato = entrante;
	aux->anterior = actual->anterior;
	aux->siguiente = actual;
	actual->anterior->siguiente = aux;
	actual->anterior = aux;
}

template<class T>
inline void Doubly_Linked_List<T>::removeFront()
{
	DoublyNodo<T>* aux = head->siguiente->siguiente;
	delete	head->siguiente;
	head->siguiente = aux;
	aux->anterior = head;

}

template<class T>
inline void Doubly_Linked_List<T>::removeBack()
{
	DoublyNodo<T>* aux = actual->anterior->anterior;
	delete actual->anterior;

	actual->anterior = aux;
	aux->siguiente = actual;
}

template<class T>
inline bool Doubly_Linked_List<T>::vacio()
{
	return (head->siguiente == actual) ? true : false;
}

template<class T>
inline T* Doubly_Linked_List<T>::getDato(int indice)
{
	DoublyNodo<T>* aux = head->siguiente;
	int i = 0;
	while (aux != actual) {
		i++;
		if (i == indice) {
			return aux->Dato;
		}
		else {
			aux = aux->siguiente;
		}
		
	}
	return nullptr;

}

template<class T>
inline T* Doubly_Linked_List<T>::getDatoReverse(int indice)
{
	DoublyNodo<T>* aux = actual->anterior;
	int i = 0;
	while (aux != head) {
		i++;
		if (i == indice) {
			return aux->Dato;
		}
		else {
			aux = aux->anterior;
		}
		
	}
	return nullptr;
}

template<class T>
inline Doubly_Linked_List<T>::~Doubly_Linked_List()
{
	while (head->siguiente != actual) {
		removeFront();
	}
	delete head;
	delete actual;
}

template<class T>
inline int Doubly_Linked_List<T>::tamano()
{
	DoublyNodo<T>* aux = head->siguiente;
	int i = 0;
	while (aux != actual) {
		i++;
		aux = aux->siguiente;
	}
	return i;

}
