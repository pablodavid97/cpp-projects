// Pablo Llanes
// 17/10/2016
// Deber #2: Punto.h
// Definicion de la clase Punto, la cual representa un punto en un plano de dos dimensiones

// previene multiples inclusiones del archivo de cabecera
#ifndef PUNTO_H
#define PUNTO_H

// definicion de la clase Punto
class Punto
{
public:
    explicit Punto(double = 0, double = 0); // constructor con argumentos opcionales
    Punto &setX(double); // asigna un valor a la coordenada x
    Punto &setY(double); // asigna un valor a la coordenada y
    double getX() const; // retorna el valor de la coordenada x
    double getY() const; // retorna el valor de la coordenada y
    void imprimirPunto() const; // imprime las coordenadas del punto a la pantalla

private:
    double x; // miembro dato para guardar la coordenada x
    double y; // miembro dato para guardar la coordenada y
}; // fin de la clase Punto

#endif // PUNTO_H
