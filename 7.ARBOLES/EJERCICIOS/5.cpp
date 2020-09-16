/*
5.	Escriba un método que imprima todos los ascendientes masculinos de 
un individuo cuyos datos genealógicos fueron almacenados en un árbol binario.
*/

#include <iostream>
#include <string.h>
using namespace std;

/* Prototipo de la plantilla de la clase ArbolBinBus. Asi, en la clase 
NodoArbol se podrá hacer referencia a ella. */
class ArbolBinBus;

/* Clase individuo */
class Individuo {
private:
    char nombre[60];
    int edad;
    char genero;
    bool vivo;
public:
    Individuo();
    Individuo(const char[], int, char, bool);
    int operator<(Individuo&);
    int operator>(Individuo&);
    friend ostream& operator<<(ostream&, Individuo&);
    friend class ArbolBinBus;
};

/* Constructor vacio de Individuo */
Individuo::Individuo()
{}

/* Constructor con parámetros de Individuo */
Individuo::Individuo(const char nombre[], int edad, char genero, bool vivo)
{
    strcpy(this->nombre, nombre);
    this->edad = edad;
    this->genero = genero;
    this->vivo = vivo;
}

int Individuo::operator<(Individuo& obj)
{
    return edad < obj.edad;
}

int Individuo::operator>(Individuo& obj)
{
    return edad > obj.edad;
}


ostream& operator<<(ostream& salida, Individuo& obj)
{
    salida << "Nombre: " << obj.nombre << endl;
    salida << "Edad: " << obj.edad << endl;
    salida << "Genero: " << obj.genero << endl;
    salida << "Estado: " << ((obj.vivo) ? "VIVO" : "MUERTO") << endl;
} 



/* Declaración de la clase NodoArbol. Cada nodo almacena la información 
(razón de ser de la estructura tipo árbol) y las direcciones de sus hijos 
izquierdo y derecho. Se incluye una relación de amistad con la clase 
ArbolBinBus para que éste pueda tener acceso a sus miembros privados. */ 
class NodoArbol {
private:
    Individuo Info;
    NodoArbol *HijoIzq;
    NodoArbol *HijoDer;
public:
    NodoArbol();
    Individuo RegresaInfo();
    void ActualizaInfo(Individuo);
    friend class ArbolBinBus;
};

/* Declaración del método constructor por omisión. Inicializa las ligas a 
los subárboles con el valor NULL, indicando que no tiene hijos. */
NodoArbol::NodoArbol()
{
    HijoIzq= NULL;
    HijoDer= NULL;
}

/* Método que regresa la información almacenada en el nodo. */
Individuo NodoArbol::RegresaInfo()
{
    return Info;
}

/* Método para actualizar la información almacenada en el nodo. */
void NodoArbol::ActualizaInfo(Individuo Dato)
{
    Info= Dato ;
}

/* Declaración de la clase ArbolBinBus. Su atributo es un puntero al
*nodo raíz. */
class ArbolBinBus
{
private:
    NodoArbol *Raiz; 
public:
    ArbolBinBus ();
    NodoArbol *RegresaRaiz();
    NodoArbol * Busqueda (NodoArbol *, Individuo);
    void InsertaNodoSinRep (NodoArbol *, Individuo);
    void ImprimeAscendientesMasculinos(NodoArbol *);
    void ImprimeAscendientesMasculinos(Individuo dato);
};

/* Declaración del método constructor. Inicializa el puntero a la raíz 
con el valor NULL, indicando árbol vacío (no tiene nodos). */
ArbolBinBus::ArbolBinBus()
{
    Raiz= NULL;
}

/* Método que regresa el valor del apuntador a la raíz del árbol. */
NodoArbol *ArbolBinBus::RegresaRaiz()
{
    return Raiz;
}

/* Método que busca un dato en un árbol binario de búsqueda. Recibe como 
parámetros un apuntador, que es la dirección del nodo a visitar (la 
primera vez es el apuntador a la raíz) y el dato a buscar. Regresa como 
resultado la dirección del nodo encontrado o el valor NULL, si la búsqueda 
termina con fracaso. */
NodoArbol * ArbolBinBus::Busqueda (NodoArbol *Apunt, Individuo Dato)
{
    if (Apunt)
        if (Dato < Apunt->Info)
            return Busqueda(Apunt->HijoIzq, Dato);
        else
            if (Dato > Apunt->Info)
                return Busqueda(Apunt->HijoDer, Dato);
            else
                return Apunt;
    else
        return NULL;
}

/* Método que inserta un nodo en un árbol binario de búsqueda. Recibe 
como parámetros un apuntador (la primera vez es la raíz del árbol) y 
la información que se quiere almacenar en el nuevo nodo. En esta 
implementación no se permite que haya información duplicada en el 
árbol. */
void ArbolBinBus::InsertaNodoSinRep(NodoArbol *Apunt, Individuo Dato)
{
    NodoArbol *ApAux;
    if (Apunt)
    {
        if (Dato < Apunt->Info)
        {
            InsertaNodoSinRep(Apunt->HijoIzq, Dato);
            Apunt->HijoIzq= Raiz;
        }
        else
            if (Dato > Apunt->Info)
            {
                InsertaNodoSinRep(Apunt->HijoDer, Dato);
                Apunt->HijoDer= Raiz;
            }
        Raiz= Apunt;
    }
    else
    {
        /* Se crea un nuevo nodo, se le asigna la información y se 
        establecen las ligas entre los nodos correspondientes. */
        ApAux= new NodoArbol();
        ApAux->Info= Dato;
        Raiz= ApAux;
    }
}

void ArbolBinBus::ImprimeAscendientesMasculinos(NodoArbol* nodo)
{   
    if(nodo->Info.genero == 'M') {
        cout << endl << nodo->Info << endl;
    }
    if(nodo->HijoIzq != NULL) {
        ImprimeAscendientesMasculinos(nodo->HijoIzq);
    }
    if(nodo->HijoDer != NULL) {
        ImprimeAscendientesMasculinos(nodo->HijoDer);
    }
}

void ArbolBinBus::ImprimeAscendientesMasculinos(Individuo dato)
{
    NodoArbol* nodo = Busqueda(Raiz, dato);
    ImprimeAscendientesMasculinos(nodo);
}

int main() 
{
    ArbolBinBus individuos = ArbolBinBus();

    Individuo ignacio = Individuo("Ignacio", 23, 'M', true);
    Individuo aracely = Individuo("Aracely", 44, 'F', true);
    Individuo valeriano = Individuo("Valeriano", 70, 'M', true);
    Individuo amalia = Individuo("Amalia", 40, 'F', false);
    Individuo jose = Individuo("Jose", 43, 'M', false);
    Individuo hilaria = Individuo("Hilaria", 65, 'F', false);
    Individuo hilario = Individuo("Abuelo hilario", 75, 'M', false);

    individuos.InsertaNodoSinRep(individuos.RegresaRaiz(), ignacio);
    individuos.InsertaNodoSinRep(individuos.RegresaRaiz(), aracely);
    individuos.InsertaNodoSinRep(individuos.RegresaRaiz(), valeriano);

    individuos.InsertaNodoSinRep(individuos.RegresaRaiz(), amalia);
    individuos.InsertaNodoSinRep(individuos.RegresaRaiz(), jose);       

    individuos.InsertaNodoSinRep(individuos.RegresaRaiz(), hilario);
    individuos.InsertaNodoSinRep(individuos.RegresaRaiz(), hilaria);  

    individuos.ImprimeAscendientesMasculinos(Individuo("Ignacio", 23, 'M', true));

    return 0;
}