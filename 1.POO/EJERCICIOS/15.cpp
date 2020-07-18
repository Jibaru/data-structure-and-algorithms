/*
15.	Defina la clase Empleado, según las especificaciones que se dan más abajo. Posteriormente, en un 
programa de aplicación, declare los objetos JefePlanta y JefePersonal usando la clase previamente 
definida. El programa debe permitir al usuario, por medio de menús:
a)	Cambiar el domicilio de uno de los dos empleados declarados. Los datos ingresados por el usuario 
serán la clave del empleado y su nuevo domicilio.
b)	Actualizar el sueldo de un empleado. Los datos ingresados por el usuario serán la clave del empleado
y el porcentaje de incremento a aplicar al sueldo.
c)	Imprimir los datos de un empleado. El usuario proporcionará la clave del empleado elegido.
d)  Cambiar el nombre de la persona  a quien reporta uno de los empleados
*/

#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

class Empleado {
private:
    int _claveEmpleado;
    char _nombre[45], _domicilio[45], _reportaA[45];
    float _sueldo;

public:
    Empleado(int, char[], char[], float, char[]);
    int obtenerClave();
    void imprime();
    void cambiaDoc(char[]);
    void cambiaReportaA(char[]);
    void actualSueldo(float);
};

Empleado::Empleado(
    int claveEmpleado, 
    char nombre[], 
    char domicilio[], 
    float sueldo, 
    char reportaA[]) {
    
    _claveEmpleado = claveEmpleado;
    strcpy(_nombre, nombre);
    strcpy(_domicilio, domicilio);
    _sueldo = sueldo;
    strcpy(_reportaA, reportaA);
}

int Empleado::obtenerClave() {
    return _claveEmpleado;
}

void Empleado::imprime() {
    cout << "Clave: " << _claveEmpleado << endl;
    cout << "Nombre: " << _nombre << endl;
    cout << "Domicilio: " << _domicilio << endl;
    cout << "Sueldo: " << _sueldo << endl;
    cout << "Reporta a: " << _reportaA << endl;
}

void Empleado::cambiaDoc(char domicilio[]) {
    strcpy(_domicilio, domicilio);
}

void Empleado::cambiaReportaA(char reportaA[]) {
    strcpy(_reportaA, reportaA);
}

void Empleado::actualSueldo(float porc) {
    _sueldo += _sueldo*porc;
}

int main() {

    Empleado JefePlanta(1234, "Don Tomas", "Calle S/N Santa Fe", 5623.53, "The Boss"),
    JefePersonal(5232, "Antonio Juliaca", "Jiron Los Pavos Reales 123", 1532.01, "Jefecito");
    int eleccion, clave;

    while(true){
        system("cls");

        cout << "Menu Empleados" << endl;
        cout << "1. Cambiar domicilio "<< endl;
        cout << "2. Actualizar sueldo " << endl;
        cout << "3. Ver datos" << endl;
        cout << "4. Cambiar nombre de a quien reporta" << endl;

        cin >> eleccion;

        system("cls");
        
        switch(eleccion){
            case 1:
                
                char domicilio[45];
                cout << "Cambiar domicilio" << endl;
                cout << "Ingrese clave:";
                cin >> clave;
                cin.ignore();
                cout << "Ingrese nuevo domicilio:";
                cin.getline(domicilio, 45);

                if(JefePlanta.obtenerClave() == clave){
                    JefePlanta.cambiaDoc(domicilio);
                    cout << "Actualizado: " << endl;
                    JefePlanta.imprime();
                } else if(JefePersonal.obtenerClave() == clave){
                    JefePersonal.cambiaDoc(domicilio);
                    cout << "Actualizado: " << endl;
                    JefePersonal.imprime();
                } else {
                    cout << " No se pudo cambiar el domicilio, clave incorrecta" << endl;
                }
                break;
            case 2:
                float porcSueldo;
                cout << "Actualiza sueldo" << endl;
                cout << "Ingrese clave: ";
                cin >> clave;
                cout << "Ingrese Porc. sueldo: ";
                cin >> porcSueldo;
                
                if(JefePlanta.obtenerClave() == clave){
                    JefePlanta.actualSueldo(porcSueldo);
                    cout << "Actualizado: " << endl;
                    JefePlanta.imprime();
                } else if(JefePersonal.obtenerClave() == clave){
                    JefePersonal.actualSueldo(porcSueldo);
                    cout << "Actualizado: " << endl;
                    JefePersonal.imprime();
                } else {
                    cout << " No se pudo actualizar el sueldo, clave incorrecta" << endl;
                }

                break;
            
            case 3:
                cout << "Ver datos" << endl;
                cout << "Ingrese clave: ";
                cin >> clave;

                if(JefePlanta.obtenerClave() == clave){
                    JefePlanta.imprime();
                } else if(JefePersonal.obtenerClave() == clave){
                    JefePersonal.imprime();
                } else {
                    cout << " Clave incorrecta" << endl;
                }
                break;
            
            case 4:
                char reporta[45];
                cout << "Cambiar a quien reporta" << endl;
                cout << "Ingrese clave: ";
                cin >> clave;
                cin.ignore();
                cout << "A quien reporta ahora: ";
                cin.getline(reporta, 45);

                if(JefePlanta.obtenerClave() == clave){
                    JefePlanta.cambiaReportaA(reporta);
                    cout << "Actualizado" << endl;
                    JefePlanta.imprime();
                } else if(JefePersonal.obtenerClave() == clave){
                    JefePersonal.cambiaReportaA(reporta);
                    cout << "Actualizado" << endl;
                    JefePersonal.imprime();
                } else {
                    cout << " Clave incorrecta" << endl;
                }
                break;
            default:
                cout << "Eleccion incorrecta" << endl;
        }
        getch();
        
    }

    return 0;
}