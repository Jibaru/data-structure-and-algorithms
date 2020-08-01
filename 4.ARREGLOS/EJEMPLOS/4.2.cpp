/* Se incluye una biblioteca que contiene la plantilla de la clase 
Arreglo, de esta manera se evita repetir código. En la biblioteca 
4.1.cpp se tiene todo el código del programa 4.1.*/

#include "4.1.cpp"
#include "conio.h"

/* Función que despliega en pantalla las opciones de trabajo que tiene 
el usuario. */
int MenuOpciones()
{
    char Opcion;
    do {
        cout << "\n\n\nL: Leer la lista de claves: ";
        cout << "\nA: Dar de alta un nuevo alumno: ";
        cout << "\nB: Dar de baja un alumno: ";
        cout << "\nI: Imprimir la lista de claves: ";
        cout << "\nF: Finalizar el proceso. ";
        cout << "\n\n Ingrese opcion de trabajo: ";
        cin >> Opcion;
    } while (Opcion != 'A' && Opcion != 'B' && Opcion != 'L' &&
        Opcion != 'I' && Opcion != 'F');
    
    return Opcion;
}

/* Función principal desde la cual se tiene el control de todo el proceso: 
se despliegan las opciones de trabajo y de acuerdo a la seleccionada 
por el usuario se invoca el método que corresponda. */
int main() {
    /* Se crea un objeto tipo Arreglo usando la plantilla de la biblioteca 
    PlanArreglo(4.1.cpp). Se indica que los elementos a almacenar en el arreglo 
    son de tipo entero. */
    Arreglo<int> ClavAlum;
    int Clave, Res;
    char Opc;

    /* Este ciclo permite al usuario realizar más de una operación con 
    las claves de los alumnos. */
    do {
        Opc= MenuOpciones();
        switch(Opc)
        {
            /* Se invoca el método de lectura del arreglo, para que el 
            usuario ingrese valores para cada uno de los atributos de la clase.
            Para esta aplicación es el total de alumnos y la clave 
            de cada uno de ellos. */
            case 'L': {
                ClavAlum.Lectura();
                break;
            }
                /* Se invoca el método de impresión del arreglo para desplegar <<
                en pantalla la clave de cada uno de ellos. */
            case 'I': {
                ClavAlum.Escribe();
                break;
            }
            /* Se invoca el método de inserción en arreglos desordenados. 
            e debe dar como parámetro un dato del mismo tipo que el usado 
            para crear el objeto, en este caso es un número entero. */
            case 'A': {
                cout << "\n\n Clave del nuevo alumno: ";
                cin >> Clave;
                Res= ClavAlum.InsertaDesordenado(Clave);
                /* Se despliega un mensaje de acuerdo al resultado 
                obtenido en el método. */
                if (Res = 1)
                    cout << "\n\n El nuevo alumno ya fue dado de alta. ";
                else if (Res = 0)
                    cout << "\n\n No hay espacio para registrar el nuevo alumno. ";
                else
                    cout << "\n\n Esa clave ya fue registrada previamente. ";
            break;
            }
            /* Se invoca el método de eliminación en arreglos desordenados. 
            Se debe dar como parámetro un dato del mismo tipo que el usado 
            para crear el objeto, en este caso un número entero. */
            case 'B': {
                cout << "\n\n Clave del alumno a dar de baja: ";
                cin >> Clave;
                Res= ClavAlum.EliminaDesordenado(Clave);
                /* Se despliega un mensaje de acuerdo al resultado obtenido 
                en el método. */
                if (Res = 1)
                    cout << "\n\n El alumno ya fue dado de baja. ";
                else if (Res == 0)
                    cout << "\n\n No hay alumnos registrados.";
                else
                    cout << "\n\n Esa clave no está registrada.";
                break;
            }
            case 'F':
                cout << "\n\n Termina el proceso. \n\n";
                break;
        }

        getch();
    } while (Opc != 'F');

    return 0;
}
