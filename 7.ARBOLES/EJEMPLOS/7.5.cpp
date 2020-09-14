#include <iostream>
#include <string.h>
using namespace std;

/* Definición de la clase Fabrica. Se incluyen varios operadores 
sobrecargados para que puedan ser utilizados por los métodos de la 
clase ArbolBalanceado. Asimismo, se declaran como amigos los operadores 
de entrada (>>) y de salida (<<) para que objetos de este tipo puedan 
leerse e imprimirse directamente con cin y cout respectivamente. */
#define MAX 60

class Fabrica {
private:
    int Clave;
    char Nombre[MAX], Domicilio[MAX], Telefono[MAX];
public:
    Fabrica();
    Fabrica(int, char [], char[], char[]);
    void CambiaDomic(char[]);
    void CambiaTelef(char[]);
    int operator>(Fabrica);
    int operator<(Fabrica);
    int operator==(Fabrica);
    friend istream& operator>> (istream & , Fabrica &);
    friend ostream& operator<< (ostream & , Fabrica &);
};

/* Declaración del método constructor por omisión. */
Fabrica::Fabrica()
{}

/* Declaración del método constructor con parámetros. */
Fabrica::Fabrica(int Cla, char Nom[], char Domic[], char Tel[])
{
    Clave= Cla;
    strcpy(Nombre, Nom);
    strcpy(Domicilio, Domic);
    strcpy(Telefono, Tel);
}

/* Método que actualiza el domicilio de una fábrica. */
void Fabrica::CambiaDomic(char NuevoDom[])
{
    strcpy(Domicilio, NuevoDom);
}

/* Método que actualiza el teléfono de una fábrica. */
void Fabrica::CambiaTelef(char NuevoTel[])
{
    strcpy(Telefono, NuevoTel);
}

/* Sobrecarga del operador > lo cual permite comparar dos objetos tipo 
Fabrica. La comparación se hace teniendo en cuenta solamente la clave. */
int Fabrica::operator > (Fabrica ObjFab)
{
    if (Clave > ObjFab.Clave)
        return 1;
    else
        return 0;
}

/* Sobrecarga del operador < lo cual permite comparar dos objetos tipo 
Fabrica. La comparación se hace teniendo en cuenta solamente la clave. */
int Fabrica::operator < (Fabrica ObjFab)
{
    if (Clave < ObjFab.Clave)
        return 1;
    else
        return 0;
}

/* Sobrecarga del operador = lo cual permite comparar dos objetos tipo 
Fabrica. La comparación se hace teniendo en cuenta solamente la clave. */
int Fabrica::operator == (Fabrica ObjFab)
{
    if (Clave == ObjFab.Clave)
        return 1;
    else
        return 0;
}

/* Sobrecarga del operador >> para permitir la lectura de objetos de 
tipo Fabrica de manera directa con el cin. */
istream & operator>> (istream & Lee, Fabrica & ObjFab)
{
    cout << "\n\nIngrese nombre de la fabrica:";
    Lee >> ObjFab.Nombre;
    cout << "\n\nIngrese clave de la fabrica:";
    Lee >> ObjFab.Clave;
    cout<<"\n\nIngrese domicilio de la fabrica:";
    Lee >> ObjFab.Domicilio;
    cout << "\n\nIngrese telefono de la fabrica:";
    Lee >> ObjFab.Telefono;
    return Lee;
}

/* Sobrecarga del operador << para permitir la impresión de objetos de
tipo Fabrica de manera directa con el cout. */
ostream & operator<<(ostream & Escribe, Fabrica & ObjFab)
{
    cout << "\n\nDatos de la fábrica\n";
    Escribe << "Nombre: " << ObjFab.Nombre << endl;
    Escribe << "Clave: " << ObjFab.Clave << endl;
    Escribe << "Domicilio: " << ObjFab.Domicilio << endl;
    Escribe << "Telófono: " << ObjFab.Telefono << endl;
    
    return Escribe;
}
