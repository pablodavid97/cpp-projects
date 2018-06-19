/**********************************
 * Complex.h
 *
 * Implementa un numero complejo de Complex.h
 *
 * Aldo Cassola <acassola@usfq.edu.ec> 2016
 */
 
// Pablo Llanes 
// Deber #3: Complex.cpp
// 25/10/2016
// Implementacion de las clases miembro y amigas de la clase Complex 

#include <iostream>
#include <cmath>
#include "Complex.h"

using namespace std;

Complex::Complex(double rval, double ival)
{
   setReal(rval);
   setImaginary(ival);
}

double Complex::getReal() const
{
   return real;
}

double Complex::getImaginary() const
{
   return imaginary;
}

Complex &Complex::setReal(double val)
{
   real = val;
   
   return *this;
}

Complex &Complex::setImaginary(double val)
{
   imaginary = val;
   
   return *this; 
}

Complex Complex::conjugate() const
{
   Complex retval(real, -imaginary);

   return retval;
}

double Complex::r() const
{
   return sqrt(pow(real, 2.0) + pow(imaginary, 2.0));
}

double Complex::theta() const
{
   return atan(imaginary / real);
}

Complex Complex::operator+(const Complex &der) const 
{
   // el operando izquierdo es el objeto actual
   double pr, pi;
   
   // hago la suma 
   pr = real + der.getReal();
   pi = imaginary + der.getImaginary();
   
   Complex complexSum(pr, pi);
   
   return complexSum; 
}

Complex Complex::operator-(const Complex &der) const 
{
   // el operando izquierdo es el objeto actual
   double pr, pi;
   
   // hago la resta
   pr = real - der.getReal();
   pi = imaginary - der.getImaginary();
   
   Complex complexSubs(pr, pi);
   
   return complexSubs; 
}

Complex Complex::operator*(const Complex &der) const 
{
   // el operando izquierdo es el objeto actual
   double pr, pi;
   
   // hago el producto
   pr = (real*der.getReal()) - (imaginary*der.getImaginary());
   pi = (real*der.getImaginary()) + (imaginary*der.getReal());
   
   Complex complexProduct(pr, pi);
   
   return complexProduct; 
}

Complex Complex::operator/(const Complex &der) const 
{
   // el operando izquierdo es el objeto actual
   double pr, pi;
   
   // hago la division
   pr = (real*der.getReal() + imaginary*der.getImaginary()) / pow(der.getReal(), 2)+pow(der.getImaginary(), 2);
   pi = (imaginary*der.getReal() - real*der.getImaginary()) / pow(der.getReal(), 2)+pow(der.getImaginary(), 2);
   
   Complex complexDivision(pr, pi);
   
   return complexDivision; 
}

ostream &operator<<(std::ostream &output, const Complex &number)
{
   // habilito la impresion de un numero complejo a la pantalla mostrando su parte real e imaginaria 
   output << number.getReal() << " + " << number.getImaginary() << "i";
   
   return output;
}

bool operator<(const Complex &left, const Complex &right) 
{
   // hago una comparacion de menor que 
   if (left.getReal() < right.getReal() || (left.getReal() == right.getReal() && left.getImaginary() < right.getImaginary()))
      return true; 
   else 
      return false; 
}

bool operator>(const Complex &left, const Complex &right) 
{
   // hago una comparacion de mayor que
   if (left.getReal() > right.getReal() || (left.getReal() == right.getReal() && left.getImaginary() > right.getImaginary()))
      return true; 
   else 
      return false; 
}

bool operator==(const Complex &left, const Complex &right) 
{
   // verifico si los dos numeros complejos son iguales 
   if (left.getReal() == right.getReal() && left.getImaginary() == right.getImaginary())
      return true; 
   else 
      return false; 
}

bool operator!=(const Complex &left, const Complex &right) 
{
   // verifico una desigualdad entre los dos numeros complejos 
   if (left.getReal() != right.getReal() || left.getImaginary() != right.getImaginary())
      return true; 
   else 
      return false; 
}

bool operator<=(const Complex &left, const Complex &right) 
{
   // realizo una comparacion de menor o igual que 
   if ((left.getReal() < right.getReal() || (left.getReal() == right.getReal() && left.getImaginary() < right.getImaginary())) || 
   (left.getReal() == right.getReal() && left.getImaginary() == right.getImaginary()))
      return true; 
   else 
      return false; 
}

bool operator>=(const Complex &left, const Complex &right)
{
   // realizo una comparacion de mayor o igual que 
   if ((left.getReal() > right.getReal() || (left.getReal() == right.getReal() && left.getImaginary() > right.getImaginary())) || 
   (left.getReal() == right.getReal() && left.getImaginary() == right.getImaginary()))
      return true; 
   else 
      return false; 
}