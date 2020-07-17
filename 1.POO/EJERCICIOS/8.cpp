/*
8.	Retome la clase del ejercicio 6, modifique el método que aumenta el sueldo del trabajador. 
Ahora, el método debe recibir como parámetro el porcentaje de aumento, el número de horas extra 
trabajadas y el valor a pagar por cada hora extra. Los dos últimos parámetros deben tener un valor
por omisión, de tal manera que cuando un trabajador no haya laborado horas extra, el usuario no 
tenga que asignarles 0.
*/

#include <iostream>
#include <string.h>

using namespace std;

class Trabajador {
private:
    char Nombre[64]; int ClaveTrab, Sindi; float Sueldo; 
public:
    Trabajador(char [], int, int, float);
    void Imprime();
    void CambiaEstado();
    void AumentaSueldo(float, int, float);
};

Trabajador::Trabajador(char Nom[],int Cla=1000,int Si=1,float Sue=1600) {
    strcpy(Nombre, Nom);
    ClaveTrab= Cla;
    Sindi= Si;
    Sueldo= Sue;
}

void Trabajador::Imprime()
{
    cout<<"\n\nNombre del trabajador: "<< Nombre; cout<<"\nClave: "<<ClaveTrab; 
    if (Sindi)
        cout<<"\nEstá sindicalizado."; 
    cout<<"\nSueldo: "<<Sueldo<<" \n\n";
}
void Trabajador::CambiaEstado()
{
    Sindi= !Sindi;
}
void Trabajador::AumentaSueldo(float Aumento, int HorasExtra = 0, float valorHoraExtra = 0)
{
    Trabajador::Sueldo = (Trabajador::Sueldo * (1 + Aumento)) + (HorasExtra * valorHoraExtra);
}