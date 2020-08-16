/*
3.	Escriba un programa que invierta el orden de los elementos de un objeto tipo 
arreglo. Tome como ejemplo el siguiente esquema. Para la declaración del objeto 
puede usar alguna de las plantillas presentadas en este capítulo. 
¿Requiere definir nuevos métodos? 
No necesariamente. En este caso se creó un método.
¿Puede solucionar el problema de alguna otra forma?
Mediante una función amiga.
Arreglo: [12, 23, 45, ..., 98, 104]
Luego: [104, 98, 0, ..., 23, 12]
*/
#include <iostream>
#define MAX 30
using namespace std;

class ArregloReales {
private:
	float elementos[MAX];
	int tam;
public:
	ArregloReales();
	void ingreso();
	void imprime();
	int insertar(float);
	void invertir();
};

ArregloReales::ArregloReales()
{
	tam = 0;
}

void ArregloReales::ingreso()
{
	do {
		cout << "Nro de elementos: ";
		cin >> tam;
	} while(tam <= 0 || tam > MAX);
	
	for(int i = 0; i < tam; i++) {
		cout << "Elemento " << i + 1 << ": ";
		cin >> elementos[i];
	}
}

void ArregloReales::imprime()
{
	cout << endl;
	for(int i = 0; i < tam; i++)
		cout << elementos[i] << " ";
	cout << endl;
}

int ArregloReales::insertar(float valor)
{
	int resultado = 1;
	if(tam + 1 > MAX)
		resultado = 0;
	else{ 
		elementos[tam] = valor;
		tam++;
	}

	return resultado;
}

void ArregloReales::invertir()
{
	int indice = 0, indiceCambio, mitad, temp;

	mitad = (int) (tam / 2);

	while(indice < mitad){
		temp = elementos[indice];
		indiceCambio = (tam - 1) - indice;
		elementos[indice] = elementos[indiceCambio];
		elementos[indiceCambio] = temp;
		indice++;
	}
}

void usaInvierte()
{
	ArregloReales arr = ArregloReales();

	arr.ingreso();

	arr.imprime();
	arr.invertir();
	arr.imprime();
}

int main()
{
	usaInvierte();
	return 0;
}
