/*
1.	Defina una plantilla para la clase ArbolMultiple. Decida qué atributos 
y métodos incluir. ¿Puede implementar esta clase en C++? Justifique su respuesta.
*/
#include <iostream>
#define MAX 10

template <class T>
class ArbolMultiple;

/*
La clase NodoArbolMultiple posee N nodos 
*/
template <class T>
class NodoArbolMultiple 
{
private:
    NodoArbolMultiple<T>* nodos[MAX];
    NodoArbolMultiple<T>* nodoPadre;
    int cantidadNodos;
    T info;
public:
    NodoArbolMultiple();
    T regresaInfo();
    friend class ArbolMultiple<T>;
};

template <class T>
NodoArbolMultiple<T>::NodoArbolMultiple()
{
    cantidadNodos = 0;
    nodoPadre = NULL;
}

template <class T>
T NodoArbolMultiple<T>::regresaInfo()
{
    return info;
}

template <class T>
class ArbolMultiple
{
private:
    NodoArbolMultiple<T>* raiz;
public:
    ArbolMultiple();
    int insertarRaiz(T);
    int insertar(T, T);
    NodoArbolMultiple<T>* regresaRaiz();
    int eliminar(T);
    NodoArbolMultiple<T>* buscar(T, NodoArbolMultiple<T>*);
    void imprimir(NodoArbolMultiple<T>* ref= NULL);
};

template <class T>
ArbolMultiple<T>::ArbolMultiple()
{
    raiz = NULL;
}

/*
Crea la raiz del arbol
0: Si la raiz ya existe
1: Si la raiz no existe y se inserta el dato
*/
template <class T>
int ArbolMultiple<T>::insertarRaiz(T dato)
{
    int resp = 1;
    if(!raiz) {
        raiz = new NodoArbolMultiple<T>();
        raiz->info = dato;
    } else {
        resp = 0;
    }
    return resp;
}

template <class T>
int ArbolMultiple<T>::insertar(T dato, T padre)
{
    int resp = 1;
    NodoArbolMultiple<T>* nodoPadre, *nuevo;

    if(raiz) {
        nodoPadre = buscar(padre, raiz);

        if(nodoPadre) {
            nuevo = new NodoArbolMultiple<T>();
            nuevo->info = dato;
            nuevo->nodoPadre = nodoPadre;

            if(nodoPadre->cantidadNodos + 1 <= MAX) {
                nodoPadre->nodos[nodoPadre->cantidadNodos] = nuevo;
                nodoPadre->cantidadNodos += 1;
            } else {
                resp = -2;
            }
        } else {
            resp = 0;
        }

    } else {
        resp = -1;
    }

    return resp;
}

template <class T>
NodoArbolMultiple<T>* ArbolMultiple<T>::regresaRaiz()
{
    return raiz;
}

template <class T>
int ArbolMultiple<T>::eliminar(T dato)
{
    int resp = 1;
    NodoArbolMultiple<T>* buscado;
    if(raiz) {
        buscado = buscar(dato, raiz);
        if(buscado) {
            if(buscado == raiz) {
                if(buscado->cantidadNodos == 0) {
                    // Solo existe la raiz, se elimina
                    raiz = NULL;
                    delete buscado;
                } else if(buscado->cantidadNodos == 1) {
                    // Existe la raiz con un unico nodo hijo
                    raiz = raiz->nodos[0];
                    delete buscado;
                } else {
                    // No se puede eliminar porque la raiz solo apunta
                    // a un unico nodo
                    resp = -2;
                }
            } else {
                int sumNodos = buscado->cantidadNodos + buscado->nodoPadre->cantidadNodos;
                if(sumNodos <= MAX) {
                    int i = buscado->nodoPadre->cantidadNodos - 1;
                    int j = 0;
                    while(j < buscado->cantidadNodos){
                        buscado->nodoPadre->nodos[i] = buscado->nodos[j];
                        i++;
                        j++;
                    }
                    
                    // buscamos el indice donde esta el nodo hijo
                    j = -2;
                    for(i = 0; i != j + 1 && i < buscado->nodoPadre->cantidadNodos; i++){
                        if(buscado->nodoPadre->nodos[i] == buscado) {
                            j = i;
                        }
                    }
                    // Disminuimos 1 unidad en los nodos hijos del padre 
                    // (se va el nodo buscado)
                    buscado->nodoPadre->cantidadNodos--;

                    // Reorganizamos
                    for(int i = j; i < buscado->nodoPadre->cantidadNodos; i++) {
                        buscado->nodoPadre->nodos[i] = buscado->nodoPadre->nodos[i+1];
                    }

                    delete buscado;
                } else {
                    // No se puede eliminar porque los nodos del hijo
                    // al pasar al ser del padre, escapan al tamaño del
                    // arreglo de nodos
                    resp = -3;
                }
            }
        } else {
            // No existe el elemento
            resp = 0;
        }
    } else {
        // No existen elementos en el arbol
        resp = -1;
    }
    return resp;
}

template <class T>
NodoArbolMultiple<T>* ArbolMultiple<T>::buscar(T dato, NodoArbolMultiple<T>* ref)
{
    if(ref->info == dato) {
        return ref;
    } else {
        if(ref->cantidadNodos != 0) {
            for(int i = 0; i < ref->cantidadNodos; i++) {
                NodoArbolMultiple<T>* encontrado = buscar(dato, ref->nodos[i]);
                if(encontrado != NULL) {
                    return encontrado;
                }
            }
        }
    }
    return NULL;
}

template <class T>
void ArbolMultiple<T>::imprimir(NodoArbolMultiple<T>* ref)
{
    if(ref == NULL) {
        ref = raiz;
        std::cout << std::endl;
    }

    std::cout << ref->info << std::endl;

    if(ref->cantidadNodos != 0) {
        for(int i = 0; i < ref->cantidadNodos; i++) {
            imprimir(ref->nodos[i]);
        }
    }

}

void testEjercicio1()
{
    ArbolMultiple<int> arbolMultiple = ArbolMultiple<int>();

    NodoArbolMultiple<int>* buscado;
    std::cout << "\nResp 7  en raiz: " << arbolMultiple.insertarRaiz(7);
    std::cout << "\nResp 8  en  7: " << arbolMultiple.insertar(8, 7);
    std::cout << "\nResp 11 en  7: " << arbolMultiple.insertar(11, 7);
    std::cout << "\nResp 3  en  8: " << arbolMultiple.insertar(3, 8);
    std::cout << "\nResp 12 en -6: " << arbolMultiple.insertar(12, -6);
    buscado = arbolMultiple.buscar(2, arbolMultiple.regresaRaiz());
    std::cout << "\nBuscar 2: " << ((buscado) ? "ENCONTRADO": "NO ENCONTRADO");
    buscado = arbolMultiple.buscar(8, arbolMultiple.regresaRaiz());
    std::cout << "\nBuscar 8: " << ((buscado) ? "ENCONTRADO": "NO ENCONTRADO");
    arbolMultiple.imprimir();

    std::cout << "\nElimina 7: " << arbolMultiple.eliminar(7);
    std::cout << "\nElimina 3: " << arbolMultiple.eliminar(3);
    std::cout << "\nElimina 165: " << arbolMultiple.eliminar(165);
    arbolMultiple.imprimir();
}

int main()
{  
    testEjercicio1();
    return 0;
}