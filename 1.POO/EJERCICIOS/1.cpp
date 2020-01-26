/* 1.Analice cuidadosamente las siguientes declaraciones y diga
si los enunciados que aparecen después del código son verdaderos o falsos.

a) La definición de la clase es correcta.
Rpta. No es del todo correcta, existe un error en el constructor por omisión.

b) En el prototipo del método constructor por omisión hay un error. Justifique su respuesta.
Rpta. El error está en no inicializar los atributos Nombre y Epoca. 
Esto puede considerarse un error, porque no hay ninguna restricción en la llamada al método
Imprime (podría ser llamado sin haberse asignado valores a los atributos).
Lo correcto sería:
Flor::Flor(){
	Nombre = "";
	Epoca = "";
}

c) Al prototipo del método imprime le faltan parámetros. Justifique su respuesta. 
Rpta. No le faltan parámetros. Utiliza los atributos propios del objeto. */

#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;

class Flor
{
private:
	char Nombre[64], Epoca[64]; 
public:
	void Flor();
	Flor(char [], char []); 
	void Imprime();
};

Flor::Flor(){}

Flor::Flor(char Nom[], char Epo[])
{
	strcpy(Nombre, Nom); strcpy(Epoca, Epo);
}

void Flor::Imprime()
{
	cout << "\n\nNombre de la flor: " << Nombre; 
	cout << "\nEpoca en la que se cosecha: " << Epoca << "\n\n";
}

int main()
{
	Flor Rosa("Rosa aterciopelada", "verano"), Jazmin; 
	cout << "\nIngrese época en la que se cosecha el jazmín"; 
	cin  >> Jazmin.Epoca;
	Rosa.Imprime();

	getch();
	return 0;
}

