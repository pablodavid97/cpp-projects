/*************************************
 * Complex.h
 *
 * Representa un numero complejo
 *
 * Aldo Cassola <acassola@usfq.edu.ec> 2016
 */
 
// Pablo Llanes 
// Deber #3: Complex.h
// 25/10/2016
// Definicion de la clase Complex, la cual representa un numero complejo  

// efita la inclusion multiple del archivo de cabecera 
#ifndef COMPLEX_H
#define COMPLEX_H

// composicion de la clase Complex 
class Complex
{
   friend std::ostream &operator<<(std::ostream &, const Complex &); // sobrecarga de operador de insercion 
   friend bool operator<(const Complex &, const Complex &); // sobrecarga de operador angular menor
   friend bool operator>(const Complex &, const Complex &); // sobrecarga de operador angular mayor 
   friend bool operator==(const Complex &, const Complex &); // sobrecarga de operador de igualdad
   friend bool operator!=(const Complex &, const Complex &); // sobrecarga de operador de desigualdad 
   friend bool operator<=(const Complex &, const Complex &); // sobrecarga de operador menor o igual que
   friend bool operator>=(const Complex &, const Complex &); // sobrecarga de operador mayor o igual que 
public:
   explicit Complex(double = 0.0, double = 0.0); // constructor con argumentos por default 
   double getReal() const;
   Complex &setReal(double val);
   double getImaginary() const;
   Complex &setImaginary(double val);
   Complex conjugate() const; // Complex(real, -imaginary)
   double r() const; // magnitude of the number
   double theta() const; // the angle with the pos. x axis
   Complex operator+(const Complex &) const; // sobrecarga de operador suma
   Complex operator-(const Complex &) const; // sobrecarga de operador resta
   Complex operator*(const Complex &) const; // sobrecarga de operador estrella
   Complex operator/(const Complex &) const; // sobrecarga de operador slash 

private:
   double real; // parte real de un numero complejo
   double imaginary; // parte imaginaria de un numero complejo 
};

#endif // COMPLEX_H