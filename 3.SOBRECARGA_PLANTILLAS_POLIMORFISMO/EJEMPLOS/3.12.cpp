/* Se define la clase Figura la cual se usará como base para declarar 
las clases derivadas: Triangulo, Rectángulo y Cuadrado. La clase base es 
una clase abstracta ya que no se crearán instancias de ella, sino que 
se utiliza para crear una abstracción de un nivel superior de todas las 
figuras geométricas. La clase abstracta contiene un método virtual puro 
llamado CalculaArea(). */
#include <iostream>
#include <math.h>
using namespace std;

/* Definición de la clase abstracta Figura. */
class Figura {
public:
    Figura();
    virtual float CalculaArea()= 0;
}; 

/* Declaración del método constructor por omisión. */
Figura::Figura()
{}

/* Definición de la clase Triangulo, derivada de la clase abstracta Figura.
Un triángulo se representa por medio de la longitud de su base de su altura.
La clase incluye además, un método virtual llamado CalculaArea(). */
class Triangulo: public Figura {
private:
    float Base, Altura;
public:
    Triangulo(float, float);
    virtual float CalculaArea();
};

/* Declaración del método constructor con parámetros. */
Triangulo::Triangulo(float Ba, float Alt)
{
    Base= Ba;
    Altura= Alt;
}

/* Método que calcula el área de un triángulo. */
float Triangulo::CalculaArea()
{
    return (Base * Altura / 2);
}

/* Definición de la clase Equilátero, derivada de la clase Triangulo. */
class TrianguloEquilatero: public Triangulo {
public:
    TrianguloEquilatero(float, float);
    float CalculaArea();
};

/* Declaración del método constructor con parámetros. Invoca al método 
constructor de la clase base. */
TrianguloEquilatero::TrianguloEquilatero(float Ba, float Alt): Triangulo(Ba, Alt)
{}

/* Método que calcula el área de un triángulo equilátero. */
float TrianguloEquilatero::CalculaArea()
{
    return Triangulo::CalculaArea();
}

/* Definición de la clase TrianguloRectángulo, derivada de la clase 
Triangulo. */
class TrianguloRectangulo: public Triangulo
{
private:
    float Cateto1, Cateto2, Hipotenusa;
public:
    TrianguloRectangulo (float, float);
    float CalculaArea();
};

/* Declaración del método constructor con parámetros. Invoca al método 
constructor de la clase base. */
TrianguloRectangulo::TrianguloRectangulo(float Cat1, float Cat2): Triangulo(Cat1, Cat2)
{
    Cateto1= Cat1;
    Cateto2= Cat2;
    Hipotenusa= sqrt(Cat1*Cat1 + Cat2*Cat2);
}

/* Método que calcula el área de un triángulo rectángulo. */
float TrianguloRectangulo::CalculaArea()
{
    return (Cateto1*Cateto2);
}

/* Definición de la clase Rectángulo, derivada de la clase abstracta Figura. */
class Rectangulo: public Figura
{
private:
    float Largo, Alto;
public:
    Rectangulo(float, float);
    float CalculaArea();
};

/* Declaración del método constructor con parámetros. */
Rectangulo::Rectangulo(float Lar, float Al)
{
    Largo= Lar;
    Alto= Al;
}

/* Método que calcula el área de un rectángulo. */
float Rectangulo::CalculaArea()
{
    return (Largo*Alto);
}

/* Definición de la clase Cuadrado, derivada de la clase Rectángulo. */
class Cuadrado: public Rectangulo {
public:
    Cuadrado(float);
    float CalculaArea();
};

/* Declaración del método constructor con parámetros. Invoca al método 
constructor de la clase base. */
Cuadrado::Cuadrado(float Lado): Rectangulo(Lado, Lado)
{}

/* Método que calcula el área de un cuadrado, haciendo uso del método 
heredado de la clase Rectángulo. */
float Cuadrado::CalculaArea()
{
    return Rectangulo::CalculaArea();
}

/* Función que usa las clases definidas previamente. Observe que no se 
han creado objetos del tipo de la clase abstracta Figura. */
void UsaFiguras()
{
    TrianguloEquilatero TriaEq(5,7);
    TrianguloRectangulo TriaRec(3, 4);
    Rectangulo Rectan(2, 3);
    Cuadrado Cuadro(5);
    cout << "\nArea del triangulo equilatero: " << TriaEq.CalculaArea();
    cout << "\nArea del triangulo rectangulo: " << TriaRec.CalculaArea();
    cout << "\nArea del rectangulo: " << Rectan.CalculaArea();
    cout << "\nArea del cuadrado: " << Cuadro.CalculaArea();
}

int main() {
    UsaFiguras();
    return 0;
}
