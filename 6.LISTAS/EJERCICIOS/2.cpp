/*
2.	Escriba un programa en C++ que:
a)	Use la plantilla del ejercicio anterior para declarar un objeto 
tipo lista simplemente ligada de números enteros.
b)	Genere una lista con al menos 10 nodos que contengan 10 números 
enteros distintos entre sí.
c)	Encuentre el mayor de los valores almacenados en la lista y lo 
elimine (también debe quitar el nodo en el cual está almacenado). 
Este proceso se debe repetir hasta que la lista quede vacía.
*/
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "1.cpp"

using namespace std;

int generaAleatorio()
{
	return (1 + rand() % (101 - 1));
}

void llenaLista(ListaSimLigada<int>& lista)
{
	srand(time(NULL));
	int temp = generaAleatorio();
	for(int i = 0; i < 10; i++) {
		while(lista.busca(temp)) {
			temp = generaAleatorio();
		}
		lista.insertaFinal(temp);
	}
}

template <class T>
void eliminaListaPorMayores(ListaSimLigada<T>& lista)
{
	NodoLista<T>* mayor;
	int i = 10;
	while(!lista.vacia()) {
		mayor = lista.mayor();
		if(mayor) {
			cout << "Mayor: " << mayor->regresaInfo() << endl;
			lista.elimina(mayor->regresaInfo());
			cout << "Lista Actual: ";
			lista.imprimir();
			cout << endl;
		}
	}
}

int main()
{
	ListaSimLigada<int> lista = ListaSimLigada<int>();
	
	llenaLista(lista);
	lista.imprimir();
	
	eliminaListaPorMayores(lista);
	
	return 0;
}