#include <iostream>
#include "GameObject.h"

using namespace std;

GameObject::GameObject(std::string myName)
   : name(myName)
{
   cout << "GameObject(" << name << ")" << endl;
}

void GameObject::draw()
{
   cout << "GameObject::draw(" << name << ")" << endl;
}
