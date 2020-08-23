/*
16.	Defina la clase SocioClub según las especificaciones que se dan más adelante. 
Utilice alguna de las plantillas previamente definidas para declarar un arreglo 
de objetos de la clase SocioClub. Escriba un programa en C++, que mediante menús pueda:
a)	Leer y validar N (1< N < 60).
b)	Leer los N elementos del arreglo.
c)	Imprimir los datos de todos los socios con más de 10 años de antigüedad.
d)	Cambiar el domicilio de un socio.
é) Dado el número de un socio, imprimir toda su información.
f)	Dar de alta un nuevo socio.
g)	Dar de baja un socio existente.
SocioClub
NúmeroSocio: int 
NombreSocio: char[]
Domicilio: char[]
AñoIngreso: int 
Métodos de acceso y actualización
*/
#include "../EJEMPLOS/4.1.cpp"
#include <conio.h>
#include <string.h>

class SocioClub {
private:
	int NumeroSocio;
	char NombreSocio[60];
	char Domicilio[60];
	int AnioIngreso;
public:
	SocioClub();
	SocioClub(int nroSoc, char nombre[], char dom[], int anio);
	void imprimirDatos();
	int regresaNumeroSocio();
	int regresaAnio();
	void cambiaDomicilio(char dom[]);
	bool operator!=(SocioClub&);
	bool operator==(SocioClub&);
	friend istream& operator >>(istream&, SocioClub&);
};

SocioClub::SocioClub(){}

SocioClub::SocioClub(int nroSoc, char nombre[], char dom[], int anio)
{
	strcpy(NombreSocio, nombre);
	strcpy(Domicilio, dom);
	NumeroSocio = nroSoc;
	AnioIngreso = anio;
}

void SocioClub::imprimirDatos()
{
	cout << "Nro Socio: " << NumeroSocio << endl;
	cout << "Nombre Socio: " << NombreSocio << endl;
	cout << "Domicilio: " << Domicilio << endl;
	cout << "Anio Ingreso: " << AnioIngreso << endl;
}

int SocioClub::regresaNumeroSocio()
{
	return NumeroSocio;
}

int SocioClub::regresaAnio()
{
	return AnioIngreso;
}

void SocioClub::cambiaDomicilio(char dom[])
{
	strcpy(Domicilio, dom);
}

bool SocioClub::operator!=(SocioClub& otro)
{
	if(NumeroSocio == otro.NumeroSocio){
		return false;
	}
	if(AnioIngreso == otro.AnioIngreso) {
		return false;
	}
	
	if(strcmp(NombreSocio, otro.NombreSocio) == 0) {
		return false;
	}
	
	if(strcmp(Domicilio, otro.Domicilio) == 0) {
		return false;
	}
	
	return true;
}

bool SocioClub::operator==(SocioClub& otro)
{
	return !(*this != otro);
}

istream& operator>>(istream& entrada, SocioClub& socio)
{
	cout << "Nro Socio: ";
	cin >> socio.NumeroSocio;
	
	cout << "Nombre Socio: ";
	entrada.ignore();
	entrada.getline(socio.NombreSocio, 60);
	
	cout << "Domicilio: ";
	entrada.getline(socio.Domicilio, 60);
	
	cout << "Anio Ingreso: ";
	entrada >> socio.AnioIngreso;

	
	return entrada;
}

int menuOpciones()
{
	int opc;
	do {
		cout << "1-Leer Socios" << endl;
		cout << "2-Ver Socios" << endl;
		cout << "3-Socios con mas de 10 anios de antiguedad" << endl;
		cout << "4-Cambiar domicilio de un socio" << endl;
		cout << "5-Imprimir socio por numero socio" << endl;
		cout << "6-Dar de alta a nuevo socio" << endl;
		cout << "7-Dar de baja a un socio" << endl;
		cout << "8-Salir" << endl;
		cout << "Ingrese opcion: ";
		cin >> opc;
	} while(opc < 1 || opc > 8);
	
	return opc;
}

int main()
{
	Arreglo<SocioClub> socios = Arreglo<SocioClub>();
	SocioClub socioTemp = SocioClub();
	int opc, tam, i;
	do {
		opc = menuOpciones();
		
		switch(opc){
			case 1: {
				do {
					cout << "\n\n Ingrese total de elementos: ";
					cin >> tam;
				} while (tam < 1 || tam > 60);
				for(i = 0; i < tam; i++) {
					cout << "\nSocio " << i + 1 << ":" << endl;
					cin >> socioTemp;
					socios.InsertaDesordenado(socioTemp);
				}
				
				break;
			}
		}
		getch();
		
	} while(opc != 8);
	
	return 0;
}