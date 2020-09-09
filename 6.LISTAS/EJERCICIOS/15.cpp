/*
15.	Defina la clase ListaCircularDoble correspondiente a una estructura 
tipo lista circular doblemente ligada. No utilice nodo de cabecera. Los 
métodos que, por lo menos, debe incluir en la clase son:
insertaOrdenada() (este método debe ir insertando ordenadamente elementos a la lista),
EliminaNodo () (este método debe poder eliminar un elemento dado como referencia si 
estuviera en la lista),
imprimeLista() (este método imprime todos los elementos de la lista),
imprimeNodo() (este método imprime la información de un nodo de la lista, 
cuya dirección se da como parámetro),
BuscaNodo () (este método busca en la lista un valor dado como referencia, si 
lo encuentra regresa la dirección del nodo y si no el valor NULL).
En todos los métodos debe considerar posibles casos de fracaso. Utilice plantillas
para su definición.
*/
#include <iostream>

template <class T>
class ListaCircularDoble;

template <class T>
class NodoListaCirDob
{
private:
    T info;
    NodoListaCirDob<T>* siguiente;
    NodoListaCirDob<T>* anterior;
public:
    NodoListaCirDob();
    T* regresaInfo();
    friend class ListaCircularDoble<T>;
};
/*
Clase ListaCircularDoble. Requiere que se sobreescriban
los operadores ==, < y != del tipo de dato T
*/
template <class T>
class ListaCircularDoble
{
private:
    NodoListaCirDob<T>* menor;
public:
    ListaCircularDoble();
    void insertaOrdenada(T);
    int eliminaNodo(T);
    void imprimeLista();
    void imprimeNodo(NodoListaCirDob<T>*);
    NodoListaCirDob<T>* buscaNodo(T);
};

/*
Constructor vacio de NodoListaCirDob
*/
template <class T>
NodoListaCirDob<T>::NodoListaCirDob()
{
    siguiente = NULL;
    anterior = NULL;
}

/*
Metodo que regresa un puntero al valor de info
*/
template <class T>
T* NodoListaCirDob<T>::regresaInfo()
{
    return &info;
}

/*
Constructor vacio de ListaCircularDoble
*/
template <class T>
ListaCircularDoble<T>::ListaCircularDoble()
{
    menor = NULL;
}

/*
Metodo que inserta de manera ordenada un elemento
*/
template <class T>
void ListaCircularDoble<T>::insertaOrdenada(T dato)
{
    NodoListaCirDob<T>* actual, *nuevo;
	nuevo = new NodoListaCirDob<T>();
	nuevo->info = dato;
    if(menor) {

        if(menor == menor->siguiente) {
            // Solo existe un elemento
			nuevo->siguiente = menor;
			nuevo->anterior = menor;
			menor->siguiente = nuevo;
			menor->anterior = nuevo;
			if(dato < menor->info) {
				menor = nuevo;
			}
        } else {
            // Hay mas de un elemento
			
			if(menor->anterior->info < dato || 
			   menor->anterior->info == dato) {
				// Si el dato es mayor o igual al ultimo
				nuevo->siguiente = menor;
				nuevo->anterior = menor->anterior;
				menor->anterior->siguiente = nuevo;
				menor->anterior = nuevo;
			} else {
				actual = menor;
				// Dato se agregara antes de actual
				while(actual != menor->anterior && actual->info < dato) {
					actual = actual->siguiente;
				}
				
				nuevo->siguiente = actual;
				nuevo->anterior = actual->anterior;
				actual->anterior->siguiente = nuevo;
				actual->anterior = nuevo;
				if(actual == menor) {
					// en caso el dato nuevo sea menor ahora 
					menor = nuevo;
				}
				
			}
			
        }

    } else {
		// No hay ningun elemento
		nuevo->siguiente = nuevo;
		nuevo->anterior = nuevo;
		menor = nuevo;
	}
}

/*
Metodo que elimina un nodo
-1: Lista vacia
 0: No se encontró el nodo
 1: Se elimino el nodo
*/
template <class T>
int ListaCircularDoble<T>::eliminaNodo(T dato)
{
    int resp = 1;
	NodoListaCirDob<T>* aux;
    if(menor) {
		if(dato < menor->info || menor->anterior->info < dato) {
			resp = 0;
		} else {
			if(menor->anterior->info == dato) {
				aux = menor->anterior;
				aux->anterior->siguiente = menor;
				menor->anterior = aux->anterior;
				delete aux;
			} else {
				aux = menor;
				
				while(aux != menor->anterior && aux->info != dato) {
					aux = aux->siguiente;
				}
				
				if(aux != menor->anterior) {
					aux->anterior->siguiente = aux->siguiente;
					aux->siguiente->anterior = aux->anterior;
					
					if(aux == menor) {
						menor = aux->siguiente;
					}
					delete aux;
				}
				
			}
		}
    } else {
        // Lista vacia
        resp = -1;
    }
    return resp;
}

/*
Metodo que imprime la lista circular doblemente ligada
*/
template <class T>
void ListaCircularDoble<T>::imprimeLista()
{
    if(menor) {
        NodoListaCirDob<T>* aux = menor;

        while(aux != menor->anterior) {
            std::cout << aux->info << " <-> ";
			aux = aux->siguiente;
        }

        if(aux == menor->anterior) {
            std::cout << aux->info << " <-> primero" << std::endl;
        }
    } else {
        std::cout << "Lista vacia" << std::endl;
    }
}

/*
Metodo que imprime la informacion de un nodo
*/
template <class T>
void ListaCircularDoble<T>::imprimeNodo(NodoListaCirDob<T> *nodo)
{
    if(nodo) {
        std::cout << nodo->info << std::endl;
    }
}

/*
Metodo que busca y devuelve un puntero a un nodo a 
partir del dato que contiene
*/
template <class T>
NodoListaCirDob<T>* ListaCircularDoble<T>::buscaNodo(T dato)
{
    NodoListaCirDob<T>* buscado = NULL, *aux;

    if(menor) {
        aux = menor;
        while(aux != menor->anterior) {
            if(aux->info == dato) {
                buscado = aux;
                break;
            }
            aux = aux->siguiente;
        }

        if(aux == menor->anterior) {
            if(aux->info == dato) {
                buscado = aux;
            }
        }
    }

    return buscado;
}

void testEjercicio15()
{
	ListaCircularDoble<int> l = ListaCircularDoble<int>();
	
	l.insertaOrdenada(9);
	l.insertaOrdenada(2);
	l.insertaOrdenada(0);
	l.insertaOrdenada(5);
	l.insertaOrdenada(6);
	l.insertaOrdenada(11);
	l.insertaOrdenada(-3);
	l.insertaOrdenada(-2);
	l.imprimeLista();
	
	l.eliminaNodo(1);
	l.eliminaNodo(-3);
	l.eliminaNodo(0);
	l.eliminaNodo(11);
	l.imprimeLista();
	
	std::cout << "Busca 5: " << ((l.buscaNodo(5)) ? "Encontrado" : "No encontrado") << std::endl;
	std::cout << "Busca 0: " << ((l.buscaNodo(0)) ? "Encontrado" : "No encontrado") << std::endl;
}