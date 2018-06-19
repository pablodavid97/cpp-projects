// Pablo Llanes 00133203
// Deber 6: Herencia
// Desktop.h: definicion de la clase Desktop

#ifndef DESKTOP_H
#define DESKTOP_H

#include <string>
#include "Computer.h"

class Desktop : public Computer
{
    public: 
        Desktop();
        
    private:
        std::string mouse;
        std::string keyboard;
        std::string box; 
};

#endif