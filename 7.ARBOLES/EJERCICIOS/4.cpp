/*
4.	Escriba un método que calcule la altura de un árbol binario. 
¿Podría resolverlo por medio de una función? Justifique su respuesta.
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

    cout << "\nAltura del arbol: " << arbol.Altura() << endl;
    
    return 0;
}