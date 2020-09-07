/*
7.	Defina la clase ListaCircularSimple correspondiente a una 
estructura tipo lista circular simplemente ligada. No utilice 
nodo de cabecera. Por lo menos, los métodos que debe incluir 
en la clase son: 
insertaOrdenada() (este método debe ir insertando ordenadamente 
elementos a la lista),
EiiminaNodo() (este método debe poder eliminar un elemento dado 
como referencia si estuviera en la lista),
imprimeLista() (este método imprime todos los elementos de la lista), 
BuscaNodo() (este método busca en la lista un valor dado como referencia). 
En todos los métodos debe considerar posibles casos de fracaso. 
Utilice plantillas para su definición.
*/
#include <iostream>

template <class T>
class ListaCircularSimple;

template <class T>
class NodoLista
{
private:
	T info;
	NodoLista<T>* siguiente;
public:
	NodoLista();
	T regresaInfo();
	friend class ListaCircularSimple<T>;
};

template <class T>
class ListaCircularSimple
{
private:
	NodoLista<T>* ultimo;
public:
	ListaCircularSimple();
	int insertaOrdenada(T);
	int eliminaNodo(T);
	void imprimeLista();
	NodoLista<T>* buscaNodo(T);
};

template <class T>
NodoLista<T>::NodoLista()
{
	siguiente = NULL;
}

template<class T>
T NodoLista<T>::regresaInfo()
{
	return info;
}

template <class T>
ListaCircularSimple<T>::ListaCircularSimple()
{
	ultimo = NULL;
}

template <class T>
int ListaCircularSimple<T>::insertaOrdenada(T dato)
{
	int resp = 1;
	NodoLista<T> *nuevo, *aux, *antes;
	nuevo = new NodoLista<T>();
	nuevo->info = dato;
	if(ultimo) {
		aux = ultimo->siguiente;
		if(ultimo == aux) {
			// Solo hay un elemento
			nuevo->siguiente = ultimo;
			ultimo->siguiente = nuevo;
			if(dato >= ultimo->info){
				// Actualizar ultimo
				ultimo = nuevo;
			}
		} else {
			if(dato >= ultimo->info) {
				// Se agrega el nuevo al final
				nuevo->siguiente = ultimo->siguiente;
				ultimo->siguiente = nuevo;
				ultimo = nuevo;
			} else {
				// Buscamos donde va
				antes = ultimo;
				while(aux != ultimo && dato > aux->info) {
					antes = aux;
					aux = aux->siguiente;
				}
				nuevo->siguiente = aux;
				antes->siguiente = nuevo;
			}
		}
	} else {
		nuevo->siguiente = nuevo;
		ultimo = nuevo;
	}
	return resp;
}

/*
-1: Lista vacia
 0: No se encontró
 1: Eliminado
*/
template <class T>
int ListaCircularSimple<T>::eliminaNodo(T dato)
{
	int resp = 1;
	NodoLista<T> *aux, *antes;
	if(ultimo) {
		if(ultimo == ultimo->siguiente) {
			// Solo hay uno
			if(ultimo->info == dato){
				aux = ultimo;
				ultimo = NULL;
				delete aux;
			} else {
				resp = 0;
			}
		} else {
			antes = ultimo;
			aux = ultimo->siguiente;
			while(aux != ultimo && aux->info != dato) {
				antes = aux;
				aux = aux->siguiente;
			}
			if(aux == ultimo) {
				if(ultimo->info == dato) {
					// Eliminar el último y actualizar ultimo
					antes->siguiente = aux->siguiente;
					ultimo = antes;
					delete aux;
				} else {
					resp = 0;
				}
			} else {
				// No es el ultimo eliminar el nodo
				antes->siguiente = aux->siguiente;
				delete aux;
			}
		}
	} else {
		resp = -1;
	}
	return resp;
}

template <class T>
void ListaCircularSimple<T>::imprimeLista()
{
	NodoLista<T>* aux;
	if(ultimo) {
		aux = ultimo->siguiente;
		if(aux == ultimo) {
			std::cout << aux->info << " -> primero" << std::endl;
		} else {
			while(aux != ultimo) {
				std::cout << aux->info << " -> ";
				aux = aux->siguiente;
			}
			std::cout << aux->info << " -> primero" << std::endl;
		}
	} else {
		std::cout << "Vacia" << std::endl;
	}
}

template <class T>
NodoLista<T>* ListaCircularSimple<T>::buscaNodo(T dato)
{
	NodoLista<T>* aux;
	if(ultimo) {
		aux = ultimo->siguiente;
		if(aux == ultimo) {
			if(aux->info != dato) {
				aux = NULL;
			}
		} else if (ultimo->info == dato) {
			aux = ultimo;
		} else {
			while(aux != ultimo && aux->info != dato) {
				aux = aux->siguiente;
			}
			if(aux == ultimo) {
				aux = NULL;
			}
		}
	} else {
		aux = NULL;
	}
	return aux;
}

int main()
{
	ListaCircularSimple<int> l = ListaCircularSimple<int>();
	l.imprimeLista();
	
	l.insertaOrdenada(2);
	l.insertaOrdenada(6);
	l.insertaOrdenada(-2);
	l.insertaOrdenada(7);
	l.insertaOrdenada(-9);
	l.insertaOrdenada(6);
	l.insertaOrdenada(8);
	l.eliminaNodo(2);
	l.imprimeLista();
	
	l.insertaOrdenada(9);
	l.imprimeLista();
	
	std::cout << "Busca 9: " << ((l.buscaNodo(9)) ? "Encontrado": "No encontrado") << std::endl;
	std::cout << "Busca 2: " << ((l.buscaNodo(2)) ? "Encontrado": "No encontrado") << std::endl;
	
	return 0;
}