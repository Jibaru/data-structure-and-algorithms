/*
16.	Defina la clase Materia, según las especificaciones que se dan. Posteriormente, en un programa de
aplicación declare los objetos Programación y BasesDatos usando la clase previamente definida. 
El programa debe permitir al usuario, por medio de menús:
a)  Cambiar la clave de la materia Programación.
b)	Cambiar el nombre del maestro que imparte la materia BasesDatos.
c)	Imprimir todos los datos de la materia BasesDatos.
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

int main() {

    Materia programacion(1234, "Programacion", "Jose Matias", "Clean Code C++"),
        baseDeDatos(1111, "Base de Datos", "Lucia Thalia", "JJ Database");

    int eleccion;

    while(true){
        system("cls");
        cout << "Menu Materias" << endl;
        cout << "1. Cambiar clave Programacion "<< endl;
        cout << "2. Cambiar profesor base de datos " << endl;
        cout << "3. Ver datos base de datos" << endl;
        cin >> eleccion;

        system("cls");
        switch (eleccion) {
        case 1:
            int clave;
            cout << "Cambiar clave Programacion" << endl;
            cout << "Clave: ";
            cin >> clave;
            programacion.cambiaClave(clave);
            cout << "Clave cambiada" << endl;
            break;
        case 2:
            char profe[45]; 
            cout << "Cambiar profesor base de datos" << endl;
            cout << "Nuevo profesor: ";
            cin.ignore();
            cin.getline(profe, 45);
            baseDeDatos.cambiaProfe(profe);
            cout << "Profesor actualizado" << endl;
            break;
        case 3:
            cout << "Ver datos base de datos" << endl;
            baseDeDatos.imprime();
            break;
        default:
            cout << "Eleccion incorrecta" << endl;
            break;
        }

        getch();
    }

    return 0;
}