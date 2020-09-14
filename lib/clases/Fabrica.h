
#ifndef _FABRICA_
#define _FABRICA_

#include <iostream>
#include <string.h>

/* Definición de la clase Fabrica. Se incluyen varios operadores 
sobrecargados para que puedan ser utilizados por los métodos de la 
clase ArbolBalanceado. Asimismo, se declaran como amigos los operadores 
de entrada (>>) y de salida (<<) para que objetos de este tipo puedan 
leerse e imprimirse directamente con std::cin y std::cout respectivamente. */
#define MAX 60

class Fabrica {
private:
    int Clave;
    char Nombre[MAX], Domicilio[MAX], Telefono[MAX];
public:
    Fabrica();
    Fabrica(int, char [], char[], char[]);
    void CambiaDomic(char[]);
    void CambiaTelef(char[]);
    int operator>(Fabrica);
    int operator<(Fabrica);
    int operator==(Fabrica);
    friend std::istream& operator>> (std::istream & , Fabrica &);
    friend std::ostream& operator<< (std::ostream & , Fabrica &);
};

#endif /* _FABRICA_ */