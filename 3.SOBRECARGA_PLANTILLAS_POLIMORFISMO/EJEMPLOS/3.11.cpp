/* Se declara la clase Volumen que servirá como base para las clases 
derivadas: Libro y Revista. La clase base tiene métodos virtuales que 
serán redefinidos en las clases derivadas. En la clase se define un 
método destructor virtual. Observe que el método virtual Imprimir no se 
define en la clase base, sólo se incluye su prototipo. Luego se define 
la clase Biblioteca que tiene como atributo un arreglo de objetos 
polimórficos. */
#include <iostream>
#include <string.h>
using namespace std;

class Volumen {
protected:
    char *NomVolumen; 
public:
    Volumen();
    Volumen(char *);
    virtual void Imprimir() { }
    virtual ~Volumen();
};

/* Declaración del método constructor por omisión. */
Volumen::Volumen()
{ }

/* Declaración del método constructor con parámetros. */
Volumen::Volumen(char *Nom)
{
    NomVolumen = new char[(strlen(Nom)+1)];
    if (NomVolumen)
        strcpy(NomVolumen, Nom);
}

/* Declaración del método destructor. */
Volumen:: ~Volumen()
{
    delete[] NomVolumen;
}

/* Definición de la clase Libro derivada de la clase Volumen. El 
método Imprimir se define en esta clase. */
class Libro: public Volumen {
private:
    int AnioEd;
public:
    Libro();
    Libro(char *Nom, int);
    void Imprimir();
};

/* Declaración del método constructor por omisión. */
Libro::Libro()
{ }

/* Declaración del método constructor con parámetros. Invoca al método 
constructor de la clase base*/
Libro::Libro(char *Nom, int Anio): Volumen(Nom)
{
    AnioEd= Anio;
}

/* Método que despliega los valores de los atributos de un libro. Observe 
que se imprimen dos atributos uno de los cuales se hereda de la clase Volumen 
y el otro es propio de esta clase. */
void Libro::Imprimir()
{
    cout << "Nombre del Libro: " << NomVolumen << endl;
    cout << "Anio de Edicion del Libro: " << AnioEd << endl;
}

/* Definición de la clase Revista derivada de la clase Volumen. El método Imprimir
se define en esta clase. */
class Revista: public Volumen {
private:
    int Numero;
public:
    Revista();
    Revista(char *, int);
    void Imprimir();
};

/* Declaración del método constructor por omisión. */
Revista::Revista()
{ }

/* Declaración del método constructor con parámetros. Invoca al método 
constructor de la clase base. */
Revista::Revista(char *Nom, int Num): Volumen(Nom)
{
    Numero= Num;
}

/* Método que despliega los valores de los atributos de una revista. 
Observe que se imprimen dos atributos, uno de los cuales se hereda de 
la clase Volumen y el otro es propio de esta clase.*/
void Revista::Imprimir()
{
    cout << "Nombre de la Revista: " << NomVolumen << endl;
    cout << "Numero de la Revista: " << Numero << endl;
}

/* Definición de la clase Biblioteca. Uno de los atributos de la clase 
es un arreglo polimórfico, lo cual da mucha generalidad en el momento 
de almacenar información en él: se pueden guardar objetos de diferentes 
tipos. */
class Biblioteca 
{
private:
    int MaxVolumen, NumVolumen;
    char Nombre[64];
    Volumen *Volumenes[];
public:
    Biblioteca();
    Biblioteca(int, char []);
    void IngresarVolumen(Volumen *);
    void Imprimir();
    ~Biblioteca();
};

/* Declaración del método constructor por omisión. */
Biblioteca::Biblioteca()
{ }

/* Declaración del método constructor con parámetros. */
Biblioteca::Biblioteca(int MaxVol, char Nom[])
{
    int Indice;
    MaxVolumen= MaxVol;
    NumVolumen= 0; strcpy(Nombre, Nom);
    *Volumenes = new Volumen[MaxVolumen];
    /* Se inicializa el arreglo de objetos polimórficos como vacio. */
    for (Indice= 0; Indice < MaxVolumen; Indice++)
        Volumenes[Indice]= NULL;
}

/* Declaración del método destructor. */
Biblioteca::~Biblioteca()
{
    delete[] *Volumenes;
}

/* Método que permite dar de alta un nuevo volumen en la colección de 
volúmenes de la biblioteca. Recibe como parámetro la dirección de un 
objeto de tipo Volumen. */
void Biblioteca::IngresarVolumen(Volumen *Vol)
{
    if (NumVolumen < MaxVolumen)
        Volumenes[NumVolumen++] = Vol;
}

/* Método que despliega los valores de los atributos de los volúmenes 
registrados en la biblioteca. */
void Biblioteca::Imprimir() 
{
    int Indice;
    cout << " Acervo de la biblioteca: " << Nombre << endl;
    if (NumVolumen > 0)
        for (Indice= 0; Indice < NumVolumen; Indice++)
            Volumenes[Indice]->Imprimir();
}

/* Función que usa las clases previamente definidas para crear objetos 
polimórficos. */
void UsaPolimorfismo() {
    /* Se crea un objeto de tipo Biblioteca, el cual podrá almacenar 10 
    volúmenes como máximo. */
    Biblioteca ObjBiblioteca(10, (char*)"Refugio del Conocimiento");

    /* Se crean objetos tipo Libro. */
    Libro ObjLibro1((char*)"Estructuras de Datos", 2006), ObjLibro2((char*)"Aprenda C++", 2005),
    ObjLibro3((char*)"Estudie Ingenieria", 2000);
    
    /* Se crean objetos tipo Revista. */
    Revista ObjRevista1((char*)"Ciencia", 12),
    ObjRevista2((char*)"Computadoras y Accesorios", 110),
    ObjRevista3((char*)"Avances de la Tecnologia", 205);

    /* Se invoca al método que permite asignar las direcciones de los 
    objetos tipo Libro a uno de los miembros del objeto tipo Biblioteca. */
    ObjBiblioteca.IngresarVolumen(&ObjLibro1);
    ObjBiblioteca.IngresarVolumen(&ObjLibro2);
    ObjBiblioteca.IngresarVolumen(&ObjLibro3);

    /* Se invoca al método que permite asignar las direcciones de 
    los objetos tipo Revista a uno de los miembros del objeto tipo Biblioteca. */
    ObjBiblioteca.IngresarVolumen(&ObjRevista1);
    ObjBiblioteca.IngresarVolumen(&ObjRevista2);
    ObjBiblioteca.IngresarVolumen(&ObjRevista3);

    /* Se invoca el método que despliega los valores de los atributos de 
    la biblioteca. Imprime el nombre de la biblioteca y los valores del 
    atributo de cada objeto de acuerdo a la forma que éste tenga. */
    ObjBiblioteca.Imprimir();
}

int main() {
    UsaPolimorfismo();
    return 0;
}
