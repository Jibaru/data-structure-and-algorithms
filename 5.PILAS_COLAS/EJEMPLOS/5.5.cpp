#include <iostream>
using namespace std;

/* Definición del número máximo de elementos que puede contener la cola, 
restricción que surge de usar un arreglo unidimensional. */
#define MAX 10

/* Definición de la plantilla de la clase Cola. Se utiliza sobrecarga de 
operadores y se define a los métodos de inserción y eliminación como 
métodos enteros. */
template <class T>
class Cola {
private:
    T EspacioCola[MAX];
    int Frente, Final;
public:
    Cola();
    int operator+(T);
    int operator-(T*);
    int ColaLlena();
    int ColaVacia();
};

/* Declaración del método constructor. Inicializa los punteros en -1, 
indicando que la cola está vacia. */
template <class T>
Cola<T>::Cola()
{
    Frente= -1;
    Final= -1;
}

/* Método que inserta un valor en la cola. La inserción se lleva a cabo por 
el extremo identificado como Final. Antes de llevar a cabo la inserción se 
verifica que la cola tenga espacio disponible. Si la operación concluye con 
éxito el método regresa un 1, en caso contrario un 0.*/
template <class T>
int Cola<T>::operator+(T Dato)
{
    /* La variable Res se inicializa en 0 (fracaso). Si la inserción se 
    lleva a cabo, entonces se le asignará el valor de 1 (éxito). */
    int Res= 0;
    
    if (ColaLlena() != 1)
    {
        EspacioCola[++Final]= Dato;
        if (Final == 0)
            Frente= 0;
        Res= 1;
    }

    return Res;
}
/* Método que elimina un elemento de la cola. La eliminación se lleva ♦a cabo por el extremo identificado como Frente. Antes de quitar el ♦elemento se debe validar que la cola no esté vacía. El valor eliminado ♦se regresa por medio de un parámetro por referencia. Si la operación ‘♦concluye con éxito el método regresa un 1, en caso contrario un 0. */ 
template <class T>
int Cola<T>::operator-(T *Dato)
{
    /* La variable Res se inicializa en 0 (fracaso). Si la eliminación se 
    lleva a cabo, entonces se le asignará el valor de 1 (éxito). */
    int Res= 0;
    
    if (!ColaVacia())
    {
        *Dato= EspacioCola[Frente];
        if (Frente == Final)
        {
            Frente= -1;
            Final= -1;
        }
        else
            Frente++;

        Res= 1;
    }
    
    return Res;
}

/* Método auxiliar que verifica si la cola está llena. Regresa 1 si la 
cola no tiene espacio disponible y 0 en caso contrario. */
template <class T>
int Cola<T>::ColaLlena()
{
    if (Final == MAX-1)
        return 1;
    else
        return 0;
}

/* Método auxiliar que verifica si la cola está vacia. Regresa 1 si la 
cola no tiene ningún elemento y 0 en caso contrario. */
template <class T>
int Cola<T>::ColaVacia()
{
    if (Frente == -1)
        return 1;
    else
        return 0;
} 
