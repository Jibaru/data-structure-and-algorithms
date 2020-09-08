/*
12.	Retome el problema anterior. Escriba un programa que lea 
una serie de N (1< N < 50) pares de números reales, los guarde 
en la lista y los use para calcular e imprimir el resultado de 
las siguientes expresiones:

B0 = Yprom - B1 Xprom

B1 = [ Sum(i=1, N)(XiYi - NXpromYprom) ] / [Sum(i=1, N)((Xi)^2 - N(Xprom)^2)]
*/
#include <iostream>
#include "11.cpp"

using namespace std;

int main()
{
	ListaSimLigadaPares l = ListaSimLigadaPares();

    l.insertaFinal(-12, 2);
    l.insertaFinal(5.33, 4);
    l.insertaFinal(11, 3.4);
	l.insertaFinal(1, 0);
	l.insertaFinal(9.3, -2.4);
    l.imprimir();
	
	cout << "Prom X: " << l.promedioX() << endl;
	cout << "Prom Y: " << l.promedioY() << endl;
	cout << "B0: " << l.calculaB0() << endl;
	cout << "B1: " << l.calculaB1() << endl;
	
	return 0;
}
