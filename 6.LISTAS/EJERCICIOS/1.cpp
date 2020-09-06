/*
1.	Defina una plantilla para la clase ListaSimLigada. Decida qué atributos 
y métodos incluir. Se sugiere que declare un apuntador al primero y otro 
al último nodo de la lista.
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
	NodoLista<T>* regresaPrimero();
	NodoLista<T>* regresaUltimo();
	void imprimir();
	void imprimirNodo(NodoLista<T>*);
	void insertaInicio(T);
	void insertaFinal(T);
	int insertaAntes(T, T);
	int insertaDespues(T, T);
	int eliminaPrimero();
	int eliminaUltimo();
	int elimina(T);
	NodoLista<T>* busca(T);
	int tamanio();
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
NodoLista<T>* ListaSimLigada<T>::regresaPrimero()
{
	return primero;
}

template <class T>
NodoLista<T>* ListaSimLigada<T>::regresaUltimo()
{
	return ultimo;
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
void ListaSimLigada<T>::imprimirNodo(NodoLista<T>* nodo)
{
	std::cout << nodo->info << std::endl;
}

template <class T>
void ListaSimLigada<T>::insertaInicio(T dato)
{
	NodoLista<T>* nuevoNodo = new NodoLista<T>();
	nuevoNodo->info = dato;
	nuevoNodo->siguiente = primero;
	if(!primero && !ultimo){
		primero = nuevoNodo;
		ultimo = nuevoNodo;
	} else {
		primero = nuevoNodo;
	}
}

template <class T>
void ListaSimLigada<T>::insertaFinal(T dato)
{
	NodoLista<T>* nuevoNodo = new NodoLista<T>();
	nuevoNodo->info = dato;
	if(primero == NULL && ultimo == NULL){
		primero = nuevoNodo;
		ultimo = nuevoNodo;
	} else {
		ultimo->siguiente = nuevoNodo;
		ultimo = nuevoNodo;
	}
}

/*
 1: Se inserta
-1: Lista vacia
 0: No se encontró la ref
*/
template <class T>
int ListaSimLigada<T>::insertaAntes(T dato, T ref)
{
	int resp = 1;
	NodoLista<T>* antes, *aux, *nuevoNodo;
	if(primero) {
		aux = primero;
		while(aux && aux->info != ref)
		{
			antes = aux;
			aux = aux->siguiente;
		}
		
		if(aux) {
			nuevoNodo = new NodoLista<T>();
			nuevoNodo->info = dato;
			
			if(primero == aux) {
				nuevoNodo->siguiente = primero;
				primero = nuevoNodo;
			} else {
				nuevoNodo->siguiente = aux;
				antes->siguiente = nuevoNodo;
			}
		} else {
			resp = 0;
		}
	} else {
		resp = -1;
	}
	
	return resp;
}

/*
 1: Se inserta
-1: Lista vacia
 0: No se encontró la ref
*/
template <class T>
int ListaSimLigada<T>::insertaDespues(T dato, T ref)
{
	int resp = 1;
	NodoLista<T>* aux, *nuevoNodo;
	
	if(primero) {
		
		aux = primero;
		while(aux && aux->info != ref) {
			aux = aux->siguiente;
		}
		
		if(aux) {
			nuevoNodo = new NodoLista<T>();
			nuevoNodo->info = dato;
			if(ultimo == aux) {
				ultimo->siguiente = nuevoNodo;
				ultimo = nuevoNodo;
			} else {
				nuevoNodo->siguiente = aux->siguiente;
				aux->siguiente = nuevoNodo;
			}
		} else {
			resp = 0;
		}
		
	} else {
		resp = -1;
	}
	return resp;
}

// 0: No se pudo eliminar (lista vacia)
// 1: Eliminado
template <class T>
int ListaSimLigada<T>::eliminaPrimero()
{
	int resp = 1;
	if(primero){
		if(primero == ultimo) {
			delete primero;
			primero = NULL;
			ultimo = NULL;
		} else {
			NodoLista<T>* aux = primero;
			primero = primero->siguiente;
			delete aux;
		}
	} else {
		resp = 0;
	}
	return resp;
}

template <class T>
int ListaSimLigada<T>::eliminaUltimo()
{
	NodoLista<T>* aux, *antes;
	int resp = 1;
	
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
		resp = 0;
	}
	
	return resp;
}

/*
-1: Listavacia
 0: No se encontro el dato
 1: Eliminado
*/
template <class T>
int ListaSimLigada<T>::elimina(T dato)
{
	NodoLista<T>* aux, *antes;
	int resp = 1;
	if(primero) {
		aux = primero;
		while(aux != NULL && aux->info != dato) {
			antes = aux;
			aux = aux->siguiente;
		}
		
		if(aux != NULL) {
			antes->siguiente = aux->siguiente;
			delete aux;
		} else {
			resp = 0;
		}
	} else {
		resp = -1;
	}
	
	return resp;
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

template <class T>
int ListaSimLigada<T>::tamanio()
{
	int cont = 0;
	NodoLista<T>* aux = primero;
	if(primero) {
		while(aux != NULL) {
			cont++;
			aux = aux->siguiente;
		}
	}

	return cont;
}

void testEjercicio1()
{
	ListaSimLigada<int> l = ListaSimLigada<int>();
	l.insertaFinal(9);
	l.insertaInicio(11);
	l.insertaFinal(3);
	l.insertaFinal(54);
	l.imprimir();
	std::cout << std::endl;
	l.insertaAntes(2, 9); 
	l.insertaDespues(76, 2);
	l.imprimir();
	std::cout << std::endl;
	l.eliminaPrimero();
	l.eliminaUltimo();
	l.elimina(76);
	l.imprimir();
	
	std::cout << "\nTam: " << l.tamanio() << std::endl;
	std::cout << "Busca 19: " << ((l.busca(19)) ? "Encontrado": "No encontrado") << std::endl;
	std::cout << "Busca 2: " << ((l.busca(2)) ? "Encontrado": "No encontrado") << std::endl;

}