/*
12.	Utilice un árbol binario de búsqueda para almacenar datos de 
tipo clientes bancarios. Para ello defina una clase ClienteBanco, 
con los atributos y los métodos que considere necesarios, atendiendo 
lo que se pide más abajo. El número de cliente será el atributo según 
el que se ordenará la información en el árbol. Escriba un programa en 
C++, que mediante un menú de opciones, permita:
a)	Generar un reporte de todos los clientes de un banco, ordenados 
por su número de cliente.
b)	Generar un reporte de todos los clientes que tengan una antigüedad 
mayor a los 5 años. Puede darle generalidad a su solución, dejando el 
número de años como un dato a ingresar por el usuario.
c)	Generar un reporte de todos los clientes que tengan como mínimo dos 
cuentas diferentes en el banco.
d)	Dar de alta un nuevo cliente. El usuario proporcionará todos los 
datos del cliente a registrar.
e)	Dar de baja un cliente registrado. El usuario dará como dato el 
número del cliente.
f)	Actualizar el saldo de alguna de las cuentas de un cliente. El usuario 
dará como datos el número del cliente, el número de la cuenta a actualizar 
y el nuevo saldo.
g)	Actualizar los datos personales (por ejemplo domicilio, teléfono casa, 
teléfono oficina, etcétera) de un cliente. Su programa debe permitir que 
en la misma opción se pueda modificar uno o todos los datos personales.
*/
#include <iostream>
#include <string.h>
#include <conio.h>
#include "../../lib/arboles/ArbolBinBusqueda.h"
#include "../../lib/arreglos/Arreglo.h"

using namespace std;

class ClienteBanco
{
private:
    int nroCliente;
    int nroAnios;
    char domicilio[60];
    char telefono[10];
    float saldoCuentas[60];
    int nroCuentas;
public:
    ClienteBanco();
    ClienteBanco(int);
    void cambiarSaldo(int, float);
    void cambiarDatosPersonales();
    int regresaNroCliente();
    int regresaNroAnios();
    int regresaNroCuentas();
    int operator<(ClienteBanco&);
    int operator>(ClienteBanco&);
    friend ostream& operator<<(ostream&, ClienteBanco&);
    friend istream& operator>>(istream&, ClienteBanco&);
};

ClienteBanco::ClienteBanco(){}

ClienteBanco::ClienteBanco(int nroCli)
{
    nroCliente = nroCli;
}

void ClienteBanco::cambiarSaldo(int pos, float nuevoSaldo)
{
    if(pos < nroCuentas) {
        saldoCuentas[pos] = nuevoSaldo;
    }
}

int ClienteBanco::regresaNroCliente()
{
    return nroCliente;
}

int ClienteBanco::regresaNroAnios()
{
    return nroAnios;
}

int ClienteBanco::regresaNroCuentas()
{
    return nroCuentas;
}

void ClienteBanco::cambiarDatosPersonales()
{
    cout << "Domicilio: ";
    cin >> domicilio;
    cout << "Telefono: ";
    cin >> telefono;
}

int ClienteBanco::operator<(ClienteBanco& obj)
{
    return nroCliente < obj.nroCliente;
}

int ClienteBanco::operator>(ClienteBanco& obj)
{
    return nroCliente > obj.nroCliente;
}

ostream& operator<<(ostream& salida, ClienteBanco& obj)
{
    salida << "Nro Cliente: " << obj.nroCliente << endl;
    salida << "Nro anios: " << obj.nroAnios << endl;
    salida << "Domicilio: " << obj.domicilio << endl;
    salida << "Telefono: " << obj.domicilio << endl;
    for(int i = 0; i < obj.nroCuentas; i++) {
        salida << " Saldo Cuenta " << i + 1 << ": " << obj.saldoCuentas[i] << endl;
    }

    return salida;
}

istream& operator>>(istream& entrada, ClienteBanco& obj)
{
    cout << "Nro Cliente: ";
    entrada >> obj.nroCliente;
    cout << "Nro Anios: ";
    entrada >> obj.nroAnios;
    cout << "Domicilio: ";
    entrada >> obj.domicilio;
    cout << "Telefono: ";
    entrada >> obj.telefono;
    cout << "Nro cuentas: ";
    entrada >> obj.nroCuentas;
    for(int i = 0; i < obj.nroCuentas; i++) {
        cout << " Saldo cuenta " << i + 1 << ": ";
        entrada >> obj.saldoCuentas[i];
    }
    return entrada;
}

int menuOpciones()
{
    int opc;
    do {
        cout << "\n1-Reporte de todos los clientes" << endl;
        cout << "2-Reporte de clientes con antiguedad mayor a 5 anios" << endl;
        cout << "3-Reporte de clientes con minimo 2 cuentas" << endl;
        cout << "4-Dar de alta un nuevo cliente" << endl;
        cout << "5-Dar de baja un cliente" << endl;
        cout << "6-Actualizar el saldo de alguna cuenta de un cliente" << endl;
        cout << "7-Actualizar datos personales de un cliente" << endl;
        cout << "8-Salir del sistema" << endl;
        cout << "Ingrese opcion: ";
        cin >> opc;
        cout << endl;
    } while(opc < 1 || opc > 8);

    return opc;
}

int main()
{
    int opc, nroCliente, posCuenta, i;
    float nuevoSaldo;
    Arreglo<int> claves = Arreglo<int>();
    ArbolBinBus<ClienteBanco> clientes = ArbolBinBus<ClienteBanco>();
    ClienteBanco cliente;
    NodoArbol<ClienteBanco> *nodoCliente;
    do {
        opc = menuOpciones();

        switch(opc) {
            case 1: {
                if(clientes.RegresaRaiz()) {
                    clientes.ImprimePorNiveles();
                }
                break;
            }
            case 2: {
                for(i = 0; i < claves.tamanio(); i++) {
                    cliente = ClienteBanco(*(claves.obtener(i)));
                    nodoCliente = clientes.Busqueda(clientes.RegresaRaiz(), cliente);
                    cliente = nodoCliente->RegresaInfo();
                    if(cliente.regresaNroAnios() > 5) {
                        cout << cliente;
                    }
                }
                break;
            }
            case 3: {
                for(i = 0; i < claves.tamanio(); i++) {
                    cliente = ClienteBanco(*(claves.obtener(i)));
                    nodoCliente = clientes.Busqueda(clientes.RegresaRaiz(), cliente);
                    cliente = nodoCliente->RegresaInfo();
                    if(cliente.regresaNroCuentas() >= 2) {
                        cout << cliente;
                    }
                }
                break;
            }
            case 4: {
                cliente = ClienteBanco();
                cin >> cliente;
                clientes.InsertaNodoSinRep(clientes.RegresaRaiz(), cliente);
                claves.insertarSinRep(cliente.regresaNroCliente());
                break;
            }
            case 5: {
                cout << "Nro cliente: ";
                cin >> nroCliente;
                cliente = ClienteBanco(nroCliente);
                clientes.EliminaNodo(clientes.RegresaRaiz(), cliente);
                claves.eliminar(cliente.regresaNroCliente());
                break;
            }
            case 6: {
                cout << "Nro cliente: ";
                cin >> nroCliente;
                cliente = ClienteBanco(nroCliente);
                nodoCliente = clientes.Busqueda(clientes.RegresaRaiz(), cliente);
                if(nodoCliente) {
                    cout << "Pos cuenta: ";
                    cin >> posCuenta;
                    cout << "Nuevo saldo: ";
                    cin >> nuevoSaldo;
                    cliente = nodoCliente->RegresaInfo();
                    cliente.cambiarSaldo(posCuenta, nuevoSaldo);
                    clientes.EliminaNodo(clientes.RegresaRaiz(), cliente);
                    clientes.InsertaNodoSinRep(clientes.RegresaRaiz(), cliente);
                } else {
                    cout << "No existe el cliente" << endl;
                }
                break;
            }
            case 7: {
                cout << "Nro cliente: ";
                cin >> nroCliente;
                cliente = ClienteBanco(nroCliente);
                nodoCliente = clientes.Busqueda(clientes.RegresaRaiz(), cliente);
                if(nodoCliente) {
                    cliente = nodoCliente->RegresaInfo();
                    cliente.cambiarDatosPersonales();
                    clientes.EliminaNodo(clientes.RegresaRaiz(), cliente);
                    clientes.InsertaNodoSinRep(clientes.RegresaRaiz(), cliente);
                } else {
                    cout << "No existe el cliente" << endl;
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