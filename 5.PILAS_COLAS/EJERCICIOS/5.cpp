/*
Defina la clase Cola y utilice sobrecarga de operadores en los métodos 
necesarios para implementar las operaciones asociadas a este tipo de 
estructura. Se sugiere usar la suma aritmética (+) para la inserción 
y la resta aritmética (-) para la eliminación
*/
#include <iostream>
using namespace std;
#define MAX 60

template <class T>
class Cola {
private:
	T elementos[MAX];
	int frente, final;
public:
	Cola();
	int push(T);
	void pop(T*);
	bool estaLlena();
	bool estaVacia();
	int operator +(T);
    void operator -(T*);
	void imprimeDatos();
};

template <class T>
Cola<T>::Cola()
{
	frente = -1;
	final = -1;
}

template <class T>
int Cola<T>::push(T dato)
{
	if(final + 1 < MAX) {
		elementos[final++] = dato;
		if(final == 0) {
			frente = final;
		}
		return 1;
	}
	return 0;
}

template <class T>
void Cola<T>::pop(T* dato)
{
	*dato = elementos[frente];
	if(frente == final) {
		frente = -1;
		final = -1;
	} else {
		frente++;
	}

}

template <class T>
bool Cola<T>::estaLlena()
{
	if(frente == final) {
		return false;
	}
	return true;
}

template <class T>
bool Cola<T>::estaVacia()
{
	return !estaLlena();
}

template <class T>
int Cola<T>::operator+(T dato)
{
	return push(dato);
}

template <class T>
void Cola<T>::operator-(T* dato)
{
	pop(dato);
}

template <class T>
void Cola<T>::imprimeDatos()
{
	for(int i = frente - 1; i < final; i++) {
		cout << "<-" << elementos[i];
	}
}

void usaCola()
{
	Cola<int> cola = Cola<int>();
	int eliminado;
	
	cola.push(9);
	cola.push(10);
	cola + 15;
	cola + 2;
	
	cola.pop(&eliminado);
	
	cola.imprimeDatos();
}

int main()
{
	usaCola();
	return 0;
}