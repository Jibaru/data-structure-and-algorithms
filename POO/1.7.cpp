/* Se define la clase Fecha con los atributos Día, Mes y Año.
Se incluye un constructor por omisión (sin parámetros) y uno con parámetros.
Este último permite dar un valor inicial a los atributos cuando se crea un objeto. */ 
class Fecha {
private:
	int Dia, Mes, Anio; 
public:
	Fecha ();
	/* Una manera equivalente de escribir las asignaciones que aparecen en el constructor es: */
	Fecha (int D, int M, int A): Dia(D), Mes(M), Anio(A) {};
};

/* Declaración del método constructor por omisión. */
Fecha::Fecha (){}
