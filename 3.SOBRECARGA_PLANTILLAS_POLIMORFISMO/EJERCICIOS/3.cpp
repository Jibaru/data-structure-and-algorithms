/*
3.	Defina la clase Fruta según las especificaciones que se muestran más adelante. Incluya la sobrecarga 
del operador == para determinar si dos objetos de tipo Fruta son iguales. Dos frutas se considerarán 
iguales si los valores de todos sus atributos son iguales. Además, sobrecargue los operadores de entrada 
(>>) y de salida (<<) para poder leer y escribir objetos de tipo Fruta con las instrucciones cin y cout
respectivamente.
Fruta
NombreFruta: char[] 
Color: char [] 
EstaciónCosecha: char[]
Constructor(es) 
int operator==(Fruta) 
void Imprime() 
friend istream... 
friend ostream...
*/
#include <iostream>
#include <string.h>
using namespace std;

class Fruta {
private:
	char NombreFruta[64];
	char EstacionCosecha[64];
public:
	Fruta();
	Fruta(char*, char*);
	int operator==(Fruta&);
	void Imprime();
	friend istream& operator>>(istream&, Fruta&);
	friend ostream& operator<<(ostream&, Fruta&);
};

Fruta::Fruta() {}

Fruta::Fruta(char* nombre, char* estacion)
{	
	strcpy(NombreFruta, nombre);
	strcpy(EstacionCosecha, estacion);
}

int Fruta::operator==(Fruta& otro)
{
	if(strcmp(NombreFruta, otro.NombreFruta) == 0 && 
	   strcmp(EstacionCosecha, otro.EstacionCosecha) == 0){
		return 1;   
	}
	return 0;
}

void Fruta::Imprime() {
	cout << "Datos de la fruta" << endl;
	cout << "Nombre: " << NombreFruta << endl;
	cout << "Estacion de cosecha: " << EstacionCosecha << endl;
}

istream& operator>>(istream& lee, Fruta& obj)
{
	cout << "\nIngrese nombre fruta: ";
	lee.getline(obj.NombreFruta, 64);
	cout << "\nEstacion de cosecha: ";
	lee.getline(obj.EstacionCosecha, 64);
	return lee;
}

ostream& operator<<(ostream& escribe, Fruta& obj)
{
	escribe << "Datos de la Fruta: " << endl;
	escribe << "Nombre: " << obj.NombreFruta << endl;
	escribe << "Estacion de cosecha: " << obj.EstacionCosecha << endl;
	return escribe;
}
