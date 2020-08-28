/* Definición del número máximo de elementos que puede contener la cola 
circular, por estar implementada con un arreglo unidimensional. */
#define MAX 10

/* Se define la plantilla de la clase ColaCircular. */
template <class T>
class ColaCircular {
private:
    T EspacioCola[MAX];
    int Frente, Final;
public:
    ColaCircular();
    int InsertaCCircular(T);
    int EliminaCCircular(T *);
    int ColaCircularLlena();
    int ColaCircularVacia();
};

/* Declaración del método constructor. Inicializa los punteros en -1 
indicando que la cola circular está vacia. */
template <class T>
ColaCircular<T>::ColaCircular()
{
    Frente= -1;
    Final= -1;
}

/* Método entero que introduce un dato en la cola circular. El método 
recibe como parámetro el valor a insertar. El método da como resultado 
el valor 1 si la inserción se lleva a cabo y 0 en caso contrario. */
template <class T>
int ColaCircular<T>::InsertaCCircular(T Dato)
{
    int Resp= 0;
    if (!ColaCircularLlena())
    {
        Resp= 1;
        Final= (Final +1) % MAX;
        EspacioCola[Final]= Dato;

        if (Frente == -1)
            Frente= 0;
    }
    
    return Resp;
}

/* Método entero que elimina un dato de la cola circular. El método 
regresa el valor eliminado por medio de un parámetro por referencia. 
Da como resultado el valor 1 si realiza la eliminación y 0 en caso 
contrario. */
template <class T>
int ColaCircular<T>::EliminaCCircular(T *Dato)
{
    int Resp= 0;
    if (!ColaCircularVacia())
    {
        Resp= 1;
        *Dato= EspacioCola[Frente];
        
        if (Frente == Final)
        {
            Frente= -1;
            Final= -1;
        }
        else
            Frente= (Frente + 1) % MAX;
    }

    return Resp;
}

/*Método auxiliar que verifica si la cola circular está llena. Regresa 1 
si la cola no tiene espacios disponibles y 0 en caso contrario. */
template <class T>
int ColaCircular<T>::ColaCircularLlena()
{
    if ((Final + 1) % MAX == Frente)
        return 1;
    else
        return 0;
}

/* Método auxiliar que verifica si la cola circular está vacía. Regresa 1 
si la cola no tiene ningún elemento almacenado y 0 en caso contrario. */
template <class T>
int ColaCircular<T>::ColaCircularVacia()
{
    if (Frente == -1)
        return 1;
    else
        return 0;
}
