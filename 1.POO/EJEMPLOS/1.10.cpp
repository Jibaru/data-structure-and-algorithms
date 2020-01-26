/* Se define la clase Fecha en la cual se incluyó un método constructor uno destructor. */ 
class Fecha{
private:
	int Dia, Mes, Anio; 
public:
	Fecha (int, int, int); 
	~Fecha();
};
 
/* Declaración del método constructor con parámetros. */
Fecha::Fecha(int D, int M, int A)
{
	Dia  = D;
	Mes  = M;
	Anio = A;
}

/* Declaración del método destructor. El cuerpo del método está vacio. */
Fecha::~Fecha()
{ }
