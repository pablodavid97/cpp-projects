/************************************************
 * /home/aldo/src/Complex/Complex_Driver.cpp
 *
 * Archivo manejador para la clase Complex
 *
 * Aldo Cassola <acassola@usfq.edu.ec 2016-10-20
 */
 
// Pablo Llanes 
// Deber #3: complex_driver.cpp
// 25/10/2016
// Archivo que prueba las funciones declaradas en la clase recta 

#include <iostream>
#include <cstdlib>
#include "Complex.h"

using namespace std;

int main()
{
   cout << "Programa de prueba para numeros complejos: \n" << endl;

   // crear numeros complejos
   Complex z1(rand(), rand()), 
           z2(rand(), rand()), 
           z3;
           
   cout << "Los numeros son:"<< endl;
   cout << "z1 = " << z1 << endl;
   cout << "z2 = " << z2 << endl;
   cout << "z3 = " << z3 << endl;   
   
   z3 = z1 + z2;
   cout << "\nAritmetica de complejos:\n";
   z3 = z1 + z2;
   cout << "z3 = z1 + z2 = " << z3 << endl;

   z3 = z1 - z2;
   cout << "z3 = z1 - z2 = " << z3 << endl;

   z3 = z1 * z2;
   cout << "z3 = z1 * z2 = " << z3 << endl;

   z3 = z1 / z2;
   cout << "z3 = z1 / z2 = " << z3 << endl;

   cout << "\nComparaciones de complejos:\n";
   cout << "z1 < z2 = " << (z1 < z2 ? "true" : "false")
      << "\nz1 > z2 = " << (z1 > z2 ? "true" : "false")
      << "\nz1 == z2 = " << (z1 == z2 ? "true" : "false")
      << "\nz1 != z2 = " << (z1 != z2 ? "true" : "false")
      << "\nz1 <= z2 = " << (z1 <= z2 ? "true" : "false")
      << "\nz1 >= z2 = " << (z1 >= z2 ? "true" : "false")
      << endl;
}