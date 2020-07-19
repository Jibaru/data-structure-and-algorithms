/* Se define la clase Ejemplo en la cual se incluye la declaración de
la función Suma como una función amiga de la misma. Esto permitirá que
dicha función pueda tener acceso a todos los miembros de la clase.*/
#include <iostream>
using namespace std;

class Ejemplo {
private:
    int Atrib1, Atrib2;
public:
    Ejemplo();
    Ejemplo(int, int);
    void Imprime();
    friend int Suma(int, Ejemplo);
};

/* Declaración del método constructor por omisión. */
Ejemplo::Ejemplo(){}

/* Declaración del método constructor con parámetros. */
Ejemplo::Ejemplo(int Num1, int Num2)
{
    Atrib1= Num1;
    Atrib2= Num2;
}

/* Método que despliega los valores de los atributos de la clase. */
void Ejemplo::Imprime()
{
    cout << "Valor del primer atributo:	" << Atrib1 << endl;
    cout << "Valor del segundo atributo: " << Atrib2 <<endl;
}

/* Función entera declarada como amiga de la clase Ejemplo, lo que 
permite que pueda sumar sus atributos a un entero de manera directa. En
este caso, el parámetro Valor es un objeto de tipo Ejemplo y la función
obtiene como resultado la suma de sus atributos más un número dado 
también como parámetro.*/
int Suma(int Dato, Ejemplo Valor)
{
    return (Dato + Valor.Atrib1 + Valor.Atrib2);
}

/* Función que hace uso de la función amiga de la clase Ejemplo para 
obtener la suma de sus atributos. */  
void UsaFuncionesAmigas()
{
    int Resultado;
    Ejemplo ObjEjemplo(2, 5);
    Resultado= Suma (10, ObjEjemplo);
    cout << "El resultado de la suma es: " << Resultado << endl;
}
