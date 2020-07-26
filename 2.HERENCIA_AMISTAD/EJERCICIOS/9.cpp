/*
9. Defina las clases RecursosHumanos y Empleado de acuerdo a las especificaciones proporcionadas más adelante. Observe que la clase RecursosHumanos incluye métodos para modificar valores de algunos atributos de objetos tipo Empleado que, por razones de seguridad, deben ser privados. Para permitir este acceso debe hacer uso de la relación de amistad (friend). Una vez definidas las clases indicadas, escriba un programa en C++ que permita:
á) Crear un objeto llamado EmpieadoPedro de tipo Empleado y un objeto llamado Personal de tipo RecursosHumanos.
b)	Imprimir los datos del EmpieadoPedro y de Personal.
c)	Registrar un cambio de domicilio del EmpieadoPedro. El usuario deberá proporcionar el nuevo domicilio. 
d)	Registrar un cambio en el nombre de la persona a la cual reporta el Em- pieadoPedro. El usuario deberá proporcionar el nombre de la persona a la que reportará a partir de ahora.
e)	Registrar una actualización del sueldo del EmpieadoPedro. El usuario deberá proporcionar el nuevo sueldo.
f)	Imprimir los datos del EmpieadoPedro si lleva más de 10 años trabajando en la empresa.

*/
#include <iostream>
#include <string.h>

using namespace std;

class RecursosHumanos;

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
	friend class RecursosHumanos;
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