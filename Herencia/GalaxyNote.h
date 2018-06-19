// Pablo Llanes 00133203
// Deber 6: Herencia
// GalaxyNote.h: definicion de la clase GalaxyNote

#ifndef GALAXYNOTE_H
#define GALAXYNOTE_H

#include <string>
#include "Smartphone.h"

class GalaxyNote : public Smartphone
{
    public: 
        GalaxyNote(); 
        void GoogleNow(); 
    
    private:
        std::string pen; 
    
};

#endif