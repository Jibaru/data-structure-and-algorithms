/* Se definen las clases Ejemplol y Ejemplo2. En la clase Ejemplo1 se 
indica que el método EsMayor de la clase Ejemplo2 es un método amigo de 
la misma. */
#include <iostream>
#include <string.h>
using namespace std;

/* Prototipo de la clase Ejemplo1. Su definición se muestra más adelante. */
class Ejemplo1;

class Ejemplo2
{
private:
    int Valor2;
public:
    Ejemplo2(int);
    void Imprime();
    int EsMayor(Ejemplo1);
};

/* Declaración del método constructor. */
Ejemplo2::Ejemplo2(int Num)
{
    Valor2= Num;
}

/* Método que despliega el valor del atributo de la clase Ejemplo2. */
void Ejemplo2::Imprime()
{
    cout << "Valor del atributo: " << Valor2 << endl;
}

/* Método de la clase Ejemplo2. Este método es amigo de la clase Ejemplol,
por lo que tendrá acceso a los miembros privados y/o protegidos de la 
misma. */
int Ejemplo2::EsMayor(Ejemplo1 Obj)
{
    if (Valor2 > Obj.Valor1) return 1;
    else return 0;
}

/* Definición de la clase Ejemplo1. En esta clase, en la sección pública,
se incluye la declaración de un método de la clase Ejemplo2 como método
amigo, lo cual permite que este método tenga acceso a sus miembros 
privados y protegidos. */
class Ejemplo1 {
private:
    int Valor1;
public:
    Ejemplo1(int);
    void Imprime();
    friend int Ejemplo2::EsMayor(Ejemplo1);
};

/* Declaración del método constructor. */
Ejemplo1::Ejemplo1(int Num)
{
    Valor1= Num;
}

/* Método que despliega el valor del atributo de la clase Ejemplo1. */
void Ejemplo1::Imprime()
{
    cout << "Valor del atributo: " << Valor1 << endl;
}

/* Función que usa el método amigo de la clase Ejemplo1. */
void UsaMetodoAmigo()
{
    Ejemplo1 Obj1(10);
    Ejemplo2 Obj2(12);
    Obj1.Imprime();
    Obj2.Imprime ();
    if (Obj2.EsMayor(Obj1))
        cout << "Obj2 es mayor que Obj1" << endl;
    else
        cout << "Obj2 no es mayor que Obj1" << endl;
}