/*
6.	Retome el problema anterior. Se definen tres métodos de la clase Trabajador y la función main. 
Analice cuidadosamente las siguientes declaraciones y diga si los enunciados que aparecen después 
del código son verdaderos o falsos.
a)	Cuando se declara el objeto Pepe se deben dar valores para todos los parámetros. Justifique su respuesta.
No, solo es necesario el nombre, los otros valores pueden omitirse
b)	Cuando se declara el objeto Carlos se pudo dar valores sólo a los atributos Nombre y Sueldo. Justifique su respuesta.
Si, pero el valor para "Si" hubiera permanecido en 1 por defecto
c)	Se dieron demasiados valores al declarar el objeto Paco. Justifique su respuesta.
No, se dieron los valores correctos diferentes a los valores por omisión
d)	En el método AumentaSueldo es incorrecto usar Trabajador::Sueldo. Justifique su respuesta.
Si, porque es no estaría llamando al atributo de instancia sino al de clase y el sueldo
sería igual para todos los objetos
*/
#include <iostream>
#include <string.h>

using namespace std;

// Del Ejercicio 5
class Trabajador {
private:
    char Nombre[64]; int ClaveTrab, Sindi; float Sueldo; 
public:
    Trabajador(char [], int, int, float);
    void Imprime();
    void CambiaEstado();
    void AumentaSueldo(float);
};

Trabajador::Trabajador(char Nom[],int Cla=1000,int Si=1,float Sue=1600) {
    strcpy(Nombre, Nom);
    ClaveTrab= Cla;
    Sindi= Si;
    Sueldo= Sue;
}

// Esto se implementa recién en este ejercicio
void Trabajador::Imprime()
{
    cout<<"\n\nNombre del trabajador: "<< Nombre; cout<<"\nClave: "<<ClaveTrab; 
    if (Sindi)
        cout<<"\nEstá sindicalizado."; 
    cout<<"\nSueldo: "<<Sueldo<<" \n\n";
}
void Trabajador::CambiaEstado()
{
    Sindi= !Sindi;
}
void Trabajador::AumentaSueldo(float Aumento )
{
    Trabajador::Sueldo= Trabajador::Sueldo * (1 + Aumento);
}
void main()
{
    Trabajador Pepe("Jose Pérez");
    Pepe.Imprime();
    Trabajador Carlos("Carlos González", 1050, 0);
    Carlos.Imprime();
    Carlos.CambiaEstado();
    Carlos.Imprime();
    Trabajador Paco("Francisco Quiroz", 2200, 1, 5680.25); Paco.Imprime();
    Paco.AumentaSueldo(0.10);
    Paco.Imprime();
}