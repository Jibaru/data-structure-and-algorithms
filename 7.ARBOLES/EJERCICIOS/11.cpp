/*
11.	Considere que no puede manejar memoria dinámica para representar 
una estructura tipo árbol binario. Sin embargo, dadas las características 
de la información, usted decide que la mejor estructura para su almacenamiento 
y posterior uso es un árbol. Utilice un arreglo unidimensional, guardando 
en cada casilla la información correspondiente a un nodo, de tal manera 
que se mantengan las relaciones (padre-de y/o hijo-de) entre ellos. 
Diseñe e implemente las operaciones de búsqueda, inserción y eliminación 
que se ajuste a esta nueva representación.
*/
#include <iostream>

#define MAX 60
#define NULO -1

enum Lugar { derecha, izquierda, cualquiera };

template <class T>
class ArbolBinario;

template <class T>
class NodoArbolBinario
{
private:
    T info;
    int nodoHijoDer;
    int nodoHijoIzq;
    int nodoPadre;
    int indice;
public:
    NodoArbolBinario();
    T regresaInfo();
    friend class ArbolBinario<T>;
};

template <class T>
NodoArbolBinario<T>::NodoArbolBinario()
{
    nodoHijoDer = NULO;
    nodoHijoIzq = NULO;
    nodoPadre = NULO;
    indice = NULO;
}

template <class T>
T NodoArbolBinario<T>::regresaInfo()
{
    return info;
}

template <class T>
class ArbolBinario
{
private:
    int nodoRaiz;
    NodoArbolBinario<T> elementos[MAX];
    int tam;
    void acomodarDesde(int);
public:
    ArbolBinario();
    NodoArbolBinario<T> regresaNodoRaiz();
    int insertar(T, Lugar, T padre = 0);
    int busqueda(T);
    NodoArbolBinario<T> busquedaNodo(T);
    int eliminar(T);
    void imprimir(NodoArbolBinario<T> nodo = 0);
    void imprimirLista();

};

template <class T>
ArbolBinario<T>::ArbolBinario()
{
    nodoRaiz = NULO;
    tam = 0;
}

template <class T>
NodoArbolBinario<T> ArbolBinario<T>::regresaNodoRaiz()
{
    if(nodoRaiz >= 0) {
        return elementos[nodoRaiz];
    }
    return NodoArbolBinario<T>();
}

template <class T>
void ArbolBinario<T>::acomodarDesde(int indice)
{
    tam--;
    for(int i = indice; i < tam; i++) {
        NodoArbolBinario<T> nodo = elementos[i+1];
        nodo.indice = nodo.indice - 1;
        elementos[i] = nodo;
    }
}


/* Método que insertar un nuevo nodo en el árbol
Recibe como parámetros el dato y el padre.
Si no se da como parámetro al padre y el arbol está vacio,
se inserta en la raiz
Devuelve:
-1: Arbol vacío
 0: No se encontró el padre
 1: Se insertó
*/
template <class T>
int ArbolBinario<T>::insertar(T dato, Lugar lugar, T padre)
{
    int resp = 1;
    if(tam != 0) {
        if(!!padre) {
            int indicePadre = busqueda(padre);

            if(indicePadre >= 0) {
                // Existe padre
                NodoArbolBinario<T> nuevoNodo = NodoArbolBinario<T>();
                nuevoNodo.info = dato;
                nuevoNodo.nodoPadre = indicePadre;
                nuevoNodo.indice = tam;
                
                if(lugar == derecha) {
                    nuevoNodo.nodoHijoDer = elementos[indicePadre].nodoHijoDer;
                    NodoArbolBinario<T> padre = elementos[indicePadre];
                    padre.nodoHijoDer = nuevoNodo.indice;
                    elementos[indicePadre] = padre;
                } else if(lugar == izquierda) {
                    nuevoNodo.nodoHijoIzq = elementos[indicePadre].nodoHijoIzq;
                    NodoArbolBinario<T> padre = elementos[indicePadre];
                    padre.nodoHijoIzq = nuevoNodo.indice;
                    elementos[indicePadre] = padre;
                }

                elementos[tam] = nuevoNodo;
                tam++;
            }

        } else{
            // no hay padre
            resp = 0;
        }
    } else {
        if(!padre) {
            // Se ingresa en la raiz
            NodoArbolBinario<T> nuevoNodo = NodoArbolBinario<T>();
            nuevoNodo.info = dato;
            nuevoNodo.indice = tam;
            elementos[tam] = nuevoNodo;
            nodoRaiz = tam;
            tam++;
        } else{
            resp = -1;
        }
    }
    return resp;
}

/* Método que devuelve el índice al dato buscado */
template <class T>
int ArbolBinario<T>::busqueda(T dato)
{
    int resp = -1;
    for(int i = 0; resp == -1 && i < tam; i++) {
        if(elementos[i].info == dato) {
            resp = i;
        }
    }

    return resp;
}

/* Método que devuelve el Nodo al dato buscado */
template <class T>
NodoArbolBinario<T> ArbolBinario<T>::busquedaNodo(T dato)
{
    int resp = -1;
    NodoArbolBinario<T> nodo = NodoArbolBinario<T>();
    for(int i = 0; resp == -1 && i < tam; i++) {
        if(elementos[i].info == dato) {
            resp = i;
        }
    }

    if(resp >= 0) {
        nodo = elementos[resp];
    }

    return nodo;
}

/* Método que elimina un nodo */
template <class T>
int ArbolBinario<T>::eliminar(T dato)
{
    int resp = 1;
    
    if(tam > 0) {
        int indiceDato = busqueda(dato);

        if(indiceDato > NULO) {
            // Existe el nodo
            if(indiceDato == nodoRaiz){
                // Si el nodo es la raiz
                acomodarDesde(indiceDato);
            } else {
                NodoArbolBinario<T> nodoEliminar = elementos[indiceDato];
                if(nodoEliminar.nodoHijoDer != NULO && nodoEliminar.nodoHijoIzq != NULO) {
                    // Se elije el de la izquierda por convenció mía :v
                    NodoArbolBinario<T> nodoPadre = elementos[nodoEliminar.nodoPadre];
                    if(nodoPadre.nodoHijoDer == indiceDato) {
                        // El nodo a eliminar está en la derecha del padre
                        nodoPadre.nodoHijoDer = nodoEliminar.nodoHijoIzq;

                    } else if(nodoPadre.nodoHijoIzq == indiceDato) {
                        // El nodo a eliminar está en la izquierda del padre
                        nodoPadre.nodoHijoIzq = nodoEliminar.nodoHijoIzq;
                    }
                    NodoArbolBinario<T> nodoAscendente = elementos[nodoEliminar.nodoHijoIzq];
                    nodoAscendente.nodoPadre = nodoPadre.indice;

                    // Sobreescribiendo el arreglo:
                    elementos[nodoAscendente.indice] = nodoAscendente;
                    elementos[nodoPadre.indice] = nodoPadre;

                } else {
                    NodoArbolBinario<T> nodoPadre = elementos[nodoEliminar.nodoPadre];
                    if(nodoPadre.nodoHijoDer == indiceDato) {
                        // El nodo a eliminar está en la derecha del padre
                        if(nodoEliminar.nodoHijoIzq != NULO) {
                            // si existe el nodo izquierdo del nodo a eliminar
                            nodoPadre.nodoHijoDer = nodoEliminar.nodoHijoIzq;
                        } else if(nodoEliminar.nodoHijoDer != NULO){
                            // si existe el nodo derecho del nodo a eliminar
                            nodoPadre.nodoHijoDer = nodoEliminar.nodoHijoDer;
                        } else {
                            // Si no existe ningún nodo
                            nodoPadre.nodoHijoDer = -1;
                        }
                        NodoArbolBinario<T> nodoAscendente = elementos[nodoPadre.nodoHijoDer];
                        nodoAscendente.nodoPadre = nodoPadre.indice;

                        // Sobreescribiendo el arreglo:
                        elementos[nodoAscendente.indice] = nodoAscendente;
                        elementos[nodoPadre.indice] = nodoPadre;

                    } else if(nodoPadre.nodoHijoIzq == indiceDato) {
                        // El nodo a eliminar está en la izquierda del padre
                        if(nodoEliminar.nodoHijoIzq != NULO) {
                            // si existe el nodo izquierdo del nodo a eliminar
                            nodoPadre.nodoHijoIzq = nodoEliminar.nodoHijoIzq;
                        } else if(nodoEliminar.nodoHijoDer != NULO){
                            // si existe el nodo derecho del nodo a eliminar
                            nodoPadre.nodoHijoIzq = nodoEliminar.nodoHijoDer;
                        } else {
                            // Si no existe ningún nodo
                            nodoPadre.nodoHijoDer = -1;
                        }
                        NodoArbolBinario<T> nodoAscendente = elementos[nodoPadre.nodoHijoIzq];
                        nodoAscendente.nodoPadre = nodoPadre.indice;

                        // Sobreescribiendo el arreglo:
                        elementos[nodoAscendente.indice] = nodoAscendente;
                        elementos[nodoPadre.indice] = nodoPadre;

                    }
                }
                acomodarDesde(indiceDato);
            }

        } else {
            // No existe
            resp = 0;
        }
    } else {
        // Arbol vacio
        resp = -1;
    }
    return resp;
}

/* Método que imprime el árbol */
template <class T>
void ArbolBinario<T>::imprimir(NodoArbolBinario<T> nodo)
{

    if (nodo.indice > NULO)
    {
        std::cout << nodo.info << std::endl;

        if(nodo.nodoHijoIzq > NULO) {
            imprimir(elementos[nodo.nodoHijoIzq]);
        }
        if(nodo.nodoHijoDer > NULO) {
            imprimir(elementos[nodo.nodoHijoDer]);
        }
    }
    
}

template <class T>
void ArbolBinario<T>::imprimirLista()
{
    for(int i = 0; i < tam; i++) {
        std::cout << "\nElemento " << i << ": " << std::endl;
        std::cout << "Info: " << elementos[i].info << std::endl;
        std::cout << "Indice: " << elementos[i].indice << std::endl;
        std::cout << "Indice der: " << elementos[i].nodoHijoDer << std::endl;
        std::cout << "Indice izq: " << elementos[i].nodoHijoIzq << std::endl;
    }
    
}

void testEjercicio11()
{
    ArbolBinario<int> arbol = ArbolBinario<int>();

    arbol.insertar(7, cualquiera);
    arbol.insertar(10, derecha, 7);
    arbol.insertar(19, izquierda, 7);
    arbol.insertar(2, derecha, 19);
    arbol.insertar(6, izquierda, 10);
    arbol.insertar(14, derecha, 2);

    std::cout << "Existe  7: " << ((arbol.busqueda(7) >= 0) ? "SI" : "NO") << std::endl;
    std::cout << "Existe 10: " << ((arbol.busqueda(10) >= 0) ? "SI" : "NO") << std::endl;
    std::cout << "Existe  5: " << ((arbol.busqueda(5) >= 0) ? "SI" : "NO") << std::endl;
    std::cout << "Existe  14: " << ((arbol.busqueda(14) >= 0) ? "SI" : "NO") << std::endl;
    
    std::cout << "Preorden: " << std::endl;
    arbol.imprimir(arbol.regresaNodoRaiz());
    std::cout << "Lista: " << std::endl;
    arbol.imprimirLista();

    std::cout << "\nBorra 2: " << arbol.eliminar(2) << std::endl;
    std::cout << "Borra 12: " << arbol.eliminar(12) << std::endl;
    std::cout << "Borra 6: " << arbol.eliminar(6) << std::endl;

    std::cout << "\nPreorden: " << std::endl;
    arbol.imprimir(arbol.regresaNodoRaiz());
    std::cout << "Lista: " << std::endl;
    arbol.imprimirLista();
}

int main()
{
    testEjercicio11();
    return 0;
}