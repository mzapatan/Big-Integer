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
		if (valorEntranteInverso[valorEntranteInverso.size() - 1] == '-') {
			flagNegativo = true;
			valorEntranteInverso.pop_back();

		}

		//si es mayor, solamente utilizaremos short con su maxima capacidad de pow(N,3)[Unidades de Millar], a N que pertence a [0..9] de

		while (valorEntranteInverso.size() > 0) {

			Vector* auxVec = new Vector();
			short int** auxDatos = auxVec->getVector();//el vector
			for (int j = 0; j < auxVec->tamano; j++) {

				int potencia = 3;
				short valor = 0;

				int indice = valorEntranteInverso.size() - 1;
				if (valorEntranteInverso[indice] - '0' == 0 && indice >= 0) {
					auxDatos[j] = new short int(valor);
					cout << "Valor: " << valor << endl;
					valorEntranteInverso.pop_back();
					if (valorEntranteInverso.size() == 0) {
						j = 70;
					}

				}
				else if (valorEntranteInverso.size() <= 4) {

					int indice = valorEntranteInverso.size();
					for (int i = 0; i < indice; i++) {//aqui
						int pos = valorEntranteInverso.size() - 1;
						char c = valorEntranteInverso[pos];
						short val = c - '0';
						valor = (pow(10, pos) * val) + valor;

						valorEntranteInverso.pop_back();
					}
					cout << "Valor: " << valor << endl;
					auxDatos[j] = new short int(valor);
					j = 70;
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


	}
	else if (tamano < 5) {
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
			for (int j = 0; j < aux->tamano; j++) {
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
string Integer::convertir_str_quitar_ceros() {
	string concat = "";
	string sinCerosAlInicio = "";
	if (!bigInteger.vacio()) {

		for (int i = 1; i <= this->bigInteger.tamano(); i++) {
			Vector* aux = bigInteger.getDato(i);
			for (int j = 0; j < 4; j++) {
				if (aux->getVector()[j] != nullptr) {
					string str = to_string(*aux->getVector()[j]);
					concat.append(str);
				}
			}
		}

		if (concat.front() == '0') {
			sinCerosAlInicio = concat.substr(1);
		}
		else {
			sinCerosAlInicio = concat;
		}
	}
	return sinCerosAlInicio;

}



bool Integer::operator ==( Integer& valor)  {
	string string_1 = convertir_str_quitar_ceros();
	string string_2 = valor.convertir_str_quitar_ceros();

	if (string_1.size() != string_2.size()) {	//Se verifica si el tama�o es igual, si no lo es retorna falso.
		return false;
	}
	else {
		for (int i = 0; i < string_1.size(); i++) {   //Se verifica elemento por elemento de la cifra para verificar si el n�mero es identico.
			if ((int(string_1[i]) != int(string_2[i]))) {
				return false;
			}
		}
		//COMENTARIO HECHO POR MIKE:
			//Con los l�mites no dar�a error por que en los if iniciales, se retorna true y false, seg�n el size de los numeros, ya que esto cumplir�a la condici�n directamente
			//La condici�n para entrar al for o while es que el tama�o de ambos sea iguales, esto ya sin los ceros a la izquierda que previamente fueron quitados.
	}
	return true;
}

bool Integer::operator !=(Integer& valor) {
	string string_1 = convertir_str_quitar_ceros();
	string string_2 = valor.convertir_str_quitar_ceros();

	if (string_1.size() != string_2.size()) {   //Se verifica si el tama�o es diferente, al cumplirse esto retorna verdadero.
		return true;
	}
	else {
		for (int i = 0; i < string_1.size(); i++) {  //Se verifica elemento por elemento de la cifra para verificar si hay alg�n elemento diferente.
			if (int(string_1[i]) != int(string_2[i])) {
				return true;
			}
		}
		//COMENTARIO HECHO POR MIKE:
				//Con los l�mites no dar�a error por que en los if iniciales, se retorna true y false, seg�n el size de los numeros, ya que esto cumplir�a la condici�n directamente
				//La condici�n para entrar al for o while es que el tama�o de ambos sea iguales, esto ya sin los ceros a la izquierda que previamente fueron quitados.
	}
	return false;
}

bool Integer::operator <(Integer& valor) {
	string string_1 = convertir_str_quitar_ceros();
	string string_2 = valor.convertir_str_quitar_ceros();

	if (string_1.size() < string_2.size()) {   //Primero se verifica si el primer n�mero de A es menor al de B, al cumplirse esto, directamente se sabr�a que es menor la cifra.
		return true;
	}
	if (string_1.size() > string_2.size()) {   //Luego se verifica si el primer n�mero de A es mayor al de B, al cumplirse esto, directamente se sabr�a que es menor la cifra.
		return false;
	}
	else if (string_1[0] < string_2[0]) {   //Al tener la misma cantidad de digitos, se verifica si el primer digito es igual o menor, al ser menor cumple directamente la condici�n.
		return true;
	}
	else if (string_1[0] == string_2[0]) { //Si las dos cifras incian con el mismo digito, se comenzar� a envaluar digito por digito hasta verificar con el resto de la cifra que se cumpla o no la condici�n del operador.
		int i = 1;
		while (i < string_1.size()) {

			if (int(string_1[i]) < int(string_2[i])) {  //Se recorren todos los digitos, en el momento que un d�gito de A sea mayor a B, se dejar� de cumplir la condici�n y se retorna falso, sino true.
				return true;
			}
			else if (string_1[i] > string_2[i]) {
				return false;
			}
			++i;
			//COMENTARIO HECHO POR MIKE:
			//Con los l�mites no dar�a error por que en los if iniciales, se retorna true y false, seg�n el size de los numeros, ya que esto cumplir�a la condici�n directamente
			//La condici�n para entrar al for o while es que el tama�o de ambos sea iguales, esto ya sin los ceros a la izquierda que previamente fueron quitados.
		}
	}
	return false;
}

bool Integer::operator >(Integer& valor) {
	string string_1 = convertir_str_quitar_ceros();
	string string_2 = valor.convertir_str_quitar_ceros();

	if (string_1.size() > string_2.size()) {  //Primero se verifica si el primer n�mero de A es menor al de B, al cumplirse esto, directamente se sabr�a que es mayor la cifra.
		return true;
	}
	if (string_1.size() < string_2.size()) {  //Luego se verifica si el primer n�mero de A es mayor al de B, al cumplirse esto, directamente se sabr�a que es mayor la cifra.
		return false;
	}
	else if (string_1[0] > string_2[0]) {//Al tener la misma cantidad de digitos, se verifica si el primer digito es igual o mayor, al ser mayor cumple directamente la condici�n.
		return true;
	}
	else if (string_1[0] == string_2[0]) { //Si las dos cifras incian con el mismo digito, se comenzar� a envaluar digito por digito hasta verificar con el resto de la cifra que se cumpla o no la condici�n del operador.
		int i = 1;
		while (i < string_1.size()) {

			if (int(string_1[i]) > int(string_2[i])) {
				return true;
			}
			else if (string_1[i] < string_2[i]) {  //Se recorren todos los digitos, en el momento que un d�gito de A sea menor a B, se dejar� de cumplir la condici�n y se retorna falso, sino true.
				return false;
			}
			++i;

			//COMENTARIO HECHO POR MIKE:
			//Con los l�mites no dar�a error por que en los if iniciales, se retorna true y false, seg�n el size de los numeros, ya que esto cumplir�a la condici�n directamente
			//La condici�n para entrar al for o while es que el tama�o de ambos sea iguales, esto ya sin los ceros a la izquierda que previamente fueron quitados.
		}
	}
	return false;
}

bool Integer::operator >=(Integer& valor) {
	if (operator >(valor) || operator ==(valor)) {  //Se utilizan los metodos anteriores en conjunto.
		return true;
	}
	return false;
}

bool Integer::operator <=(Integer& valor) {
	if (operator <(valor) || operator ==(valor)) { //Se utilizan los metodos anteriores en conjunto.
		return true;
	}
	return false;
}
void Integer::acarreo() {
	string valor = convertir_str_quitar_ceros();
	for (int i = 0; i < valor.size(); ++i) {
		int acarreo = valor[i] / 10; //Se le asigna el valor de acarreo dependiendo de su decena
		valor[i] %= 10;
		if (i == valor.size() - 1 && acarreo != 0) { // se asigna el valor de acarreo en el lugar correspondiente
			valor.push_back(acarreo);
		}
		else {
			valor[i + 1] += acarreo;
		} //se manda el acarreo a el numero siguiente (de unidad a decena, de decena a centena
	}
}
int Integer::getValor(int i) const {
	string valor;
	if (i < 0) {
		throw exception();
		if (i > valor.size() - 1)
			return 0;
		return valor[i];

	}
}
Integer& Integer::operator +(Integer& i) { //Sobrecarga de suma
	Integer suma("");
	string suma_valor = suma.convertir_str_quitar_ceros();
	string valor_i = i.convertir_str_quitar_ceros();


	for (int w = valor_i.size() - 1; w >= 0; --w) {
		suma_valor[w] = suma.getValor(w) + i.getValor(w);
	}
	suma.acarreo();
	return suma;
}
ostream& operator << (ostream& o, Integer& i) {
	string valor_i = i.convertir_str_quitar_ceros();
	for (int a = valor_i.size() - 1; a >= 0; --a) {
		o << valor_i[a];
	}
	return o;
}

Integer& Integer::operator -(Integer& i) {//sobrecarga de resta
	Integer resta("");

	string resta_valor = resta.convertir_str_quitar_ceros();
	string valor_i = i.convertir_str_quitar_ceros();

	resta_valor.resize(resta_valor.size(), valor_i.size());

	for (int w = 0; w < resta_valor.size() - 1; w++) {
		resta_valor[w] = resta.getValor(w) - i.getValor(w);
	}
	resta.acarreo();

	return resta;
}
Integer& Integer::operator * (Integer& i) {//sobrecarga multiplicacion
	Integer multi("");
	string  multi_valor = multi.convertir_str_quitar_ceros();
	string valor_i = i.convertir_str_quitar_ceros();
	multi_valor.resize(multi_valor.size() + valor_i.size(), 0);
	for (int i = 0; i < multi_valor.size(); ++i) {
		for (int j = 0; j < multi_valor.size(); ++j) {
			multi_valor[i + j] += multi_valor[i] * valor_i[j];
		}
	}
	multi.acarreo();
	//multi.RemoverCeros();
	return multi;
}

Integer::~Integer()
{
	 bigInteger.~Doubly_Linked_List();
}
