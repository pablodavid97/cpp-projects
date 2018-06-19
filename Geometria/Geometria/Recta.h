// Pablo Llanes
// 17/10/2016
// Deber #2: Recta.h
// Definicion de la clase Recta, la cual representa una recta en un plano de dos dimensiones

// previene multiples inclusiones del archivo de cabecera
#ifndef RECTA_H
#define RECTA_H

#include "Punto.h" // definicion de la clase Punto

// definicion de la clase Recta
class Recta
{
    friend Punto intersect(Recta &, Recta &); // declaracion de funcion amiga a la clase
public:
    Recta(); // constructor sin argumentos
    explicit Recta(Punto &, Punto &); // constructor con argumentos
    Recta &setPunto1(Punto &); // asigna un valor al primer punto por el cual pasa una recta creada
    Recta &setPunto2(Punto &); // asigna un valor al segundo punto por el cual pasa la recta
    Punto getPunto1() const; // retorna una copia del primer punto de la recta
    Punto getPunto2() const; // retorna una copia del segundo punto de la recta
    double getPendiente() const; // retorna el valor de la pendiente de una recta
    double getAxisIntersect() const; // retorna el valor del punto de interseccion de la recta con el eje x, o y si su pendiente es infinita
    void imprimirRecta() const; // imprime la ecuacion de la recta a la pantalla

private:
     Punto p1; // miembro dato que guarda las coordenadas del punto1 de la recta
     Punto p2; // miembro dato que guarda las coordenadas del punto2 de la recta
}; // fin de la clase Recta

#endif // RECTA_H

