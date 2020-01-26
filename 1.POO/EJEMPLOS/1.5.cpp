/* Se define la clase Persona en la cual, además de los atributos, 
se incluyen tres métodos en la sección pública: un constructor, 
un destructor y uno para imprimir los datos. */ 

#include <string.h>

class Persona {
private:
	char Nombre[64]; 
	int Edad; 
public:
	/* Método constructor: se llama igual que la clase, no da ningún tipo de resultado. */
	Persona(char *, int);
	
	/* Método destructor: se llama igual que la clase, va precedido por ~ y no tiene argumentos. */
	~Persona();
	void ImprimeDatos();
};

/* Declaración del método constructor: tiene 2 parámetros (Nom y Ed) que se usarán 
para dar un valor inicial a los atributos (Nombre y Edad respectivamente), al momento de crearse un objeto. */
Persona::Persona(char *Nom, int Ed)
{
	strcpy (Nombre, Nom);
	Edad = Ed;
}
