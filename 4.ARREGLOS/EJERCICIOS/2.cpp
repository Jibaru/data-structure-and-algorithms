/*
2.	Utilice la clase definida en el ejercicio 1 para almacenar la edad de un grupo 
de N (1< N<30) alumnos. Una vez almacenados los datos, calcule e imprima el promedio 
de edad del grupo, así como el total de alumnos con una edad mayor al promedio.
a)	El cálculo del promedio y el cálculo del total de alumnos con edad mayor al 
promedio debe hacerse con métodos de la clase.
b)	El cálculo del promedio y el cálculo del total de alumnos con edad mayor al 
promedio NO puede hacerse con métodos de la clase. Utilice alguno(s) de los conceptos 
vistos en los capítulos anteriores.
*/

#include "1.cpp"

void usaPromedioYTotal()
{
	ArregloEnteros arr = ArregloEnteros();
	int n, edadTemp;

	do {
		cout << "Ingrese total de alumnos: ";
		cin >> n;
	} while (n <= 1 || n >= 30);

	for(int i = 0; i < n; i++) {
		cout << "Edad alumno " << i + 1 << ": ";
		cin >> edadTemp;
		arr.insertar(edadTemp);
	}

	arr.imprime();
	cout << "Promedio: " << calculoPromedio(arr) << endl;
	cout << "Total mayores a promedio: " << totalMayoresAPromedio(arr) << endl;

}

int main()
{
	usaPromedioYTotal();
	return 0;
}


