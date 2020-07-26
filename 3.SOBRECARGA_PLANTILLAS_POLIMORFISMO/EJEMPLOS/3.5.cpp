/* Se define la clase Complejo en la cual, algunos de los métodos se 
definieron sobrecargando operadores. Además, uno de esos métodos se 
sobrecargó. Es decir, usa un operador sobrecargado y tiene asociadas dos 
funciones dependiendo de los parámetros con los cuales se invoque. */
#include <iostream>
using namespace std;
/* Definición de la clase Complejo. */
class Complejo {
private:
    double Real, Imaginario;
public:
    Complejo (double R= 0, double I= 0);
    Complejo operator+(Complejo);
    Complejo operator-(Complejo);
    Complejo operator-();
    void MuestraComplejo();
}; 

/* Declaración del método constructor con parámetros predeterminados: si 
al crear un objeto no se dan valores al constructor, éste le asignará 0 
a los dos atributos. */
Complejo::Complejo(double R, double I)
{
    Real= R;
    Imaginario= I;
}

/* Método que suma dos números complejos. Se sobrecarga el operador +. */
Complejo Complejo::operator+(Complejo Com)
{
    return Complejo(Real + Com.Real, Imaginario + Com.Imaginario);
}

/* Método que resta dos números complejos. Se sobrecarga el operador -. */
Complejo Complejo::operator-(Complejo Com)
{
    return Complejo(Real - Com.Real, Imaginario - Com.Imaginario);
}

/* Método que cambia el signo de un número complejo. Se sobrecarga el 
operador - y el método operator -. */
Complejo Complejo::operator-()
{
    return Complejo (-Real, -Imaginario);
}

/* Método que imprime los valores de los atributos de un complejo. */
void Complejo::MuestraComplejo()
{
    cout << "Parte Real: " << Real << endl;
    cout << "Parte Imaginaria: " << Imaginario << endl;
}

/* Función que usa sobrecarga de operadores y de métodos: se declaran 
objetos de tipo Complejo y se opera con ellos utilizando los operadores 
y el método sobrecargados. */ 
void UsaSobrecargaOpMetodo()
{
    Complejo ObjComplejo1(5, 2), ObjComplejo2(2, 6), ObjComplejo3;
    /* Se invoca al método que suma números complejos y luego al que ^imprime. */
    ObjComplejo3= ObjComplejo1 + ObjComplejo2; ObjComplejo3.MuestraComplejo();
    /* Se invoca al método que resta números complejos y luego al que ^imprime. */
    ObjComplejo3= ObjComplejo1 - ObjComplejo2;
    ObjComplejo3.MuestraComplejo();
    /* Se invoca al método que cambia el signo de un número complejo y 
    luego al método que imprime. */
    ObjComplejo3= -ObjComplejo1;
    ObjComplejo3.MuestraComplejo();
}

int main() {
    UsaSobrecargaOpMetodo();
    return 0;
}