/*
11.	Implemente la clase base Cuadrilátero, con atributos Base y Altura y un 
método CaiculaArea que calcule el área del cuadrilátero. Implemente también 
las clases derivadas Cuadrado, Rectángulo y Trapezoide. Use un objeto 
polimórfico para calcular el área de un objeto de cada una de estas clases.
*/
#include <iostream>

using namespace std;

class Cuadrilatero {
protected:
	float Base;
	float Altura;
public:
	Cuadrilatero();
	Cuadrilatero(float, float);
	float calcularArea();
};

Cuadrilatero::Cuadrilatero() {}

Cuadrilatero::Cuadrilatero(float base, float altura)
{
	Base = base;
	Altura = altura;
}

float Cuadrilatero::calcularArea()
{
	return Base * Altura;
}

class Cuadrado : public Cuadrilatero {
public:
	Cuadrado();
	Cuadrado(float);
};

Cuadrado::Cuadrado() {}

Cuadrado::Cuadrado(float lado) : Cuadrilatero(lado, lado) {}

class Rectangulo : public Cuadrilatero {
public:
	Rectangulo();
	Rectangulo(float, float);
};

Rectangulo::Rectangulo() {}

Rectangulo::Rectangulo(float lado1, float lado2) : 
			Cuadrilatero(lado1, lado2) {}

class Trapezoide : public Cuadrilatero {
public:
	Trapezoide();
	Trapezoide(float, float);
	float calcularArea();
};

Trapezoide::Trapezoide(){}

Trapezoide::Trapezoide(float base, float altura) : 
			Cuadrilatero(base, altura){}
			
float Trapezoide::calcularArea()
{
	return 2 * Cuadrilatero::calcularArea();
}

int main() {
	
	Cuadrilatero cuadrilatero;
	
	cuadrilatero = Cuadrado(6);
	
	cout << "Area cuadrado: " << cuadrilatero.calcularArea() << endl;
	
	cuadrilatero = Rectangulo(14, 17.6);
	
	cout << "Area rectangulo: " << cuadrilatero.calcularArea() << endl;
	
	cuadrilatero = Trapezoide(2.3, 5.4);
	
	cout << "Area trapezoide: " << cuadrilatero.calcularArea() << endl;
	
	return 0;
}