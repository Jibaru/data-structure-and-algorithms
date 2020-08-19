/*
7.	Utilice la plantilla de la clase ArreParal definida en este capítulo para declarar 
dos objetos: un arreglo de enteros y un arreglo de números reales. El primero permitirá 
almacenar las claves de un grupo de N productos (1< N < 30), ordenadas crecientemente, 
mientras que el segundo será para guardar los precios de dichos productos. Escriba un 
programa en C++ que, mediante un menú de opciones, permita al usuario:
a)	Leer y validar el número de productos.
b)	Leer la información correspondiente de cada uno de los N productos.
c)	Dada la clave de un producto, poder actualizar su precio.
d)	Dar de baja un producto.
e)	Dar de alta un nuevo producto.
f)	Imprimir las claves de todos los productos cuyos precios sean mayores a uno dado 
como referencia por el usuario.
*/

#include "../EJEMPLOS/4.5.cpp"
#include <conio.h>

int MenuOpciones()
{
    int Opc;
    do {
        cout << "\n1-(a)Captura inicial de claves y precios de productos. ";
        cout << "\n2-(b)Obtener un listado de claves y precios de todos los productos.";
        cout << "\n3-(c)Actualizar el precio de un producto.";
        cout << "\n4-(d)Eliminar un producto y su precio. ";
        cout << "\n5-(e)Ingresar un nuevo producto y su precio. ";
        cout << "\n6-(f)Imprimir las claves de todos los productos cuyos precios sean mayores a X";
        cout << "\n7-Terminar el proceso. ";
        cout << "\n\nIngrese la opcion seleccionada. ";
        cin >> Opc;
    } while (Opc < 1 || Opc > 7);
    
    return Opc;
}

int main ()
{
    ArreParal<int> Claves;
    ArreParal<float> Precios;
    
    int ClaProd, Opc, Posic, Indice, TotalProd;
    float PrecProd;

    do {
        Opc= MenuOpciones();
        switch (Opc)
        {
            case 1: {
                cout << "\n\nDe el numero de claves y cada una de las claves\n";
                cin >> Claves;
                cout << "\n\nDe el numero de precios y cada una de ellos \n";
                cin >> Precios;
                break ;
            }
            case 2: {
                TotalProd= Claves.RegresaTamano();
                cout << "\n\nClave Precio \n";
                for (Indice= 0; Indice < TotalProd; Indice ++)
                {
                    cout << Claves.RegresaValor(Indice) << " : " ;
                    cout << Precios.RegresaValor(Indice) << " \n";
                }
                break ;
            }

            case 3: {
                cout << "\n\nClave del producto que desea actualizar su precio: ";
                cin >> ClaProd;
                Posic= Claves.BuscaOrdenado(ClaProd);
                if (Posic >= 0)
                {
                    cout << "\nIngrese el nuevo precio para el producto: ";
                    cin >> PrecProd;
                    if(Precios.ActualizaValor(Posic, PrecProd) == 1) {
                        cout << "\nPrecio actualizado correctamente" << endl;
                    } else {
                        cout << "\nNo se pudo actualizar" << endl;
                    }
                }
                else
                    cout << "\n\nEsa clave no esta registrada. \n\n";
                break ;
            }

            case 4: {
                cout << "\n\nDe la clave del producto que desea dar de baja: ";
                cin >> ClaProd;
                Posic= Claves.BuscaOrdenado(ClaProd);
                if (Posic >= 0)
                {
                    Claves.Elimina(Posic);
                    Precios.Elimina(Posic);
                }
                else
                    cout<<"\n\nEsa clave no esta registrada. \n";
                break ;
            }

            case 5: {
                cout << "\n\nDe la clave y precio del nuevo producto: ";
                cin >> ClaProd;
                cin >> PrecProd;
                Posic = Claves.BuscaOrdenado(ClaProd);
                if (Posic >= 0)
                    cout << "\n\nEsa clave ya fue registrada previamente. \n";
                else {
                    Posic= (Posic * -1) -1;
                    if (Claves.InsertaOrdenado(Posic, ClaProd) == 1)
                        Precios.InsertaOrdenado(Posic, PrecProd);
                    else
                        cout<<"\n\nYa no se pueden registrar nuevos productos. \n";
                }
                break ;
            }

            case 6: {
                cout << "\n\nDe precio minimo del producto: ";
                cin >> PrecProd;

                for(int i = 0; i <= Precios.RegresaTamano(); i++) {
                    if(Precios.RegresaValor(i) >= PrecProd) {
                        cout << Claves.RegresaValor(i) << ", ";
                    }
                }
                cout << endl;
                break;
            }

            case 7: {
                cout << "\n\nTermina el procesamiento de los datos. \n\n";
                break;
            }
        }

        getch();

    } while (Opc != 7);

    return 0;
}