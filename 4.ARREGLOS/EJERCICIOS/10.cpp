/*
10.	Escriba un programa que sume dos objetos de tipo arreglos bidimensionales de enteros. 
Utilice la plantilla de la clase arreglo bidimensional para declarar los objetos. 
Modifíquela si lo cree necesario. El programa debe imprimir el arreglo resultante.
Cmxn = Amxn + Bmxn
*/
#include "../EJEMPLOS/4.7.cpp"

void UsaArregloBidimensional() 
{
    ArregloBidimensional<int> a(4, 5);
    ArregloBidimensional<int> b(4, 5);
    ArregloBidimensional<int> c(4, 5);

    a.Lectura();
    b.Lectura();
    c = a + b;

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