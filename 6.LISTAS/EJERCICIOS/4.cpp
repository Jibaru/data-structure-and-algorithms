/*
4.	Escriba un programa que mezcle dos listas simplemente ligadas 
de números enteros, cuyos valores están ordenados crecientemente. 
El programa debe ir generando una única lista con los nodos de las 
listas dadas como datos. Al terminar el proceso, sólo debe quedar 
una lista ordenada, formada con la unión de las listas de entrada.
*/
#include <iostream>
#include "1.cpp"
using namespace std;

int main()
{
	ListaSimLigada<int> l1 = ListaSimLigada<int>();
	ListaSimLigada<int> l2 = ListaSimLigada<int>();
	ListaSimLigada<int> *lcomb = new ListaSimLigada<int>();
	
	l1.insertaFinal(1);
	l1.insertaFinal(5);
	l1.insertaFinal(8);
	l1.insertaFinal(19);
	
	l2.insertaFinal(3);
	l2.insertaFinal(4);
	l2.insertaFinal(5);
	l2.insertaFinal(10);
	l2.insertaFinal(12);
	l2.insertaFinal(20);
	
	lcomb = l1.combina(l2);
	
	cout << "\nL1: ";
	l1.imprimir();
	
	cout << "\nL2: ";
	l2.imprimir();

	cout << "\nL3: ";
	lcomb->imprimir();
	
	return 0;
}