#include <iostream>
using namespace std;
/* Definición del número máximo de elementos que puede contener la pila, 
restricción que resulta del uso de un arreglo unidimensional. */
#define MAX 10

/* Se define la plantilla de la clase Pila con todos sus atributos y 
métodos. Además, se incluye una pequeña aplicación de la misma. */
template <class T>
class Pila {
private:
    T EspacioPila[MAX];
    int Tope;
public:
    Pila();
    void Push(T Dato);
    void Pop(T *Dato);
    int PilaLlena();
    int PilaVacia();
};

/* Declaración del método constructor. Inicializa el Tope en -1, 
indicando pila vacia. */
template <class T>
Pila<T>::Pila()
{
    Tope= -1;
}

/* Método que introduce un dato en la pila, actualizando el tope de la 
misma. El uso de este método presupone que antes de invocarlo se debe 
verificar que haya espacio disponible en la pila. */
template <class T>
void Pila<T>::Push(T Dato)
{
    EspacioPila[++Tope]= Dato;
}

/* Método que quita al elemento que está en el tope de la pila y lo 
asigna a un parámetro por referencia. El uso de este método presupone 
que antes de invocarlo se debe verificar que la pila no esté vacía. */
template <class T>
void Pila<T>::Pop(T *Dato)
{
    *Dato= EspacioPila[Tope--];
}

/* Método auxiliar que verifica si la pila está llena. Regresa 1 si 
todos los espacios están ocupados y 0 en caso contrario. */
template <class T>
int Pila<T>::PilaLlena()
{
    if (Tope == MAX-1)
        return 1;
    else
        return 0;
}

/* Método auxiliar que verifica si la pila está vacía, regresando 1 si
*lo está y 0 en caso contrario. */
template <class T>
int Pila<T>::PilaVacia()
{
    if (Tope == -1)
        return 1;
    else
        return 0;
}

/* Función que usa la plantilla de la clase Pila. Se almacenan algunos 
números enteros en un objeto tipo Pila y posteriormente se quita el 
último guardado y lo imprime. */
void FuncionUsaPila ()
{
    /* Declaración de un objeto tipo Pila, usando el tipo int para 
    instanciar la T. */
    Pila<int> ObjPila;
    int Valor = 0;
    /* Mientras la pila no se llena inserta números en la misma. En este 
    ejemplo, es en la aplicación donde se evalúa que haya espacio disponible 
    antes de llamar al método que inserta un valor en la pila. */
    while (ObjPila.PilaLlena() != 1)
        ObjPila.Push(Valor++);
    
    /* Verifica si la pila no está vacía. Si es así, quita el elemento 
    almacenado en el Tope (el último insertado) y lo imprime. */
    if (ObjPila.PilaVacia() != 1) {
        ObjPila.Pop(&Valor);
        cout << Valor << "\n";
    }
}

int main()
{
    FuncionUsaPila();
    return 0;
}