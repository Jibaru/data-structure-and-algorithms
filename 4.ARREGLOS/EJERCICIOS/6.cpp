/*
6.	Defina la clase Arreglo usando plantillas y sobrecarga de operadores para 
representar las operaciones de inserción (operador +) y de eliminación (operador -).
*/
#include <iostream>
#define MAX 50
using namespace std;

template <class T>
class Arreglo {
private:
	T elementos[MAX];
	int tam;
public:
	Arreglo();
	int insertar(T);
	int buscar(T);
	int eliminar(T);
	void imprime();
	Arreglo operator+(T);
	Arreglo operator-(T);
};

template <class T>
Arreglo<T>::Arreglo()
{
	tam = 0;
}

template <class T>
int Arreglo<T>::insertar(T valor)
{
	int resultado = 1;
	if(tam + 1 > MAX) {
		resultado = -1;
	} else {
		elementos[tam++] = valor;
	}
	return resultado;
}

template <class T>
int Arreglo<T>::buscar(T valor)
{
	int indice = 0, resultado = -1;
	while(indice < tam && elementos[indice] != valor)
		indice++;
	
	if(indice < tam)
		resultado = indice;
	
	return indice;
}

template <class T>
int Arreglo<T>::eliminar(T valor)
{
	int resultado = 1;
	int pos = buscar(valor);
	if(valor < 0) {
		resultado = -1;
	} else {
		for(int i = pos; i < tam; i++)
			elementos[i] = elementos[i + 1];
		tam--;
	}
	
	return resultado;
}

template <class T>
Arreglo<T> Arreglo<T>::operator+(T valor)
{
	insertar(valor);
	return *this;
}

template <class T>
Arreglo<T> Arreglo<T>::operator-(T valor)
{
	eliminar(valor);
	return *this;
}

template <class T>
void Arreglo<T>::imprime() 
{
	cout << endl;
	for(int i = 0; i < tam; i++)
		cout << elementos[i] << " ";
	cout << endl;
}

void usaArreglo()
{
	Arreglo<int> arr = Arreglo<int>();
	int n, dato;
	do {
		cout << "Cantidad de elementos: ";
		cin >> n;
	} while(n < 0 || n > MAX);
	
	for(int i = 0; i < n; i++) {
		cout << "Elemento " << i + 1 << ": ";
		cin >> dato;
		arr.insertar(dato);
	}
	
	arr.imprime();
	
	arr = arr + 87;
	arr = arr - 12;
	arr.imprime();
}

int main()
{
	usaArreglo();
	return 0;
}