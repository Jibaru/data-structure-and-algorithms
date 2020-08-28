/* Se define la plantilla de la clase Cola. Además, se incluye un 
ejemplo muy simple de aplicación de esta clase. */
#include <iostream>
using namespace std;

/* Definición del número máximo de elementos que puede contener la cola, 
restricción que surge de usar un arreglo unidimensional. */
#define MAX 10

/* Definición de la plantilla de la clase Cola. */
template <class T>
class Cola {
private:
    T EspacioCola[MAX];
    int Frente, Final;
public:
    Cola();
    void InsertaCola(T);
    void EliminaCola(T*);
    int ColaLlena();
    int ColaVacia();
};

/* Declaración del método constructor. Inicializa los punteros en -1, 
indicando que la cola está vacía. */
template <class T>
Cola<T>::Cola()
{
    Frente= -1;
    Final= -1;
}

/* Método que inserta un valor en la cola. La inserción se lleva a cabo
por el extremo identificado como Final. Antes de invocar el método se
debe verificar que la cola tenga espacio disponible. El método recibe
como parámetro el valor a insertar. */
template <class T>
void Cola<T>::InsertaCola(T Dato)
{
    EspacioCola[++Final]= Dato;
    if (Final == 0)
        Frente= 0;
}

/* Método que elimina un elemento de la cola. La eliminación se lleva a
cabo por el extremo identificado como Frente. Antes de invocar el método
se debe verificar que la cola no esté vacia. El valor eliminado se
regresa por medio de un parámetro por referencia. */
template <class T>
void Cola<T>::EliminaCola(T *Dato)
{
    *Dato= EspacioCola[Frente];
    if (Frente == Final)
    {
        Frente= -1;
        Final= -1;
    }
    else
        Frente++;
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

/* Función que hace uso de la plantilla de la clase Cola. Se declara un 
objeto tipo Cola de números enteros. Se le inserta el número 5 y luego 
se quita y se imprime. Este ejemplo sencillo muestra el uso de los 
métodos de la clase. */ 
void UsaClaseCola ()
{
    Cola<int> ObjCola;
    int Indice, Valor = 5;
    
    if (ObjCola.ColaLlena() != 1)
        ObjCola.InsertaCola(5);
    else
        cout << "\nError de desbordamiento. Cola llena. \n";

    if (ObjCola.ColaVacia() != 1)
    {
        ObjCola.EliminaCola(&Valor);
        cout << Valor << "\n";
    }
    else
        cout << "\nSubdesbordamiento. Cola vacia.\n";
}

int main() 
{
    UsaClaseCola();
    return 0;
}
