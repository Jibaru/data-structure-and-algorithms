/*2.	Considere la siguiente relación de herencia. Defina las clases vehículo, 
Terrestre y Marítimo. Decida qué atributos y métodos incluir de tal manera que su 
programa pueda:
á) Declarar un objeto llamado MiAuto de tipo Terrestre y otro llamado MíBarco de tipo 
Marítimo. La asignación de valores a los atributos debe hacerse a través de un método de
lectura, definido para tal fin.
b)	Imprimir los atributos de los objetos declarados en el inciso anterior.
c)	Actualizar el precio de MiAuto.
d)	Actualizar potencia de motores de MiBarco. ¿A qué clase debería perte¬necer el 
método que le permitirá hacer esta actualización?
é) Imprimir un mensaje que indique si MiAuto tiene o no más de 5 años de antigüedad.
f)	Imprimir el tipo de combustible que usa y la capacidad máxima del tanque de MiBarco.
*/
#include <iostream>
#include <string.h>

using namespace std;

class Vehiculo {
protected:
	float precio;
	char* tipoCombustible;
	int anioCreacion;
public:
	Vehiculo(float, char*, int);
	Vehiculo();
	void pedirDatos();
	void imprimirDatos();
	void actualizarPrecio(float);
	void imprimirTipoComb();
};

Vehiculo::Vehiculo(){}

Vehiculo::Vehiculo(float prec, char* tipoCom, int anio) 
{
	precio = prec;
	strcpy(tipoCombustible, tipoCom);
	anioCreacion = anio;
}

void Vehiculo::pedirDatos() 
{
	cout << "Precio: ";
	cin >> precio;
	cout << "Tipo comb.: ";
	cin >> tipoCombustible;
	cout << "Anio Crea: ";
	cin >> anioCreacion;
}

void Vehiculo::imprimirDatos() 
{
	cout << "Precio: " << precio << endl;
	cout << "Tipo Comb: " << tipoCombustible << endl;
	cout << "Anio Crea: " << anioCreacion << endl;
}

void Vehiculo::actualizarPrecio(float prec) 
{
	precio = prec;
}

void Vehiculo::imprimirTipoComb() 
{
	cout << "Tipo Comb: " << tipoCombustible << endl;
}

class Terrestre : public Vehiculo {
public:
	Terrestre(float, char*, int);
	void tieneMasDe5Anios();
};

Terrestre::Terrestre(float prec, char* tipoComb, int anio):
		   Vehiculo(prec, tipoComb, anio){}

void Terrestre::tieneMasDe5Anios() {
	if(2020 - anio >= 5){
		cout << "Tiene mas de 5 anios" << endl;
	} else {
		cout << "No tiene mas de 5 anios" << endl;
	}
}

class Maritimo : public Vehiculo {
private:
	char* potenciaMotores;
	float capacidadMax;
public:
	Maritimo(float, char*, int, char*, float);
	void actualizarPotenciaMot(char*);
	void imprimirTipoCombCapMax();
}

Maritimo::Maritimo(float prec, char* tipoComb, int anio, char* potencia, float cap) :
		  Vehiculo(prec, tipoComb, anio)
{
	strcpy(potenciaMotores, potencia);
	capacidadMax = cap;
}

void Maritimo::actualizarPotenciaMot(char* pot)
{
	strcpy(potenciaMotores, pot);
}

void Maritimo::imprimirTipoCombCapMax()
{
	cout << "Tipo Combustible: " << tipoCombustible << endl;
	cout << "Cap. Max: " << capacidadMax << endl;
}

int main() {
	

	return 0;
}