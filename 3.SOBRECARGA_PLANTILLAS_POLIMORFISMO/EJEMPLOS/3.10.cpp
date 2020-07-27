/*Se define la clase Insecto que incluye un método virtual, el cual 
se redefinirá en las clases derivadas: Mosca y Cucaracha. El método 
virtual Imprime adoptará diferentes formas según la declaración del 
mismo en cada una de las clases derivadas. Además, en la clase se 
incluyó un destructor virtual. */
#include <iostream>
#include <string.h>
using namespace std;

class Insecto {
protected:
    char Nombre[30];
    int NumPatas;
    float TamCabeza, TamTorax, TamAbdomen;
public:
    Insecto(char*, int, float, float, float);
    virtual void Imprime();
    virtual ~Insecto() { }
};

/* Declaración del método constructor con parámetros. */
Insecto::Insecto(char *Nom, int NumP, float TamC, float TamT, float TamA)
{
    strcpy(Nombre, Nom);
    NumPatas= NumP;
    TamCabeza= TamC;
    TamTorax= TamT;
    TamAbdomen= TamA;
}

/* Método que despliega los valores de los atributos de un insecto. */
void Insecto::Imprime()
{
    cout << "Nombre: " << Nombre << endl;
    cout << "Numero de Patas: " << NumPatas << endl;
    cout << "Tamanio de Cabeza: " << TamCabeza << endl;
    cout << "Tamanio de Torax: " << TamTorax << endl;
    cout << "Tamanio de Abdomen: " << TamAbdomen << endl;
}

/* Definición de la clase Mosca, derivada de la clase Insecto. En el 
prototipo del método Imprime se puede omitir el uso de la palabra 
virtual. Se la incluyó sólo para ofrecer mayor claridad. */
class Mosca: public Insecto {
private:
    int NumAlas; public:
    Mosca(char *, int, float, float, float, int);
    virtual void Imprime();
    ~Mosca() { }
};

/* Declaración del método constructor con parámetros. Invoca al método 
constructor de la clase base. */
Mosca::Mosca(char *Nom, int Pat, float Cab, float Tor, float Abd, int Alas): 
       Insecto(Nom, Pat, Cab, Tor, Abd)
{
    NumAlas= Alas;
}

/* Método que despliega los valores de los atributos de una mosca. */
void Mosca::Imprime()
{
    Insecto::Imprime();
    cout << "Numero de Alas: " << NumAlas << endl;
}

/* Definición de la clase Cucaracha derivada de la clase Insecto. En el 
prototipo del método Imprime se puede omitir la palabra virtual, se la 
incluyó sólo para ofrecer mayor claridad. */
class Cucaracha: public Insecto {
private:
    char CaractCuerpo[30];
public:
    Cucaracha(char*, int, float, float, float, char*);
    virtual void Imprime();
    ~Cucaracha() { }
};

/* Declaración del método constructor con parámetros. Invoca al método 
constructor de la clase base. */
Cucaracha::Cucaracha(char *Nom, int Pat, float Cab, float Tor, float Abd, char *Cuer):
            Insecto(Nom, Pat, Cab, Tor, Abd)
{
    strcpy(CaractCuerpo, Cuer);
}

/* Método que despliega los valores de los atributos de una cucaracha. */
void Cucaracha::Imprime()
{
    Insecto::Imprime();
    cout << "Caracteristicas del cuerpo: " << CaractCuerpo << endl;
}

/* Función que usa las clases previamente definidas: se declaran objetos 
polimórficos y por medio de los métodos virtuales se trabaja con ellos. */
void UsaFuncionVirtual()
{
    /* Se crean dos apuntadores a objetos polimórficos. */
    Insecto *ObjInsecto1, *ObjInsecto2;
    Mosca ObjMosca((char*)"Mosca", 6, 3, 1, 2, 4);
    Cucaracha ObjCucaracha((char*)"Cucaracha", 6, 2, 8, 4, (char*)"Cuerpo Aplanado");
    /* Se asigna la dirección de los objetos de las clases derivadas a 
    los apuntadores a los objetos polimórficos. */
    ObjInsecto1= &ObjMosca;
    ObjInsecto2= &ObjCucaracha;
    /* Invoca al método correspondiente a la clase Mosca, a través del 
    objeto polimórfico. */
    ObjInsecto1->Imprime();
    /* Invoca al método correspondiente a la clase Mosca a través del 
    objeto tipo Mosca. */
    ObjMosca.Imprime();
    /* Invoca al método correspondiente a la clase Cucaracha, a través 
    del objeto polimórfico. */
    ObjInsecto2->Imprime();
    /* Invoca al método correspondiente a la clase Cucaracha a través 
    del objeto tipo Cucaracha. */
    ObjCucaracha.Imprime();
}

int main() {
    UsaFuncionVirtual();
    return 0;
}