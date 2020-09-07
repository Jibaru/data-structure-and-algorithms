/*
9.	Implemente la estructura cola con una lista simplemente ligada. 
Utilice la plantilla de la clase definida en el ejercicio 1 para 
definir una plantilla para la clase cola.
*/
#include <iostream>

template <class T>
class ColaLigada;

template <class T>
class NodoCola
{
private:
	T info;
	NodoCola<T>* siguiente;
public:
	NodoCola();
	T regresaInfo();
	friend class ColaLigada<T>;
};

template <class T>
class ColaLigada 
{
private:
	NodoCola<T>* primero;
	NodoCola<T>* ultimo;
public:
	ColaLigada();
	~ColaLigada();
	NodoCola<T>* regresaPrimero();
	NodoCola<T>* regresaUltimo();
    NodoCola<T>* busca(T);
	void imprimir();
	void push(T);
	int pop();
	int tamanio();
	int vacia();
	void invertir();
};

/* 
Constructor vacio de NodoCola.
Inicializa siguiente en NULL
*/
template <class T>
NodoCola<T>::NodoCola()
{
	siguiente = NULL;
}

/*
Regresa la informacion almacenada en el nodo
*/
template<class T>
T NodoCola<T>::regresaInfo()
{
	return info;
}

/*
Constructor de ColaLigada.
Inicializa el primer y ultimo nodo en NULL
*/
template <class T>
ColaLigada<T>::ColaLigada()
{
	primero = NULL;
	ultimo = NULL;
}

/*
Destructor de ColaLigada.
Elimina todos los elementos creados con memoria dinamica
*/
template <class T>
ColaLigada<T>::~ColaLigada()
{
	NodoCola<T>* aux;
	while(primero) {
		aux = primero;
		primero = primero->siguiente;
		delete aux;
	}
}

/*
Regresa el primer nodo de la cola
*/
template <class T>
NodoCola<T>* ColaLigada<T>::regresaPrimero()
{
	return primero;
}

/*
Regresa el ultimo nodo de la cola
*/
template <class T>
NodoCola<T>* ColaLigada<T>::regresaUltimo()
{
	return ultimo;
}

/*
Imprime todos los elementos de la cola
*/
template <class T>
void ColaLigada<T>::imprimir()
{
	NodoCola<T>* aux = primero;
	
	while(aux) {
		std::cout << " <- " << aux->info;
		aux = aux->siguiente;
	}
    std::cout << std::endl;
}

/*
Ingresa un nuevo elemento a la cola
*/
template <class T>
void ColaLigada<T>::push(T dato)
{
	NodoCola<T>* nuevoNodo = new NodoCola<T>();
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

// 0: No se pudo eliminar (cola vacia)
// 1: Eliminado
template <class T>
int ColaLigada<T>::pop()
{
	int resp = 1;
	if(primero){
		if(primero == ultimo) {
			delete primero;
			primero = NULL;
			ultimo = NULL;
		} else {
			NodoCola<T>* aux = primero;
			primero = primero->siguiente;
			delete aux;
		}
	} else {
		resp = 0;
	}
	return resp;
}

/*
Devuelve el tamanio de la cola
*/
template <class T>
int ColaLigada<T>::tamanio()
{
	int cont = 0;
	NodoCola<T>* aux = primero;
	if(primero) {
		while(aux != NULL) {
			cont++;
			aux = aux->siguiente;
		}
	}

	return cont;
}

/*
1: Cola vacia
0: Cola con elementos
*/
template <class T>
int ColaLigada<T>::vacia()
{
	if(primero == NULL && ultimo == NULL) {
		return 1;
	}
	return 0;
}

/*
Devuelve el nodo a buscar. Sera NULL si no lo encuentra
*/
template <class T>
NodoCola<T>* ColaLigada<T>::busca(T dato)
{
	NodoCola<T>* elemento;
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

/*
Invierte los elementos de la cola
*/
template <class T>
void ColaLigada<T>::invertir()
{
	if(primero != ultimo) {
		NodoCola<T>* actual, *anterior, *despues;
		if(primero->siguiente == ultimo) {
			// solo dos elementos
			ultimo->siguiente = primero;
			primero->siguiente = NULL;
		} else {
			anterior = NULL;
			actual = primero;
			despues = primero->siguiente;

			while(actual) {
				actual->siguiente = anterior;
				anterior = actual;
				actual = despues;
				if(actual){
					despues = actual->siguiente;
				}
			}
		}
		actual = primero;
		primero = ultimo;
		ultimo = actual;
	}
}

void testEjercicio9()
{
    ColaLigada<int> c = ColaLigada<int>();

    c.imprimir();
    c.push(6);
    c.push(7);
    c.push(100);
    c.push(8);
    c.push(65);
    c.push(19);
    c.push(11);

    c.imprimir();

    c.pop();
    c.pop();

    c.imprimir();

    std::cout << "Busca 65: " << ((c.busca(65)) ? "ENCONTRADO" : "NO ENCONTRADO") << std::endl;
    std::cout << "Busca 7: " << ((c.busca(7)) ? "ENCONTRADO" : "NO ENCONTRADO") << std::endl;
    std::cout << "Estado: " << ((c.vacia()) ? "Vacia" : "No vacia") << std::endl;
    std::cout << "Tamanio: " << c.tamanio() << std::endl;

}