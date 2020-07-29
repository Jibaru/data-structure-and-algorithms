/*
8.	Retome la clase definida en el ejercicio anterior. Escriba un programa en 
C++ que:
a)	Cree el objeto ProfeJuan de tipo Profesor, usando int para instanciar T.
b)	Imprima todos los datos del ProfeJuan.
c)	Cambie el nombre del departamento al cual está adscrito el ProfeJuan.
d)	Cambie la materia que tiene a cargo el ProfeJuan.
*/

#include "7.cpp"

int main() {
	
	Profesor<int> ProfeJuan((char*)"Profesor Juan", (char*)"Lima", 2020, 7);
	
	ProfeJuan.Imprime();
	
	ProfeJuan.CambiaDepto((char*)"La Libertad");
	
	ProfeJuan.Imprime();
	
	ProfeJuan.CambiaMat(8);
	
	ProfeJuan.Imprime();
	
	return 0;
}