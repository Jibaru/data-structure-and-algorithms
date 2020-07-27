/*
Defina una plantilla para la clase Materia, de tal manera que el tipo de dato del atributo Calificación 
sea del tipo T. Esto permitirá crear objetos de tipo Materia que tengan calificaciones que sean: 
(a) Números enteros, por ejem¬plo, 8 o 9, 
(b) Números con decimales, por ejemplo 8.5 o 
(c) Letras, por ejemplo A.
Materia(T)
NombreMateria: char[] 
Clave: int 
Calificación: T
Constructor(es) 
void Imprime()
*/
#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class Materia {
private:
	char NombreMateria[64];
	int Clave;
	T Calificacion;
public:
	Materia();
	Materia(char*, int, T);
	void cambiaCalificacion(T);
	void imprime();
};

template <class T>
Materia<T>::Materia() {}

template <class T>
Materia<T>::Materia(char* nombre, int clave, T calif)
{
	strcpy(NombreMateria, nombre);
	Clave = clave;
	Calificacion = calif;
}

template <class T>
void Materia<T>::imprime()
{
	cout << "\nMateria:\n";
	cout << "Nombre: " << NombreMateria << endl;
	cout << "Clave: " << Clave << endl;
	cout << "Calificacion: " << Calificacion << endl;
}

template <class T>
void Materia<T>::cambiaCalificacion(T calif)
{
	Calificacion = calif;
}