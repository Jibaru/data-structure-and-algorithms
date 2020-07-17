/* 4.Retome el problema anterior. Se definen los métodos de la clase Gato 
y la función main. Analice cuidadosamente las siguientes declaraciones y 
diga si los enunciados que aparecen después del código son verdaderos o falsos.

a) La declaración del objeto MiGato es correcta. Justifique su respuesta.
Si porque llama al constructor Gato con los argumentos correctos
b) La declaración del objeto TuGato es incorrecta. Justifique su respuesta.
Si, porque no existe un constructor vacío para Gato
c) La impresión del valor del atributo Nombre del objeto MiGato es correcta. Justifique su respuesta.
Si, el método RegresaNombre() devuelve el atributo nombre del objeto
d) La impresión del valor del atributo MarcaAümento del objeto MiGato es correcta. Justifique su respuesta.
Si, porque esta llamando directamente al atributo
e) La impresión del valor del atributo Edad del objeto MiGato es correcta. Justifique su respuesta.
No, porque el atributo edad es privado
j) El método cambiaEdad está incorrectamente asociado al objeto MiGato.
Si, el método cambiaEdad no está correctamente asociado al objeto MiGato puesto que es 
un método de clase y no de instancia.
*/
#include <iostream>
using namespace std;

Gato::Gato(char Nom[], int Ed, char MAlim[])
{
	strcpy(Nombre, Nom);
	Edad= Ed;
	strcpy(MarcaAlimento, MAlim);
}

void Gato::Imprime()
{
	cout << "\n\nNombre del gato: " << Nombre; 
	cout << "\nEdad: " << Edad;
	cout << "\nMarca del alimento que come: "<< MarcaAlimento << "\n\n";
}

char* Gato::RegresaNombre()
{
	return Nombre;
}

void Gato::CambiaEdad(int NuevaE) 
{
	Edad = NuevaE;
}
int main()
{
	Gato MiGato("Michifus", 3, "SaborYNutricion"), TuGato(); 
	MiGato::CambiaEdad(4);
	cout << "\n\nNombre del gato: " << MiGato.RegresaNombre() << "\n\n"; 
	cout << "\nAlimento que come: " << MiGato.MarcaAlimento << "\n\n"; 
	cout << "\nEdad: " << MiGato.Edad;

	return 0;
}
