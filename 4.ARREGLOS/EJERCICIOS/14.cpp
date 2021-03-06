/*
14.	Escriba un programa que obtenga la traspuesta de una matriz cuadrada (arreglo 
bidimensional de N por N elementos). Por ejemplo, si la matriz dada es a), su 
traspuesta es b).
a) Matriz    b) Traspuesta
10 -12  6    10 45  9
45  20 17   -12 20  6
 9   6  2     6 17  2
*/
#include "../EJEMPLOS/4.7.cpp"

void UsaArregloBidimensional() 
{
    ArregloBidimensional<float> a(3, 3);

    a.Lectura();
    a.Escritura();
    cout << "\nTranspuesta: \n";
    a.Transpuesta().Escritura();
}

int main() {
    UsaArregloBidimensional();
    return 0;
}