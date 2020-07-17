/*
5.	Analice cuidadosamente las siguientes declaraciones y diga si los enunciados que aparecen 
después del código son verdaderos o falsos. Las afirmaciones tienen relación con el segmento 
del programa al cual suceden.
a)	En la declaración de la clase no se pudo incluir un método constructor por omisión. Justifique su respuesta.
Si se pudo incluir un método constructor por omisión: Trabajador();
b)	En los parámetros formales del método constructor faltó darle un valor por omisión al parámetro Nom. Justifique su respuesta.
No es conveniente porque sino se podrían crear "trabajadores iguales"
c)	Los valores que aparecen en el encabezado del método siempre se asignan. Justifique su respuesta.
Si no tienen parámetros por omisión, si.
*/
#include <iostream>
#include <string.h>

class Trabajador {
private:
    char Nombre[64]; int ClaveTrab, Sindi; float Sueldo; public:
    Trabajador(char [], int, int, float);
    void Imprime();
    void CambiaEstado();
    void AumentaSueldo(float);
};
Trabajador::Trabajador(char Nom[],int Cla=1000,int Si=1,float Sue=1600) {
    strcpy(Nombre, Nom);
    ClaveTrab= Cla;
    Sindi= Si;
    Sueldo= Sue;
}
