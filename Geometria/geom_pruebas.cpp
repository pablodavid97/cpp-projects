// Pablo Llanes
// 17/10/2016
// Deber #2: geom_pruebas.cpp
// Archivo de prueba para las clases Punto y Recta, con sus respectivos miembros

#include <iostream>
#include <stdexcept>
#include "Geometria/Punto.h" // definicion de la clase Punto
#include "Geometria/Recta.h" // definicion de la clase Recta
using namespace std;

int main()
{
    // declaracion de objetos Punto y Recta para la evalucion de su funcionamiento
    Punto p1(3,1);
    Punto p2(4,8);
    Punto p3(4,9.5);
    Recta r1(p3, p3); // caso 1: constructor que recibe puntos iguales
    Recta r2(p1, p3); // recta con pendiente representable
    Recta r3; // recta con pendiente infinita

    // puntos de la recta r1
    Punto p1r1 = r1.getPunto1();
    Punto p2r1 = r1.getPunto2();

    // impresion de los puntos de la recta r1 a la pantalla
    cout << "\nLos puntos por los que pasa la recta r1 son: " << endl;
    cout << "P2 = ";
    p1r1.imprimirPunto();
    cout << "P3 = ";
    p2r1.imprimirPunto();

    cout << "\nCambiando los valores para P3 " << endl;
    // cambio de los puntos por los que pasa la recta 1
    r1.setPunto1(p2).setPunto2(p3);

    // impresion de los puntos p1, p2 y p3 a la pantalla
    cout << "\nLos puntos declarados son: " << endl;
    cout << "P1 = (" << p1.getX() << ", " << p1.getY() << ")" << endl; // impresion del punto p1 utilizando funciones get
    cout << "P2 = ";
    p2.imprimirPunto();
    cout << "P3 = ";
    p3.imprimirPunto();

    cout << "\nLas ecuaciones de las rectas declaradas son: " << endl;
    // impresion de las rectas r1, r2 y r3 a la pantalla
    cout << "r1: ";
    r1.imprimirRecta();
    cout << "r2: ";
    r2.imprimirRecta();
    cout << "r3: ";
    r3.imprimirRecta();

    // punto de interseccion entre dos rectas
    Punto i = intersect(r1, r2);
    cout << "\nEl punto de interseccion entre las rectas r1 y r2 es: " << endl;
    i.imprimirPunto();

    cout << endl;


    cout << "La interseccion entre las rectas r1 y r3 es: " << endl;
    // caso 2: no existe cruce entre las dos rectas
    try
    {
        i = intersect(r1, r3);
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
    }

    cout << "Cambiando los valores para P3 " << endl;
    // cambio de valores de p3
    p3.setX(3).setY(1);

    try
    {
        // caso 3: los puntos asignados a la recta son los mismos
        r3.setPunto1(p1).setPunto2(p3);
    }
    catch(invalid_argument &e)
    {
        cout << e.what() << endl;
    }
}
