#include <iostream>
#include "Projectile.h"

using namespace std;

Projectile::Projectile(std::string myName)
   : GameObject(myName)
{
   cout << "Projectile(" << name << ")" << endl;
}

void Projectile::draw()
{
   cout << ">>--> Projectile::draw(" << name << ")" << endl;
}
