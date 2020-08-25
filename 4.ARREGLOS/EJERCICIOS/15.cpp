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
#include <conio.h>

#define MAX 100

using namespace std;

class ArregloAlumnos;

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
	void lecturaPorCarrera(char* carr);
	float calculaPromedio();
	void cambiaCarrera(char* carr);
	void imprimeDatos();
	bool operator==(Alumno&);
	bool operator!=(Alumno&);
	friend class ArregloAlumnos;
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
	cin.ignore();
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
	cin >> nroMateriasReprob;
	
	for(int i = 0; i < nroMateriasAprob; i++) {
		cout << "Calif. Materia Aprobada " << i + 1 << ": ";
		cin >> califMateriasAprob[i];
	}
}

void Alumno::lecturaPorCarrera(char* carr)
{
	char nom[100];
	cout << "Nombre: ";
	cin.ignore();
	cin.getline(nom, 100);
	
	nombre = new char[strlen(nom) + 1];
	if(nombre != NULL) {
		strcpy(nombre, nom);
	}
	
	carrera = new char[strlen(carr) + 1];
	if(nombre != NULL) {
		strcpy(carrera, carr);
	}
	
	cout << "Nro Materias Aprobadas: ";
	cin >> nroMateriasAprob;
	cout << "Nro Materias Reprobadas: ";
	cin >> nroMateriasReprob;
	
	for(int i = 0; i < nroMateriasAprob; i++) {
		cout << "Calif. Materia Aprobada " << i + 1 << ": ";
		cin >> califMateriasAprob[i];
	}
}

float Alumno::calculaPromedio()
{
	float sum = 0;
	for(int i = 0; i < nroMateriasAprob; i++) {
		sum += califMateriasAprob[i];
	}
	
	return sum / nroMateriasAprob;
}

void Alumno::cambiaCarrera(char* carr)
{
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
	
	for(int i = 0; i < nroMateriasAprob; i++) {
		cout << "Calif. Aprob. " << i + 1 << ": " << califMateriasAprob[i] << endl;
	}
	
	cout << "Promedio: " << calculaPromedio() << endl;
}

bool Alumno::operator==(Alumno& otro)
{
	if(nroMateriasAprob != otro.nroMateriasAprob) {
		return false;
	}
	if(nroMateriasReprob != otro.nroMateriasReprob) {
		return false;
	}
	if(strcmp(nombre, otro.nombre) != 0) {
		return false;
	}
	if(strcmp(carrera, otro.carrera) != 0) {
		return false;
	}
	return true;
}

bool Alumno::operator!=(Alumno& otro)
{
	return !(*this == otro);
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
	Alumno* obtener(int pos);
	int tamanio();
	void mostrarConMasDe25MatAprob();
	void mostrarPromGrupalIndividual();
	void darDeBajaConMasMatReprobQueAprob();
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

Alumno* ArregloAlumnos::obtener(int pos)
{
	return &datos[pos];
}

int ArregloAlumnos::tamanio()
{
	return tam;
}

void ArregloAlumnos::lectura()
{
	Alumno a = Alumno();
	do {
		cout << "Ingrese el tamanio: ";
		cin >> tam;
	} while(tam > MAX || tam <= 0);
	
	for(int i = 0; i < tam; i++) {
		cout << "Alumno: " << i + 1 << ": " << endl;
		a.lectura();
		datos[i] = a;
	}
}

void ArregloAlumnos::escritura()
{
	for(int i = 0; i < tam; i++) {
		cout << "Alumno: " << i + 1 << ": " << endl;
		datos[i].imprimeDatos();
		cout << endl;
	}
}

void ArregloAlumnos::mostrarConMasDe25MatAprob()
{
	for(int i = 0; i < tam; i++) {
		if(datos[i].nroMateriasAprob > 25) {
			cout << "\nAlumno " << i + 1 << ":" << endl;
			datos[i].imprimeDatos();
		}
	}
}

void ArregloAlumnos::mostrarPromGrupalIndividual()
{
	float sumTotal = 0;
	for(int i = 0; i < tam; i++) {
		cout << "\nAlumno " << i + 1 << ":" << endl;
		datos[i].imprimeDatos();
		sumTotal += datos[i].calculaPromedio();
	}
	cout << "\nPromedio de grupo: " << (sumTotal / tam) << endl;
}

void ArregloAlumnos::darDeBajaConMasMatReprobQueAprob()
{
	for(int i = 0; i < tam; i++) {
		if(datos[i].nroMateriasReprob > datos[i].nroMateriasAprob) {
			eliminar(i);
		}
	}
}

int menuOpciones()
{
	int opc;
	
	do {
		cout << "1-Ingresar alumnos por carrera" << endl;
		cout << "2-Promedio de alumnos (por cada uno y total)" << endl;
		cout << "3-Cambiar carrera por posicion" << endl;
		cout << "4-Alumnos con mas de 25 materias aprobadas" << endl;
		cout << "5-Dar de baja a alumnos con mat. desap. mayores o iguales a mat. aprob" << endl;
		cout << "6-Dar de alta a un nuevo alumno" << endl;
		cout << "7-Ver todos" << endl;
		cout << "8-Salir" << endl;
		cout << "Ingrese opcion: ";
		cin >> opc;
	} while(opc < 1 || opc > 8);
	return opc;
}

int main()
{
	ArregloAlumnos alumnos = ArregloAlumnos();
	Alumno alm;

	int opc, resul, sumTotal, pos, numAlum;
	char carrera[60];
	do {
		opc = menuOpciones();
		switch (opc)
		{
			case 1: {
				cout << "Cantidad de alumnos: ";
				cin >> numAlum;
				cout << "Carrera: ";
				cin.ignore();
				cin.getline(carrera, 60);
				for(pos = 0; pos < numAlum; pos++) {
					alm = Alumno();
					alm.lecturaPorCarrera(carrera);
					alumnos.insertar(alm);
				}
				break;
			}
			case 2: {
				alumnos.mostrarPromGrupalIndividual();
				break;
			}

			case 3: {
				cout << "Posicion: ";
				cin >> pos;
				if(pos < alumnos.tamanio() && pos >= 0) {
					cout << "Nueva carrera: ";
					cin.ignore();
					cin.getline(carrera, 60);
					alumnos.obtener(pos)->cambiaCarrera(carrera);
				} else {
					cout << "No existe el alumno" << endl;
				}
				break;
			}
			case 4: {
				alumnos.mostrarConMasDe25MatAprob();
				break;
			}

			case 5: {
				alumnos.darDeBajaConMasMatReprobQueAprob();
				break;
			}

			case 6: {
				alm = Alumno();
				alm.lectura();
				resul = alumnos.insertar(alm);
				if(resul == 1) {
					cout << "Alumno registrado" << endl;
				} else if(resul == 0) {
					cout << "No se pudo registrar el alumno" << endl;
				}
				break;
			}

			case 7: {
				alumnos.escritura();
				break;
			}

			case 8: {
				cout << "Programa terminado" << endl;
				break;
			}
		
		}
		getch();
	} while(opc != 8);

	return 0;
}