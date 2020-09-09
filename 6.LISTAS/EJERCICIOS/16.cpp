/*
16.	En una empresa se necesita un sistema que permita manejar la información 
de los automóviles que tienen para su personal. Para representar los datos 
de los automóviles se debe tener en cuenta la clase Automóvil dada más abajo. 
Escriba un programa que, usando una lista circular doblemente ligada, pueda:
a) Registrar un automóvil nuevo. Considere que no puede haber dos automóviles 
con la misma clave que los identifica y que la lista debe ir quedando ordenada 
por clave.
b) Dar de baja un automóvil que ya no está disponible para el personal. 
c) Generar un reporte de todos los automóviles que sean de un cierto año. 
El año de interés será un dato dado por el usuario.
d) Generar un reporte de todos los automóviles cuyo precio sea superior a un 
monto dado por el usuario.
e) Dado el nombre de un empleado, imprimir los datos del automóvil que tiene asignado
f) Cambiar el nombre de la persona a la que está asignado un automóvil

Automovil
ClaveAuto: int
MarcaAuto: char[]
Modelo: char[]
AñoFabricacion: int
PrecioCompra: float
AsignadoA: char[]
Métodos de acceso y actualización
*/
#include <iostream>
#include <conio.h>
#include <string.h>
#include "15.cpp"

using namespace std;

class Automovil
{
private:
	int ClaveAuto;
	char MarcaAuto[60];
	char Modelo[60];
	int AnioFabricacion;
	float PrecioCompra;
	char AsignadoA[60];
public:
	Automovil();
	Automovil(int);
	Automovil(int, char[], char[], int, float, char[]);
	int regresaClaveAuto();
	float regresaPrecioCompra();
	int regresaAnioFabricacion();
	char* regresaAsignadoA();
	void cambiaAsignadoA(char[]);
	int operator==(Automovil&);
	int operator!=(Automovil&);
	int operator<(Automovil&);
	friend ostream& operator<<(ostream&, Automovil&);
	friend istream& operator>>(istream&, Automovil&);
};

Automovil::Automovil()
{ }

Automovil::Automovil(int clave)
{
	ClaveAuto = clave;
}

Automovil::Automovil(int cla, char marca[], char modelo[], int anio, float prec, char asignA[])
{
	ClaveAuto = cla;
	strcpy(MarcaAuto, marca);
	strcpy(Modelo, modelo);
	AnioFabricacion = anio;
	PrecioCompra = prec;
	strcpy(AsignadoA, asignA);
}

int Automovil::regresaClaveAuto()
{
	return ClaveAuto;
}

float Automovil::regresaPrecioCompra()
{
	return PrecioCompra;
}

int Automovil::regresaAnioFabricacion()
{
	return AnioFabricacion;
}

char* Automovil::regresaAsignadoA()
{
	return AsignadoA;
}

void Automovil::cambiaAsignadoA(char asignado[])
{
	strcpy(AsignadoA, asignado);
}

int Automovil::operator==(Automovil& obj)
{
	return ClaveAuto == obj.ClaveAuto;
}

int Automovil::operator!=(Automovil& obj)
{
	return ClaveAuto != obj.ClaveAuto;
}

int Automovil::operator<(Automovil& obj)
{
	return ClaveAuto < obj.ClaveAuto;
}

ostream& operator<<(ostream& salida, Automovil& a)
{
	salida << "Clave: " << a.ClaveAuto << endl;
	salida << "Marca: " << a.MarcaAuto << endl;
	salida << "Modelo: " << a.Modelo << endl;
	salida << "Anio Fabricacion: " << a.AnioFabricacion << endl;
	salida << "Precio: " << a.PrecioCompra << endl;
	salida << "Asignado a: " << a.AsignadoA << endl;
}

istream& operator>>(istream& entrada, Automovil& a)
{
	cout << "Clave auto: ";
	entrada >> a.ClaveAuto;
	cout << "Marca: ";
	entrada.ignore();
	entrada.getline(a.MarcaAuto, 60);
	cout << "Modelo: ";
	entrada.getline(a.Modelo, 60);
	cout << "Asignado A: ";
	entrada.getline(a.AsignadoA, 60);
	cout << "Anio Fabricacion: ";
	entrada >> a.AnioFabricacion;
	cout << "Precio: ";
	entrada >> a.PrecioCompra;
	
	return entrada;
}

int menuOpciones()
{
	int opc;
	
	do {
		cout << "1-Registrar nuevo automovil (no repe) " << endl;
		cout << "2-Dar de baja un automovil" << endl;
		cout << "3-Reporte de automoviles de cierto anio" << endl;
		cout << "4-Reporte de automoviles mayores a cierto precio" << endl;
		cout << "5-Automoviles por empleado" << endl;
		cout << "6-Cambiar empleado asignado por clave auto" << endl;
		cout << "7-Ver todos" << endl;
		cout << "8-Salir del sistema" << endl;
		cin >> opc;
		cout << endl;
	} while(opc < 1 || opc > 8);
	return opc;
}

int main()
{
	ListaCircularDoble<Automovil> lista = ListaCircularDoble<Automovil>();
	
	int opc, clave, resp, anio;
	float precio;
	char empleado[60];
	Automovil automovil, aux;
	NodoListaCirDob<Automovil>* it, *menor;
	
	do {
		opc = menuOpciones();
		
		switch(opc) {
			case 1: {
				automovil = Automovil();
				cin >> automovil;
				aux = Automovil(automovil.regresaClaveAuto());
				if(lista.buscaNodo(aux)) {
					cout << "El automovil ya existe" << endl;
				} else {
					lista.insertaOrdenada(automovil);
					cout << "Automovil ingresado" << endl;
				}
				break;
			}
			
			case 2: {
				cout << "Ingrese clave: ";
				cin >> clave;
				automovil = Automovil(clave);
				resp = lista.eliminaNodo(automovil);
				switch(resp) {
					case -1: {
						cout << "Lista vacia" << endl;
						break;
					}
					case 0: {
						cout << "No se encontro el automovil" << endl;
						break;
					}
					case 1: {
						cout << "Automovil fue dado de baja" << endl;
						break;
					}
				}
				break;
			}
			
			case 3: {
				cout << "Ingrese anio de fabricacion: ";
				cin >> anio;
				it = lista.regresaMenor();
				menor = it;
				while(it != menor->regresaAnterior()) {
					automovil = *(it->regresaInfo());
					if(anio == automovil.regresaAnioFabricacion()) {
						cout << automovil;
					}
					it = it->regresaSiguiente();
				}
				if(it == menor->regresaAnterior()) {
					automovil = *(it->regresaInfo());
					if(anio == automovil.regresaAnioFabricacion()) {
						cout << automovil;
					}
				}
				break;
			}
			case 4: {
				cout << "Ingrese precio compra: ";
				cin >> precio;
				it = lista.regresaMenor();
				menor = it;
				while(it != menor->regresaAnterior()) {
					automovil = *(it->regresaInfo());
					if(precio < automovil.regresaPrecioCompra()) {
						cout << automovil;
					}
					it = it->regresaSiguiente();
				}
				if(it == menor->regresaAnterior()) {
					automovil = *(it->regresaInfo());
					if(precio < automovil.regresaPrecioCompra()) {
						cout << automovil;
					}
				}
				break;
			}
			case 5: {
				cout << "Ingrese empleado asignado: ";
				cin.ignore();
				cin.getline(empleado, 60);
				it = lista.regresaMenor();
				menor = it;
				while(it != menor->regresaAnterior()) {
					automovil = *(it->regresaInfo());
					if(strcmp(empleado, automovil.regresaAsignadoA()) == 0) {
						cout << automovil;
					}
					it = it->regresaSiguiente();
				}
				if(it == menor->regresaAnterior()) {
					automovil = *(it->regresaInfo());
					if(strcmp(empleado, automovil.regresaAsignadoA()) == 0) {
						cout << automovil;
					}
				}
				break;
			}
			case 6: {
				cout << "Ingrese clave de auto: ";
				cin >> clave;
				automovil = Automovil(clave);
				it = lista.buscaNodo(automovil);
				if(it) {
					cout << "Ingrese nuevo empleado asignado: ";
					cin.ignore();
					cin.getline(empleado, 60);
					it->regresaInfo()->cambiaAsignadoA(empleado);
				} else {
					cout << "No se encontro el automovil" << endl;
				}
				break;
			}
			case 7: {
				cout << "\nLista de automoviles: \n";
				lista.imprimeLista();
				break;
			}
			case 8: {
				cout << "Fin del programa" << endl;
				break;
			}
		}
		
		getch();
		
	} while(opc != 8);
	
	return 0;
}