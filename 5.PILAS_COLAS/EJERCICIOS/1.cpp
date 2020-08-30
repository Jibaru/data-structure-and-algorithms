/*
1.	Escriba un programa en C++ que, apoyándose en un objeto tipo pila, 
traduzca una expresión dada en notación infija a notación prefija. Por 
ejemplo, si la expresión dada es a + b, su programa debe generar como 
salida + ab.
*/
#include "../EJEMPLOS/5.1.cpp"
#include <string.h>

// Comprueba si el caracter es un numero
bool esNumero(char c) {

    int ascii = static_cast<int>(c);

    if(ascii >= 48 && ascii <= 57) {
        return true;
    }

    return false;
}

// Comprueba si el caracter es un ")"
bool esCierreParentesis(char c) {
    if(c == ')') {return true; }
    return false;
}

// Comprueba si el caracter es un "("
bool esAberturaParentesis(char c) {
    if(c == '(') {return true; }
    return false;
}

// Funcion que usa pilas para convertir expresion
// infijo a prefijo
void UsaPilaConversion() {

    // Pila que almacenaran operadores y el prefijo salida
    Pila<char> operadores = Pila<char>();
    Pila<char> prefijo = Pila<char>();

    char cadena[60];
    int contador;

    cout << "Ingrese expresion infija (sin espacios): ";
    cin >> cadena;

    cout << "Expresion infijo: " << cadena << endl;

    // Posicion final de la cadena (tamaño - 1)
    contador = strlen(cadena) - 1;

    // Se recorrerá la cadena de final a inicio
    while(contador >= 0) {
        // si es número, lo agregamos a la pila prefijo
        if(esNumero(cadena[contador])) {
            prefijo.Push(cadena[contador]);

        // Si es un "(", vaciamos la pila operadores
        } else if(esAberturaParentesis(cadena[contador])) {
            // Mientras que la pila operadores no este vacia
            // y el operador no sea "(" o ")", lo agregamos
            // a la pila prefijo
            while(operadores.PilaVacia() != 1) {
                char dato;
                operadores.Pop(&dato);
                if(!esAberturaParentesis(dato) && 
                   !esCierreParentesis(dato)) {
                    prefijo.Push(dato);
                }
            }
        // Si no es ninguno de los dos casos anteiores,
        // debe ser un operador, por lo que lo agregamos
        // a la pila de operadores
        } else {
            operadores.Push(cadena[contador]);
        }
        contador--;
    }

    // si al final quedaron operadores en la pila
    // operadores, vaciamos esa pila e ingresamos los 
    // operadores diferentes a "(" o ")" a la pila prefijo
    while(operadores.PilaVacia() != 1) {
        char dato;
        operadores.Pop(&dato);
        if(!esAberturaParentesis(dato) && 
            !esCierreParentesis(dato)) {
            prefijo.Push(dato);
        }
    }

    // Muestra la expresión en prefijo
    cout << "Expresion sufijo: ";
    while(prefijo.PilaVacia() != 1) {
        char dato;
        prefijo.Pop(&dato);
        cout << dato;
    }

}

int main() {
    UsaPilaConversion();
    return 0;
}
