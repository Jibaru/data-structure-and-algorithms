/*
12.	Escriba un programa que imprima los elementos de la diagonal principal de un arreglo 
bidimensional. Utilice la plantilla de la clase arreglo bidimensional para declarar el 
objeto. Modifíquela si lo cree necesario.
*/

#include "../EJEMPLOS/4.7.cpp"

void UsaArregloBidimensional() 
{
    ArregloBidimensional<float> a(3, 3);

    a.Lectura();
    a.Escritura();
    cout << "\nDiagonal: ";
    a.muestraDiagonal();
}

int main() {
    UsaArregloBidimensional();
    return 0;
}