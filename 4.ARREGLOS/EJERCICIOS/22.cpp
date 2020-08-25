/*
22.	Escriba una función que sume dos matrices poco densas almacenadas de acuerdo 
a lo visto en este libro. ¿Requiere modificar las plantillas definidas?
*/

#include "../EJEMPLOS/4.12.cpp"

void usaMatrizPocoDensa()
{
    int col, sumaCol;
    MatPocoDen<int> matriz1 = MatPocoDen<int>();
    MatPocoDen<int> matriz2 = MatPocoDen<int>();
    MatPocoDen<int> matrizSuma = MatPocoDen<int>();
    matriz1.Lectura();
    matriz2.Lectura();

    matrizSuma = matriz1 + matriz2;

    cout << "\nMatriz 1: " << endl;
    matriz1.Escritura();

    cout << "\nMatriz 2: " << endl;
    matriz2.Escritura();

    cout << "\nMatriz Suma: " << endl;
    matrizSuma.Escritura();
}

int main()
{
    usaMatrizPocoDensa();

    return 0;
}