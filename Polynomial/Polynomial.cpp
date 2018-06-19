/******************************************************
 * Polynomial.cpp
 *
 * Implementacion de Polynomial
 *
 * Nombre: Pablo Llanes
 *
 */

#include <iostream>
#include <cmath> 
#include <stdexcept> 
#include "Polynomial.h"
using namespace std; 

// crea un polinomio de grado 0 con coeficiente 0 
Polynomial::Polynomial()
    : degree(0), coefs(new double [1])
{
    coefs[0] = 0; 
}

// crea un polinomio de grado deg con un solo termino, x^deg
Polynomial::Polynomial(int deg)
    : degree(deg >= 0 ? deg: throw invalid_argument("El grado debe ser >= 0\n")), 
    coefs(new double [deg + 1])
{
    for (int i = 0; i < degree; i++)
        coefs[i] = 0; 
        
    coefs[degree] = 1; 
}

// destructor del objeto 
Polynomial::~Polynomial()
{
    delete [] coefs; 
}

// constructor copia
// crea un nuevo arreglo que es copia del polinomio dado
Polynomial::Polynomial(const Polynomial &aCopiar)
    : degree(aCopiar.degree), 
    coefs(new double [degree + 1])
{
    for (int i = 0; i <= degree; i++)
        coefs[i] = aCopiar.coefs[i]; 
}

// permite asignar valores a los coeficientes de un polinomio con un grado especifico 
Polynomial &Polynomial::setCoefficient(int exp, int coef)
{
    (exp >= 0 && exp <= degree) ? coefs[exp] = coef: throw invalid_argument("El grado del exponente debe ser >= 0 y <= al grado del polinomio\n");
}

double Polynomial::getCoefficient(int exp) const
{
   return (exp >= 0 && exp <= degree) ?  coefs[exp]: throw invalid_argument("El grado del exponente debe ser >= 0 y <= al grado del polinomio\n");
}

// funcion que devuelve el grado del polinomio 
int Polynomial::getDegree() const
{
    return degree; 
}

// permite asignar el valor de un polinomio a otro 
const Polynomial &Polynomial::operator=(const Polynomial &pRight)
{
    // si los grados de los polinomios son diferentes 
    // asigna el espacio necesario en memoria para asignar un polinomio a otro 
    if (degree != pRight.degree)
    {
        delete [] coefs;
        degree = pRight.degree; 
        coefs = new double[degree+1];
    }
    
    // copia de los coeficientes de los polinomios 
    for (int i = 0; i <= degree; i++)
        coefs[i] = pRight.coefs[i]; 
    
    // retorna una referencia al objeto 
    return *this; 
}

// suma entre dos polinomios 
Polynomial Polynomial::operator+(const Polynomial &pRight) const
{
    // suma de polinomios segun el grado que tengan 
    if (degree == pRight.degree) // si los grados son iguales 
    {
        Polynomial sum(degree); 
        
        for(int i = 0; i <= degree; i++)
        {
            sum.coefs[i] = coefs[i] + pRight.coefs[i]; 
        }
        
        // devuelve la suma de los polinomios 
        return sum; 
    }
    else if (degree > pRight.degree) // si el grado del polinomio izquierdo es mayor 
    {
        Polynomial sum(degree); 
        
        for (int i = 0; i <= degree; i++)
        {
            sum.coefs[i] = coefs[i]; 
            
            if (i <= pRight.degree)
            {
                sum.coefs[i] += pRight.coefs[i]; 
            }
        }
        
        // devuelve la suma de los polinomios 
        return sum; 
    }
    else // si el grado del polinomio del grado derecho es mayor 
    {
        Polynomial sum(pRight.degree); 
        
        for (int i = 0; i <= pRight.degree; i++)
        {
            sum.coefs[i] = pRight.coefs[i]; 
            
            if (i <= degree)
            {
                sum.coefs[i] += coefs[i]; 
            }
        }
        
        // devuelve la suma de los polinomios 
        return sum; 
    }
}

// resta entre dos polinomios 
Polynomial Polynomial::operator-(const Polynomial &pRight) const
{
    // realiza una resta de polinomios de acuerdo a su grado 
    if (degree == pRight.degree) // si los grados son iguales 
    {
        Polynomial subs(degree); 
        
        for(int i = 0; i <= degree; i++)
        {
            subs.coefs[i] = coefs[i] - pRight.coefs[i]; 
        }
        
        // devuelve la resta entre los dos polinomios 
        return subs; 
    }
    else if (degree > pRight.degree) // si el grado del polinomio izquierdo es mayor
    {
        Polynomial subs(degree); 
        
        for (int i = 0; i <= degree; i++)
        {
            subs.coefs[i] = coefs[i] - pRight.coefs[i]; 
        }
        
        // devuelve la resta entre los dos polinomios 
        return subs; 
    }
    else // si el grado del polinomio derecho es mayor 
    {
        Polynomial subs(pRight.degree); 
        
        for (int i = 0; i <= pRight.degree; i++)
        {
            subs.coefs[i] = pRight.coefs[i]; 
            
            if (i <= degree)
            {
                subs.coefs[i] -= coefs[i]; 
            }
        }
        
        // devuelve la resta entre los dos polinomios 
        return subs; 
    }
}

// multiplicacion entre dos polinomios 
Polynomial Polynomial::operator*(const Polynomial &pRight) const
{
    unsigned int pDegree = degree + pRight.degree;
    
    // objeto prodcuto cuyo tamaño es la suma de los grados de los dos polinomios 
    Polynomial product(pDegree);
    
    product.setCoefficient(pDegree, 0); // asegura que la multiplicacion se realice correctamente 
    
    // se realiza el producto de los polinomios 
    for(int i = 0; i <= degree; i++)
    {
        for (int j = 0; j <= pRight.degree; j++)
        {
            product.coefs[i+j] += coefs[i] * pRight.coefs[j]; // suma entre términos de igual grado 
        }
    }
    
    // devuelve el producto 
    return product; 
}

// op. asignacion suma 
// permite sumar dos polinomios y asignar ese valor al polinomio izquierdo 
const Polynomial &Polynomial::operator+=(const Polynomial &pRight)
{
    *this = *this + pRight; 
    
    return *this; 
}

// op. asignacion resta 
// permite restar dos polinomios y asignar ese valor al polinomio izquierdo 
const Polynomial &Polynomial::operator-=(const Polynomial &pRight)
{
    *this = *this - pRight;
    
    return *this; 
}

// op. asignacion multiplicacion 
// permite multiplicar dos polinomios y asignar ese valor al polinomio izquierdo 
const Polynomial &Polynomial::operator*=(const Polynomial &pRight)
{
    *this = *this * pRight;
    
    return *this; 
}

//imprime el polinomio en forma ax^n + bx^n-1, ...
ostream &operator<<(std::ostream &output, const Polynomial &p)
{
    // imprime el polinomio como una suma de terminos hasta el grado del polinomio
    for(int i = p.degree; i >= 0; i--)
    {
        // revisa si el grado no es igual a cero 
        if (i != 0)
        {
            // permite imprimir el primer monomio adecuadamente, así como
            // los terminos con coeficiente negativos 
            if(i == p.degree || p.coefs[i] < 0)
            {
                output << p.coefs[i] << "x^" << i;
            }
            else 
            {
                output << "+" << p.coefs[i] << "x^" << i;
            }
        }
        else 
        {
            if (p.coefs[i] == 0)
            {
                output << "+0";
            }
            else if(p.coefs[i] < 0) // permite imprimir terminos con coeficiente negativo
            {
                output << p.coefs[i];
            }
            else 
            {
                output << "+" << p.coefs[i]; 
            }
        }
    }
    
    output << endl; 
    
    // permite llamadas en cascada 
    return output; 
}

// funcion que evalua el polinomio en un determinado valor para x 
double evaluate(Polynomial &p, double x)
{
    // variable que contiene el polinomio evaluado 
    double pX = 0; 
    
    // evalua el polinomio segun el grado del coeficiente 
    for(int i = p.getDegree(); i >= 0; i--)
    {
        if (i != 0)
            pX += p.getCoefficient(i) * pow(x, i); 
        else 
            pX += p.getCoefficient(i); 
    }
    
    // devuelve el valor del polinomio evaluado en x 
    return pX;
}