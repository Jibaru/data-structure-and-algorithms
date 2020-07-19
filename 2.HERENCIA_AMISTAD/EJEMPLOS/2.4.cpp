/* Se define la clase Persona de la cual se deriva la clase Alumno. De 
ésta se deriva la clase Universitario, que a su vez sirve como base 
para definir la clase Ingeniería. Finalmente, a partir de ésta se 
define la clase Computación. */
#include <iostream>
#include <string.h>
using namespace std;

class Persona
{
protected:
    char *Nombre;
    int Edad;
public:
    Persona(char *Nom, int Ed);
    void ImprimePersona();
};

/* Declaración del método constructor con parámetros. */
Persona::Persona(char *Nom, int Ed)
{
    Nombre= new char[strlen(Nom)+1];
    if (Nombre){
        strcpy(Nombre, Nom);
        Edad= Ed;
    }
}

/* Método que despliega los valores de los atributos de una persona. */
void Persona::ImprimePersona()
{
    cout <<"Nombre: " << Nombre << endl;
    cout << "Edad: " << Edad << endl;
}

/* Primer nivel de herencia: definición de la clase Alumno como clase 
derivada de la clase Persona. */
class Alumno: public Persona {
protected:
    float Promedio;
public:
    Alumno(char *Nom, int Ed, float Prom);
    void ImprimeAlumno();
};

/* Declaración del método constructor. Invoca al método constructor de
la clase base. */
Alumno::Alumno(char *Nom, int Ed, float Prom): Persona(Nom, Ed)
{
    Promedio= Prom;
}

/* Método que despliega los valores de los atributos de un alumno. */
void Alumno::ImprimeAlumno()
{
    Persona::ImprimePersona();
    cout << "Promedio: " << Promedio << endl;
}

/* Segundo nivel de herencia: definición de la clase Universitario como 
clase derivada de la clase Alumno. */
class Universitario: public Alumno {
protected:
    char *NombreUniversidad;
public:
    Universitario(char *Nom, int Ed, float Prom, char *NomUniv);
    void ImprimeUniversitario();
};

/* Declaración del método constructor. Invoca al método constructor de 
la clase base. */
Universitario::Universitario(char *Nom, int Ed, float Prom, char *NomUniv):
               Alumno(Nom, Ed, Prom)
{
    NombreUniversidad= new char[strlen(NomUniv)+1];
    if (NombreUniversidad)
        strcpy(NombreUniversidad, NomUniv);
}

/* Método que despliega los valores de los atributos de un alumno
universitario. */
void Universitario::ImprimeUniversitario()
{
    Alumno::ImprimeAlumno();
    cout << "Nombre de la Universidad: " << NombreUniversidad << endl;
}

/* Tercer nivel de herencia: definición de la clase Ingeniería como 
clase derivada de la clase Universitario. */
class Ingenieria: public Universitario {
protected:
    char *NombreIngenieria;
public:
    Ingenieria(char *Nom, int Ed, float Prom, char *NomUniv, char *NomIng);
    void ImprimeIngenieria();
};

/* Declaración del método constructor. Invoca al método constructor de
la clase base. */
Ingenieria::Ingenieria(char *Nom, int Ed, float Prom, char *NomUniv, char *NomIng):
            Universitario(Nom, Ed, Prom, NomUniv)
{
    NombreIngenieria= new char[strlen(NomIng)+1];
    if (NombreIngenieria)
        strcpy(NombreIngenieria, NomIng);
}

/* Método que despliega los valores de los atributos de un alumno de
alguna ingeniería. */
void Ingenieria::ImprimeIngenieria()
{
    Universitario::ImprimeUniversitario();
    cout  << "Nombre de la Ingenieria: " << NombreIngenieria << endl;
}

/* Cuarto nivel de herencia: definición de la clase Computación como 
clase derivada de la clase Ingeniería. */
class Computacion: public Ingenieria {
protected:
    char Plataformas[64];
public:
    Computacion(char *Nom, int Ed, float Prom, char *NomUniv, char *NomIng, char *Pla);
    void ImprimeComputacion();
};

/* Declaración del método constructor. Invoca al método constructor de *la clase base. */
Computacion::Computacion(char *Nom, int Ed, float Prom, char *NomUniv, char *NomIng, char *Pla):
             Ingenieria (Nom, Ed, Prom, NomUniv, NomIng)
{
    strcpy(Plataformas, Pla);
}

/* Método que despliega los valores de los atributos de un alumno de
^ingeniería en computación. */
void Computacion::ImprimeComputacion()
{
    Ingenieria::ImprimeIngenieria();
    cout << "Plataformas usadas: " << Plataformas << endl;
}

/* Función que usa las clases previamente definidas en las cuales hay 
una relación de herencia de niveles múltiples. */
void UsaHerencia()
{
    Persona ObjPersona("Carlos", 23);
    Alumno ObjAlumno("Adriana", 20, 9.75);
    Universitario ObjUniversitario("Carolina", 19, 8.65, "ITAM");
    Ingenieria ObjIngenieria("Pablo", 21, 8.25, "UNAM", "Mecánica");
    Computacion ObjComputacion("Alfonso", 22, 9.8, "UPT", "Computación", "Varias");
    ObjPersona.ImprimePersona();
    ObjAlumno.ImprimeAlumno();
    ObjUniversitario.ImprimeUniversitario();
    ObjIngenieria.ImprimeIngenieria();
    
    /* Imprime los datos del alumno de ingeniería en computación. */
    ObjComputacion.ImprimeComputacion();
    /* Imprime sólo los datos personales del alumno de ingeniería en computación. */
    ObjComputacion.ImprimePersona();
}
