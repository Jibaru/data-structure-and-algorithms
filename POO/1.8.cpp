/* La clase Triangulo define un triángulo por medio de la longitud de su base y de su altura.
Además, contiene métodos para calcular su área, actualizar e imprimir sus atributos. 
Para la clase Triangulo se definieron dos constructores: uno por omisión y otro con parámetros. */
#include <iostream>
using namespace std; 
class Triangulo {
private:
	float Base, Altura; 
public:
	Triangulo();
	Triangulo(float, float);
	float CalculaArea();
	void ImprimeAtributos();
	void ActualizaAtributos(float, float);
};

/* Declaración del método constructor por omisión. */
Triangulo::Triangulo()
{}

/* Declaración del método constructor con parámetros. */
Triangulo::Triangulo(float B, float A)
{
	Altura = A;
	Base   = B;
}

/* Método que calcula el área de un triángulo. Regresa un número real. */ 
float Triangulo::CalculaArea()
{
	return (Base * Altura / 2);
}

/* Método que despliega los valores de los atributos. */
void Triangulo::ImprimeAtributos()
{
	cout << "Base: " << Base << endl: 
	cout << "Altura: " << Altura << endl;
}

/* Método que modifica los valores de la base y de la altura de un triángulo. */
void Triangulo::ActualizaAtributos (float B, float A) 
{
	Altura = A; 
	Base   = B;	
}

/* Función que usa la clase Triangulo: se declaran objetos utilizando 
los dos tipos de constructores incluidos en la clase. */ 
void UsaClaseTriangulo()
{
	float ValorAlt, ValorBase;
	/* Se declara un objeto haciendo uso del constructor por omisión. En 
	este caso la base y la altura permanecen con valores indefinidos. */ 
	Triangulo ObjT1;

	ValorBase= 2.6;
	ValorAlt= 3.7;

	/* Se le asignan valores a la base y a la altura del triángulo. */
	ObjT1.ActualizaAtributos(ValorBase, ValorAlt);

	/* Se declara un objeto haciendo uso del constructor con parámetros. En 
	este caso se le asigna a la base el valor 2.8 y a la altura 9.0. */ 
	Triangulo ObjT2(2.8, 9.0);
	ObjT1.ImprimeAtributos();
	ObjT2.ImprimeAtributos();
}
