/*
4.	Escriba un programa en C++ que invierta los elementos almacenados
en una pila. Puede usar cualquier estructura de datos como auxiliar.
Observe la siguiente figura: 
Pila Dato:          Pila Resultado:
Tope -> [ 623]      [ 928] <- Tope
        [1024]      [3209]
        [3209]      [1024]
        [ 928]      [ 623]
*/
#include "../EJEMPLOS/5.1.cpp"

template <class T>
void inviertePila(Pila<T>& pila)
{
	T dato;
	Pila<T> aux = pila;
	
	// vaciar la pila
	while(pila.PilaVacia() != 1) {
		pila.Pop(&dato);
	}
	
	// agregar los elementos de aux en la pila
	while(aux.PilaVacia() != 1) {
		aux.Pop(&dato);
		pila.Push(dato);
	}
}

void UsaPilaEjercicio4() 
{
	Pila<int> pila = Pila<int>();
	
	pila.Push(928);
	pila.Push(3209);
	pila.Push(1024);
	pila.Push(623);
	
	cout << "\nPila: " << endl;
	pila.ImprimeDatos();
	
	inviertePila(pila);
	
	cout << "\nPila invertida: " << endl;
	pila.ImprimeDatos();
	
}

int main()
{
	UsaPilaEjercicio4();
	return 0;
}