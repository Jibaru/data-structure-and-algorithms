/*
17.	Defina la clase Automóvil teniendo en cuenta las especificaciones que se dan más adelante. 
Para decidir qué métodos incluir, lea cuidadosamente el resto del problema. Declare un arreglo 
de N (1< N < 120) objetos tipo Automóvil, el cual almacenará la flotilla de automóviles de una 
empresa. Asuma que los mismos serán dados de manera ordenada, crecientemente, por claveAuto. 
Escriba un programa en C++, que mediante menús pueda:
a)	Leer y validar N (1< N < 120).
b)	Leer los N elementos del arreglo.
c)	Imprimir los datos de todos los automóviles que hayan sido fabricados en cierto año. 
El usuario dará como dato el año deseado.
d)	Imprimir los datos de todos los automóviles que sean de cierta marca. El usuario dará 
como dato la marca.
e)	Imprimir los datos de todos los automóviles que sean de cierta marca y de cierto modelo. 
El usuario dará como dato la marca y el modelo.
f)	Cambiar el nombre de la persona a la cual se le ha asignado el automóvil. El usuario 
dará como dato la clave del automóvil y el nombre de la persona que ahora lo usará.
g)	Dada la clave de un automóvil, imprimir toda su información.
h)	Dar de alta un nuevo automóvil. El usuario ingresará como datos toda la información 
relacionada al nuevo automóvil.
i)	Dar de baja un automóvil existente. El usuario dará como dato la clave del automóvil 
que desea eliminar de la flotilla. 
Automóvil
CiaveAuto: int 
MarcaAuto: char[] 
Modelo: char[] 
AñoFabricacion: int 
PrecioCompra: float 
AsignadoA: char[]
Métodos de acceso y actualización
*/
#include "../EJEMPLOS/4.1.cpp"
#include <conio.h>
#include <string.h>

class Automovil {
private:
    int claveAuto;
    char marcaAuto[60];
    char modelo[60];
    int anioFab;
    char asignadoA[60];
public:
    Automovil();
    Automovil(int, char[], char[], int, char[]);
    int obtenerClave();
    int obtenerAnioFab();
    char* obtenerMarca();
    char* obtenerModelo();
    void cambiaAsignadoA(char[]);
    bool operator==(Automovil&);
    bool operator!=(Automovil&);
    friend ostream& operator<<(ostream&, Automovil&);
    friend istream& operator>>(istream&, Automovil&);
};

Automovil::Automovil() {}

Automovil::Automovil(int claveAuto, char marcaAuto[60], char modelo[60], int anioFab, char asignadoA[60])
{
    this->claveAuto = claveAuto;
    this->anioFab = anioFab;
    strcpy(this->marcaAuto, marcaAuto);
    strcpy(this->modelo, modelo);
    strcpy(this->asignadoA, asignadoA);
}

int Automovil::obtenerClave()
{
    return claveAuto;
}

int Automovil::obtenerAnioFab()
{
    return anioFab;
}

char* Automovil::obtenerMarca()
{
    return marcaAuto;
}

char* Automovil::obtenerModelo()
{
    return modelo;
}

void Automovil::cambiaAsignadoA(char asignadoA[])
{
    strcpy(this->asignadoA, asignadoA);
}

bool Automovil::operator==(Automovil& otro)
{
    if(claveAuto != otro.claveAuto) {
        return false;
    }
    if(anioFab != otro.anioFab) {
        return false;
    }
    if(strcmp(marcaAuto, otro.marcaAuto) != 0) {
        return false;
    }
    if(strcmp(modelo, otro.modelo) != 0) {
        return false;
    }
    if(strcmp(asignadoA, otro.asignadoA) != 0) {
        return false;
    }
    return true;
}

bool Automovil::operator!=(Automovil& otro)
{
    return !(*this == otro);
}

ostream& operator<<(ostream& salida, Automovil& obj)
{
    salida << "Clave: " << obj.claveAuto << endl;
    salida << "Marca: " << obj.marcaAuto << endl;
    salida << "Modelo: " << obj.modelo << endl;
    salida << "Anio Fab.: " << obj.anioFab << endl;
    salida << "Asignado a: " << obj.asignadoA << endl;
    return salida;
}

istream& operator>>(istream& entrada, Automovil& obj)
{
    cout << "Clave: ";
    entrada >> obj.claveAuto;

    cout << "Marca: ";
    entrada.ignore();
    entrada.getline(obj.marcaAuto, 60);

    cout << "Modelo: ";
    entrada.getline(obj.modelo, 60);

    cout << "Anio Fab.: ";
    entrada >> obj.anioFab;

    cout << "Asignado a: ";
    entrada.ignore();
    entrada.getline(obj.asignadoA, 60);

    return entrada;
}

int menuOpciones()
{
    int opc;

    do {

        cout << "1-Ingresar datos iniciales" << endl;
        cout << "2-Ver todos los automoviles" << endl;
        cout << "3-Automoviles por anio" << endl;
        cout << "4-Automoviles por marca" << endl;
        cout << "5-Automoviles por marca y modelo" << endl;
        cout << "6-Cambiar \"asignado a\" por clave de auto" << endl;
        cout << "7-Automovil por clave de auto" << endl;
        cout << "8-Dar de alta un nuevo automovil" << endl;
        cout << "9-Dar de baja un automovil" << endl;
        cout << "10-Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> opc;

    }while(opc < 1 && opc > 10);
    return opc;

}

int main()
{
    Arreglo<Automovil> autos = Arreglo<Automovil>();
    Automovil autoTemp;

    int opc, cantidad, i, anio, claveAuto, result;
    char marca[60], modelo[60], asignado[60];
    do {

        opc = menuOpciones();

        switch(opc) {
            case 1: {

                do {
                    cout << "Ingrese cantidad de automoviles: ";
                    cin >> cantidad;
                } while(cantidad <= 1 && cantidad >= 120);

                for(i = 0; i < cantidad; i++) {
                    autoTemp = Automovil();
                    cout << "Automovil " << i + 1 << ":" << endl;
                    cin >> autoTemp;
                    autos.InsertaDesordenado(autoTemp);
                }

                break;
            }

            case 2: {

                cout << "Flota completa: " << endl;
                cantidad = autos.tamanio();
                for(i = 0; i < cantidad; i++) {
                    autoTemp = *(autos.obtener(i));
                    cout << "Automovil " << i + 1 << ":" << endl;
                    cout << autoTemp << endl;
                }

                break;
            }

            case 3: {
                cout << "Ingrese anio: ";
                cin >> anio;
                cantidad = autos.tamanio();
                for(i = 0; i < cantidad; i++) {
                    autoTemp = *(autos.obtener(i));
                    if(autoTemp.obtenerAnioFab() == anio) {
                        cout << "Automovil " << i + 1 << ":" << endl;
                        cout << autoTemp << endl;
                    }
                }
                break;
            }

            case 4: {
                cout << "Ingrese marca: ";
                cin.ignore();
                cin.getline(marca, 60);
                cantidad = autos.tamanio();
                for(i = 0; i < cantidad; i++) {
                    autoTemp = *(autos.obtener(i));
                    if(strcmp(autoTemp.obtenerMarca(), marca) == 0) {
                        cout << "Automovil " << i + 1 << ":" << endl;
                        cout << autoTemp << endl;
                    }
                }
                break;
            }

            case 5: {
                cout << "Ingrese marca: ";
                cin.ignore();
                cin.getline(marca, 60);

                cout << "Ingrese modelo: ";
                cin.getline(modelo, 60);
                cantidad = autos.tamanio();
                for(i = 0; i < cantidad; i++) {
                    autoTemp = *(autos.obtener(i));
                    if((strcmp(autoTemp.obtenerMarca(), marca) == 0) && 
                       (strcmp(autoTemp.obtenerModelo(), modelo) == 0)) {
                        cout << "Automovil " << i + 1 << ":" << endl;
                        cout << autoTemp << endl;
                    }
                }
                break;
            }

            case 6: {
                cout << "Clave de auto: ";
                cin >> claveAuto;
                cantidad = autos.tamanio();
                i = 0;
                while(i < cantidad && (*autos.obtener(i)).obtenerClave() != claveAuto) {
                    i++;
                }

                if(i < cantidad) {
                    cout << "Ingrese nuevo asignado: "; 
                    cin.ignore();
                    cin.getline(asignado, 60);

                    (*autos.obtener(i)).cambiaAsignadoA(asignado);
                } else {
                    cout << "No se encontro esa clave" << endl;
                }
                break;
            }

            case 7: {
                cout << "Clave de auto: ";
                cin >> claveAuto;
                cantidad = autos.tamanio();
                i = 0;
                while(i < cantidad && (*autos.obtener(i)).obtenerClave() != claveAuto) {
                    i++;
                }

                if(i < cantidad) {
                    cout << "Automovil: ";
                    autoTemp = (*autos.obtener(i)); 
                    cout << autoTemp;
                } else {
                    cout << "No se encontro esa clave" << endl;
                }
                break;
            }

            case 8: {
                autoTemp = Automovil();
                cout << "Nuevo automovil:" << endl;
                cin >> autoTemp;
                result = autos.InsertaDesordenado(autoTemp);
                if(result == 1) {
                    cout << "Automovil ingresado" << endl;
                } else if(result == 0) {
                    cout << "La lista esta llena" << endl;
                } else if(result == -1) {
                    cout << "Ya existe dicho automovil" << endl;
                }
                break;
            }
            case 9: {
                autoTemp = Automovil();
                cout << "Clave automovil:" << endl;
                cin >> claveAuto;
                cantidad = autos.tamanio();
                i = 0;
                while(i < cantidad && (*autos.obtener(i)).obtenerClave() != claveAuto) {
                    i++;
                }

                if(i < cantidad) {
                    cout << "Automovil: ";
                    autoTemp = (*autos.obtener(i)); 
                    result = autos.EliminaDesordenado(autoTemp);

                    if(result == 1) {
                        cout << "Automovil dado de baja" << endl;
                    } else if(result == 0) {
                        cout << "Lista vacia" << endl;
                    }
                } else {
                    cout << "No se encontro esa clave" << endl;
                }
                break;
            }
            case 10: {
                cout << "Fin del programa" << endl;
                break;
            }
        }

        getch();

    }while(opc != 10);

    return 0;
}