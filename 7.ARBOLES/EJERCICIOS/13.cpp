/*
13.	Utilice un árbol binario balanceado para almacenar datos relacionados 
a insectos. Para ello defina una clase insecto, con los atributos y 
los métodos que considere necesarios, atendiendo lo que se pide más 
abajo. Cada insecto tendrá una clave, que será el atributo que permita 
que la información esté ordenada en el árbol. Escriba un programa en 
C++, que mediante un menú de opciones, pueda:
a) Registrar un nuevo insecto. El usuario dará todos los datos necesarios.
b)	Dar de baja un insecto registrado. El usuario dará la clave del 
insecto a eliminar.
c)	 Generar un reporte de todos los insectos, ordenados por clave.
d)	 Generar un reporte de todos los insectos que viven en el área del 
Mediterráneo europeo.
e) Generar un reporte de todos los insectos que viven sólo en el desierto 
de Rub al-Jali.
f) Generar un reporte de todos los insectos que se alimentan de 
madera en estado de descomposición.
*/
#include <iostream>
#include <conio.h>
#include <string.h>
#include "../../lib/arreglos/Arreglo.h"
#include "../../lib/arboles/ArbolBalanceado.h"

using namespace std;

class Insecto 
{
private:
    int clave;
    char nombre[60];
    char habitat[60];
    char alimento[60];
public:
    Insecto();
    Insecto(int);
    int regresaClave();
    char* regresaHabitat();
    char* regresaAlimento();
    int operator<(Insecto&);
    int operator>(Insecto&);
    int operator==(Insecto&);
    friend ostream& operator<<(ostream&, Insecto&);
    friend istream& operator>>(istream&, Insecto&);
};

Insecto::Insecto() {}

Insecto::Insecto(int clave)
{
    this->clave = clave;
}

int Insecto::regresaClave()
{
    return clave;
}

char* Insecto::regresaHabitat()
{
    return habitat;
}

char* Insecto::regresaAlimento()
{
    return alimento;
}

int Insecto::operator<(Insecto& obj)
{
    return clave < obj.clave;
}

int Insecto::operator>(Insecto& obj)
{
    return clave > obj.clave;
}

int Insecto::operator==(Insecto& obj)
{
    return clave == obj.clave;
}

ostream& operator<<(ostream& salida, Insecto& obj)
{
    salida << "Clave: " << obj.clave << endl;
    salida << "Nombre: " << obj.nombre << endl;
    salida << "Habitat: " << obj.habitat << endl;
    salida << "Alimento: " << obj.alimento << endl;
    return salida;
}

istream& operator>>(istream& entrada, Insecto& obj)
{
    cout << "Clave: ";
    entrada >> obj.clave;
    cout << "Nombre: ";
    entrada.ignore();
    entrada.getline(obj.nombre, 60);
    cout << "Habitat: ";
    entrada.getline(obj.habitat, 60);
    cout << "Alimento: ";
    entrada.getline(obj.alimento, 60);

    return entrada;
}

int menuOpciones()
{
    int opc;
    do {
        cout << "\n1-Registrar un nuevo insecto" << endl;
        cout << "2-Dar de baja un insecto registrado" << endl;
        cout << "3-Reporte de todos los insectos" << endl;
        cout << "4-Insectos del area mediterraneo" << endl;
        cout << "5-Insectos del desierto de Rub al-jali" << endl;
        cout << "6-Insectos que se alimentan de madera en descomposicion" << endl;
        cout << "7-Salir del sistema" << endl;
        cout << "Ingrese opcion: ";
        cin >> opc;
        cout << endl;
    } while(opc < 1 || opc > 7);
    return opc;
}

int main()
{
    int opc, band, clave, i;
    Arreglo<int> claves = Arreglo<int>();
    ArbolBalanceado<Insecto> insectos = ArbolBalanceado<Insecto>();
    Insecto insecto;
    NodoArbolBal<Insecto> *nodoInsecto;
    do {
        opc = menuOpciones();

        switch(opc) {
            case 1: {
                insecto = Insecto();
                band = 0;
                cin >> insecto;
                if(insectos.Busca(insectos.RegresaRaiz(), insecto) == NULL) {
                    insectos.InsertaBalanceado(insecto, insectos.RegresaRaiz(), &band);
                    claves.insertarSinRep(insecto.regresaClave());
                    cout << "Insecto registrado" << endl;
                } else {
                    cout << "Insecto con esa clave ya existe" << endl;
                }
                break;
            }
            case 2: {
                cout << "Clave del insecto a eliminar: ";
                cin >> clave;
                insecto = Insecto(clave);
                band = 0;
                
                if(insectos.Busca(insectos.RegresaRaiz(), insecto) != NULL) {
                    insectos.EliminaBalanceado(insectos.RegresaRaiz(), NULL, &band, insecto);
                    claves.eliminar(insecto.regresaClave());
                    cout << "Insecto dado de baja" << endl;
                } else {
                    cout << "Insecto con esa clave no existe" << endl;
                }
                break;
            }
            case 3: {
                insectos.Imprime(insectos.RegresaRaiz());
                break;
            }
            case 4: {
                for(i = 0; i < claves.tamanio(); i++) {
                    insecto = Insecto(*(claves.obtener(i)));
                    nodoInsecto = insectos.Busca(insectos.RegresaRaiz(), insecto);
                    insecto = nodoInsecto->RegresaInfo();
                    if(strcmp(insecto.regresaHabitat(), "mediterraneo") == 0) {
                        cout << insecto;
                    }
                }
                break;
            }
            case 5: {
                for(i = 0; i < claves.tamanio(); i++) {
                    insecto = Insecto(*(claves.obtener(i)));
                    nodoInsecto = insectos.Busca(insectos.RegresaRaiz(), insecto);
                    insecto = nodoInsecto->RegresaInfo();
                    if(strcmp(insecto.regresaHabitat(), "rub al-jali") == 0) {
                        cout << insecto;
                    }
                }
                break;
            }
            case 6: {
                for(i = 0; i < claves.tamanio(); i++) {
                    insecto = Insecto(*(claves.obtener(i)));
                    nodoInsecto = insectos.Busca(insectos.RegresaRaiz(), insecto);
                    insecto = nodoInsecto->RegresaInfo();
                    if(strcmp(insecto.regresaAlimento(), "madera descompuesta") == 0) {
                        cout << insecto;
                    }
                }
                break;
            }
            case 7: {
                cout << "Fin del programa" << endl;
                break;
            }
        }

        getch();
    } while(opc != 7);

    return 0;
}