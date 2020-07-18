/*
14.	Retome el problema anterior y utilice la clase Cubo para definir cajas de cartón, en forma de cubo. 
Escriba un programa que calcule e imprima el total de pliegos de cartón que serán necesarios para 
fabricar un total de N (1 < N < 20) cajas. Las cajas pueden ser de diferentes tamaños. El programa 
además de calcular el total de pliegos, deberá calcular el desperdicio de papel. Datos: N, tamaño de 
cada caja (considere 1/2 cm para pegar los diferentes lados de cada cara del cubo) y tamaño del pliego 
de cartón.

*/

#include <iostream>
#include "13.cpp"

#define EXTRA 0.5

using namespace std;

float calcularCartonUsado(Cubo &c){
	return c.area() + (0.5 + c.obtenerLado())* 6;
}

int main(){
	
	int N = 4, totalPliegos;
	float areaPliego = 50, areaUsada = 0;

	for(int i = 0; i < N; i++){
		Cubo cubo((float)i+5, "carton");
		areaUsada += calcularCartonUsado(cubo);
	}

	cout << "Total de pliegos: " << ((int)areaUsada/areaPliego )<< endl;
	cout << "Area usada: " << areaUsada << endl;

	return 0;
}

