// Pablo Llanes
// 17/10/2016
// Deber #2: Recta.cpp
// Implementacion  de las funciones miembro de la clase Recta

#include <iostream>
#include <cmath> // para detectar si la pendiente de una recta es infinita
#include <iomanip> // formato de impresion a la pantalla
#include <limits> // para encontrar el limite la pendiente de una recta
#include <stdexcept> // para manejar los argumentos invalidos mediante excepciones
#include "Recta.h" // defincion de la clase Recta
using namespace std;

// constructor sin argumentos que tiene valores por default para los puntos de una recta
Recta::Recta()
    : p1(0,0), p2(0,1) // valores por default
{
    // cuerpo del constructor vacio
}

// constructor de la clase que recibe una referencia a dos puntos de una recta como valores inciales
Recta::Recta(Punto &punto1, Punto &punto2)
{
    // si los puntos son iguales este asigna valores por default a los puntos 1 y 2 de la recta
    try
    {
        setPunto1(punto1);
        setPunto2(punto2);
    }
    catch(invalid_argument &e)
    {
        p1.setX(0).setY(0);
        p2.setX(0).setY(1);
    }
}

// funcion que recibe una referencia al primer punto de una recta y devuelve una referencia a una recta
Recta &Recta::setPunto1(Punto &punto1)
{
    // si el punto ingresado es igual al otro punto de la recta, se lanza una excepcion
    if((punto1.getX() == p2.getX()) && (punto1.getY() == p2.getY()))
        throw invalid_argument("El nuevo punto es invalido\n");
    else
        p1 = punto1; // de lo contrario se asigna valores miembro a miembro de los objetos punto.

    return *this; // retorna una referencia a una recta
}

// funcion que recibe una referencia al segundo punto de una recta y devuelve una referencia a una recta
Recta &Recta::setPunto2(Punto &punto2)
{
    // si el punto ingresado es igual al otro punto de la recta, se lanza una excepcion
    if((punto2.getX() == p1.getX()) && (punto2.getY() == p1.getY()))
        throw invalid_argument("El nuevo punto es invalido\n");
    else
        p2 = punto2; // de lo contrario se asigna valores miembro a miembro de los objetos punto

    return *this; // retorna una referencia a una recta
}

// devuelve una copia del primer punto de la recta
Punto Recta::getPunto1() const
{
    return p1;
}

// devuelve una copia del segundo punto de la recta
Punto Recta::getPunto2() const
{
    return p2;
}

// retorna el valor de la pendiente de una recta como un double
double Recta::getPendiente() const
{
    // valores para remplazar en la ecuacion de la pendiente y obtener su valor
    double y2 = p2.getY();
    double y1 = p1.getY();
    double x2 = p2.getX();
    double x1 = p1.getX();

    // variable que contiene el valor de la pendiente de una recta
    double m = (y2-y1) / (x2-x1);

    // manejo de excepciones, si el denominador es igual a 0 la pendiente tiene un valor infinito
    if (x2-x1 == 0)
    {
        return numeric_limits<double>::infinity();
    }
    else
        return m;
}

// funcion que encuentra el punto de interseccion de una recta con el eje y, o x en el caso de que la pendiente sea infinita
double Recta::getAxisIntersect() const
{
    // variable que guarda el valor de la pendiente
    double m = getPendiente();

    // si la pendiente es infinita, devolver la interseccion con el eje x
    if(isinf(m))
    {
        double vx = p1.getX();
        return vx;
    }
    else // de lo contrario regresar el valor de la interseccion con el eje y
    {
        double c = p2.getY() - m*p2.getX();
        return c;
    }
}

// funcion que imprime la ecuacion explicita de una recta a la pantalla
void Recta::imprimirRecta() const
{
     // variable que guarda el valor de la pendiente
    double m = getPendiente();

    // imprime la ecuacion de una recta tomando en consideracion el valor de la pendiente
    if(isinf(m))
    {
        cout << "y = vertical sobre " << getAxisIntersect() << endl; // si la pendiente es infinita
    }
    else
    {
        cout << "y = " << setprecision(2) << fixed << m << "x + " << getAxisIntersect() << endl; // si la pendiente no es infinita
    }
}

// funcion amiga de la clase Recta que toma una referencia de dos rectas y devuelve un punto de interseccion
Punto intersect(Recta &recta1, Recta &recta2)
{
    // valores a utilizar para encontrar el punto de interseccion
    double m1 = recta1.getPendiente();
    double c1 = recta1.getAxisIntersect();
    double m2 = recta2.getPendiente();
    double c2 = recta2.getAxisIntersect();
    double x, y; // coordenadas x y y
    Punto corte; // punto que va a contener las coordenadas del punto de interseccion

    // manejo de excepciones, si las pendientes son iguales lanzar una excepcion para indicar al usuario que no hay cruce
    if(m1 == m2)
    {
        throw invalid_argument("El cruce de las rectas dadas no existe\n");
    }
    else // si las pendientes no son iguales
    {
        // la pendiente de la primera recta es infinita, y en este caso
        if(isinf(m1))
        {
            // utilizar la interseccion de la primera recta como la coordenada x del punto de cruce
            x = c1;
            y = (m2*x) + c2; // remplazar x en la ecuacion de la segunda recta para obtener y
            corte.setX(x).setY(y);

            return corte; // devolver el punto de interseccion
        }
        else if(isinf(m2)) // la pendiente de la segunda recta es infinita
        {
            // utilizar la interseccion de la segunda recta como la coordenada x del punto de cruce
            x = c2;
            y = (m1*x) + c1; // remplazar x en la ecuacion de la primera recta para obtener y
            corte.setX(x).setY(y);

            return corte; // devolver el punto de interseccion
        }
        else // ninguna de las dos pendientes es infinita
        {
            // despejar el valor de x y remplazarlo en la ecuacion de la primera recta
            x = (c2-c1) / (m1-m2);
            y = (m1*x) + c1;
            corte.setX(x).setY(y);

            return corte; // devolver el punto de interseccion
        }
    }
}
