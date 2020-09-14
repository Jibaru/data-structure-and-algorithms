#include <iostream>
using namespace std;

/* Prototipo de la plantilla de la clase ArbolBalanceado. De esta 
manera, en la clase NodoArbolBal se podrá hacer referencia a ella. */
template <class T>
class ArbolBalanceado;

/* Declaración de la clase de un nodo de un árbol balanceado. Además de 
almacenar la información, las direcciones de los hijos izquierdo y 
derecho, guarda el factor de equilibrio. */
template <class T>
class NodoArbolBal {
private:
    NodoArbolBal<T> *HijoIzq;
    NodoArbolBal<T> *HijoDer;
    T Info;
    int FE;
public:
    NodoArbolBal();
    T RegresaInfo();
    void ActualizaInfo(T);
    friend class ArbolBalanceado<T>;
};

/* Declaración del método constructor. Inicializa los apuntadores a 
ambos hijos con el valor de NULL, indicando vacio. */
template <class T>
NodoArbolBal<T>::NodoArbolBal()
{
    HijoIzq= NULL;
    HijoDer= NULL;
}

/* Método que regresa la información almacenada en el nodo. */
template <class T>
T NodoArbolBal<T>::RegresaInfo()
{
    return Info;
}

/* Método que permite actualizar la información almacenada en el nodo. */
template <class T>
void NodoArbolBal<T>::ActualizaInfo(T Dato)
{
    Info= Dato;
}

/* Declaración de la clase ArbolBalanceado. Se incluyen sólo los proto
tipos de los métodos presentados más arriba. */
template <class T>
class ArbolBalanceado
{
private:
    NodoArbolBal<T> *Raiz;
public:
    ArbolBalanceado ();
    NodoArbolBal<T> * RegresaRaiz();
    NodoArbolBal<T> * Busca (NodoArbolBal<T> *, T) ;
    void InsertaBalanceado (T, NodoArbolBal<T> *, int *);
    NodoArbolBal<T> * RotacionHI_HD (NodoArbolBal<T> *, NodoArbolBal<T> *);
    NodoArbolBal<T> * RotacionHD_HI (NodoArbolBal<T> *, NodoArbolBal<T> *);
    NodoArbolBal<T> * RotacionHI_HI (NodoArbolBal<T> *, NodoArbolBal<T> *);
    NodoArbolBal<T> * RotacionHD_HD (NodoArbolBal<T> *, NodoArbolBal<T> *);
    NodoArbolBal<T> * RestructuraI (NodoArbolBal<T> *, int *);
    NodoArbolBal<T> * RestructuraD (NodoArbolBal<T> *, int *);
    void EliminaBalanceado (NodoArbolBal<T> *, NodoArbolBal<T> *, int *, T);
    void Sustituye (NodoArbolBal<T> *, NodoArbolBal<T> *, int *);
    void Imprime (NodoArbolBal<T> *);
};

/* Declaración del método constructor. Inicializa el puntero a la raiz 
con el valor NULL, indicando que el árbol está vacio. */
template <class T>
ArbolBalanceado<T>::ArbolBalanceado()
{
    Raiz= NULL;
}

/* Método que regresa el apuntador a la raíz del árbol.*/
template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RegresaRaiz()
{
    return Raiz;
}

/* Método que busca un valor dado como parámetro en el árbol. Recibe 
como parámetros el puntero del nodo a visitar (la primera vez es la 
raíz) y el dato a buscar. Regresa el puntero al nodo donde lo encontró 
o NULL si no está en el árbol. */
template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::Busca (NodoArbolBal<T> *Apunt, T Dato)
{
    if (Apunt != NULL)
        if (Apunt->Info = Dato)
            return Apunt;
        else
            if (Apunt->Info > Dato)
                return Busca(Apunt->HijoIzq, Dato);
            else
                return Busca(Apunt->HijoDer, Dato);
    else
        return NULL;
}

/* Método que imprime el contenido del árbol. Recibe como parámetro el 
apuntador al nodo a visitar (la primera vez es la raiz del árbol). 
Utiliza recorrido inorden para que el contenido se imprima en orden 
creciente. */
template <class T>
void ArbolBalanceado<T>::Imprime(NodoArbolBal<T> *Apunt)
{
    if (Apunt != NULL)
    {
        Imprime(Apunt->HijoIzq);
        cout << Apunt->Info << "\n\n";
        Imprime(Apunt->HijoDer);
    }
}

/* Método que realiza la rotación simple HI-HI en un árbol balanceado. 
Además, reasigna el FE del nodo involucrado en la rotación. */
template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RotacionHI_HI(NodoArbolBal<T> *Apunt, NodoArbolBal<T> *ApAux1)
{
    Apunt->HijoIzq= ApAux1->HijoDer;
    ApAux1->HijoDer= Apunt;
    Apunt->FE= 0;
    
    return ApAux1;
}

/* Método que realiza la rotación simple HD-HD en un árbol balanceado. 
Además, reasigna el FE del nodo involucrado en la rotación. */
template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RotacionHD_HD(NodoArbolBal<T> *Apunt, NodoArbolBal<T> *ApAux1)
{
    Apunt->HijoDer= ApAux1->HijoIzq;
    ApAux1->HijoIzq= Apunt;
    Apunt->FE= 0;

    return ApAux1;
}

/* Método que realiza la rotación compuesta HI-HD en un árbol balanceado. 
Además, reasigna los FE de los nodos involucrados en la rotación. */
template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RotacionHI_HD(NodoArbolBal<T> *Apunt, NodoArbolBal<T> *ApAux1)
{
    NodoArbolBal<T> *ApAux2;
    ApAux2= ApAux1->HijoDer;
    Apunt->HijoIzq= ApAux2->HijoDer;
    ApAux2->HijoDer= Apunt;
    ApAux1->HijoDer= ApAux2->HijoIzq;
    ApAux2->HijoIzq= ApAuxl;
    if (ApAux2->FE == -1)
        Apunt->FE= 1;
    else
        Apunt->FE= 0;
    if (ApAux2->FE == 1)
        ApAux1->FE= -1;
    else
        ApAux1->FE= 0;
    
    return ApAux2;
}

/* Método que realiza la rotación compuesta HD-HI en un árbol balanceado. ^Además, reasigna los FE de los nodos involucrados en la rotación. */
template <class T>
NodoArbolBal<T> * ArbolBalanceado<T>::RotacionHD_HI(NodoArbolBal<T> *Apunt, NodoArbolBal<T> *ApAux1)
{
    NodoArbolBal<T> *ApAux2;
    ApAux2= ApAux1->HijoIzq;
    Apunt->HijoDer= ApAux2->HijoIzq;
    ApAux2->HijoIzq= Apunt;
    ApAux1->HijoIzq= ApAux2->HijoDer;
    ApAux2->HijoDer= ApAux1;
    if (ApAux2->FE == 1)
        Apunt->FE= -1;
    else
        Apunt->FE= 0;
    
    if (ApAux2->FE == -1)
        ApAux1->FE= 1;
    else
        ApAux1->FE= 0;
    
    return ApAux2;
}

/* Método que inserta un nuevo elemento en un árbol balanceado. Recibe 
como parámetros el dato a insertar, un puntero al nodo a visitar (la 
primera vez es la raiz) y un entero (Band) que la primera vez trae el 
valor 0.*/ 
template <class T>
void ArbolBalanceado<T>::InsertaBalanceado(T Dato, NodoArbolBal<T> *Apunt, int *Band)
{
    NodoArbolBal<T> *ApAux1, *ApAux2;
    if (Apunt != NULL)
    {
        if (Dato < Apunt->Info)
        {
            /* Se invoca el método con el subárbol izquierdo. */
            InsertaBalanceado(Dato, Apunt->HijoIzq, Band);
            Apunt->HijoIzq= Raiz;
            if (0 < *Band)
                /* Verifica si creció el subárbol 
                izquierdo. */
                switch (Apunt->FE)
                {
                    case 1: {
                        Apunt->FE = 0;
                        *Band= 0;
                        break;
                    }
                    case 0: {
                        Apunt->FE = -1;
                        break;
                    }
                    case -1: {
                        ApAux1 = Apunt->HijoIzq;
                        if (ApAux1->FE <= 0)
                            Apunt= RotacionHI_HI(Apunt, ApAux1);
                        else
                            Apunt= RotacionHI_HD(Apunt, ApAux1);
                        Apunt->FE = 0;
                        *Band = 0;
                    }
                }   
        }
        else
            if (Dato > Apunt->Info)
            {
                /* Invoca el método con el subárbol derecho. */
                InsertaBalanceado(Dato, Apunt->HijoDer, Band);
                Apunt->HijoDer= Raiz;
                if (0 < *Band)	/* Verifica si creció el subárbol derecho. */
                    switch ( Apunt->FE )
                    {
                        case -1: {
                            Apunt->FE = 0;
                            *Band= 0;
                            break;
                        } 
                        case 0: {
                            Apunt->FE = 1;
                            break;
                        }
                        case 1: {
                            ApAux1= Apunt->HijoDer;
                            if (ApAux1->FE >= 0)
                                Apunt= RotacionHD_HD(Apunt, *ApAux1) ;
                            else
                                Apunt= RotacionHD_HI(Apunt, *ApAux1);
                            Apunt->FE = 0;
                            *Band= 0;
                        }
                    }
            }
            Raiz= Apunt;
    }
    else
    {
        /* Inserta un nuevo nodo y actualiza el valor de Band indicando 
        que el árbol creció. */
        ApAux2= new NodoArbolBal<T>();
        ApAux2->Info= Dato;
        ApAux2->FE= 0;
        *Band = 1;
        Raiz= ApAux2;
    }
}

/* Método auxiliar del método EliminaBalance ado que reestructura el 
árbol cuando la altura de la rama izquierda ha disminuido. */
template <class T>
NodoArbolBal<T>* ArbolBalanceado<T>::RestructuraI(NodoArbolBal<T> *Nodo, int *Aviso)
{
    NodoArbolBal<T> *ApAux;
    if (*Aviso > 0)
    {
        switch (Nodo->FE)
        {
            case -1: {
                Nodo->FE= 0;
                break;
            }
            case 0: { 
                Nodo->FE= 1;
                *Aviso= 0;
                break;
            }
            case 1: {
                ApAux= Nodo->HijoDer;
                if (ApAux->FE >= 0) //Rotación HD-HD
                {
                    Nodo->HijoDer= ApAux->HijoIzq;
                    ApAux->HijoIzq= Nodo;
                    switch (ApAux->FE)
                    {
                    case 0: 
                        Nodo->FE= 1;
                        ApAux->FE= -1;
                        *Aviso= 0;
                        break;
                    case 1:
                        Nodo->FE= 0;
                        ApAux->FE= 0;
                        break;
                    }
                    Nodo= ApAux;
                }
                else //Rotación HD-HI
                {
                    Nodo= RotacionHD_HI(Nodo, ApAux);
                    Nodo->FE= 0;
                }
                break;
            }
        }
    }
    return Nodo;
}

/* Método auxiliar del método EliminaBalance ado que reestructura el 
árbol cuando la altura de la rama derecha ha disminuido. */
template <class T>
NodoArbolBal<T>* ArbolBalanceado<T>::RestructuraD(NodoArbolBal<T> *Nodo, int *Aviso)
{
    NodoArbolBal<T> *ApAux;
    if (*Aviso > 0)
    {
        switch (Nodo->FE)
        {
            case 1:
                Nodo->FE= 0;
                break;
            case 0:
                Nodo->FE= -1;
                *Aviso= 0;
                break;
            case -1:
                ApAux= Nodo->HijoIzq;
                if (ApAux->FE <= 0) //Rotación HI-HI
                {
                    Nodo->HijoIzq= ApAux->HijoDer;
                    ApAux->HijoDer= Nodo;
                    switch (ApAux->FE)
                    {
                        case 0:
                            Nodo->FE= -1;
                            ApAux->FE= 1;
                            *Aviso= 0;
                            break;
                        case -1:
                            Nodo->FE= 0;
                            ApAux->FE= 0;
                            break;
                    }
                    Nodo= ApAux;
                }
                else //Rotación HI-HD
                {
                    Nodo= RotacionHI_HD(Nodo, ApAux);
                    Nodo->FE= 0;
                }
                break;
        }
    }

    return Nodo;
}

/* Método auxiliar del método EliminaBalanceado que sustituye el 
elemento que se desea eliminar por el que se encuentra más a la derecha 
del subárbol izquierdo. */
template <class T>
void ArbolBalanceado<T>::Sustituye(NodoArbolBal<T> *Nodo, NodoArbolBal<T> *ApAux, int *Avisa)
{
    if (Nodo->HijoDer != NULL)
    {
        Sustituye(Nodo->HijoDer, ApAux, Avisa);
        if (ApAux->HijoIzq == NULL)
            Nodo->HijoDer= NULL;
        else
            Nodo->HijoDer= ApAux->HijoIzq;
        Nodo= RestructuraD(Nodo, Avisa);
    }
    else
    {
        ApAux->Info= Nodo->Info;
        Nodo= Nodo->HijoIzq;
        *Avisa= 1;
    }
    ApAux->HijoIzq= Nodo;
}

/* Método que elimina un elemento en un árbol balanceado. Luego de la 
eliminación se actualizan los factores de equilibrio de cada nodo hasta 
la raiz y se reestructura el árbol si fuera necesario. */
template <class T>
void ArbolBalanceado<T>::EliminaBalanceado(NodoArbolBal<T> *Apunt, NodoArbolBal<T> *ApAnt, int *Avisa, T Dato)
{
    NodoArbolBal<T> *ApAux;
    int Bandera;
    if (Apunt != NULL)
        if (Dato < Apunt->Info)
        { 
            if (*Avisa > 0)
                Bandera= 1;
            else
                if (*Avisa != 0)
                    Bandera= -1;
            *Avisa= -1;
            EliminaBalanceado(Apunt->HijoIzq, Apunt, Avisa, Dato);
            Apunt= RestructuraI(Apunt, Avisa);
            if (ApAnt != NULL)
                switch (Bandera)
                {
                    case -1:
                        ApAnt->HijoIzq= Apunt;
                        break;
                    case 1:
                        ApAnt->HijoDer= Apunt;
                        break;
                    default:
                        break;
                }
            else
                Raiz= Apunt;
        }
        else
            if (Dato > Apunt->Info)
            {
                if (*Avisa < 0)
                    Bandera= -1;
                else
                    if (*Avisa != 0)
                        Bandera=1;
                *Avisa= 1;
                EliminaBalanceado(Apunt->HijoDer, Apunt, Avisa, Dato);
                Apunt= RestructuraD(Apunt, Avisa);
                if (ApAnt != NULL)
                    switch (Bandera)
                    {
                        case -1:
                            ApAnt->HijoIzq= Apunt;
                            break;
                        case 1:
                            ApAnt->HijoDer= Apunt;
                            break;
                        default:
                            break;
                    }
                else
                    Raiz= Apunt;
            }
            else
            {
                ApAux= Apunt;
                if (ApAux->HijoDer == NULL)
                {
                    Apunt= ApAux->HijoIzq;
                        if (*Avisa != 0)
                            if (*Avisa < 0)
                                ApAnt->HijoIzq= Apunt;
                            else
                                ApAnt->HijoDer= Apunt;
                        else
                            if (Apunt == NULL)
                                Raiz= NULL;
                            else
                                Raiz= Apunt;
                        *Avisa= 1;
                }
                else
                    if (ApAux->HijoIzq == NULL)
                    {
                        Apunt= ApAux->HijoDer;
                        if (*Avisa != 0)
                            if (*Avisa < 0)
                                ApAnt->HijoIzq= Apunt;
                            else
                                ApAnt->HijoDer= Apunt;
                        else
                            if (Apunt == NULL)
                                Raiz= NULL;
                            else
                                Raiz= Apunt;
                        *Avisa= 1;
                    }
                    else
                    {
                        Sustituye(ApAux->HijoIzq, ApAux, Avisa);
                        Apunt= RestructuraI(Apunt, Avisa);
                        if (ApAnt != NULL)
                            if (*Avisa <= 0)
                                ApAnt->HijoIzq= Apunt;
                            else
                                ApAnt->HijoDer= Apunt;
                        else
                            Raiz= Apunt;
                    }
            }
    else
        cout << "\n\nEl dato a eliminar no se encuentra registrado.\n\n";

}