/*
3.	Escriba un método que cuente el número de nodos intermedios de un árbol 
binario. ¿Podría resolverlo por medio de una función? Justifique su respuesta.
*/
#include <iostream>
#include "../../lib/arboles/ArbolBinBusqueda.h"

using namespace std;

int main()
{
    ArbolBinBus<int> arbol = ArbolBinBus<int>();

    arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 156);
    arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 99);
    arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 360);
    arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 67);
    arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 258);
    arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 508);
    arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 301);

    arbol.Preorden(arbol.RegresaRaiz());

    cout << "\nCantidad nodos intermedios: " << arbol.NumeroNodosIntermedios() << endl;
    
    return 0;
}