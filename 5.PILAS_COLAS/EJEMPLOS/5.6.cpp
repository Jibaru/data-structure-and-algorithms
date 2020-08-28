/* Aplicación de una estructura de datos tipo cola. Se define la clase
Producto y una cola de objetos tipo Producto. Considerando que se 
quieren vender los productos de acuerdo al orden en el que fueron 
comprados, se usó una cola para almacenarlos. La cola se actualiza a 
medida que se compran o se venden productos. */
#include "5.5.cpp"
#include <string.h>

/* Definición de la clase Producto. */
class Producto {
private:
    int Clave;
    char NomProd[64];
    double Precio;
public:
    Producto();
    Producto(int, char[], double);
    double RegresaPrecio();
    friend istream &operator>>(istream&, Producto&);
    friend ostream &operator<<(ostream&, Producto&);
};

/* Declaración del método constructor por omisión. */
Producto::Producto()
{}

/* Declaración del método constructor con parámetros. */
Producto::Producto(int Cla, char NomP[], double Pre)
{
    Clave= Cla;
    strcpy(NomProd, NomP);
    Precio= Pre;
}

/* Método que permite, a usuarios externos a la clase, conocer el valor 
del atributo privado Precio. */
double Producto::RegresaPrecio()
{
    return Precio;
}

/* Sobrecarga del operador >>. De esta forma se permite leer objetos de
*tipo Producto de manera directa . */
istream &operator>>(istream &Lee, Producto &ObjProd)
{
    cout << "\n\nIngrese clave del producto: ";
    Lee >> ObjProd.Clave;
    cout << "\n\nIngrese nombre del producto: ";
    Lee >> ObjProd.NomProd;
    cout << "\n\nIngrese precio: ";
    Lee >> ObjProd.Precio;
    return Lee;
}

/* Sobrecarga del operador <<. De esta forma se permite imprimir objetos
de tipo Producto de manera directa . */
ostream &operator<< (ostream &Escribe, Producto &ObjProd)
{
    Escribe << "\n\nDatos del producto\n";
    Escribe << " \nClave: " << ObjProd.Clave;
    Escribe << "\nNombre: " << ObjProd.NomProd;
    Escribe << "\nPrecio: " << ObjProd.Precio;
    return Escribe;
}

/* Función auxiliar que despliega al usuario las opciones de trabajo. En 
este caso registrar la compra o la venta de un producto. */
int Menu ()
{
    int Resp;
    do {
        cout << "\n\nIngrese operacion a registrar: ";
        cout << "\n1-Compra de un producto ";
        cout << "\n2-Venta de un producto\n ";
        cout << "\n3-Termina el registro\n ";
        cin >> Resp;
    } while (Resp != 1 && Resp != 2 && Resp != 3);
    
    return Resp; 
}
 
/* Función principal que lleva a cabo la aplicación descrita. Se crea 
una cola de objetos tipo Producto y la misma se va modificando a medida 
que se compran o se venden productos. El uso de una cola para guardar 
los productos facilita el cumplimiento de la condición impuesta para su 
venta: el primero que se compre será el primero que se venda. Al final 
de las transacciones se imprime el total de dinero recaudado con las 
ventas. */
int main()
{
    Cola<Producto> Deposito;
    Producto Prod;
    int Opc;
    double Total= 0;
    Opc= Menu();
    while (Opc == 1 || Opc == 2)
    {
        switch (Opc)
        {
            case 1:
                cin>>Prod;
                if (!(Deposito + Prod))
                    cout<< "\n\nNo hay lugar en el deposito para registrar el producto.\n";
                break;

            case 2:
                if (Deposito - &Prod)
                {
                    cout << Prod;
                    Total= Total + Prod.RegresaPrecio();
                }
                else
                cout << "\n\n\nYa no hay productos en el deposito. \n\n";
                break;
        }
        Opc= Menu();
    }
    cout << "\n\n\nTotal vendido: " << Total << endl;

    return 0;
}
