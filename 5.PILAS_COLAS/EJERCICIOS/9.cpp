/*
9.	Defina la plantilla de la clase DobleCola, de acuerdo a las 
especificaciones que se dan a continuación.
DobleCola(T)
Frente, Final: int
EspaDobleCola[MAX]: T
Constructor
int Insertalzq(T)
int InsertaDer(T)
int Eliminalzq(T)
int EliminaDer(T)
int DobleColaLlena()
int DobleColaVacia()

*/
#include <iostream>
using namespace std;
#define MAX 10

template <class T>
class DobleCola {
private:
	T EspaDobleCola[MAX];
	int Frente, Final;
public:
	DobleCola();
	int InsertaIzq(T);
	int InsertaDer(T);
	int EliminaIzq(T*);
	int EliminaDer(T*);
	int DobleColaLlena();
	int DobleColaVacia();
	void ImprimeDatos();
};

template <class T>
DobleCola<T>::DobleCola()
{
	Frente = -1;
	Final = -1;
}

/*
Metodo de insercion clásico :v
*/
template <class T>
int DobleCola<T>::InsertaDer(T dato)
{
	int Resp = 0;
	if(Final < (MAX - 1)) {
		Resp= 1;
		Final++;
        EspaDobleCola[Final]= dato;
        if (Final == 0) {
			Frente = 0;
		}
	}
	return Resp;
}

/*
Metodo de insercion por la izquierda
Es necesario que halla espacio antes del "Frente"
para poder agregar elementos. En caso de estar vacía
se agrega como si fuese por la derecha
*/
template <class T>
int DobleCola<T>::InsertaIzq(T dato)
{
	int Resp = 0;
	if(Frente > 0) {
		Resp= 1;
		Frente--;
        EspaDobleCola[Frente]= dato;
	} else if(DobleColaVacia() == 1) {
		Resp = InsertaDer(dato);
	}
	return Resp;
}

/*
Metodo que elimina un dato por la izquierda, clásico
*/
template <class T>
int DobleCola<T>::EliminaIzq(T* dato)
{
	int Resp= 0;
    if (!DobleColaVacia())
    {
        Resp= 1;
        *dato= EspaDobleCola[Frente];
        
        if (Frente == Final)
        {
            Frente= -1;
            Final= -1;
        } else {
			Frente++;
		}
    }

    return Resp;
}

/*
Metodo que elimina un dato por la derecha
*/
template <class T>
int DobleCola<T>::EliminaDer(T* dato)
{
	int Resp= 0;
    if (!DobleColaVacia())
    {
        Resp= 1;
        *dato= EspaDobleCola[Final];
        
        if (Frente == Final)
        {
            Frente= -1;
            Final= -1;
        } else {
			Final--;
		}
    }

    return Resp;
}

template <class T>
int DobleCola<T>::DobleColaVacia()
{
	if(Frente == Final == -1) {
		return 1;
	}
	return 0;
}

template <class T>
int DobleCola<T>::DobleColaLlena()
{
	if (Frente == 0 && Final == (MAX - 1))
	{
		return 1;
	}
	return 0;
}

template <class T>
void DobleCola<T>::ImprimeDatos()
{
	for(int i = Frente; i <= Final; i++) {
		cout << EspaDobleCola[i];
		if(i < Final){
			cout << " <-> ";
		}
	}
}

void usaDobleCola()
{
	DobleCola<int> dobleCola = DobleCola<int>();
	int eliminado;
	
	dobleCola.InsertaDer(1);
	dobleCola.InsertaDer(12);
	dobleCola.InsertaDer(10);
	dobleCola.InsertaDer(-2);

	cout << "\nDoble cola inicial: ";
	dobleCola.ImprimeDatos();
	
	if(dobleCola.EliminaIzq(&eliminado) == 1) {
		cout << "\nDato eliminado por izq: " << eliminado;
	}
	
	cout << "\nDoble cola actual: ";
	dobleCola.ImprimeDatos();
	
	dobleCola.InsertaIzq(91);
	
	cout << "\nDoble cola con insercion por izq: ";
	dobleCola.ImprimeDatos();

	if(dobleCola.EliminaDer(&eliminado) == 1) {
		cout << "\nDato eliminado por der: " << eliminado;
	}
	
	cout << "\nDoble cola actual: ";
	dobleCola.ImprimeDatos();
	
	dobleCola.InsertaDer(7);
	
	cout << "\nDoble cola con insercion por der: ";
	dobleCola.ImprimeDatos();
}

int main()
{
	usaDobleCola();
	return 0;
}