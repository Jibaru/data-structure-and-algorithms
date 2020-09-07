/*
8.	Retome el problema anterior y defina una clase Alumnos con todos 
los atributos y métodos que crea necesarios (puede usar la solución 
al problema 8 del capítulo 2). La clase Alumnos servirá como tipo 
para el atributo información de cada nodo de la lista. Con estas 
especificaciones desarrolle una aplicación que:
a) Permita crear (alfabéticamente por nombre de alumno) una lista 
con los alumnos que toman cierta materia.
b) Imprima los datos de todos los alumnos.
c) Busque en la lista el nombre de un alumno. Si lo encuentra, debe 
imprimir todos sus datos, en caso contrario debe imprimir un mensaje 
adecuado.
d) Busque en la lista el nombre de un alumno que se dio de baja de la 
materia, si su nombre no está en la lista, la aplicación debe eliminarlo 
o enviar un mensaje adecuado.
*/
#include <iostream>
#include <conio.h>
#include <string.h>
#include "7.cpp"

using namespace std;

class Alumno {
private:
	char* Nombre;
	int AnioIngreso;
	char* NomCarrera;
	int NroMatAprob;
	float Promedio;
public:
    Alumno();
	Alumno(char*, int, char*, int, float);
	void imprime();
    void cambiaNombre(char *);
    char* regresaCarrera();
    int operator==(Alumno&);
    int operator!=(Alumno&);
    int operator<(Alumno&);
    int operator<=(Alumno&);
    int operator>(Alumno&);
    int operator>=(Alumno&);
    friend istream& operator>>(istream&, Alumno&);
    friend ostream& operator<<(ostream&, Alumno&);
};

Alumno::Alumno()
{}

Alumno::Alumno(char* nom, int anioIng, char* carr, int nroMatAp, float prom)
{
	Nombre = new char[strlen(nom) + 1];
	NomCarrera = new char[strlen(carr) + 1];

	strcpy(Nombre, nom);
	strcpy(NomCarrera, carr);
	AnioIngreso = anioIng;
	NroMatAprob = nroMatAp;
	Promedio = prom;
}

void Alumno::imprime()
{
	cout << "Nombre: " << Nombre << endl;
	cout << "Anio Ingreso: " << AnioIngreso << endl;
	cout << "Nombre Carrera: "<< NomCarrera << endl;
	cout << "Nro Materias Aprob: " << NroMatAprob << endl;
	cout << "Promedio: " << Promedio << endl;
}

void Alumno::cambiaNombre(char* nom)
{
    Nombre = new char[strlen(nom) + 1];
    strcpy(Nombre, nom);
}
char* Alumno::regresaCarrera()
{
    return NomCarrera;
}
int Alumno::operator==(Alumno& obj)
{
    if(strcmp(Nombre, obj.Nombre) != 0){
        return false;
    }
    return true;
}

int Alumno::operator!=(Alumno& obj)
{
    return !(*this == obj);
}

int Alumno::operator<(Alumno& obj)
{
    if(strcmp(Nombre, obj.Nombre) < 0) {
        return true;
    }
    return false;
}

int Alumno::operator<=(Alumno& obj)
{
    if(strcmp(Nombre, obj.Nombre) <= 0) {
        return true;
    }
    return false;
}

int Alumno::operator>(Alumno& obj)
{
    if(strcmp(Nombre, obj.Nombre) > 0) {
        return true;
    }
    return false;
}

int Alumno::operator>=(Alumno& obj)
{
    if(strcmp(Nombre, obj.Nombre) >= 0) {
        return true;
    }
    return false;
}

istream& operator>>(istream& ent, Alumno& a)
{
    char aux[60];
    cout << "Nombre: ";
    ent.ignore();
    ent.getline(aux, 60);
    a.Nombre = new char[strlen(aux) + 1];
    strcpy(a.Nombre, aux);
    cout << "Anio Ingreso: ";
    ent >> a.AnioIngreso;
	cout << "Nombre Carrera: ";
    ent.ignore();
    ent.getline(aux, 60);
    a.NomCarrera = new char[strlen(aux) + 1];
    strcpy(a.NomCarrera, aux);
	cout << "Nro Materias Aprob: ";
    ent >> a.NroMatAprob;
	cout << "Promedio: ";
    ent >> a.Promedio;
    return ent;
}

ostream& operator<<(ostream& sal, Alumno& a)
{
    sal << "\nNombre: " << a.Nombre << endl;
	sal << "Anio Ingreso: " << a.AnioIngreso << endl;
	sal << "Nombre Carrera: "<< a.NomCarrera << endl;
	sal << "Nro Materias Aprob: " << a.NroMatAprob << endl;
	sal << "Promedio: " << a.Promedio << endl << endl;
    return sal;
}

int menuOpciones()
{
    int Opc;

    do {
        cout << "\n1-Ingresar Alumno" << endl;
        cout << "2-Mostrar todos" << endl;
        cout << "3-Buscar por nombre" << endl;
        cout << "4-Dar de baja por nombre" << endl;
        cout << "5-Salir del sistema" << endl;
        cout << "Ingrese opcion: ";
        cin >> Opc;
        cout << endl;
    } while(Opc < 1 || Opc > 5);
    return Opc;
}

int main()
{
    ListaCircularSimple<Alumno> lista = ListaCircularSimple<Alumno>();
    Alumno alumno;
    NodoLista<Alumno> *buscado;
    int opc, resp;
    char nombre[60];
    do {
        opc = menuOpciones();
        switch(opc) {
            case 1: {
                alumno = Alumno();
                cin >> alumno;
                lista.insertaOrdenada(alumno);
                break;
            }
            case 2: {
                cout << "Lista de alumnos: " << endl;
                lista.imprimeLista();
                break;
            }
            case 3: {
                cout << "Ingrese nombre: ";
                cin.ignore();
                cin.getline(nombre, 60);
                alumno = Alumno();
                alumno.cambiaNombre(nombre);
                
                buscado = lista.buscaNodo(alumno);

                if(buscado) {
                    alumno = buscado->regresaInfo();
                    cout << "Alumno encontrado: " << endl;
                    cout << alumno;
                } else {
                    cout << "Alumno no encontrado" << endl;
                }

                break;
            }
            case 4: {
                cout << "Ingrese nombre: ";
                cin.ignore();
                cin.getline(nombre, 60);
                alumno = Alumno();
                alumno.cambiaNombre(nombre);
                
                resp = lista.eliminaNodo(alumno);

                switch (resp) {
                    case -1: {
                        cout << "Lista vacia" << endl; break;
                    }
                    case 0: {
                        cout << "Alumno no encontrado" << endl; break;
                    }
                    case 1: {
                        cout << "Alumno fue dado de baja" << endl; break;
                    }
                }

                break;
            }
        }

        getch();
    } while(opc != 5);

    return 0;
}