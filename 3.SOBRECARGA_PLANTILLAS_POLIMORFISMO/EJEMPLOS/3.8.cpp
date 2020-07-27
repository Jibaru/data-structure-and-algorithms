/* Se define la plantilla de la clase Segmento. De esta forma cuando se 
declare un objeto de la clase Segmento se podrá decidir el tipo de dato 
para sus miembros.*/
#include <iostream>
using namespace std;

template <class T> class Segmento {
private:
    T Origen, Final;
public:
    Segmento();
    Segmento(T, T);
    void ModificaOrigen(T);
    void ModificaFinal(T);
    T ObtieneOrigen();
    T ObtieneFinal();
    void ImprimeDatos();
};

/* Declaración del método constructor por omisión. */
template <class T>
Segmento<T>::Segmento()
{ }

/* Declaración del método constructor con parámetros. */
template <class T>
Segmento<T>::Segmento(T Or, T Fi)
{
    Origen= Or;
    Final= Fi;
}

/* Plantilla del método que permite modificar el valor del atributo 
Origen. */
template <class T>
void Segmento<T>::ModificaOrigen(T NuevoPunto)
{
    Origen= NuevoPunto;
}

/* Plantilla del método que permite modificar el valor del atributo 
Final. */
template <class T>
void Segmento<T>::ModificaFinal(T NuevoPunto) 
{
    Final= NuevoPunto;
}
/* Plantilla del método que permite, a usuarios externos a la clase, 
conocer el valor del atributo Origen. */
template <class T>
T Segmento<T>::ObtieneOrigen()
{
    return Origen;
}

/* Plantilla del método que permite, a usuarios externos a la clase, 
conocer el valor del atributo Final. */
template <class T>
T Segmento<T>::ObtieneFinal()
{
    return Final;
}

/* Plantilla del método que imprime los valores de los atributos de la
clase. */
template <class T>
void Segmento<T>::ImprimeDatos()
{
    cout << "Origen: " << Origen << endl;
    cout << "Final: " << Final << endl;
}

/* Función que usa la plantilla de la clase Segmento: se crean dos objetos, 
uno con números enteros y otro con números reales. Posteriormente se 
modifican y se imprimen los valores de los atributos de los objetos creados. */
void UsaPlantilla() {
    Segmento<int> SegmentoEntero(1, 6);
    Segmento<float> SegmentoReal(2.0, 15.0);
    cout << "Datos del primer segmento: " << endl;
    SegmentoEntero.ImprimeDatos();
    cout << "Datos del segundo segmento: " << endl;
    SegmentoReal.ImprimeDatos();
    SegmentoEntero.ModificaOrigen(SegmentoEntero.ObtieneOrigen() + 2);
    SegmentoReal.ModificaFinal(SegmentoReal.ObtieneFinal() - 5.3);
    cout << "Datos del primer segmento modificado: " << endl;
    SegmentoEntero.ImprimeDatos();
    cout << "Datos del segundo segmento modificado: " << endl;
    SegmentoReal.ImprimeDatos();
}

int main() {
    UsaPlantilla();
    return 0;
}