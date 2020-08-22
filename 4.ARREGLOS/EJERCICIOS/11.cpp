/*
11.	Escriba un programa que multiplique dos objetos de tipo arreglos bidimensionales 
de números reales. Utilice la plantilla de la clase arreglo bidimensio¬nal para declarar 
los objetos. Modifíquela si lo cree necesario.
Cmxn = Amxn * Bmxn
*/

#include "../EJEMPLOS/4.7.cpp"

void UsaArregloBidimensional() 
{
    ArregloBidimensional<float> a(3, 2);
    ArregloBidimensional<float> b(2, 4);
    ArregloBidimensional<float> c(3, 4);

    a.Lectura();
    b.Lectura();
    c = a * b;

    a.Escritura();
    cout << endl;
    b.Escritura();
    cout << endl;
    c.Escritura();
}

int main() {
    UsaArregloBidimensional();
    return 0;
}