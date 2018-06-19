// Pablo Llanes
// 17/10/2016
// Deber #2: Punto.cpp
// Implementacion  de las funciones miembro de la clase Punto

#include <iostream>
#include <iomanip>
#include "Punto.h" // definicion de la clase Punto
using namespace std;

// constructor que toma dos argumentos y los asigna a los miembros datos x y y
Punto::Punto(double coordx, double coordy)
    : x(coordx), y(coordy)
{

}

// asigna un valor ingresado por el usuario a la coordenada x del punto y regresa una referencia al objeto
Punto &Punto::setX(double cx)
{
    x = cx;

    return *this; // retorna una referencia al objeto punto
}

// asigna un valor ingresado por el usuario a la coordenada y del punto y regresa una referencia al objeto
Punto &Punto::setY(double cy)
{
    y = cy;

    return *this; // retorna una referencia al objeto punto
}

// retorna el valor de la coordenada x del punto
double Punto::getX() const
{
    return x;
}

// retorna el valor de la coordenada y del punto
double Punto::getY() const
{
    return y;
}

// imprime las coordenadas x y y del punto a la pantalla entre parentesis
void Punto::imprimirPunto() const
{
    cout << "(" << getX() << ", " << getY() << ")" << endl;
}
