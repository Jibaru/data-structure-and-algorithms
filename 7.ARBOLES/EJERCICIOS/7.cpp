/*
7.	Se dice que dos árboles son similares cuando sus estructuras 
son iguales. Escriba una función en C++ que determine si dos árboles 
(dados como parámetros) son similares. En la siguiente figura se 
presenta un ejemplo de dos árboles que tienen esta característica.

        T                   X
    J       V           Z       A
      Q   G   S           M   K   P
*/  
#include <iostream>
#include "1.cpp"

using namespace std;

int main()
{
  ArbolMultiple<char> arbol1 = ArbolMultiple<char>();
  ArbolMultiple<char> arbol2 = ArbolMultiple<char>();
  
  arbol1.insertarRaiz('T');
  arbol1.insertar('J', 'T');
  arbol1.insertar('V', 'T');
  arbol1.insertar('Q', 'J');
  arbol1.insertar('G', 'V');
  arbol1.insertar('S', 'V');

  arbol2.insertarRaiz('X');
  arbol2.insertar('Z', 'X');
  arbol2.insertar('A', 'X');
  arbol2.insertar('M', 'Z');
  arbol2.insertar('K', 'A');
  arbol2.insertar('P', 'A');

  cout << "Arboles similares: " << (arbol1.similar(arbol2) ? "SIMILAR" : "NO SIMILAR") << endl;

  return 0;
}