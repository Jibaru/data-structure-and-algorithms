/* Clase Vector en la cual se incluye un método para sumar vectores 
sobrecargando el operador +. */ 

#include <iostream>
using namespace std;

class Vector {
private:
float CoordX, CoordY;
public:
    Vector (float Val1= 0, float Val2= 0);
    void ImprimeVector();
    Vector operator+(Vector Vec);
};

/* Declaración del método constructor con parámetros predeterminados;
*+a los cuales, si no les especifican otros valores, se les asignará 0. */ 
Vector::Vector(float Val1, float Val2)
{
    CoordX= Val1;
    CoordY= Val2;
}

/* Método que imprime los valores de los atributos de un vector. */ 
void Vector::ImprimeVector()
{
    cout << "X: " << CoordX << " Y: " << CoordY << endl;
}

/* Método en el cual se sobrecarga el operador +; por lo tanto, el 
operador + se podrá usar tanto para la suma aritmética como para suma 
de vectores. Lo anterior da como resultado un objeto de tipo Vector. */
Vector Vector::operator+ (Vector Vec)
{
    return Vector(CoordX+Vec.CoordX, CoordY + Vec.CoordY);
}

/* Función que utiliza el operador + sobrecargado. Se declaran dos objetos
de tipo Vector y, por medio del operador +, se obtiene su suma. */
void UsaSobrecarga(void)
{
    Vector ObjVectorU(3, 1), ObjVectorV(1, 2), ObjVectorR;
    /* Se invoca al operador sobrecargado: se realiza la suma de ^•vectores. */
    ObjVectorR= ObjVectorU + ObjVectorV;
    ObjVectorR.ImprimeVector();
}

int main() {
    UsaSobrecarga();
    return 0;
}
