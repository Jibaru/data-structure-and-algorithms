/*
12.	Defina la clase Mamifero que contenga los atributos que caracterizan a un animal de este tipo, 
los métodos necesarios para el manejo de la información, así como diferentes constructores para crear e
inicializar objetos de tipo Mamifero. Se sugiere definir constructores por omisión, con parámetros y/o 
con parámetros por omisión. Escriba un programa en C++ que utilice la clase previamente definida. 
El programa debe poder realizar, por medio de los métodos incluidos en la clase, las siguientes 
operaciones:
a) Declarar los objetos Perro y Elefante. Utilice los métodos constructores o algún método de lectura 
para darle valor a los atributos incluidos en la clase.
b) Imprimir el tipo de alimentación del objeto Elefante. Analice alternativas de solución considerando
 que el atributo en cuestión sea privado o público.
c) Imprimir los valores de todos los atributos del objeto Perro.

*/
#include <iostream>
#include <string.h>

using namespace std;

class Mamifero {
private:
    char _nombre[40], _alimento[40], _color[40];
public:
    Mamifero();
    Mamifero(char[], char[], char[]);
    char* obtenerAlimento();
    void imprimirDatos();
};

Mamifero::Mamifero(){}

Mamifero::Mamifero(char nombre[], char alimento[], char color[]){
    strcpy(_nombre, nombre);
    strcpy(_alimento, alimento);
    strcpy(_color, color);
}

char* Mamifero::obtenerAlimento(){
    return _alimento;
}

void Mamifero::imprimirDatos() {
    cout << "Nombre: " << _nombre << endl;
    cout << "Alimento: " << _alimento << endl;
    cout << "Color: " << _color << endl;
}

int main() {

    Mamifero perro("Perro", "carne", "negro"), elefante("Elefante", "plantas", "gris");

    cout << "Alimento del elefante: " << elefante.obtenerAlimento() << endl;

    perro.imprimirDatos();

    return 0;
}