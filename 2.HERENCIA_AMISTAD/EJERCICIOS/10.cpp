/*
10.	Retome el problema 9 pero ahora utilice el concepto de métodos amigos. Reescriba lo que considere 
necesario de tal manera que sólo los métodos ActualizaDomic, ActualizaRepA y ActualizaSueido puedan 
tener acceso a los miembros privados de la clase Empleado.
*/

#include <iostream>
#include <string.h>

using namespace std;

class Empleado;

class RecursosHumanos {
private:
	char* Responsable;
	char* Telefono;
public:
	RecursosHumanos(char*, char*);
	void actualizaDomic(Empleado&, char*);
	void actualizaRepA(Empleado&, char*);
	void actualizaSueldo(Empleado&, float);
	void imprime();
};

class Empleado {
private:
	char* Nombre;
	int AnioIngreso;
	char* Domicilio;
	float Sueldo;
	char* ReportaA;
public:
	Empleado(char*, int, char*, float, char*);
	void imprime();
	friend void RecursosHumanos::actualizaDomic(Empleado&, char*);
	friend void RecursosHumanos::actualizaRepA(Empleado&, char*);
	friend void RecursosHumanos::actualizaSueldo(Empleado&, float);
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
	Sueldo = sueldo;
}

void Empleado::imprime()
{
	cout << "Nombre: " << Nombre << endl;
	cout << "Anio Ingreso: " << AnioIngreso << endl;
	cout << "Domicilio: "<< Domicilio << endl;
	cout << "Sueldo: " << Sueldo << endl;
	cout << "Reporta a: " << ReportaA << endl;
}

RecursosHumanos::RecursosHumanos(char* resp, char* telf)
{
	Responsable = new char[strlen(resp) + 1];
	Telefono = new char[strlen(telf) + 1];
	strcpy(Responsable, resp);
	strcpy(Telefono, telf);
}

void RecursosHumanos::actualizaDomic(Empleado &a, char* dom)
{
	a.Domicilio = new char[strlen(dom) + 1];
	a.Domicilio = dom;
}

void RecursosHumanos::actualizaRepA(Empleado &a, char* reporta)
{
	a.ReportaA = new char[strlen(reporta) + 1];
	a.ReportaA = reporta;
}

void RecursosHumanos::actualizaSueldo(Empleado &a, float sueldo)
{
	a.Sueldo = sueldo;
}

void RecursosHumanos::imprime()
{
	cout << "Responsable: " << Responsable << endl;
	cout << "Telefono: " << Telefono << endl;
}

int main() {

	char dom[64], rep[64];
	float sueldo;

	Empleado EmpleadoPedro((char*)"Juan", 2020, (char*)"Las Palomas", 1567.1, (char*)"Juan Ramos");
	RecursosHumanos Personal((char*)"Don Pedro", (char*)"2315095");

	EmpleadoPedro.imprime();
	cout << endl;
	Personal.imprime();

	cout << "Nuevo domicilio: ";
	cin.getline(dom, 64);

	cout << "Nuevo reporta a: ";
	cin.getline(rep, 64);

	cout << "Nuevo sueldo: ";
	cin >> sueldo;

	Personal.actualizaDomic(EmpleadoPedro, dom);
	Personal.actualizaRepA(EmpleadoPedro, rep);
	Personal.actualizaSueldo(EmpleadoPedro, sueldo);

	cout << endl;
	EmpleadoPedro.imprime();

	return 0;
}