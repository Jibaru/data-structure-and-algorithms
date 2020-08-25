#include <iostream>
using namespace std;

/* Prototipo de la clase MatPocoDen para poder declararla como amiga 
de la clase Componente, y de esta forma darle acceso a los miembros 
privados de esta última. */
template <class T> 
class MatPocoDen;

/* Definición de la plantilla de clase que representa cada uno de los 
elementos distintos de cero de la matriz poco densa. */
template <class T>
class Componente {
private:
    T Dato;
    int Ren, Col;
public:
    Componente();
    Componente(T, int , int);
    friend class MatPocoDen<T>;
    template <class M>
    friend istream &operator>>(istream &, Componente<M> &);
    template <class M>
    friend ostream &operator<<(ostream &, Componente<M> &);
};

/* Declaración del método constructor por omisión. */
template <class T>
Componente<T>::Componente(){}

/* Declaración del método constructor con parámetros. */
template <class T>
Componente<T>::Componente(T Valor, int Re, int Co)
{
    Dato= Valor;
    Ren= Re;
    Col= Co;
}

/* Declaración de la función amiga que sobrecarga el operador >>. */
template <class T>
istream &operator>>(istream &Lee, Componente<T> &Com)
{
    cout << "\n\nIngrese el valor: ";
    Lee >> Com.Dato;
    cout << "\n\nIngrese el numero del renglon que le corresponde: ";
    Lee >> Com.Ren;
    cout << "\n\nIngrese el número de la columna que le corresponde: ";
    Lee >> Com.Col;
    return Lee;
}

/* Declaración de la función amiga que sobrecarga el operador <<. */
template <class T>
ostream &operator<<(ostream &Escribe, Componente<T> &Com)
{
    Escribe << Com.Dato << " ";
    return Escribe;
}

/* Plantilla de la clase correspondiente a una matriz poco densa, 
almacenada por medio de un arreglo unidimensional de objetos. Los 
atributos son la colección de componentes formados por el valor diferente 
de cero, el renglón y la columna que le corresponden en la matriz 
original. Además, se guardan el total de renglones y de columnas que 
tiene la matriz original y el total de elementos diferentes de cero.*/
template <class T>
class MatPocoDen {
private:
    Componente<T> Valores[30];
    int TotRen, TotCol, TotVal;
public:
    MatPocoDen();
    void Lectura();
    T SumaRen(int Renglon);
    T MaxCol(int Colum);
    void Imprime();
    T SumaCol(int Colum);
};

/* Declaración del método constructor por omisión. */
template <class T>
MatPocoDen<T>::MatPocoDen()
{
    TotVal= 0;
}

/* Método que lee los datos de la matriz que son distintos de cero,
junto con el renglón y la columna que le corresponde en la matriz
original. Los valores leidos se van guardando en un arreglo
unidimensional. */
template <class T>
void MatPocoDen<T>::Lectura()
{
    int IndRen, IndCol, Resp;
    T Dato;
    do {
        cout << "\n\nIngrese total de renglones y columnas de la matriz\n";
        cin >> TotRen >> TotCol;
    } while (TotRen <= 0 || TotCol <= 0);
    
    cout << "\n\nIngrese 1 si desea capturar datos, 0 para terminar. \n";
    cin >> Resp;

    while (Resp)
    {
        cout<<"\n\nIngrese los datos diferentes de 0 (o vacio).\n";
        cin>>Dato;
        do {
            cout << "\nQue renglon le corresponde - de 0 a " << TotRen << ": ";
            cin >> IndRen;
        } while (IndRen < 0 || IndRen >= TotRen);
        
        do {
            cout << "\nQue columna le corresponde - de 0 a " << TotCol << ": ";
            cin >> IndCol;
        } while (IndCol < 0 || IndCol >= TotCol);

        Componente<T> Elemento(Dato, IndRen, IndCol);
        Valores[TotVal]= Elemento;
        TotVal++;
        cout << "\n\nIngrese 1 si desea capturar mas datos, 0 para terminar. \n";
        cin >> Resp;
    }
}

/* Método que realiza la suma de los elementos de un renglón de una 
matriz poco densa almacenada en un arreglo unidimensional. Recibe como 
parámetro el renglón a sumar y da como resultado la suma del mismo. */
template <class T>
T MatPocoDen<T>::SumaRen(int Renglon)
{
    T Suma= 0; int Indice;
    for (Indice= 0; Indice < TotVal; Indice++)
        if (Valores[Indice].Ren == Renglon)
            Suma= Suma + Valores[Indice].Dato;
            
    return Suma;
}

/* Método que encuentra el valor más grande de una columna de una matriz 
poco densa almacenada en un arreglo unidimensional. Recibe el número de 
la columna que interesa y regresa el máximo elemento de dicha columna. */
template <class T>
T MatPocoDen<T>::MaxCol(int Colum)
{
    T Maximo;
    int Indice, Band=1;
    for (Indice= 0; Indice < TotVal; Indice++) 
    {
        if (Valores[Indice].Col == Colum && Band) {
            Maximo= Valores[Indice].Dato;
            Band= 0;
        }
        else if (Valores[Indice].Col == Colum && Valores[Indice].Dato > Maximo) {
            Maximo= Valores[Indice].Dato;
        }
    }
    return Maximo;
}

/* Método que despliega en pantalla los valores diferentes de cero de la
matriz poco densa. */
template <class T>
void MatPocoDen<T>::Imprime()
{
    int Indice;
    cout<<"\n\nValores almacenados\n\n";
    for (Indice= 0; Indice < TotVal; Indice++)
        cout << Valores[Indice] << " ";
    cout << "\n\n\n";
}

/*
Método que suma los valores de una una columna
en una matriz poco densa
*/
template <class T>
T MatPocoDen<T>::SumaCol(int Colum)
{
    T Suma= 0; int Indice;
    for (Indice= 0; Indice < TotVal; Indice++)
        if (Valores[Indice].Col == Colum)
            Suma= Suma + Valores[Indice].Dato;
            
    return Suma;
}

class Arbol {
protected:
    int Edad;
    double Altura;
    char Nombre[64];
public:
    Arbol();
    void ModificaEdad(int);
    void ModificaAltura(float);
    friend istream &operator>>(istream &, Arbol &);
    friend ostream &operator<<(ostream &, Arbol &);
};

/* Declaración del método constructor por omisión. */
Arbol::Arbol()
{ }

/* Método que modifica la edad de un árbol. */
void Arbol::ModificaEdad(int NuevaE)
{
    Edad= NuevaE;
}

/* Método que modifica la altura de un árbol. */
void Arbol::ModificaAltura(float NuevaA)
{
    Altura= NuevaA;
}

/* Declaración de la función amiga donde se usa el operador >> 
sobrecargado. */
istream &operator>>(istream &Lee, Arbol &ObjArbol)
{
    cout << "\n\nIngrese nombre del arbol: ";
    Lee >> ObjArbol.Nombre;
    cout << "\n\nIngrese altura del arbol: ";
    Lee >> ObjArbol.Altura;
    cout << "\n\nIngrese edad en numero de anios del arbol: ";
    Lee >> ObjArbol.Edad;
    return Lee;
}

/* Declaración de la función amiga donde se usa el operador << 
sobrecargado. */
ostream &operator<<(ostream &Escribe, Arbol &ObjArbol)
{
    cout << "\n\nDatos del arbol: " << endl;
    Escribe << "Nombre: " << ObjArbol.Nombre << endl;
    Escribe << "Altura: " << ObjArbol.Altura << endl;
    Escribe << "Edad: " << ObjArbol.Edad << endl;

    return Escribe;
}

/* Función principal en la que se hace uso de las clases definidas para 
la representación de la matriz poco densa. */
void usaMatPocoDensa()
{
    MatPocoDen<int> Matriz1;
    Matriz1.Lectura();
    Matriz1.Imprime();
    MatPocoDen<Arbol> Matriz2;
    Matriz2.Lectura();
    Matriz2.Imprime();

}
