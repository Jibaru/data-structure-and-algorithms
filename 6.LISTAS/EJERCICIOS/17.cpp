/*
17. Observe el siguiente esquema. Diseñe una estructura de datos que pueda 
representar los datos y las relaciones entre ellos de manera adecuada. 
Defina una clase para las marcas y otra para los modelos.

Primer Nivel(Marcas): Primero->Audi->...->...->(Último)->NULL
Segundo Nivel(Modelos): Audi->A3->A4->NULL ...->...->NULL ...->NULL
*/
#include <iostream>
#include <string.h>

/* Prototipo de la plantilla de la clase Lista. Asi, en la clase NodoLista 
se podrá hacer referencia a ella. */
template <class T>
class Lista;

/* Definición de la clase NodoLista. */
template <class T>
class NodoLista {
private:
    NodoLista<T> *Liga;
    T Info;
public:
    NodoLista();
    T* RegresaInfo();
    NodoLista<T>* RegresaSiguiente();
    friend class Lista<T>;
};

template <class T>
class Lista {
private:
    NodoLista<T> *Primero;
public:
    Lista();
    ~Lista();
    NodoLista<T> * RegresaPrimero();
    void CreaInicio();
    void ImprimeIterativo();
    void InsertaFinal(T);
    int EliminaUnNodo(T);
    NodoLista<T> * Busca(T);
};

/* Declaración del método constructor por omisión. Inicializa con el 
valor NULL al puntero al siguiente nodo. */
template <class T>
NodoLista<T>::NodoLista()
{
    Liga= NULL;
}

/* Método que permite, a usuarios ajenos a la clase, conocer el valor 
del atributo Info. */
template <class T>
T* NodoLista<T>::RegresaInfo()
{
    return &Info;
}

/* Método que permite, a usuarios ajenos a la clase, conocer el valor 
del nodo siguiente. */
template <class T>
NodoLista<T>* NodoLista<T>::RegresaSiguiente()
{
    return Liga;
}

/* Declaración del método constructor. Inicializa el puntero al primer 
nodo de la lista con el valor NULL: indica lista vacia. */
template <class T>
Lista<T>::Lista()
{
    Primero= NULL;
}

/*
Declaración del metodo destructor de la lista
*/
template <class T>
Lista<T>::~Lista()
{
	NodoLista<T>* aux;
	while(Primero) {
		aux = Primero;
		Primero = Primero->Liga;
		delete aux;
	}
}


/* Método que regresa la dirección del primer nodo de la lista. */
template <class T>
NodoLista<T> * Lista<T>::RegresaPrimero()
{
    return Primero;
}

/* Método que crea una lista agregando el nuevo nodo al inicio de la
*misma. */
template <class T>
void Lista<T>::CreaInicio()
{
    NodoLista<T> * P;
    T Dato; char Resp;

    Primero= new NodoLista<T>();

    std::cout << "Ingrese la informacion a almacenar: \n";
    std::cin >> Dato;

    Primero->Info= Dato;
    
    std::cout << "Desea ingresar otro elemento (S/N)? ";
    std::cin >> Resp;
    while (Resp == 'S' || Resp == 's')
    {
        std::cout << "Ingrese la informacion: \n";
        std::cin >> Dato;
        P = new NodoLista<T>();
        P->Info= Dato;
        P->Liga= Primero;
        Primero= P;
        std::cout<< "\nDesea ingresar otro elemento (S/N)? ";
        std::cin >> Resp;
    }
}

/* Método que despliega el contenido de la lista iterativamente. */
template <class T>
void Lista<T>::ImprimeIterativo()
{
    NodoLista<T> *P;
    P= Primero;

    while (P)
    {
        std::cout<< "\nInformacion: "<< P->Info;
        P= P->Liga;
    }
    std::cout<< "\n";
}

/* Método que inserta un nodo al final de la lista. El método es válido 
tanto para listas ya creadas como para listas vacias. */
template <class T>
void Lista<T>::InsertaFinal(T Dato)
{
    NodoLista<T> *P, *Ultimo;
    P= new NodoLista<T>();
    P->Info= Dato;
    if (Primero)
    {
        /* Si la lista tiene al menos un elemento, entonces se debe 
        recorrer hasta llegar al último nodo. */
        Ultimo= Primero;

        while (Ultimo->Liga)
            Ultimo= Ultimo->Liga;

        /* El último nodo de la lista apunta al nuevo nodo, cuya 
        dirección está en P. */
        Ultimo->Liga= P;
    }
    else
    {
        /* Si la lista no tiene elementos, entonces el nuevo elemento 
        será el primero de la misma. */
        Primero= P;
    }
    std::cout << "Primero: " << Primero->Info << std::endl;
}

/* Método que elimina un nodo que almacena cierta información. Recibe 
como parámetro el dato a eliminar y regresa como resultado 1 si lo 
elimina, 0 si no lo encuentra y -1 si la lista está vacia. */
template <class T>
int Lista<T>::EliminaUnNodo(T Ref)
{
    NodoLista<T> *P, *Ant; int Resp= 1;
    if (Primero)
    {
        P= Primero;
        while ((P->Liga) && (P->Info != Ref))
        {
            Ant= P;
            P= P->Liga;
        }
        if (P->Info != Ref)
        {
            /* El elemento no fue encontrado. */
            Resp= 0;
        }
        else
        {
            if (Primero == P)
                Primero= P->Liga;
            else
            {
                Ant->Liga= P->Liga;
                delete (P);
            }
        }
    }
    else
        Resp= -1;
    
    return Resp;
}

/* Método que busca un elemento dado referencia en una lista desordenada. 
Regresa la dirección del nodo si lo encuentra y NULL en caso contrario. */
template <class T>
NodoLista<T> * Lista<T>::Busca(T Ref)
{
    NodoLista<T> * Q, *Resp= NULL;
    if (Primero)
    {
        Q= Primero;
        while ((Q->Info != Ref) && (Q->Liga))
            Q= Q->Liga;
        
        /* Se verifica si el elemento dado como referencia fue encontrado 
        en la lista. */
        if (Q->Info == Ref)
            Resp= Q;
    }

    return Resp;
}

/*
Clase Modelo de auto
*/
class Modelo
{
private:
    char* nombre;
    float precio;
public:
    Modelo();
    Modelo(char*, float);
    Modelo(char*);
    ~Modelo();
    char* regresaNombre();
    void cambiaNombre(char*);
    float regresaPrecio();
    int operator==(Modelo&);
    int operator!=(Modelo&);
    friend std::istream& operator>>(std::istream&, Modelo&);
    friend std::ostream& operator<<(std::ostream&, Modelo&);
};

/*
Constructor vacio
*/
Modelo::Modelo()
{
    nombre = NULL;
}

/*
Constructor con parametros
*/
Modelo::Modelo(char* nombre, float precio)
{
    if(this->nombre) {
        delete this->nombre;
    }

    this->nombre = new char[strlen(nombre) + 1];
    if(this->nombre != NULL) {
        strcpy(this->nombre, nombre);
    }
    this->precio = precio;
}

/*
Constructor con parametros
*/
Modelo::Modelo(char* nombre)
{
    if(this->nombre) {
        delete this->nombre;
    }

    this->nombre = new char[strlen(nombre) + 1];
    if(this->nombre != NULL) {
        strcpy(this->nombre, nombre);
    }

}

/*
Destructor de Modelo
*/
Modelo::~Modelo()
{
    if(nombre) {
        delete nombre;
    }
}

/*
Metodo que regresa el nombre del modelo
*/
char* Modelo::regresaNombre()
{
    return nombre;
}

/*
Metodo que permite cambiar el nombre del modelo
*/
void Modelo::cambiaNombre(char* nombre)
{
    if(this->nombre) {
        delete this->nombre;
    }

    this->nombre = new char[strlen(nombre) + 1];
    if(this->nombre != NULL) {
        strcpy(this->nombre, nombre);
    }
}

/*
Metodo que regresa el precio del modelo
*/
float Modelo::regresaPrecio()
{
    return precio;
}

/*
Sobreescritura del operator ==
*/
int Modelo::operator==(Modelo& obj)
{
    return (strcmp(nombre, obj.nombre) == 0);
}

/*
Sobreescritura del operator !=
*/
int Modelo::operator!=(Modelo& obj)
{
    return (strcmp(nombre, obj.nombre) != 0);
}

/*
Sobreescritura del operator >>
*/
std::istream& operator>>(std::istream& entrada, Modelo& m)
{
    char nomAux[60];
    std::cout << "Nombre Modelo: ";
    entrada.ignore();
    entrada.getline(nomAux, 60);
    m.cambiaNombre(nomAux);
    std::cout << "Precio Modelo: ";
    entrada >> m.precio;
    
    return entrada;
}

/*
Sobreescritura del operator <<
*/
std::ostream& operator<<(std::ostream& salida, Modelo& m)
{
    salida << "Nombre Modelo: " << m.nombre << std::endl;
    salida << "Precio Modelo: " << m.precio << std::endl;
    return salida;
}

/*
Clase Marca de auto
*/
class Marca 
{
private:
    char* nombre;
    Lista<Modelo> modelos;
public:
    Marca();
    Marca(char*);
    ~Marca();
    char* regresaNombre();
    void cambiaNombre(char*);
    Lista<Modelo>* regresaModelos();
    int operator==(Marca&);
    int operator!=(Marca&);
    friend std::istream& operator>>(std::istream&, Marca&);
    friend std::ostream& operator<<(std::ostream&, Marca&);
};

/*
Constructor vacio de Marca
*/
Marca::Marca()
{
    nombre = NULL;
    modelos = Lista<Modelo>();
}

/*
Constructor con parametros
*/
Marca::Marca(char* nombre)
{
    if(this->nombre) {
        delete this->nombre;
    }

    this->nombre = new char[strlen(nombre) + 1];
    if(this->nombre != NULL) {
        strcpy(this->nombre, nombre);
    }
    modelos = Lista<Modelo>();
}

/*
Destructor de Marca
*/
Marca::~Marca()
{
    if(nombre){
        delete nombre;
    }
}

/*
Metodo que regresa el nombre del Marca
*/
char* Marca::regresaNombre()
{
    return nombre;
}

/*
Metodo que permite cambiar el nombre del Marca
*/
void Marca::cambiaNombre(char* nombre)
{
    if(this->nombre) {
        delete this->nombre;
    }

    this->nombre = new char[strlen(nombre) + 1];
    if(this->nombre != NULL) {
        strcpy(this->nombre, nombre);
    }
}

/*
Metodo que devuelve un apuntador a la lista de modelos
de la marca
*/
Lista<Modelo>* Marca::regresaModelos()
{
    return &modelos;
}

/*
Sobreescritura del operator ==
*/
int Marca::operator==(Marca& obj)
{
    return (strcmp(nombre, obj.nombre) == 0);
}

/*
Sobreescritura del operator !=
*/
int Marca::operator!=(Marca& obj)
{
    return (strcmp(nombre, obj.nombre) != 0);
}

/*
Sobreescritura del operator >>
*/
std::istream& operator>>(std::istream& entrada, Marca& m)
{
    char nomAux[60];
    std::cout << "Nombre Marca: ";
    entrada.ignore();
    entrada.getline(nomAux, 60);
    m.cambiaNombre(nomAux);
    
    //m.modelos.CreaInicio();
    
    return entrada;
}

/*
Sobreescritura del operator <<
*/
std::ostream& operator<<(std::ostream& salida, Marca& m)
{
    salida << "Nombre Marca: " << m.nombre << std::endl;
    //salida << "Modelos: " << std::endl;
    //m.modelos.ImprimeIterativo();
    return salida;
}