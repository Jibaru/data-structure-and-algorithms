/*
1.	Considere la siguiente relación de herencia entre clases. Defina las clases Mamífero,
Vacuno y Equino de tal manera que pueda declarar un arreglo polimórfico, es decir, un 
arreglo que pueda almacenar objetos de diferentes tipos, en este caso de las tres clases 
indicadas. Decida qué atributos y métodos incluir, tenga en cuenta lo que se pide a 
continuación. Escriba un programa de aplicación en C++ que pueda, por medio de menús:
á) Imprimir todos los atributos de objetos tipo Mamífero, vacuno y Equino.
b)	Dar de alta nuevos objetos, de cualquiera de los 3 tipos mencionados.
c)	Dar de baja un objeto previamente almacenado.
d)	Actualizar el establecimiento donde habita alguno de los animales. El dato que dará 
el usuario será la clave del animal y el nombre del esta¬blecimiento al cual fue trasladado.
Mamífero <- Vacuno
Mamífero <- Equino
*/
#include "../EJEMPLOS/4.1.cpp"
#include <conio.h>
#include <string.h>

class Mamifero {
protected:
    int clave;
    char nombre[60];
    char establecimiento[60];
    char alimento[10];
public:
    Mamifero();
    Mamifero(int, char[], char[], char[]);
    int obtenerClave();
    void cambiarEstablecimiento(char[]);
    void lectura();
    void escritura();
    bool operator==(Mamifero&);
    bool operator!=(Mamifero&);
    friend istream& operator >>(istream&, Mamifero&);
    friend ostream& operator <<(ostream&, Mamifero&);
};

Mamifero::Mamifero() {}

Mamifero::Mamifero(int clave, char nombre[], char establecimiento[], char alimento[])
{
    this->clave = clave;
    strcpy(this->nombre, nombre);
    strcpy(this->establecimiento, establecimiento);
    strcpy(this->alimento, alimento);
}

int Mamifero::obtenerClave()
{
    return clave;
}

void Mamifero::cambiarEstablecimiento(char establecimiento[])
{
    strcpy(this->establecimiento, establecimiento);  
}

void Mamifero::lectura()
{
    cout << "Clave: ";
    cin >> clave;
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(nombre, 60);
    cout << "Establecimiento: ";
    cin.getline(establecimiento, 60);
    cout << "Alimento: ";
    cin.getline(alimento, 60);
}

void Mamifero::escritura()
{
    cout << "Clave: " << clave << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Establecimiento: " << establecimiento << endl;
    cout << "Alimento: " << alimento << endl;
}

bool Mamifero::operator==(Mamifero& otro)
{
    if(clave != otro.clave) {
        return false;
    }
    if(strcmp(nombre, otro.nombre) != 0) {
        return false;
    }

    if(strcmp(establecimiento, otro.establecimiento) != 0) {
        return false;
    }
    if(strcmp(alimento, otro.alimento) != 0) {
        return false;
    }
    return true;
}

bool Mamifero::operator!=(Mamifero& otro)
{
    return !(*this == otro);
}

istream& operator>>(istream& entrada, Mamifero& obj)
{
    cout << "Clave: ";
    entrada >> obj.clave;
    cout << "Nombre: ";
    entrada.ignore();
    entrada.getline(obj.nombre, 60);
    cout << "Establecimiento: ";
    entrada.getline(obj.establecimiento, 60);
    cout << "Alimento: ";
    entrada.getline(obj.alimento, 60);
    return entrada; 
}

ostream& operator<<(ostream& salida, Mamifero& obj)
{
    salida << "Clave: " << obj.clave << endl;
    salida << "Nombre: " << obj.nombre << endl;
    salida << "Establecimiento: " << obj.establecimiento << endl;
    salida << "Alimento: " << obj.alimento << endl;
    return salida;
}

class Vacuno : public Mamifero {
private:
    char tipoCarne[60];
public:
    Vacuno();
    Vacuno(int, char[], char[], char[], char[]);
    void lectura();
    void escritura();
};

Vacuno::Vacuno() : Mamifero() {}

Vacuno::Vacuno(int clave, char nombre[], char establecimiento[], char alimento[], char tipoCarne[]) : 
Mamifero(clave, nombre, establecimiento, alimento)
{
    strcpy(this->tipoCarne, tipoCarne);
}

void Vacuno::lectura()
{
    Mamifero::lectura();
    cout << "Tipo carne: ";
    cin.getline(tipoCarne, 60);
}

void Vacuno::escritura()
{
    Mamifero::escritura();
    cout << "Tipo carne: " << tipoCarne << endl;
}

class Equino : public Mamifero {
private:
    char color[60];
public:
    Equino();
    Equino(int, char[], char[], char[], char[]);
    void lectura();
    void escritura();
};

Equino::Equino() : Mamifero() {}

Equino::Equino(int clave, char nombre[], char establecimiento[], char alimento[], char color[]) : 
Mamifero(clave, nombre, establecimiento, alimento)
{
    strcpy(this->color, color);
}

void Equino::lectura()
{
    Mamifero::lectura();
    cout << "Color: ";
    cin.getline(color, 60);
}

void Equino::escritura()
{
    Mamifero::escritura();
    cout << "Color: " << color << endl;
}

int menuOpciones()
{
    int opc;

    do {
        cout << "1-Ver todos" << endl;
        cout << "2-Dar de alta a nuevo mamifero" << endl;
        cout << "3-Dar de baja por clave" << endl;
        cout << "4-Cambiar establecimiento por clave" << endl;
        cout << "5-Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> opc;
    } while(opc < 1 || opc > 5);
    return opc;
}

int main()
{
    Arreglo<Mamifero> mamiferos = Arreglo<Mamifero>();
    Mamifero mamiferoTemp;
    Vacuno vacunotemp;
    Equino equinoTemp;

    int opc, tipo, clave, i;
    char establecimiento[60];

    do {

        opc = menuOpciones();

        switch(opc) {
            case 1: {
                for(i = 0; i < mamiferos.tamanio(); i++) {
                    cout << "\nMamifero " << i + 1 << ":" << endl;
                    mamiferos.obtener(i)->escritura();
                }
                break;
            }
            case 2: {
                cout << "1-Mamifero" << endl;
                cout << "2-Vacuno" << endl;
                cout << "3-Equino" << endl;
                cout << "Opcion: ";
                cin >> tipo;

                if(tipo == 1) {
                    mamiferoTemp = Mamifero();
                    mamiferoTemp.lectura();
                    mamiferos.InsertaDesordenado(mamiferoTemp);
                } else if(tipo == 2) {
                    vacunotemp = Vacuno();
                    vacunotemp.lectura();
                    mamiferos.InsertaDesordenado(vacunotemp);
                } else if(tipo == 3) {
                    equinoTemp = Equino();
                    equinoTemp.lectura();
                    mamiferos.InsertaDesordenado(equinoTemp);
                }
                break;
            }
            case 3: {
                cout << "Ingrese clave: ";
                cin >> clave;
                i = 0;
                while(i < mamiferos.tamanio() && mamiferos.obtener(i)->obtenerClave() != clave) {
                    i++;
                }

                if(i < mamiferos.tamanio()) {
                    mamiferos.EliminaDesordenado(*mamiferos.obtener(i));
                } else {
                    cout << "No existe un mamifero con dicha clave " << endl;
                }

                break;
            }

            case 4: {
                cout << "Ingrese clave: ";
                cin >> clave;
                i = 0;
                while(i < mamiferos.tamanio() && mamiferos.obtener(i)->obtenerClave() != clave) {
                    i++;
                }

                if(i < mamiferos.tamanio()) {
                    cout << "Nuevo establecimiento: ";
                    cin.ignore();
                    cin.getline(establecimiento, 60);
                    mamiferos.obtener(i)->cambiarEstablecimiento(establecimiento);
                } else {
                    cout << "No existe un mamifero con dicha clave " << endl;
                }

                break;
            }

            case 5: {
                cout << "Fin del programa" << endl;
                break;
            }
        }
        getch();

    } while(opc != 5);

    return 0;
}