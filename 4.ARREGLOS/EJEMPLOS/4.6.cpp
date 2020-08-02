/* Ejemplo de aplicación de arreglos paralelos. En la biblioteca 
"4.5.cpp* se incluye la plantilla de la clase definida
 en el programa 4.5. */
#include "4.5.cpp"
#include <conio.h>
/* Función que despliega al usuario las posibles opciones de trabajo. */
int MenuOpciones()
{
    int Opc;
    do {
        cout << "\n1-Captura inicial de claves y calificaciones de alumnos. ";
        cout << "\n2-Ingresar un nuevo alumno y su calificacion. ";
        cout << "\n3-Eliminar un alumno y su calificacion. ";
        cout << "\n4-Obtener un listado de las claves de los alumnos.";
        cout << "\n5-Obtener un listado de claves y calificaciones de todos los alumnos.";
        cout << "\n6-Obtener la calificacion de un alumno. ";
        cout << "\n7-Terminar el proceso. ";
        cout << "\n\nIngrese la opcion seleccionada. ";
        cin >> Opc;
    } while (Opc < 1 || Opc > 7);
    
    return Opc;
}

/* Función principal: se despliega el menú de opciones y, de 
acuerdo a la opción elegida por el usuario, se invoca el método 
correspondiente. */
int main ()
{
    ArreParal<int> Claves;
    ArreParal<float> Calific;
    
    int ClaAlum, Opc, Posic, Indice, TotalAl;
    float CalAlum;

    do {
        Opc= MenuOpciones();
        switch (Opc)
        {
            /* Se leen los datos (clave y calificación) de cada uno de los 
            alumnos del grupo. Por medio del operador sobrecargado >> se 
            indica la lectura de los objetos Claves y Calific. */
            case 1: {
                cout << "\n\nDe el numero de claves y cada una de las claves\n";
                cin >> Claves;
                cout << "\n\nDe el numero de calificaciones y cada una de ellas \n";
                cin >> Calific;
                break ;
            }
            /* Se registra un nuevo alumno, proporcionando para ello su clave 
            y su calificación. Las claves son únicas y están ordenadas de manera 
            ascendente. Primero se verifica, por medio del método BuscaOrdenado(),
            que la clave dada no haya sido previamente almacenada. Si no se repite,
            entonces se agrega a la colección de claves sin alterar el orden de éstas.
            Para ello se usa el método InsertaOrdenado(). Si la inserción se lleva a 
            cabo con éxito, entonces se procede a agregar la calificación del nuevo 
            alumno en la posición que le corresponde por el valor de su clave. */ 
            case 2: {
                cout << "\n\nDe la clave y calificacion del nuevo alumno: ";
                cin >> ClaAlum;
                cin >> CalAlum;
                Posic = Claves.BuscaOrdenado(ClaAlum);
                if (Posic >= 0)
                    cout << "\n\nEsa clave ya fue registrada previamente. \n";
                else {
                    Posic= (Posic * -1) -1;
                    if (Claves.InsertaOrdenado(Posic, ClaAlum) == 1)
                        Calific.InsertaOrdenado(Posic, CalAlum);
                    else
                        cout<<"\n\nYa no se pueden registrar nuevos alumnos. \n";
                }
                break ;
            }
            /* Se elimina un alumno dando su clave como dato de entrada. Si 
            la clave está (existe un alumno con dicha clave) se procede a 
            eliminarla y a eliminar su correspondiente calificación. */
            case 3: {
                cout << "\n\nDe la clave del alumno que desea dar de baja: ";
                cin >> ClaAlum;
                Posic= Claves.BuscaOrdenado(ClaAlum);
                if (Posic >= 0)
                {
                    Claves.Elimina(Posic);
                    Calific.Elimina(Posic);
                }
                else
                    cout<<"\n\nEsa clave no esta registrada. \n";
                break ;
            }
            /* Se genera un reporte con todas las claves de los alumnos 
            registrados. Por medio del operador sobrecargado << se indica 
            la escritura del objeto Claves de manera directa. */
            case 4: {
                cout << "\n\nListado de claves de alumnos registrados. \n";
                cout << Claves;
                cout << "\n\n";
                break;
            }
            /* Se genera un reporte con la clave y la calificación de todos 
            los alumnos registrados. Primero se obtiene el total de alumnos
            por medio del método que regresa el tamaño del arreglo. Luego 
            se tiene acceso a cada uno de los valores almacenados, por 
            medio del método RegresaValor(), y se los imprime. */
            case 5: {
                TotalAl= Claves.RegresaTamano();
                cout << "\n\nClave Calificacion \n";
                for (Indice= 0; Indice < TotalAl; Indice ++)
                {
                    cout << Claves.RegresaValor(Indice) << " : " ;
                    cout << Calific.RegresaValor(Indice) << " \n";
                }
                break ;
            }
            /* Dada la clave de un alumno, se imprime la calificación del 
            mismo. Se hace uso del método BuscaOrdenado(), para encontrar 
            la clave. Si se encuentra (ese alumno está registrado), se 
            invoca al método RegresaValor() para tener acceso a su 
            calificación. */
            case 6: {
                cout << "\n\nClave del alumno que desea conocer su calificacion: ";
                cin >> ClaAlum;
                Posic= Claves.BuscaOrdenado(ClaAlum);
                if (Posic >= 0)
                {
                    cout << "\n\nCalificacion del alumno con clave: " << ClaAlum;
                    cout << " es: " << Calific.RegresaValor(Posic);
                }
                else
                    cout << "\n\nEsa clave no esta registrada. \n\n";
                break ;
            }
            /* Termina el ciclo de procesamiento. */
            case 7: {
                cout << "\n\nTermina el procesamiento de los datos. \n\n";
                break;
            }
        }

        getch();

    } while (Opc != 7);

    return 0;
}
