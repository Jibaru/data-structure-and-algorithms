/* Clase Arbol con algunos atributos y métodos; en la sección pública
se incluyen dos funciones amigas en las cuales se sobrecargan los
operadores de salida y entrada, << y >>. */ 
#include <iostream>
using namespace std;

class Arbol {
protected:
    int Edad;
    double Altura;
    char Nombre[64];
public:
    Arbol();
    void ModificaEdad(int);
    void ModificaAltura(float);
    friend istream &operator>>(istream &, Arbol &);
    friend ostream &operator<<(ostream &, Arbol &);
};

/* Declaración del método constructor por omisión. */
Arbol::Arbol()
{ }

/* Método que modifica la edad de un árbol. */
void Arbol::ModificaEdad(int NuevaE)
{
    Edad= NuevaE;
}

/* Método que modifica la altura de un árbol. */
void Arbol::ModificaAltura(float NuevaA)
{
    Altura= NuevaA;
}

/* Declaración de la función amiga donde se usa el operador >> 
sobrecargado. */
istream &operator>>(istream &Lee, Arbol &ObjArbol)
{
    cout << "\n\nIngrese nombre del arbol: ";
    Lee >> ObjArbol.Nombre;
    cout << "\n\nIngrese altura del arbol: ";
    Lee >> ObjArbol.Altura;
    cout << "\n\nIngrese edad en numero de anios del arbol: ";
    Lee >> ObjArbol.Edad;
    return Lee;
}

/* Declaración de la función amiga donde se usa el operador << 
sobrecargado. */
ostream &operator<<(ostream &Escribe, Arbol &ObjArbol)
{
    cout << "\n\nDatos del arbol: " << endl;
    Escribe << "Nombre: " << ObjArbol.Nombre << endl;
    Escribe << "Altura: " << ObjArbol.Altura << endl;
    Escribe << "Edad: " << ObjArbol.Edad << endl;

    return Escribe;
}

/* Función que usa la clase previamente definida. En esta función puede 
apreciar cómo simplificar la entrada/salida de los datos de un objeto. 
La escritura de las funciones amigas implica más código, sin embargo, 
su uso produce un código más legible. */
void UsaSobreCarga()
{
    Arbol DeMiCampo;
    /* Se usa el operador >> sobrecargado para leer un objeto tipo
    Arbol como si fuera un dato simple. */
    cin >> DeMiCampo;
    DeMiCampo.ModificaAltura(12.5);
    DeMiCampo.ModificaEdad(3);
    /* Se usa el operador << sobrecargado para imprimir un objeto tipo 
    Arbol como si fuera un dato simple. */
    cout << DeMiCampo;
}

int main() {
    UsaSobreCarga();
    return 0;
}
