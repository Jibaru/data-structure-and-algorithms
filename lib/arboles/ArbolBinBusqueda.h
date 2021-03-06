#ifndef _ARBOL_BIN_BUSQUEDA_
#define _ARBOL_BIN_BUSQUEDA_

#include <iostream>

/* Prototipo de la plantilla de la clase ArbolBinBus. Asi, en la clase 
NodoArbol se podrá hacer referencia a ella. */
template <class T>
class ArbolBinBus;

/* Declaración de la clase NodoArbol. Cada nodo almacena la información 
(razón de ser de la estructura tipo árbol) y las direcciones de sus hijos 
izquierdo y derecho. Se incluye una relación de amistad con la clase 
ArbolBinBus para que éste pueda tener acceso a sus miembros privados. */ 
template <class T>
class NodoArbol {
private:
    T Info;
    NodoArbol<T> *HijoIzq;
    NodoArbol<T> *HijoDer;
public:
    NodoArbol();
    T RegresaInfo();
    void ActualizaInfo(T);
    friend class ArbolBinBus<T>;
};

/* Declaración del método constructor por omisión. Inicializa las ligas a 
los subárboles con el valor NULL, indicando que no tiene hijos. */
template <class T>
NodoArbol<T>::NodoArbol()
{
    HijoIzq= NULL;
    HijoDer= NULL;
}

/* Método que regresa la información almacenada en el nodo. */
template <class T>
T NodoArbol<T>::RegresaInfo()
{
    return Info;
}

/* Método para actualizar la información almacenada en el nodo. */
template <class T>
void NodoArbol<T>::ActualizaInfo(T Dato)
{
    Info= Dato ;
}

/* Declaración de la clase ArbolBinBus. Su atributo es un puntero al
*nodo raíz. */
template <class T>
class ArbolBinBus
{
private:
    NodoArbol<T> *Raiz; 
public:
    ArbolBinBus ();
    NodoArbol<T> *RegresaRaiz();
    void Preorden (NodoArbol<T> *);
    void Inorden (NodoArbol<T> *);
    void Postorden (NodoArbol<T> *);
    NodoArbol<T> * Busqueda (NodoArbol<T> *, T);
    void InsertaNodoSinRep (NodoArbol<T> *, T);
    void EliminaNodo (NodoArbol<T> *, T);
    int ContarNodosHoja(NodoArbol<T>*);
    int ContarNodosIntermedios(NodoArbol<T>*);
    int NumeroHojas();
    int NumeroNodosIntermedios();
    int Altura(NodoArbol<T>* nodo = NULL, int alturaAcum = 1);
    int NodoCompleto(NodoArbol<T>*);
    int EsCompleto();
    void ImprimeNivel(NodoArbol<T>* nodo, int nivel);
    void ImprimePorNiveles();
};

/* Declaración del método constructor. Inicializa el puntero a la raíz 
con el valor NULL, indicando árbol vacío (no tiene nodos). */
template <class T>
ArbolBinBus<T>::ArbolBinBus()
{
    Raiz= NULL;
}

/* Método que regresa el valor del apuntador a la raíz del árbol. */
template <class T>
NodoArbol<T> *ArbolBinBus<T>::RegresaRaiz()
{
    return Raiz;
}

/* Método que realiza el recorrido preorden de un árbol binario de bús
queda. Recibe como parámetro el nodo a visitar (la primera vez es la 
raíz). */
template <class T>
void ArbolBinBus<T>::Preorden (NodoArbol<T> *Apunt)
{
    if (Apunt)
    {
        std::cout << Apunt->Info << " ";
        Preorden(Apunt->HijoIzq);
        Preorden(Apunt->HijoDer);
    }
}

/* Método que realiza el recorrido inorden de un árbol binario de 
búsqueda. Recibe como parámetro el nodo a visitar (la primera vez es la 
raíz). */
template <class T>
void ArbolBinBus<T>::Inorden (NodoArbol<T> *Apunt)
{
    if (Apunt)
    {
        Inorden(Apunt->HijoIzq);
        std::cout << Apunt->Info << " ";
        Inorden(Apunt->HijoDer);
    }
}

/* Método que realiza el recorrido postorden de un árbol binario de 
búsqueda. Recibe como parámetro el nodo a visitar (la primera vez es la 
raíz). */
template <class T>
void ArbolBinBus<T>::Postorden (NodoArbol<T> *Apunt)
{
    if (Apunt)
    {
        Postorden(Apunt->HijoIzq);
        Postorden(Apunt->HijoDer);
        std::cout << Apunt->Info << " ";
    }
}

/* Método que busca un dato en un árbol binario de búsqueda. Recibe como 
parámetros un apuntador, que es la dirección del nodo a visitar (la 
primera vez es el apuntador a la raíz) y el dato a buscar. Regresa como 
resultado la dirección del nodo encontrado o el valor NULL, si la búsqueda 
termina con fracaso. */
template <class T>
NodoArbol<T> * ArbolBinBus<T>::Busqueda (NodoArbol<T> *Apunt, T Dato)
{
    if (Apunt)
        if (Dato < Apunt->Info)
            return Busqueda(Apunt->HijoIzq, Dato);
        else
            if (Dato > Apunt->Info)
                return Busqueda(Apunt->HijoDer, Dato);
            else
                return Apunt;
    else
        return NULL;
}

/* Método que inserta un nodo en un árbol binario de búsqueda. Recibe 
como parámetros un apuntador (la primera vez es la raíz del árbol) y 
la información que se quiere almacenar en el nuevo nodo. En esta 
implementación no se permite que haya información duplicada en el 
árbol. */
template <class T>
void ArbolBinBus<T>::InsertaNodoSinRep(NodoArbol<T> *Apunt, T Dato)
{
    NodoArbol<T> *ApAux;
    if (Apunt)
    {
        if (Dato < Apunt->Info)
        {
            InsertaNodoSinRep(Apunt->HijoIzq, Dato);
            Apunt->HijoIzq= Raiz;
        }
        else
            if (Dato > Apunt->Info)
            {
                InsertaNodoSinRep(Apunt->HijoDer, Dato);
                Apunt->HijoDer= Raiz;
            }
        Raiz= Apunt;
    }
    else
    {
        /* Se crea un nuevo nodo, se le asigna la información y se 
        establecen las ligas entre los nodos correspondientes. */
        ApAux= new NodoArbol<T>();
        ApAux->Info= Dato;
        Raiz= ApAux;
    }
}

/* Método que elimina un nodo de un árbol binario de búsqueda. Recibe 
como parámetro un apuntador (la primera vez es la raiz) y el dato a 
eliminar. */
template <class T>
void ArbolBinBus<T>::EliminaNodo(NodoArbol<T> *Apunt, T Dato)
{
    if (Apunt)
        if (Dato < Apunt->Info)
        {
            EliminaNodo(Apunt->HijoIzq, Dato);
            Apunt->HijoIzq= Raiz;
        }
        else
            if (Dato > Apunt->Info)
            {
                EliminaNodo(Apunt->HijoDer, Dato);
                Apunt->HijoDer= Raiz;
            }
            else
            {
                NodoArbol<T> *ApAux1,*ApAux2,*ApAux3;
                ApAux3= Apunt;
                /* Encuentra el nodo que contiene el dato a eliminar. 
                Verifica si tiene hijos. */
                if (!ApAux3->HijoDer)
                    if (!ApAux3->HijoIzq)
                        /* Si no tiene hijo derecho ni izquierdo, entonces 
                        se redefine como vacio. */
                        Apunt= NULL;
                    else
                        /* Si sólo tiene hijo izquierdo, el nodo 
                        eliminado se reemplaza con éste.*/
                        Apunt= ApAux3->HijoIzq;
                else
                    if (!ApAux3->HijoIzq)
                        /* Si sólo tiene hijo derecho, el nodo eliminado 
                        se reemplaza con éste. */
                        Apunt= ApAux3->HijoDer;
                    else
                    {    
                        /* Si tiene ambos hijos, entonces se reemplaza 
                        (en esta solución) por el nodo que está más a la 
                        derecha del subárbol izquierdo. */ 
                        ApAux1= ApAux3->HijoIzq;
                        ApAux2= ApAux3;
                        while (ApAux1->HijoDer)
                        {
                            ApAux2= ApAux1;
                            ApAux1= ApAux1->HijoDer;
                        }

                        ApAux3->Info= ApAux1->Info;
                        if (ApAux3 == ApAux2)
                            ApAux3->HijoIzq= NULL;
                        else
                            if (!ApAux1->HijoIzq)
                                ApAux2->HijoDer= NULL;
                            else
                                ApAux2->HijoDer= ApAux1->HijoIzq;
                        ApAux3= ApAux1;
                    }
                delete(ApAux3);
            }
            Raiz= Apunt;
}

/* Método que cuenta los nodos hoja a partir de un nodo */
template <class T>
int ArbolBinBus<T>::ContarNodosHoja(NodoArbol<T>* nodo)
{
    int sumDer = 0, sumIzq = 0;
    if(nodo->HijoDer == NULL && nodo->HijoIzq == NULL) {
        return 1;
    } else {
        if(nodo->HijoDer) {
            sumDer = ContarNodosHoja(nodo->HijoDer);
        }
        if(nodo->HijoIzq) {
            sumIzq = ContarNodosHoja(nodo->HijoIzq);
        }
    } 
    
    return  sumDer + sumIzq;
    
}


/* Método que cuenta los nodos intermedios a partir de un nodo */
template <class T>
int ArbolBinBus<T>::ContarNodosIntermedios(NodoArbol<T>* nodo)
{
    int sumDer = 0, sumIzq = 0, actual = 0;
    if(nodo->HijoDer == NULL && nodo->HijoIzq == NULL) {
        return 0;
    } else {
        if(nodo != Raiz) {
            actual = 1;
        }
        if(nodo->HijoDer) {
            sumDer = ContarNodosIntermedios(nodo->HijoDer);
        }
        if(nodo->HijoIzq) {
            sumIzq = ContarNodosIntermedios(nodo->HijoIzq);
        }
    } 
    
    return  sumDer + sumIzq + actual;
    
}

/* Método que devuelve el número de hojas del árbol
binario */
template <class T>
int ArbolBinBus<T>::NumeroHojas()
{
    return ContarNodosHoja(Raiz);
}

/* Método que devuelve el número de nodos intermedios del árbol
binario */
template <class T>
int ArbolBinBus<T>::NumeroNodosIntermedios()
{
    return ContarNodosIntermedios(Raiz);
}

/* Método que devuelve la altura de un árbol a partir de un nodo */
template <class T>
int ArbolBinBus<T>::Altura(NodoArbol<T>* nodo, int alturaAcum)
{
    int mayorAltura = 0, altDer = 0, altIzq = 0;
    if(nodo == NULL) {
        nodo = Raiz;
    }

    if(nodo->HijoDer == NULL && nodo->HijoIzq == NULL) {
        return alturaAcum;
    } else {
        if(nodo->HijoDer) {
            altDer = Altura(nodo->HijoDer, alturaAcum + 1);
        }
        if(nodo->HijoIzq) {
            altIzq = Altura(nodo->HijoIzq, alturaAcum + 1);
        }
        if(altDer > altIzq) {
            mayorAltura = altDer;
        } else {
            mayorAltura = altIzq;
        }
    }
    return mayorAltura;
}

/* Método que verifica si un nodo y sus subnodos (excepto las hojas) 
son completos */
template <class T>
int ArbolBinBus<T>::NodoCompleto(NodoArbol<T>* nodo)
{
    if(nodo->HijoDer == NULL && nodo->HijoIzq == NULL) {
        // es un nodo hoja
        return 1;
    } else if (nodo->HijoDer == NULL ||nodo->HijoIzq == NULL) {
        // no es completo
        return 0;
    } else if (nodo->HijoDer != NULL && nodo->HijoIzq != NULL) {
        // es completo
        int der = NodoCompleto(nodo->HijoDer);
        int izq = NodoCompleto(nodo->HijoIzq);

        if(der == 1 && izq == 1) {
            return 1;
        } else {
            return 0;
        }
    }
}

/* Método que verifica si una arbol binario es completo */
template <class T>
int ArbolBinBus<T>::EsCompleto()
{
    return NodoCompleto(Raiz);
}

/* Método que imprime por los nodos de un nivel del árbol */
template <class T>
void ArbolBinBus<T>::ImprimeNivel(NodoArbol<T>* nodo, int nivel)
{
    if (nodo == NULL) 
        return; 
    if (nivel == 1) 
        std::cout << nodo->Info << " ";
    else if (nivel > 1) 
    { 
        ImprimeNivel(nodo->HijoIzq, nivel-1); 
        ImprimeNivel(nodo->HijoDer, nivel-1); 
    } 

}

/* Método que imprime por niveles los nodos de un arbol */
template <class T>
void ArbolBinBus<T>::ImprimePorNiveles()
{
    int altura = Altura(); 
    int i;
    for (i = 1; i <= altura; i++) { 
        ImprimeNivel(Raiz, i);
    }
}

#endif /* _ARBOL_BIN_BUSQUEDA_ */