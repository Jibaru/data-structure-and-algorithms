/* Se define la clase Dinos la cual se usa como base para declarar el 
tipo de datos de un arreglo. En la biblioteca "4.1.cpp" se incluye 
la plantilla de la clase de arreglos desordenados presentada en el 
programa 4.1. La aplicación permite leer los elementos del arreglo, dar 
de alta nuevos dinosaurios, dar de baja dinosaurios registrados e
imprimir todos los datos de los mismos. */
#define MAX 100
#include <string.h>
#include <conio.h>
#include "4.1.cpp"

/* Definición de la clase Dinos. Se sobrecargan operadores para que los 
objetos de esta clase puedan utilizarse directamente en los métodos de 
los arreglos. */
class Dinos {
private:
    int Clave;
    char Nombre[MAX], Alimen[MAX], Periodo[MAX], Region[MAX];
public:
    Dinos();
    Dinos(int , char [], char [],char [],char []);
    int operator!=(Dinos);
    friend istream &operator>>(istream &, Dinos &);
    friend ostream &operator<<(ostream &, Dinos &);
};

/* Definición del método constructor por omisión. */
Dinos::Dinos()
{}

/* Definición del método constructor con parámetros. */
Dinos::Dinos(int Cla, char Nom[], char Ali[],char Per[],char Reg[])
{
    Clave= Cla;
    strcpy(Nombre, Nom); strcpy(Alimen, Ali);
    strcpy(Periodo, Per);
    strcpy(Region, Reg);
}

/* Sobrecarga del operador != para comparar objetos de tipo Dinos.
De esta forma el método de búsqueda en arreglos puede aplicarse también
a objetos de este tipo. */
int Dinos::operator!= (Dinos ObjD)
{
    if ((Clave != ObjD.Clave)||
    (strcmp(Nombre, ObjD.Nombre) != 0) ||
    (strcmp(Alimen, ObjD.Alimen) != 0) ||
    (strcmp(Periodo,ObjD.Periodo) != 0) ||
    (strcmp(Region, ObjD.Region) != 0))
        return 1;
    else
        return 0;
}

/* Sobrecarga del operador >> para permitir la lectura directa de 
objetos de tipo Dinos. De esta forma, el método Lectura de la clase 
Arreglo puede ser usado con objetos de este tipo. */
istream& operator>>(istream& Lee, Dinos& ObjDino)
{
    cout << "\n\nIngrese clave del dinosaurio: ";
    Lee >> ObjDino.Clave;
    cout << "\n\nIngrese nombre del dinosaurio: ";
    Lee >> ObjDino.Nombre;
    cout << "\n\nIngrese tipo de alimentacion del dinosaurio: ";
    Lee >> ObjDino.Alimen;
    cout << "\n\nIngrese periodo en el que vivio el dinosaurio: ";
    Lee >> ObjDino.Periodo;
    cout << "\n\nIngrese region en la que vivio el dinosaurio: ";
    Lee >> ObjDino.Region;
    return Lee;
}

/* Sobrecarga del operador << para permitir la impresión directa de 
objetos de tipo Dinos. De esta forma, el método Escribe de la clase 
Arreglo puede ser usado con objetos de este tipo. */
ostream& operator<<(ostream& Escribe, Dinos& ObjDino)
{
    Escribe << "\n\nDatos del dinosaurio\n";
    Escribe << "\nClave: " << ObjDino.Clave;
    Escribe << "\nNombre: " << ObjDino.Nombre;
    Escribe << "\nAlimentación: " << ObjDino.Alimen;
    Escribe << "\nPeriodo: "<< ObjDino.Periodo;
    Escribe << "\nRegión: "<< ObjDino.Region;
    return Escribe;
}

/* Se define la clase Menú que permite desplegar al usuario las opciones 
de trabajo de la aplicación. */
class Menu {
public:
    Menu();
    int Despliega();
};

/* Definición del método constructor. */
Menu::Menu()
{}

/* Definición del método que muestra las opciones de trabajo. */
int Menu::Despliega()
{
    int Opc;
    do {
        cout << "\n\nBienvenido al sistema del Museo de los Dinosaurios\n\n";
        cout << "\nQue desea hacer?\n";
        cout << "\n1-Registrar un nuevo dinosaurio. ";
        cout << "\n2-Dar de baja un dinosaurio.";
        cout << "\n3-Obtener un listado de todos los dinosaurios registrados.";
        cout << "\n4-Terminar.\n";
        cout << "\n\nIngrese la opcion elegida: ";
        cin >> Opc;
    } while (Opc < 1 || Opc > 4);
    
    return Opc;
}

/* Función principal que hace uso de la plantilla del arreglo y de las 
clases. La aplicación permite al usuario almacenar los datos de varios 
dinosaurios, dar de alta/baja dinosaurios e imprimir los datos de los 
mismos. */
int main ()
{
    Arreglo<Dinos> Parque;
    Dinos ObjDino;
    Menu Opciones;
    int Opc, Res;
    /* Se lee el total de dinosaurios a almacenar y los datos de cada uno 
    de ellos por medio del método Lectura. Para que dicho método pueda 
    ser usado es necesaria la sobrecarga del operador >> en la clase Dinos. */
    Parque.Lectura();
    Opc= Opciones.Despliega();
    while (Opc>= 1 && Opc <= 3)
    {
        switch (Opc)
        {
            /* Se da de alta un dinosaurio si el arreglo tiene espacio y 
            si no se repiten los datos del dinosaurio. Se usa la sobrecarga 
            del operador >>. */
            case 1: {
                cin >> ObjDino;
                Res= Parque.InsertaDesordenado(ObjDino);
                if (Res == 1)
                    cout << "\n\nDinosaurio registrado.\n"; 
                else
                    if (Res = 0)
                        cout << "\n\nNo se tiene espacio para registrar nuevos dinos.\n";
                    else
                        cout << "\n\nEse dinosaurio ya fue registrado previamente. \n";
                break;
            }
            /* Se elimina un dinosaurio si el arreglo no está vacio y si 
            el dinosaurio dado como dato fue registrado previamente. Se 
            usa la sobrecarga del operador >>. */
            case 2: {
                cin >> ObjDino;
                Res= Parque.EliminaDesordenado(ObjDino);
                if (Res = 1)
                    cout<< "\n\nDinosaurio eliminado\n";
                else
                    if (Res == 0)
                        cout << "\n\nNo se tiene registrado ningun dinosaurio.\n";
                    else
                        cout << "\n\nEse dinosaurio no fue registrado. \n";
                break;
            }
            /* Se despliegan en pantalla todos los datos de los 
            dinosaurios almacenados en el arreglo por medio del método 
            Escribe. Para que dicho método pueda ser usado es necesaria 
            la sobrecarga del operador << en la clase Dinos. */
            case 3: {
                Parque.Escribe();
                break;
            }
        }

        getch();

        Opc= Opciones.Despliega();
    }

    return 0;
}
