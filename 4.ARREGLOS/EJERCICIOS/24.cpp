/*
24.	Retome el problema anterior. Incluya un método en la plantilla que permita 
encontrar el valor más grande de un renglón. El usuario dará como dato el número 
del renglón que le interesa.
*/
#include "23.cpp"

void UsarMatrizTrianInf()
{
    int renglon;
    MatrizTrianInf<int> matriz = MatrizTrianInf<int>();
    matriz.Lectura();
    matriz.ImprimeDatos();
    matriz.ImprimeMatriz();
    cout << "\nIngrese renglon: ";
    cin >> renglon;

    cout << "\nEl valor maximo del renglon " << renglon << " es: " << matriz.ValorMaximoRenglon(renglon);


}

int main() 
{
    UsarMatrizTrianInf();
    return 0;
}