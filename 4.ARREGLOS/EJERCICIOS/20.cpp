/*
20.	Escriba un método para sumar los elementos de una columna de una matriz poco densa, 
guardada en memoria por medio de un arreglo unidimensional. El usuario dará como dato el 
número de la columna a sumar.
*/

#include "../EJEMPLOS/4.12.cpp"

void usaMatrizPocoDensa()
{
    int col, sumaCol;
    MatPocoDen<int> matriz = MatPocoDen<int>();

    matriz.Lectura();
    
    cout << "Ingrese columna a sumar: ";
    cin >> col;

    sumaCol = matriz.SumaCol(col);

    cout << "La suma de elementos de la columna " << col << " es: " << sumaCol << endl;
}

int main()
{
    usaMatrizPocoDensa();

    return 0;
}