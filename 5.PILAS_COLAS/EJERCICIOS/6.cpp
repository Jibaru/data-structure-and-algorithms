/*
6.	Escriba un programa en C++ que invierta iterativamente los elementos 
de una cola. Puede usar cualquier estructura de datos como auxiliar.
*/

#include "../EJEMPLOS/5.5.cpp"

template <class T>
void invierteCola(Cola<T> &cola)
{
	T arr[20];
	T dato;
	int i = 0;
	while(cola.ColaVacia() != 1) {
		cola - &dato;
		arr[i] = dato;
		i++;
	}
	i -= 1;
	while(i >= 0) {
		cola + arr[i];
		i--;
	}
}

void UsaColaEjercicio6()
{
	Cola<char> cola = Cola<char>();
	
	cola + 'h';
	cola + 'o';
	cola + 'l';
	cola + 'a';
	
	cout << "\nCola: ";
	cola.ImprimeDatos();
	
	invierteCola(cola);
	
	cout << "\nCola invertida: ";
	cola.ImprimeDatos();
	
}

int main()
{
	UsaColaEjercicio6();
	return 0;
}