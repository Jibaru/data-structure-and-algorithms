/*
8.	Escriba un programa en C++ que elimine los elementos repetidos 
de una cola circular. Suponga que si existen elementos repetidos, 
los mismos se encuentran en posiciones consecutivas (ver la figura). 
Puede usar cualquier estructura de datos como auxiliar.
     
     0   1   2   3   4   5     MAX-1
	[87, 54, 54, 54, 91, 91,..., ] 
         ^           ^
       Frente      Final
*/
#include <iostream>
#include "../EJEMPLOS/5.7.cpp"
using namespace std;

template <class T>
void eliminaRepetidos(ColaCircular<T>& cola)
{
	ColaCircular<T> aux = ColaCircular<T>();
	T dato = 0, anterior = 0;
	
	while(cola.ColaCircularVacia() != 1) {
		cola.EliminaCCircular(&dato);
		aux.InsertaCCircular(dato);
	}
	
	while(aux.ColaCircularVacia() != 1) {
		
		aux.EliminaCCircular(&dato);
		
		if(dato != anterior) {
			cola.InsertaCCircular(dato);
		}
		anterior = dato;
	}
}

template <class T>
void muestraColaCircular(ColaCircular<T> cola){
	ColaCircular<T> aux = cola;
	T dato = 0;
	
	while(cola.ColaCircularVacia() != 1) {
		cola.EliminaCCircular(&dato);
		cout << " <- " << dato;
	}
}

void UsaColaCirculaEjercicio8()
{
	ColaCircular<int> cola = ColaCircular<int>();
	
	cola.InsertaCCircular(87);
	cola.InsertaCCircular(54);
	cola.InsertaCCircular(54);
	cola.InsertaCCircular(54);
	cola.InsertaCCircular(91);
	cola.InsertaCCircular(91);
	
	cout << "\nCola Circular: ";
	muestraColaCircular(cola);
	
	eliminaRepetidos(cola);
	
	cout << "\nCola Circular sin repetidos: ";
	muestraColaCircular(cola);
}

int main()
{
	UsaColaCirculaEjercicio8();
	return 0;
}