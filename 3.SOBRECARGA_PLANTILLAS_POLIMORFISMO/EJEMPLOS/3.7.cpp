/* La clase EjemploPlantilla tiene dos miembros privados, cada uno de un 
tipo diferente, por lo que se usan los tipos T1 y T2 para indicarlo. 
Asimismo, en los métodos definidos se utilizan T1 y T2 para dar 
flexibilidad en cuanto a los tipos de datos. */
#include <iostream>
using namespace std;

template <class T1, class T2>
class EjemploPlantilla {
private:
    T1 Dato1;
    T2 Dato2;
public:
    EjemploPlantilla ();
    EjemploPlantilla (T1, T2);
    void ModificaDato1(T1);
    void ModificaDato2(T2);
    T1 ObtieneDato1();
    T2 ObtieneDato2();
    void ImprimeDatos();
};

/* Declaración del método constructor por omisión. */
template <class T1, class T2>
EjemploPlantilla<T1,T2>::EjemploPlantilla()
{ }

/* Declaración del método constructor con parámetros. */
template <class T1, class T2>
EjemploPlantilla<T1,T2>::EjemploPlantilla (T1 D1, T2 D2)
{
    Dato1= D1;
    Dato2= D2;
}

/* Plantilla del método que permite modificar el valor del atributo 
Dato1. */
template <class T1, class T2>
void EjemploPlantilla<T1,T2>::ModificaDato1(T1 NuevoDato)
{
    Dato1= NuevoDato;
}

/* Plantilla del método que permite modificar el valor del atributo 
Dato2. */
template <class T1, class T2>
void EjemploPlantilla <T1,T2>::ModificaDato2(T2 NuevoDato) 
{
    Dato2= NuevoDato;
}

/* Plantilla del método que permite, a usuarios externos a la clase, 
conocer el valor del atributo Dato1. */
template <class T1, class T2>
T1 EjemploPlantilla <T1,T2>::ObtieneDato1()
{
    return Dato1;
}

/* Plantilla del método que permite, a usuarios externos a la clase, 
conocer el valor del atributo Dato2. */
template <class T1, class T2>
T2 EjemploPlantilla <T1,T2>::ObtieneDato2()
{
    return Dato2;
}

/* Plantilla del método que imprime los valores de los atributos. */
template <class T1, class T2>
void EjemploPlantilla <T1,T2>::ImprimeDatos()
{
    cout << "Dato 1: " << Dato1 << endl;
    cout << "Dato 2: " << Dato2 << endl;
}

/* Función que usa la plantilla de la clase EjemploPlantilla previamente 
definida: se declara un objeto usando los tipos int y float para 
instanciar los tipos T1 y T2 en la plantilla. Luego se modifican sus 
atributos y se imprimen. */
void UsaPlantilla(){
    EjemploPlantilla<int, float> ObjPlantilla(1, 6.0);
    ObjPlantilla.ImprimeDatos();
    ObjPlantilla.ModificaDato1(2);
    ObjPlantilla.ModificaDato2(12.0);
    cout << "Dato 1 modificado : " << ObjPlantilla.ObtieneDato1() << endl;
    cout << "Dato 2 modificado : " << ObjPlantilla.ObtieneDato2() << endl; 
}

int main() {
    UsaPlantilla();
    return 0;
}