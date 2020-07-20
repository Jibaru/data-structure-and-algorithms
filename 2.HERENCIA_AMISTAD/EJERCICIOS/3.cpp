/*3.	Definir la clase Planta que contenga todos los atributos que caracterizan a las plantas, y los 
métodos necesarios para manejarlos. Además, defina las clases derivadas Arbol, Arbusto y Pino, en el
 nivel de herencia adecuado.*/
#include <iostream>
#include <string.h>
using namespace std;

class Planta {
protected:
    char* nombre;
    float tamanio;
    char* especie;
public:
    Planta(char*, float, char*);
    char* obtenerNombre();
    float obtenerTamanio();
    char* obtenerEspecie();
    void cambiarNombre(char*);
    void cambiarTamanio(float);
    void cambiarEspecie(char*);
    void imprimirDatos();
};

Planta::Planta(char* nom, float tam, char* espe)
{
    nombre = new char[strlen(nom) + 1];
    especie = new char[strlen(espe) + 1];

    strcpy(nombre, nom);
    strcpy(especie, espe);
    tamanio = tam;
}

char* Planta::obtenerNombre()
{
    return nombre;
}

float Planta::obtenerTamanio()
{
    return tamanio;
}

char* Planta::obtenerEspecie()
{
    return especie;
}

void Planta::cambiarNombre(char* nom)
{
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
}

void Planta::cambiarTamanio(float tam)
{
    tamanio = tam;
}

void Planta::cambiarEspecie(char* espe)
{
    especie = new char[strlen(espe) + 1];
    strcpy(especie, espe);
}

void Planta::imprimirDatos()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Especie: " << especie << endl;
    cout << "Tamanio: " << tamanio << endl;
}

// Clase derivada Arbol
class Arbol : public Planta {
private:
    char* nomFruto;
public:
    Arbol(char*, float, char*, char*);
    char* obtenerNomFruto();
    void cambiarNomFruto(char* nom);
    void imprimirDatos();
};

Arbol::Arbol(char* nom, float tam, char* espe, char* nomFrut) :
       Planta(nom, tam, espe)
{
    nomFruto = new char[strlen(nomFrut) + 1];
    strcpy(nomFruto, nomFrut);
}

char* Arbol::obtenerNomFruto()
{
    return nomFruto;
}

void Arbol::cambiarNomFruto(char* nomFrut)
{
    nomFruto = new char[strlen(nomFrut) + 1];
    strcpy(nomFruto, nomFrut);
}

void Arbol::imprimirDatos()
{
    Planta::imprimirDatos();
    cout << "Nomb. Fruto: " << nomFruto << endl;
}

// Clase derivada Arbusto
class Arbusto : public Planta {
private:
    bool esRamificado;
public:
    Arbusto(char*, float, char*, bool);
    bool obtenerEsRamificado();
    void cambiarEsRamificado(bool);
    void imprimirDatos();
};

Arbusto::Arbusto(char* nom, float tam, char* espe, bool esRam):
         Planta(nom, tam, espe)
{
    esRamificado = esRam;
}

bool Arbusto::obtenerEsRamificado()
{
    return esRamificado;
}

void Arbusto::cambiarEsRamificado(bool esRam)
{
    esRamificado = esRam;
}

void Arbusto::imprimirDatos()
{
    Planta::imprimirDatos();
    cout << "Es ramificado: " << (esRamificado ? "Si" : "No") << endl;
}

// Clase derivada Pino
class Pino : public Planta {
protected:
    char* nomPinia;
public:
    Pino(char*, float, char*, char*);
    char* obtenerNomPinia();
    void cambiarNomPinia(char*);
    void imprimirDatos();
};

Pino::Pino(char* nom, float tam, char* espe, char* nomPina):
      Planta(nom, tam, espe)
{
    nomPinia = new char[strlen(nomPina) + 1];
    strcpy(nomPinia, nomPina);
}

char* Pino::obtenerNomPinia()
{
    return nomPinia;
}

void Pino::cambiarNomPinia(char* nom)
{
    nomPinia = new char[strlen(nom) + 1];
    strcpy(nomPinia, nom);
}

void Pino::imprimirDatos()
{
    Planta::imprimirDatos();
    cout << "Nombre Pinia: " << nomPinia << endl;
}

int main(){

    Arbol arbol((char*)"Roble", 12.5, (char*)"Arbolae", (char*)"roblecito");
    Arbusto arbusto((char*)"Arbusto", 5.2, (char*)"Arbustae", true);
    Pino pino((char*)"Pino", 40.5, (char*)"Pinacae", (char*)"Piniata");

    arbol.imprimirDatos();
    cout << endl;
    arbusto.imprimirDatos();
    cout << endl;
    pino.imprimirDatos();

    return 0;
}