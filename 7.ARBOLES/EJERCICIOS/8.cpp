/*
8.	Se dice que dos árboles son equivalentes cuando sus estructuras 
son iguales y además tienen el mismo contenido. Escriba una función 
en C++ que determine si dos árboles (dados como parámetros) son 
equivalentes. En la siguiente figura se presenta un ejemplo de dos 
árboles que tienen esta característica.

        X                   X
    Z       A           Z       A
      M   K   P           M   K   P

*/
#include <iostream>
#include "1.cpp"

using namespace std;

int main()
{
  ArbolMultiple<char> arbol1 = ArbolMultiple<char>();
  ArbolMultiple<char> arbol2 = ArbolMultiple<char>();
  
  arbol1.insertarRaiz('X');
  arbol1.insertar('Z', 'X');
  arbol1.insertar('A', 'X');
  arbol1.insertar('M', 'Z');
  arbol1.insertar('K', 'A');
  arbol1.insertar('P', 'A');

  arbol2.insertarRaiz('X');
  arbol2.insertar('Z', 'X');
  arbol2.insertar('A', 'X');
  arbol2.insertar('M', 'Z');
  arbol2.insertar('K', 'A');
  arbol2.insertar('P', 'A');

  cout << "Arboles iguales: " << (arbol1.igual(arbol2) ? "IGUAL" : "DESIGUAL") << endl;

  return 0;
}