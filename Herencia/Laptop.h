// Pablo Llanes 00133203
// Deber 6: Herencia
// Laptop.h: definicion de la clase Laptop

#ifndef LAPTOP_H
#define LAPTOP_H

#include <string>
#include "Computer.h"

class Laptop : public Computer
{
    public:
        Laptop();
    
    private:
        std::string charger; 
        std::string touchpad; 
};

#endif