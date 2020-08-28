/* Aplicación de una cola circular. Los datos de un grupo de pacientes 
(objetos de tipo Paciente) se registran en una cola a medida que los 
pacientes solicitan atención de un medico. A su vez, cuando un mddico 
se desocupa y está en condiciones de recibir a otro paciente se obtienen 
(de la cola) los datos de un paciente y se le asigna a dicho medico.
De esta manera se garantiza que los pacientes sean atendidos en el 
orden en el que fueron registrados. */
#include <iostream>
#include <string.h>
using namespace std;

/* En la biblioteca "ColaCircular.h" se incluye la plantilla de la clase 
ColaCircular presentada en el programa 5.7. */
#include "5.7.cpp"

/* Definición de la clase Paciente. */
class Paciente {
private:
    char Nombre[64], Sexo, Padecim[64];
    int AnioNac;
public:
    Paciente();
    Paciente(char[], char, char[], int);
    friend istream &operator>>(istream &, Paciente &);
    friend ostream &operator<<(ostream &, Paciente &);
};

/* Declaración del método constructor por omisión. */
Paciente::Paciente()
{}
/* Declaración del método constructor con parámetros. */
Paciente::Paciente(char Nom[], char S, char Padec[], int ANac)
{
    strcpy(Nombre, Nom);
    Sexo= S;
    strcpy(Padecim, Padec);
    AnioNac= ANac;
}

/* Sobrecarga del operador >> para poder leer objetos de tipo Paciente 
de manera directa. */
istream &operator>>(istream &Lee, Paciente &ObjPac)
{
    cout << "\n\nIngrese nombre del paciente: ";
    Lee >> ObjPac.Nombre;
    cout << "\n\nSexo: ";
    Lee >> ObjPac.Sexo;
    cout << "\n\nPadecimiento del paciente: ";
    Lee >> ObjPac.Padecim;
    cout << "\n\nAnio de nacimiento: ";
    Lee >> ObjPac.AnioNac;
    
    return Lee;
}

/* Sobrecarga del operador << para poder desplegar en pantalla objetos 
de tipo Paciente de manera directa. */
ostream &operator<< (ostream &Escribe, Paciente &ObjPac)
{
    Escribe << "\n\nDatos del paciente\n";
    Escribe << "\nNombre: " << ObjPac.Nombre;
    Escribe << "\nSexo: " << ObjPac.Sexo;
    Escribe << "\nAnio nacimiento: " << ObjPac.AnioNac;
    Escribe << "\nPadecimiento: " << ObjPac.Padecim;
    
    return Escribe;
}

/* Función auxiliar que despliega al usuario las opciones de trabajo: registrar 
un nuevo paciente o asignar módico a un paciente ya registrado. */
int Menu()
{
    int Opc;
    do {
        cout << "\n\nBienvenido al sistema de registro de pacientes para consulta. \n\n";
        cout << "\nQue desea hacer\n";
        cout << "\n1-Registrar un nuevo paciente. ";
        cout << "\n2-Asignar medico a un paciente.";
        cout << "\n3-Terminar. \n";
        cout << "\n\nIngrese la opcion elegida: ";
        cin >> Opc;
    } while (Opc < 1 || Opc > 3);
    
    return Opc;
}

/* Función que hace uso de la cola circular para almacenar los datos a 
procesar. Por medio de la cola se asegura que los datos se procesen en
orden en el que llegan: los pacientes se asignan a los medicos en el orden 
en el que llegaron a la consulta. */
void UsaColaCircular()
{
    ColaCircular<Paciente> ListaEspera;
    Paciente Pac;
    
    int Opc= Menu();
    while (Opc == 1 || Opc== 2)
    {
        switch (Opc)
        {
            case 1:
                cin >> Pac;
                if (!ListaEspera.InsertaCCircular(Pac))
                    cout << "\nLa cuota de pacientes se agoto. Regrese maniana.";
                break;

            case 2:
                if (ListaEspera.EliminaCCircular(&Pac))
                    cout << "\n\nEl paciente que pasa a consulta es: " << Pac;
                else
                    cout << "\n\nNo hay pacientes en espera de ser atendidos.\n";
                break;
        }
        Opc= Menu();
    }

    
}

int main() {
    UsaColaCircular();
    return 0;
}