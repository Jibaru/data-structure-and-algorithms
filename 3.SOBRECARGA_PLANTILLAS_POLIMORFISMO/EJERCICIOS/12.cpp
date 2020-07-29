/*
12.	Considere la siguiente relación de herencia entre una clase abstracta y 
dos clases concretas. 
Decida qué atributos y métodos incluir de tal manera que su programa pueda:
a) Crear un objeto llamado Soldadora, de tipo HerramientasPlomero y otro 
llamado Serrucho, de tipo HerramientasCarpintero.
b)	Cambiar el precio del objeto Soldadora. El usuario dará como dato el nuevo
 precio.
c)	Cambiar el color del objeto Serrucho.
d)	Imprimir los datos de los objetos creados y modificados. 
Clase Abstracta: Herramientas
Clases Concretas: HerramientasPlomero, HerramientasCarpintero
*/
#include <iostream>
#include <string.h>

using namespace std;

class Herramientas {
protected:
	char Nombre[64];
	char Color[64];
	float Precio;
public:
	Herramientas();
	Herramientas(char*, char*, float);
	void imprimir();
	void cambiarColor(char*);
	void cambiarPrecio(float);
	virtual void ejecutarAccion() = 0;
};

Herramientas::Herramientas() {}

Herramientas::Herramientas(char* nom, char* col, float prec)
{
	strcpy(Nombre, nom);
	strcpy(Color, col);
	Precio = prec;
}

void Herramientas::cambiarColor(char* col)
{
	strcpy(Color, col);
}

void Herramientas::cambiarPrecio(float prec)
{
	Precio = prec;
}

void Herramientas::imprimir()
{
	cout << "Nombre: " << Nombre << endl;
	cout << "Color: " << Color << endl;
	cout << "Precio: " << Precio << endl;
}

class HerramientasPlomero : public Herramientas {
private:
	char Plomero[64];
public:
	HerramientasPlomero();
	HerramientasPlomero(char*, char*, float, char*);
	void imprimir();
	void ejecutarAccion();
};

HerramientasPlomero::HerramientasPlomero() {}

HerramientasPlomero::HerramientasPlomero(char* nom, char* col, float prec, char* plom) :
					 Herramientas(nom, col, prec)
{
	strcpy(Plomero, plom);
}

void HerramientasPlomero::imprimir()
{
	Herramientas::imprimir();
	cout << "Plomero: " << Plomero << endl << endl;
}

void HerramientasPlomero::ejecutarAccion()
{
	cout << "La herramienta " << Nombre << " la usa el plomero " << Plomero << endl;
}

class HerramientasCarpintero : public Herramientas {
private:
	char Carpintero[64];
public:
	HerramientasCarpintero();
	HerramientasCarpintero(char*, char*, float, char*);
	void imprimir();
	void ejecutarAccion();
};

HerramientasCarpintero::HerramientasCarpintero() {}

HerramientasCarpintero::HerramientasCarpintero(char* nom, char* col, float prec, char* carp) :
					 Herramientas(nom, col, prec)
{
	strcpy(Carpintero, carp);
}

void HerramientasCarpintero::imprimir()
{
	Herramientas::imprimir();
	cout << "Carpintero: " << Carpintero << endl << endl;
}

void HerramientasCarpintero::ejecutarAccion()
{
	cout << "La herramienta " << Nombre << " la usa el carpintero " << Carpintero << endl;
}

int main() {
	
	float precio;
	char color[64];
	
	HerramientasPlomero Soldadora((char*)"Soldadora", (char*)"Amarilla", 1600, (char*)"Pedro");
	HerramientasCarpintero Serrucho((char*)"Serrucho", (char*)"Gris", 400, (char*)"Luis");
	
	Soldadora.imprimir();
	Serrucho.imprimir();
	
	cout << "Nuevo precio para soldadora: ";
	cin >> precio;
	
	Soldadora.cambiarPrecio(precio);
	
	cout << "Nuevo color para serrucho: ";
	cin.ignore();
	cin.getline(color, 64);
	
	Serrucho.cambiarColor(color);
	
	cout << "Objetos modificados:" << endl;
	Soldadora.imprimir();
	Soldadora.ejecutarAccion();
	Serrucho.imprimir();
	Serrucho.ejecutarAccion();
	
	
	return 0;
}