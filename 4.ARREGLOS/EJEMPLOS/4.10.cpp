/* Se declara la clase Cliente la cual define un cliente por medio de 
los atributos: Nombre, Dirección, Teléfono, Saldo, Tipo de Cuenta y 
Número de Cuenta, y de algunos métodos que permiten el manejo de los 
mismos. Para la clase Cliente se definieron dos métodos constructores,
uno de los cuales es por omisión. Asimismo, se desarrolla una pequeña 
aplicación que hace uso de la clase definida. */
#include <iostream>
#include <string.h>
using namespace std;

class Cliente
{
private:
    char Nombre[64], Direccion[32], Telefono[10];
    float Saldo;
    int TipoDeCuenta, NumDeCuenta;
public:
    Cliente();
    Cliente(char [],char [], char [], float, int , int);
    float ObtenerSaldo();
    void ImprimeDatos();
    int ObtenerTipoCta();
    int ObtenerNumCta();
    void HacerRetiro(float);
    void HacerDeposito(float);
};

/* Definición del método constructor por omisión. */
Cliente::Cliente()
{}

/* Definición del método constructor con parámetros. */
Cliente::Cliente(char Nom[],char Dir[], char Tel[], float Sal, int TCta, int NoCta)
{
    strcpy(Nombre, Nom);
    strcpy(Direccion, Dir);
    strcpy(Telefono, Tel);
    Saldo= Sal;
    TipoDeCuenta= TCta;
    NumDeCuenta= NoCta;
}

/* Método que permite tener acceso, a usuarios externos a la clase, al 
saldo de un cliente. */
float Cliente::ObtenerSaldo()
{
    return Saldo;
}

/* Método que despliega en pantalla los atributos de un cliente. */
void Cliente::ImprimeDatos()
{
    cout << "Nombre: " << Nombre << "\n";
    cout << "Dirección: " << Direccion << "\n";
    cout << "Teléfono: " << Telefono << "\n1";
    cout << "Saldo: " << Saldo << "\n1";
    cout << "Tipo de Cuenta: " << TipoDeCuenta << "\n";
    cout << "Número de Cuenta: " << NumDeCuenta << "\n";
}

/* Método que permite tener acceso, a usuarios externos a la clase, al
tipo de cuenta de un cliente. */
int Cliente::ObtenerTipoCta()
{
    return TipoDeCuenta;
}

/* Método que permite tener acceso, a usuarios externos a la clase, al
número de cuenta de un cliente. */
int Cliente::ObtenerNumCta()
{
    return NumDeCuenta;
}

/* Método para registrar un retiro de una cuenta del cliente. El método 
verifica que el saldo de la cuenta sea mayor o igual al monto que va retirar. 
Si se cumple esta condición, actualiza el saldo. En caso contrario, imprime 
un mensaje. */
void Cliente::HacerRetiro(float Monto)
{
    if ((Saldo - Monto) < 0)
        cout << "No se puede hacer el retiro.\n ";
    else
        Saldo= Saldo - Monto;
}

/* Método que registra un depósito a la cuenta del cliente. Actualiza el saldo. */
void Cliente::HacerDeposito(float Monto)
{
    Saldo= Saldo + Monto;
}

/* Función que usa un arreglo de objetos tipo Cliente. Se realizan 
algunas operaciones en las cuentas de los clientes de dos bancos. */
void UsaArregloObjetos ()
{
    int Indice, TipoC, NumC;
    float Saldo, Monto;
    char Nom[64], Direc[64], Telef[64];
    /* Declaración de dos arreglos de 100 objetos de tipo Cliente. Se 
    hace uso del constructor por omisión. */
    Cliente ClientesBanco1[100];
    Cliente ClientesBanco2[100];
    /* Se crean tres objetos de tipo Cliente usando el constructor con parámetros. */
    Cliente ObjCli1((char*)"Laura", (char*)"Insurgentes 2564", (char*)"55559900", 28000, 2, 2509);
    Cliente ObjCli2((char*)"Juan", (char*)"Reforma 3600", (char*)"55408881", 4000, 1, 8324 );
    Cliente ObjCli3((char*)"Tomas", (char*)"Tlalpan 1005", (char*)"56703311", 20000, 2, 7604);

    /* Asignación de objetos al arreglo correspondiente al primer banco. */
    ClientesBanco1[0]= ObjCli1;
    ClientesBanco1[1]= ObjCli2;
    ClientesBanco1[2]= ObjCli3;

    /* Impresión de los datos correspondientes a los clientes del primer banco. */
    for (Indice= 0; Indice < 3; Indice++)
        ClientesBanco1[Indice].ImprimeDatos();

    /* Lectura de los datos de los clientes del segundo banco. Primero se leerán 
    valores para cada uno de los atributos definidos en la clase Cliente. 
    Posteriormente se creará un objeto usando el método constructor con parámetros
    y finalmente se asignará dicho objeto a una ^casilla del arreglo. Estos pasos
    se repiten para cada cliente. */
    for (Indice= 0; Indice < 20; Indice++)
    {
        cout << "\n\nIngrese datos del cliente: " << Indice + 1 << "\n\n";
        cin >> Nom >> Direc >> Telef >> Saldo>> TipoC >> NumC;
        Cliente ObjCli(Nom, Direc, Telef, Saldo, TipoC, NumC);
        ClientesBanco2[Indice]= ObjCli;
    }

    /* Registro de un retiro de $1000 de la cuenta del tercer cliente del segundo banco. */
    ClientesBanco2[2].HacerRetiro(1000);

    /* Impresión de los datos de todos los clientes que tienen un saldo tayor a $10000. */
    cout << "\nReporte de clientes con saldo superior a $10000\n";
    for (Indice= 0; Indice < 20; Indice++)
        if (ClientesBanco2[Indice].ObtenerSaldo() > 10000)
            ClientesBanco2[Indice].ImprimeDatos();

    /* Registro de un depósito a cierta cuenta. El número de cuenta y el monto son dados por
    el usuario. */
    cout << "\n\nIngrese el numero de cuenta a la cual va a depositar y el monto del deposito \n";
    cin >> NumC >> Monto;

    /* Se aplica búsqueda secuencial para buscar el cliente con el número de cuenta dado. */
    Indice= 0;
    while (Indice < 20 && NumC != ClientesBanco2[Indice].ObtenerNumCta())
        Indice++;
    
    if (Indice < 20)
        ClientesBanco2[Indice].HacerDeposito(Monto);
    else
        cout<<"\nNo esta registrado ningún cliente con el numero de cuenta dado. \n";
}

int main() {

    UsaArregloObjetos();

    return 0;
}