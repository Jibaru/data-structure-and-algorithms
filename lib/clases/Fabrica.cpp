#include <iostream>
#include <string.h>
#include "Fabrica.h"

/* Declaración del método constructor por omisión. */
Fabrica::Fabrica()
{}

/* Declaración del método constructor con parámetros. */
Fabrica::Fabrica(int Cla, const char Nom[], const char Domic[], const char Tel[])
{
    Clave= Cla;
    strcpy(Nombre, Nom);
    strcpy(Domicilio, Domic);
    strcpy(Telefono, Tel);
}

/* Método que actualiza el domicilio de una fábrica. */
void Fabrica::CambiaDomic(const char NuevoDom[])
{
    strcpy(Domicilio, NuevoDom);
}

/* Método que actualiza el teléfono de una fábrica. */
void Fabrica::CambiaTelef(const char NuevoTel[])
{
    strcpy(Telefono, NuevoTel);
}

/* Sobrecarga del operador > lo cual permite comparar dos objetos tipo 
Fabrica. La comparación se hace teniendo en cuenta solamente la clave. */
int Fabrica::operator > (Fabrica ObjFab)
{
    if (Clave > ObjFab.Clave)
        return 1;
    else
        return 0;
}

/* Sobrecarga del operador < lo cual permite comparar dos objetos tipo 
Fabrica. La comparación se hace teniendo en cuenta solamente la clave. */
int Fabrica::operator < (Fabrica ObjFab)
{
    if (Clave < ObjFab.Clave)
        return 1;
    else
        return 0;
}

/* Sobrecarga del operador = lo cual permite comparar dos objetos tipo 
Fabrica. La comparación se hace teniendo en cuenta solamente la clave. */
int Fabrica::operator == (Fabrica ObjFab)
{
    if (Clave == ObjFab.Clave)
        return 1;
    else
        return 0;
}

/* Sobrecarga del operador >> para permitir la lectura de objetos de 
tipo Fabrica de manera directa con el std::cin. */
std::istream & operator>> (std::istream & Lee, Fabrica & ObjFab)
{
    std::cout << "\n\nIngrese nombre de la fabrica:";
    Lee >> ObjFab.Nombre;
    std::cout << "\n\nIngrese clave de la fabrica:";
    Lee >> ObjFab.Clave;
    std::cout<<"\n\nIngrese domicilio de la fabrica:";
    Lee >> ObjFab.Domicilio;
    std::cout << "\n\nIngrese telefono de la fabrica:";
    Lee >> ObjFab.Telefono;
    return Lee;
}

/* Sobrecarga del operador << para permitir la impresión de objetos de
tipo Fabrica de manera directa con el std::cout. */
std::ostream & operator<<(std::ostream & Escribe, Fabrica & ObjFab)
{
    std::cout << "\n\nDatos de la fabrica\n";
    Escribe << "Nombre: " << ObjFab.Nombre << std::endl;
    Escribe << "Clave: " << ObjFab.Clave << std::endl;
    Escribe << "Domicilio: " << ObjFab.Domicilio << std::endl;
    Escribe << "Telefono: " << ObjFab.Telefono << std::endl;
    
    return Escribe;
}