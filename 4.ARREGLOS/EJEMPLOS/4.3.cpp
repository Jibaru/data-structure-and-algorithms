/* Se define una constante para almacenar el número máximo de elementos
que puede guardar el arreglo. */
#include <iostream>
using namespace std;
#define MAX 100
/* Se define la plantilla de la clase Arreglo con todos sus atributos y 
métodos. Se asume que los elementos del arreglo están ordenados ascendentemente.
Los atributos corresponden a los explicados en la sección 4.2. */
template <class T>
class Arreglo {
private:
    T Datos[MAX];
    int Tam;
public:
    Arreglo();
    void Lectura();
    int InsertaOrdenado(T);
    int EliminaOrdenado(T);
    void Escribe();
    int BuscaOrdenado(T);
};

/* Declaración del método constructor. Inicializa el número actual de 
elementos en 0. */
template <class T>
Arreglo<T>::Arreglo()
{
    Tam= 0;
}

/* Método que permite leer el número de elementos que se van a almacenar 
y el valor de cada uno de ellos. Verifica que el total de elementos sea 
al menos 1 y que no supere el máximo especificado. */
template <class T> void Arreglo<T>::Lectura()
{
    int Indice;
    do {
        cout << "\n\n Ingrese número de datos a guardar: ";
        cin >> Tam;
    } while (Tam < 1 || Tam > MAX);
        
    for (Indice= 0; Indice < Tam; Indice++)
    {
        cout << "\nIngrese el " << Indice + 1 << " dato: ";
        cin >> Datos[Indice];
    }
}

/* Método que inserta un elemento en un arreglo ordenado crecientemente, 
sin alterar su orden. Recibe como parámetro un dato de tipo T {Valor). 
Da como resultado uno de tres posibles valores: 1 si Valor se inserta,
0 si el arreglo está lleno y -1 si Valor ya está en el arreglo. Si la 
inserción concluye con éxito se incrementa a Tam en uno.*/ 
template <class T>
int Arreglo<T>::InsertaOrdenado(T Valor)
{
    int Indice, Posic, Resultado= 1;
    if (Tam < MAX)
    {
        Posic= BuscaOrdenado(Valor);
        if (Posic > 0)
            Resultado= -1;
        else
        {
            Posic= (Posic * -1) - 1;
            for (Indice= Tam; Indice > Posic; Indice--)
                Datos[Indice]= Datos[Indice - 1];
            Datos[Posic]= Valor;
            Tam++;
        }
    }
    else
        Resultado= 0;

    return Resultado;
}

/* Método que elimina un elemento de un arreglo. Recibe como 
parámetro, Valor, un dato de tipo T. Da como resultado uno de tres 
posibles valores: 1 si Valor se eliminó, 0 si el arreglo está vacio 
y -1 si Valor no está en el arreglo. En caso de éxito, disminuye a Tam 
en uno. */
template <class T>
int Arreglo<T>::EliminaOrdenado(T Valor)
{
    int Posic, Indice, Resultado= 1;
    if (Tam > 0)
    {
        Posic= BuscaOrdenado(Valor);
        if (Posic < 0)
            Resultado= -1;
        else
        {
            Tam--;
            for (Indice= Posic; Indice < Tam; Indice++)
                Datos[Indice]= Datos[Indice+1];
        }
    }
    else
        Resultado= 0;
    
    return Resultado;
}

/* Método que despliega los valores almacenados en el arreglo. */
template <class T>
void Arreglo<T>::Escribe()
{
    int Indice;
    if (Tam > 0)
    {
        cout << "\n Impresión de datos\n";
        for (Indice= 0; Indice < Tam; Indice++)
        cout << "\t" << Datos[ Indice];
    }
    else
        cout << "\nNo hay elementos registrados.";
}

/* Método que busca un elemento en un arreglo ordenado ascendentemente. 
Recibe como parámetro un dato de tipo T {Valor). Si lo encuentra, 
regresa la posición del mismo. En caso contrario, regresa el negativo 
de la posición (+1) en la que deberla estar. Note que el método regresa 
la posición más uno para poder indicar con el negativo la posición en la 
que deberla estar si ésta fuera 0. */
template <class T>
int Arreglo<T>::BuscaOrdenado(T Valor)
{
    int Indice= 0, Resultado;

    while ((Indice < Tam) && (Datos[Indice] < Valor))
        Indice++;

    if (Indice = Tam || Datos[Indice] > Valor)
        Resultado= -(Indice +1);
    else
        Resultado= Indice;

    return Resultado;
}
