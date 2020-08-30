/*
3.	Escriba un programa en C++ que elimine los elementos repetidos de 
una pila. Suponga que si existen elementos repetidos, los mismos se 
encuentran en posiciones consecutivas. Puede usar cualquier estructura 
de datos como auxiliar. Observe la siguiente figura:
Pila Dato:          Pila Resultado:
Tope -> [ 879]      [ 879] <- Tope
        [1285]      [1285]
        [1285]      [1500]
        [1285]      [ 450]
        [1500]
        [ 450]
        [ 450]
*/
#include "../EJEMPLOS/5.1.cpp"

template <class T>
void eliminaRepetidosConsecutivos(Pila<T>& pila)
{
	T anterior = 0;
	Pila<T> aux = Pila<T>();
	while(pila.PilaVacia() != 1) {
		T dato;
		pila.Pop(&dato);
		if(dato != anterior) {
			aux.Push(dato);
		}
		anterior = dato;
	}
	
	while(aux.PilaVacia() != 1) {
		T dato;
		aux.Pop(&dato);
		pila.Push(dato);
	}
}

void UsaPilaEjercicio3() 
{
	Pila<int> pila = Pila<int>();
	
	pila.Push(450);
	pila.Push(450);
	pila.Push(1500);
	pila.Push(1285);
	pila.Push(1285);
	pila.Push(1285);
	pila.Push(879);
	
	cout << "\nPila: " << endl;
	pila.ImprimeDatos();
	
	eliminaRepetidosConsecutivos(pila);
	
	cout << "\nPila sin repetidos consecutivos: " << endl;
	pila.ImprimeDatos();
	
}

int main()
{
	UsaPilaEjercicio3();
	return 0;
}