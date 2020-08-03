/* Se tienen las calificaciones de un grupo de N alumnos obtenidas en M 
exámenes. Para almacenar esta información se usa un objeto de tipo 
ArregloBidimensioanl: los renglones representan a los alumnos y las 
columnas a los exámenes. */

/* Se incluye la plantilla de la clase ArregloBdimensiónal correspondiente
al programa 4.7, en la biblioteca "4.7.cpp". */
#include "4.7.cpp"
#include "conio.h"
 
/* Función que despliega al usuario las opciones de trabajo sobre los datos ingresados. */
int Menu()
{
    int Opc;
    do {
        cout << "\n1-Listado de calificaciones de un alumno.";
        cout << "\n2-Listado de calificaciones de un examen.";
        cout << "\n3-Promedio de calificaciones de un alumno.";
        cout << "\n4-Promedio de calificaciones de un examen.";
        cout << "\n5-Calificacion de un alumno obtenida en un examen.";
        cout << "\n6-Maxima calificacion de un examen.";
        cout << "\n7-Minima calificacion de un examen.";
        cout << "\n8-Maxima calificacion de un alumno.";
        cout << "\n9-Minima calificacion de un alumno.";
        cout << "\n10-Terminar.";
        cout << "\nIngrese opcion elegida:";
        cin >> Opc;
    } while(Opc < 1 || Opc > 10);

    return Opc;
}

/* Plantilla de función para imprimir las calificaciones obtenidas por 
un alumno (el usuario proporcionará un número para identificarlo) en 
todos los exámenes. */
template <class T>
void CalifAlum(ArregloBidimensional <T> ObjArreBidi, int NumExam)
{
    int Alum, Exam;
    cout << "\n\n Ingrese el numero del alumno:"; 
    cin >> Alum;
    cout << "\n\n Calificaciones obtenidas por el alumno en los examenes\n";
    for (Exam = 0; Exam < NumExam; Exam++)
        cout << "\nExamen: " << Exam + 1 << " - " << "Calif.: " << ObjArreBidi.RegresaDato(Alum - 1, Exam);
}

/* Plantilla de función para imprimir las calificaciones obtenidas en un 
examen (el usuario proporcionará un número para identificarlo) por 
todos los alumnos. */
template <class T>
void CalifExam(ArregloBidimensional <T> ObjArreBidi, int NumAlum)
{
    int Alum, Exam;
    cout << "\n\n Ingrese el numero del examen:";
    cin >> Exam;
    cout << "\n\n Calificaciones obtenidas por los alumnos en el examen\n";
    for (Alum= 0; Alum < NumAlum; Alum++)
        cout << "\nAlumno: " << Alum + 1 << " - " << "Calificacion: " << ObjArreBidi.RegresaDato(Alum, Exam - 1);
}

/*El promedio de calificaciones obtenido por un alumno se calcula como 
la suma de todos los elementos correspondientes al renglón del alumno 
(sus calificaciones), entre el número de columnas (exámenes). */
template <class T>
float PromAlum(ArregloBidimensional <T> ObjArreBidi, int NumExam)
{
    int Alum;
    cout << "\n\n Ingrese el numero del alumno:";
    cin >> Alum ;
    return (float) (ObjArreBidi.SumaRenglon(Alum - 1) / NumExam);
}

/* El promedio de calificaciones de un examen se calcula como la suma de 
los elementos correspondientes a la columna del examen, entre el número 
de renglones (alumnos). */
template <class T>
float PromExam(ArregloBidimensional <T> ObjArreBidi, int NumAlum)
{
    int Exam;
    cout << "\n\n Ingrese el numero del examen:";
    cin >> Exam;
    return (float) (ObjArreBidi.SumaColumna(Exam - 1) / NumAlum);
}

/* Función que usa un arreglo bidimensional. Se declara un objeto del 
tipo ArregloBidimensional para almacenar un conjunto de números enteros 
que representan las calificaciones obtenidas por varios alumnos en diversos 
exámenes. */
void UsaArregloBidimensional() {
    int Alum, Exam, NumAlum, NumExam, Opc;

    cout << "\n\nIngrese el total de alumnos y el numero de examenes: ";
    cin >> NumAlum >> NumExam;

    ArregloBidimensional<int> ObjArreBidi(NumAlum, NumExam);
    
    cout << "\n\nIngrese por cada alumno todas las calificaciones obtenidas en los examenes.\n";
    ObjArreBidi.Lectura() ;
    Opc= Menu();
    while (Opc >= 1 && Opc <= 9)
    {
        switch (Opc)
        {
            case 1: {
                CalifAlum(ObjArreBidi, NumExam);
                break;
            }
            case 2: {
                CalifExam(ObjArreBidi, NumAlum);
                break;
            }
            case 3: {
                cout << "\nEl Promedio del alumno es: " << PromAlum(ObjArreBidi, NumExam);
                break;
            }
            case 4: {
                cout << "\nPromedio de los alumnos en el examen es:" << PromExam(ObjArreBidi, NumAlum);
                break;
            }
            case 5: {
                cout << "\n\nIngrese el numero del alumno:";
                cin >> Alum;
                cout << "\n\nIngrese el numero del examen:";
                cin >> Exam;
                cout << "\nEl alumno " << Alum << " obtuvo en el examen " << Exam << ":"
                << ObjArreBidi.RegresaDato(Alum - 1, Exam - 1);
                break;
            }
            case 6: {
                cout << "\n\nIngrese el numero del examen:";
                cin >> Exam;
                cout << "\n\nMaxima calificacion del examen " << Exam << " " 
                << ObjArreBidi.MaximoColumna(Exam - 1);
                break;
            }
            case 7: {
                cout << "\n\nIngrese el numero del examen:";
                cin >> Exam;
                cout << "\n\nMinima calificacion del examen: " << Exam << " "
                << ObjArreBidi.MinimoColumna(Exam - 1);
                break;
            }
            case 8: {
                cout << "\n\nIngrese el numero del alumno:";
                cin >> Alum;
                cout << "\n\nMaxima calificacion del alumno: " << Alum << " "
                << ObjArreBidi.MaximoRenglon(Alum - 1);
                break;
            }
            case 9: {
                cout << "\n\nIngrese el numero del alumno: ";
                cin >> Alum;
                cout << "\n\nMinima calificacion del alumno: " << Alum << " "
                << ObjArreBidi.MinimoRenglon(Alum - 1);
                break;
            }
        }

        getch();

        Opc= Menu();
    }
}

int main() {

    UsaArregloBidimensional();

    return 0;
}
