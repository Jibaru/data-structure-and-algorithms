/*1. Defina la clase CadenaCar según las especificaciones que se muestran a 
continuación. Incluya la sobrecarga de los siguientes operadores: ==, !=, +, < y >, 
de tal manera que dos objetos tipo CadenaCar se puedan comparar (=, !=, <, >) o 
unir (+) usando los operadores indicados.
CadenaCar
Tam: int
Cadena: char[]
Constructor(es) 
int operator==(CadenaCar) 
int operator!=(CadenaCar) 
int operator<(CadenaCar) 
int operator>(CadenaCar) 
CadenaCar operator+(CadenaCar) 
void Imprime()*/
#include <iostream>
#include <string.h>
using namespace std;

class CadenaCar {
private:
	int Tam;
	char* Cadena;
public:
	CadenaCar();
	CadenaCar(char*);
	int operator==(CadenaCar&);
	int operator!=(CadenaCar&);
	int operator<(CadenaCar&);
	int operator>(CadenaCar&);
	CadenaCar operator+(CadenaCar&);
	void Imprime();
};

CadenaCar::CadenaCar(){}

CadenaCar::CadenaCar(char* cadena)
{
	Tam = strlen(cadena);
	Cadena = new char[Tam + 1];
	strcpy(Cadena, cadena);
}

int CadenaCar::operator==(CadenaCar& otro)
{
	return strcmp(Cadena, otro.Cadena);
}

int CadenaCar::operator!=(CadenaCar& otro)
{
	return strcmp(Cadena, otro.Cadena);
}

int CadenaCar::operator<(CadenaCar& otro)
{
	return strcmp(Cadena, otro.Cadena);
}

int CadenaCar::operator>(CadenaCar& otro)
{
	return strcmp(Cadena, otro.Cadena);
}

CadenaCar CadenaCar::operator+(CadenaCar& otro)
{
	char* cad = new char[strlen(Cadena) + strlen(otro.Cadena) + 1];
	strcpy(cad, Cadena);
	strcat(cad, otro.Cadena);
	return CadenaCar(cad);
}

void CadenaCar::Imprime()
{
	cout << "Cadena: " << Cadena << endl;
	cout << "Tamanio: " << Tam << endl;
}
