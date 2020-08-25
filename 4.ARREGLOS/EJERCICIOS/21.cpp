/*
21.	Escriba un método que imprima una matriz poco densa almacenada por medio 
de un arreglo unidimensional, con formato de arreglo bidimensional. Es decir, 
el usuario verá en la pantalla la matriz con su forma original.
*/

#include "../EJEMPLOS/4.12.cpp"

void usaMatrizPocoDensa()
{
    int col, sumaCol;
    MatPocoDen<int> matriz = MatPocoDen<int>();

    matriz.Lectura();
    
    matriz.Escritura();
}

int main()
{
    usaMatrizPocoDensa();

    return 0;
}