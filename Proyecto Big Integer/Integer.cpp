#include "Integer.h"

Integer::Integer(string valorEntrante)
{
	string valor;
	for (string::reverse_iterator inverso = valorEntrante.rbegin(); inverso != valorEntrante.rend(); inverso++) {
		valor= valor+*inverso;
	}
	//cout << valor << endl;
	tamano = valor.size();
	
	int veces = 1;
	if (tamano > 4) {
		if (tamano % 2 == 0) {

			veces = tamano / 4;
		}
		else {
			veces = tamano / 4;
			veces++;
		}
	}


	int contInsercion = 0;
	for (int i = 0; i < veces; i++) {
		Vector* vec = new Vector();
		unsigned short** aux = vec->getVector();

		for (int j = 0; j < 4; j++) {
			int indice = valor.size() - 1;
			if (indice > -1 && contInsercion != tamano) {
				char c = valor[indice];
				unsigned short numero = c - '0';
				//cout << numero << endl;
				delete aux[j];
				aux[j] = new unsigned short(numero);
				valor.pop_back();
				contInsercion++;
			}

		}
		bigInteger.addBack(vec);
	}


	if (!bigInteger.vacio()) {
		for (int i = 1; i <= this->bigInteger.tamano(); i++) {
			Vector* aux = bigInteger.getDato(i);
			unsigned short** vector = aux->getVector();
			for (int j = 0; j < 4; j++) {
				unsigned short* var = vector[4];
				vector[4] = vector[1];


			}
		}
	}
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
