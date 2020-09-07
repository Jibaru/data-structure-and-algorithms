/*
6.	Escriba un programa que, dada una lista simplemente ligada de 
números enteros ordenados crecientemente, agregue tantos nodos 
como sea necesario de manera que la lista quede formada con los 
nodos requeridos para que contengan todos los números comprendidos 
entre el valor del primer nodo y el valor del último. Por ejemplo, 
si la lista dada por el usuario es la que aparece en la parte a) 
de la siguiente figura, luego de ejecutarse el programa planteado, 
la lista debería quedar como lo muestra la parte b).

a) Primero->3->5->8->9->NULL
b) Primero->3->4->5->6->7->8->9->NULL
*/

#include <iostream>

class ListaSimLigada;

class NodoLista
{
private:
	int info;
	NodoLista* siguiente;
public:
	NodoLista();
	int regresaInfo();
	friend class ListaSimLigada;
};

class ListaSimLigada 
{
private:
	NodoLista* primero;
	NodoLista* ultimo;
public:
	ListaSimLigada();
	~ListaSimLigada();
	void imprimir();
	void insertaFinal(int);
	int tamanio();
	int vacia();
	void rellenaFaltantesOrdenada();
};

NodoLista::NodoLista()
{
	siguiente = NULL;
}

int NodoLista::regresaInfo()
{
	return info;
}

ListaSimLigada::ListaSimLigada()
{
	primero = NULL;
	ultimo = NULL;
}

ListaSimLigada::~ListaSimLigada()
{
	NodoLista* aux;
	while(primero) {
		aux = primero;
		primero = primero->siguiente;
		delete aux;
	}
}

void ListaSimLigada::imprimir()
{
	NodoLista* aux = primero;
	
	while(aux) {
		std::cout << aux->info << " -> ";
		aux = aux->siguiente;
	}
}

void ListaSimLigada::insertaFinal(int dato)
{
	NodoLista* nuevoNodo = new NodoLista();
	if(nuevoNodo == NULL) {
		std::cout << "SIN MEM" << std::endl;
	}
	nuevoNodo->info = dato;
	if(primero == NULL && ultimo == NULL){
		primero = nuevoNodo;
		ultimo = nuevoNodo;
	} else {
		ultimo->siguiente = nuevoNodo;
		ultimo = nuevoNodo;
	}
}

int ListaSimLigada::tamanio()
{
	int cont = 0;
	NodoLista* aux = primero;
	if(primero) {
		while(aux != NULL) {
			cont++;
			aux = aux->siguiente;
		}
	}

	return cont;
}

int ListaSimLigada::vacia()
{
	if(primero == NULL && ultimo == NULL) {
		return 1;
	}
	return 0;
}

void ListaSimLigada::rellenaFaltantesOrdenada()
{
	NodoLista* actual,*nuevo;
	actual = primero;
	while(actual) {
		if(actual != ultimo) {
			if(actual->info != actual->siguiente->info - 1) {
				nuevo = new NodoLista();
				nuevo->info = actual->info + 1;
				nuevo->siguiente = actual->siguiente;
				actual->siguiente = nuevo;
			}
		}
		actual = actual->siguiente;
	}
}

int main()
{
	ListaSimLigada lista = ListaSimLigada();
	lista.insertaFinal(3);
	lista.insertaFinal(5);
	lista.insertaFinal(8);
	lista.insertaFinal(9);
	
	std::cout << "\nLista: ";
	lista.imprimir();
	
	lista.rellenaFaltantesOrdenada();
	
	std::cout << "\nLista completa: ";
	lista.imprimir();
	
	return 0;
}