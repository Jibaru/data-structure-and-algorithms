/*
6.	Retome la clase definida en el ejercicio anterior. Escriba un programa en 
C++ que:
a)	Cree un objeto de tipo Materia usando el tipo int. Imprima los valores de 
los atributos del
objeto creado.
b)	Cree un objeto de tipo Materia usando el tipo fioat. Imprima los valo¬res 
de los atributos del 
objeto creado.
c)	Cree un objeto de tipo Materia usando el tipo char. Imprima los valo¬res 
de los atributos del
objeto creado.
d)	Incluya un método en la clase que permita modificar la calificación de 
una materia.
*/
#include "5.cpp"

int main() {
	
	Materia<int> ObjMateria1((char*)"Matematica Discreta", 100, 18);
	Materia<float> ObjMateria2((char*)"Calculo", 101, 17.52);
	Materia<char> ObjMateria3((char*)"Ciencias", 102, 'A');
	
	ObjMateria1.imprime();
	ObjMateria2.imprime();
	ObjMateria3.imprime();
	
	ObjMateria1.cambiaCalificacion(20);
	ObjMateria2.cambiaCalificacion(16.5);
	ObjMateria3.cambiaCalificacion('C');
	
	cout << "\n\n";
	ObjMateria1.imprime();
	ObjMateria2.imprime();
	ObjMateria3.imprime();
	
	return 0;
}