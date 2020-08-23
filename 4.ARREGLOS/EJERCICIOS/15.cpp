/*
15.	Considerando las especificaciones (que aparecen más adelante) de las clases Alumno y 
Arreglo escriba un programa completo en C++ que:
á) Lea el número de alumnos registrados en una cierta carrera y capture los datos 
correspondientes a los mismos.
b)	Obtenga e imprima el promedio de cada uno de los alumnos y el promedio del grupo.
c)	Dado un alumno y una nueva carrera registrar el cambio de carrera correspondiente. 
Se debe validar que dicho alumno haya sido almacena¬do previamente en el arreglo.
d)	Imprimir todos los datos de aquellos alumnos que lleven más de 25 materias aprobadas.
e)	Dar de baja de la carrera a aquellos alumnos que hayan completado igual (o mayor)
número de materias reprobadas que aprobadas.
f)	Dar de alta un alumno nuevo. 
Alumno
----------------------------
Nombre: cadena de caracteres
Carrera: cadena de caracteres
Número de materias aprobadas: entero
Calificaciones obtenidas en materias aprobadas: arreglo de enteros (de máximo 60 valores)
Total de materias reprobadas: entero
----------------------------
Constructor (es)
Lectura
Calcula promedio del alumno
Cambia de carrera
Imprime datos

Arreglo
Datos: 
tipo Alumno
Número de elementos: entero
Constructor
Lectura
Impresión
...
*/

#include <iostream>
#include <string.h>

#define MAX 100

using namespace std;

class Alumno {
private:
	char* nombre;
	char* carrera;
	int nroMateriasAprob;
	int califMateriasAprob[60];
	int nroMateriasReprob;
public:
	Alumno();
	Alumno(char* nom, char* carr, int nroMatAprob, int nroMatReprob);
	void lectura();
	float calculaPromedio();
	void cambiaCarrera(char* carr);
	void imprimeDatos();
};

Alumno::Alumno(){}

Alumno::Alumno(char* nom, char* carr, int nroMatAprob, int nroMatReprob)
{
	nombre = new char[strlen(nom) + 1];
	carrera = new char[strlen(carr) + 1];
	
	if(nombre != NULL) {
		strcpy(nombre, nom);
	}
	if(carrera != NULL) {
		strcpy(carrera, carr);
	}
	nroMateriasAprob = nroMatAprob;
	nroMateriasReprob = nroMatReprob;
}

void Alumno::lectura()
{
	char nom[100], carr[100];
	cout << "Nombre: ";
	cin.getline(nom, 100);
	
	nombre = new char[strlen(nom) + 1];
	if(nombre != NULL) {
		strcpy(nombre, nom);
	}
	
	cout << "Carrera: ";
	cin.getline(carr, 100);
	
	carrera = new char[strlen(carr) + 1];
	if(nombre != NULL) {
		strcpy(carrera, carr);
	}
	
	cout << "Nro Materias Aprobadas: ";
	cin >> nroMateriasAprob;
	cout << "Nro Materias Reprobadas: ";
	cin >> nroMatReprob;
	
	for(int i = 0; i < nroMatAprob; i++) {
		cout << "Calif. Materia Aprobada " << i + 1 << ": ";
		cin >> califMateriasAprob[i];
	}
}

float Alumno::calculaPromedio()
{
	float sum = 0;
	for(int i = 0; i < nroMatAprob; i++) {
		sum += califMateriasAprob[i];
	}
	
	return sum / nroMatAprob;
}

void Alumno::cambiaCarrera(char* carr)
{
	delete carrera;
	carrera = new char(strlen(carr) + 1);
	
	if(carrera != NULL) {
		strcpy(carrera, carr);
	}
}

void Alumno::imprimeDatos()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Carrera: " << carrera << endl;
	cout << "Nro. Materias Aprob.: " << nroMateriasAprob << endl;
	cout << "Nro. Materias Reprob.: " << nroMateriasReprob << endl;
	
	for(int i = 0; i < nroMatAprob; i++) {
		cout << "Calif. Aprob. " << i + 1 << ": " << califMateriasAprob[i] << endl;
	}
	
	cout << "Promedio: " << calculaPromedio() << endl;
}

class ArregloAlumnos {
private:
	Alumno datos[MAX];
	int tam;
public:
	ArregloAlumnos();
	void lectura();
	void escritura();
	int insertar(Alumno a);
	int eliminar(int pos);
	int buscar(Alumno a);
	Alumno obtener(int pos);
};

ArregloAlumnos::ArregloAlumnos()
{
	tam = 0;
}
/*
Devuelve 1 si se insertó el alumno
Devuelve 0 si no se insertó el alumno
*/
int ArregloAlumnos::insertar(Alumno a)
{
	int resultado = 1;
	if(tam + 1 <= MAX) {
		datos[tam++] = a;
	} else {
		resultado = 0;
	}
	return resultado;
}

/*
Devuelve la posicion encontrada
Si no encuentra alumno devuelve -1
*/
int ArregloAlumnos::buscar(Alumno a)
{
	int i = 0, resultado = -1;
	while(i < tam && datos[i] != a){
		i++;
	}
	
	if(i < tam) {
		resultado = i;
	}
	
	return resultado;
}

/*
Devuelve 1 si eliminó al alumno en la posición pos
Devuelve 0 si no se eliminó
*/
int ArregloAlumnos::eliminar(int pos)
{
	int resultado = 1;
	if(pos >= tam) {
		resultado = 0;
	} else {
		for(int i = pos; i < tam; i++) {
			datos[i] = datos[i+1];
		}
	}
	
	return resultado;
}

Alumno ArregloAlumnos::obtener(int pos)
{
	return datos[pos];
}

void ArregloAlumnos::lectura()
{
	Alumno a();
	do {
		cout << "Ingrese el tamanio: ";
		cin >> tam;
	} while(tam > MAX || tam <= 0);
	
	for(int i = 0; i < tam; i++) {
		cout << "Alumno: " << i + 1 << ": ";
		a.lectura();
		datos[i] = a;
	}
}

void ArregloAlumnos::escritura()
{
	for(int i = 0; i < tam; i++) {
		cout << "Alumno: " << i + 1 << ": ";
		a.imprimeDatos();
		cout << endl;
	}
}

int menuOpciones()
{
	int opc;
	
	do {
		cout << "1-Ingresar alumnos por carrera" << endl;
		cout << "2-Promedio de alumnos (por cada uno y total)" << endl;
		cout << "3-"
	}
}