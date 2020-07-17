/*
11.	Defina la clase Persona. Determine los atributos y el conjunto de métodos (lo más completos posible)
que caracterizan al concepto persona. Luego declare el objeto MiMaestra, de tipo Persona. Escriba un 
programa en C++ que utilice la clase previamente definida. El programa debe poder, por medio de los 
métodos incluidos en la clase, realizar las siguientes operaciones:
a)	Cambiar la dirección de MiMaestra. El usuario dará la nueva dirección.
b)	Cambiar el número de teléfono de MiMaestra. El usuario dará el nuevo número.
c)	Imprimir todos los datos de MiMaestra.
d)	Imprimir, si MiMaestra está casada, el nombre de su cónyuge.

*/
#include <iostream>
#include <string.h>

using namespace std;

class Persona {
private:
    char _nombre[45];
    char _direccion[64];
    char _telefono[10];
    bool _casado;
    char _nombreConyuge[45];

public:
    Persona(char[], char[], char[], bool, char[]);
    void cambiarDireccion(char []);
    void cambiarTelefono(char []);
    void imprimir();
    void imprimirNombreConyuge();
};

Persona::Persona(char nombre[45], char direccion[64], char telefono[10], bool casado, char nombreConyuge[45])
{
    strcpy(_nombre, nombre);
    strcpy(_direccion, direccion);
    strcpy(_telefono, telefono);
    _casado = casado;
    strcpy(_nombreConyuge, nombreConyuge);
}

void Persona::cambiarDireccion(char direccion[45])
{
    strcpy(_direccion, direccion);
}

void Persona::cambiarTelefono(char telefono[])
{
    strcpy(_telefono, telefono);
}

void Persona::imprimir()
{
    cout << "Nombre: " << _nombre << endl;
    cout << "Direccion: " << _direccion << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Casado: " << (_casado ? "SI" : "NO") << endl;
    imprimirNombreConyuge();
}

void Persona::imprimirNombreConyuge()
{
    if(_casado) cout << "Nombre conyuge: " << _nombreConyuge << endl;
}

int main(){

    Persona MiMaestra("Ana Banana", "Calle San Fernando 123", "985623221", true, "Pedro Carbonel");

    MiMaestra.cambiarDireccion("Calle San Jose 453");
    MiMaestra.cambiarTelefono("966553269");
    MiMaestra.imprimir();
    MiMaestra.imprimirNombreConyuge();

    return 0;
}