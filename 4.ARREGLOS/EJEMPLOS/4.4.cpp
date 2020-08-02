/* Se incluye la biblioteca "4.3.cpp" en la cual está la 
plantilla de la clase Arreglo presentada en el programa 4.3, con el 
objeto de no repetir código. */
#include "4.3.cpp"
#include <conio.h>

/* Función que despliega en pantalla las opciones de trabajo relacionadas
 a la aplicación. Regresa un dato tipo carácter que representa la 
 opción seleccionada por el usuario. */
char MenuOpciones()
{
    char Opc;
    do {
        cout << "\n\nL: Leer los tiempos hechos por el nadador. \n";
        cout << "\nI: Imprimir un listado con los tiempos del nadador. \n";
        cout << "\nA: Dar de alta un nuevo tiempo. \n";
        cout << "\nB: Dar de baja un tiempo ya registrado. \n";
        cout << "\nT: Terminar el proceso. \n";
        cin >> Opc;
    } while (Opc != 'L' && Opc != 'I' && Opc != 'A' && Opc != 'B' && Opc != 'T');
    
    return Opc;
}

/* Función principal en la cual se tiene el control de toda la 
aplicación: se crea un objeto y otras variables de trabajo, se muestran 
las posibles operaciones a realizar y de acuerdo a la opción elegida 
por el usuario se invocan los métodos que correspondan. */
int main()
{
    /* Se crea un objeto arreglo para almacenar números reales. */
    Arreglo <float> TiemposNada;
    char Opc;
    float Tiempo;
    int Res;
    do {
        Opc= MenuOpciones();
        switch (Opc){
            
            /* Se invoca el método que ingresa, del teclado, valores para 
            los atributos del arreglo. En este caso el total de tiempos 
            registrados y cada uno de los mismos. */
            case 'L': {
                TiemposNada.Lectura();
                break;
            }
            /* Se invoca el método que despliega en pantalla los valores 
            almacenados en el objeto arreglo, en este caso los tiempos 
            registrados por el nadador durante su entrenamiento. */
            case 'I': {
                TiemposNada.Escribe();
                break;
            }
            /* Se invoca el método que inserta un nuevo elemento en el 
            arreglo ordenado, en este caso es un nuevo tiempo del nadador. 
            Luego de ejecutar el método se analiza el resultado obtenido y 
            se despliega un mensaje adecuado. */
            case 'A': {
                cout << "\n\n Nuevo tiempo registrado por el nadador: ";
                cin >> Tiempo;
                Res = TiemposNada.InsertaOrdenado(Tiempo);
                if (Res = 1)
                    cout << "\n\n El nuevo tiempo ya fue dado de alta. ";
                else
                    if (Res == 0)
                        cout << "\n\n No hay espacio para registrar el nuevo tiempo.";
                    else
                        cout << "\n\n Ese tiempo ya fue registrado.";
                break;
            }
            /* Se invoca el método que elimina un elemento del arreglo, en 
            este caso un tiempo que ya no interesa conservar. Luego de 
            ejecutar el método se analiza el resultado obtenido y se despliega
            el mensaje adecuado. */
            case 'B': {
                cout << "\n\n Tiempo a dar de baja: ";
                cin >> Tiempo;
                Res= TiemposNada.EliminaOrdenado(Tiempo);
                if (Res = 1)
                    cout << "\n\n El tiempo ya fue dado de baja.";
                else
                    if (Res == 0)
                        cout << "\n\n No hay tiempos registrados.";
                    else
                        cout << "\n\n Ese tiempo no está registrado.";
                break;
            }
            case 'T': {
                cout << "\n\n Termina el proceso.\n\n ";
                break;
            }
        }

        getch();

    } while (Opc != 'T');

    return 0;
} 
