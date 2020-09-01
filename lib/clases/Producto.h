#ifndef _PRODUCTOS_H_
#define _PRODUCTOS_H_

/* Definición de la clase Producto. Se sobrecargan algunos operadores 
para que objetos de esta clase puedan ser usados de manera directa. 
Esta clase se guarda en la biblioteca "Productos.h" */
#include <iostream>

class Producto {
private:
    int Clave;
    char NomProd[64];
    double Precio;
public:
    Producto();
    Producto(int, const char[], double);
    double RegresaPrecio();
    int operator == (Producto);
    int operator != (Producto);
    int operator > (Producto);
    int operator < (Producto);
    friend std::istream &operator>> (std::istream &, Producto &);
    friend std::ostream &operator<< (std::ostream &, Producto &);
};

#endif