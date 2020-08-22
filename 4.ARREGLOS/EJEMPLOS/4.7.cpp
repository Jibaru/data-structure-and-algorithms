/* Plantilla de la clase ArregloBidimensional. Se definen algunos métodos
útiles para el manejo del contenido de un arreglo de dos dimensiones.
Los atributos son la colección de datos, Datos[MAX] [MAX], en la cual se
establece un número máximo de renglones y de columnas y el número 
de renglones y de columnas que están ocupadas, Numñen y NumCol. */
#include <iostream>
#define MAX 40
using namespace std;

template <class T>
class ArregloBidimensional
{
private:
    T Datos[MAX] [MAX];
    int NumRen, NumCol;
    
public:
    ArregloBidimensional();
    ArregloBidimensional(int, int);
    void Lectura();
    void Escritura();
    T SumaRenglon(int);
    T SumaColumna(int);
    T MaximoColumna(int) ;
    T MaximoRenglon(int);
    T MinimoColumna(int);
    T MinimoRenglon(int);
    T RegresaDato(int, int);
    ArregloBidimensional<T> operator+(ArregloBidimensional&);
    ArregloBidimensional<T> operator*(ArregloBidimensional&);
};

/* Declaración del método constructor por omisión. Inicializa el 
número actual de renglones y de columnas en 0. */
template <class T>
ArregloBidimensional<T>::ArregloBidimensional()
{
    NumRen= 0;
    NumCol= 0;
}

/* Declaración del método constructor con parámetros. */
template <class T>
ArregloBidimensional<T>::ArregloBidimensional(int NR, int NC)
{
    NumRen= NR;
    NumCol= NC;
}

/* Método de lectura. Los datos leídos del teclado se almacenan por 
renglones. Observe que el ciclo externo es el de los renglones (primer índice).
Por lo tanto, para cada valor del mismo se recorren todas las columnas 
(ciclo interno). Para darle mayor información al usuario, se supone que la 
lectura y validación del total de elementos se hace en el programa de 
aplicación y desde ahí también se invoca el constructor con parámetros 
para asignarle valores a los atributos NumRen y NumCol.*/
template <class T>
void ArregloBidimensional<T>::Lectura()
{
    int Ren, Col;
    for (Ren= 0; Ren < NumRen; Ren++)
    {
        for (Col= 0; Col < NumCol; Col++)
        {
            cout << "\n[" << Ren << "][" << Col << "]. Ingrese dato: ";
            cin >> Datos[Ren][Col];
        }
    }
}

/* Método de escritura. Los datos almacenados se despliegan en la pantalla 
por renglones. Con respecto al orden de los índices aplica el mismo 
comentario que en el método de lectura. */
template <class T>
void ArregloBidimensional<T>::Escritura()
{
    int Ren, Col;
    for (Ren= 0; Ren < NumRen; Ren++)
    {
        for (Col= 0; Col < NumCol; Col++)
            cout << Datos[Ren][Col] << " ";
        cout << endl;
    }
}

/* Método que suma todos los elementos de un renglón. Para ello se deben 
recorrer todas las columnas de dicho renglón. El número de renglón a 
sumar se indica a través del parámetro. Si el tipo T usado para crear 
el objeto ArregloBidimensional no fuera un número, entonces se debería 
sobrecargar el operador + . */
template <class T>
T ArregloBidimensional<T>::SumaRenglon(int Ren)
{
    T Suma = 0; int Col;

    for (Col= 0; Col < NumCol; Col++)
        Suma= Suma + Datos[Ren][Col];

    return Suma;
}

/* Método que suma todos los elementos de una columna. Para ello se 
deben recorrer todos los renglones de dicha columna. El número de 
columna a sumar se indica a través del parámetro. Si el tipo T usado 
para crear el objeto ArregloBidimensional no fuera un número, entonces 
se debería sobrecargar el operador + . */
template <class T>
T ArregloBidimensional<T>::SumaColumna(int Col)
{
    T Suma= 0; int Ren;
    for (Ren= 0; Ren < NumRen; Ren++)
        Suma= Suma + Datos[Ren][Col];
    
    return Suma;
}

/* Método que da como resultado el valor más grande almacenado en una 
columna del arreglo, dada como dato. Para ello se deja fijo el valor de 
la columna y se recorren todos los renglones. Si el tipo T usado para 
crear el objeto ArregloBidimensional no fuera un número, entonces se 
debería sobrecargar el operador > . */
template <class T>
T ArregloBidimensional<T>::MaximoColumna(int Col)
{
    T Maximo= Datos[0][Col];
    int Ren;

    for (Ren= 1; Ren < NumRen; Ren++)
    {
        if (Datos[Ren][Col] > Maximo)
            Maximo= Datos[Ren][Col];
    }
            
    return Maximo;
}

/* Método que da como resultado el valor más grande almacenado en un 
renglón del arreglo, dado como dato. Para ello se deja fijo el valor 
del renglón y se recorren todas las columnas. Si el tipo T usado para
crear el objeto ArregloBidimensional no fuera un número, entonces se 
debería sobrecargar el operador >. */
template <class T>
T ArregloBidimensional<T>::MaximoRenglon(int Ren)
{
    T Maximo= Datos[Ren][0];
    int Col;

    for (Col= 1; Col < NumCol; Col++)
    {
        if (Datos[Ren][Col] > Maximo)
            Maximo= Datos[Ren][Col];
    }
    
    return Maximo;
}

/* Método que da como resultado el valor más pequeño almacenado en una
columna del arreglo, dada como dato. Para ello se deja fijo el valor de
la columna y se recorren todos los renglones. Si el tipo T usado para 
crear el objeto ArregloBidimensional no fuera un número, entonces se 
debería sobrecargar el operador <. */
template <class T>
T ArregloBidimensional<T>::MinimoColumna(int Col)
{
    T Minimo= Datos[0][Col]; int Ren;
    for (Ren= 1; Ren < NumRen; Ren++)
    {
        if (Datos[Ren][Col] < Minimo)
            Minimo= Datos[Ren][Col];
    }
    
    return Minimo;
}

/* Método que da como resultado el valor más pequeño almacenado en un
renglón del arreglo, dado como dato. Para ello se deja fijo el valor 
del renglón y se recorren todas las columnas. Si el tipo T usado para 
crear el objeto ArregloBidimensional no fuera un número, entonces se 
debería sobrecargar el operador <. */
template <class T>
T ArregloBidimensional<T>::MinimoRenglon(int Ren)
{
    T Minimo= Datos[Ren][0]; int Col;
    for (Col= 1; Col < NumCol; Col++)
    {
        if (Datos[Ren][Col] < Minimo)
            Minimo= Datos[Ren][Col];
    }

    return Minimo;
}

/* Método que permite, a usuarios externos a la clase, conocer el 
contenido de una de las casillas del arreglo. Recibe como parámetros 
dos enteros, fíen y Col, que indican la posición (renglón y columna 
respectivamente) del componente deseado del arreglo. El resultado es un 
valor de tipo T. */
template <class T>
T ArregloBidimensional<T>::RegresaDato(int Ren, int Col)
{
    return Datos[Ren][Col];
}

/*Sobreescritura del operador + 
Suma los elementos del arregloBidimensional con otro y devuelve un nuevo 
ArregloBidimensional*/
template <class T>
ArregloBidimensional<T> ArregloBidimensional<T>::operator+(ArregloBidimensional<T>& otro)
{
    ArregloBidimensional<T> nuevo(NumRen, NumCol);
    for(int i = 0; i < NumCol; i++) {
        for(int j = 0; j < NumRen; j++) {
            nuevo.Datos[i][j] = Datos[i][j] + otro.Datos[i][j];
        }
    }
    return nuevo;
}

/*Sobreescritura del operador * 
Multiplica los elementos del arregloBidimensional con otro y devuelve un nuevo 
ArregloBidimensional*/
template <class T>
ArregloBidimensional<T> ArregloBidimensional<T>::operator*(ArregloBidimensional<T>& otro)
{
    ArregloBidimensional<T> nuevo(NumRen, otro.NumCol);
    int suma = 0, r = 0;
    for(int i = 0; i < NumRen; i++) {
        for(int j = 0; j < otro.NumCol; j++) {

            while(r < NumCol) {
                suma += Datos[i][r] * otro.Datos[r][j];
                r++;
            }

            nuevo.Datos[i][j] = suma;
            r = 0;
            suma = 0;
        }
    }
    return nuevo;
}