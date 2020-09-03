/* Ejemplo de una multilista. Se declara una lista de autores, donde 
cada nodo (como parte de la información) tiene una lista de libros. */
#include <iostream>
#include <string.h>
#include <conio.h>

#define MAX 100

using namespace std;

/* Clase Lista dependiente de la clase NodoLista. */
template <class T>
class Lista;

/* Definición de la clase NodoLista. Se incluyeron sólo algunos de los
métodos vistos.*/
template <class T>
class NodoLista
{
private:
    NodoLista<T> *Liga;
    T Info;
public:
    NodoLista();
    T RegresaInfo();
    friend class Lista<T>;
};

/* Declaración del método constructor por omisión. */
template <class T>
NodoLista<T>::NodoLista()
{
    Liga= NULL;
}

/* Regresa la información almacenada en el nodo. */
template <class T>
T NodoLista<T>::RegresaInfo()
{
    return Info;
}

/* Definición de la clase Lista. Es una lista simplemente ligada. */
template <class T>
class Lista {
private:
    NodoLista<T> *Primero;
public:
    Lista ();
    NodoLista<T> *RegresaPrimero();
    void CreaInicio();
    void Imprime(NodoLista<T> *);
    void InsertaInicio(T);
    NodoLista<T> * Busca(T, NodoLista<T> *);
};

/* Declaración del método constructor. */
template <class T>
Lista<T>::Lista()
{
    Primero= NULL;
}

/* Método que regresa la dirección del primer nodo de la lista. */
template <class T>
NodoLista<T> *Lista<T>::RegresaPrimero()
{
    return Primero;
}

/* Método que crea una lista agregando el nuevo nodo al inicio de la
**misma. */
template <class T>
void Lista<T>::CreaInicio()
{
    NodoLista<T> * P;
    T Dato;
    char Resp;

    Primero= new NodoLista<T>();

    cout << "Ingrese la informacion a almacenar: \n";
    cin >> Dato;

    Primero->Info= Dato;
    
    cout << "\nDesea ingresar otro elemento (S/N)? ";
    cin >> Resp;
    while (Resp == 'S' || Resp == 's')
    {
        cout << "Ingrese la informacion: \n";
        cin >> Dato;
        P = new NodoLista<T>();
        P->Info= Dato;
        P->Liga= Primero;
        Primero= P;
        cout<< "\nDesea ingresar otro elemento (S/N)? ";
        cin >> Resp;
    }
}

/* Método que despliega el contenido de la lista. */
template <class T>
void Lista<T>::Imprime(NodoLista<T> *P)
{
    if (P)
    {
        cout << P->Info;
        Imprime(P->Liga);
    }
    cout << "\n";
}

/* Método que inserta un nodo al inicio de la lista. */
template <class T>
void Lista<T>::InsertaInicio(T Dato) 
{
    NodoLista<T> *P;
    P= new NodoLista<T>();
    P->Info= Dato;
    P->Liga= Primero;
    Primero= P;
}

/* Método que busca un nodo dado como referencia en la lista. El método 
recibe como parámetro el elemento a buscar y una variable que almacena 
la dirección de un nodo, inicialmente es la dirección del primero. 
Regresa como resultado la dirección del nodo si lo encuentra y NULL en 
caso contrario. */
template <class T>
NodoLista<T> * Lista<T>::Busca(T Dato, NodoLista<T> *Q)
{
    if (Q)
        if (Q->Info == Dato)
            return Q;
        else
            return Busca(Dato, Q->Liga);
    else
        return NULL;
}

/* Declaración de la clase Libro. Se usará como base para el tipo de 
información de las listas del segundo nivel. */
class Libro {
private:
    char Nombre[MAX], ISBN[MAX];
    int AnioEdic;
public:
    Libro();
    Libro(char [], char [], int);
    int operator == (Libro);
    int operator != (Libro);
    friend istream &operator>>(istream& Lee, Libro&);
    friend ostream &operator<<(ostream& Escribe, Libro&);
};

/* Declaración del método constructor por omisión. */
Libro::Libro()
{}

/* Declaración del método constructor con parámetros. */
Libro::Libro(char Nom[], char Clave[], int AEd)
{
    strcpy(Nombre, Nom);
    strcpy(ISBN, Clave);
    AnioEdic= AEd;
}

/* Sobrecarga del operador == para comparar dos objetos de este tipo. 
Regresa 1 si los libros tienen el mismo nombre y cero en caso 
contrario. */
int Libro::operator == (Libro Lib)
{
    if (strcmp(Nombre, Lib.Nombre) == 0)
        return 1;
    else
        return 0;
}

/* Sobrecarga del operador != para comparar dos objetos de este tipo. 
Regresa 1 si los libros tienen nombres distintos y cero en caso 
contrario. */
int Libro::operator != (Libro Lib)
{
    if (strcmp(Nombre, Lib.Nombre) != 0)
        return 1;
    else
        return 0;
}

/* Declaración de la función amiga en la que se sobrecarga al operador 
de lectura >>, de tal manera que objetos de tipo Libro puedan ser leidos 
directamente. */
istream &operator>>(istream &Lee, Libro &Lib)
{
    cout << "\n\nIngrese nombre del libro:";
    Lee >> Lib.Nombre;
    cout<< "\n\nIngrese ISBN:";
    Lee >> Lib.ISBN;
    cout << "\n\nIngrese anio de edicion:";
    Lee >> Lib.AnioEdic;
    return Lee;
}

/* Declaración de la función amiga en la que se sobrecarga al operador
de impresión <<, de tal manera que objetos de tipo Libro puedan ser 
escritos directamente. */
ostream &operator<< (ostream &Escribe, Libro &Lib)
{
    Escribe << "\n\n\nDatos del libro\n";
    Escribe << "\nNombre: " << Lib.Nombre;
    Escribe << "\nISBN: " << Lib.ISBN;
    Escribe << "\nAnio de edicion: " << Lib.AnioEdic << "\n";
    return Escribe;
}

/* Declaración de la clase Autor. Se usará como tipo base para darle 
valor a la T del atributo Info de los nodos de la lista del primer 
nivel. El atributo Obra es un objeto de tipo Lista, en este caso es
una lista de libros (usando la clase previamente definida). */
class Autor {
private:
    char Nombre[MAX], Nacional[MAX];
    int AnioNac;
    Lista<Libro> Obra;
public:
    Autor();
    Autor(char[]);
    Lista<Libro> RegresaLisLibros();
    int operator == (Autor);
    int operator != (Autor);
    friend istream &operator>>(istream &Lee, Autor &);
    friend ostream &operator<< (ostream &Escribe, Autor &);
};

/* Declaración del método constructor por omisión. */
Autor::Autor()
{}

/* Declaración del método constructor con parámetros. */
Autor::Autor(char Nom[])
{
    strcpy(Nombre, Nom);
}

/* Método que regresa la lista de libros de un autor. */
Lista<Libro> Autor::RegresaLisLibros()
{
    return Obra;
}

/* Sobrecarga del operador = para poder comparar dos objetos de tipo 
Autor. El método regresa 1 si los objetos tienen nombres iguales y 0 en 
caso contrario.*/
int Autor::operator == (Autor Aut)
{
    if (strcmp(Nombre, Aut.Nombre) == 0)
        return 1;
    else
        return 0;
}

/* Sobrecarga del operador != para poder comparar dos objetos de tipo 
Autor. El método regresa 1 si los objetos tienen nombres distintos y 0 
en caso contrario.*/
int Autor::operator != (Autor Aut)
{
    if (strcmp(Nombre, Aut.Nombre) != 0)
        return 1;
    else
        return 0;
}

/* Declaración de la función amiga en la que se sobrecarga al operador 
de lectura <<, de tal manera que objetos de tipo Autor puedan ser 
leidos directamente. */
istream &operator>>(istream &Lee, Autor &VarAut)
{
    cout << "\n\nIngrese nombre del autor:";
    Lee >> VarAut.Nombre;
    cout << "\n\nIngrese nacionalidad del autor:";
    Lee >> VarAut.Nacional;
    cout << "\n\nIngrese anio de nacimiento:";
    Lee >> VarAut.AnioNac;
    cout << "\n\nIngrese los datos de su obra\n";
    VarAut.Obra.CreaInicio();
    return Lee;
}

/* Declaración de la función amiga en la que se sobrecarga al operador 
de impresión <<, de tal manera que objetos de tipo Autor puedan ser 
escritos directamente. */
ostream &operator<< (ostream &Escribe, Autor &VarAut)
{
    Escribe << "\n\nDatos del autor\n\n";
    Escribe << "\nNombre: " << VarAut.Nombre;
    Escribe << "\nNacionalidad: " << VarAut.Nacional;
    Escribe << "\nAnio de nacimiento: " << VarAut.AnioNac << "\n";
    Escribe << "\nDatos de su obra";
    VarAut.Obra.Imprime(VarAut.Obra.RegresaPrimero());
    return Escribe;
}

/* Función auxiliar que despliega en pantalla las opciones de trabajo. */
int Menu ()
{
    int Opc;
    do {
        cout << "\n\nIngrese opcion de trabajo\n";
        cout << "\n(1) Agregar un nuevo autor. ";
        cout << "\n(2) Generar un reporte de todos los autores con sus obras. ";
        cout << "\n(3) Generar un reporte con todos los datos de un cierto autor. ";
        cout << "\n(4) Generar un reporte con la obra de un cierto autor. ";
        cout << "\n(5) Terminar el proceso.";
        cout << "\n\nIngrese la opcion seleccionada: ";
        cin >> Opc;
    } while (Opc < 1 || Opc > 5);
    
    return Opc;
}

/* Función principal. De acuerdo a la opción de trabajo seleccionada por 
el usuario se invoca a los métodos que corresponda. */
int main()
{
    int OpcTrab;
    char NomAut[MAX];
    NodoLista<Autor> * RespBus;
    Lista<Autor> Acervo;
    Lista<Libro> ObraAutor;
    Autor Escritor;

    Acervo.CreaInicio();

    do {
        OpcTrab= Menu();
        switch (OpcTrab)
        {
            case 1: {
                /* Se inserta un nuevo elemento en la lista de 
                autores. */
                cin >> Escritor;
                Acervo.InsertaInicio(Escritor);
                break;
            }
            case 2: {
                /* Se imprime toda la lista. */
                Acervo.Imprime(Acervo.RegresaPrimero());
                break;
            }
            case 3: {
                /* Se imprimen todos los datos de un autor, cuyo 
                nombre proporciona el usuario. */
                cout << "\nIngrese nombre del autor: ";
                cin >> NomAut ;
                Autor AutorAux(NomAut);
                RespBus= Acervo.Busca(AutorAux, Acervo.RegresaPrimero());
                if (RespBus)
                {
                    Autor aux = RespBus->RegresaInfo();
                    cout << aux;
                }
                else
                    cout << "\n\nEse autor no esta registrado. \n\n";
                
                break;
            }
            case 4: {
                /* Se imprimen los datos de todos los libros de un 
                autor, cuyo nombre da el usuario. Se recupera el 
                atributo que fue declarado como una lista, y a éste se 
                le aplica el método de impresión de las listas. */
                cout << "\nIngrese nombre del autor: ";
                cin >> NomAut ;
                Autor AutorAux (NomAut);
                RespBus= Acervo.Busca(AutorAux, Acervo.RegresaPrimero());
                if (RespBus) 
                {
                    ObraAutor= RespBus->RegresaInfo().RegresaLisLibros();
                    ObraAutor.Imprime(ObraAutor.RegresaPrimero());
                }
                else
                    cout << "\n\nEse autor no esta registrado. \n\n";
                break;
            }
            case 5: cout << "\n\nFin del proceso. \n\n";
        }

        getch();

    } while (OpcTrab != 5);

    return 0;
}
