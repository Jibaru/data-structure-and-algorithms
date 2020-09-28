#ifndef _GRAFICA_H_
#define _GRAFICA_H_

#include <iostream>

/* Máximo número de vértices que maneja la clase Grafica */
#define MAX 20

/* Fúnción auxiliar que obtiene el valor más pequeño de dos dados como
parámetros. La utiliza el método Kruskal */
int Minimo(int Val1, int Val2)
{
    int Min = Val1;
    if(Val2 < Min)
        Min = Val2;
    return Min;
}

/* Fúnción auxiliar que obtiene el valor más grande de dos dados como
parámetros. La utiliza el método de kruskal */
int Maximo(int Val1, int Val2)
{
    int Max = Val1;
    if(Val2 > Max)
        Max = Val2;
    return Max;
}

/* Definición de la plantilla de la clase Gráfica. Se incluyen como 
atributos el total de vértices (NumVer), los costos/distancias entre 
los vértices (MatAdy) y sus nombres (Vértices). */
template <class T>
class Grafica {
private:
    T MatAdy[MAX][MAX];
    int NumVer, Vertices[MAX];
public:
    /* Método constructor y métodos auxiliares para leer la información 
    relacionada a la gráfica e imprimir los resultados obtenidos al 
    aplicar los demás métodos. */
    Grafica();
    void Lee();
    void Imprime();
    /* Métodos que permiten el cálculo del árbol abarcador de costo *minimo. */
    void Prim();
    void Kruskal();
};

/* Declaración del método constructor. Inicializa el número de vértices 
en cero y la matriz de distancias con un valor arbitrario muy grande 
(999), excepto en la diagonal principal, donde el costo es cero. */
template <class T>
Grafica<T>::Grafica()
{
    int Ind1, Ind2;
    for (Ind1= 0; Ind1 <MAX; Ind1++)
        for (Ind2= 0; Ind2<MAX; Ind2++)
            if (Ind1 != Ind2)
                MatAdy[Ind1][Ind2]= 999;
            else
                MatAdy[Ind1][Ind2]= 0;
    NumVer= 0;
}

/* Método que lee del teclado la información de la gráfica. En esta 
solución el nombre de los vértices sólo pueden ser valores enteros. */
template <class T>
void Grafica<T>::Lee()
{
    int Aristas, Costo, Ind1, Origen, Destino;
    std::cout << "\n\nIngrese total de vertices de la grafica: ";
    std::cin >> NumVer;
    for (Ind1= 0; Ind1 < NumVer; Ind1++)
    {
        std::cout << "\nIngrese el nombre del vertice: ";
        std::cin >> Vertices[Ind1];
    }
    std::cout << "\n\nIngrese total de aristas de la grafica: ";
    std::cin >> Aristas;
    Ind1= 0;
    while (Ind1 < Aristas)
    {
        std::cout << "\nVertice origen: ";
        std::cin >> Origen;
        std::cout << "\nVertice destino: ";
        std::cin >> Destino;
        std::cout << "\nCosto de ir de "<< Origen << " a " << Destino << ": ";
        std::cin >> Costo;
        MatAdy[Origen - 1][Destino - 1]= Costo;
        MatAdy[Destino - 1][Origen - 1]= Costo;
        Ind1++;
    }
}

/* Método que imprime información relacionada a una gráfica. 
En este caso solo se imprime la matriz de adyacencia*/
template <class T>
void Grafica<T>::Imprime()
{
    int Ind1, Ind2;
    std::cout << "\n\n Matriz de Adyacencia o de Costos: \n\n";
    for (Ind1= 0; Ind1 < NumVer; Ind1++)
    {
        std::cout << Vertices[Ind1]<< ": ";
        for (Ind2= 0; Ind2 < NumVer; Ind2++)
            std::cout << MatAdy[Ind1][Ind2] << "\t";
            
        std::cout << std::endl;
    }
}

/* Este método encuentra el árbol abarcador de costo minimo de una 
gráfica. En el arreglo VerAux se almacenan los vértices con menor costo 
que van formando el árbol abarcador. */
template <class T>
void Grafica<T>::Prim()
{
    int MCosto[MAX], VerAux[MAX], Ind1, Ind2, VerMen, MenCos;
    /* Inicializa el subconjunto de vértices VerAux con el valor del
    primer vértice. */
    for (Ind1= 0; Ind1<NumVer; Ind1++)
    {
        MCosto[Ind1]= MatAdy[0][Ind1];
        VerAux[Ind1]= 0;
    }

    std::cout << "\n\n\nArcos y costos del arbol abarcador de costo minimo\n\n";
    std::cout << "\nVertice Vertice Costo \n";
    /* Encuentra el vertice VerMen en (Vertices - VerAux) tal que el 
    costo de ir de dicho vértice a uno de VerAux sea mínimo. */
    for (Ind1= 0; Ind1 < NumVer - 1; Ind1++)
    {
        MenCos= MCosto[1];
        VerMen= 1;
        for (Ind2= 2; Ind2 < NumVer; Ind2++)
            if (MCosto[Ind2] < MenCos)
            {
                MenCos= MCosto[Ind2];
                VerMen= Ind2;
            }

        std::cout << "\n" << Vertices[VerMen] << " - "
                  << Vertices[VerAux[VerMen]]
                  << " " << MatAdy[VerMen][VerAux[VerMen]];
        /* Se agrega el vértice VerMen a VerAux y se redefinen los 
        costos asociados. */
        MCosto[VerMen]= 1000;
        for (Ind2= 1; Ind2 < NumVer; Ind2++)
            if ((MatAdy[VerMen][Ind2] < MCosto[Ind2]) && MCosto[Ind2] < 1000)
        {
            MCosto[Ind2]= MatAdy[VerMen][Ind2];
            VerAux[Ind2]= VerMen;
        }
    }
    std::cout << "\n\n";
}

/* Este métdo encuentra el árbol abarcador de costo mínimo de una
gráfica */
template <class T>
void Grafica<T>::Kruskal()
{
    /* El arreglo auxiliar ArisCosto[][] almacena en cada renglón los
    datos de una arista: vértices adyacentes y costo. El arreglo
    Partic[] alamcena particiones de Vertices. Inicialmente
    Partic = {{1}, {2}, ..., {NumVer}}. */
    int ArisCosto[2*MAX][3], Partic[MAX], Ind1, Ind2, Ver1, Ver2,
    TotAris, Menor, Mayor, Band;

    /* Inicializa Partic[] */
    for(Ind1=0; Ind1 < NumVer; Ind1++)
        Partic[Ind1] = Ind1;

    /* Inicializa ArisCosto[][] */
    Ver1 = 0;
    Ver2 = 0;
    TotAris = 0;

    for (Ind1= 0; Ind1 < NumVer; Ind1++)
        for (Ind2= Ind1; Ind2 < NumVer; Ind2++)
            if (MatAdy[Ind1][Ind2] != 0 && MatAdy[Ind1][Ind2] != 999)
            {
                ArisCosto[Ver1][Ver2++]= Ind1;
                ArisCosto[Ver1][Ver2++]= Ind2;
                ArisCosto[Ver1++][Ver2]= MatAdy[Ind1][Ind2];
                Ver2= 0;
                TotAris++;
            }
    /* Ciclo en el cual se seleccionan aristas y se agregan los vértices 
    mientras existan vértices en Partic que se encuentren en distintas 
    particiones. */
    Band= 0;
    while (Band != 1)
    {
        /* Se selecciona la arista de menor costo. */
        Menor= 999;
        for (Ind1= 0; Ind1 < TotAris; Ind1++)
            if (ArisCosto[Ind1][2] < Menor)
            {
                Ver1= ArisCosto[Ind1][0];
                Ver2= ArisCosto[Ind1][1];
                Menor= ArisCosto[Ind1][2];
                Ind2= Ind1;
            }

        /* Se elimina la arista de menor costo de la matriz ArisCosto. */
        ArisCosto[Ind2][2]= 999;

        /* Se verifica que la arista (Veri, Ver2) una dos vértices que 
        pertenecen a particiones diferentes. */
        if (Partic[Ver1] != Partic[Ver2])
        {
            std::cout << "\nVertice: "<< Vertices[Ver1] << " Vertice: "
                      << Vertices[Ver2] << " Costo: " << MatAdy[Ver1][Ver2] << "\n\n";
            Mayor= Maximo(Partic[Ver1], Partic[Ver2]);
            
            for (Ind1= 0; Ind1 < NumVer; Ind1++)
                if (Ind1 == Ver1 || Ind1 == Ver2 || Partic[Ind1] == Mayor)
                    Partic[Ind1]= Minimo(Partic[Ver1], Partic[Ver2]);
        }
        /* Ciclo para determinar si quedan vértices en particiones 
        diferentes. */
        Ind1= 0;
        while (Ind1 < NumVer && !Band)
        {
            if (Partic[Ind1] != 0)
                Band= 1;
            Ind1++;
        }

        /* Si existen particiones en Partic se debe seguir con el 
        proceso. */
        Band= !Band;
    }

}

#endif /* _GRAFICA_H_ */