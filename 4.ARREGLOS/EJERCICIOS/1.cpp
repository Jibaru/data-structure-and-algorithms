/*
1. Defina la clase ArregloEnteros. Determine los atributos y el conjunto de métodos
(lo más completo posible) que caracterizan al concepto arreglo unidimensional de números enteros.
*/

#include <iostream>

using namespace std;

#define MAX 30

class ArregloEnteros {
private:
	int elementos[MAX];
	int tam;

public:
	ArregloEnteros();
	int insertar(int);
	int eliminar(int);
	int buscar(int);
	void lectura();
	void imprime();
};

ArregloEnteros::ArregloEnteros()
{
	tam = 0;
}

void ArregloEnteros::lectura()
{
	int indice;

	do {
		cout << "Ingrese el total de elementos: ";
		cin >> tam;
	} while(tam < 1 || tam > MAX);


	for(indice = 0; indice < tam; indice ++) {
		cout << "Ingrese el elemento " << indice + 1 << ": ";
		cin >> elementos[indice];
	}

}


//  Devuelve la posición encontrada del valor a buscar
//  en caso contrario devuelve -1
int ArregloEnteros::buscar(int valor)
{
	int indice = 0, resultado = -1;
	while((indice < tam) && (elementos[indice] != valor))
		indice++;

	if(indice < tam)
		resultado = indice;

	return resultado;
}

// Devuelve 0 si el arreglo está lleno
// Devuelve 1 si el valor se insertó
// Devuelve -1 si el valor no se insertó (ya existe)
int ArregloEnteros::insertar(int valor)
{
	int posic, resultado = 1;

	if(tam < MAX) {
		int posic = buscar(valor);
		if(posic < 0) {
			// Aumenta el tamaño a 1 más e ingresa el nuevo valor
			elementos[tam++] = valor;
		} else {
			resultado = -1;
		}
	} else {
		resultado = 0;
	}

	return resultado;
}

// Devuelve 0 si no hay elementos en el arreglo
// Devuelve 1 si se eliminó
// Devuelve -1 si no se eliminó
int ArregloEnteros::eliminar(int valor)
{
	int indice, posic, resultado = 1;

	if(tam > 0) {
		posic = buscar(valor);
		if(posic < 0)
			resultado = -1;
		else {
			for(indice = posic; indice < tam; indice++)
				elementos[indice] = elementos[indice + 1];
			tam--;
		}

	} else {
		resultado = 0;
	}

	return resultado;
}

void ArregloEnteros::imprime()
{
	int indice = 0;
	cout << "Elementos del arreglo" << endl;
	while(indice < tam) {
		cout << elementos[indice] << " ";
		indice ++;
	}
	cout << endl;
}

void usaArregloEnteros()
{
	ArregloEnteros arr = ArregloEnteros();
	int nuevo, res;

	arr.lectura();

	cout << "Insertar nuevo elemento: ";
	cin >> nuevo;
	res = arr.insertar(nuevo);
	if(res == 0)
		cout << "Arreglo lleno" << endl;
	else if(res == 1)
		cout << "Elemento insertado" << endl;
	else if(res == -1)
		cout << "Elemento repetido" << endl;
	arr.imprime();

	cout << "Elimina elemento: ";
	cin >> nuevo;
	res = arr.eliminar(nuevo);
	if(res == 0)
		cout << "Arreglo sin elementos" << endl;
	else if(res == 1)
		cout << "Elemento eliminado" << endl;
	else if(res == -1)
		cout << "Elemento no existe" << endl;

	arr.imprime();

	cout << "Busca elemento: ";
	cin >> nuevo;
	res = arr.buscar(nuevo);
	if(res >= 0)
		cout << "Elemento encontrado en posicion: " << res << endl;
	else
		cout << "Elemento no encontrado" << endl;

}

int main() 
{
	usaArregloEnteros();
	return 0;
}

