/*1. Considere la siguiente relación de herencia. Defina las clases Mamífero, Felino y GatoDomestico.
Decida qué atributos y métodos incluir de tal manera que su programa pueda:
á) Declarar un objeto llamado Minino de tipo GatoDomestico y otro llamado EstrellaCirco de tipo Felino.
b)	Imprimir la dieta de Minino y de EstrellaCirco.
c)	Imprimir el año y lugar de nacimiento de Minino y de EstrellaCirco.
d)	Cambiar el nombre del dueño de Minino.
e)	Imprimir la raza de Minino y de EstrellaCirco.
f)	Cambiar el nombre del circo en el que actúa EstrellaCirco.

Mamifero <- Felino <- GatoDomestico
*/
#include <iostream>
#include <string.h>
using namespace std;

class Mamifero {
protected:
    int anioNac;
    char* lugarNac;
public:
    Mamifero(int, char*);
    void imprimirDatos();
};

Mamifero::Mamifero(int anio, char* lugar){
    anioNac = anio;
    lugarNac = new char[strlen(lugar)+1];

    if (lugarNac)
        strcpy(lugarNac, lugar);
}

void Mamifero::imprimirDatos() {
    cout << "Anio Nac.: " << anioNac << endl;
    cout << "Lugar Nac.: " << lugarNac << endl; 
}

class Felino : public Mamifero {
private:
    char* nombreCirco;
protected:
    char* nombre;
    char* raza;
    char* dieta;
public:
    Felino(char*, char*, char*, int, char*);
    void cambiarNombreCirco(char*);
    void imprimirDieta();
    void imprimirAnioLugar();
    void imprimirRaza();
    void imprimirDatos();
};

Felino::Felino(char* nom, char* raz, char* diet, int anioNac, char*lugarNac):
        Mamifero(anioNac, lugarNac) {
    nombre = nom;
    raza = raz;
    dieta = diet;
    nombreCirco = NULL;
}

void Felino::cambiarNombreCirco(char* nomCirco) {
    nombreCirco = nomCirco;
}

void Felino::imprimirDieta() {
    cout << "Dieta: " << dieta << endl;
}

void Felino::imprimirAnioLugar() {
    cout << "Anio y lugar de Nac: " << anioNac << ", " << lugarNac << endl;
}

void Felino::imprimirRaza() {
    cout << "Raza: " << raza << endl;
}

void Felino::imprimirDatos() {
    Mamifero::imprimirDatos();
    cout << "Nombre: " << nombre << endl;
    cout << "Raza: " << raza << endl;
    cout << "Dieta: " << dieta << endl;
    if(nombreCirco)
        cout << "Nombre circo: " << nombreCirco << endl; 
}

class GatoDomestico : public Felino {
private:
    char* nombreDuenio;
public:
    GatoDomestico(char* nom, char* raz, char* diet, int anioNac, char*lugarNac);
    void cambiarNomDuenio(char*);
    void imprimirDatos();
};

GatoDomestico::GatoDomestico(char* nom, char* raz, char* diet, int anioNac, char*lugarNac):
    Felino(nom, raz, diet, anioNac, lugarNac) {
    nombreDuenio = NULL;
}

void GatoDomestico::cambiarNomDuenio(char* nomDue){
    nombreDuenio = nomDue;
}

void GatoDomestico::imprimirDatos() {
    Felino::imprimirDatos();
    if(nombreDuenio)
        cout << "Nombre Duenio: " << nombreDuenio << endl;
}

int main(){

    Felino EstrellaCirco("Estrella circo", "Tigre", "Carne cruda", 1997, "Los Angeles");
    GatoDomestico Minino("Minimo", "Cuto", "Ricocat", 2001, "Peru");

    Minino.imprimirDieta();
    EstrellaCirco.imprimirDieta();

    Minino.imprimirAnioLugar();
    EstrellaCirco.imprimirAnioLugar();

    Minino.cambiarNomDuenio("Ignacio");

    Minino.imprimirRaza();
    EstrellaCirco.imprimirRaza();

    EstrellaCirco.cambiarNombreCirco("Los 3 gatitos");

    EstrellaCirco.imprimirDatos();
    Minino.imprimirDatos();

    return 0;
}