/* 3.Analice cuidadosamente las siguientes declaraciones y diga si 
los enunciados que aparecen después del código son verdaderos o falsos.

a)	El atributo MarcaAlimento no se puede declarar en la sección pública. Justifique su respuesta.
Rpta. No es recomendable declarar atributos de manera pública. Lo recomendado es
declararlos privados y crear métodos setter y getter si es necesario modificar/acceder 
al contenido de estos.

b)	La clase Gato necesita un método constructor por omisión. Justifique su respuesta.
Rpta. Si es necesario crear el método constructor por omisión para darle un valor
inicial a las propiedades y que no lance una error al llamar a los métodos que los invocan.

c)	La clase Gato está correctamente definida. 
Rpta. La declaración está hecha, pero haría falta la definición de los métodos.
*/
class Gato
{
private:
	char Nombre[64]; int Edad; 
public:
	char MarcaAlimento[64]; 
	Gato(char [], int, char[]); 
	void Imprime(); 
	char* RegresaNombre(); 
	void CambiaEdad(int);
};