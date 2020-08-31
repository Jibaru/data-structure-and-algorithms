/*
2.	Escriba un programa en C++ que, apoyándose en un objeto tipo pila, 
evalúe una expresión dada en notación prefija. Por ejemplo, si la expresión 
dada es + 8 4, su programa debe generar como salida el valor 12. 
Puede asumir que se darán números de un solo dígito.
*/
#include "../EJEMPLOS/5.1.cpp"
#include <string.h>

float operacion(float a, float b, char op) 
{
    float res;
    switch(op) {
        case '+': {
            res = a + b;
            break;
        }
        case '-': {
            res = a - b;
            break;
        }
        case '*': {
            res = a * b;
            break;
        }
        case '/': {
            res = a / b;
            break;
        }
    }
    return res;
}

float caracterAFlotante(char c)
{
    float f;
    switch(c) {
        case '0': { f = 0; break; }
        case '1': { f = 1; break; }
        case '2': { f = 2; break; }
        case '3': { f = 3; break; }
        case '4': { f = 4; break; }
        case '5': { f = 5; break; }
        case '6': { f = 6; break; } 
        case '7': { f = 7; break; }
        case '8': { f = 8; break; }
        case '9': { f = 9; break; }
    }
    return f;
}

bool esNumero(char c) {

    int ascii = static_cast<int>(c);

    if(ascii >= 48 && ascii <= 57) {
        return true;
    }

    return false;
}

void UsaPilaPrefijoOperacion()
{
    Pila<char> operadores = Pila<char>();
    Pila<float> operandos = Pila<float>();

    char cadena[60], op;
    int contador = 0, tam;
    float aux;
    int cantOperandos = 0;

    cout << "Ingrese expresion prefija: ";
    cin >> cadena;

    tam = strlen(cadena);

    while(contador < tam) {
        // si no es número, es operador
        if(!esNumero(cadena[contador])) {
            operadores.Push(cadena[contador]);
            cantOperandos = 0;
        } else {
            if(cantOperandos == 0) {
                aux = caracterAFlotante(cadena[contador]);
                operandos.Push(aux);
                cantOperandos++;
            } else if(cantOperandos == 1) {
                aux = caracterAFlotante(cadena[contador]);
                operandos.Push(aux);
                cantOperandos++;
            }

            if(cantOperandos == 2) {

                float num1, num2;

                if(operandos.PilaVacia() != 1) {
                    operandos.Pop(&aux);
                    num2 = aux;
                    cantOperandos--;
                }

                if(operandos.PilaVacia() != 1) {
                    operandos.Pop(&aux);
                    num1 = aux;
                    cantOperandos--;
                }

                if(operadores.PilaVacia() != 1) {
                    operadores.Pop(&op);
                }

                aux = operacion(num1, num2, op);

                operandos.Push(aux);
                cantOperandos++;                
            }
        }
        contador++;
    }

    if(operadores.PilaVacia() != 1) {
        float num1, num2;

        if(operandos.PilaVacia() != 1) {
            operandos.Pop(&aux);
            num2 = aux;
        }

        if(operandos.PilaVacia() != 1) {
            operandos.Pop(&aux);
            num1 = aux;
        }

        if(operadores.PilaVacia() != 1) {
            operadores.Pop(&op);
        }

        aux = operacion(num1, num2, op);

        operandos.Push(aux);
    }

    while(operandos.PilaVacia() != 1) {
        operandos.Pop(&aux);
        cout << aux << endl;
    }
}

int main()
{
    UsaPilaPrefijoOperacion();
    return 0;
}