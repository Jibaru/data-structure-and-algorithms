/* Se declara la clase Árbol que será superclase de la clase Frutal. 
De ésta, a su vez, se derivará la clase Cítrico. Por lo tanto, esta 
última hereda los miembros de las dos anteriores. Con esta relación de 
herencia, se expresa que un objeto tipo Cítrico, es además del tipo Frutal y también un Árbol.*/
/* Definición de la clase Arbol. */
#include <iostream>
#include <string.h>
using namespace std;

class Arbol {
protected: 
    int Edad;
    double Altura;
    char Nombre[64];
public:
    Arbol(int Ed, double Alt, char *Nom);
    void ImprimeArbol();
};


/* Declaración del método constructor con parámetros. Asigna valores a 
los atributos. */
Arbol::Arbol(int Ed, double Alt, char *Nom)
{
    Edad= Ed;
    Altura= Alt;
    strcpy(Nombre, Nom);
}

/* Imprime los valores de los atributos de un árbol. */
void Arbol::ImprimeArbol()
{
    cout << "Nombre: " << Nombre << endl;
    cout << "Edad: " << Edad << endl;
    cout << "Altura: " <<  Altura << endl;
}

/* Primer nivel de herencia: declaración de la clase Frutal como clase 
derivada de la clase Arbol.*/
class Frutal: public Arbol
{
protected:
    char EstacionFruto[64];
public:
    Frutal(int Ed, double Alt, char *Nom, char *EstFr);
    void ImprimeFrutal();
};

/* Declaración del método constructor. Invoca al método constructor de 
la clase base. */
Frutal::Frutal(int Ed, double Alt, char *Nom, char *EstFr):
        Arbol (Ed, Alt, Nom)
{
    strcpy(EstacionFruto, EstFr);
}

/* Método que despliega los valores de los atributos de un árbol frutal. */ 
void Frutal::ImprimeFrutal()
{
    Arbol::ImprimeArbol();
    cout << " Estación del año en la que da frutos: " << EstacionFruto << endl;
}
/* Segundo nivel de herencia: definición de la clase Cítrico como derivada
de la clase Frutal. */
class Citrico: public Frutal {
private:
    char NombreCitrico[64];
public:
    Citrico (int Ed, double Alt, char *Nom, char *EstFr, char *NomCit);
    void ImprimeCitrico();
};

/* Declaración del método constructor. Invoca al método constructor de 
la clase base. */
Citrico::Citrico(int Ed, double Alt, char *Nom, char *EstFr, char *NomCit):
        Frutal (Ed, Alt, Nom, EstFr)
{
    strcpy(NombreCitrico, NomCit);
}


/* Método que despliega los valores de los atributos de un citrico. */
void Citrico::ImprimeCitrico()
{
    Frutal::ImprimeFrutal();
    cout << "Nombre del Cítrico: " << NombreCitrico << endl;
}

/* Función que usa las clases definidas previamente en las cuales existe 
una relación de herencia de niveles múltiples: crea objetos e imprime
el valor de sus atributos. */
void UsaHerencia()
{
    Arbol ObjArbol(2, 3.55, "Álamo");
    Frutal ObjFrutal(3, 2.56, "Manzano", "Otoño");
    Citrico ObjCitrico(1, 2.22, "Limonero", "Invierno", "Limón");
    ObjArbol.ImprimeArbol();
    ObjFrutal.ImprimeFrutal();
    ObjCitrico.ImprimeCitrico();
}
