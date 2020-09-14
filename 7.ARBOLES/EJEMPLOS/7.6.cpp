/* Programa que utiliza un árbol balanceado para almacenar ordenadamente 
los datos de ciertas fábricas. El usuario puede dar de alta nuevas 
fábricas, eliminar alguna ya registrada, obtener un reporte de todas 
(ordenadas según su clave) y actualizar sus direcciones y teléfonos. Se 
incluyen dos bibliotecas, una con la plantilla de la clase ArbolBalanceado
presentada en el programa 7.4 y la otra con la clase Fabrica del programa 7.5. */
#include <iostream>
#include <conio.h>
#include "../../lib/arboles/ArbolBalanceado.h"
#include "../../lib/clases/Fabrica.h"

using namespace std;

/* Función que despliega en pantalla las opciones de trabajo para el 
usuario. */
int Menu()
{
    int Opc;
    do {
        cout << "\n\n\t\tOpciones de trabajo.\n\n\n";
        cout << "(1) Capturar los datos de una fabrica.\n";
        cout << "(2) Dar de baja una fabrica.\n";
        cout << "(3) Imprimir los datos de todas las fabricas, ordenadas por clave. \n";
        cout << "(4) Cambiar el domicilio de una fabrica.\n";
        cout << "(5) Cambiar el telefono de una fabrica.\n";
        cout << "(6) Terminar la sesion de trabajo.\n\n";
        cout << "Ingrese la opcion seleccionada: ";
        cin >> Opc;
    } while (Opc > 6 || Opc < 1);
    
    return Opc;
}

/* Función principal. De acuerdo a la opción de trabajo seleccionada por 
el usuario invoca los métodos que correspondan. */
int main()
{
    ArbolBalanceado<Fabrica> Proveedores;
    NodoArbolBal<Fabrica> *Apunt1, *Apunt2;
    Fabrica Prov;
    int Operac, Band, Clave;
    char NuevoDom[MAX], NuevoTel[MAX];
    do {
        Operac= Menu();
        switch (Operac)
        {
            /* Se registra una nueva fábrica siempre que la clave dada por 
            el usuario no se encuentre en el árbol. */
            case 1: {
                cin >> Prov;
                Band= 0;
                Apunt1= Proveedores.RegresaRaiz();
                Proveedores.InsertaBalanceado(Prov, Apunt1, &Band);
                break;
            }

            /* En caso de dar de baja una fábrica registrada, se solicita sólo 
            la clave ya que es el dato que identifica a cada elemento. */
            case 2: {
                cout << "\n\nIngrese la clave de la fabrica a eliminar: ";
                cin >> Clave;
                Fabrica Prov(Clave, "", "", "");
                Band= 0;
                Apunt1= Proveedores.RegresaRaiz();
                Proveedores.EliminaBalanceado(Apunt1, NULL, &Band, Prov);
                break;
            }
            /* Se imprimen los datos de todas las fábricas, ordenadas de 
            menor a mayor por clave. */
            case 3: {
                Apunt1= Proveedores.RegresaRaiz();
                Proveedores.Imprime(Apunt1);
                break;
            }
            /* Se actualiza la dirección de una fábrica. Para llevar a cabo 
            esta operación, primero se debe encontrar la fábrica de interés, 
            luego recuperar todo el objeto, actualizar el domicilio y posteriormente 
            redefinir el contenido del nodo con el objeto ya modificado. */ 
            case 4: {
                cout << "\n\nIngrese la clave de la fabrica: ";
                cin >> Clave;
                cout << "\n\nIngrese nuevo domicilio: ";
                cin >> NuevoDom;
                Fabrica Prov(Clave, "", "", "");
                Apunt1= Proveedores.RegresaRaiz();
                Apunt2= Proveedores.Busca(Apunt1, Prov);
                if (Apunt2)
                {
                    Prov= Apunt2->RegresaInfo();
                    Prov.CambiaDomic(NuevoDom);
                    Apunt2->ActualizaInfo(Prov);
                }
                else
                    cout << "\n\nEsa fabrica no esta registrada. \n";
                break;
            }
            /* Se actualiza el teléfono de una fábrica. Para llevar a cabo 
            esta operación, primero se debe encontrar la fábrica de interés, 
            luego recuperar todo el objeto, actualizar el teléfono y posteriormente 
            redefinir el contenido del nodo con el objeto ya modificado. */
            case 5: {
                cout << "\n\nIngrese la clave de la fabrica: ";
                cin >> Clave;
                cout << "\n\nlngrese nuevo telefono: ";
                cin >> NuevoTel;
                Fabrica Prov(Clave, "", "", "");
                Apunt1= Proveedores.RegresaRaiz();
                Apunt2= Proveedores.Busca(Apunt1, Prov);
                if (Apunt2)
                {
                    Prov= Apunt2->RegresaInfo();
                    Prov.CambiaTelef(NuevoTel);
                    Apunt2->ActualizaInfo(Prov);
                }
                else
                    cout << "\n\nEsa fabrica no esta registrada. \n";
                
                break;
            }
        }

        getch();

    } while (Operac < 6);

    return 0;
}
