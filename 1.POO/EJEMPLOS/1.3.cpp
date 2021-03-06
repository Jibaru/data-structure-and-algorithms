/* La clase triángulo define un triángulo por medio de la longitud de su
base y de su altura. Además, contiene un método para calcular su área y
otro para imprimir sus atributos. */

#include <iostream>
#include <conio.h>
using namespace std;

class Triangulo
{
public:
	float base, altura;
	float calcularArea();
	void imprimeAtributos();
};

/* Método que calcula el área de un triángulo y regresa un número real
como resultado */
float Triangulo::calcularArea()
{
	return base * (altura / 2);
}

/* Método que imprime el valor de la base y de la altura de un 
triángulo */
void Triangulo::imprimeAtributos()
{
	cout << "Base: " << base << endl;
	cout << "Altura: " << altura << endl;
}

/* Función que usa la clase Triángulo: declara un objeto tipo Triangulo
y a través de los métodos imprime la base y la altura del triángulo y 
calcula e imprime su área */
void usaClaseTriangulo()
{
	/* Declaración de un objeto de tipo Triángulo */
	Triangulo objTriangulo;
	objTriangulo.base = 10.0;
	objTriangulo.altura = 20.0;
	float area;

	objTriangulo.imprimeAtributos();

	area = objTriangulo.calcularArea();
	cout << "Area del triangulo: " << area << endl;
}

int main(){

	usaClaseTriangulo();
	getch();
	return 0;
}