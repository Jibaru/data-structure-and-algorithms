/*
2. Retome la clase definida en el ejercicio anterior. Escriba un programa en C++ 
que:
a)	Declare dos objetos tipo CadenaCar.
b)	Le asigne una cadena de caracteres a cada uno de los objetos. La asignación puede 
ser a través de una lectura o por medio del método constructor.
c)	Compare los objetos e imprima un mensaje adecuado si los mismos son iguales. Si 
no lo fueran, el mensaje, además de indicar este caso, debe decir cuál de las cadenas
 es menor.
d)	Enlace dos objetos tipo CadenaCar formando un tercer objeto del mismo tipo. 
Imprima el objeto resultante.
*/

#include "1.cpp"

int main() {
	
	CadenaCar ObjCadena1((char*)"Cadena1"), ObjCadena2((char*)"Cadena2");
	
	if(ObjCadena1 == ObjCadena2) {
		cout << "Las cadenas son iguales" << endl;
	} else if(ObjCadena1 < ObjCadena2) {
		cout << "La cadena 1 es menor a la cadena 2" << endl;
	} else if(ObjCadena1 > ObjCadena2) {
		cout << "La cadena 1 es mayor a la cadena 2" << endl;
	}
	
	CadenaCar ObjCadena3 = ObjCadena1 + ObjCadena2;
	
	ObjCadena3.Imprime();
	
	return 0;
}