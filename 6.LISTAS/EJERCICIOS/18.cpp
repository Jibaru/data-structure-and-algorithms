/*
18.	Retome el problema anterior. Escriba un programa en C++, que mediante 
menús pueda:
á) Agregar una nueva marca.
b)	Agregar un nuevo modelo a una marca registrada.
c)	Eliminar una marca. En este caso se deben eliminar también todos los 
modelos que tiene dicha marca.
d)	Eliminar un modelo de una marca registrada.
é) Generar un reporte con todas las marcas y todos los modelos de las mismas.
j)	Dada una marca, imprimir todos los modelos que tiene.
g)	Generar un reporte con el modelo más caro de cada una de las marcas.
*/
#include <iostream>
#include <conio.h>
#include "17.cpp"

using namespace std;

int menuOpciones()
{
    int opc;
    do {
        cout << "\n1-Agregar nueva marca" << endl;
        cout << "2-Agregar nuevo modelo a marca registrada" << endl;
        cout << "3-Eliminar una marca (y sus modelos)" << endl;
        cout << "4-Eliminar un modelo de una marca" << endl;
        cout << "5-Reporte de todas las marcas y modelos" << endl;
        cout << "6-Ver modelos por una marca" << endl;
        cout << "7-Reporte de modelo mas caro de cada marca" << endl;
        cout << "8-Salir del sistema" << endl;
        cin >> opc;
        cout << endl;
    } while(opc < 1 || opc > 8);
    return opc;
}

int main()
{
    int opc, resp;
    Lista<Marca> marcas = Lista<Marca>();
    
    // Auxiliares
    Marca marca;
    Modelo modelo;
    Lista<Modelo>* modelosDeMarca;
    NodoLista<Marca>* nodoMarca, *itMarca;
    NodoLista<Modelo>* nodoModelo, *itModelo;
    char nombreMarca[60], nombreModelo[60];

    do {
        opc = menuOpciones();

        switch(opc) {
            case 1: {
                marca = Marca();
                cout << "Nueva marca: " << endl;
                cin >> marca;
                marcas.InsertaFinal(marca);
                break;
            }
            case 2: {
                cout << "Nombre de marca: ";
                cin.ignore();
                cin.getline(nombreMarca, 60);
                marca = Marca(nombreMarca);
                nodoMarca = marcas.Busca(marca);
                if(nodoMarca) {
                    modelosDeMarca = nodoMarca->RegresaInfo()->regresaModelos();
                    modelo = Modelo();
                    cout << "Nuevo modelo: " << endl;
                    cin >> modelo;
                    modelosDeMarca->InsertaFinal(modelo);
                } else {
                    cout << "No se encontro la marca" << endl;
                }
                break;
            }
            case 3: {
                cout << "Nombre de marca a eliminar: ";
                cin.ignore();
                cin.getline(nombreMarca, 60);
                marca = Marca(nombreMarca);

                resp = marcas.EliminaUnNodo(marca);
                switch(resp) {
                    case -1: {
                        cout << "Lista vacia" << endl;
                        break;
                    }
                    case 0: {
                        cout << "No se encontra la marca" << endl;
                        break;
                    }
                    case 1: {
                        cout << "Marca eliminada" << endl;
                        break;
                    }
                }
                
                break;
            }
            case 4: {
                cout << "Nombre de marca: ";
                cin.ignore();
                cin.getline(nombreMarca, 60);
                marca = Marca(nombreMarca);
                nodoMarca = marcas.Busca(marca);
                if(nodoMarca) {
                    modelosDeMarca = nodoMarca->RegresaInfo()->regresaModelos();
                    cout << "Nombre modelo a eliminar: " << endl;
                    cin.ignore();
                    cin.getline(nombreModelo, 60);
                    modelo = Modelo(nombreModelo);
                    resp = modelosDeMarca->EliminaUnNodo(modelo);
                    switch(resp) {
                        case -1: {
                            cout << "Lista vacia" << endl;
                            break;
                        }
                        case 0: {
                            cout << "No se encontra el modelo" << endl;
                            break;
                        }
                        case 1: {
                            cout << "Modelo eliminado" << endl;
                            break;
                        }
                    }
                } else {
                    cout << "No se encontro la marca" << endl;
                }
                break;
            }
            case 5: {
                cout << "Todas las marcas y modelos:" << endl;
                marcas.ImprimeIterativo();
                break;
            }
            case 6: {
                cout << "Nombre de marca: ";
                cin.ignore();
                cin.getline(nombreMarca, 60);
                marca = Marca(nombreMarca);
                nodoMarca = marcas.Busca(marca);
                if(nodoMarca) {
                    modelosDeMarca = nodoMarca->RegresaInfo()->regresaModelos();
                    cout << "Modelos de esta marca: " << endl;
                    modelosDeMarca->ImprimeIterativo();
                } else {
                    cout << "No se encontro la marca" << endl;
                }
                break;
            }
            case 7: {
                
                for(itMarca = marcas.RegresaPrimero();
                    itMarca != NULL;
                    itMarca = itMarca->RegresaSiguiente()) 
                {
                    modelo = Modelo((char*)"", -9999);
                    for(itModelo = itMarca->RegresaInfo()->regresaModelos()->RegresaPrimero();
                        itModelo != NULL;
                        itModelo = itModelo->RegresaSiguiente())
                    {
                        if(itModelo->RegresaInfo()->regresaPrecio() > modelo.regresaPrecio()) {
                            modelo = *(itModelo->RegresaInfo());
                        }
                    }
                    cout << "Modelo mas caro de la marca " << itMarca->RegresaInfo()->regresaNombre() << endl;
                    cout << modelo;
                }
                break;
            }
            case 8: {
                cout << "Fin del programa" << endl;
                break;
            }
        }
        getch();

    } while(opc != 8);

    return 0;
}