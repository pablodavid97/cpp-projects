/******************************************************
 * Polynomial.h
 *
 * La clase Polynomial, que representa un polinomio.
 *
 * Provee asignacion, suma resta y multiplicacion.
 *
 */
 
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

class Polynomial
{
   //imprime el polinomio en forma ax^n + bx^n-1, ...
   friend std::ostream &operator<<(std::ostream &, const Polynomial &);
   
   public:
      Polynomial(); // constructor sin argumentos
      explicit Polynomial(int deg); // constructor que toma el grado del pol.
      ~Polynomial(); // destructor
      Polynomial(const Polynomial& other); // constructor copia
      // funcion set para coeficientes: el exponente exp tendra coeficiente coef
      Polynomial &setCoefficient(int exp, int coef);
      double getCoefficient(int exp) const; // funcion get para coeficientes
      int getDegree() const; // funcion get para grado
      const Polynomial &operator=(const Polynomial& other); // op. asignacion
      Polynomial operator+(const Polynomial &) const; // op. suma
      Polynomial operator-(const Polynomial &) const; // op. resta
      Polynomial operator*(const Polynomial &) const; // op. multiplicacion
      const Polynomial &operator+=(const Polynomial &); // op. asignacion suma
      const Polynomial &operator-=(const Polynomial &); // op. asignacion resta
      const Polynomial &operator*=(const Polynomial &); // op. asignacion multiplicacion 

   private:
      unsigned int degree; // el grado del polinomio
      double *coefs; // puntero al arreglo de coeficientes, memoria dinamica
};

double evaluate(Polynomial &p, double x);

#endif // POLYNOMIAL_H