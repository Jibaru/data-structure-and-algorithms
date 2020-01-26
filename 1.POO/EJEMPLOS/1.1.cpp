/* La clase Persona queda definida por los atributos: 
Nombre, Domicilio, y Edad y un método ActualizaDomicilio 
que permite cambiar el domicilio de una persona */

class Persona
{
public:
	char Nombre[64], Domicilio[64];
	int Edad;
	void ActualizaDomicilio (char NuevoDom[]);
};

/* En la función main se declaran dos objetos de la clase Persona. 
Estos objetos son las variables que se usarán en la solución del problema */

int main()
{
	Persona objJefe, objGerente;
	return 0;
}