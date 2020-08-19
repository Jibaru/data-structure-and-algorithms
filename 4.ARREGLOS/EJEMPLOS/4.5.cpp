/* Se define una constante para almacenar el número máximo de elementos 
que puede guardar el arreglo. */
#include <iostream>
using namespace std;
#define MAX 100

/* Se define la plantilla de la clase ArreParal con todos sus atributos 
y métodos. Se incluyen diferentes versiones de algunos de los métodos 
de tal manera que la plantilla sirva tanto para arreglos ordenados como 
para arreglos desordenados. */
template <class T>
class ArreParal {
private:
    T Datos[MAX];
    int Tam;
public:
    ArreParal();
    int	InsertaOrdenado(int , T);
    int	InsertaDesordenado(T);
    void Elimina(int);
    int	BuscaOrdenado(T);
    int	BuscaDesordenado(T);
    T RegresaValor(int);
    int	RegresaTamano();
    int ActualizaValor(int, T);
    template <class M>
    friend istream &operator>>(istream &, ArreParal<M> &);
    template <class M>
    friend ostream &operator<<(ostream &, ArreParal<M> &);
};

/* Declaración del método constructor. Inicializa el número actual de 
elementos en 0. */
template <class T>
ArreParal<T>::ArreParal()
{
    Tam= 0;
}

/* Método que inserta un elemento en un arreglo ordenado crecientemente, 
sin alterar su orden. Recibe como parámetros: Posic, un entero que 
indica la posición en la que debe insertarse el nuevo elemento si hay 
espacio y el elemento a insertar que es un dato de tipo T (Valor). Da 
como resultado uno de dos posibles valores: 1 si Valor se inserta o 0 
si el arreglo está lleno. Si la inserción concluye con éxito se incrementa
a Tam en uno.*/
template <class T>
int ArreParal<T>::InsertaOrdenado(int Posic, T Valor)
{
    int Indice, Resultado=1;
    if (Tam < MAX)
    {
        for (Indice= Tam; Indice > Posic; Indice--)
            Datos[Indice]= Datos[Indice - 1];
        Datos[Posic]= Valor;
        Tam++;
    }
    else
        Resultado= 0;
    
    return Resultado;
}

/* Método que inserta un elemento en un arreglo desordenado. Recibe como 
parámetro el elemento a insertar, que es un dato de tipo T (Valor). Da 
como resultado uno de dos posibles valores: 1 si Valor se inserta o 0 
si el arreglo está lleno. Si la inserción concluye con éxito se incrementa
a Tam en uno.*/
template <class T>
int ArreParal<T>::InsertaDesordenado(T Valor)
{
    int Indice, Resultado= 1; 
    if (Tam < MAX)
    {
        Datos[Tam]= Valor;
        Tam++;
    }
    else
        Resultado= 0;
        
    return Resultado;
}

/* Método que elimina un elemento de un arreglo. Recibe como parámetro 
un número entero, Posic, que indica la posición del dato a eliminar, 
este método se invoca sólo si antes se ejecutó con éxito el método de 
búsqueda. Se disminuye el valor de Tam en uno. */
template <class T>
void ArreParal<T>::Elimina(int Posic)
{
    int Indice;
    Tam--;
    for (Indice= Posic; Indice < Tam; Indice++)
        Datos[Indice]= Datos[Indice+1];
}

/* Método que busca un elemento en un arreglo ordenado ascendentemente. 
Recibe como parámetro un dato de tipo T (Valor). Si lo encuentra, 
regresa la posición del mismo. En caso contrario, regresa el negativo 
de la posición (+1) en la que debería estar. */
template <class T>
int ArreParal<T>::BuscaOrdenado(T Valor)
{
    int Indice= 0, Resultado;
    while ((Indice < Tam) && (Datos[Indice] < Valor))
        Indice++;

    if (Indice == Tam || Datos[Indice] > Valor)
        Resultado= -(Indice +1);
    else
        Resultado= Indice;
    
    return Resultado;
}

/* Método que busca un elemento en un arreglo desordenado. Recibe como 
parámetro un dato de tipo T (Valor). Si lo encuentra, regresa la 
posición del mismo. En caso contrario, regresa un número negativo. */
template <class T>
int ArreParal<T>::BuscaDesordenado(T Valor)
{
    int Indice= 0, Resultado= -1;
    while ((Indice < Tam) && (Datos[Indice] != Valor))
        Indice++;
    
    if (Indice < Tam)
        Resultado= Indice;
    
    return Resultado;
}
/* Método que permite, a usuarios externos a la clase, conocer el 
contenido de una casilla del arreglo. Recibe como parámetro un entero, 
Indice, que indica el número de celda de la cual se dará su contenido. 
El resultado es un valor de tipo T. */
template <class T>
T ArreParal<T>::RegresaValor(int Indice)
{
    return Datos[Indice];
}

/* Método que regresa el total de elementos del arreglo. */
template <class T>
int ArreParal<T>::RegresaTamano()
{
    return Tam;
}

template <class T>
int ArreParal<T>::ActualizaValor(int Indice, T valor) {
    int Resultado = 1;
    if(Indice > Tam) {
        Resultado = -1;
    } else {
        Datos[Indice] = valor;
    }
    return Resultado;
}

/* Definición de la sobrecarga del operador >>. Por medio de este 
operador sobrecargado y declarado como amigo de la clase ArreParal se 
podrá leer de manera directa a todos los miembros de la misma. */
template <class T>
istream &operator>>(istream& Lee, ArreParal<T>& ObjArre)
{
    int Indice;
    do {
        Lee >> ObjArre.Tam;
    } while (ObjArre.Tam <1 || ObjArre.Tam > MAX);
    
    for (Indice= 0; Indice < ObjArre.Tam; Indice++)
        Lee >> ObjArre.Datos[Indice];
    
    return Lee;
}

/* Definición de la sobrecarga del operador <<. Por medio de este 
operador sobrecargado y declarado como amigo de la clase ArreParal se 
podrá desplegar de manera directa a todos los miembros de la misma. */
template <class T>
ostream &operator<<(ostream& Escribe, ArreParal<T>& ObjArre)
{
    int Indice;
    if (ObjArre.Tam > 0)
        for (Indice= 0; Indice < ObjArre.Tam; Indice++)
            Escribe << ObjArre.Datos[Indice] << " ";
    else
        cout<< "\nNo hay elementos registrados.";
    
    return Escribe;
}