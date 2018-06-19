#include <iostream>
#include "Building.h"

using namespace std;

Building::Building(std::string myName)
   : GameObject(myName)
{
   cout << "Building(" << myName << ")" << endl;
}

void Building::draw()
{
   cout << "[][][] Building::draw(" << name << ")" << endl;
}
