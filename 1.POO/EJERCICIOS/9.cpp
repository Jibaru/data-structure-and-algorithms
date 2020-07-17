/*
9.	Defina la clase Rectángulo. Determine los atributos y el conjunto de métodos (lo más completos
posible) que caracterizan al concepto rectángulo.
*/
#include <iostream>

using namespace std;

class Rectangulo {
private:
    float lado1, lado2;
public:
    Rectangulo(float l1, float l2): lado1(l1), lado2(l2){};
    float area();
    float perimetro();
    void imprime();
};

float Rectangulo::area()
{
    return lado1 * lado2;
}

float Rectangulo::perimetro()
{
    return 2 * (lado1 + lado2);
}

void Rectangulo::imprime()
{
    cout << "Lado1: " << lado1 << endl;
    cout << "Lado2: " << lado2 << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimetro: " << perimetro << endl;
}