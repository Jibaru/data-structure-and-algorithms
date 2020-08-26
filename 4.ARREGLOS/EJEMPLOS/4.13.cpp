#include <iostream>
using namespace std;
/* Constante que define el máximo número de elementos que se pueden 
almacenar en el arreglo unidimensional. */
#define MAX 50

/* Definición de la clase MatrizTrianSup. Sus atributos son un arreglo 
unidimensional en el cual se guardarán los valores de la matriz 
triangular superior y el orden de la misma. */
template <class T>
class MatrizTrianSup
{
private:
    T Datos[MAX]; int Dim;
public:
    MatrizTrianSup();
    int RegresaPosic(int, int);
    int TotalDatos();
    void Lectura();
    void ImprimeMatriz();
    void ImprimeDatos();
    MatrizTrianSup<T> operator+(MatrizTrianSup<T>&);
};

/* Método constructor por omisión. */
template <class T>
MatrizTrianSup<T>::MatrizTrianSup()
{}

/* Método que calcula la posición que le corresponde a un elemento de la 
matriz dentro del arreglo unidimensional en el cual fue guardado. */
template <class T>
int MatrizTrianSup<T>::RegresaPosic(int Ren, int Col)
{
    return (Dim * Ren - ((Ren - 1) * Ren) / 2 + (Col - Ren));
}

/* Método que calcula el total de elementos guardados en el arreglo
unidimensional, que son los que estaban de la diagonal principal hacia
arriba. */
template <class T>
int MatrizTrianSup<T>::TotalDatos()
{
    return ((Dim * (Dim + 1)) / 2) ;
}

/* Método que lee del teclado los valores para los atributos de la clase.
Al usuario sólo se le piden los valores que están en la diagonal arriba de ella. */
template <class T>
void MatrizTrianSup<T>::Lectura()
{
    int Ren, Col, Indice= 0;
    do {
        cout << "\n\nIngrese orden de la matriz triangular superior: ";
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
void MatrizTrianSup<T>::ImprimeMatriz()
{
    int Ren, Col, Indice;
    cout << "\n\nMatriz triangular superior\n\n";
    for (Ren= 0; Ren < Dim; Ren++)
    {
        for (Col= 0; Col < Dim; Col++) 
        {
            if (Ren <= Col)
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
void MatrizTrianSup<T>::ImprimeDatos()
{
    int Indice, TotElem;
    TotElem= TotalDatos();
    cout << "\n\nElementos de la matriz triangular superior\n\n";
    for (Indice= 0; Indice < TotElem; Indice++)
        cout << Datos[Indice] << " ";
    cout << "\n\n";
}

/* Sobreescritura del operador + que suma dos matrices
triangulares superiores de la misma dimension*/
template <class T>
MatrizTrianSup<T> MatrizTrianSup<T>::operator+(MatrizTrianSup<T>& otro)
{
    int i;
    MatrizTrianSup<T> nuevo = MatrizTrianSup<T>();
    nuevo.Dim = Dim;
    for (i = 0; i < TotalDatos(); i++)
    {
        nuevo.Datos[i] = Datos[i] + otro.Datos[i];
    }
    return nuevo;
}