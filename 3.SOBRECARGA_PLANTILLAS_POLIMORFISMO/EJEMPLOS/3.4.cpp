#include <iostream>
#include <math.h>
using namespace std;

/* Se define la función Max de tipo int, con parámetros también de tipo
int. Esta función compara dos valores enteros y regresa el valor más grande. */
int Max(int Val1, int Val2)
{
    if (Val1 > Val2)
        return Val1;
    else
        return Val2;
}

/* Se define la función Max de tipo double, con parámetros también de
tipo double. Esta función compara dos valores de tipo double y regresa
el valor más grande. */
double Max(double Val1, double Val2)
{
    if (Val1 > Val2)
        return Val1;
    else
        return Val2;
}

/* Se define la función Raiz2, con un parámetro de tipo int. Regresa la
raíz cuadrada del dato. */
double Raiz2(int Num)
{
    return sqrt(Num);
}

/*Se define la función Raiz2, con un parámetro de tipo double. Regresa 
la raiz cuadrada del dato. */
double Raiz2(double Num)
{
    return sqrt(Num);
}

/* Función que usa las funciones sobrecargadas definidas previamente. */
void UsaSobrecargaFunciones()
{
    /* Se imprime el resultado de la función Max, primero invocándola con 
    valores enteros y luego con valores de doble precisión. */ 
    cout << "Max de 2 y 5 es: " << Max(2, 5) << endl;
    cout << "Max de 5.23 y 6.98 es: " << Max(5.23, 6.98) << endl;
    /* Se imprime el resultado de la función Raiz2, primero invocándola
    con valores enteros y luego con valores de doble precisión. */
    cout << "Raiz cuadrada de 5 es: " << Raiz2(5) << endl;
    cout << "Raiz cuadrada de 8.96 es: " << Raiz2(8.96) << endl;
}

int main() {
    UsaSobrecargaFunciones();
    return 0;
}
