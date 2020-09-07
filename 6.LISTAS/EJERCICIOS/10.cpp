/*
10.	Escriba un programa que invierta los elementos de una cola 
implementada por medio de una lista. Utilice la plantilla definida 
en el ejercicio anterior.
*/
#include <iostream>
#include "9.cpp"

using namespace std;

int main()
{
    ColaLigada<int> c = ColaLigada<int>();

    c.push(6);
    c.push(7);
    c.push(100);
    c.push(8);
    c.push(65);
    c.push(19);
    c.push(11);
    c.imprimir();
    
    c.invertir();
    c.imprimir();
    return 0;
}