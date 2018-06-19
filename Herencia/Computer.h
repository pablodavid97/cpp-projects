// Pablo Llanes 00133203
// Deber 6: Herencia
// Computer.h: definicion de la clase Computer

#ifndef COMPUTER_H
#define COMPUTER_H

#include <string> 

class Computer
{
    public: 
        Computer();
        void setBrand(std::string);
        std::string getBrand();
        void setModel(std::string);
        std::string getModel();
        void setProcessor(std::string);
        std::string getProcessor();
        void setgraphicsCard(std::string); 
        std::string getGraphicsCard(); 
        void setSoftware(std::string s); 
        std::string getSoftware(); 
        void setSound(int level); 
        int getSound(); 
        void displayGraphics(); 
        void informationSearch(std::string); 
        void setBatteryLevel(int x);
        int getBatteryLevel(); 
        
    protected: 
        std::string brand; 
        std::string model; 
        std::string proccesor; 
        std::string graphicsCard; 
        std::string software;
        std::string screen; 
        std::string battery; 
        std::string speakers; 
}; 

#endif