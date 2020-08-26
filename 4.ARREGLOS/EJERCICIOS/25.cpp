/*
25.	Escriba un programa que sume dos matrices triangulares superiores, almacenadas 
en arreglos unidimensionales.
*/
#include "../EJEMPLOS/4.13.cpp"

void UsarMatrizTrianInf()
{
    int renglon;
    MatrizTrianSup<int> matriz1 = MatrizTrianSup<int>();
    MatrizTrianSup<int> matriz2 = MatrizTrianSup<int>();
    MatrizTrianSup<int> matrizSuma = MatrizTrianSup<int>();

    matriz1.Lectura();
    matriz2.Lectura();

    matriz1.ImprimeMatriz();
    matriz2.ImprimeMatriz();

    matrizSuma = matriz1 + matriz2;

    matrizSuma.ImprimeMatriz();

    matriz1.ImprimeDatos();
    matriz2.ImprimeDatos();
    matrizSuma.ImprimeDatos();
}

int main() 
{
    UsarMatrizTrianInf();
    return 0;
}