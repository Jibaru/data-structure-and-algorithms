#ifndef _DIGRAFICA_H_
#define _DIGRAFICA_H_

#include <iostream>
#include "../listas/ListasSimLig.h"

/* Constante usada para establecer el número máximo de vórtices de la 
digráfica. */
#define MAX 20

/* Función auxiliar que obtiene el valor más pequeño de dos dados como 
parámetros. La utiliza el método de Dijkstra. */
int Minimo(int Val1, int Val2)
{
    int Min= Val1;
    
    if (Val2 < Min)
        Min= Val2;
    
    return Min;
}

/* Definición de la plantilla de la clase DiGrafica. Se incluyen como 
atributos: la matriz de costos/distancias (MatAdy), el número de vértices 
(NumVer), el nombre de cada uno de los vértices (Vértices), un arreglo 
para las distancias mínimas entre los vórtices (DistMin), un arreglo para 
la cerradura transitiva de la matriz de adyacencia (CerTran), y un 
arreglo para vértices intermedios (VerInt). Los tres últimos se usan 
como auxiliares en métodos que se estudian más adelante. */
template <class T>
class DiGrafica {
private:
/* Declaración del arreglo donde se almacenan las distancias entre los vértices. */
    T MatAdy[MAX][MAX];
    int NumVer, Vertices[MAX], DistMin[MAX], CerTran[MAX][MAX],
    VerInt[MAX][MAX];
public:
    /* Método constructor y métodos auxiliares para leer la información 
    relacionada a la gráfica e imprimir los resultados obtenidos al 
    aplicar los demás métodos. */
    DiGrafica();
    void Lee();
    void Imprime(int);
    /* Métodos que recorren una gráfica dirigida, determinando caminos de 
    distancias minimas. */
    void Warshall();
    void Floyd();
    void FloydVerInt();
    void Dijkstra();

    int BuscaVertice(T VertiDato);
    Lista<T> VerticesAdyacentes(int VertiDato);
    int DepthFirst(int NivelProf);

};

/* Declaración del método constructor. Inicializa la matriz de adyacencias 
MatAdy con un valor arbitrario muy grande (999), indicando que no existe 
camino entre los nodos correspondientes. Además, asigna ceros a los arreglos 
que se usarán en otros métodos. */
template <class T>
DiGrafica<T>::DiGrafica()
{
    int Ind1, Ind2;
    for (Ind1= 0; Ind1 < MAX; Ind1++)
    {
        DistMin[Ind1]= 0;
        for (Ind2= 0; Ind2 < MAX; Ind2++)
        {
            if (Ind1 != Ind2)
                MatAdy[Ind1][Ind2]= 999;
            else
                MatAdy[Ind1][Ind2]= 0;
            
            CerTran[Ind1][Ind2]= 0;
            VerInt[Ind1][Ind2]= 0;
        }
    }
    NumVer= 0;
}

/* Método que lee los datos de la gráfica dirigida directamente del 
teclado. */
template <class T>
void DiGrafica<T>::Lee()
{
    int NumArcos, Indice, Origen, Destino;
    std::cout << "\n\n Ingrese numero de vertices de la grafica dirigida: ";
    std::cin >> NumVer;
    std::cout << "\n\n Ingrese los nombres de los vertices de la grafica dirigida: ";
    for (Indice= 0; Indice < NumVer; Indice++)
        std::cin >> Vertices[Indice];
    
    std::cout << "\n\n Total de aristas de la grafica dirigida: ";
    std::cin >> NumArcos;
    Indice= 0;

    while (Indice < NumArcos)
    {
        std::cout <<"\n\n Ingrese vertice origen: ";
        std::cin >> Origen;
        std::cout << "\n\n Ingrese vertice destino: ";
        std::cin >> Destino;
        std::cout << "\n\n Distancia de origen a destino: ";
        std::cin >> MatAdy[Origen - 1][Destino - 1];
        Indice++;
    }
}

/* Método que imprime información relacionada a una gráfica dirigida. 
Por medio de un número entero se selecciona lo que se va a imprimir, lo 
cual depende del método aplicado para recorrer la digráfica. */
template <class T>
void DiGrafica<T>::Imprime(int Opc)
{
    int Ind1, Ind2;
    switch(Opc)
    {
        /* Impresión de la matriz de adyacencia o de costos. */
        case 0: 
            std::cout << "\n\n Matriz de Adyacencia o de Costos: \n\n";
            for (Ind1= 0; Ind1 < NumVer; Ind1++)
            {
                std::cout << Vertices[Ind1]<< ": ";
                for (Ind2= 0; Ind2 < NumVer; Ind2++)
                    std::cout << MatAdy[Ind1][Ind2] << "\t";
                    
                std::cout << std::endl;
            }
            break;

        /* Impresión de la cerradura transitiva correspondiente a la 
        matriz de adyacencia. Se obtiene cuando se aplica el método de 
        Warshall. */
        case 1: 
            std::cout << "\n\n Cerradura Transitiva de la Matriz de Adyacencia: " << std::endl;
            for (Ind1= 0; Ind1 < NumVer; Ind1++)
            {
                std::cout << Vertices[Ind1] << ": ";
                for (Ind2= 0; Ind2 < NumVer; Ind2++)
                    std::cout << CerTran[Ind1][Ind2] << "\t";
                
                std::cout << std::endl;
            }
            break;
            
        /* Impresión de la matriz de distancias minimas entre todos los 
        vértices de la gráfica. Se obtiene por medio del método de Floyd. */
        case 2:
            std::cout << "\n\n Matriz de Distancias Minimas: " << std::endl;
            for (Ind1= 0; Ind1 < NumVer; Ind1++)
            {
                std::cout << Vertices[Ind1] << ": ";
                for (Ind2= 0; Ind2 < NumVer; Ind2++)
                    std::cout << MatAdy[Ind1][Ind2] << "\t";

                std::cout << std::endl;
            }
            break;

        /* Impresión de la matriz con los vértices intermedios usados 
        para establecer los caminos de distancias minimas. Esta 
        impresión complementa la de la opción 2 cuando se aplica el 
        método FloydVerInt. */
        case 3: 
            std::cout << "\n\n Vertices Intermedios para lograr distancias minimas: " << std::endl;
            for (Ind1= 0; Ind1 < NumVer; Ind1++)
            {
                for (Ind2= 0; Ind2 < NumVer; Ind2++)
                    std::cout << VerInt[Ind1][Ind2] << "\t";
                    
                std::cout << std::endl;
            }
            break;
        /* Impresión de las distancias minimas entre un vértice y los 
        demás. Se obtiene con el método de Dijkstra. */
        case 4:
            std::cout << "\n\n Distancias minimas a partir del vertice: " 
                      << Vertices[0] << "\n\n";
            
            for (Ind1= 0; Ind1 < NumVer; Ind1++)
                std::cout<< " " << DistMin[Ind1] << "\t" << std::endl;
            break;
        default: 
            break;
    }

    std::cout << std::endl;
}

/* Método que determina si existe un camino entre cada uno de los 
vértices de la gráfica dirigida. CerTran es una matriz que representa
la cerradura transitiva de la matriz de adyacencia. */
template <class T>
void DiGrafica<T>::Warshall()
{
    int Ind1, Ind2, Ind3;
    /* En la posición i,j de la matriz de adyacencia se asignó el valor 999 
    si no existe un camino directo del vértice i al vértice j. La cerradura 
    transitiva se forma inicialmente a partir de la matriz de adyacencia. */
    for (Ind1= 0; Ind1 < NumVer; Ind1++)
        for (Ind2= 0; Ind2 < NumVer; Ind2++)
            if (MatAdy[Ind1][Ind2] != 999)
                CerTran[Ind1][Ind2]= 1;

    /* Se recorren todos los vértices para determinar si existe un camino 
    entre él y los demás, usando otros vértices como intermedios. */
    for (Ind3= 0; Ind3 < NumVer; Ind3++)
        for (Ind1= 0; Ind1 < NumVer; Ind1++)
            for (Ind2= 0; Ind2 < NumVer; Ind2++)
                CerTran[Ind1][Ind2] !=
                CerTran[Ind1][Ind3] &&
                CerTran[Ind3][Ind2];
}

/* Método que encuentra el camino de costo mínimo entre todos los vértices de 
la gráfica dirigida. Va modificando la matriz de adyacencia a medida que 
encuentra un camino más corto entre dos vértices. */
template <class T>
void DiGrafica<T>::Floyd()
{
    int Ind1, Ind2, Ind3;
    for (Ind3= 0; Ind3 < NumVer; Ind3++)
        for (Ind1= 0; Ind1 < NumVer; Ind1++)
            for (Ind2= 0; Ind2 < NumVer; Ind2++)
                if ( (MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2]) < MatAdy[Ind1][Ind2])
                    MatAdy[Ind1][Ind2]= MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2];
}

/* Método Floyd modificado para que, además de encontrar las distancias 
minimas entre todos los vértices de una digráfica, genere una matriz (VerInt) 
con los vértices intermedios utilizados para minimizar las distancias. Este 
método usa los atributos Vértices (arreglo que almacena los nombres de todos los 
vértices de la digráfica) y VerInt (arreglo donde se van guardando los vértices 
intermedios. Fue inicializado en 0 en el método constructor). */
template <class T>
void DiGrafica<T>::FloydVerInt()
{
    int Ind1, Ind2, Ind3;
    for (Ind3= 0; Ind3 < NumVer; Ind3++)
        for (Ind1= 0; Ind1 < NumVer; Ind1++)
            for (Ind2= 0; Ind2 < NumVer; Ind2++)
                if ((MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2]) < MatAdy[Ind1][Ind2]) {
                    MatAdy[Ind1][Ind2] = MatAdy[Ind1][Ind3] + MatAdy[Ind3][Ind2];
                    VerInt[Ind1][Ind2] = Vertices[Ind3];
                }
}

/* Método que encuentra la distancia minima entre un vértice dado y los
además vértices de una gráfica dirigida. En el arreglo DistMin se
almacenan las distancias minimas desde el vértice origen a cada uno
de los otros nodos. Es decir DistMin[i] almacena la menor distancia
centre el vértice origen y el vórtice i. */
template <class T>
void DiGrafica<T>::Dijkstra()
{
    int Aux[MAX], VertInc[MAX], Ver1, Ver2, Ind1, Ind2, Menor, Band, Origen;
    /* El arreglo VertInc se utiliza para guardar los vértices elegidos *
    por ser los de la distancia minima. El arreglo Aux es un arreglo 
    lógico que indica si el nodo de la posición i ya fue incluido en 
    VertInc y de esta manera evitar ciclos. */
    for (Ind1= 0; Ind1 < NumVer; Ind1++)
    {
        Aux[Ind1]= 0;
        VertInc[Ind1]= 0;
    }

    std::cout << "\n\n Ingrese vertice origen: ";
    std::cin >> Origen;

    Aux[Origen - 1]= 1;
    
    /* El arreglo donde se guardan las distancias mínimas del Origen a 
    los demás vértices se inicializa con los valores de la matriz de 
    adyacencia. */
    for (Ind1= 0; Ind1 < NumVer; Ind1++)
        DistMin[Ind1]= MatAdy[Origen][Ind1];

    for (Ind1= 0; Ind1 < NumVer; Ind1++)
    {
        /* Se busca el vértice Ver1 en (Vértices - VertInc) tal que 
        DistMin[Ver1] sea el mínimo valor. Se usa el 999 como valor 
        inicial ya que es el elegido para indicar que no existe camino 
        entre dos vértices. */
        Menor= 999;
        for (Ind2= 1; Ind2 < NumVer; Ind2++)
            if (DistMin[Ind2] < Menor && !Aux[Ind2])
            {
                Ver1= Ind2;
                Menor= DistMin[Ind2];
            }
        
        /* Se incluye Ver1 a VertInc y se actualiza el arreglo Aux. */
        VertInc[Ind1]= Ver1;
        Aux[Ver1]= 1;

        /* Se busca la distancia minima para cada vértice Ver2 en 
        (Vértices - VertInc). */
        Ver2= 1;
        while (Ver2 < NumVer)
        {
            Band=0;
            Ind2= 1;
            while (Ind2 < NumVer && !Band)
                if (VertInc[Ind2] == Ver2)
                    Band= 1;
                else
                    Ind2++;
            
            if (!Band)
                DistMin[Ver2]= Minimo(DistMin[Ver2], DistMin[Ver1] + MatAdy[Ver1][Ver2]);
            
            Ver2++;
        }
    }
}

/* Método entero que determina si un vértice dado como parámetro es o 
no un vértice de la digráfica. Regresa la posición en la que lo encuentra
o un negativo. */
template <class T>
int DiGrafica<T>::BuscaVertice(T VertiDato)
{
    int Indice= 0, Resp= -1;
    
    /* Busca el nombre del vértice dado en el arreglo que guarda los 
    nombres de todos los vértices de la gráfica. */
    while (Indice < NumVer && Vertices[Indice] != VertiDato)
        Indice++;
    
    if (Indice < NumVer)
        Resp= Indice;
    
    return Resp;
}

/* Método que genera una lista con los vértices adyacentes de un vértice 
dado como parámetro. Recibe como parámetro el nombre de un vértice y da 
como resultado una lista con sus vértices adyacentes. */
template <class T>
Lista<T> DiGrafica<T>::VerticesAdyacentes(int VertiDato)
{
    int Indice;
    Lista <T> Adyacentes;
    for (Indice= 0; Indice < NumVer; Indice++)
        if (MatAdy[VertiDato][Indice] != 0)
            Adyacentes.InsertaFinal(Vertices[Indice]);
            
    return Adyacentes;
}

/* Este método busca una soución (estado final) de un problema
representado por medio de una gráfica. Recibe como parámetro el nivel
máximo de profundidad permitido. En esta implementación se considera
el estado final como el último vértice de la digráfica. Regresa uno si
llega al estado meta y cero en caso contrario. En el método se usan los
atributos definidos en la clase DiGrafica. Se declaran tres objetos
de la clase Lista para almacenar los vértices que se van visitando
y los pendientes de visitar, asi como una lista auxiliar para guardar 
los vértices adyacentes de uno dado. */
template <class T>
int DiGrafica<T>::DepthFirst(int NivelProf)
{
    int Indice, EstadoFinal= 0, VisitaAux[MAX], Resp= 1;
    Lista<T> Visitado, NoVisitado, ListaAux;
    T VertiX;
    for (Indice= 0; Indice < NumVer; Indice++)
        VisitaAux[Indice]= 0;

    /* Se guarda el primer vértice (representa el estado inicial) de la 
    digráfica en la lista NoVisitado. */
    NoVisitado.InsertaFinal(Vertices[0]);
    
    /* En el arreglo auxiliar VisitaAux se indica que el primer vértice 
    ya fue visitado, para evitar caer en ciclos. */
    VisitaAux[0]= 1;
    
    /* Se repiten los pasos del algoritmo de búsqueda mientras no se llegue 
    al estado final y mientras queden elementos en la lista NoVisitado. */
    Indice= 0;
    while (!NoVisitado.ListaVacia() && !EstadoFinal)
    {
        /* Se saca el primer elemento de NoVisitado. */
        VertiX= NoVisitado.EliminaPrimero();
        
        /* Se evalúa si el vértice no está en Visitado y si no se alcanzó 
        la profundidad limite. */
        if (!Visitado.BuscaDesordenada(VertiX) && Indice < NivelProf)
        {
            Visitado.InsertaFinal(VertiX);

            /* Se obtienen sus vértices adyacentes. */
            ListaAux= VerticesAdyacentes(BuscaVertice(VertiX));
            while (!ListaAux.ListaVacia() && !EstadoFinal)
            {
                VertiX= ListaAux.EliminaPrimero();
                if (BuscaVertice(VertiX) != NumVer-1 && !VisitaAux[BuscaVertice(VertiX)])
                {
                    NoVisitado.InsertaInicio(VertiX);
                    VisitaAux[BuscaVertice(VertiX)]= 1;
                }
                /* Se evalúa si se llegó al último vértice (representa el
                restado final). */
                else
                    if (BuscaVertice(VertiX) == NumVer-1) 
                    {
                        Visitado.InsertaFinal(VertiX);
                        EstadoFinal= 1;
                    }
            }
            Indice++;
        }
    }
    /* Si se llegó al estado final se imprime la secuencia de vértices visitados. */
    if (EstadoFinal)
        Visitado.ImprimeIterativo();
    else
        Resp= 0;
    
    return Resp;
}

#endif /* _DIGRAFICA_H_ */