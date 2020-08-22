/*
9.	Se tienen 2 arreglos paralelos. El primero de ellos almacena las claves de N (1< N<50) 
escuelas, ordenadas ascendentemente. En el segundo se almacena, por escuela, el total de 
alumnos de preprimaria, primaria, secundaria y preparatoria. Observe el siguiente esquema. 
La escuela, cuya clave está en la casilla 0 del primer arreglo, tiene 624 alumnos en preprimaria, 
1600 en primaria, 1260 en secundaria y 893 en preparatoria. Los totales de alumnos, por nivel, 
de la segunda escuela ocuparán las casillas 4, 5, 6 y 7 del segundo arreglo, y así sucesivamente.

Clave escuelas(pos) [{0}, 1, 2, ..., MAX -1]
Total Alumnos (pos) [{0, 1, 2, 3}, ..., MAX*4-1]

Teniendo en cuenta estas especificaciones para guardar los datos, escriba un programa en C++ que:
a)	Genere un reporte que imprima, de cada una de las escuelas, el total de alumnos en cada una 
de las secciones y el total general de la escuela. El usuario podrá dar la clave de una escuela 
o pedir un listado de todas las escuelas.
b)	Calcule e imprima el total de alumnos de cualquiera de las 4 secciones, considerando todas 
las escuelas. El usuario indicará la sección elegida.
c)	Calcule e imprima el total de alumnos en cada una de las 4 secciones, considerando todas las 
escuelas. Es decir, el total de alumnos en preprimaria, primaria, etcétera, tenga en cuenta las 
N escuelas. ¿Puede reutilizar la solución del inciso b)?
d)	Registre una nueva escuela. Los datos proporcionados por el usuario serán la clave de la escuela 
y el número de alumnos en cada una de las 4 seccio¬nes. Si la escuela no tiene alguna de las secciones 
se ingresará un 0. 
e) Elimine alguna de las escuelas. El dato proporcionado por el usuario será la clave de la escuela.
f) Actualice los totales de alumnos en alguna sección (o en todas). El dato proporcionado por el 
usuario será la clave de la escuela, la clave de la sección (o secciones) y el nuevo número de alumnos.
*/

#include "../EJEMPLOS/4.5.cpp"
#include <conio.h>

int MenuOpciones()
{
    int Opc;
    do {
        cout << "\n1-Captura inicial de escuelas, y alumnos por secciones";
        cout << "\n2-Ver todas las escuelas con sus alumnos por seccion y total por escuela";
        cout << "\n3-Total de alumnos de cualquiera de las 4 secciones de todas las escuelas.";
        cout << "\n4-Total de alumnos de todas las secciones de todas las escuelas ";
        cout << "\n5-Ingresar nueva escuela y alumnos";
        cout << "\n6-Eliminar escuela";
        cout << "\n7-Actualizar cantidad de alumnos por seccion de escuela";
        cout << "\n8-Salir.";
        cout << "\n\nIngrese la opcion seleccionada. ";
        cin >> Opc;
    } while (Opc < 1 || Opc > 8);
    
    return Opc;
}

int main() {

    ArreParal<int> ClaveEscuelas = ArreParal<int>();
    ArreParal<int> TotalAlumnos = ArreParal<int>();

    int Opc, ClaveEsc, NumEsc, SeccionSel;
    int NumAlumnos, Pos, Indice, Indice2;
    int TotalPrePrim, TotalPrim, TotalSecu, TotalPrepa;

    do {
        Opc= MenuOpciones();

        switch(Opc) {

            case 1: {
                cout << "\n\nNumero de claves de escuela: ";
                cin >> ClaveEscuelas;
                
                NumEsc = ClaveEscuelas.RegresaTamano();
                Indice = 0;
                while(Indice < NumEsc) {
                    cout << "Escuela Nro " << Indice + 1 << endl;
                    cout << "Cant. alumnos preprimaria: ";
                    cin >> NumAlumnos;
                    TotalAlumnos.InsertaDesordenado(NumAlumnos);
                    cout << "Cant. alumnos primaria: ";
                    cin >> NumAlumnos;
                    TotalAlumnos.InsertaDesordenado(NumAlumnos);
                    cout << "Cant. alumnos secundaria: ";
                    cin >> NumAlumnos;
                    TotalAlumnos.InsertaDesordenado(NumAlumnos);
                    cout << "Cant. alumnos preparatoria: ";
                    cin >> NumAlumnos;
                    TotalAlumnos.InsertaDesordenado(NumAlumnos);
                    Indice++;
                }

                break;
            }

            case 2: {

                cout << "\nEscuela\tPreprim\tPrimar\tSecund\tPrepa\n";
                Indice = 0, Indice2 = 0;
                NumEsc = ClaveEscuelas.RegresaTamano();
                while(Indice < NumEsc) {
                    
                    cout << ClaveEscuelas.RegresaValor(Indice) << "\t";
                    cout << TotalAlumnos.RegresaValor(Indice2) << "\t";
                    Indice2++;
                    cout << TotalAlumnos.RegresaValor(Indice2) << "\t";
                    Indice2++;
                    cout << TotalAlumnos.RegresaValor(Indice2) << "\t";
                    Indice2++;
                    cout << TotalAlumnos.RegresaValor(Indice2) << "\t\n";
                    Indice2++;
                    Indice++;
                }

                break;
            }

            case 3: {
                NumAlumnos = 0;
                cout << "1-Preprimaria"<< endl;
                cout << "2-Primaria" << endl;
                cout << "3-Secundaria" << endl;
                cout << "4-Preparatoria" << endl;
                cout << "Ingrese seccion: ";
                cin >> SeccionSel;

                if(SeccionSel == 1) {
                    Indice = 0;
                } else if(SeccionSel == 2) {
                    Indice = 1;
                } else if(SeccionSel == 3) {
                    Indice = 2;
                } else if(SeccionSel == 4) {
                    Indice = 3;
                }

                for(; Indice < TotalAlumnos.RegresaTamano(); Indice+=4) {
                    NumAlumnos += TotalAlumnos.RegresaValor(Indice);
                }

                cout << "Numero de alumnos opcion"<< SeccionSel << ": " << NumAlumnos << endl;

                break;
            }

            case 4: {
                TotalPrePrim = 0;
                TotalPrim = 0;
                TotalSecu = 0;
                TotalPrepa = 0;
                for(Indice = 0; Indice < TotalAlumnos.RegresaTamano(); ) {
                    TotalPrePrim += TotalAlumnos.RegresaValor(Indice);
                    Indice++;
                    TotalPrim += TotalAlumnos.RegresaValor(Indice);
                    Indice++;
                    TotalSecu += TotalAlumnos.RegresaValor(Indice);
                    Indice++;
                    TotalPrepa += TotalAlumnos.RegresaValor(Indice);
                    Indice++;
                }

                cout << "Preprimaria: " << TotalPrePrim << endl;
                cout << "Primaria: " << TotalPrim << endl;
                cout << "Secundaria: " << TotalSecu << endl;
                cout << "Preparatoria: " << TotalPrepa << endl;
                
            }

            case 5: {
                cout << "Clave de escuela: ";
                cin >> ClaveEsc;

                ClaveEscuelas.InsertaDesordenado(ClaveEsc);

                cout << "Cant. alumnos preprimaria: ";
                cin >> NumAlumnos;
                TotalAlumnos.InsertaDesordenado(NumAlumnos);
                cout << "Cant. alumnos primaria: ";
                cin >> NumAlumnos;
                TotalAlumnos.InsertaDesordenado(NumAlumnos);
                cout << "Cant. alumnos secundaria: ";
                cin >> NumAlumnos;
                TotalAlumnos.InsertaDesordenado(NumAlumnos);
                cout << "Cant. alumnos preparatoria: ";
                cin >> NumAlumnos;
                TotalAlumnos.InsertaDesordenado(NumAlumnos);
                break;
            }

            case 6: {
                cout << "Clave de escuela a eliminar: ";
                cin >> ClaveEsc;
                Pos = ClaveEscuelas.BuscaDesordenado(ClaveEsc);
                
                if(Pos >=0) {
                    ClaveEscuelas.Elimina(Pos);

                    for(Indice = Pos * 4; Indice < (Pos*4) + 4; Indice++) {
                        TotalAlumnos.Elimina(Indice);
                    }

                } else {
                    cout << "No existe una escuela registrada con dicha clave" << endl;
                }
                break;
            }

            case 7: {
                cout << "Clave de escuela a actualizar: ";
                cin >> ClaveEsc;
                Pos = ClaveEscuelas.BuscaDesordenado(ClaveEsc);
                
                if(Pos >=0) {
                    Indice = Pos * 4;

                    cout << "Cant. alumnos preprimaria: ";
                    cin >> NumAlumnos;
                    TotalAlumnos.ActualizaValor(Indice, NumAlumnos);
                    Indice++;
                    cout << "Cant. alumnos primaria: ";
                    cin >> NumAlumnos;
                    TotalAlumnos.ActualizaValor(Indice, NumAlumnos);
                    Indice++;
                    cout << "Cant. alumnos secundaria: ";
                    cin >> NumAlumnos;
                    TotalAlumnos.ActualizaValor(Indice, NumAlumnos);
                    Indice++;
                    cout << "Cant. alumnos preparatoria: ";
                    cin >> NumAlumnos;
                    TotalAlumnos.ActualizaValor(Indice, NumAlumnos);
                    Indice++;

                } else {
                    cout << "No existe una escuela registrada con dicha clave" << endl;
                }
                break;
            }

            case 8: {
                cout << "\n\nTermina el procesamiento de los datos. \n\n";
                break;
            }

        }

        getch();

    } while(Opc != 8);

    return 0;

}