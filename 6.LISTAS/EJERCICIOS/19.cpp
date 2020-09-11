/*
19.	Retome el problema anterior. Ahora considere que cada modelo 
tiene una lista, de tercer nivel, con todas las versiones del mismo: 
económico, con piel, equipados, con quemacocos, etcétera. Deberá 
definir una clase para las versiones. Desarrolle una aplicación, 
escrita en C++, que mediante menús, pueda realizar lo siguiente:
a)	Agregar una nueva marca.
b)	Incorporar un nuevo modelo a una marca registrada.
c)	Agregar una versión a un modelo de una cierta marca.
d)	Eliminar una marca. En este caso se deben eliminar también 
todos los modelos que tiene dicha marca, y de cada modelo se deben 
eliminar todas las versiones.
e)	Eliminar un modelo de una marca registrada. En este caso, 
también se deben eliminar las versiones de dicho modelo.
f)	Eliminar una versión de un modelo de una cierta marca.
g)	Generar un reporte con todas las marcas, sus modelos y las 
distintas versiones de éstos.
h)	Encuentre e imprima la marca que más modelos tiene.
i)	Encuentre e imprima el modelo que más versiones tiene. 
*/
#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

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
    int tamanio();
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

    cout << "Ingrese la informacion a almacenar: \n";
    cin >> Dato;

    Primero->Info= Dato;
    
    cout << "Desea ingresar otro elemento (S/N)? ";
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

/* Método que despliega el contenido de la lista iterativamente. */
template <class T>
void Lista<T>::ImprimeIterativo()
{
    NodoLista<T> *P;
    P= Primero;

    while (P)
    {
        cout<< "\nInformacion: \n"<< P->Info;
        P= P->Liga;
    }
    cout<< "\n";
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
Método que devuelve la cantidad de nodos que existen en la lista
*/
template <class T>
int Lista<T>::tamanio()
{
    int sum = 0;
    if(Primero) {
        NodoLista<T>* aux = Primero;
        while(aux != NULL) {
            sum ++;
            aux = aux->Liga;
        }
    }
    return sum;
}

/*
Clase Version de Modelo
*/
class Version 
{
private:
	char nomVersion[60];
public:
	Version();
	Version(char[]);
	char* regresaNomVersion();
	int operator==(Version&);
	int operator!=(Version&);
	friend istream& operator>>(istream&, Version&);
	friend ostream& operator<<(ostream&, Version&);
};

/*
Constructor vacio
*/
Version::Version()
{}

/*
Constructor con parametros de Version
*/
Version::Version(char nomVersion[])
{
	strcpy(this->nomVersion, nomVersion);
}

/*
Metodo que regresa el nombre de la version
*/
char* Version::regresaNomVersion()
{
	return nomVersion;
}

/*
Sobreescritura del operador ==
*/
int Version::operator==(Version& obj)
{
	return strcmp(nomVersion, obj.nomVersion) == 0;
}

/*
Sobreescritura del operador !=
*/
int Version::operator!=(Version& obj)
{
	return strcmp(nomVersion, obj.nomVersion) != 0;
}

/*
Sobreescritura del operador >>
*/
istream& operator>>(istream& entrada, Version& v)
{
	cout << "Nombre de version: ";
	entrada.ignore();
	entrada.getline(v.nomVersion, 60);
	
	return entrada;
}

/*
Sobreescritura del operador <<
*/
ostream& operator<<(ostream& salida, Version& v)
{
	salida << "Nombre version: " << v.nomVersion << endl;
	return salida;
}

/*
Clase Modelo de auto
*/
class Modelo
{
private:
    char nombre[60];
    float precio;
	Lista<Version>* versiones;
public:
    Modelo();
    Modelo(char[], float);
    Modelo(char[]);
    ~Modelo();
    char* regresaNombre();
    void cambiaNombre(char[]);
    float regresaPrecio();
	Lista<Version>* regresaVersiones();
    int operator==(Modelo&);
    int operator!=(Modelo&);
    friend istream& operator>>(istream&, Modelo&);
    friend ostream& operator<<(ostream&, Modelo&);
};

/*
Constructor vacio
*/
Modelo::Modelo()
{
	versiones = new Lista<Version>();
}

/*
Constructor con parametros
*/
Modelo::Modelo(char nombre[], float precio)
{
    strcpy(this->nombre, nombre);
    this->precio = precio;
	versiones = new Lista<Version>();
}

/*
Constructor con parametros
*/
Modelo::Modelo(char nombre[])
{
	strcpy(this->nombre, nombre);
}

/*
Destructor de Modelo
*/
Modelo::~Modelo()
{
	//delete versiones;
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
void Modelo::cambiaNombre(char nombre[])
{
	strcpy(this->nombre, nombre);
}

/*
Metodo que regresa el precio del modelo
*/
float Modelo::regresaPrecio()
{
    return precio;
}

/*
Metodo que regresa un puntero a la lista de versiones
del modelo
*/
Lista<Version>* Modelo::regresaVersiones()
{
	return versiones;
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
istream& operator>>(istream& entrada, Modelo& m)
{

    cout << "Nombre Modelo: ";
    entrada.ignore();
    entrada.getline(m.nombre, 60);
    cout << "Precio Modelo: ";
    entrada >> m.precio;
	
    m.versiones->CreaInicio();
    return entrada;
}

/*
Sobreescritura del operator <<
*/
ostream& operator<<(ostream& salida, Modelo& m)
{
    salida << "Nombre Modelo: " << m.nombre << endl;
    salida << "Precio Modelo: " << m.precio << endl;
	salida << "Versiones: " << endl;
	m.versiones->ImprimeIterativo();
    return salida;
}

/*
Clase Marca de auto
*/
class Marca 
{
private:
    char nombre[60];
    Lista<Modelo>* modelos;
public:
    Marca();
    Marca(char[]);
    ~Marca();
    char* regresaNombre();
    void cambiaNombre(char[]);
    Lista<Modelo>* regresaModelos();
    int operator==(Marca&);
    int operator!=(Marca&);
    friend istream& operator>>(istream&, Marca&);
    friend ostream& operator<<(ostream&, Marca&);
};

/*
Constructor vacio de Marca
*/
Marca::Marca()
{
    modelos = new Lista<Modelo>();
}

/*
Constructor con parametros
*/
Marca::Marca(char nombre[])
{
	strcpy(this->nombre, nombre);
    modelos = new Lista<Modelo>();
}

/*
Destructor de Marca
*/
Marca::~Marca()
{
	//delete modelos;
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
void Marca::cambiaNombre(char nombre[])
{
	strcpy(this->nombre, nombre);
}

/*
Metodo que devuelve un apuntador a la lista de modelos
de la marca
*/
Lista<Modelo>* Marca::regresaModelos()
{
    return modelos;
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
istream& operator>>(istream& entrada, Marca& m)
{

    std::cout << "Nombre Marca: ";
    entrada.ignore();
    entrada.getline(m.nombre, 60);

    m.modelos->CreaInicio();
    return entrada;
}

/*
Sobreescritura del operator <<
*/
ostream& operator<<(ostream& salida, Marca& m)
{
    salida << "Nombre Marca: " << m.nombre << endl;
    salida << "Modelos: " << endl;
    m.modelos->ImprimeIterativo();
    return salida;
}

int menuOpciones()
{
	int opc;
	
	do {
		cout << "\n1-Agregar nueva marca" << endl;
		cout << "2-Agregar nuevo modelo a marca" << endl;
		cout << "3-Agregar nueva version a modelo de una marca" << endl;
		cout << "4-Eliminar Marca (con sus modelos y versiones)" << endl;
		cout << "5-Eliminar Modelo (con sus versiones) de una marca" << endl;
		cout << "6-Eliminar vesion de un modelo de una marca" << endl;
		cout << "7-Reporte de marcas, modelos y versiones" << endl;
		cout << "8-Marca con mayor cantidad de modelos" << endl;
		cout << "9-Modelo con mayor cantidad de versiones" << endl;
		cout << "10-Salir del sistema" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opc;
		cout << endl;
	} while(opc < 1 || opc > 10);
	
	return opc;
}

int main()
{
	int opc, resp, mayor;
	Lista<Marca> marcas = Lista<Marca>();
	
	// Auxiliares
	Marca marca;
	Modelo modelo;
	Version version;
	char nombreMarca[60], nombreModelo[60], nombreVersion[60];
	Lista<Modelo>* modelosDeMarca;
	Lista<Version> *versionesDeModelo;
	NodoLista<Marca>* nodoMarca, *itMarca;
	NodoLista<Modelo> *nodoModelo, *itModelo;
	NodoLista<Version> *nodoVersion;
	do {
		opc = menuOpciones();
		
		switch(opc) {
			case 1: {
				marca = Marca();
				cout << "Nueva marca: " << endl;
				cin >> marca;
				marcas.InsertaFinal(marca);
				break;
			}
			case 2: {
				cout << "Nombre de marca: ";
                cin.ignore();
                cin.getline(nombreMarca, 60);
                marca = Marca(nombreMarca);
                nodoMarca = marcas.Busca(marca);
                if(nodoMarca) {
                    modelosDeMarca = nodoMarca->RegresaInfo()->regresaModelos();
                    modelo = Modelo();
                    cout << "Nuevo modelo: " << endl;
                    cin >> modelo;
                    modelosDeMarca->InsertaFinal(modelo);
                } else {
                    cout << "No se encontro la marca" << endl;
                }
				break;
			}
			case 3: {
				cout << "Nombre de marca: ";
                cin.ignore();
                cin.getline(nombreMarca, 60);
                marca = Marca(nombreMarca);
                nodoMarca = marcas.Busca(marca);
                if(nodoMarca) {
					modelosDeMarca = nodoMarca->RegresaInfo()->regresaModelos();
                    cout << "Nombre de modelo: ";
					cin.getline(nombreModelo, 60);
					modelo = Modelo(nombreModelo);
					nodoModelo = modelosDeMarca->Busca(modelo);
					if(nodoModelo) {
						versionesDeModelo = nodoModelo->RegresaInfo()->regresaVersiones();
						version = Version();
						cout << "Nueva version: " << endl;
						cin >> version;
						versionesDeModelo->InsertaFinal(version);
					} else {
						cout << "No se encontro el modelo" << endl;
					}
					
                } else {
                    cout << "No se encontro la marca" << endl;
                }
				break;
			}
			case 4: {
				cout << "Nombre de marca a eliminar: ";
                cin.ignore();
                cin.getline(nombreMarca, 60);
                marca = Marca(nombreMarca);

                resp = marcas.EliminaUnNodo(marca);
                switch(resp) {
                    case -1: {
                        cout << "Lista vacia" << endl;
                        break;
                    }
                    case 0: {
                        cout << "No se encontra la marca" << endl;
                        break;
                    }
                    case 1: {
                        cout << "Marca eliminada" << endl;
                        break;
                    }
                }
				break;
			}
			case 5: {
				cout << "Nombre de marca: ";
                cin.ignore();
                cin.getline(nombreMarca, 60);
                marca = Marca(nombreMarca);
                nodoMarca = marcas.Busca(marca);
                if(nodoMarca) {
                    modelosDeMarca = nodoMarca->RegresaInfo()->regresaModelos();
                    cout << "Nombre modelo a eliminar: " << endl;
                    cin.ignore();
                    cin.getline(nombreModelo, 60);
                    modelo = Modelo(nombreModelo);
                    resp = modelosDeMarca->EliminaUnNodo(modelo);
                    switch(resp) {
                        case -1: {
                            cout << "Lista vacia" << endl;
                            break;
                        }
                        case 0: {
                            cout << "No se encontra el modelo" << endl;
                            break;
                        }
                        case 1: {
                            cout << "Modelo eliminado" << endl;
                            break;
                        }
                    }
                } else {
                    cout << "No se encontro la marca" << endl;
                }
				break;
			}
			case 6: {
				cout << "Nombre de marca: ";
                cin.ignore();
                cin.getline(nombreMarca, 60);
                marca = Marca(nombreMarca);
                nodoMarca = marcas.Busca(marca);
                if(nodoMarca) {
                    modelosDeMarca = nodoMarca->RegresaInfo()->regresaModelos();
                    cout << "Nombre de modelo: " << endl;
                    cin.getline(nombreModelo, 60);
                    modelo = Modelo(nombreModelo);
                    nodoModelo = modelosDeMarca->Busca(modelo);
                    if(nodoModelo) {
                        versionesDeModelo = nodoModelo->RegresaInfo()->regresaVersiones();
                        cout << "Nombre de version a eliminar: " << endl;
                        cin.getline(nombreVersion, 60);
                        version = Version(nombreVersion);
                        resp = versionesDeModelo->EliminaUnNodo(version);
                        switch(resp) {
                            case -1: {
                                cout << "Lista vacia" << endl;
                                break;
                            }
                            case 0: {
                                cout << "No se encontra la version" << endl;
                                break;
                            }
                            case 1: {
                                cout << "Version eliminada" << endl;
                                break;
                            }
                        }
                    } else {
                        cout << "No se encontro el modelo" << endl;
                    }
                } else {
                    cout << "No se encontro la marca" << endl;
                }
				break;
			}
			case 7: {
				cout << "Todas las marcas, modelos y versiones:" << endl;
                marcas.ImprimeIterativo();
				break;
			}
			case 8: {
                mayor = -1;
				for(itMarca = marcas.RegresaPrimero();
                    itMarca != NULL;
                    itMarca = itMarca->RegresaSiguiente()) 
                {
                    resp = itMarca->RegresaInfo()->regresaModelos()->tamanio();
                    if(mayor < resp) {
                        mayor = resp;
                        nodoMarca = itMarca;
                    }
                }
                cout << "Marca con mayor cantidad de modelos (" << mayor << "): " << endl;
                cout << *(nodoMarca->RegresaInfo()) << endl;
				break;
			}
			case 9: {
                mayor = -1;
				for(itMarca = marcas.RegresaPrimero();
                    itMarca != NULL;
                    itMarca = itMarca->RegresaSiguiente()) 
                {
                    modelo = Modelo((char*)"", -9999);
                    for(itModelo = itMarca->RegresaInfo()->regresaModelos()->RegresaPrimero();
                        itModelo != NULL;
                        itModelo = itModelo->RegresaSiguiente())
                    {
                        resp = itModelo->RegresaInfo()->regresaVersiones()->tamanio();
                        if(mayor < resp) {
                            mayor = resp;
                            modelo = *(itModelo->RegresaInfo());
                        }
                    }
                }
                cout << "Modelo con la mayor cantidad de versiones (" << mayor << "): " << endl;
                cout << modelo << endl;
				break;
			}
			case 10: {
				cout << "Fin del programa" << endl;
				break;
			}
		}
		getch();
		
	} while(opc != 10);
	
	return opc;
}