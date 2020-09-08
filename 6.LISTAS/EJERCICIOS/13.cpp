/*
13.	Retome los métodos de eliminación de nodos de una lista simplemente 
ligada (que se explicaron anteriormente) y modifíquelos de tal manera que 
regresen la dirección del nodo eliminado.
*/

#include <iostream>

template <class T>
class ListaSimLigada;

template <class T>
class NodoLista
{
private:
	T info;
	NodoLista<T>* siguiente;
public:
	NodoLista();
	T regresaInfo();
	friend class ListaSimLigada<T>;
};

template <class T>
class ListaSimLigada 
{
private:
	NodoLista<T>* primero;
	NodoLista<T>* ultimo;
public:
	ListaSimLigada();
	~ListaSimLigada();
	void imprimir();
	void insertaFinal(T);
	NodoLista<T>& eliminaPrimero();
	NodoLista<T>& eliminaUltimo();
	NodoLista<T>& elimina(T);
	NodoLista<T>* busca(T);
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
ListaSimLigada<T>::ListaSimLigada()
{
	primero = NULL;
	ultimo = NULL;
}

template <class T>
ListaSimLigada<T>::~ListaSimLigada()
{
	NodoLista<T>* aux;
	while(primero) {
		aux = primero;
		primero = primero->siguiente;
		delete aux;
	}
}

template <class T>
void ListaSimLigada<T>::imprimir()
{
	NodoLista<T>* aux = primero;
	
	while(aux) {
		std::cout << aux->info << " -> ";
		aux = aux->siguiente;
	}
}

template <class T>
void ListaSimLigada<T>::insertaFinal(T dato)
{
	NodoLista<T>* nuevoNodo = new NodoLista<T>();
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

// 0: No se pudo eliminar (lista vacia)
// 1: Eliminado
template <class T>
NodoLista<T>& ListaSimLigada<T>::eliminaPrimero()
{
	NodoLista<T>* aux;
	if(primero){
		if(primero == ultimo) {
			delete primero;
			primero = NULL;
			ultimo = NULL;
		} else {
			aux = primero;
			primero = primero->siguiente;
			delete aux;
		}
	} else {
		aux = NULL;
	}
	return (*aux);
}

template <class T>
NodoLista<T>& ListaSimLigada<T>::eliminaUltimo()
{
	NodoLista<T>* aux, *antes;
	
	if(primero) {
		if(!primero->siguiente) {
			delete primero;
			primero = NULL;
			ultimo = NULL;
		} else {
			aux = primero;
			while(aux->siguiente) {
				antes = aux;
				aux = aux->siguiente;
			}
			antes->siguiente = NULL;
			ultimo = antes;
			delete aux;
		}
	} else {
		aux = NULL;
	}
	
	return (*aux);
}

/*
-1: Listavacia
 0: No se encontro el dato
 1: Eliminado
*/
template <class T>
NodoLista<T>& ListaSimLigada<T>::elimina(T dato)
{
	NodoLista<T>* aux, *antes;

	if(primero) {
		aux = primero;
		
		if(primero->info == dato) {
			if(primero == ultimo) {
				ultimo = NULL;
			}
			primero = primero->siguiente;
			delete aux;
		} else {
			while(aux != NULL && aux->info != dato) {
				antes = aux;
				aux = aux->siguiente;
			}
			
			if(aux != NULL) {
				if(ultimo->info == dato) {
					ultimo = antes;
				}
				antes->siguiente = aux->siguiente;
				delete aux;
			} else {
				aux = NULL;
			}
		}
		
	} else {
		aux = NULL;
	}
	
	return (*aux);
}

template <class T>
NodoLista<T>* ListaSimLigada<T>::busca(T dato)
{
	NodoLista<T>* elemento;
	if(primero) {
		elemento = primero;
		while(elemento != NULL && elemento->info != dato) {
			elemento = elemento->siguiente;
		}
	} else {
		elemento = NULL;
	}
	
	return elemento;
}

int main()
{
	ListaSimLigada<int> l = ListaSimLigada<int>();
	l.insertaFinal(12);
	l.insertaFinal(9);
	l.insertaFinal(5);
	NodoLista<int>* a = &l.eliminaUltimo();
	std::cout << "Nodo eliminado final (mem): " << &(*a) << std::endl;
	a = &l.eliminaPrimero();
	std::cout << "Nodo eliminado primero (mem): " << &(*a) << std::endl;
	a = &l.elimina(9);
	std::cout << "Nodo eliminado 9 (mem): " << &(*a) << std::endl;
	return 0;
}