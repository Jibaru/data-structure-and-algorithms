/*
9.	Se dice que un árbol binario es completo si todos sus nodos, 
excepto las hojas, tienen dos hijos. Escriba una función en C++ 
que determine si un árbol (dado como parámetro) es completo. 
En la siguiente figura se presenta un ejemplo de un árbol 
que tiene esta característica.

        M
    J       Q
  I  K     O  S
*/
#include <iostream>
#include "../../lib/arboles/ArbolBinBusqueda.h"

using namespace std;

int main()
{
  ArbolBinBus<char> arbol = ArbolBinBus<char>();

  arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 'M');
  arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 'J');
  arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 'Q');
  arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 'I');
  arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 'K');
  arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 'O');
  arbol.InsertaNodoSinRep(arbol.RegresaRaiz(), 'S');

  cout << "Arbol Completo: " << (arbol.EsCompleto() ? "COMPLETO" : "INCOMPLETO") << endl;

  return 0;
}