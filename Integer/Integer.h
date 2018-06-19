/************************************************
 * Integer.h
 *
 * Clase envolvente para enteros
 *
 * Aldo Cassola <acassola@usfq.edu.ec 2016-10-20
 */
 
// Pablo Llanes 
// Deber #4: Integer.h
// 27/10/2016
// Definicion de la clase Integer, la cual representa un numero entero 

// evita que se incluya el archivo mas de una sola vez 
#ifndef INTEGER_H
#define INTEGER_H

// composicion de la clase Integer 
class Integer
{
   friend std::istream &operator>>(std::istream &, Integer &); // sobrecarga del operador de insercion 
   friend std::ostream &operator<<(std::ostream &, const Integer &); // sobrecarga del operador de estraccion 
   
   public:
      explicit Integer(int = 0); // constructor con valor por default 
      bool operator<=(int) const; // sobrecarga del operador menor o igual que con un entero    
      int operator=(int); // sobrecarga del operador de asignacion con un entero 
      bool operator<=(const Integer &) const; // sobtrecarga del operador menor o igual que con un entero de la clase 
      bool operator==(int) const; // sobrecarga del operador de igualdad 
      Integer operator++(int); // sobrecarga del operador posincremento 

   private:
      int integer; // dato miembro entero 
};

#endif // INTEGER_H
