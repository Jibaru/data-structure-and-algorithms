/*
4.	Retome la clase definida en el ejercicio anterior. Escriba un programa en 
C++ que:
a)	Cree dos objetos tipo Fruta, asignándole valores a sus atributos por medio
 del operador >> sobrecargado.
b)	Compare los objetos e indique si son iguales. Imprima un mensaje adecuado.
*/

#include "3.cpp"

int main() {
	
	Fruta ObjFruta1, ObjFruta2;
	
	cin >> ObjFruta1 >> ObjFruta2;
	
	if(ObjFruta1 == ObjFruta2) {
		cout << "\nFrutas iguales\n" << endl;
	} else {
		cout << "\nFrutas diferentes\n" << endl;
	}
	
	cout << ObjFruta1 << endl << ObjFruta2 << endl;
	
	return 0;
}