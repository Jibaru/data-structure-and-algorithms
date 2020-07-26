#include <iostream>
using namespace std;
/* Versión de la función Potencia para trabajar con números enteros. */
int Potencia (int Num, int Pot)
{
    int Indice, Res= 1;
    for (Indice= 1; Indice <= Pot; Indice++)
        Res= Res * Num; 
        
    return Res;
}
/* Versión de la función Potencia para trabajar con números de doble 
precisión. */
double Potencia (double Num, int Pot)
{
    double Res= 1; 
    int Indice;
    for (Indice= 1; Indice <= Pot; Indice++)
        Res= Res * Num;
    return Res;
}

/* Función que utiliza las funciones sobrecargadas previamente definidas. */
void UsaFuncionesSobrecargadas()
{
    int Base1, Expo1, Expo2; double Base2;
    cout << "Ingrese base y exponente - ambos numeros enteros - \n ";
    cin >> Base1 >> Expo1;

    /* Se invoca a la función Potencia con un número entero como primer 
    parámetro, por lo tanto se ejecutará la primera versión presentada y 
    se obtendrá un número entero como resultado. */
    cout << "\n\nEl resultado es: " << Potencia(Base1, Expo1) << endl;
    cout << "Ingrese base y exponente - la base puede ser un valor de doble precision - \n";
    cin >> Base2 >> Expo2;
    /* Se invoca a la función Potencia con un número de doble precisión 
    como primer parámetro, por lo tanto se ejecutará la segunda versión 
    presentada y se obtendrá un número de doble precisión como resultado. */
    cout << "\n\nEl resultado es: "<< Potencia(Base2, Expo2);
}

int main() {
    UsaFuncionesSobrecargadas();
    return 0;
}