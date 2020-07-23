/*
6.	Considere la relación de herencia que se muestra en la siguiente figura. La misma involucra tres 
clases: AlimVegetal, AlimAnimal y AlimPreparado. Esta última representa a los alimentos preparados 
que pueden incluir como base alimentos vegetales y/o animales.

Escriba un programa en C++ que:
á) Declare y cree un objeto llamado Tallarines de tipo AlimPreparado. Los tallarines se preparan con harina de trigo, huevo y agua. Se cue¬cen en agua hirviendo.
b)	Declare y cree un objeto llamado EnsaladaVerde de tipo AlimPreparado. La ensalada verde se prepara con diferentes tipos de lechuga y se condimenta con aceite de oliva, vinagre balsámico y sal (esta última no puede ser representada). No se cuece.
c)	Imprima los atributos de los Tallarines y de la EnsaladaVerde.
d)	Declare y cree un objeto llamado LechugaFrancesa de tipo AlimVegetal.
e)	En el objeto LechugaFrancesa actualice el valor del atributo EpocaDisponibie a “todo el año”.
f)	Declare y cree un objeto llamado salmón de tipo AlimAnimai.
g)	Imprima los atributos de la LechugaFrancesa y del Salmón.

*/
#include <iostream>
#include <string.h>

using namespace std;

class AlimVegetal {
protected:
    char* Nombre;
    char* EpocaDisponible;
    int Vitaminas;
    int Minerales;
    int ProteinasVeg;
public:
    AlimVegetal();
    AlimVegetal(char*, char*, int, int, int);
    void imprime();
    void cambiaEpoca(char*);
};

AlimVegetal::AlimVegetal(){}

AlimVegetal::AlimVegetal(char* nom, char* epoca, int vita, int mine, int prote)
{
    Nombre = new char[strlen(nom) + 1];
    EpocaDisponible = new char[strlen(epoca) + 1];

    strcpy(Nombre, nom);
    strcpy(EpocaDisponible, epoca);
    Vitaminas = vita;
    Minerales = mine;
    ProteinasVeg = prote;
}

void AlimVegetal::imprime()
{
    cout << "Nombre Veg: " << Nombre << endl;
    cout << "Epoca disponible: " << EpocaDisponible << endl;
    cout << "Vitaminas: " << Vitaminas << endl;
    cout << "Minerales: " << Minerales << endl;
    cout << "Proteinas: " << ProteinasVeg << endl;
}

void AlimVegetal::cambiaEpoca(char* epoca)
{
    EpocaDisponible = new char[strlen(epoca) + 1];
    strcpy(EpocaDisponible, epoca);
}

class AlimAnimal {
protected:
    char* Nombre;
    char* Origen;
    int Vitaminas;
    int Minerales;
    int ProteinasAnim;
    int Grasa;
public:
    AlimAnimal();
    AlimAnimal(char*, char*, int, int, int, int);
    void imprime();
};

AlimAnimal::AlimAnimal(){}

AlimAnimal::AlimAnimal(char* nom, char* ori, int vita, int mine, int prote, int gras)
{
    Nombre = new char[strlen(nom) + 1];
    Origen = new char[strlen(ori) + 1];
    strcpy(Nombre, nom);
    strcpy(Origen, ori);
    Vitaminas = vita;
    Minerales = mine;
    ProteinasAnim = prote;
    Grasa = gras;
}

void AlimAnimal::imprime()
{
    cout << "Nombre Anm: " << Nombre << endl;
    cout << "Origen: " << Origen << endl;
    cout << "Vitaminas: " << Vitaminas << endl;
    cout << "Minerales: " << Minerales << endl;
    cout << "Proteinas: " << ProteinasAnim << endl;
    cout << "Grasa: " << Grasa << endl;
}

class AlimPreparado : public AlimVegetal, public AlimAnimal {
private:
    char* Nombre;
    int Cocido;
public:
    AlimPreparado();
    AlimPreparado(char*, int, char*, char*, char*, char*, int, int, int, int, int, int, int);
    void imprime();
};

AlimPreparado::AlimPreparado(){}

AlimPreparado::AlimPreparado(
    char* nom, 
    int coc, 
    char* nomVeg,
    char* epocaVeg,
    char* nomAnm,
    char* oriAnm,
    int vitaVeg = 0, 
    int mineVeg = 0, 
    int proteVeg = 0,
    int vitaAnm = 0,
    int mineAnm = 0, 
    int proteAnm = 0, 
    int grasAnm = 0) : 
    AlimVegetal(nomVeg, epocaVeg, vitaVeg, mineVeg, proteVeg),
    AlimAnimal(nomAnm, oriAnm, vitaAnm, mineAnm, proteAnm, grasAnm)
{
    Nombre = new char[strlen(nom) + 1];
    strcpy(Nombre, nom);
    Cocido = coc;
}

void AlimPreparado::imprime()
{
    AlimVegetal::imprime();
    AlimAnimal::imprime();
    cout << "Nombre Prep.: " << Nombre << endl;
    cout << "Cocido: " << (Cocido == 1 ? "Si": "No") << endl;
}

int main()
{
    AlimPreparado tallarines(
        (char*)"Tallarines", 
        1, 
        (char*)"Harina de trigo", 
        (char*)"Primavera", 
        (char*)"Huevo", 
        (char*)"Gallina",
        14, 45, 12, 45, 2, 65, 6);
    AlimPreparado ensaladaVerde(
        (char*)"Ensalada verde", 
        0, 
        (char*)"Lechuga, aceite, vinagre, sal", 
        (char*)"Invierno", 
        (char*)"Ninguno", 
        (char*)"Ninguno",
        12, 23, 45);

    tallarines.imprime();
    cout << endl;
    ensaladaVerde.imprime();
    cout << endl;

    AlimVegetal lechugaFrancesa((char*)"Lechuga francesa", (char*)"Ninguna", 12, 41, 1);
    AlimAnimal salmon((char*)"Salmon", (char*)"Pez", 46, 2, 103, 35);

    lechugaFrancesa.cambiaEpoca((char*)"Todo el anio");

    lechugaFrancesa.imprime();
    cout << endl;
    salmon.imprime();

    return 0;
}