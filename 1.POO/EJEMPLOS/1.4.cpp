/* La clase Cliente define a un cliente de banco.Se tienen los
atributos privados:Nombre, Direccion, Telefono, Saldo, TipoDeCuenta y
NumDeCuenta. Además, en la sección pública de la clase, se incluyeron
los métodos necesarios para imprimir los atributos de un cliente,
obtener su saldo, obtener el tipo de cuenta, hacer un retiro y un
depósito a la cuenta. */
#include <iostream>
using namespace std;

class Cliente
{
private:
	char Nombre[64], Direccion [64], Telefono[5];
	float Saldo;
	int TipoDeCuenta, NumDeCuenta; 
public:
	void ImprimeDatos(); 
	float ObtenerSaldo(); 
	int ObtenerTipoCta(); 
	int HacerRetiro(float);
	void HacerDeposito(float);
};

/* Método que despliega los datos de un cliente. */
void Cliente::ImprimeDatos()
{
	cout << "Nombre: " << Nombre << endl;
	cout << "Direccion: " << Direccion << endl;
	cout << "Teléfono: " << Telefono << endl;
	cout << "Saldo: " << Saldo << endl;
	cout << "Tipo cuenta: " << TipoDeCuenta << endl;
	cout << "Nro de cuenta: " << NumDeCuenta << endl;
}

/* Método que permite, a usuarios e.xternos a la clase, conocer el saldo
de un cliente .*/
float Cliente::ObtenerSaldo()
{
	return Saldo;
}

/*Método que permite, a usuarios externos a la clase, conocer el tipo"
de cuenta de un cliente.*/
int Cliente ::ObtenerTipoCta()
{
	return TipoDeCuenta;
}

/* Método que registra un retiro en la cuenta de un cliente.*/
int Cliente::HacerRetiro(float Monto)
{
	int Respuesta= 1;
	/*Verifica que haya dinero suficiente en la cuenta. */
	if ((Saldo - Monto)< 0)
		Respuesta = 0;
	else
		Saldo = Saldo - Monto;

	return Respuesta;
}

/* Método que registra un depósito en la cuenta de un cliente.*/
void Cliente::HacerDeposito(float Monto)
{
	Saldo = Saldo + Monto;
}

/* Función que usa la clase Cliente: se declaran dos objetos tipo
•Cliente y por medio de los métodos se registran retiros y depósitos en
•sus cuentas.*/
void UsaClaseCliente()
{
	float SaldoCli;

	/* Declaración de dos objetos de la clase Cliente.*/ 
	Cliente ObjClien1, ObjClien2;

	/* Se obtiene el saldo del cliente, asumiendo que previamente le fue"
	asignado un valor.*/

	SaldoCli = ObjClien2.ObtenerSaldo();
	cout<< "El saldo del cliente es: " << SaldoCli << endl;
	/* Se hace un retiro de la cuenta de cheques de un cliente: se
	verifica que tenga una cuenta de cheques (1), en cuyo caso se
	efectúa el retiro. */

	if (ObjClien1.ObtenerTipoCta() == 1) 
		if (ObjClien1.HacerRetiro(150.0))
			cout<<"\nRetiro realizado con éxito.Cuenta actualizada.\n"; 
		else
			cout<<"\nNo tiene saldo suficiente para realizar ese retiro.\n";
	else
		cout << "\n Para realizar un retiro debe ser una cuenta de cheques.\n";

	/* Se hace un depósito en la cuenta de un cliente :se registra el
	nuevo saldo. */
	ObjClien2.HacerDeposito(50000.00);
}

int main(){

	UsaClaseCliente();
	return 0;
}