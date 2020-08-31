/*
10. Escriba un programa en C++, que mediante la plantilla de la cola circular 
presentada en este capítulo, simule el comportamiento de una cola de impresión. 
La cola deberá almacenar objetos de la clase impresión, cuyas especificaciones 
se dan a continuación. El programa leerá dos posibles opciones de trabajo sobre 
la cola de impresión: 
a) encolar un nuevo archivo a imprimir o 
b) imprimir un archivo. Su programa debe verificar que las opciones dadas por 
el usuario puedan realizarse, en caso contrario desplegará un mensaje adecuado.

NombreArchivo: char[]
Autor: char[]
HoraDeEncolar: char[]
Constructor(es).
Métodos de acceso y modificación a los miembros de la clase.

*/
#include <iostream>
#include <conio.h>
#include "../EJEMPLOS/5.7.cpp"
#include <string.h>

using namespace std;

class Impresion {
private:
	char NombreArchivo[60];
	char Autor[60];
	char HoraDeEncolar[60];
public:
	Impresion();
	Impresion(char[], char[]);
	void cambiaHoraDeEncolar(char[]);
	void ImprimirDatos();
	friend istream& operator>>(istream&, Impresion&);
};

Impresion::Impresion(){}

Impresion::Impresion(char nom[], char autor[])
{
	strcpy(NombreArchivo, nom);
	strcpy(Autor, autor);
}

void Impresion::cambiaHoraDeEncolar(char horaEncol[])
{
	strcpy(HoraDeEncolar, horaEncol);
}

void Impresion::ImprimirDatos()
{
	cout << "Nombre archivo: " << NombreArchivo << endl;
	cout << "Autor: " << Autor << endl;
	cout << "Hora de encolado: " << HoraDeEncolar << endl;
}

istream& operator>>(istream& entrada, Impresion& obj)
{
	cout << "Nombre archivo: ";
	entrada >> obj.NombreArchivo;
	cout << "Autor: ";
	entrada >> obj.Autor;
	return entrada;
}

int menuOpciones()
{
	int opc;
	
	do {
		cout << "1-Encolar nuevo archivo" << endl;
		cout << "2-Imprimir archivo" << endl;
		cout << "3-Ver cola" << endl;
		cout << "4-Salir" << endl;
		cin >> opc;
	}while(opc < 1 || opc > 4);
	
	return opc;
}

int main()
{
	ColaCircular<Impresion> colaCircular = ColaCircular<Impresion>();
	ColaCircular<Impresion> aux;
	int opc, resul;
	Impresion archivo;
	
	do {
		
		opc = menuOpciones();
		
		switch(opc) {
			case 1: {
				archivo = Impresion();
				cout << "Nuevo archivo: " << endl;
				cin >> archivo;
				resul = colaCircular.InsertaCCircular(archivo);
				if(resul == 1) {
					cout << "Archivo encolado" << endl;
				} else {
					cout << "Cola llena" << endl;
				}
				break;
			}
			case 2: {
				resul = colaCircular.EliminaCCircular(&archivo);
				archivo.cambiaHoraDeEncolar((char*)"06:22");
				if(resul == 1) {
					cout << "Se imprime el siguiente archivo: " << endl;
					archivo.ImprimirDatos();
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
						aux.EliminaCCircular(&archivo);
						archivo.ImprimirDatos();
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