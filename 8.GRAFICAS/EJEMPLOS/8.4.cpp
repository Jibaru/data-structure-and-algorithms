/* Aplicación del concepto de gráficas para encontrar el conjunto mínimo de 
carreteras, con el menor costo asociado, que una un grupo de ciudades. */
#include <iostream>
#include "../../lib/graficas/Grafica.h"

using namespace std;

int main()
{
    Grafica<int> Caminos;
    cout << "\n\nIngrese datos de las ciudades (vertices) y de las carreteras (aristas)\n\n";
    Caminos.Lee();
    Caminos.Imprime();
    cout << "\n\nLa red minima de carreteras requerida para unir todas las ciudades es:\n";
    Caminos.Kruskal();
    Caminos.Prim();

    return 0;
}
