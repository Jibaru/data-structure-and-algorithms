/*
11.	Escriba un programa en C++, que mediante la plantilla de la cola 
circular presentada en este capítulo, simule el comportamiento de una 
cola de atención a clientes de un banco. La cola deberá almacenar 
objetos de la clase Clientes. Defina qué atributos y métodos deberá 
incluir esta clase. El programa leerá, mientras el usuario así lo 
requiera, dos posibles opciones de trabajo sobre la cola de espera 
de los clientes:
a)	Llega un nuevo cliente al banco, en cuyo caso debe ingresarse a la 
cola de espera. El usuario proporcionará los datos del cliente.
b)	Un cliente pasa a la ventanilla donde será atendido. El dato será el 
número de ventanilla a la que debe pasar.
Al finalizar el día de trabajo, su programa debe imprimir el total de 
clientes atendidos.
*/
#include <iostream>
#include <conio.h>
#include "../EJEMPLOS/5.7.cpp"
#include <string.h>

using namespace std;

class Cliente {
private:
	char nombre[60];
	char dni[9];
	int edad;
public:
	Cliente();
	Cliente(char[], char[], int);
	void ImprimirDatos();
	friend istream& operator>>(istream&, Cliente&);
};

Cliente::Cliente(){}

Cliente::Cliente(char nombre[], char dni[], int edad)
{
	strcpy(this->nombre, nombre);
	strcpy(this->dni, dni);
	this->edad = edad;
}

void Cliente::ImprimirDatos()
{
	cout << "Nombre: " << nombre << endl;
	cout << "DNI: " << dni << endl;
	cout << "Edad: " << edad << endl;
}

istream& operator>>(istream& entrada, Cliente& obj)
{
	cout << "Nombre: ";
	cin >> obj.nombre;
	cout << "DNI: ";
	cin >> obj.dni;
	cout << "Edad: ";
	cin >> obj.edad;
	return entrada;
}

int menuOpciones()
{
	int opc;
	
	do {
		cout << "1-Ingresar cliente a la cola espera" << endl;
		cout << "2-Pasar a ventanilla" << endl;
		cout << "3-Ver cola" << endl;
		cout << "4-Salir" << endl;
		cin >> opc;
	}while(opc < 1 || opc > 4);
	
	return opc;
}

int main()
{
	ColaCircular<Cliente> colaCircular = ColaCircular<Cliente>();
	ColaCircular<Cliente> aux;
	int opc, resul, ventanilla;
	Cliente cli;
	
	do {
		
		opc = menuOpciones();
		
		switch(opc) {
			case 1: {
				cli = Cliente();
				cout << "Datos del cliente: " << endl;
				cin >> cli;
				resul = colaCircular.InsertaCCircular(cli);
				if(resul == 1) {
					cout << "Cliente en cola de espera" << endl;
				} else {
					cout << "Cola llena" << endl;
				}
				break;
			}
			case 2: {
				
				cout << "Ventanilla: ";
				cin >> ventanilla;
				
				resul = colaCircular.EliminaCCircular(&cli);
					
				if(resul == 1) {
					cout << "Pasar a ventanilla " << ventanilla << ":" << endl;
					cli.ImprimirDatos();
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
						aux.EliminaCCircular(&cli);
						cli.ImprimirDatos();
						cout << endl;
					}
				}
				
				break;
			}
			case 4: {
				cout << "Fin del programa" << endl;
				break;
			}
		}
		getch();
	} while(opc != 4);

	return 0;
}