/* Se declaran plantillas de funciones para Max y Raiz2. De esta manera 
las mismas podrán trabajar sobre diferentes tipos de datos. Es decir, 
en el momento de invocar a las funciones y al darles parámetros específicos, 
se estarán creando versiones diferentes de las mismas,
de acuerdo a los tipos de los datos proporcionados. */
#include <iostream>
#include <math.h>
using namespace std;

/* El objetivo de esta plantilla de función es encontrar el mayor de dos avalores dados. */
template <class T>
T Max (T Val1, T Val2)
{
    if (Val1 > Val2) 
        return Val1;
    else
        return Val2;
}

/* El objetivo de esta plantilla de función es calcular la raíz cuadrada 
de un valor dado. */
template <class T>
double Raiz2 (T Num)
{
    return sqrt(Num);
}
/* Función que utiliza las plantillas de funciones previamente 
definidas. */
void UsaPlantilla() {
    /* En las siguientes dos líneas se invocan las versiones enteras y de 
    punto flotante de la función Max, respectivamente. */
    cout << "Max de 2 y 5 es: " << Max(2, 5) << endl;
    cout << "Max de 5.23 y 6.98 es: " << Max(5.23, 6.98) << endl;
    /* En las siguientes dos lineas se invocan a las versiones enteras de
    punto flotante de la función Raiz2, respectivamente. */ 
    cout << "Raiz2 de 5 es: " << Raiz2(5) << endl;
    cout << "Raiz2 de 8.96 es: " << Raiz2(8.96) << endl;
}

int main() {
    UsaPlantilla();
    return 0;
}