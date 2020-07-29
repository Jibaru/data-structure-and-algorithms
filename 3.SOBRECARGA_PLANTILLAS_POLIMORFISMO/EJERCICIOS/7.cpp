/*
7.	Defina la plantilla de la clase Profesor según las especificaciones que se
dan más adelante. 
El atributo MateriaACargo es del tipo T, en este caso podría ser un entero 
(si la materia se representa por medio de una clave), una cadena de caracteres
(si la materia se representa por su nombre) u otro objeto (si la materia se 
representa usando una clase previamente definida).
Profesor
NombreProfesor: char[]
Departamento: char[]
AñoIngreso: int
MateriaACargo: T
Constructor(es)
void CambiaDepto(char[])
void CambiaMat(T)
void Imprime()
*/
#include <iostream>
#include <string.h>
using namespace std;

template <class T>
class Profesor {
private:
	char NombreProfesor[64];
	char Departamento[64];
	int AnioIngreso;
	T MateriaACargo;
public:
	Profesor();
	Profesor(char*, char*, int, T);
	void CambiaDepto(char*);
	void CambiaMat(T);
	void Imprime();
};

template <class T>
Profesor<T>::Profesor() {}

template <class T>
Profesor<T>::Profesor(char* nombre, char* depto, int anio, T mat)
{
	strcpy(NombreProfesor, nombre);
	strcpy(Departamento, depto);
	AnioIngreso = anio;
	MateriaACargo = mat;
}

template <class T>
void Profesor<T>::CambiaDepto(char* dpto)
{
	strcpy(Departamento, dpto);
}

template <class T>
void Profesor<T>::CambiaMat(T mat)
{
	MateriaACargo = mat;
}

template <class T>
void Profesor<T>::Imprime()
{
	cout << "\nNombre: " << NombreProfesor << endl;
	cout << "Anio ingreso: " << AnioIngreso << endl;
	cout << "Departamento: " << Departamento << endl;
	cout << "Materia a cargo: " << MateriaACargo << endl << endl;
}
