// Pablo Llanes 00133203
// Deber 6: Herencia
// iPhone.h: definicion de la clase iPhone

#ifndef IPHONE_H
#define IPHONE_H

#include <string>
#include "Smartphone.h"

class iPhone : public Smartphone 
{
    public: 
        iPhone();
        void Siri(); 
};

#endif 