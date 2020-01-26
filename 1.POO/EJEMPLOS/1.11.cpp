/* Se define la clase Texto por medio de los atributos privados que 
representan la longitud del texto y la estructura requerida para 
almacenar los caracteres. Asimismo, se incluyen algunos métodos. */ 
#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

class Texto {
private:
	char *CadenaTexto; int Longitud; public:
	Texto(char *);
	~Texto();
	void ImprimeTexto();
};

/* Declaración del método constructor con parámetros. */
Texto::Texto(char *Cad)
{
	/* Genera dinámicamente el espacio de memoria necesario para almacenar 
	la cadena Cad más un carácter adicional (carácter nulo). */ 
	CadenaTexto = new char[strlen(Cad)+1];

	/* Se verifica si se pudo generar el espacio requerido. */ 
	if (CadenaTexto){
		strcpy(CadenaTexto, Cad);
		Longitud= strlen(CadenaTexto);
	} else {
		Longitud= 0;
	}
}
/* Declaración del método destructor. Verifica que la longitud de la 
cadena sea distinta de cero. Libera el espacio de memoria empleado 
por CadenaTexto. */
Texto::~Texto()
{
	if (Longitud)
		delete[] CadenaTexto;
}

/* Método para imprimir el texto. */ 
void Texto::ImprimeTexto ()
{
	cout << "La cadena es: " << CadenaTexto << endl; 
	cout << "Su longitud es: " << Longitud << endl;
}

/* Función que utiliza la clase Texto: se crea un objeto usando el 
constructor con parámetros e imprime su valor. Al terminar la función 
el objeto se destruye liberando espacio de memoria. */ 
void UsaTexto ()
{
	Texto ObjTexto((char*)"Cadena de longitud 41, incluyendo blancos");
	ObjTexto.ImprimeTexto();
}

int main(){
	UsaTexto();
	getch();
	return 0;
}