/* Se define la clase Fecha con los atributos Día, Mes y Año.
Se incluye un constructor por omisión (sin parámetros) y uno con parámetros.
Este último permite dar un valor inicial a los atributos cuando se crea un objeto. */ 
class Fecha {
private:
	int Dia, Mes, Anio; 
public:
	Fecha ();
	Fecha (int, int, int);
};

/* Declaración del método constructor por omisión. */
Fecha::Fecha (){}

/* Declaración del método constructor con parámetros (tres enteros): inicializa los atributos. */
Fecha::Fecha (int D, int M, int A)
{
	Dia  = D;
	Mes  = M;
	Anio = A;
}

/* Función que utiliza la clase Fecha: se crean objetos usando los dos constructores. */ 
void UsaConstructores ()
{
	/* En este caso se invoca al constructor por omisión. 
	El objeto ObjFecha tendrá sus atributos (Día, Mes y Año) con valores indeterminados. */
	Fecha ObjFecha;
	
	/* En este caso se invoca al constructor con parámetros. Al objeto Cumpleanios se le 
	asignarán los valores 18, 05 y 2006 para sus atributos Día, Mes y Año respectivamente. */
	Fecha Cumpleanios(18, 05, 2006);
	
}

