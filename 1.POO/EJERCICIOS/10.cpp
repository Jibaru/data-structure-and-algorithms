/*
10.	Utilice la clase definida en el ejercicio 9 para declarar objetos que representan dos alfombras 
rectangulares a colocar en una oficina. Escriba un programa que solicite las dimensiones de cada una 
de las alfombras y del piso y utilice los métodos incluidos en la clase, para calcular e imprimir la 
superficie del piso que va a quedar cubierta.
*/

#include <iostream>
#include "9.cpp"

using namespace std;

int main (){

    Rectangulo alfombra1(14, 30), alfombra2(23, 86);

    cout << "Superficie alfombra 1: " << alfombra1.area() << endl;
    cout << "Superficie alfombra 2: " << alfombra2.area() << endl;

    return 0;
}