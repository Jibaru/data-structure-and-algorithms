/* Este programa muestra el uso de las listas para almacenar y recuperar 
información. En este caso se ofrecen opciones de trabajo al usuario para 
guardar, eliminar o consultar datos de un cierto producto, asi como 
generar un reporte con los datos de todos los productos almacenados
hasta el momento. Para evitar la repetición de código se incluyen las 
bibliotecas "ListasSimLig.h" y "Productos.h”. La primera corresponde a 
la plantilla de la clase Lista presentada en el programa 6.1 y la 
segunda a la clase Producto presentada en el programa 6.2. */

#include <iostream>
#include <conio.h>
#include "../../lib/listas/ListasSimLig.h"
#include "../../lib/clases/Producto.h"

using namespace std;

/* Función auxiliar que presenta al usuario las diferentes opciones de 
trabajo. */
int Menu()
{
    int Opc;
    cout << "\n\nBienvenido al sistema de registro de productos.\n\n";
    cout << "\n(1) Registrar un nuevo producto.\n";
    cout << "\n(2) Dar de baja un producto.\n";
    cout << "\n(3) Verificar si un producto ya fue registrado. \n";
    cout << "\n(4) Imprimir la lista de productos registrados. \n";
    cout << "\n(5) Salir.\n";
    cout << "\n\nIngrese opcion de trabajo:\n";
    cin >> Opc;
    
    return Opc;
}

/* Función principal. Se declara un objeto de tipo Lista, el cual 
servirá para llevar a cabo las operaciones de almacenamiento, consulta 
eliminación de información relacionada a productos. */
int main()
{
    Lista<Producto> ListaProds;
    Producto ObjProd;
    NodoLista<Producto> *Apunt;
    int Opc, Res, Clave;

    Opc= Menu();
    while (Opc >= 1 && Opc <= 4)
    {
        /* Selección de la operación a realizar considerando la opción 
        elegida por el usuario. */
        switch (Opc)
        {
            /* Los productos se guardan en la lista ordenados de manera 
            creciente, según su clave. */
            case 1: {
                cout << "\n\nIngrese datos del producto a registrar:\n";
                cin >> ObjProd;
                ListaProds.InsertaOrdenCrec(ObjProd);
                break;
            }
            case 2: {
                cout << "\n\nIngrese la clave del producto a eliminar: ";
                cin >> Clave;
                /* Se solicita sólo la clave del producto, ya que la 
                búsqueda se hace tomando en cuenta este atributo que 
                es el que lo identifica. */
                Producto Produc(Clave,"", 0);
                Res= ListaProds.EliminaUnNodo(Produc);
                switch (Res)
                {
                    case 1: cout << "\n\nEl producto ya fue eliminado.\n"; break;
                    case 0: cout << "\n\nEse producto no se encuentra registrado.\n"; break;
                    case -1: cout << "\n\nNo hay productos registrados.\n"; break;
                }
                break;
            }
            case 3: {
                cout << "\n\nIngrese la clave del producto a buscar:\n";
                cin >> Clave;
                /* Se solicita sólo la clave del producto, ya que la 
                búsqueda se hace tomando en cuenta este atributo que 
                es el que lo identifica. */
                Producto Produc(Clave,"",0);
                Apunt= ListaProds.BuscaOrdenada(Produc);
                if (!Apunt)
                    cout << "\n\nEse producto no esta registrado.\n\n";
                else
                {
                    cout << "\n\nEse producto esta registrado.\n";
                    ListaProds.ImprimeUnNodo(Apunt);
                }
                break;
            }
        
            case 4: {
                ListaProds.ImprimeRecursivo(ListaProds.RegresaPrimero());
                break;
            }
        }

        getch();

        Opc= Menu();

    }

    return 0;
}
