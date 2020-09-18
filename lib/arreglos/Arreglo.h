#ifndef _ARREGLO_H_
#define _ARREGLO_H_

#define MAX_ARREGLO 100

template <class T>
class Arreglo
{
private:
    T arreglo[MAX_ARREGLO];
    int tam;
public:
    Arreglo();
    int insertar(T);
    int insertarSinRep(T);
    int modificar(T, T);
    int eliminar(T);
    int buscar(T);
    int tamanio();
    T* primero();
    T* ultimo();
    T* obtener(int);
};

template <class T>
Arreglo<T>::Arreglo()
{
    tam = 0;
}

template <class T>
int Arreglo<T>::insertar(T dato)
{
    int resp = 1;
    if(tam < MAX_ARREGLO) {
        arreglo[tam] = dato;
        tam++;
    } else {
        resp = 0;
    }
    return resp;
}

template <class T>
int Arreglo<T>::insertarSinRep(T dato)
{
    int resp = 1, i = 0;
    if (tam < MAX_ARREGLO) {
        while(i < tam && arreglo[i] != dato) {
            i++;
        }
        if(i == tam) {
            arreglo[tam] = dato;
            tam++;
        } else {
            // Repetido
            resp = -1;
        }
    } else {
        resp = 0;
    }
    return resp;
}

template <class T>
int Arreglo<T>::modificar(T antiguo, T nuevo)
{
    int resp = 1, indice;

    indice = buscar(antiguo);

    if(indice >= 0) {
        arreglo[indice] = nuevo;
    } else {
        resp = 0;
    }

    return resp;
}

template <class T>
int Arreglo<T>::buscar(T dato)
{
    int i = 0, resp;
    while(i < tam && arreglo[i] != dato) {
        i++;
    }

    if(i == tam) {
        resp = 0;
    } else {
        resp = i;
    }

    return resp;
}

template <class T>
int Arreglo<T>::eliminar(T dato)
{
    int resp = 1, indice;
    indice = buscar(dato);

    if(indice >= 0) {
        // Existe
        tam--;
        for(int i = indice; i < tam; i++) {
            arreglo[i] = arreglo[i+1];
        }
    } else {
        resp = 0;
    }
    return resp;
}

template <class T>
int Arreglo<T>::tamanio()
{
    return tam;
}

template <class T>
T* Arreglo<T>::primero()
{
    if(tam == 0) {
        return NULL;
    }
    return &arreglo[0];
}

template <class T>
T* Arreglo<T>::ultimo()
{
    if(tam == 0) {
        return NULL;
    }
    return &arreglo[tam - 1];
}

template <class T>
T* Arreglo<T>::obtener(int pos)
{
    if(pos < tam) {
        return &arreglo[pos];
    }
    return NULL;
}

#endif /* _ARREGLO_H_ */