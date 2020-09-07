/*
5.	Escriba un programa que, dada una lista simplemente ligada de 
números enteros, elimine los elementos repetidos.
a) Considere el caso de una lista ordenada.
b) Considere el caso de una lista desordenada
*/
#include <iostream>
#include "1.cpp"

using namespace std;

int main()
{
	ListaSimLigada<int> lisOrd = ListaSimLigada<int>();
	ListaSimLigada<int> lisDes = ListaSimLigada<int>();
	
	// Lista ordenada
	lisOrd.insertaFinal(8);
	lisOrd.insertaFinal(11);
	lisOrd.insertaFinal(19);
	lisOrd.insertaFinal(19);
	lisOrd.insertaFinal(19);
	lisOrd.insertaFinal(22);
	lisOrd.insertaFinal(34);
	lisOrd.insertaFinal(34);
	lisOrd.insertaFinal(41);
	lisOrd.insertaFinal(41);
	
	// Lista desordenada
	lisDes.insertaFinal(12);
	lisDes.insertaFinal(12);
	lisDes.insertaFinal(2);
	lisDes.insertaFinal(4);
	lisDes.insertaFinal(12);
	lisDes.insertaFinal(9);
	lisDes.insertaFinal(2);
	lisDes.insertaFinal(23);
	lisDes.insertaFinal(23);
	
	cout << "\nLista ordenada: ";
	lisOrd.imprimir();
	cout << "\nLista desordenada: ";
	lisDes.imprimir();
	
	lisOrd.eliminaRepetidosOrdenada();
	lisDes.eliminaRepetidosDesordenada();
	
	cout << "\nLista ordenada sin repetidos: ";
	lisOrd.imprimir();
	cout << "\nLista desordenada sin repetidos: ";
	lisDes.imprimir();
	
	return 0;
}