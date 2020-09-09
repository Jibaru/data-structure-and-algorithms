/*
17. Observe el siguiente esquema. Diseñe una estructura de datos que pueda 
representar los datos y las relaciones entre ellos de manera adecuada. 
Defina una clase para las marcas y otra para los modelos.

Primer Nivel(Marcas): Primero->Audi->...->...->(Último)->NULL
Segundo Nivel(Modelos): Audi->A3->A4->NULL ...->...->NULL ...->NULL
*/
#include <iostream>
#include <string.h>
#include "../../lib/listas/ListasSimLig.h"

/*
Clase Modelo de auto
*/
class Modelo
{
private:
    char* nombre;
public:
    Modelo();
    Modelo(char*);
    char* regresaNombre();
    void cambiaNombre(char*);
    int operator==(Modelo&);
    int operator!=(Modelo&);
    friend std::istream& operator>>(std::istream&, Modelo&);
    friend std::ostream& operator<<(std::ostream&, Modelo&);
};

/*
Constructor vacio
*/
Modelo::Modelo()
{
    nombre = NULL;
}

/*
Constructor con parametros
*/
Modelo::Modelo(char* nombre)
{
    if(this->nombre) {
        delete this->nombre;
    }

    this->nombre = new char[strlen(nombre) + 1];
    if(this->nombre != NULL) {
        strcpy(this->nombre, nombre);
    }
}

/*
Metodo que regresa el nombre del modelo
*/
char* Modelo::regresaNombre()
{
    return nombre;
}

/*
Metodo que permite cambiar el nombre del modelo
*/
void Modelo::cambiaNombre(char* nombre)
{
    if(this->nombre) {
        delete this->nombre;
    }

    this->nombre = new char[strlen(nombre) + 1];
    if(this->nombre != NULL) {
        strcpy(this->nombre, nombre);
    }
}

/*
Sobreescritura del operator ==
*/
int Modelo::operator==(Modelo& obj)
{
    return (strcmp(nombre, obj.nombre) == 0);
}

/*
Sobreescritura del operator !=
*/
int Modelo::operator!=(Modelo& obj)
{
    return (strcmp(nombre, obj.nombre) != 0);
}

/*
Sobreescritura del operator >>
*/
std::istream& operator>>(std::istream& entrada, Modelo& m)
{
    char nomAux[60];
    std::cout << "Nombre Modelo: ";
    entrada.ignore();
    entrada.getline(nomAux, 60);
    m.cambiaNombre(nomAux);
    
    return entrada;
}

/*
Sobreescritura del operator <<
*/
std::ostream& operator<<(std::ostream& salida, Modelo& m)
{
    salida << "Nombre Modelo: " << m.nombre << std::endl;
    return salida;
}

/*
Clase Marca de auto
*/
class Marca 
{
private:
    char* nombre;
    Lista<Modelo> modelos;
public:
    Marca();
    Marca(char*);
    char* regresaNombre();
    void cambiaNombre(char*);
    Lista<Modelo>* regresaModelos();
    int operator==(Marca&);
    int operator!=(Marca&);
    friend std::istream& operator>>(std::istream&, Marca&);
    friend std::ostream& operator<<(std::ostream&, Marca&);
};

/*
Constructor vacio de Marca
*/
Marca::Marca()
{
    nombre = NULL;
}

/*
Constructor con parametros
*/
Marca::Marca(char* nombre)
{
    if(this->nombre) {
        delete this->nombre;
    }

    this->nombre = new char[strlen(nombre) + 1];
    if(this->nombre != NULL) {
        strcpy(this->nombre, nombre);
    }
}

/*
Metodo que regresa el nombre del Marca
*/
char* Marca::regresaNombre()
{
    return nombre;
}

/*
Metodo que permite cambiar el nombre del Marca
*/
void Marca::cambiaNombre(char* nombre)
{
    if(this->nombre) {
        delete this->nombre;
    }

    this->nombre = new char[strlen(nombre) + 1];
    if(this->nombre != NULL) {
        strcpy(this->nombre, nombre);
    }
}

/*
Metodo que devuelve un apuntador a la lista de modelos
de la marca
*/
Lista<Modelo>* Marca::regresaModelos()
{
    return &modelos;
}

/*
Sobreescritura del operator ==
*/
int Marca::operator==(Marca& obj)
{
    return (strcmp(nombre, obj.nombre) == 0);
}

/*
Sobreescritura del operator !=
*/
int Marca::operator!=(Marca& obj)
{
    return (strcmp(nombre, obj.nombre) != 0);
}

/*
Sobreescritura del operator >>
*/
std::istream& operator>>(std::istream& entrada, Marca& m)
{
    char nomAux[60];
    std::cout << "Nombre Marca: ";
    entrada.ignore();
    entrada.getline(nomAux, 60);
    m.cambiaNombre(nomAux);
    
    return entrada;
}

/*
Sobreescritura del operator <<
*/
std::ostream& operator<<(std::ostream& salida, Marca& m)
{
    salida << "Nombre Marca: " << m.nombre << std::endl;
    return salida;
}