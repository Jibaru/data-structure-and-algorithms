/* Programa que imprime los datos ascendentes femeninos de un
individuo. Primero forma el árbol genealógico y posteriormente genera
el reporte*/

#include <iostream>
#include <string.h>

using namespace std;

/* Prototipo de la plantilla de la clase ArbolBinario. De esta manera, 
en la clase NodoArbol se podrá hacer referencia a ella. */
template <class T>
class ArbolBinario;

/* Declaración de la clase NodoArbol. Cada nodo almacena la información 
(que es la razón de ser de la estructura tipo árbol) y las direcciones 
de sus hijos izquierdo y derecho. En la sección pública se establece la 
relación de amistad entre esta clase y la clase ArbolBinario para que los 
métodos de esta última puedan tener acceso a sus miembros privados. */
template <class T>
class NodoArbol {
private:
    T Info;
    NodoArbol<T> *HijoIzq;
    NodoArbol<T> *HijoDer;
public:
    NodoArbol();
    T RegresaInfo();
    void ActualizaInfo(T);
    friend class ArbolBinario<T>;
};

/* Declaración del método constructor por omisión. Inicializa las ligas 
a los subárboles con el valor de NULL, indicando que están vacias. */
template <class T>
NodoArbol<T>::NodoArbol()
{
    HijoIzq= NULL;
    HijoDer= NULL;
}

/* Método que permite conocer la información almacenada en el nodo. */
template <class T>
T NodoArbol<T>::RegresaInfo()
{
    return Info ;
}

/* Método para actualizar la información almacenada en el nodo. */
template <class T>
void NodoArbol<T>::ActualizaInfo(T Dato)
{
    Info= Dato ;
}

/* Declaración de la clase ArbolBinario. Su atributo es un puntero al
nodo raíz. */
template <class T>
class ArbolBinario
{
private:
    NodoArbol<T> *Raiz; 
public:
    ArbolBinario ();
    /* En esta sección se declaran los métodos de acceso y 
    modificación a los miembros de la clase. */
    NodoArbol<T> *RegresaRaiz(); 
    void CreaArbol(NodoArbol<T> *);
    void ImprimeIzq(NodoArbol<T> *);
    void Preorden(NodoArbol<T> *);
    void Inorden(NodoArbol<T> *);
    void Postorden(NodoArbol<T> *);
};

/* Declaración del método constructor. Inicializa el puntero a la raíz con 
el valor NULL, indicando que el árbol está vacío (no tiene nodos). */
template <class T>
ArbolBinario<T>::ArbolBinario()
{
    Raiz= NULL;
}

/* Método que regresa el valor del apuntador a la raíz del árbol. */
template <class T>
NodoArbol<T> *ArbolBinario<T>::RegresaRaiz()
{
    return Raiz;
}


/* Plantilla del método que crea un árbol binario. Recibe como parámetro 
un apuntador a un subárbol. La primera vez es la raiz del árbol la cual 
se inicializó con el valor NULL, indicando que el árbol está vacio. */
template <class T>
void ArbolBinario<T>::CreaArbol(NodoArbol<T> *Apunt)
{
    char Resp;
    /* Se crea un nodo. */
    Apunt= new NodoArbol<T>;
    cout << "\n\nIngrese la informacion a almacenar:";
    cin >> Apunt->Info;

    cout << "\n\n" << Apunt->Info << "Tiene hijo izquierdo (S/N)?";
    cin >> Resp;
    if (Resp == 's')
    {
        /* Se invoca al método con el subárbol izquierdo. Se usa la 
        definición recursiva de un árbol. */
        CreaArbol(Apunt->HijoIzq);
        Apunt->HijoIzq= Raiz;
    }

    cout << "\n\n" << Apunt->Info << "Tiene hijo derecho (S/N)? ";
    cin >> Resp;
    if (Resp == 's')
    {
        /* Se invoca al método con el subárbol derecho. Se usa la 
        definición recursiva de un árbol. */
        CreaArbol(Apunt->HijoDer);
        Apunt->HijoDer= Raiz;
    }

    Raiz= Apunt;
}

/* Método que imprime la información almacenada en las raices de todos 
los subárboles izquierdos. La primera vez recibe como dato la raiz del 
árbol. */
template <class T>
void ArbolBinario<T>::ImprimeIzq(NodoArbol<T> *Apunt)
{
    if (Apunt)
    {
        if (Apunt->HijoIzq)
        {
            cout << Apunt->HijoIzq->Info;
            ImprimeIzq(Apunt->HijoIzq);
        }
        ImprimeIzq(Apunt->HijoDer);
    }
}

/* Método que realiza el recorrido preorden de un árbol binario. Se usa 
el recorrido para imprimir la información almacenada en cada uno de sus 
nodos. Recibe como parámetro el nodo a visitar. La primera vez es la 
raíz del árbol, luego será la raiz del subárbol izquierdo y la raiz del 
subárbol derecho y asi hasta llegar a las hojas. */
template <class T>
void ArbolBinario<T>::Preorden(NodoArbol<T> *Apunt)
{
    if (Apunt)
    {
        cout << Apunt->Info << " ";
        Preorden(Apunt->HijoIzq);
        Preorden(Apunt->HijoDer);
    }
}

/* Método que realiza el recorrido inorden de un árbol binario. Se usa 
el recorrido para imprimir la información almacenada en cada uno de sus 
nodos. Recibe como parámetro el nodo a visitar. La primera vez es la 
raiz del árbol, luego será la raiz del subárbol izquierdo y la raíz del 
subárbol derecho y así hasta llegar a las hojas. */
template <class T>
void ArbolBinario<T>::Inorden(NodoArbol<T> *Apunt)
{
    if (Apunt)
    {
        Inorden(Apunt->HijoIzq);
        cout << Apunt->Info << " ";
        Inorden(Apunt->HijoDer);
    }
}

/* Método que realiza el recorrido postorden de un árbol binario. Se usa 
el recorrido para imprimir la información almacenada en cada uno de sus 
nodos. Recibe como parámetro el nodo a visitar. La primera vez es la 
raíz del árbol, luego será la raíz del subárbol izquierdo y la raíz del 
subárbol derecho y así hasta llegar a las hojas. */
template <class T>
void ArbolBinario<T>::Postorden (NodoArbol<T> *Apunt)  
{
    if (Apunt)
    {
        Postorden(Apunt->HijoIzq);
        Postorden(Apunt->HijoDer);
        cout << Apunt->Info << " ";
    }
}

/* Definición de la clase Persona */
class Persona { 
private:
    int AnioNac, Vive;
    char NomPers[64], LugNac[64];
public:
    Persona();
    Persona(int, int, char [], char[]);
    friend istream& operator>> (istream &, Persona &);
    friend ostream& operator<< (ostream &, Persona &);
};

/* Declaración del método constructor por omisión. */
Persona::Persona()
{}

/* Declaración del método constructor con parámetros. */
Persona::Persona(int ANac, int Vi, char NomP[], char LugN[])
{
    AnioNac= ANac;
    Vive= Vi;
    strcpy(NomPers, NomP);
    strcpy(LugNac, LugN);
}

/* Sobrecarga del operador >> para permitir la lectura de objetos tipo 
Persona de manera directa. */
istream & operator>>(istream & Lee, Persona & ObjPers)
{
    cout << "\n\nIngrese nombre de la Persona:";
    Lee >> ObjPers.NomPers;
    cout<<"\n\nIngrese anio de nacimiento:";
    Lee >> ObjPers.AnioNac;
    cout<<"\n\nIngrese lugar de nacimiento:";
    Lee >> ObjPers.LugNac;
    cout<<"\n\nEsta viva?:";
    Lee >> ObjPers .Vive;
    
    return Lee;
}

/* Sobrecarga del operador << para permitir la escritura de objetos tipo 
Persona de manera directa. */
ostream & operator<< (ostream & Escribe, Persona & ObjPers)
{
    Escribe<<"\n\nDatos de la Persona\n";
    Escribe<<"\nNombre: "<< ObjPers .NomPers;
    Escribe<<"\nLugar de nacimiento: " << ObjPers.LugNac;
    Escribe<<"\nAnio de nacimiento: " << ObjPers.AnioNac;

    if (ObjPers.Vive == 1)
        Escribe<<"\nEstá viva.\n";
    else
        Escribe<<"\nNo esta viva.\n";
        
    return Escribe; 
}

/* Función principal. Crea el árbol genealógico de un individuo y 
posteriormente imprime los datos de todos sus ascendientes femeninos. */
int main()
{
    ArbolBinario<Persona> Genealogico;
    Persona Individuo;
    NodoArbol<Persona> *Ap;

    Ap= Genealogico.RegresaRaiz();

    /* Se invoca el método que crea el árbol genealógico. */
    Genealogico.CreaArbol(Ap);
    Ap= Genealogico.RegresaRaiz();

    /* Se recupera la información del individuo. */
    Individuo= Ap->RegresaInfo();
    cout << "\n\n\n------------------------------\n";
    cout << "Los ascendientes femeninos de: \n" << Individuo;
    cout << "\n\n------------------------------\n";

    /* Se invoca el método que imprime los datos de los ascendientes 
    femeninos. */
    Genealogico.ImprimeIzq(Ap);

    return 0;
}
