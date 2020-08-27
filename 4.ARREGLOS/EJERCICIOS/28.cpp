/*
28.	Retome el problema anterior. Defina una plantilla para una clase que 
represente este tipo de matrices.
*/
#include <iostream>

using namespace std;
#define MAX 50

/* Definición de la clase MatrizTrianInf. Sus atributos son un arreglo 
unidimensional en el cual se guardarán los valores de la matriz 
triangular inferior y el orden de la misma. */
template <class T>
class MatrizTriDiagonal
{
private:
    T Datos[MAX];
    int Dim;
public:
    MatrizTriDiagonal();
    int RegresaPosic(int, int);
    int TotalDatos();
    void Lectura();
    void ImprimeMatriz();
    void ImprimeDatos();
};

/* Método constructor por omisión. */
template <class T>
MatrizTriDiagonal<T>::MatrizTriDiagonal()
{}

/* Método que calcula la posición que le corresponde a un elemento de la 
matriz dentro del arreglo unidimensional en el cual fue guardado. */
template <class T>
int MatrizTriDiagonal<T>::RegresaPosic(int Ren, int Col)
{
    int pos;
    if(Ren == Col) {
        pos = 3 * Ren;
    } else if(Ren == Col - 1) {
        pos = (3 * Ren) + 1;
    } else if(Ren == Col + 1) {
        pos = (3 * Ren) - 1;
    }
    return pos;
}

/* Método que calcula el total de elementos guardados en el arreglo
unidimensional, que son los que estaban de la diagonal principal, diagonal arriba
y debajo de esta. */
template <class T>
int MatrizTriDiagonal<T>::TotalDatos()
{
    return (Dim + (2 * (Dim - 1)));
}

/* Método que lee del teclado los valores para los atributos de la clase.
Al usuario sólo se le piden los valores que están en la diagonal principal,
la diagonal sobre y debajo de esta*/
template <class T>
void MatrizTriDiagonal<T>::Lectura()
{
    int Ren, Col, Indice= 0;
    do {
        cout << "\n\nIngrese orden de la matriz tridiagonal: ";
        cin >> Dim;
    } while (Dim > MAX || Dim < 0);
    
    for (Ren= 0; Ren < Dim; Ren++)
    {
        for (Col= 0; Col < Dim; Col++) 
        {
            if (Col == Ren ||Ren == Col - 1 ||Ren == Col + 1)
            {
                cout << "\n\nIngrese el elemento " << Ren + 1 << " - " << Col + 1 << ": ";
                cin >> Datos[Indice];
                Indice= Indice + 1;
            }
        }
    }
}

/* Método que imprime los valores almacenados con forma de arreglo 
bidimensional. */
template <class T>
void MatrizTriDiagonal<T>::ImprimeMatriz()
{
    int Ren, Col, Indice;
    cout << "\n\nMatriz tridiagonal\n\n";
    for (Ren= 0; Ren < Dim; Ren++)
    {
        for (Col= 0; Col < Dim; Col++) 
        {
            if (Col == Ren ||Ren == Col - 1 ||Ren == Col + 1)
            {
                Indice= RegresaPosic(Ren, Col);
                cout << Datos[Indice] << "\t";
            }
            else
                cout << "0\t";
        
        }
        cout << "\n";
    }
    cout << "\n\n";
}

/* Método que imprime sólo los valores almacenados. */
template <class T>
void MatrizTriDiagonal<T>::ImprimeDatos()
{
    int Indice, TotElem;
    TotElem= TotalDatos();
    cout << "\n\nElementos de la matriz tridiagonal\n\n";
    for (Indice= 0; Indice < TotElem; Indice++)
        cout << Datos[Indice] << " ";
    cout << "\n\n";
}

void usaMatrizTridiagonal()
{
    MatrizTriDiagonal<int> matriz = MatrizTriDiagonal<int>();
    matriz.Lectura();
    matriz.ImprimeDatos();
    matriz.ImprimeMatriz();
}

int main()
{
    usaMatrizTridiagonal();
    return 0;
}