/*
6.	Retome la gráfica del problema anterior. Aplique el método que crea 
conveniente para encontrar e imprimir el árbol abarcador de costo mínimo 
correspondiente a dicha gráfica.
*/

#include <iostream>
#include "../../lib/graficas/Grafica.h"

int main() 
{

    Grafica<int> grafica;

    grafica.Lee();
    
    // Método para encontrar e imprimir el árbol 
    //abarcador de costo mínimo
    grafica.Kruskal();

    return 0;
}