/* La clase Fecha contiene los atributos privados Día, Mes y Año. Además 
tiene dos constructores y un método para imprimir los valores de los 
atributos. */
#include <iostream>
using namespace std;
class Fecha {
private:
    int Dia, Mes, Anio;
public:
    Fecha(int, int , int );
    Fecha();
    void ImprimeFecha();
};

/* Definición del método constructor con parámetros. */
Fecha::Fecha (int D, int M, int A): Dia(D),Mes(M), Anio(A)
{}

/* Definición del método constructor por omisión. */
Fecha::Fecha ()
{}

/* Método que despliega los valores de los atributos de una fecha. */
void Fecha::ImprimeFecha ()
{
    cout << "\nDia: " << Dia << "\tMes: " << Mes << "\tAnio: " << Anio;
}

/* Función que usa un arreglo de objetos tipo Fecha. */
void UsaArregloObjetos ()
{
    int Indice;
    /* Se declara un arreglo de 3 objetos de tipo Fecha, usando el 
    constructor por omisión. */
    Fecha Cumpleanios[3];

    /* Se declaran 3 objetos de tipo Fecha, usando el constructor con parámetros. */
    Fecha Cumple_Franco(18, 9, 2005);
    Fecha Cumple_Monica(12, 4, 2005);
    Fecha Cumple_Rodrigo(25, 11, 2005);

    /* Se declara e inicializa un arreglo de 2 objetos de tipo Fecha. */
    Fecha DiasFestivos[2]= {Fecha (21, 3, 2005), Fecha (1, 5, 2005)};

    /* Se asignan valores (objetos) a las casillas del arreglo. */
    Cumpleanios[0]= Cumple_Franco;
    Cumpleanios[1]= Cumple_Monica;
    Cumpleanios[2]= Cumple_Rodrigo;

    /* Impresión del contenido de los arreglos. */
    for (Indice= 0; Indice < 3; Indice++)
        Cumpleanios[Indice].ImprimeFecha();

    for (Indice= 0; Indice < 2; Indice++)
        DiasFestivos[Indice].ImprimeFecha();
}

int main() {

    UsaArregloObjetos();

    return 0;
}
