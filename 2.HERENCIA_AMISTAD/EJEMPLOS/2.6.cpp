/* Se definen las clases Medico y Paciente, siendo esta última una clase 
amiga de la primera. Por lo tanto, la clase Paciente podrá tener acceso 
a todos los miembros de la clase Medico. */
#include <iostream>
#include <string.h>
using namespace std;

/* Prototipo de la clase Paciente. La definición de la misma aparece más 
adelante. */
class Paciente;

/* Definición de la clase Medico. */
class Medico {
private:
    char NombreCompleto[64], Especialidad[64];
public:
    Medico();
    Medico(char *NomCom, char *Esp);
    char* ObtenerNombreCompleto();
    char* ObtenerEspecialidad();
    void ImprimeDatos();
    /* Clase amiga que tiene acceso a los miembros privados de la clase Medico. */
    friend class Paciente;
};

/* Declaración del método constructor por omisión. */
Medico::Medico(){ }

/* Declaración del método constructor con parámetros. */
Medico::Medico(char *NomCom, char *Esp)
{
    strcpy(NombreCompleto, NomCom);
    strcpy(Especialidad, Esp);
}

/* Método que permite, a los usuarios externos a la clase, conocer el
nombre del médico. */
char* Medico::ObtenerNombreCompleto()
{
    return NombreCompleto;
}

/* Método que permite, a los usuarios externos a la clase, conocer la
especialidad del médico. */
char* Medico::ObtenerEspecialidad()
{
    return Especialidad;
}

/* Método que despliega los valores de los atributos de un médico. */
void Medico::ImprimeDatos(void)
{
    cout << "Nombre completo del médico: "<< NombreCompleto << endl;
    cout << "Especialidad: " << Especialidad << endl << endl;
}

/* Definición de la clase Paciente. */
class Paciente {
private:
    char NombreCompleto[64];
    int Edad;
    char Padecimiento[64];
    Medico* MedicoEspecialista;
public:
    Paciente();
    Paciente(char *NomCom, int Ed, char *Pad);
    char* ObtenerNombreCompleto();
    int ObtenerEdad();
    char* ObtenerPadecimiento();
    void AsociarMedico();
    void ImprimeDatos();
};

/* Declaración del método constructor por omisión. */
Paciente::Paciente(){ }

/* Declaración del método constructor con parámetros. */
Paciente::Paciente(char *NomCom, int Ed, char *Pad)  
{
    strcpy(NombreCompleto, NomCom);
    Edad= Ed;
    strcpy(Padecimiento, Pad);
}

/* Método que permite, a los usuarios externos a la clase, conocer el
nombre del paciente. */
char* Paciente::ObtenerNombreCompleto()
{
    return NombreCompleto;
}

/* Método que permite, a los usuarios externos a la clase, conocer la 
edad del paciente. */
int Paciente::ObtenerEdad()
{
    return Edad;
}

/* Método que permite, a los usuarios externos a la clase, conocer el
nombre del padecimiento. */
char* Paciente::ObtenerPadecimiento()
{
    return Padecimiento;
}

/* Método que asocia un médico especialista a cada paciente. Note cómo 
el miembro MedicoEspecialista (de tipo puntero a un objeto tipo Medico)
tiene acceso a los miembros privados de la clase Medico. */
void Paciente::AsociarMedico()
{
    MedicoEspecialista= new Medico();
    cout << "Ingrese el Nombre Completo del Médico: ";
    cin >> MedicoEspecialista->NombreCompleto;
    cout << "Ingrese la especialidad: ";
    cin >> MedicoEspecialista->Especialidad;
}

/* Método que despliega los valores de los atributos de un paciente. */
void Paciente::ImprimeDatos()
{
    cout << "\nNombre Completo: " << NombreCompleto << endl;
    cout << "Edad: " << Edad << endl;
    cout << "Padecimiento: " << Padecimiento << endl;
    cout << "Datos del Medico Especialista:" << endl;
    MedicoEspecialista->ImprimeDatos();
}

/* Función que usa las clases amigas previamente definidas. */
void UsaClaseAmiga()
{
    Paciente ObjPacienteA ("Juan Carlos G.", 25, "Gripe"),
             ObjPacienteB ("Adriana Z.", 38, "Gastritis");
    ObjPacienteA.AsociarMedico();
    ObjPacienteB.AsociarMedico();
    ObjPacienteA.ImprimeDatos();
    ObjPacienteB.ImprimeDatos();
}