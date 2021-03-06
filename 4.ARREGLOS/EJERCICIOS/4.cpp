/*
4.	Escriba un programa que, utilizando la plantilla vista para arreglos desordenados,
almacene las calificaciones de un grupo de N (1< N < 80) alumnos. Las calificaciones 
serán números reales comprendidos entre 0 y 10. A partir de los datos guardados en el
arreglo, su programa debe realizar las siguientes operaciones. Puede agregar métodos a
la plantilla de la clase arreglo, si lo cree necesario.
a)	Imprimir la calificación más alta, la más baja y el promedio de las mismas.
b)	 Obtener e imprimir el total de calificaciones menores a 6.
c)	 Obtener e imprimir el total de calificaciones mayores a 8.5.

*/

#include <iostream>
using namespace std;

/* Se define una constante que representa el número máximo de elementos 
que puede almacenar el arreglo. */
#define MAX 100

template <class T>
class Arreglo {
private:
    T Datos[MAX]; 
    int Tam; 
public:
    Arreglo();
    void Lectura();
    int InsertaDesordenado(T);
    int EliminaDesordenado(T);
    int BuscaDesordenado(T);
    void Escribe();
	void ImprimirMax();
	void ImprimirMin();
	void ImprimirPromedio();
	int TotalMenoresA(T valor);
	int TotalMayoresA(T valor);
};

/* Declaración del método constructor. Inicializa el número actual de 
elementos en 0. */
template <class T>
Arreglo<T>::Arreglo()
{
    Tam= 0;
}
/* Método para la lectura de los atributos del arreglo. */
template <class T>
void Arreglo<T>::Lectura()
{
    int Indice;

    /* Lectura del número de elementos a guardar en el arreglo. Se 
    verifica que el valor dado por el usuario sea menor o igual que 
    el máximo permitido y mayor o igual que 1. */
    do {
        cout << "\n\n Ingrese total de elementos: ";
        cin >> Tam;
    } while (Tam < 1 || Tam > MAX);

    /* Lectura de valores para cada una de las Tam casillas del arreglo. */
    for (Indice= 0; Indice < Tam; Indice++){
        cout << "\nIngrese el " << Indice + 1 << " dato: ";
        cin >> Datos[Indice];
    }

}
/* Método que inserta el elemento Valor en el arreglo. En esta implementación 
no se aceptan elementos repetidos. Se usa un método auxiliar, BuscaDesordenado(), 
el cual da como resultado la posición en la cual encontró el elemento, o un número
negativo en caso contrario. Si la inserción se lleva a cabo, se incrementa a Tam. 
Este método da acornó resultado uno de tres posibles valores: 1 si Valor se insertó 
en el arreglo, 0 si el arreglo está lleno y -1 si Valor ya está en el arreglo. */
template <class T>
int Arreglo<T>::InsertaDesordenado(T Valor)
{
    int Posic, Resultado= 1;

    if (Tam < MAX) {
        Posic= BuscaDesordenado(Valor);
        if (Posic < 0)
            Datos[Tam++]= Valor;
        else
            Resultado= -1;
    } else {
        Resultado= 0;
    }

    return Resultado;
}

/* Método que elimina el elemento Valor del arreglo. Para ello usa un 
método auxiliar, BuscaDesordenadof), el cual busca a Valor en el 
arreglo y regresa su posición, si lo encuentra. En caso contrario, 
regresa un número negativo. Este método da como resultado uno de tres 
posibles valores: 1 si Valor se elimina del arreglo, 0 si el arreglo 
está vacio y -1 si Valor no está en el arreglo. Si la eliminación se 
lleva a cabo, se decrementa a Tam. */ 
template <class T>
int Arreglo<T>::EliminaDesordenado(T Valor)
{
    int Indice, Posic, Resultado= 1;
    if (Tam > 0) {
        Posic= BuscaDesordenado(Valor);
        if (Posic < 0)
            Resultado= -1;
        else {
            Tam--;
            for (Indice= Posic; Indice < Tam; Indice++)
                Datos[Indice]= Datos[Indice+1];
        }
    }
    else
        Resultado= 0;

    return Resultado;
}

/* Método que busca sesencialmente el elemento Valor en el arreglo. 
Recibe como parámetro el dato buscado y da como resultado, si lo 
encuentra, el número de casilla donde fue encontrado. En caso contrario 
da un número negativo.*/
template <class T>
int Arreglo<T>::BuscaDesordenado(T Valor)
{
    int Indice= 0, Resultado= -1;
    while ((Indice < Tam) && (Datos[Indice] != Valor))
        Indice++;
    
    if (Indice < Tam)
        Resultado= Indice;
        
    return Resultado;
}

/* Método que despliega los valores almacenados en las casillas del
arreglo. */
template <class T>
void Arreglo<T>::Escribe()
{
    int Indice;
    if (Tam > 0)
    {
        cout << "\n\n";
        for (Indice= 0; Indice < Tam; Indice++)
        cout << "\t" << Datos [Indice];
        cout << "\n\n";
    }
    else
        cout << "\n No hay elementos almacenados.";
}

template <class T>
void Arreglo<T>::ImprimirMax()
{
	T max;
	max = Datos[0];
	for(int i = 1; i < Tam; i++){
		if(max < Datos[i])
			max = Datos[i];
	}
	
	cout << "El maximo es: " << max << endl;
}

template <class T>
void Arreglo<T>::ImprimirMin()
{
	T mini;
	mini = Datos[0];
	
	for(int i = 1; i < Tam; i++){
		if(mini > Datos[i])
			mini = Datos[i];
	}
	
	cout << "El minimo es: " << mini << endl;
}

template <class T>
void Arreglo<T>::ImprimirPromedio()
{
	T sum;
	sum = Datos[0];
	
	for(int i = 1; i < Tam; i++)
		sum = sum + Datos[i];
	
	cout << "El promedio es: " << sum / Tam << endl;
}

template <class T>
int Arreglo<T>::TotalMenoresA(T valor)
{
	int tot = 0;
	
	for(int i = 0; i < Tam; i++){
		if(valor > Datos[i]){
			tot++;
		}
	}
	
	return tot;
}

template <class T>
int Arreglo<T>::TotalMayoresA(T valor)
{
	int tot = 0;
	
	for(int i = 0; i < Tam; i++){
		if(valor < Datos[i]){
			tot++;
		}
	}
	
	return tot;
}

void usaArreglo()
{
	Arreglo<float> arr = Arreglo<float>();
	int i = 0, n;
	float valor;
	do {
		cout << "Ingrese cantidad de alumnos: ";
		cin >> n;
		
	} while (n <= 0 || n >= 80);
	
	while(i < n) {
		cout << "Ingrese valor " << i + 1 << ": ";
		cin >> valor;
		arr.InsertaDesordenado(valor);
		i++;
	}
	
	arr.ImprimirMax();
	arr.ImprimirMin();
	arr.ImprimirPromedio();
	cout << "Menores a 6: " << arr.TotalMenoresA(6) << endl;
	cout << "Mayores a 8.5: " << arr.TotalMayoresA(8.5) << endl;
}

int main()
{
	usaArreglo();
	return 0;
}