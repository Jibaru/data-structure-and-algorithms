/* Se definen las clases Boleto y Hotel, que servirán como base para 
definir la clase PlanVacac, representando un caso de herencia múltiple.
Se presenta una aplicación muy sencilla que utiliza las clases 
previamente definidas. */

#include <iostream>
#include <string.h>

using namespace std;

/* Definición de la clase Boleto. */ 
class Boleto {
private:
    float Precio;
    char Numero[64], CdadOri[64], CdadDes[64]; 
public:
    Boleto();
    Boleto(float, char *, char*, char *);
    void Imprime();
};

/* Declaración del constructor por omisión. */
Boleto::Boleto()
{ }

/* Declaración del constructor con parámetros. */
Boleto::Boleto(float Pre, char Num[], char CO[], char CD[])
{
    Precio = Pre; 
    strcpy(Numero, Num); 
    strcpy(CdadOri, CO); 
    strcpy(CdadDes, CD);
}
/* Método que imprime los valores de los atributos de un boleto. */ 
void Boleto::Imprime()
{
    cout << "\n\nNúmero del boleto: " << Numero; 
    cout << "\nPrecio:	" << Precio;
    cout << "\nDe la ciudad: " << CdadOri << " a la ciudad: " << CdadDes << endl;
}
/* Definición de la clase Hotel. */ 
class Hotel {
private:
    float PrecioHab; int NumHab; char TipoHab; 
public:
    Hotel();
    Hotel(float, int, char);
    void Imprime();
};

/* Declaración del método constructor por omisión. */
Hotel::Hotel()
{ }

/* Declaración del método constructor con parámetros. */
Hotel::Hotel(float PreH, int NH, char TH)
{
    PrecioHab= PreH;
    NumHab= NH;
    TipoHab= TH;
}

/* Método que despliega los valores de los atributos de un hotel. */
void Hotel::Imprime() 
{
    cout << "\n\nNúmero de habitación: " << NumHab; 
    cout << "\nPrecio:	" << PrecioHab;
    cout << "\nTipo de habitación:	" << TipoHab << endl;
}

/* Definición de la clase PlanVacac como clase derivada de las clases 
Boleto y Hotel.Esta clase hereda los atributos de las otras dos. 
Además, tiene dos atributos propios. */
class PlanVacac: public Boleto, public Hotel {
private:
    char Descrip[64]; int TotalDias; public:
    PlanVacac();
    PlanVacac(float, char *, char *, char*, float, int, char, char *, int); 
    void Imprime();
};

/* Declaración del método constructor por omisión. */
PlanVacac::PlanVacac()
{ }

/* Declaración del método constructor con parámetros. */
PlanVacac::PlanVacac(float PB, char NB[], char CO[], char CD[],
                     float PH, int NH, char TH, char Des[], int TD): 
                     Boleto(PB, NB, CO, CD), Hotel(PH, NH, TH)
{
    strcpy(Descrip, Des);
    TotalDias= TD;
}

/* Método que despliega los valores de los atributos de un plan
vacacional. */
void PlanVacac::Imprime()
{
    cout << "\nDescripción: " << Descrip;
    cout << "\nTotal de dias: " << TotalDias;
    cout << "\nDatos del boleto\n ";
    Boleto::Imprime();
    cout <<"\nDatos del hotel\n ";
    Hotel::Imprime();
}
/* Función que pide al usuario los datos relacionados a un viaje. Con 
estos datos se crea un objeto tipo PlanVacac. Regresa como resultado 
dicho objeto. */
PlanVacac Lee()
{
    char CO[64], CD[64], NumBol[64], TH, Des[64];
    float Prec, PreHab;
    int NumHab, TD;
    cout << "\n¿De dónde sale? ";
    cin >> CO;
    cout << "\n¿A dónde llega?";
    cin >>CD;
    cout << "\nPrecio: ";
    cin >> Prec;
    cout << "\nNúmero de boleto:";
    cin >> NumBol;
    cout << "\nTipo de habitación: ";
    cin >> TH;
    cout << "\nPrecio de la habitación: ";
    cin >> PreHab;
    cout << "\nNúmero de habitación asignada: ";
    cin >> NumHab;
    cout << "\nTipo de paquete: ";
    cin >> Des;
    cout << "\nTotal de días: ";
    cin >> TD;
    PlanVacac Paquete(Prec, NumBol,CO, CD, PreHab, NumHab, TH, Des, TD);
    
    return Paquete;
}

/* Función que usa las clases previamente definidas entre las cuales
existe una relación de herencia múltiple. */
void UsaHerenciaMultiple()
{
    PlanVacac Viaje;
    Viaje= Lee();
    cout << "\n\nDatos del paquete seleccionado: ";
    Viaje.Imprime();
}

