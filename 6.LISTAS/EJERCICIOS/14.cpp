/*
14.	Escriba un programa, que usando una lista doblemente ligada, pueda 
almacenar y manipular información relacionada a socios de un club deportivo.
La especificación de los datos correspondientes a cada socio se presenta 
a continuación. El programa debe permitir a los usuarios, por medio de un menú, 
llevar a cabo las siguientes operaciones:
a)	Registrar un nuevo socio. Considere que no puede haber dos socios con 
el mismo número (NumeroSocio). La lista de socios debe ir quedando ordenada 
de menor a mayor, según el número de socio.
b)	Dar de baja un socio del club.
c)	Generar un reporte con todos los socios que tengan una antigüedad mayor o 
igual a una proporcionada por el usuario.
d)	Cambiar el domicilio de un socio registrado.
e) Generar un reporte con los datos de todos los socios.
f) Calcular e imprimir el total de socios registrados.
SocioClub
NumeroSocio: int
NombreSocio: char[]
Domicilio: char[]
AnioIngreso: int
Métodos de acceso y actualización
*/
#include <iostream>
#include <string.h>
#include <conio.h>
#include "../../lib/listas/ListasDobLig.h"

using namespace std;

class SocioClub
{
private:
	int NumeroSocio;
	char NombreSocio[60];
	char Domicilio[60];
	int AnioIngreso;
public:
	SocioClub();
	SocioClub(int);
	void cambiaDomicilio(char[]);
	int regresaAnioIngreso();
	int operator==(SocioClub&);
	int operator!=(SocioClub&);
	int operator<(SocioClub&);
	int operator>(SocioClub&);
	friend ostream& operator<<(ostream&, SocioClub&);
	friend istream& operator>>(istream&, SocioClub&);
};

SocioClub::SocioClub()
{}

SocioClub::SocioClub(int cod)
{
	NumeroSocio = cod;
}

void SocioClub::cambiaDomicilio(char dom[])
{
	strcpy(Domicilio, dom);
}

int SocioClub::regresaAnioIngreso()
{
	return AnioIngreso;
}

int SocioClub::operator==(SocioClub& obj)
{
	return NumeroSocio == obj.NumeroSocio;
}

int SocioClub::operator!=(SocioClub& obj)
{
	return NumeroSocio != obj.NumeroSocio;
}

int SocioClub::operator<(SocioClub& obj)
{
	return NumeroSocio < obj.NumeroSocio;
}

int SocioClub::operator>(SocioClub& obj)
{
	return NumeroSocio > obj.NumeroSocio;
}

ostream& operator<<(ostream& salida, SocioClub& s)
{
	salida << "Numero socio: " << s.NumeroSocio << endl;
	salida << "Nombre socio: " << s.NombreSocio << endl;
	salida << "Domicilio: " << s.Domicilio << endl;
	salida << "Anio ingreso: " << s.AnioIngreso << endl;
	return salida;
}

istream& operator>>(istream& entrada, SocioClub& s)
{
	cout << "Numero socio: ";
	entrada >> s.NumeroSocio;
	cout << "Nombre socio: ";
	entrada.ignore();
	entrada.getline(s.NombreSocio, 60);
	cout << "Domicilio: ";
	entrada.getline(s.Domicilio, 60);
	cout << "Anio ingreso: ";
	entrada >> s.AnioIngreso;
	
	return entrada;
}

int menuOpciones()
{
	int Opc;
	do {
		cout << "1-Registrar nuevo socio" << endl;
		cout << "2-Dar de baja a socio" << endl;
		cout << "3-Reporte de socios de acuerdo a entiguedad" << endl;
		cout << "4-Cambiar domicilio de algun socio" << endl;
		cout << "5-Reporte de todos los socios" << endl;
		cout << "6-Total de socios" << endl;
		cout << "7-Salir del programa" << endl;
		cout << "Ingrese opcion: ";
		cin >> Opc;
		cout << endl;
	} while(Opc < 1 || Opc > 7);
	return Opc;
}

int main()
{
	ListaDobLiga<SocioClub> lista = ListaDobLiga<SocioClub>();
	int opc, codigo, resp, tamanio = 0;
	char domicilio[60];
	SocioClub socio;
	NodoDobleLiga<SocioClub>* primero, *buscado;
	do {
		
		opc = menuOpciones();
		switch(opc) {
			case 1: {
				socio = SocioClub();
				cin >> socio;
				lista.InsertaOrdenado(socio);
				tamanio++;
				break;
			}
			case 2: {
				cout << "Ingrese numero socio: ";
				cin >> codigo;
				socio = SocioClub(codigo);
				resp = lista.EliminaUnNodo(socio);
				if(resp == 0) {
					cout << "Socio no existe" << endl;
				} else if (resp == -1) {
					cout << "Lista vacia" << endl;
				} else if (resp == 1) {
					cout << "Socio eliminado" << endl;
					tamanio--;
				}
				break;
			}
			case 3: {
				// No se puede sin modificar la lista :V
				break;
			}
			case 4: {
				cout << "Ingrese numero socio: ";
				cin >> codigo;
				socio = SocioClub(codigo);
				primero = lista.RegresaPrimero();
				buscado = lista.Busca(socio, primero);
				if(buscado) {
					cout << "Nuevo Domicilio: ";
					cin.ignore();
					cin.getline(domicilio, 60);
					socio = buscado->RegresaInfo();
					socio.cambiaDomicilio(domicilio);
					lista.EliminaUnNodo(socio);
					lista.InsertaOrdenado(socio);
				} else {
					cout << "No existe el socio" << endl;
				}
				break;
			}
			case 5: {
				primero = lista.RegresaPrimero();
				lista.ImprimeIzq_Der(primero);
				break;
			}
			case 6: {
				cout << "Total de socios: " << tamanio << endl;
				break;
			}
			case 7: {
				cout << "Fin del programa" << endl;
				break;
			}
		}
		
		getch();
		
	} while(opc != 7);
	
	return 0;
}