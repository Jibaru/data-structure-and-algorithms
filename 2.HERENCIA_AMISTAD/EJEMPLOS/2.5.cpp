/* La clase Vehículo se define por medio de los atributos privados
Marca, Placas y el Número de Motor, asi como por medio de un método
para desplegar los valores de los atributos y un constructor. Esta 
clase sirve como clase base para definir las clases Motocicleta y
Automóvil. De la clase Automóvil se deriva la clase Deportivo. */
#include <iostream>
#include <string.h>
using namespace std;

/* Definición de la clase Vehículo. */
class Vehiculo {
private:
    char Marca[32];
    int Placas, NumMotor;
public:
    Vehiculo(char *Mar, int Pla, int NM);
    void ImprimeVehiculo();
};

/* Declaración del método constructor con parámetros. */
Vehiculo::Vehiculo(char *Mar, int Pla, int NM)
{
    strcpy(Marca, Mar);
    Placas= Pla;
    NumMotor= NM;
}

/* Método que despliega los valores de los atributos de un vehiculo. */
void Vehiculo::ImprimeVehiculo()
{
    cout << "Marca: " << Marca << "\n";
    cout << "Placas: " << Placas << "\n";
    cout << "Número de Motor: " << NumMotor << "\n";
}

/* Se define la clase Motocicleta, derivada de Vehiculo, la cual tiene 
como atributos propios la Potencia del Motor y como método el que le 
permite desplegar sus atributos. */
class Motocicleta: public Vehiculo {
private:
    int PotMotor;
public:
    Motocicleta(char *Mar, int Pla, int NM, int PM);
    void ImprimeMotocicleta();
};

/* Declaración del método constructor. Invoca al método constructor de
la clase Vehículo. */
Motocicleta::Motocicleta(char *Mar, int Pla, int NM, int PM):
             Vehiculo(Mar, Pla, NM)
{
    PotMotor= PM;
}

/* Método que despliega los valores de los atributos de una motocicleta. */
void Motocicleta::ImprimeMotocicleta()
{
    Vehiculo::ImprimeVehiculo();
    cout << "Potencia del Motor: " << PotMotor << "\n";
}

/* Se define la clase Automóvil, derivada de Vehículo, la cual tiene
como atributos propios el Número de Puertas y como método el que le
permite desplegar sus atributos. */
class Automovil: public Vehiculo {
private:
    int NumPuertas;
public:
    Automovil(char *Mar, int Pla, int NM, int NP);
    void ImprimeAutomovil();
};

/* Declaración del método constructor. Invoca al método constructor de
la clase Vehiculo. */
Automovil::Automovil(char *Mar, int Pla, int NM, int NP):
           Vehiculo(Mar, Pla, NM)
{
    NumPuertas= NP;
}

/* Método que despliega los valores de los atributos de un automóvil. */
void Automovil::ImprimeAutomovil()
{
    Vehiculo::ImprimeVehiculo();
    cout << "Número de Puertas: " << NumPuertas << "\n";
}

/* Se define la clase Deportivo, derivada de Automóvil, la cual tiene
como atributo propio el Color y como método el que le permite desplegar 
sus atributos. */
class Deportivo: public Automovil 
{
private:
    char Color[8];
public:
    Deportivo (char *Mar, int Pla, int m, int NP, char *Col);
    void ImprimeDeportivo();
};

/* Declaración del método constructor. Invoca al constructor de la clase Automóvil. */
Deportivo::Deportivo(char *Mar, int Pla, int NM, int NP, char *Col):
           Automovil (Mar, Pla, NM, NP)
{
    strcpy(Color, Col);
}

/* Método que despliega los valores de los atributos de un automóvil deportivo. */
void Deportivo::ImprimeDeportivo()
{
    Automovil::ImprimeAutomovil();
    cout << "Color: " << Color << "\n";
}

/* Función que hace uso de las clases previamente definidas. */
void UsaHerencia()
{
    /* Declaración de un objeto de tipo Motocicleta. */
    Motocicleta Moto("Honda", 231, 2941, 225);
    /* Declaración de un objeto de tipo Automovil. */
    Automovil Auto("BMW", 569, 7436, 4);
    /* Declaración de un objeto de tipo Deportivo. */
    Deportivo AutoDep("Ferrari", 442, 52348, 2, "rojo");
    /* Despliega las características de la motocicleta. */ 
    Moto.ImprimeMotocicleta();
    /* Despliega las características del automóvil. */
    Auto.ImprimeAutomovil();
    /* Despliega las características del automóvil deportivo. */
    AutoDep.ImprimeDeportivo();
}
