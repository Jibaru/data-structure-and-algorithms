/* La clase Cliente define un cliente por medio de los atributos:
Nombre, Dirección, Teléfono, Saldo, Tipo de Cuenta y Número de Cuenta, 
y de los métodos que permiten el manejo de ellos. Para la clase Cliente 
se definieron dos constructores: uno con parámetros para algunos de los 
atributos y otro con parámetros por omisión. */ 

#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

class Cliente {
private:
	char Nombre[64], Direccion[32], Telefono[10];
	float Saldo;
	int TipoDeCuenta, NumDeCuenta;
public:
	Cliente(char Nom[], char Tel[], float Sal);
	Cliente(char Nom[], char Dir[], char Tel[], float Sal= 0,int tC= 1,int NoC= 0);
	float ObtenerSaldo();
	void ImprimeDatos();
	char ObtenerTipoCta();
	void HacerRetiro(float Monto);
	void HacerDeposito(float Monto);
};

/* Declaración del método constructor con parámetros. Se asignan valores 
a los atributos, tomando los que aparecen en el prototipo del constructor 
si el usuario no proporciona otros. */
Cliente::Cliente(char Nom[], char Dir[], char Tel[], float Sal, int TC, int NoC)
{
	strcpy(Nombre, Nom); 
	strcpy(Direccion, Dir); 
	strcpy(Telefono, Tel);
	Saldo        = Sal;
	TipoDeCuenta = TC;
	NumDeCuenta  = NoC;
}

/* Declaración del método constructor donde se asignan, por medio de tos parámetros,
 valores a algunos de los atributos y a otros se les dan ^valores por omisión. */
Cliente::Cliente(char Nom[], char Tel[], float Sal)
{
	strcpy(Nombre, Nom); 
	strcpy(Telefono, Tel);
	Saldo = Sal;
	strcpy(Direccion, "Desconocida");
	TipoDeCuenta =  0;
	NumDeCuenta  = -1;
}

/* Método que permite conocer el Saldo de un cliente. */ 
float Cliente::ObtenerSaldo()
{
	return Saldo;
}

/* Método que despliega en pantalla los valores de los atributos de un cliente. */
void Cliente::ImprimeDatos()
{
	cout << "Nombre: " << Nombre << endl;
	cout << "Direccion: " << Direccion << endl;
	cout << "Telefono: " << Telefono << endl;
	cout << "Saldo: " << Saldo << endl;
	cout << "Tipo de Cuenta: " << TipoDeCuenta << endl;
	cout << "Numero de Cuenta: " << NumDeCuenta << endl;
}

/* Función que muestra el uso de los dos tipos de constructores. */ 
void UsaClaseCliente()
{
	/* Se crean dos objetos de tipo Cliente usando los constructores ^definidos. */
	Cliente ObjCli1((char*)"Laura", (char*)"Insurgentes No. 2", (char*)"55559900", 28000, 2, 2);
	Cliente ObjCli2((char*)"Juan", (char*)"55408881", 4000);

	/* En el último objeto creado se dan valores para 3 de sus atributos, 
	por lo tanto el constructor asigna a los restantes los dados por ^omisión. */

	/* Se imprimen los datos de cada cliente. */
	ObjCli1.ImprimeDatos();
	ObjCli2.ImprimeDatos();
}

int main(){
	UsaClaseCliente();
	getch();
	return 0;
}