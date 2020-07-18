/*
13.	Defina la clase Cubo. Determine los atributos y el conjunto de métodos (lo más completos posible) 
que caracterizan al concepto cubo.
*/
#include <iostream>
#include <string.h>

using namespace std;

class Cubo {
private:
    float _lado;
    char _color[40];

public:
    Cubo(float lado, char color[]): _lado(lado) { strcpy(_color, color); };
    float area();
    float volumen();
    float obtenerLado();
};

float Cubo::area() {
    return 6 * (_lado * _lado);
}

float Cubo::volumen() {
    return _lado * _lado * _lado;
}

float Cubo::obtenerLado() {
    return _lado;
}