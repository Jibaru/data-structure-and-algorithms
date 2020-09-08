/*
11.	Defina una lista que pueda almacenar, en cada nodo, un 
par (X, Y) de números reales. Haga los cambios en las clases 
que crea conveniente.
*/
#include <iostream>

class ListaSimLigadaPares;

class NodoListaPares
{
private:
	float x;
    float y;
	NodoListaPares* siguiente;
public:
	NodoListaPares();
	float regresaX();
    float regresaY();
	friend class ListaSimLigadaPares;
};

class ListaSimLigadaPares 
{
private:
	NodoListaPares* primero;
	NodoListaPares* ultimo;
public:
	ListaSimLigadaPares();
	~ListaSimLigadaPares();
	NodoListaPares* regresaPrimero();
	NodoListaPares* regresaUltimo();
	void imprimir();
	void imprimirNodo(NodoListaPares*);
	void insertaInicio(float, float);
	void insertaFinal(float, float);
	int elimina(float, float);
	NodoListaPares* busca(float, float);
};

NodoListaPares::NodoListaPares()
{
	siguiente = NULL;
}

float NodoListaPares::regresaX()
{
	return x;
}

float NodoListaPares::regresaY()
{
    return y;
}

ListaSimLigadaPares::ListaSimLigadaPares()
{
	primero = NULL;
	ultimo = NULL;
}

ListaSimLigadaPares::~ListaSimLigadaPares()
{
	NodoListaPares* aux;
	while(primero) {
		aux = primero;
		primero = primero->siguiente;
		delete aux;
	}
}

NodoListaPares* ListaSimLigadaPares::regresaPrimero()
{
	return primero;
}

NodoListaPares* ListaSimLigadaPares::regresaUltimo()
{
	return ultimo;
}

void ListaSimLigadaPares::imprimir()
{
	NodoListaPares* aux = primero;
	
	while(aux) {
		std::cout << "(" << aux->x << ", " << aux->y << ") -> ";
		aux = aux->siguiente;
	}
    std::cout << std::endl;
}

void ListaSimLigadaPares::imprimirNodo(NodoListaPares* nodo)
{
	std::cout << "(" << nodo->x << ", " << nodo->y << ")" << std::endl;
}

void ListaSimLigadaPares::insertaInicio(float x, float y)
{
	NodoListaPares* nuevoNodo = new NodoListaPares();
	nuevoNodo->x = x;
    nuevoNodo->y = y;
	nuevoNodo->siguiente = primero;
	if(!primero && !ultimo){
		primero = nuevoNodo;
		ultimo = nuevoNodo;
	} else {
		primero = nuevoNodo;
	}
}

void ListaSimLigadaPares::insertaFinal(float x, float y)
{
	NodoListaPares* nuevoNodo = new NodoListaPares();
	if(nuevoNodo != NULL) {
		nuevoNodo->x = x;
        nuevoNodo->y = y;
        if(primero == NULL && ultimo == NULL){
            primero = nuevoNodo;
            ultimo = nuevoNodo;
        } else {
            ultimo->siguiente = nuevoNodo;
            ultimo = nuevoNodo;
        }
	} else {
        std::cout << "SIN MEM" << std::endl;
    }
	
}

/*
-1: Listavacia
 0: No se encontro el dato
 1: Eliminado
*/
int ListaSimLigadaPares::elimina(float x, float y)
{
	NodoListaPares* aux, *antes;
	int resp = 1;
	if(primero) {
		aux = primero;
		
		if(primero->x == x && primero->y == y) {
			if(primero == ultimo) {
				ultimo = NULL;
			}
			primero = primero->siguiente;
			delete aux;
		} else {
			while(aux != NULL && (aux->x != x && aux->y != y)) {
				antes = aux;
				aux = aux->siguiente;
			}
			
			if(aux != NULL) {
				if(ultimo->x == x && ultimo->y == y) {
					ultimo = antes;
				}
				antes->siguiente = aux->siguiente;
				delete aux;
			} else {
				resp = 0;
			}
		}
		
	} else {
		resp = -1;
	}
	
	return resp;
}

NodoListaPares* ListaSimLigadaPares::busca(float x, float y)
{
	NodoListaPares* elemento;
	if(primero) {
		elemento = primero;
		while(elemento != NULL && (elemento->x != x && elemento->y != y)) {
			elemento = elemento->siguiente;
		}
	} else {
		elemento = NULL;
	}
	
	return elemento;
}

void testEjercicio11()
{
    ListaSimLigadaPares l = ListaSimLigadaPares();

    l.insertaFinal(12, 2);
    l.insertaFinal(5, 4);
    l.insertaFinal(11, 3);
    l.imprimir();

    l.elimina(2, 5);
    l.elimina(5, 4);
    l.imprimir();
}