/*
5.	Considere la relación de herencia que se muestra en la siguiente figura, 
la cual involucra tres clases: Alumno, Deportista y BecadoDeporte. Esta Última 
representa a aquellos alumnos que son deportistas y que por esa razón han 
recibido una beca especial del gobierno para premiar sus esfuerzos. Decida 
qué atributos y métodos incluir de tal manera que su programa pueda:
a)	Declarar dos objetos llamados Alumno Juan y AlumnoPedro de tipo Alumno.
b)	Declarar un objeto llamado DeporLuis de tipo Deportista.
c)	Declarar dos objetos llamados BDAna y BDCarmen de tipo BecadoDeporte.
d)	Imprimir los datos de todos los objetos declarados.
e)	Actualizar el nombre de la carrera que están estudiando AiumnoJuan y BDAna. El dato dado por el usuario será el nombre de la nueva carrera.
f)	Actualizar el nombre del entrenador de DeporLuis y BDCarmen. El dato dado por el usuario será el nombre del nuevo entrenador.
g)	Actualizar el monto de la beca de BDAna y BDCarmen. El dato dado por el usuario será el porcentaje de incremento de la beca actual. 
*/
#include <iostream>
#include <string.h>

using namespace std;

class Alumno {
private:
	char* carrera;
public:
	Alumno(char*);
	char* obtenerCarrera();
	void cambiarCarrera(char*);
	void imprimirDatos();
};

Alumno::Alumno(char* carr)
{
	carrera = new char[strlen(carr) + 1];
	strcpy(carrera, carr);
}

char* Alumno::obtenerCarrera()
{
	return carrera;
}

void Alumno::cambiarCarrera(char* carr)
{
	carrera = new char[strlen(carr) + 1];
	strcpy(carrera, carr);
}

void Alumno::imprimirDatos()
{
	cout << "Carrera: " << carrera << endl;
}

class Deportista {
private:
	char* deporte;
	char* entrenador;
public:
	Deportista(char*, char*);
	char* obtenerDeporte();
	char* obtenerEntrenador();
	void cambiarEntrenador(char*);
	void imprimirDatos();
};

Deportista::Deportista(char* depor, char* entren)
{
	deporte = new char[strlen(depor) + 1];
	entrenador = new char[strlen(entren) + 1];
	strcpy(deporte, depor);
	strcpy(entrenador, entren);
}

char* Deportista::obtenerDeporte()
{
	return deporte;
}

char* Deportista::obtenerEntrenador()
{
	return entrenador;
}

void Deportista::cambiarEntrenador(char* entren)
{
	entrenador = new char[strlen(entren) + 1];
	strcpy(entrenador, entren);
}

void Deportista::imprimirDatos()
{
	cout << "Deporte: " << deporte << endl;
	cout << "Entrenador: " << entrenador << endl;
}

class BecadoDeporte : public Alumno, public Deportista {
private:
	float montoBeca;
public:
	BecadoDeporte(char*, char*, char*, float);
	void incrementarMonto(float);
	void imprimirDatos();
};

BecadoDeporte::BecadoDeporte(char* carr, char* depor, char* entren, float montBec) :
			   Alumno(carr), Deportista(depor, entren)
{
	montoBeca = montBec;
}

void BecadoDeporte::incrementarMonto(float porc)
{
	montoBeca += (montoBeca*porc);
}

void BecadoDeporte::imprimirDatos()
{
	Alumno::imprimirDatos();
	Deportista::imprimirDatos();
	cout << "Monto beca: " << montoBeca << endl;
}

int main() {

	char temp[60];
	float porc;

	Alumno alumnoJuan((char*)"Ing. Sistemas"), alumnoPedro((char*)"Contabilidad");
	Deportista deporLuis((char*)"Atletismo", (char*)"Don Lucas");
	BecadoDeporte bdAna((char*)"Ed. Fisica", (char*)"Voley", (char*)"Dra. Luisa", 1500), 
	bdCarmen((char*)"Danza", (char*)"Baile", (char*)"Maricarmen", 955.5);

	alumnoJuan.imprimirDatos();
	cout << endl;
	alumnoPedro.imprimirDatos();
	cout << endl;
	deporLuis.imprimirDatos();
	cout << endl;
	bdAna.imprimirDatos();
	cout << endl;
	bdCarmen.imprimirDatos();

	cout << "\nNueva carrera para Juan: ";
	cin.ignore();
	cin.getline(temp, 60);

	alumnoJuan.cambiarCarrera(temp);
	alumnoJuan.imprimirDatos();

	cout << "Nueva carrera para Ana: ";
	cin.ignore();
	cin.getline(temp, 60);
	
	bdAna.cambiarCarrera(temp);
	bdAna.imprimirDatos();
	
	cout << "Nuevo entrenador para Luis: ";
	cin.ignore();
	cin.getline(temp, 60);

	deporLuis.cambiarEntrenador(temp);
	deporLuis.imprimirDatos();

	cout << "Nuevo entrenador para Carmen: ";
	cin.ignore();
	cin.getline(temp, 60);
	bdCarmen.cambiarEntrenador(temp);
	bdCarmen.imprimirDatos();

	cout << "Incrementar monto beca para Ana (porc.): ";
	cin >> porc;

	bdAna.incrementarMonto(porc);
	bdAna.imprimirDatos();

	cout << "Incrementar monto beca para Carmen (porc.): ";
	cin >> porc;

	bdCarmen.incrementarMonto(porc);
	bdCarmen.imprimirDatos();
	return 0;
}