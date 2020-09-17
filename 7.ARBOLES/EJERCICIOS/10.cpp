/*
10.	Retome la plantilla de la clase ArboiBinario presentada en este libro, 
e incluya un método que imprima por niveles toda la información de un 
objeto tipo árbol. Si el árbol fuera el que aparece en el problema 8, 
la impresión sería:

X-Z-A-M-K-P
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

  arbol.ImprimePorNiveles();

  return 0;
}