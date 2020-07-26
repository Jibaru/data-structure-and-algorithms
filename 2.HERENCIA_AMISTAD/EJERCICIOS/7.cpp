/*
7.	Considere las siguientes relaciones de herencia. Defina todas las clases que aparecen en el esquema. Decida qué atributos y métodos incluir de tal manera que su programa pueda:
á) Declarar y crear objetos de cualquiera de las clases sin utilizar métodos de lectura para asignar valores a los atributos.
b)	Imprimir los atributos de cualquiera de los objetos declarados. 
c)	Actualizar las dimensiones de un objeto tipo Casas. El usuario deberá proporcionar el nuevo número de metros cuadrados de la casa.
d)	Actualizar el giro de una industria. Es decir, a un objeto tipo industria se le podrá cambiar el valor de un atributo que representa el tipo de actividad que desarrolla dicha industria.
é) Actualizar el número de teléfono de cualquiera de los objetos declarados.

*/
#include <iostream>
#include <string.h>
using namespace std;

class Vivienda {
protected:
	char* telefono;
	float metrosCuadrados;
	char* direccion;
public:
	Vivienda(char*, float, char*);
	void imprimir();
	void cambiarTelefono(char*);
	void cambiarMetrosCuadrados(float);
};

Vivienda::Vivienda(char* telf, float metCuad, char* direc)
{
	telefono = new char[strlen(telf) + 1];
	direccion = new char[strlen(direc) + 1];
	strcpy(telefono, telf);
	strcpy(direccion, direc);
	metrosCuadrados = metCuad;
}

void Vivienda::imprimir()
{
	cout << "Telefono: " << telefono << endl;
	cout << "Direccion: " << direccion << endl;
	cout << "Metros Cuadrados: " << metrosCuadrados << endl;
}

void Vivienda::cambiarTelefono(char* telf)
{
	telefono = new char[strlen(telf) + 1];
	strcpy(telefono, telf);
}

void Vivienda::cambiarMetrosCuadrados(float mt)
{
	metrosCuadrados = mt;
}

class Residencial : public Vivienda {
protected:
	int nroFamilias;
public:
	Residencial(char*, float, char*, int);
	void imprimir();
};

Residencial::Residencial(char* telf, float metCuad, char* direc, int numFam):
			 Vivienda(telf, metCuad, direc)
{
	nroFamilias = numFam;
}

void Residencial::imprimir()
{
	Vivienda::imprimir();
	cout << "Nro Familias: " << nroFamilias << endl;
}

class Comercial : public Vivienda {
protected:
	int nroComerciantes;
public:
	Comercial(char*, float, char*, int);
	void imprimir();
};

Comercial::Comercial(char* telf, float metCuad, char* direc, int numComr):
		   Vivienda(telf, metCuad, direc)
{
	nroComerciantes = numComr;
}

void Comercial::imprimir()
{
	Vivienda::imprimir();
	cout << "Nro Comerciantes: " << nroComerciantes << endl;
}

class Departamento : public Residencial {
private:
	int nroPersonas;
public:
	Departamento(char*, float, char*, int, int);
	void imprimir();
};

Departamento::Departamento(char* telf, float metCuad, char* direc, int numFam, int numPer):
			  Residencial(telf, metCuad, direc, numFam)
{
	nroPersonas = numPer;
}

void Departamento::imprimir()
{
	Residencial::imprimir();
	cout << "Nro Personas: " << nroPersonas << endl;
}

class Casa : public Residencial {
private:
	int nroIntegrantes;
public:
	Casa(char*, float, char*, int, int);
	void imprimir();
};

Casa::Casa(char* telf, float metCuad, char* direc, int numFam, int numInteg):
			  Residencial(telf, metCuad, direc, numFam)
{
	nroIntegrantes = numInteg;
}

void Casa::imprimir()
{
	Residencial::imprimir();
	cout << "Nro Integrante: " << nroIntegrantes << endl;
}

class Industria : public Comercial {
private:
	char* giro;
public:
	Industria(char*, float, char*, int, char*);
	void imprimir();
	void cambiarGiro(char*);
};

Industria::Industria(char* telf, float metCuad, char* direc, int numComer, char* gir):
			  Comercial(telf, metCuad, direc, numComer)
{
	giro = new char[strlen(gir) + 1];
	strcpy(giro, gir);
}

void Industria::imprimir()
{
	Comercial::imprimir();
	cout << "Giro: " << giro << endl;
}

void Industria::cambiarGiro(char* gir)
{
	giro = new char[strlen(gir) + 1];
	strcpy(giro, gir);
}

class Oficina : public Comercial {
private:
	char* actividad;
public:
	Oficina(char*, float, char*, int, char*);
	void imprimir();
};

Oficina::Oficina(char* telf, float metCuad, char* direc, int numComer, char* actv):
			  Comercial(telf, metCuad, direc, numComer)
{
	actividad = new char[strlen(actv) + 1];
	strcpy(actividad, actv);
}

void Oficina::imprimir()
{
	Comercial::imprimir();
	cout << "Actividad: " << actividad << endl;
}

int main() {

	Casa casa = Casa((char*)"2315050", 34.5, (char*) "La perla", 4, 5);
	Departamento departamento = Departamento((char*)"423212", 67.7, (char*)"San jose", 6, 78);
	Industria industria = Industria((char*)"99893423", 76.3, (char*)"Calle Las Palomas", 7, (char*)"Venta de alamanaques");

	casa.imprimir();
	cout << endl;
	departamento.imprimir();
	cout << endl;
	industria.imprimir();
	cout << endl;

	casa.cambiarMetrosCuadrados(76.5);
	industria.cambiarGiro((char*)"Venta de libros");
	departamento.cambiarTelefono((char*)"8743232");

	casa.imprimir();
	cout << endl;
	departamento.imprimir();
	cout << endl;
	industria.imprimir();
	cout << endl;

	return 0;
}