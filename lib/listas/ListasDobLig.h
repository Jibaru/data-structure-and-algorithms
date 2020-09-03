#ifndef _LISTAS_DOB_LIG_
#define _LISTAS_DOB_LIG_

#include <iostream>

/* Prototipo de la plantilla de la clase ListaDobLiga. Asi, en la clase 
NodoDobleLiga se podrá hacer referencia a ella. */
template <class T>
class ListaDobLiga;

/* Definición de la plantilla de la clase NodoDobleLiga. La clase 
ListaDobLiga se declara como una clase amiga para que pueda tener acceso a
los miembros privados de la clase NodoDobleLiga. */
template <class T>
class NodoDobleLiga
{
private:
    NodoDobleLiga<T> * LigaIzq;
    NodoDobleLiga<T> * LigaDer;
    T Info;
public:
    NodoDobleLiga();
    T RegresaInfo();
    friend class ListaDobLiga<T>;
};

/* Método constructor. Inicializa los punteros con el valor NULL. */
template <class T>
NodoDobleLiga<T>::NodoDobleLiga()
{
    LigaIzq= NULL;
    LigaDer= NULL;
}

/* Método que regresa el valor de Info, permitiendo que usuarios 
externos a la clase tengan acceso a él sin poder para modificarlo. */
template <class T>
T NodoDobleLiga<T>::RegresaInfo()
{
    return Info;
}

/* Definición de la plantilla de la clase ListaDobLiga. Esta clase tiene 
dos atributos que son los punteros al primero y último elementos de la 
misma. */
template <class T>
class ListaDobLiga {
private:
    NodoDobleLiga<T> * Primero;
    NodoDobleLiga<T> * Ultimo;
public:
    ListaDobLiga ();
    void ImprimeIzq_Der(NodoDobleLiga<T>*);
    void ImprimeDer_Izq(NodoDobleLiga<T>*);
    void ImprimeNodo(NodoDobleLiga<T>*);
    void InsertaInicio(T);
    void InsertaFinal(T);
    void InsertaOrdenado(T);
    int InsertaAntes(T, T);
    int EliminaPrimero();
    int EliminaUltimo();
    int EliminaUnNodo(T);
    int EliminaAnterior(T); 
    NodoDobleLiga<T> *Busca(T, NodoDobleLiga<T>*);
    NodoDobleLiga<T> *RegresaPrimero();
    NodoDobleLiga<T> *RegresaUltimo();
    NodoDobleLiga<T> *RegresaVecinoDer(NodoDobleLiga<T>*);
    NodoDobleLiga<T> *RegresaVecinoIzq(NodoDobleLiga<T>*);
};

/* Declaración del método constructor. Inicializa el apuntador al primero 
al último elementos con el valor de NULL, indicando lista vacia. */
template <class T>
ListaDobLiga<T>::ListaDobLiga()
{
    Primero= NULL;
    Ultimo= NULL;
}

/* Método que imprime la información almacenada en cada uno de los nodos 
de la lista, empezando por el primer nodo. La primera vez, recibe como 
parámetro el valor almacenado en Primero. */
template <class T>
void ListaDobLiga<T>::ImprimeIzq_Der(NodoDobleLiga<T>* Apunt)
{
    if (Apunt)
    {
        std::cout <<Apunt->Info << "\n";
        ImprimeIzq_Der(Apunt->LigaDer);
    }
}

/* Método que imprime la información almacenada en cada uno de los nodos 
de la lista, empezando por el último nodo. La primera vez, recibe como 
parámetro el valor almacenado en Ultimo. */
template <class T>
void ListaDobLiga<T>::ImprimeDer_Izq(NodoDobleLiga<T>* Apunt)
{
    if (Apunt)
    {
        std::cout << Apunt->Info << "\n";
        ImprimeDer_Izq(Apunt->LigaIzq);
    }
}

/* Método que imprime la información almacenada en uno de los nodos de 
la lista, cuya dirección se recibe como parámetro. */
template <class T>
void ListaDobLiga<T>::ImprimeNodo(NodoDobleLiga<T>* Apunt)
{
    std::cout << Apunt->Info << "\n";
}

/* Método que inserta un nuevo nodo con la información de Dato al inicio 
de la lista doblemente ligada. */
template <class T>
void ListaDobLiga<T>::InsertaInicio(T Dato)
{
    NodoDobleLiga<T> * Apunt;
    Apunt= new NodoDobleLiga<T>();
    Apunt->Info= Dato;
    Apunt->LigaDer= Primero;
    if (Primero)
        Primero->LigaIzq= Apunt;
    else
    {
        Ultimo= Apunt;
        Primero= Apunt;
    }

}

/* Método que inserta un nuevo nodo con la información de Dato al final 
de la lista doblemente ligada. */
template <class T>
void ListaDobLiga<T>::InsertaFinal(T Dato)
{
    NodoDobleLiga<T> * Apunt;
    Apunt= new NodoDobleLiga<T>;
    Apunt->Info= Dato;
    Apunt->LigaIzq= Ultimo;
    if (Ultimo)
        Ultimo->LigaDer= Apunt;
    else
        Primero= Apunt;
    Ultimo= Apunt;
}

/* Método que inserta un nuevo nodo con la información de Dato, de 
manera que los elementos de la lista vayan quedando ordenados de menor 
a mayor. */
template <class T>
void ListaDobLiga<T>::InsertaOrdenado(T Dato)
{
    NodoDobleLiga<T> * Apun1, *Apun2, *Apun3;
    /* Si la lista está vacia o si el valor a insertar es más pequeño que 
    el contenido del primer nodo, entonces se invoca al método que 
    inserta al inicio de la lista. */
    if (!Primero || Dato < Primero->Info)
        InsertaInicio(Dato);
    else
    {
        /* Si el dato a insertar es más grande que el contenido del 
        último nodo, entonces se invoca al método que inserta al final 
        de la lista. */
        if (Dato > Ultimo->Info)
            InsertaFinal(Dato);
        else
        {
            Apun1= new NodoDobleLiga<T>;
            Apun1->Info= Dato;
            Apun2= Primero;
            while (Apun2->Info < Apun1->Info)
                Apun2= Apun2->LigaDer;

            Apun3= Apun2->LigaIzq;
            Apun3->LigaDer= Apun1;
            Apun1->LigaDer= Apun2;
            Apun1->LigaIzq= Apun3;
            Apun2->LigaIzq= Apun1;
        }
    }

}

/* Método que inserta un nuevo nodo con la información de Dato antes de 
un nodo dado como referencia, cuya información está en Ref. Regresa 1 
si encuentra la referencia y puede llevar a cabo la inserción, 0 si no 
encuentra la referencia y -1 si la lista está vacía. */
template <class T>
int ListaDobLiga<T>::InsertaAntes(T Dato, T Ref)
{
    NodoDobleLiga<T> * Apun1,*Apun2,*Apun3;
    int Resp= 1;
    if (Primero)
    {
        Apun1= Primero;
        while((Apun1 == NULL) && (Apun1->Info != Ref))
            Apun1= Apun1->LigaDer;
    
        /*Verifica si encontró la información dada como referencia. */
        if (Apun1 != NULL)
        {
            Apun3= new NodoDobleLiga<T>();
            Apun3->Info= Dato;
            Apun3->LigaDer= Apun1;
            Apun2= Apun1->LigaIzq;
            Apun1->LigaIzq= Apun3;
            Apun3->LigaIzq= Apun2;
            if (Primero == Apun1)
                Primero= Apun3;
            else
                Apun2->LigaDer= Apun3;
        }
        else
            Resp= 0;
    }
    else
        Resp= -1;
        
    return Resp;
}

/* Método que elimina el primer elemento de la lista doblemente ligada. 
Regresa 1 si la lista tiene al menos un elemento y 0 en caso contrario. */
template <class T> 
int ListaDobLiga<T>::EliminaPrimero()
{
    NodoDobleLiga<T> * Apunt; int Resp= 1;
    /* Verifica si la lista tiene al menos un elemento.*/
    if (Primero)
    {
        Apunt= Primero;
        if (Apunt->LigaDer)
        {
            Primero= Apunt->LigaDer;
            Primero->LigaIzq= NULL;
        }
        else
        {
            /* La lista tiene sólo un elemento, por lo tanto luego de la 
            eliminación queda vacia. */
            Primero= NULL;
            Ultimo= NULL;
        }
        delete(Apunt);
    }
    else
        Resp= 0;
        
    return Resp;

}

/* Método que elimina el último elemento de la lista doblemente ligada. 
Regresa 1 si la lista tiene al menos un elemento y 0 en caso contrario. */
template <class T>
int ListaDobLiga<T>::EliminaUltimo()
{
    NodoDobleLiga<T> * Apunt; int Resp= 1;
    /* Verifica si la lista tiene al menos un elemento.*/
    if (Ultimo)
    {
        Apunt= Ultimo;
        if (Apunt->LigaIzq)
        {
            Ultimo= Apunt->LigaIzq;
            Ultimo->LigaDer= NULL;
        }
        else
        {
            /* La lista tiene sólo un elemento, por lo tanto luego de la 
            eliminación queda vacia. */
            Primero= NULL;
            Ultimo= NULL;
        }
        delete(Apunt);
    }
    else
        Resp= 0;
    
    return Resp;
}

/* Método que elimina un nodo cuya información es igual a Dato. Regresa 
1 si la eliminación se puede llevar a cabo, 0 si el elemento no está en 
la lista y -1 si la lista está vacia. */
template <class T>
int ListaDobLiga<T>::EliminaUnNodo(T Dato)
{
    NodoDobleLiga<T> * Apun1,*Apun2,*Apun3;
    int Resp= 1;
    /* Verifica si la lista tiene al menos un elemento.*/
    if (Primero)
    {
        Apun1= Primero;
        while ((Apun1!= NULL) && (Apun1->Info != Dato))
            Apun1= Apun1->LigaDer;
            
        if (Apun1 == NULL)
            Resp= 0;
        else
        {
            /* Verifica si hay sólo un elemento en la lista. Si es asi, 
            entonces la lista quedará vacia luego de la eliminación. */
            if (Primero == Ultimo)
            {
                Primero= NULL;
                Ultimo= NULL;
            }
            else
                /* Verifica si el elemento a eliminar es el primero de 
                la lista. */
                if (Apun1 == Primero)
                {
                    Primero= Apun1->LigaDer;
                    Primero->LigaIzq= NULL;
                }
                else
                    /* Verifica si el elemento a eliminar es el último 
                    de la lista. */
                    if (Apun1 == Ultimo)
                    {
                        Ultimo= Apun1->LigaIzq;
                        Ultimo->LigaDer= NULL;
                    }
                    else
                    {
                        Apun2= Apun1->LigaIzq;
                        Apun3= Apun1->LigaDer;
                        Apun2->LigaDer= Apun3;
                        Apun3->LigaIzq= Apun2;
                    }
            delete(Apun1);
        }
    }
    else
        Resp= -1;
        
    return Resp;

}

/* Método que elimina el nodo anterior al nodo que contiene la información 
Dato. Regresa 1 si la eliminación se puede llevar a cabo, 0 si el valor dado 
como referencia no está en la lista, -1 si la referencia es el primer nodo y 
por lo tanto no hay anterior, y -2 si la lista mstá vacia. */
template <class T>
int ListaDobLiga<T>::EliminaAnterior(T Dato)
{
    NodoDobleLiga<T> * Apun1, *Apun2, *Apun3;
    int Resp= 1;
    if (Primero)
    {
        Apun1= Primero;
        while ((Apun1 != NULL) && (Apun1->Info != Dato))
            Apun1= Apun1->LigaDer;
            
        if (Apun1 == NULL)
            Resp= 0;
        else
        {
            /* Verifica si la información dada como referencia está en el 
            primer nodo. */
            if (Primero == Apun1)
                Resp= -1;
            else {
                if (Primero == Apun1->LigaIzq)
                {
                    Apun2= Primero;
                    Primero= Apun1;
                    Primero->LigaIzq= NULL;
                }
                else
                {
                    Apun2= Apun1->LigaIzq;
                    Apun3= Apun2->LigaIzq;
                    Apun3->LigaDer= Apun1;
                    Apun1->LigaIzq= Apun3;
                }
                delete(Apun2);
            }
        }
        
    }
    else
        Resp= -2;
    
    return Resp;
}

/* Método que busca en la lista un nodo dado como referencia. El método 
recibe como parámetro el elemento a buscar {Dato) y una variable (Apunt) 
que almacena la dirección de un nodo. La primera vez es la dirección del 
primero. Regresa como resultado la dirección del nodo o NULL si no lo 
encuentra. */
template <class T>
NodoDobleLiga<T> * ListaDobLiga<T>::Busca(T Dato, NodoDobleLiga<T> *Apunt)
{
    if (Apunt)
        if (Apunt->Info = Dato)
            return Apunt;
        else
            return Busca (Dato, Apunt->LigaDer);
    else
        return NULL;

}

/* Método que regresa el valor del apuntador al primer elemento de la 
lista. */
template <class T>
NodoDobleLiga<T> * ListaDobLiga<T>::RegresaPrimero() 
{
    return Primero;
}

/* Método que regresa el valor del apuntador al último elemento de la 
lista. */
template <class T>
NodoDobleLiga<T> * ListaDobLiga<T>::RegresaUltimo()
{
    return Ultimo;
}

/* Método que, dada la dirección de un nodo, regresa la dirección del 
siguiente nodo a la derecha. Este método facilita el desplazamiento a 
través de la lista por parte de usuarios externos a la misma. */
template <class T>
NodoDobleLiga<T> * ListaDobLiga<T>::RegresaVecinoDer(NodoDobleLiga<T> *Apunt)
{
    return Apunt->LigaDer;
}

/* Método que, dada la dirección de un nodo, regresa la dirección del 
siguiente nodo a la izquierda. Este método facilita el desplazamiento a 
través de la lista por parte de usuarios externos a la misma. */
template <class T>
NodoDobleLiga<T> * ListaDobLiga<T>::RegresaVecinoIzq(NodoDobleLiga<T> *Apunt)
{
    return Apunt->LigaIzq;
}

#endif