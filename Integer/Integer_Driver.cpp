/************************************************
 * Integer_Driver.cpp
 *
 * Driver para la clase Integer
 *
 * Aldo Cassola <acassola@usfq.edu.ec 2016-10-20
 */
 
// Pablo Llanes 
// Deber #4: Integer_Driver.cpp
// 27/10/2016
// Archivo que comprueba la funcionalidad de la clase Integer 

#include <iostream>
#include "Integer.h"

using namespace std;

int main()
{
   // declara dos objetos tipo Integer
   Integer i, limite;

   // pide el ingreso de un numero al usuario 
   do 
   {
      cout << "Dame un numero: " << endl;
      cin >> limite;
   }
   while(limite <= 0); // sigue insistiendo hasta que el usuario ingrese un valor adecuado 

   // imprime el mensaje el numero de veces establecido por el usuario    
   for(i = 1; i <= limite; i++)
   {
      cout << i << " elefante" << (i == 1 ? " " : "s ")
         << "se balanceaba" << (i == 1 ? "\n" : "n\n")
         << " sobre la tela de una arana\n"
         << " como veia" << (i == 1 ? " " : "n ")
         << " que resistia\n"
         << " fue" << (i == 1 ? " " : "ron ")
         << "a llamar a un camarada\n\n";
   }
}
