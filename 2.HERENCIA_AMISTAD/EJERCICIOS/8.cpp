/*
Defina las clases DireccionEscoiar y Alumno de acuerdo a las especifi¬caciones que se proporcionan más adelante. Observe que la clase DireccionEscoiar incluye métodos para modificar valores de algunos atributos de objetos tipo Alumno que, por razones de seguridad, deben ser privados. Para permitir este acceso debe hacer uso de la relación de amistad (friend) explicada en este capítulo. Una vez definidas las clases indicadas, escriba un programa en C++ que permita:
á) Crear un objeto llamado AiumnoJuan de tipo Alumno y un objeto llamado DirEsc de tipo DireccionEscoiar.
b) Imprimir los datos del AiumnoJuan y de la DirEsc. 
c)	Registrar un cambio de carrera para el Alumno Juan. El usuario deberá proporcionar el nombre de la carrera a la cual se cambiará.
d)	Registrar una actualización del número de materias aprobadas por el Alumno Juan. El usuario deberá proporcionar el total de materias aprobadas en este último semestre (el cual se sumará al total anterior).
e)	Registrar una actualización del promedio de calificaciones del Alumno Juan. El usuario deberá proporcionar el nuevo promedio.

*/
#include <iostream>
#include <string.h>

using namespace std;

class DireccionEscolar;

class Alumno {
private:
	char* Nombre;
	int AnioIngreso;
	char* NomCarrera;
	int NroMatAprob;
	float Promedio;
public:
	Alumno(char*, int, char*, int, float);
	void imprime();
	friend class DireccionEscolar;
};

Alumno::Alumno(char* nom, int anioIng, char* carr, int nroMatAp, float prom)
{
	Nombre = new char[strlen(nom) + 1];
	NomCarrera = new char[strlen(carr) + 1];

	strcpy(Nombre, nom);
	strcpy(NomCarrera, carr);
	AnioIngreso = anioIng;
	NroMatAprob = nroMatAp;
	Promedio = prom;
}

void Alumno::imprime()
{
	cout << "Nombre: " << Nombre << endl;
	cout << "Anio Ingreso: " << AnioIngreso << endl;
	cout << "Nombre Carrera: "<< NomCarrera << endl;
	cout << "Nro Materias Aprob: " << NroMatAprob << endl;
	cout << "Promedio: " << Promedio << endl;
}

class DireccionEscolar {
private:
	char* Responsable;
	char* Telefono;
public:
	DireccionEscolar(char*, char*);
	void actualizaCarre(Alumno&, char*);
	void actualizaMatAprob(Alumno&, int);
	void actualizaMatProm(Alumno&, float);
	void imprime();
};

DireccionEscolar::DireccionEscolar(char* resp, char* telf)
{
	Responsable = new char[strlen(resp) + 1];
	Telefono = new char[strlen(telf) + 1];
	strcpy(Responsable, resp);
	strcpy(Telefono, telf);
}

void DireccionEscolar::actualizaCarre(Alumno &a, char* carre)
{
	a.NomCarrera = new char[strlen(carre) + 1];
	a.NomCarrera = carre;
}

void DireccionEscolar::actualizaMatAprob(Alumno &a, int matAprob)
{
	a.NroMatAprob = matAprob;
}

void DireccionEscolar::actualizaMatProm(Alumno &a, float prom)
{
	a.Promedio = prom;
}

void DireccionEscolar::imprime()
{
	cout << "Responsable: " << Responsable << endl;
	cout << "Telefono: " << Telefono << endl;
}

int main() {

	char carr[64];
	int numMat;
	float prom;

	Alumno AlumnoJuan((char*)"Juan", 2020, (char*)"Ingenieria", 6, 17.6);
	DireccionEscolar DirEsc((char*)"Don Pedro", (char*)"2315095");

	AlumnoJuan.imprime();
	cout << endl;
	DirEsc.imprime();

	cout << "Nueva carrera: ";
	cin.getline(carr, 64);

	cout << "Numero materias aprob.: ";
	cin >> numMat;

	cout << "Nuevo Promedio: ";
	cin >> prom;

	DirEsc.actualizaCarre(AlumnoJuan, carr);
	DirEsc.actualizaMatAprob(AlumnoJuan, numMat);
	DirEsc.actualizaMatProm(AlumnoJuan, prom);

	cout << endl;
	AlumnoJuan.imprime();

	return 0;
}
