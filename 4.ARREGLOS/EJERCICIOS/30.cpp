/*
30.	Considere que los siguientes datos representan los costos de boletos de 
avión entre ciudades. Cuando no existe vuelo directo entre dos ciudades aparece 
un cero, y los valores de la diagonal principal no se toman en cuen¬ta ya que no 
hay vuelos de una ciudad a sí misma. Por ejemplo, en la si¬guiente figura, se 
representó que ir de la ciudad 0 a la ciudad 1 cuesta $1,000 (lo mismo de la 1 a la 0) 
y que ir de la ciudad 2 a la 3 cuesta $2,050 (lo mismo de la 3 a la 2). Además, no hay 
vuelo de la ciudad 1 a la 3.

-	    1000	 890    720
1000	   -    1250	  0
890	    1250	   -   2050
720	       0	2050	  -

Escriba un programa en C++ que, por medio de menús, permita realizar las siguientes 
operaciones. Utilice la plantilla del problema anterior.
a)	Dado un número que identifica a una ciudad (proporcionado por el usuario), 
genere un reporte de todas las ciudades destinos a las que se puede llegar a partir de dicha ciudad.
b)	Dado un número que identifica a una ciudad origen y otro que identifi¬ca a una 
ciudad destino (ambos proporcionados por el usuario) indique si hay vuelo directo entre 
ambas ciudades, y si es así, su costo.
c)	Genere un reporte de todas las ciudades entre las que no existen vuelos directos. 

*/
#include "29.cpp"
#include <conio.h>

int menuOpciones()
{
    int opc;
    do {
        cout << "1-Ver destinos por posicion ciudad" << endl;
        cout << "2-Ver si existe vuelo entre dos ciudades, y su costo si existe" << endl;
        cout << "3-Reporte de ciudades en las que no hay vuelos directos" << endl;
        cout << "4-Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> opc;
    } while(opc < 1 || opc > 4);

    return opc;
}

int main()
{
    float arrCostos[10] = {0, 1000, 0, 890, 1250, 0, 720, 0, 2050, 0};
    MatrizSimetrica<float> costos = MatrizSimetrica<float>(arrCostos, 10, 4);
    int opc, pos, posDestino;
    float dato;
    costos.ImprimeMatriz();

    do {
        opc =menuOpciones();

        switch(opc) {
            case 1: {
                cout << "Ingrese posicion: ";
                cin >> pos;
                for(int i = 0; i < 4; i++) {
                    float dato = *costos.regresaDato(pos, i);
                    if(dato != 0) {
                        cout << "Destino ciudad " << pos 
                             << " hacia ciudad " << i 
                             << " con costo: " << dato << endl;
                    }
                }
                break;
            }
        
            case 2: {
                cout << "Ingrese posicion ciudad origen: ";
                cin >> pos;
                cout << "Ingrese posicion ciudad destino: ";
                cin >> posDestino;
                float dato = *costos.regresaDato(pos, posDestino);
                if(dato != 0) {
                    cout << "Destino ciudad " << pos 
                            << " hacia ciudad " << posDestino 
                            << " con costo: " << dato << endl;
                } else {
                    cout << "No existe vuelo" << endl;
                }
                break;
            }

            case 3: {
                cout << "Origen y destino donde no hay vuelos" << endl;
                for(int i = 0; i < 4; i++) {
                    for(int j = 0; j < 4; j++) {
                        float dato = *costos.regresaDato(i, j);
                        if(dato == 0) {
                            cout << "Destino ciudad " << i 
                                << " hacia ciudad " << j << endl;
                        }
                    }
                }
                break;
            }

            case 4: {
                cout << "Fin del programa" << endl;
                break;
            }
        }
        getch();
    } while(opc != 4);

    return 0;
}