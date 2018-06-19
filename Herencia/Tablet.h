// Pablo Llanes 00133203
// Deber 6: Herencia
// Tablet.h: definicion de la clase Tablet

#ifndef TABLET_H
#define TABLET_H

#include <string>
#include "Computer.h"

class Tablet : public Computer 
{
    public:
        Tablet(); 
        
    private:
        std::string touchscreen; 
};

#endif 