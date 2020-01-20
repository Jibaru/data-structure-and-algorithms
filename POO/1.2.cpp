/* La clase Punto contiene como atributos privados las coordernadas en
el eje de las X's y de las Y's, lo cual garantiza mayor seguridad en el 
manejo de los mismos. Además, en la sección pública se han definido
métodos para accesar, modificar e imprimir los atributos privados
*/
#include <iostream>
using namespace std;

class Punto
{
private:
	float CoordenadaX, CoordenadaY;
public:
	float ObtenerCoordX();
	float ObtenerCoordY();
	void ModificaX(float NuevaX);
	void ModificaY(float NuevaY);
	void ImprimeCoordenadas();
};

/* Método que permite a los usuarios externos a la clas, conocer el
valor de la coordenada X */
float Punto::ObtenerCoordX()
{
	return CoordenadaX;
}

/* Método que permite actualizar el valor de la coordenada X */
void Punto::ModificaX(float NuevaX)
{
	CoordenadaX = NuevaX;
}

/* Método que permite a los usuarios externos a la clas, conocer el
valor de la coordenada Y */
float Punto::ObtenerCoordY()
{
	return CoordenadaY;
}

/* Método que permite actualizar el valor de la coordenada Y */
void Punto::ModificaY(float NuevaY)
{
	CoordenadaY = NuevaY;
}

/* Método que despliega los valores de las coordernadas X y Y */
void Punto::ImprimeCoordenadas()
{
	cout << "Coordenada X: " << CoordenadaX << endl;
	cout << "Coordenada Y: " << CoordenadaY << endl;
}

/* Función que usa la clase Punto: se declara un objeto tipo Punto y
a través de los métodos se modifican e imprime las coordenadas del punto */
void UsaClasePunto()
{
	/* Declaración de un objeto usando la clase Punto */
	Punto objPunto();
	float auxiliar;

	auxiliar = 2.4;

	/* Modifica el valor de la coordenada X, asignándole el valor
	almacenado en auxiliar */
	objPunto.ModificaX(auxiliar);

	auxiliar = 5.8;

	/* Modifica el valor de la coordenada Y, asignándole el valor
	almacenado en auxiliar */
	objPunto.ModificaY(auxiliar);

	/* Imprime el valor de las coordenadas del punto */
	objPunto.ImprimeCoordenadas();

	/* Obtiene e imprime el valor de las coordenadas X y Y del punto */
	auxiliar = objPunto.ObtenerCoordX();
	cout << "La coordenada X es: " << auxiliar << endl;
	auxiliar = objPunto.ObtenerCoordY();
	cout << "La coordenada Y es: " << auxiliar << endl;
	
}