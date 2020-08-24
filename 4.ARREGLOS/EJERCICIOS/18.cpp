/*
18.	Considere la siguiente relación de herencia entre clases. Defina las clases Arbol, Frutal 
y cítrico de tal manera que pueda declarar un arreglo polimórfico, es decir, un arreglo que 
pueda almacenar objetos de diferentes tipos, en este caso de las tres clases indicadas. 
Decida qué atributos y métodos incluir, tenga en cuenta lo que se pide más a continuación. 
Escriba una programa de aplicación en C++ que pueda, por medio de menús:
a)	Imprimir los atributos de objetos tipo Arbol, Frutal y Citrico.
b)	Dar de alta nuevos objetos, de cualquiera de los 3 tipos mencionados.
c)	Dar de baja un objeto previamente almacenado.
d)	Imprimir todos los datos de los objetos que tengan una altura mayor a los 2 metros.

Arbol <- Frutal <- Cítrico
*/
#include "../EJEMPLOS/4.1.cpp"
#include <conio.h>
#include <string.h>

class Arbol {
protected:
    char* nombre;
    float altura;
public:
    Arbol();
    Arbol(char*, float);
    float obtenerAltura();
    bool operator==(Arbol&);
    bool operator!=(Arbol&);
    friend ostream& operator<<(ostream&, Arbol&);
    friend istream& operator>>(istream&, Arbol&);
};

Arbol::Arbol() {}

Arbol::Arbol(char* nombre, float altura)
{
    this->nombre = new char[strlen(nombre) + 1];
    if(this->nombre != NULL) {
        strcpy(this->nombre, nombre);
    }
    this->altura = altura;
}

float Arbol::obtenerAltura()
{
    return altura;
}

bool Arbol::operator==(Arbol& obj)
{
    if(altura != obj.altura) {
        return false;
    }
    if(strcmp(nombre, obj.nombre) != 0) {
        return false;
    }
    return true;
}

bool Arbol::operator!=(Arbol& obj)
{
    return !(*this == obj);
}

ostream& operator<<(ostream& salida, Arbol& obj)
{
    salida << "Nombre: " << obj.nombre << endl;
    salida << "Altura: " << obj.altura << endl;
    return salida;
}

istream& operator>>(istream& entrada, Arbol& obj)
{
    char nom[60];
    cout << "Nombre: ";
    entrada.ignore();
    entrada.getline(nom, 60);
    obj.nombre = new char[strlen(nom) + 1];
    strcpy(obj.nombre, nom);
    cout << "Altura: ";
    cin >> obj.altura;
}

class Frutal : public Arbol {
protected:
    char* nombreFruto;
public:
    Frutal();
    Frutal(char*, float, char*);
    bool operator==(Frutal&);
    friend ostream& operator<<(ostream&, Frutal&);
    friend istream& operator>>(istream&, Frutal&);
};

Frutal::Frutal() : Arbol() {}

Frutal::Frutal(char* nombre, float altura, char* nomFruto) : 
Arbol(nombre, altura)
{
    nombreFruto = new char[strlen(nomFruto) + 1];
    if(nombreFruto != NULL) {
        strcpy(nombreFruto, nomFruto);
    }
}

bool Frutal::operator==(Frutal& obj)
{
    if(altura != obj.altura) {
        return false;
    }
    if(strcmp(nombre, obj.nombre) != 0) {
        return false;
    }
    if(strcmp(nombreFruto, obj.nombreFruto) != 0) {
        return false;
    }
    return true;
}

ostream& operator<<(ostream& salida, Frutal& obj)
{
    salida << "Nombre: " << obj.nombre << endl;
    salida << "Altura: " << obj.altura << endl;
    salida << "Nom. Fruto: " << obj.nombreFruto << endl;
    return salida;
}

istream& operator>>(istream& entrada, Frutal& obj)
{
    char nom[60];
    cout << "Nombre: ";
    entrada.ignore();
    entrada.getline(nom, 60);
    obj.nombre = new char[strlen(nom) + 1];
    strcpy(obj.nombre, nom);

    cout << "Nombre Fruto: ";
    entrada.getline(nom, 60);
    obj.nombreFruto = new char[strlen(nom) + 1];
    strcpy(obj.nombreFruto, nom);
    cout << "Altura: ";
    cin >> obj.altura;
}

class Citrico : public Frutal {
public:
    Citrico();
    Citrico(char* nomFruto, float altura);
    friend ostream& operator<<(ostream&, Citrico&);
    friend istream& operator>>(istream&, Citrico&);
};

Citrico::Citrico() : Frutal()
{
    nombre = new char[6];
    strcpy(nombre, "CITRICO");
}

Citrico::Citrico(char* nomFruto, float altura):
Frutal((char*)"CITRICO", altura, nombreFruto) {}

ostream& operator<<(ostream& salida, Citrico& obj)
{
    salida << "Nombre: " << obj.nombre << endl;
    salida << "Altura: " << obj.altura << endl;
    salida << "Nom. Fruto: " << obj.nombreFruto << endl;
    return salida;
}

istream& operator>>(istream& entrada, Citrico& obj)
{
    char nom[60];
    cout << "Nombre: ";
    entrada.ignore();
    entrada.getline(nom, 60);
    obj.nombre = new char[strlen(nom) + 1];
    strcpy(obj.nombre, nom);

    obj.nombreFruto = new char[6];
    strcpy(obj.nombreFruto, "CITRICO");
    cout << "Altura: ";
    cin >> obj.altura;
}

int menuOpciones()
{
    int opc;

    do {

        cout << "1-Ingresar datos iniciales" << endl;
        cout << "2-Imprimir todos los datos" << endl;
        cout << "3-Dar de alta" << endl;
        cout << "4-Dar de baja" << endl;
        cout << "5-Arboles con altura mayor a 2 metros" << endl;
        cout << "6-Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> opc;

    }while(opc < 1 && opc > 6);
    return opc;
}

int main() {
    Arreglo<Arbol> arboles = Arreglo<Arbol>();
    Arbol *arbol;
    Frutal frut;
    Citrico citric;
    int opc, tipo, pos, i;
    do {

        opc = menuOpciones();

        switch(opc) {
            case 1: {
                arboles.Lectura();
                break;
            }
            case 2: {
                arboles.Escribe();
                break;
            }

            case 3: {
                cout << "Ingrese el tipo: ";
                cout << "1-Arbol" << endl;
                cout << "2-Frutal" << endl;
                cout << "3-Citrico" << endl;
                cin >> tipo;

                if(tipo == 1) {
                    arbol = new Arbol();
                } else if(tipo == 2) {
                    arbol = new Frutal();
                } else if(tipo == 3) {
                    arbol = new Citrico();
                }
                cin >> *arbol;
                arboles.InsertaDesordenado(*arbol);
                break;
            }

            case 4: {
                cout << "Posicion: ";
                cin >> pos;
                if(pos >= 0 && pos < arboles.tamanio()) {
                    arbol = arboles.obtener(pos);
                    arboles.EliminaDesordenado(*arbol);
                } else {
                    cout << "Posicion incorrecta" << endl;
                }
                break;
            }

            case 5: {
                cout << "Arboles con altura mayor a dos metros:" << endl;
                for(i = 0; i < arboles.tamanio(); i++) {
                    arbol = arboles.obtener(i);
                    if((*arbol).obtenerAltura() > 2) {
                        cout << "Arbol "<< i + 1 << endl;
                        cout << arbol << endl;
                    }
                }
                break;
            }

            case 6: {
                cout << "Fin del programa" << endl;
                break;
            }
        }

        getch();

    }while(opc != 10);

    return 0;
}