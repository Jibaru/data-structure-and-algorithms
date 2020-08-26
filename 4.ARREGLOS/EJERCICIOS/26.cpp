/*
26.	Escriba un programa que multiplique dos matrices triangulares inferiores, 
almacenadas en arreglos unidimensionales.
*/
#include "23.cpp"

void UsarMatrizTrianInf()
{
    int renglon;
    MatrizTrianInf<int> matriz1 = MatrizTrianInf<int>();
    MatrizTrianInf<int> matriz2 = MatrizTrianInf<int>();
    MatrizTrianInf<int> mtrizProd = MatrizTrianInf<int>();

    matriz1.Lectura();
    matriz2.Lectura();

    matriz1.ImprimeMatriz();
    matriz2.ImprimeMatriz();

    mtrizProd = matriz1 * matriz2;

    mtrizProd.ImprimeMatriz();

    matriz1.ImprimeDatos();
    matriz2.ImprimeDatos();
    mtrizProd.ImprimeDatos();
}

int main() 
{
    UsarMatrizTrianInf();
    return 0;
}