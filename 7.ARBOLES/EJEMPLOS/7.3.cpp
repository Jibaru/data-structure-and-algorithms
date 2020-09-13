/* Este programa es para almacenar un conjunto de productos (ordenados 
por clave), utilizando un árbol binario de búsqueda. Además, se pueden 
eliminar y buscar productos ya registrados y generar un reporte con la 
información de todos los productos. La biblioteca "Productos.h" tiene 
la clase Producto utilizada en el programa 6.2. Por su parte, la 
biblioteca "ArbolBinBusqueda.h" contiene la plantilla de la clase 
ArbolBinBus del programa 7.2. */
#include <iostream>
#include <conio.h>
#include "../../lib/clases/Producto.h"
#include "../../lib/arboles/ArbolBinBusqueda.h"

using namespace std;

/* Función que despliega al usuario las opciones de trabajo. Regresa la 
opción seleccionada. */
int Menu()
{
int Opcion;
    do {
        cout << "\n\n\n\tOpciones de trabajo:\n";
        cout << "\t1 .Ingresar nuevo producto.\n";
        cout << "\t2.Dar de baja un producto.\n";
        cout << "\t3.Reporte de todos los productos ordenados por clave.\n";
        cout << "\t4.Buscar un producto por clave.\n";
        cout << "\t5.Terminar el proceso.\n\n";
        cout << "\tIngrese opcion seleccionada: ";
        cin >> Opcion ;
    } while(Opcion < 1 || Opcion > 5);
    
    return Opcion;
}

/* Función principal desde la cual se controla la ejecución de las 
operaciones seleccionadas por el usuario. */
int main()
{
    ArbolBinBus<Producto> Inventario;
    NodoArbol<Producto> *Ap1, *Ap2;
    Producto Prod;
    int Opc, Cla;
    do {
        Opc= Menu();
        switch (Opc) {
            /* Se registra un nuevo producto. No se aceptan productos con 
            claves repetidas. */
            case 1: {
                cin >> Prod;
                Ap1= Inventario.RegresaRaiz();
                Inventario.InsertaNodoSinRep(Ap1, Prod);
                break;
            }
            /* Se elimina un producto ya registrado. */
            case 2:{
                cout << "\n\nIngrese la clave del producto a eliminar: ";
                cin >> Cla;
                Producto Prod(Cla, "", 0);
                Ap1= Inventario.RegresaRaiz();
                Inventario.EliminaNodo(Ap1, Prod); break;
            }
            /* Con el método Inorden se genera un reporte de todos los 
            productos ordenados por clave. */
            case 3:{
                Ap1= Inventario.RegresaRaiz();
                cout << " \n\n\n---------------------------------\n\n";
                cout << "PRODUCTOS EN INVENTARIO\n\n";
                cout << "---------------------------------\n";
                Inventario.Inorden(Ap1);
                break;
            }
            /* Se busca un elemento por su clave. Si ya está registrado 
            entonces se despliegan todos sus datos. En caso contrario, 
            sólo un mensaje informativo. */
            case 4: {
                cout << "\n\nIngrese la clave del producto a buscar: ";
                cin >> Cla;
                Producto Prod(Cla, "", 0);
                Ap1= Inventario.RegresaRaiz();
                Ap2= Inventario.Busqueda(Ap1, Prod); if (Ap2)
                {
                    Prod = Ap2->RegresaInfo();
                    cout << "\n\n\nExiste un producto registrado con esa clave. \n";
                    cout << Prod;
                }
                else
                    cout<<"\n\nNo se ha registrado ningun producto con esa clave. \n";
                break;
            }
            case 5: {
                cout << "\n\n\nFIN DEL PROCESO.\n\n\n";
                break;
            }
        }
            getch();
    } while (Opc >= 1 && Opc <= 5);

    return 0;
}
