// Pablo Llanes 00133203
// Deber 6: Herencia
// Smartphone.h: definicion de la clase Smartphone

#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <string>
#include "Computer.h"

class Smartphone : public Computer 
{
    public:
        Smartphone(); 
        void makeCall(); 
        void setCallsRecieved(int c);
        int callsRecieved();
        void setCallsMade(int c);
        int callsMade();
        void takePicture(); 
        void takeVideo(); 
    
    private:
        std::string touchscreen; 
        std::string simCard; 
        std::string camera; 
};

#endif 