/************************************************
 * Integer.cpp
 *
 * clase envolvente de entero
 *
 * Aldo Cassola <acassola@usfq.edu.ec 2016-10-20
 */
 
// Pablo Llanes 
// Deber #4: Integer.cpp
// 27/10/2016
// Implementacion de las clases miembro y amigas de la clase Integer

#include <iostream>
#include "Integer.h" // inclusion del archivo de definicion  
using namespace std; 

Integer::Integer(int val)
    : integer(val)
{
   // cuerpo vacio 
}

// sobrecarga de operador menor o igual que 
bool Integer::operator<=(int num) const
{
    // si el numero es menor o igual al objeto de la clase devuelve verdadero 
    return (integer < num || integer == num);
}

// sobrecarga del operador menor o igual que con un entero
int Integer::operator=(int num) 
{
    // asigna el valor de un entero al miembro del objeto 
    integer = num;
    
    // devuelve el numero 
    return num; 
}

// sobrecarga del operador menor o igual que entre enteros 
bool Integer::operator<=(const Integer &num) const
{
    // si el objeto actual es menor o igual al otro objeto devuelve verdadero 
    return (integer < num.integer || integer == num.integer);
}

// sobrecarga del operador de igualdad  
bool Integer::operator==(int num) const
{
    // si el objeto es igual al numero entero devuelvo verdadero 
    return (integer == num);
}

// sobrecarga del operador posincremento 
Integer Integer::operator++(int)
{
    Integer num;
    
    // incrementa el miembro dato por 1 
    num.integer = integer++; 
    
    // devuelve el resultado del incremento 
    return num;
}

// sobrecarga del operador de insercion 
istream &operator>>(std::istream &input, Integer &num)
{
    // ingresa un valor al objeto entero 
    input >> num.integer; 
    
    // permite llamadas en cascada 
    return input; 
}

// sobrecarga del operador de estraccion 
ostream &operator<<(std::ostream &output, const Integer &num)
{
    // imprime el numero entero a la pantalla
    output << num.integer; 

    // permite las llamadas en cascada 
    return output; 
}
