// Integer.cpp
// Autor: Dorian Vallecillo
// Descripción: Modelo del Big Integer
//
#include "Integer.h"

Integer::Integer(string valorEntrante)
{
	string valorEntranteInverso;
	short cont = 1;
	for (string::reverse_iterator inverso = valorEntrante.rbegin(); inverso != valorEntrante.rend(); inverso++) {
		valorEntranteInverso = valorEntranteInverso + *inverso;
	}
	int tamano = valorEntrante.size();
	short valorMax = 32767;
	short valorMin = -32767;
	int veces;
	int valorPrimario = 0;
	bool flagNegativo = false;
	//Validamos que el tamano sea mayor a la capacidad de un short

	if (tamano >= 5) {


		int potencia = 4;
		for (int i = 0; i < 5; i++) {
			char c = valorEntrante[i];
			int val = c - '0';
			valorPrimario += pow(10, potencia) * val;
			potencia--;
		}
	}

	if (tamano >= 5 || (valorPrimario > valorMax || valorPrimario < valorMin)) {
		if (valorEntranteInverso[valorEntranteInverso.size()-1] == '-') {
			flagNegativo = true;
			valorEntranteInverso.pop_back();

		}

		//si es mayor, solamente utilizaremos short con su maxima capacidad de pow(N,3)[Unidades de Millar], a N que pertence a [0..9] de
		
		while (valorEntranteInverso.size() > 0) {
			
			Vector* auxVec = new Vector();
			short int** auxDatos = auxVec->getVector();//el vector
			for (int j = 0; j < 4; j++) {

				int potencia = 3;
				short valor = 0;
				
				int indice = valorEntranteInverso.size() - 1;
					if (valorEntranteInverso[indice] - '0' == 0&& indice>=0) {
						auxDatos[j] = new short int(valor);
						cout << "Valor: " << valor << endl;
						valorEntranteInverso.pop_back();
						if (valorEntranteInverso.size() == 0) {
							j = 7;
						}

					}
					else if (valorEntranteInverso.size() <= 4) {

						
						int indice = valorEntranteInverso.size();
						for (int i = 0; i < indice; i++) {//aqui
						int pos = valorEntranteInverso.size() - 1;
						char c = valorEntranteInverso[pos];
						short val = c - '0';
						valor = ( pow(10, pos) * val) + valor;
						cout << "Valor: " << valor << endl;
						valorEntranteInverso.pop_back();
						}
				
					auxDatos[j] = new short int(valor);
					j = 7;
				}
				else {

					for (int i = 0; i < 4; i++) {
						int pos = valorEntranteInverso.size() - 1;
						
						char c = valorEntranteInverso[pos];
						short val = c - '0';
						valor += pow(10, potencia) * val;
						
						valorEntranteInverso.pop_back();
						potencia--;
					}
					cout << "Valor: " << valor << endl;
					auxDatos[j] = new short int(valor);
				}
			}

			bigInteger.addBack(auxVec);
			cout << "Nodo Usado # " << cont << endl;
			cont++;
		}
		if (flagNegativo) {
			short num = *bigInteger.getFront()->getVector()[0];
			short negativo = num * -1;
			*bigInteger.getFront()->getVector()[0] = negativo;
		}
		

	}else if(tamano<5) {
		Vector* auxVec = new Vector();
		short int** auxDatos = auxVec->getVector();//el vector
		int transform = atoi(valorEntrante.c_str());
		auxDatos[0] = new short int(transform);
		bigInteger.addFront(auxVec);
	}
	
	cout << "Listo" << endl;
}
string Integer::toString()
{
	stringstream p;
	if (!bigInteger.vacio()) {
		for (int i = 1; i <= this->bigInteger.tamano(); i++) {
			Vector* aux = bigInteger.getDato(i);
			for (int j = 0; j < 4; j++) {
				if (aux->getVector()[j] != nullptr) {
					p << *aux->getVector()[j];
				}
				
			}
		}
		return p.str();
	}
	else {
		p << 0;
		return p.str();
	}
}
