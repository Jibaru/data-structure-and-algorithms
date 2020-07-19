/* Se define la clase Persona formada por atributos protegidos y 
públicos, y se usa como clase base para definir la clase Empleado. 
Los objetos que sean del tipo Empleado tendrán los atributos de esta clase 
(por ejemplo Salario), además de los atributos heredados de la clase Persona. */ 
#include <iostream>
#include <string.h>

using namespace std;

class Persona
{
protected:
    char Nombre[30]; 
    int Edad; 
public:
    Persona (char *Nom, int Ed); 
    void ImprimePersona();
};
/* Declaración del método constructor con parámetros. Da un valor inicial 
a los atributos. */
Persona::Persona(char *Nom, int Ed)
{
    strcpy(Nombre, Nom);
    Edad = Ed;
}
/* Método que despliega los valores de los atributos de una persona. */ 
void Persona::ImprimePersona()
{
    cout << "Nombre: " << Nombre << endl; 
    cout << "Edad: " << Edad << endl;
}

/* Definición de la clase Empleado como clase derivada de la clase 
Persona. Se usa herencia pública. */ 
class Empleado: public Persona {
protected:
    float Salario; 
public:
    Empleado (char *Nom, int Ed, float Sal); 
    void ImprimeEmpleado();
    ~Empleado();
};

/* Declaración del método constructor. Invoca al constructor de la clase base. */
Empleado::Empleado(char *Nom, int Ed, float Sal): Persona(Nom, Ed)
{
    Salario= Sal;
}

/* Declaración del método destructor. */
Empleado::~Empleado(){}
 
/* Método que imprime los valores de algunos de los atributos de un empleado. */
void Empleado::ImprimeEmpleado()
{
    cout << "Empleado: " << Nombre << endl; 
    cout << "Salario: " << Salario << endl;
}

/* Función que usa las clases Persona y Empleado: se declaran apuntadores 
a objetos tipo Persona y Empleado. Por medio de los constructores 
se les asignan valores a estos objetos, se imprimen y finalmente se 
destruyen liberando la memoria. */ 
void UsaHerencia(void)
{
    Persona *ObjPersona = new Persona("Carlos", 22);
    Empleado *ObjEmpleado = new Empleado("Adriana", 25, 20000);
    
    ObjPersona->ImprimePersona();
    ObjEmpleado->ImprimeEmpleado();
    
    delete ObjPersona;
    delete ObjEmpleado;
}

