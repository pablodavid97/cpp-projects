// Pablo Llanes 00133203
// Deber 6: Herencia
// Server.h: definicion de la clase Server

#ifndef SERVER_H
#define SERVER_H

#include <string>
#include "Computer.h"

class Server : public Computer
{
    Server(); 
    void setNumberofRequests(int n);
    int getNumberofRequests(); 
    void setRequest(std::string);
    void getRequest();
    
    private:
        std::string database;
};

#endif 