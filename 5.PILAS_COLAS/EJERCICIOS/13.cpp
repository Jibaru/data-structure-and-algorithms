/*
13.	Retome el problema anterior. Escriba un programa en C++ que permita 
eliminar de la cola de espera de la Dirección escolar a todos aquellos 
alumnos cuya carrera sea igual a un cierto valor dado por el usuario.
*/
#include <iostream>
#include <conio.h>
#include "../EJEMPLOS/5.7.cpp"
#include <string.h>

using namespace std;

class Alumno {
private:
	char nombre[60];
	char carrera[60];
	float notas[60];
	int cantNotas;
public:
	Alumno();
	Alumno(char[], char[], float[], int);
	float CalcularPromedio();
	int CantidadMatAprobadas();
	char* ObtenerCarrera();
	void ImprimeDatos();
	void ImprimeConstancia();
	friend istream& operator>>(istream&, Alumno&);
};

Alumno::Alumno(){}

Alumno::Alumno(char nombre[], char carr[], float notas[], int cantNotas)
{
	strcpy(this->nombre, nombre);
	strcpy(carrera, carr);
	this->cantNotas = cantNotas;
	for(int i = 0; i < cantNotas; i++){
		this->notas[i] = notas[i];
	}
}

float Alumno::CalcularPromedio()
{
	float sum = 0;
	for(int i = 0; i < cantNotas; i++){
		sum += notas[i];
	}
	return sum / cantNotas;
}

int Alumno::CantidadMatAprobadas()
{
	int sum = 0;
	for(int i = 0; i < cantNotas; i++){
		if(notas[i] >= 10.5) {
			sum ++;
		}
	}
	return sum;
}

char* Alumno::ObtenerCarrera()
{
	return carrera;
}

void Alumno::ImprimeDatos()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Carrera: " << carrera << endl;
	cout << "Cantidad de notas: " << cantNotas<< endl;
	cout << "Notas: ";
	for(int i = 0; i < cantNotas; i++){
		cout << notas[i] << " ";
	}
}

void Alumno::ImprimeConstancia()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Carrera: " << carrera << endl;
	cout << "Materias Aprob.: " <<  CantidadMatAprobadas() << endl;
	cout << "Promedio: " << CalcularPromedio() << endl;
}

istream& operator>>(istream& entrada, Alumno& obj)
{
	cout << "Nombre: ";
	entrada >> obj.nombre;
	cout << "Carrera: ";
	entrada >> obj.carrera;
	cout << "Cantidad notas: ";
	entrada >> obj.cantNotas;
	cout << "Notas: " << endl;
	for(int i = 0; i < obj.cantNotas; i++) {
		cout << "Nota " << i + 1 << ": ";
		entrada >> obj.notas[i];
	}
	
	return entrada;
}

int menuOpciones()
{
	int opc;
	
	do {
		cout << "1-Dar de alta solicitud" << endl;
		cout << "2-Generar constancia" << endl;
		cout << "3-Ver cola" << endl;
		cout << "4-Quitar de la cola por carrera" << endl;
		cout << "5-Salir" << endl;
		cin >> opc;
	}while(opc < 1 || opc > 5);
	
	return opc;
}

int main()
{
	ColaCircular<Alumno> colaCircular = ColaCircular<Alumno>();
	ColaCircular<Alumno> aux;
	int opc, resul;
	char carrera[60];
	Alumno alumno;
	
	do {
		
		opc = menuOpciones();
		
		switch(opc) {
			case 1: {
				alumno = Alumno();
				cout << "Datos del alumno: " << endl;
				cin >> alumno;
				resul = colaCircular.InsertaCCircular(alumno);
				if(resul == 1) {
					cout << "Solicitud en la cola" << endl;
				} else {
					cout << "Cola llena" << endl;
				}
				break;
			}
			case 2: {
				
				resul = colaCircular.EliminaCCircular(&alumno);
					
				if(resul == 1) {
					cout << "Constancia:"<< endl;
					alumno.ImprimeConstancia();
				} else {
					cout << "Cola vacia" << endl;
				}
				break;
			}
			case 3: {
				aux = colaCircular;
				
				if(aux.ColaCircularVacia() == 1){
					cout << "Cola vacia" << endl;
				} else {
					while(aux.ColaCircularVacia() != 1) {
						cout << endl;
						aux.EliminaCCircular(&alumno);
						alumno.ImprimeDatos();
						cout << endl;
					}
				}
				
				break;
			}
			case 4: {
				cout << "Ingrese carrera: ";
				cin >> carrera;
				
				aux = colaCircular;
				while(colaCircular.ColaCircularVacia() != 1) {
					colaCircular.EliminaCCircular(&alumno);
				}
				while(aux.ColaCircularVacia() != 1) {
					aux.EliminaCCircular(&alumno);
					if(strcmp(alumno.ObtenerCarrera(), carrera) != 0) {
						colaCircular.InsertaCCircular(alumno);
					}
				}
				
				break;
			}
			case 5: {
				cout << "Fin del programa" << endl;
				break;
			}
		}
		getch();
	} while(opc != 5);

	return 0;
}
