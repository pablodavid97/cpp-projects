/*****************************************************
 * Polynomial_Driver.cpp
 *
 * Manejador para pruebas de la clase Polynomial
 *
 * Crea varios objetos Polynomio y prueba sus
 * capacidades.
 */

#include <iostream>
#include <cstdlib>
#include "Polynomial.h"

using namespace std;

Polynomial test1(int d);
Polynomial *test2(Polynomial &p);
void test3(int r, int d, int p);


int main(void)
{
   int r = 100, d = 100, p = 100;

   Polynomial result1(test1(10));
   cout << "result1 : " << result1 << endl;
   
   cout << "Evaluating Polynomial result1 in x = 2..." << endl; 
   
   double value = evaluate(result1, 2);
   
   cout << "result1 in x = 2 is: " << value << endl;

   Polynomial *result2 = test2(result1);

   cout << "\n*result2: " << *result2 << endl;

   cout << "Deleting result2..." << endl;
   delete result2;

   cout << "\nresult1 after deleting result2: " << result1 << endl;

   test3(r, d, p);
}

Polynomial test1(int deg)
{
   Polynomial retval(deg);

   for(int i = 0; i <= deg; i++)
      retval.setCoefficient(i, i+1);

   return retval;
}

Polynomial *test2(Polynomial &p)
{
   return new Polynomial(p);

}

void test3(int rounds, int degs, int numpolys)
{
   Polynomial **pArray = new Polynomial *[numpolys];

   cout << "Starting " << rounds << " rounds of "
      << numpolys << " operations...";

   for(int i = 0; i < rounds; i++)
   {
      Polynomial sumtotal, difftotal, multtotal;

      multtotal.setCoefficient(0, 1);

      for(int j = 0; j < numpolys; j++)
      {
         pArray[j] = new Polynomial(degs);

         for(int k = 0; k <= degs; k++)
            pArray[j]->setCoefficient(k, rand() % 10 - 5);

         sumtotal += *pArray[j];
         difftotal -= *pArray[j];
         multtotal *= *pArray[j];
      }

      for(int j = numpolys - 1; j >= 0; j--)
         delete pArray[j];

      if(i % 10)
         cout << ".";
   }

   cout << "\nDone." << endl;

}
