/*
4.	Aplique el método que crea conveniente a la gráfica del problema 2, para generar 
una matriz que indique si existe o no un camino entre cada uno de los vértices de la 
gráfica dirigida.
*/
#include <iostream>
#include "../../lib/graficas/Digrafica.h"

int main() 
{

    DiGrafica<int> digrafica;

    digrafica.Lee();
    
    // Método que generar una matriz que indica si existe o no 
    // un camino entre cada uno de los vértices de la gráfica dirigida
    digrafica.Warshall();
    digrafica.Imprime(1);

    return 0;
}