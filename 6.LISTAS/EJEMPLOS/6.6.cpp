#include <iostream>
#include <conio.h>
#include "../../lib/listas/ListasDobLig.h"
#include "../../lib/clases/Producto.h"

using namespace std;

/* Función auxiliar que despliega las opciones de trabajo del usuario. */
int Menu()
{
    int Opcion;
    do {
        cout << "\n\nBienvenido al sistema de inventario.\n\n";
        cout << "Opciones de trabajo:";
        cout << "\n (1) Registrar un producto (se hara en orden segun la relave).";
        cout << "\n (2) Dar de baja un producto.";
        cout << "\n (3) Generar un reporte en orden creciente por claves.";
        cout << "\n (4) Generar un reporte en orden decreciente por claves.";
        cout << "\n (5) Generar un reporte de productos cuyos precios esten en cierto rango.";
        cout << "\n (6) Promedio de precios de los productos registrados.";
        cout << "\n (7) Salir.";
        cout << "\n\nIngrese opcion elegida: ";
        cin >> Opcion;
        cout << "\n";
    } while (Opcion < 1 || Opcion > 7);

    return Opcion;
}

/* Función que genera un reporte con los datos de los productos en orden 
creciente. Para ello, considerando el orden en el cual fue creada la 
lista, la misma se recorre de izquierda a derecha empezando con el 
primer nodo. */
void ReporteCrec(ListaDobLiga<Producto> Inventario)
{
    cout << "\n\nLista de productos ordenados por clave de menor a mayor.\n";
    Inventario.ImprimeIzq_Der(Inventario.RegresaPrimero());
}

/* Función que genera un reporte con los datos de los productos en orden 
decreciente. Para ello, considerando el orden en el cual fue creada la 
lista, la misma se recorre de derecha a izquierda empezando con el 
último nodo. */
void ReporteDec(ListaDobLiga<Producto> Inventario) 
{
    cout << "\n\nLista de productos ordenados por clave de mayor a menor.\n";
    Inventario.ImprimeDer_Izq(Inventario.RegresaUltimo());
}

/* Función que genera un reporte con los datos de los productos cuyos 
precios se encuentran comprendidos en cierto rango. La función recibe 
como parámetro la lista de productos. */
void ReportePrecios(ListaDobLiga<Producto> Inventario)
{
    NodoDobleLiga <Producto> *Apunt;
    double PrecInf, PrecSup;
    cout << "\nIngrese el rango de precios que le interesa. \n";
    cout << "Limite Inferior: ";
    cin >> PrecInf;
    cout << "\nLimite Superior: ";
    cin >> PrecSup;
    Apunt= Inventario.RegresaPrimero();
    cout << "\n\nLista de productos cuyos precios son >= " << PrecInf 
         << " y <= " << PrecSup << "\n";
    
    while (Apunt)
    {
        if (Apunt->RegresaInfo().RegresaPrecio() >= PrecInf && 
            Apunt->RegresaInfo().RegresaPrecio() <= PrecSup )
                Inventario.ImprimeNodo(Apunt);

        Apunt= Inventario.RegresaVecinoDer(Apunt);
    }
}

/* Función que calcula el promedio de los precios de todos los productos 
registrados en el inventario. Recibe como parámetro la lista y da como 
resultado el promedio calculado.*/
double Promedio(ListaDobLiga<Producto> Inventario)
{
    NodoDobleLiga <Producto>*Apunt;
    Apunt= Inventario.RegresaPrimero();
    double Prom= 0;
    int Total= 0;
    while (Apunt)
    {
        Prom= Prom + Apunt->RegresaInfo().RegresaPrecio() ;
        Apunt= Inventario.RegresaVecinoDer(Apunt);
        Total= Total + 1;
    }
    if (Total)
        Prom= Prom/Total;
        
    return Prom;
}

/* Función principal. Invoca los diferentes métodos para que las 
operaciones elegidas por el usuario se puedan llevar a cabo. */
int main()
{
    ListaDobLiga<Producto> Inventario;
    Producto Produ;
    int Opcion, Clave, Resp;
    do {

        Opcion= Menu();
        /* Selección de acuerdo a la opción de trabajo elegida por el 
        usuario. */
        switch (Opcion)
        {
            case 1:{
                cout << "\nIngrese datos del producto a registrar.";
                cin >> Produ;
                Inventario.InsertaOrdenado(Produ);
                break;
            }
            case 2:{
                cout << "\nIngrese la clave del producto a eliminar. ";
                cin >> Clave;
                Producto Prod(Clave,"",0);
                Resp= Inventario.EliminaUnNodo(Prod);
                if (Resp == 1)
                    cout<< "\nBaja registrada.\n";
                else
                    if (Resp == -1)
                        cout << "\nNo hay productos registrados en inventario. \n";
                    else
                        cout << "\nNo hay producto registrado con la clave dada. \n";
                break;
            }
            case 3: ReporteCrec(Inventario); break;
            case 4: ReporteDec(Inventario); break;
            case 5: ReportePrecios(Inventario); break;
            case 6: {
                cout << "\n\n\nPromedio de precios: " << Promedio(Inventario);
                break;
            }
            case  7: break;
        }

        getch();

    } while (Opcion >= 1 && Opcion < 7);

    return 0;
}
