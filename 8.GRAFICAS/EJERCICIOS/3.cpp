/*
3.	Retome el problema anterior. Aplique el método que crea adecuado para 
obtener e imprimir los caminos de mínimos costos entre el vértice 3 y los 
demás vértices de la digráfica.
*/
#include <iostream>
#include "../../lib/graficas/Digrafica.h"

int main() 
{

    DiGrafica<int> digrafica;

    digrafica.Lee();
    
    // Método que imprime los caminos de costos mínimos entre
    // el vértice 3 y los demás vértices (Dijsktra)
    digrafica.Dijkstra();
    digrafica.Imprime(4);

    return 0;
}