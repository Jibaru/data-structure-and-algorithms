/*
7.	Escriba un programa en C++ que invierta recursivamente los elementos 
de una cola. Puede usar cualquier estructura de datos como auxiliar.
*/

#include "../EJEMPLOS/5.5.cpp"

void UsaColaEjercicio6()
{
	Cola<char> cola = Cola<char>();
	
	cola + 'h';
	cola + 'o';
	cola + 'l';
	cola + 'a';
	
	cout << "\nCola: ";
	cola.ImprimeDatos();
	
	InvierteColaRecursivo(cola, -1);
	
	cout << "\nCola invertida: ";
	cola.ImprimeDatos();
	
}

int main()
{
	UsaColaEjercicio6();
	return 0;
}