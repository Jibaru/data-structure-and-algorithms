/*
4. Definir la clase FiguraGeometrica que contenga los atributos que caracterizan a toda figura 
geométrica y los métodos necesarios para manejarlos. Además, defina las clases derivadas Cuadrado y
Triangulo. Escriba un programa en C++ que haga uso de estas clases para calcular el total de metros 
cuadrados de tela necesaria para fabricar N almohadones con forma cuadrada y M almohadones con forma 
de triángulo equilátero. Los datos que se ingresarán al programa son: 
Datos:
•N: total de almohadones con forma cuadrada.
•LadoC: tamaño, en centímetros, de cada uno de los lados del almoha¬dón cuadrado.
•M: total de almohadones con forma triangular.
•LadoT: tamaño, en centímetros, de cada uno de los lados del almoha¬dón triangular.
Resultado esperado: Total de metros cuadrados requeridos para la fabricación de los N + M almohadones.

*/
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

class FiguraGeometrica {
protected:
    int numLados;
    char* nombre;
public:
    FiguraGeometrica(int, char*);
    FiguraGeometrica(){};
    void cambiarNumLados(int);
    void cambiarNombre(char*);
    int obtenerNumLados();
    char* obtenerNombre();
    void imprimirDatos();
};

FiguraGeometrica::FiguraGeometrica(int numLad, char* nom)
{
    numLados = numLad;
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
}

void FiguraGeometrica::cambiarNumLados(int num)
{
    numLados = num;
}

void FiguraGeometrica::cambiarNombre(char* nom)
{
    nombre = new char[strlen(nom) + 1];
    strcpy(nombre, nom);
}

int FiguraGeometrica::obtenerNumLados()
{
    return numLados;
}

char* FiguraGeometrica::obtenerNombre()
{
    return nombre;
}

void FiguraGeometrica::imprimirDatos()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Num. Lados: " << numLados << endl;
}

class Cuadrado : public FiguraGeometrica {
private:
    float lado;
public:
    Cuadrado(){}
    Cuadrado(float);
    float obtenerLado();
    void cambiarLado(float);
    float area();
    float perimetro();
    float areaDeN(int);
    void imprimirDatos();
};

Cuadrado::Cuadrado(float lad)
{
    FiguraGeometrica(4, "Cuadrado");
    lado = lad;
}

float Cuadrado::obtenerLado()
{
    return lado;
}

void Cuadrado::cambiarLado(float lad)
{
    lado = lad;
}

float Cuadrado::area()
{
    return lado * lado;
}

float Cuadrado::areaDeN(int n)
{
    return n * area();
}

float Cuadrado::perimetro()
{
    return lado * 4;
}

void Cuadrado::imprimirDatos()
{
    FiguraGeometrica::imprimirDatos();
    cout << "Lado: " << lado << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimetro: " << perimetro() << endl;
}

class Triangulo : public FiguraGeometrica {
private:
    float lado1, lado2, lado3;
public:
    Triangulo(float, float, float);
    Triangulo(){}
    float perimetro();
    float area();
    float areaDeN(int);
    void imprimirDatos();
};

Triangulo::Triangulo(float l1, float l2, float l3)
{
    FiguraGeometrica(3, "Triangulo");
    lado1 = l1;
    lado2 = l2;
    lado3 = l3;
}

float Triangulo::perimetro()
{
    return lado1 + lado2 + lado3;
}

float Triangulo::area()
{
    float s = perimetro()/2;
    return sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
}

float Triangulo::areaDeN(int n)
{
    return n * area();
}

void Triangulo::imprimirDatos()
{
    FiguraGeometrica::imprimirDatos();
    cout << "Lado 1: " << lado1 << endl;
    cout << "Lado 2: " << lado2 << endl;
    cout << "Lado 3: " << lado3 << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimetro: " << perimetro() << endl;
}

int main() {

    Cuadrado almCuadrado;
    Triangulo almTriangular;
    
    int N, M;
    float ladoC, ladoT;

    cout << "Ingrese cantidad de almohadones cuadrados: ";
    cin >> N;

    cout << "Ingrese lado del almohadon: ";
    cin >> ladoC;

    cout << "Ingrese cantidad de almohadones triangulares: ";
    cin >> M;

    cout << "Ingrese lado del almohadon: ";
    cin >> ladoT;

    almCuadrado = Cuadrado(ladoC);
    almTriangular = Triangulo(ladoT, ladoT, ladoT);

    cout << "El area para alm. cuadrados: " << almCuadrado.areaDeN(N) << endl;
    cout << "El area para alm. triangulares: " << almTriangular.areaDeN(M) << endl;
    cout << "Area total: " << almCuadrado.areaDeN(N) + almTriangular.areaDeN(M) << endl;

    return 0;
}