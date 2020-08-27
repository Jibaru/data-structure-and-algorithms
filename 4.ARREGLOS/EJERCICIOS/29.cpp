/*
29.	Se llama matriz simétrica cuando se cumple la condición:
Datos[Ren][Col] = Datos[Col][Ren]
para todo 1 <= Ren, Col <= orden del arreglo. Cuando se presenta un caso así, 
resulta conveniente guardar sólo la matriz triangular inferior o superior, 
ya que de lo contrario se duplicaría la información. Defina una plantilla 
para una clase que represente este tipo de matrices.
*/
#include <iostream>

using namespace std;
#define MAX 50

/* Definición de la clase MatrizSimetrica. Sus atributos son un arreglo 
unidimensional en el cual se guardarán los valores de la matriz 
triangular simetrica y el orden de la misma. */
template <class T>
class MatrizSimetrica
{
private:
    T Datos[MAX]; int Dim;
public:
    MatrizSimetrica();
    MatrizSimetrica(T[], int, int);
    int RegresaPosic(int, int);
    int TotalDatos();
    void Lectura();
    void ImprimeMatriz();
    void ImprimeDatos();
    T* regresaDato(int, int);
};

/* Método constructor por omisión. */
template <class T>
MatrizSimetrica<T>::MatrizSimetrica()
{}

/* Metodo constructor a partir de un arreglo de n posiciones*/
template <class T>
MatrizSimetrica<T>::MatrizSimetrica(T arr[], int n, int dim)
{
    Dim = dim;
    int Ren, Col, Indice = 0;
    for (Ren= 0; Ren < Dim; Ren++)
    {
        for (Col= Ren; Col < Dim; Col++) 
        {
            Datos[Indice] = arr[Indice];
            Indice= Indice + 1;
        }
    }
}

/* Método que calcula la posición que le corresponde a un elemento de la 
matriz dentro del arreglo unidimensional en el cual fue guardado. */
template <class T>
int MatrizSimetrica<T>::RegresaPosic(int Ren, int Col)
{
    return ((Ren * (Ren + 1)) / 2) + Col;
}

/* Método que calcula el total de elementos guardados en el arreglo
unidimensional, que son los que estaban de la diagonal principal hacia
arriba. */
template <class T>
int MatrizSimetrica<T>::TotalDatos()
{
    return ((Dim * (Dim + 1)) / 2) ;
}

/* Método que lee del teclado los valores para los atributos de la clase.
Al usuario sólo se le piden los valores que están en la diagonal arriba de ella. */
template <class T>
void MatrizSimetrica<T>::Lectura()
{
    int Ren, Col, Indice= 0;
    do {
        cout << "\n\nIngrese orden de la matriz simetrica: ";
        cin >> Dim;
    } while (Dim > MAX || Dim < 0);
    
    for (Ren= 0; Ren < Dim; Ren++)
    {
        for (Col= Ren; Col < Dim; Col++) 
        {
            cout << "\n\nIngrese el elemento " << Ren + 1 << " - " << Col + 1 << ": ";
            cin >> Datos[Indice];
            Indice= Indice + 1;
        }
    }
}

/* Método que imprime los valores almacenados con forma de arreglo 
bidimensional. */
template <class T>
void MatrizSimetrica<T>::ImprimeMatriz()
{
    int Ren, Col, Indice;
    cout << "\n\nMatriz simetrica\n\n";
    for (Ren= 0; Ren < Dim; Ren++)
    {
        for (Col= 0; Col < Dim; Col++) 
        {
            if (Col <= Ren)
            {
                Indice= RegresaPosic(Ren, Col);
                cout << Datos[Indice] << "\t";
            }
            else {
                Indice= RegresaPosic(Col, Ren);
                cout << Datos[Indice] << "\t";
            }
        
        }
        cout << "\n";
    }
    cout << "\n\n";
}

/* Método que imprime sólo los valores almacenados. */
template <class T>
void MatrizSimetrica<T>::ImprimeDatos()
{
    int Indice, TotElem;
    TotElem= TotalDatos();
    cout << "\n\nElementos de la matriz simetrica\n\n";
    for (Indice= 0; Indice < TotElem; Indice++)
        cout << Datos[Indice] << " ";
    cout << "\n\n";
}

template <class T>
T* MatrizSimetrica<T>::regresaDato(int Ren, int Col)
{
    int Indice= RegresaPosic(Col, Ren);
    return &Datos[Indice];
}

void usaMatrizSimetrica()
{
    MatrizSimetrica<int> matriz = MatrizSimetrica<int>();
    matriz.Lectura();
    matriz.ImprimeDatos();
    matriz.ImprimeMatriz();
}