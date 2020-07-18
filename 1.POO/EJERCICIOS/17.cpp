/*
17. Retome la clase definida en el ejercicio anterior. ¿Qué método(s) debería agregarle/quitarle para que se 
pudiera imprimir, desde algún programa de aplicación, el nombre del libro de texto usado para la materia 
de BasesDatos

Se podría implementar el método obtenerLibro que devuelva el atributo libro.
*/
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

class Materia {
private:
    int _clave;
    char _nombre[45], _profesorTit[45], _libroTexto[45];

public:
    Materia(int, char[], char[], char[]);
    void imprime();
    void cambiaClave(int);
    void cambiaProfe(char[]);
    // nuevo método
    char* obtenerLibro();
};

Materia::Materia(int clave, char nombre[], char profesorTit[], char libroTexto[]) {
    _clave = clave;
    strcpy(_nombre, nombre);
    strcpy(_profesorTit, profesorTit);
    strcpy(_libroTexto, libroTexto);
}

void Materia::imprime() {
    cout << "Clave: " << _clave << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Profesor Tit.: " << _profesorTit << endl;
    cout << "Libro Text.: " << _libroTexto << endl;
}

void Materia::cambiaClave(int clave) {
    _clave = clave;
}

void Materia::cambiaProfe(char profesorTit[]) {
    strcpy(_profesorTit, profesorTit);
}

// Método que devolverá el libro de la materia
char* Materia::obtenerLibro() {
    return _libroTexto;
}