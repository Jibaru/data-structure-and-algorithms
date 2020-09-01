#include <iostream>
#include <string.h>

using namespace std;

/* Prototipo de la plantilla de la clase Pila. De esta forma, la clase 
Nodo podrá hacer referencia a ella. */
template <class T>
class Pila;

/* Definición de la clase Nodo. */
template <class T>
class Nodo {
private:
    Nodo<T> * Liga;
    T Info;
public:
    Nodo();
    friend class Pila<T>;
};

/* Declaración del método constructor por omisión. Inicializa con el 
valor NULL el puntero al siguiente nodo. */
template <class T>
Nodo<T>::Nodo()
{
    Liga= NULL;
}

/* Definición de la clase Pila. Su único atributo es el Tope, que en 
este caso es un puntero al primer elemento almacenado en la pila. */
template <class T>
class Pila
{
private:
    Nodo<T> * Tope;
public:
    Pila ();
    int Push(T);
    int Pop(T *);
};

/* Declaración del método constructor. Inicializa el puntero al primer 
elemento de la pila con el valor NULL. Indica pila vacia. */
template <class T>
Pila<T>::Pila()
{
    Tope= NULL;
}

/* Método que inserta un elemento en la pila. Recibe como parámetro el 
dato a insertar. El método verifica el caso de pila llena. Si se puede 
llevar a cabo la inserción regresa 1, en caso contrario regresa 0. */
template <class T>
int Pila<T>::Push(T Dato)
{
    Nodo<T> * Apunt;
    int Resp= 1;
    Apunt= new Nodo<T>();

    /* Verifica si hay espacio de memoria disponible. */
    if (Apunt)
    {
        Apunt->Info= Dato;
        Apunt->Liga= Tope;
        Tope= Apunt;
    }
    else
        Resp= 0;
        
    return Resp;
}

/* Método que elimina el elemento de la pila que está en el Tope. El 
método redefine el valor de Tope y libera el espacio de memoria del nodo 
eliminado. Regresa 1 si se lleva a cabo la eliminación y 0 en caso contrario.
Además, pasa como parámetro el contenido del nodo eliminado. */
template <class T>
int Pila<T>::Pop(T *Dato)
{
    Nodo<T> * Apunt;
    int Resp= 1;
    if (Tope)
    {
        *Dato= Tope->Info;
        Apunt= Tope;
        Tope= Apunt->Liga; delete(Apunt);
    }
    else 
    {
        /* La Pila está vacía. */
        Resp= 0;
    }
    
    return Resp;
}

/* Función principal. Se lee una expresión aritmética dada en notación 
postfija. La evalúa con ayuda de una pila. Se sugiere que siga el proagrama 
con la expresión: "53+8*2/"	*/
int main()
{
    Pila<double> Operandos;
    char Expresion[20];
    int Indice, Resp= 1;
    double Resultado, Op1, Op2;

    cout << "\n\nIngrese la expresion en notacion postfija. \n";
    cin >> Expresion;

    for (Indice= 0; Indice < strlen(Expresion); Indice++)
    {
        if (Expresion[Indice] >= '1' && Expresion[Indice] <= '9')
        {
            Operandos.Push(Expresion[Indice]-'0');
            /* Se le resta el ordinal correspondiente al carácter '0' del 
            código ASCII para obtener el valor decimal del carácter tomado 
            de la cadena. Si, por ejemplo, el carácter fuera el '8', al 
            restarle el ordinal del '0' queda el valor entero 8. */
        }
        else
        {   
            if (Operandos.Pop(&Op1) && Operandos.Pop(&Op2))
            { 
                switch (Expresion[Indice])
                {
                    case '+': Resultado= Op2 + Op1; break;
                    case '-': Resultado= Op2 - Op1; break;
                    case '*': Resultado= Op2 * Op1; break;
                    case '/': Resultado= Op2 / Op1; break;
                }
                Operandos.Push(Resultado);
            }
            else
                Resp= 0;
        }
    }

    if (Resp)
    {
        Operandos.Pop(&Resultado);
        cout << "\n\nLa expresion en notacion postfija fue evaluada: " << Resultado << " \n\n";
    }
    else
        cout << "\n\nLa expresion dada es incorrecta.\n\n";

    return 0;
}