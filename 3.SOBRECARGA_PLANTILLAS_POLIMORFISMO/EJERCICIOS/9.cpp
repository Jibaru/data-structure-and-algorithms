/*
9.	Retome el problema 8, pero ahora utilice una cadena de caracteres para 
instanciar T. 
¿Debe modificar la plantilla de la clase Profesor?, o ¿debe definir alguna 
otra clase?
Rpta: No es necesario
*/

#include "7.cpp"

int main() {
	
	Profesor<char*> ProfeJuan((char*)"Profesor Juan", (char*)"Lima", 2020, (char*)"Historia");
	
	ProfeJuan.Imprime();
	
	ProfeJuan.CambiaDepto((char*)"La Libertad");
	
	ProfeJuan.Imprime();
	
	ProfeJuan.CambiaMat((char*)"Calculo");
	
	ProfeJuan.Imprime();
	
	return 0;
}