/*
8.	Se tienen 3 arreglos paralelos: el primero almacena las claves de 20 productos,
ordenadas crecientemente; el segundo guarda la existencia de cada uno de ellos, y el
tercero almacena el precio de venta de los mismos. Escriba un programa completo en C++
que permita:
a)	Consultar: 
    a.1) El producto con mayor existencia,
    a.2) El producto con mayor precio de venta. En ambos casos el programa debe imprimir 
    todos los datos del producto que cumpla con la condición buscada.
b)	Actualizar:
    b.1) La existencia de un producto (si se venden algunas unidades o se compran más).
    Los datos de entrada son la clave del producto, una clave de operación (para indicar 
    si es venta o compra) y la cantidad vendida/comprada.
    b.2) El precio de venta de un producto. Los datos de entrada son la clave del producto 
    y el nuevo precio de venta.
c)	Eliminar: un producto. El dato de entrada es la clave.
*/

#include "../EJEMPLOS/4.5.cpp"
#include <conio.h>

int MenuOpciones()
{
    int Opc;
    do {
        cout << "\n1-Captura inicial de claves, existencias y precios de venta de productos. ";
        cout << "\n2-Producto con mayor existencia.";
        cout << "\n3-Producto con mayor precio de venta.";
        cout << "\n4-Actualizar existencia de un producto. ";
        cout << "\n5-Actualizar el precio de venta de un producto. ";
        cout << "\n6-Ver todos.";
        cout << "\n7-Terminar el proceso. ";
        cout << "\n\nIngrese la opcion seleccionada. ";
        cin >> Opc;
    } while (Opc < 1 || Opc > 7);
    
    return Opc;
}

int main() {

    ArreParal<int> Claves = ArreParal<int>();
    ArreParal<float> Precios = ArreParal<float>();
    ArreParal<int> Existencias = ArreParal<int>();

    int Opc, ClaveProd, ExistenciaProd, AdicionExistencia, Pos, TipoOperacion, TotalProd;
    float PrecioProd;

    do {
        Opc= MenuOpciones();

        switch(Opc) {

            case 1: {
                cout << "\n\nDe el numero de claves y cada una de las claves\n";
                cin >> Claves;
                cout << "\n\nDe el numero de precios y cada una de ellos \n";
                cin >> Precios;
                cout << "\n\nDe el numero de existencias y cada uno de ellos \n";
                cin >> Existencias;
                break;
            }
            
            case 2: {
                ExistenciaProd = Existencias.MayorValor();
                Pos = Existencias.BuscaOrdenado(ExistenciaProd);

                cout << "\nEl Producto con mayor precio de venta es: " << endl;
                cout << "Clave: " << Claves.RegresaValor(Pos) << endl;
                cout << "Existencia: " << ExistenciaProd << endl;
                cout << "Precio venta: " << Precios.RegresaValor(Pos) << endl;
                break;
            }

            case 3: {
                PrecioProd = Precios.MayorValor();
                Pos = Precios.BuscaOrdenado(PrecioProd);

                cout << "\nEl Producto con mayor precio de venta es: " << endl;
                cout << "Clave: " << Claves.RegresaValor(Pos) << endl;
                cout << "Existencia: " << Existencias.RegresaValor(Pos) << endl;
                cout << "Precio venta: " << PrecioProd << endl;
                break;
            }

            case 4: {
                cout << "\nIngrese clave del producto: ";
                cin >> ClaveProd;
                Pos = Claves.BuscaOrdenado(ClaveProd);
                if(Pos >= 0) {

                    cout << "\nIngrese tipo de operacion (1. Venta, 2.Compra): ";
                    cin >> TipoOperacion;

                    if(TipoOperacion == 1) {
                        cout << "\nCantidad vendida: ";
                        cin >> AdicionExistencia;

                        ExistenciaProd = Existencias.RegresaValor(Pos);

                        Existencias.ActualizaValor(Pos, ExistenciaProd - AdicionExistencia);
                    } else if(TipoOperacion == 2) {
                        cout << "\nCantidad comprada: ";
                        cin >> ExistenciaProd;
                        ExistenciaProd = Existencias.RegresaValor(Pos);

                        Existencias.ActualizaValor(Pos, ExistenciaProd + AdicionExistencia);
                    } else {
                        cout << "\nOperacion incorrecta" << endl;
                    }

                } else {
                    cout << "\nNo hay registrado un producto con dicha clave" << endl;
                }
                break;
            }

            case 5: {
                cout << "\nIngrese clave del producto: ";
                cin >> ClaveProd;
                Pos = Claves.BuscaOrdenado(ClaveProd);
                if(Pos >= 0) {

                    cout << "\nIngrese nuevo precio: ";
                    cin >> PrecioProd;

                    Precios.ActualizaValor(Pos, PrecioProd);

                } else {
                    cout << "\nNo hay registrado un producto con dicha clave" << endl;
                }
                break;
            }

            case 6: {
                TotalProd= Claves.RegresaTamano();
                cout << "\n\nClave\tPrecio\tExistencias\n";
                for (int i= 0; i < TotalProd; i++)
                {
                    cout << Claves.RegresaValor(i) << "\t" ;
                    cout << Precios.RegresaValor(i) << "\t";
                    cout << Existencias.RegresaValor(i) << "\t\n";
                }
                break;
            }

            case 7: {
                cout << "\n\nTermina el procesamiento de los datos. \n\n";
                break;
            }

        }

        getch();

    } while(Opc != 7);

    return 0;

}