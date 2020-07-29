/*
10.	Retome el problema 8, pero ahora utilice una clase Materia para instanciar
 T. Puede usar la del problema 5 o definir su propia clase. 
¿Debe modificar la plantilla de la clase Profesor?,
No, no es necesario 
¿debe modificar la otra clase? Si usó la plantilla del problema 5, 
Si, es necesario sobrecargar el operador <<
¿cuántos valores para T debe dar al crear un objeto de tipo Profesor?
2 valores, Materia y float
*/

#include "5.cpp"
#include "7.cpp"

int main() {
	
	Materia<float> materia((char*)"Historia", 7, 17.5);
	
	Profesor<Materia<float>> ProfeJuan((char*)"Profesor Juan", (char*)"Lima", 2020, materia);
	
	ProfeJuan.Imprime();
	
	ProfeJuan.CambiaDepto((char*)"La Libertad");
	
	ProfeJuan.Imprime();
	
	Materia<float> nuevaMateria((char*)"Calculo", 9, 19);
	
	ProfeJuan.CambiaMat(nuevaMateria);
	
	ProfeJuan.Imprime();
	
	return 0;
}