/* Se define la clase Fabricante. Luego se define la plantilla de la 
clase Producto que tiene un atributo, SeCompraA, que es un objeto de tipo T.
En el ejemplo, primero toma el tipo Fabricante y luego el tipo 
int. Por lo tanto, en el primer caso se tendrá que un atributo de la clase 
es, a su vez, un objeto, y en el segundo caso, el atributo representará 
una clave numérica que identificará a un proveedor. Para que los métodos 
de la segunda clase puedan utilizarse indistintamente con números o con 
objetos se deben sobrecargar los operadores >> y <<. */
#include <iostream>
#include <string.h>
using namespace std;

#define MAX 64
class Fabricante
{
private:
    char Nombre[MAX], Domicilio[MAX], Telefono[MAX];
public:
    Fabricante();
    Fabricante(char [], char [], char []);
    void CambiaDomic(char []);
    void CambiaTelef(char []);
    friend istream &operator>>(istream &, Fabricante &);
    friend ostream &operator<<(ostream &, Fabricante &);
};

/* Definición del método constructor por omisión. */
Fabricante::Fabricante()
{}

/* Definición del método constructor con parámetros. */
Fabricante::Fabricante(char Nom[], char Domic[], char Tel[])
{
    strcpy(Nombre, Nom);
    strcpy(Domicilio, Domic);
    strcpy(Telefono, Tel);
}

/* Declaración del método que permite actualizar el domicilio de un 
fabricante. */
void Fabricante::CambiaDomic(char NuevoDom[])
{
    strcpy(Domicilio, NuevoDom);
}

/* Declaración del método que permite actualizar el teléfono de un 
fabricante. */
void Fabricante::CambiaTelef(char NuevoTel[])
{
    strcpy(Telefono, NuevoTel);
}

/* Definición de la sobrecarga del operador >>. */
istream &operator>>(istream &Lee, Fabricante &ObjFab)
{
    cout << "\n\nIngrese nombre del fabricante: ";
    Lee >> ObjFab.Nombre;
    cout << "\n\nIngrese domicilio del fabricante: ";
    Lee >> ObjFab.Domicilio;
    cout << "\n\nIngrese telefono del fabricante: ";
    Lee >> ObjFab.Telefono;
    return Lee;
}

/* Definición de la sobrecarga del operador <<. */
ostream &operator<<(ostream &Escribe, Fabricante &ObjFab)
{
    cout << "\n\nDatos del fabricante\n ";
    Escribe << "Nombre: " << ObjFab.Nombre << endl;
    Escribe << "Domicilio: " << ObjFab.Domicilio << endl;
    Escribe << "Telefono: " << ObjFab.Telefono << endl;
    return Escribe;
}

/* Definición de la plantilla de la clase Producto. */
template <class T>
class Producto {
private:
    int Clave;
    char Nombre[MAX];
    float Precio;
    T SeCompraA;
public:
    Producto();
    Producto(int, char [], float, T);
    void Imprime();
    void ActualizaPrecio(float );
};
/* Definición de la plantilla del método constructor por omisión. */
template <class T>
Producto<T>::Producto()
{}
/* Definición de la plantilla del método constructor con parámetros. */
template <class T>
Producto<T>::Producto(int Cla, char Nom[], float Pre, T Provee)
{
    Clave= Cla; strcpy(Nombre, Nom);
    Precio= Pre;
    SeCompraA= Provee;
}

/* Definición de la plantilla del método que despliega en pantalla los
valores de los atributos. */
template <class T>
void Producto<T>::Imprime()
{
    cout << "\n\nDatos del producto\n\n";
    cout << "\nClave: " << Clave;
    cout << "\nNombre: " << Nombre;
    cout << "\nPrecio: " << Precio;
    cout << "\nProvisto por: " << SeCompraA << endl;
}

/* Definición de la plantilla del método que actualiza el valor del 
precio de un producto. */
template <class T>
void Producto<T>::ActualizaPrecio(float NuevoPre)
{
    Precio= NuevoPre;
}

/* Función que utiliza la plantilla de la clase Producto, usando la 
clase Fabricante y el tipo int para darle valor a T. La aplicación 
es muy simple: se declaran y crean objetos del tipo Producto usando 
los tipos ya mencionados. */
void FuncionUsaPlantilla(){
    Fabricante CablesMexico;
    int ClaProveedor;
    /* Se lee un objeto de tipo Fabricante, usando el operador
    sobrecargado >>. */
    cin >> CablesMexico;
    /* Se crea un objeto de tipo Producto, reemplazando el tipo T por un 
    objeto de tipo Fabricante. */
    Producto<Fabricante> CableTel(1050, (char*)"Cable telefonico", 100, CablesMexico);
    CableTel.Imprime();
    CableTel.ActualizaPrecio(105);
    cout << "\n\nIngrese la clave del proveedor de las cajas concentradoras: ";
    cin >> ClaProveedor;
    /* Se crea un objeto de tipo Producto, reemplazando el tipo T por 
    int. */
    Producto<int> Cajas (2600, (char*)"Cajas concentradoras", 450, ClaProveedor);
    Cajas.Imprime();
}

int main() {
    FuncionUsaPlantilla();
    return 0;
}