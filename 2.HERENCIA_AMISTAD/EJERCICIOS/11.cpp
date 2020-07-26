/*
11.	Defina la clase Empleado según las especificaciones que se proporcionan más adelante. Además, en la clase debe incluir una relación de amistad con una función que tenga como objetivo calcular el sueldo a pagar al emplea¬do, de acuerdo a la siguiente expresión:
SueldoBase + Incentivo*TotalAñosTrabajados + HorasExtra
Donde:
•	SueldoBase se toma directamente del objeto tipo Empleado.
•	Incentivo es una constante declarada en el programa. 
•	TotaiAñosTrabajados lo calcula la función como la diferencia entre el año actual y el Añoingreso del empleado.
•	HorasExtra es un valor que recibe la función como parámetro. 
*/

#include <iostream>
#include <string.h>

#define INCENTIVO 10

using namespace std;

class Empleado;

float calcularSueldoAPagar(Empleado&, int);

class Empleado {
private:
	char* Nombre;
	int AnioIngreso;
	char* Domicilio;
	float SueldoBase;
	char* ReportaA;
public:
	Empleado(char*, int, char*, float, char*);
	void imprime();
	friend float calcularSueldoAPagar(Empleado&, int);
};

Empleado::Empleado(char* nom, int anioIng, char* dom, float sueldo, char* reporta)
{
	Nombre = new char[strlen(nom) + 1];
	Domicilio = new char[strlen(dom) + 1];
	ReportaA = new char[strlen(reporta) + 1];

	strcpy(Nombre, nom);
	strcpy(Domicilio, dom);
	strcpy(ReportaA, reporta);
	AnioIngreso = anioIng;
	SueldoBase = sueldo;
}

void Empleado::imprime()
{
	cout << "Nombre: " << Nombre << endl;
	cout << "Anio Ingreso: " << AnioIngreso << endl;
	cout << "Domicilio: "<< Domicilio << endl;
	cout << "Sueldo: " << SueldoBase << endl;
	cout << "Reporta a: " << ReportaA << endl;
}

float calcularSueldoAPagar(Empleado& e, int horasExtra)
{
	int totalAniosTrab = 2020 - e.AnioIngreso;
	return e.SueldoBase + (INCENTIVO * totalAniosTrab) + horasExtra;
}

int main() {

	Empleado EmpleadoPedro((char*)"Juan", 2017, (char*)"Las Palomas", 1567.1, (char*)"Juan Ramos");

	EmpleadoPedro.imprime();
	cout << "Sueldo a pagar: " << calcularSueldoAPagar(EmpleadoPedro, 4);

	return 0;
}